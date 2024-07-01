# Leandro: ableton-style audio synthesis software

<a href="https://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1"><img src="./docs/by-nc_small.png" alt="CC BY-NC 4.0" style="width:100px;"/></a>

Leandro is a piece of software that explores different methods of audio synthesis and different audio filters, written entirely in C++, using portaudio and Qt.

It synthesizes notes from MIDI files using its own instruments and audio filters. After importing a .MIDI file, the user can choose from the different synthesizing methods and combine any number of filters and the melody will be generated accordingly.

Everyone loves images, so here's a screenshot of Leandro's main screen in action:

![Main](./Leandro/images/leandro_main.png "Main screen")

Leandro also supports multi-channel MIDI files, and allows for each channel to have its own synthesis method and assortment of audio filters:

![multi channel](./Leandro/images/leandro_multichan.png "Multi channel")

After experimenting with different "instruments" and filters, you might like what you hear: the session's recording can be started and stopped at any point, and .wav files can be saved with the contents of those recordings.

# Table of Contents

* [Fast Fourier Transform](fast-fourier-transform)
* [Sample-Based Synthesis](sample-based-synthesis)
* [Additive Synthesis](additive-synthesis)
* [Sound synthesis using physical models](sound-synthesis-using-physical-models)
* [Waveform synthesis](waveform-synthesis)
* [Random behavior](random-behavior)
* [Digital Effects](digital-effects)
* [Program implementation](program-implementation)

## Fast Fourier Transform
>[Table of contents](#table-of-contents)

### Theory
>[Fast Fourier Transform](fast-fourier-transform)

To apply the Fast-Fourier-Transform algorithm, we used the Decimation-in-time algorithm, better known as the Cooley-Tukey algorithm, which will be developed below.

Starting from the assumption that what you want to obtain is,

$$X(k)=\sum_{n=0}^{N-1} x(n) W_N^{-kn} \, , \,\,\, W_N = e^{j2\pi /N}$$

Taking this into account, and knowing that $N$ can be written in the form $N=2^{r}$ being $r\in\mathbb{N}$, we can split this summation into even and odd parts, leaving,

$$X(k)=\sum_{n=0}^{N/2 -1} x(2n)W_{N/2}^{-kn} + W_N^{-k} \sum_{n=0}^{N/2-1} x(2n+1)W_{N/2}^{-kn} $$

Therefore, if we call $x_p(n)=x(2n)$ and $x_i(n)=x(2n+1)$, we can rewrite the expression as,

$$X(k)=X_p(k)+W_N^{-k}X_i(k)$$

Finally, given the periodicity $X_p(k+frac{N}{2}) = X_p(k)$ and $X_i(k+frac{N}{2}) = X_i(k)$

We obtain that,

$$X\left(k+\frac{N}{2}\right) = X_p(k) - W_N^{-k}X_i(k)$$

Finally, from the expression above, we can see that by saving the values obtained for half of the FFT interval, we can reuse them to calculate the missing half.
The Cooley-Tukey algorithm uses this property, recursively subdividing the odd and even parts until we arrive at a function with only one element.

### Implementation
>[Fast Fourier Transform](fast-fourier-transform)

The implementation of the algorithm can be seen below.

```c++
void fft(std::complex<float>* in, std::complex<float>* out, size_t n) {
    vector<complex<double>> temp;
    for (size_t i = 0; i < n; i++)
        temp.push_back(in[i]);
    temp = Cooley_Tukey(temp);
    for (size_t i = 0; i < temp.size(); i++)
        out[i] = temp[i];
    return;
}

std::vector<complex<double>> Cooley_Tukey(std::vector<complex<double>>& samples) {
    unsigned int numSamples = samples.size();

    if (numSamples <= 1)
        return samples;
    unsigned int newSampleSize = numSamples / 2;
    std::vector<complex<double>> Xeven(newSampleSize, 0);
    std::vector<complex<double>> Xodd(newSampleSize, 0);

    for (unsigned int i = 0; i < newSampleSize; i++) {
        Xeven[i] = samples[2 * i];
        Xodd[i] = samples[2 * i + 1];
    }
    std::vector<complex<double>> Feven(newSampleSize, 0);
    std::vector<complex<double>> Fodd(newSampleSize, 0);

    Feven = Cooley_Tukey(Xeven);
    Fodd = Cooley_Tukey(Xodd);

    std::vector<complex<double>> freqBins(numSamples, 0);

    for (unsigned int i = 0; i < (numSamples / 2); i++) {
        complex<double> cmplxExponential = polar(1.0, (-2 * 3.14159 * i / numSamples)) * Fodd[i];
        freqBins[i] = Feven[i] + cmplxExponential;
        freqBins[i + numSamples / 2] = Feven[i] - cmplxExponential;
    }
    return freqBins;
}
```

### Results
>[Fast Fourier Transform](fast-fourier-transform)

Comparing the results for the data sequence expressed in the equation below, using the python FFT function yielded the results shown in the figure below.

$$x(n) = 10 sin(2\pi100 n T) + 5 sin(2\pi 200 n T) + 2.5 sin(2\pi 300 n T)\\
    T=\frac{1}{800} \,\, and \,\, 0<n<4096$$

<img src="./docs/fft_results.png" alt="CC BY-NC 4.0" style="width:500px;"/>

## Sample-Based Synthesis
>[Table of contents](#table-of-contents)

### Introduction

Sample-based synthesis is very different from other forms of synthesis such as additive synthesis. As seen above this type of synthesis uses basic functions such as sine, square, triangle or sawtooth to synthesize different sounds. However, sample-based synthesis uses a sample to recreate another sound. This sample, henceforth referred to as a sample, can be a recorded sound or instrument. Consequently, this form of synthesis allows you to recreate a more realistic sound since you are working on a real sound. In addition, it is less demanding on the CPU than other forms of synthesis, such as synthesis using physical models, since the output signal is not calculated in real time but pre-recorded samples are used. However, this type of synthesis involves a similar difficulty. Suppose you want to synthesize a piano. By this method it is possible but it would require to have pre-recorded all the notes of the piano with all the possible durations. This is clearly impossible since the memory is finite. For this reason, algorithms are used to perform time and frequency stretching and compression to form from a pre-recorded note another note with different frequency and different duration. This is the objective of this section, to be able to determine an appropriate algorithm so that, from a recorded note, another note of different frequency and duration can be created. In this way, with just a few samples, we can synthesize an instrument. Taking all this into consideration, it is proposed to synthesize a piano.

### Pitch shifting

First, the possibility of modifying the pitch of a note is analyzed. The pitch is one of the four essential qualities of sound. It determines whether a sound is high-pitched or low-pitched. The higher the frequency, the higher the pitch, and the lower the frequency, the lower the pitch. The Pitch is determined by the fundamental frequency of the signal.

Understanding these basic notions, the objective of this sub-section is defined. Starting from a sound with a certain Pitch, such as a piano note, we want to modify its fundamental frequency in order to generate another note with the same duration as the original one. This is possible by means of a frequency shift or pitch shifting. This process involves two steps: first, the pitch must be identified (Pitch Detection) and secondly, the pitch shift or correction must be made (Pitch Correction).

#### Pitch Detection

<img src="./docs/c3_time_domain.png" style="width:400px;"/>
<img src="./docs/c3_frec_domain.png" style="width:400px;"/>

The Pitch of a signal can be analyzed in the frequency domain as well as in the time domain. The Figure above shows a simple sample of the note C3 of a piano. Note that, the frequency domain plot tells much more than the other plot. You can clearly see the peaks of the signal. The most predominant peak determines the fundamental frequency and, as stated above, the fundamental frequency is the ÒpitchÓ of the signal. For this particular signal, the Pitch is $130.8128Hz$. On the other hand, see that the graph in the time domain the Pitch is periodic. This is much less intuitive than the previous case. Therefore, the detection of the Pitch is best analyzed in the frequency domain.

Typical detection methods include autocorrelation methods or by means of magnitude difference averaging. These methods are very interesting if you do not know the signal at which pitch shifting is to be performed. However, since the objective of the section is to synthesize notes from a piano, the different Pitch are already known beforehand. Recalling music theory concepts, the frequency of the $k-th note of a piano is given by the equation:

$$f = 2^{\frac{k-49}{12}}\cdot 440Hz$$

For example, note C3 which is note number 28 has a fundamental frequency or Pitch of $130.8128Hz$, as seen in the Figure above. In summary, with equation above you have all the Pitches of all the notes of the piano. Furthermore, it follows from the equation above that each note is separated by $2^{frac{1}{12}}$. For example, if you have C3, C3 will be $130.8128Hz \cdot 2^{frac{1}{12}}$. D3 will be $130.8128Hz \cdot 2^{frac{2}{12}}$ and so on.

The following is an analysis of a Sample to demonstrate the theory described above. The analysis is performed with the free program Audacity. This program allows to perform the frequency spectrum of a Sample. Figure below shows the spectrum of a Sample of the note C4 of a classical electronic piano. The Sample was acquired using the GrageBand program.

<img src="./docs/espectro_c4.png" style="width:600px;"/>

As can be seen in the Figure above, the fundamental frequency is $264Hz$ so it is effectively the note C4. This type of analysis is the one that is going to be performed to determine the Pitch of each Sample.

As a last clarification on the subject. Do not confuse Pitch which has units of Hz and is observed in the frequency domain with the Pitch Period which is the reciprocal of the Pitch, has units of second and is observed in the time domain.

#### Pitch Correction

In the previous subsection we analyzed how to determine the pitch of a Pitch of a Sample. Now we analyze how to modify or, better said, correct the Pitch of a Sample to generate a new pitch. Correction algorithms can work in the time domain or in the frequency domain. Generally those working in the frequency domain are very robust but suffer from long latencies. Therefore, a time domain method is used. 

Most of the techniques that work in the time domain to perform pitch correction are based on the TD-PSOLA method.
TD-PSOLA (Time-Domain Pith Synchronous Overlap and Add method). This is the method used in this section because it is fast, simple and, as will be shown later, has very good results.

The TD-PSOLA method can be divided into three steps:

    * Decompose the input signal into a series of short-time analysis signals.
    * Modification of the short-time analysis signals to short-time synthesis signals
    * Composition of the new signal with the short time synthesis signals. Here is the concept of overlap-add

<img src="./docs/TD-PSOLA.png" style="width:400px;"/>

Step 3 is where the interesting thing happens. When recomposing the signal, the short time synthesis signals can overlap or move away from each other. This causes the fundamental frequency of the signal to vary. If the signals move closer together, the fundamental frequency increases (higher pitch). Conversely, if the signals move away from each other, the fundamental frequency decreases (lower Pitch). An illustration of the method is shown in the Figure above to understand how it works. Keeping in mind the steps of the method, we continue to develop each one in detail.

##### Step 1

This step consists of decomposing the input signal $x(n)$ into a sequence of short-time analysis signals, called $x(s,n)$. These signals are obtained by multiplying $x(n)$ by a sequence of time-translated analysis windows. That is:

$$x(s,n)=h_s(n)x(n-t_a(s))$$

Where $h_s(n)$ is the analysis window with support at $n=0$ and $t_a(s)$ is the s-th analysis time instant. These time instants are called pitch-marks and are the peaks in $x(n)$. In the case of piano notes, these peaks are periodic. This period is the $P(s)$ (\textit{Pitch Period}).

Returning to the analysis window, its length $T$ is proportional to $P(s)$. Generally, one usually takes $T = $P(s)$ with $P(s)$ = 2$. The shape of the window $h_s(n)$ is arbitrary. In this case the Hanning window is used because of its spectral behavior.

##### Step 2

The second step consists of transforming the sequence of short-time analysis signals into a sequence of short-time synthesis signals. The latter are synchronized with a new set of time instants $t_s(\mu)$ called synthesis pitch-marks. The set of $t_s(\mu)$ are determined by the set of $t_a(s)$ instants, depending on the Pitch correction to be performed. This is the most important concept of TD-PSOLA. Let $P_0$ be the original Pitch Period of the signal and $P_1$ be the Pitch Period of the signal to be synthesized. Then, the desired shift can be expressed as $P_1 = \frac{1}{beta} \cdot P_0$ with $\beta$ being the shift factor. For example, if one wants to synthesize C4 from C4, i.e. run a half-tone, $B = 2^{frac{1}{12}}$. In this way, the synthesized signal will have the pitch-marks of the original signal but now spaced $P_1$. These synthesis pitch-marks determine $t_s(\mu)$. Figure \ref{fig:pitch_marks} greatly aids in the compression of this step. 

<img src="./docs/pitch_marks.png" style="width:400px;"/>

##### Step 3

Composition of the synthesized signal. We already have the synthesis pitch-marks so it would be necessary to center each short time synthesis signal to these time instants. But a small problem arises. If the duration of the original signal is to be maintained, a synthesis signal may have to be repeated in two or more synthesis pitch-marks. Then, to determine which signal is repeated we simply calculate which synthesis pitch-mark is closest to the synthesis pitch-mark being evaluated. In this way the synthesized signal is 'filled in'. Depending on the value of $\beta$ it may be that the synthesis signals are overlapped so that operlap-add must be done to form the synthesized signal.

<img src="./docs/psola_c4.png" style="width:600px;"/>

Figure above shows the method on a Sample of C4 of a classical electronic piano to synthesize C4 (fundamental frequency one semi-tone higher than C4). In the first graph, the peaks or pitch-marks of the signal separated approximately by the Pitch Period are detected. In the second graph, the windows centered on the pitch-marks are placed. The third plot shows short time analysis signals already modified by the window. The fourth graph shows the signal synthesized with the synthesis pitch-marks. It would remain to be determined whether the fundamental frequency of the synthesized signal is indeed that of C4 ($279Hz$). Figure below shows the spectrum of the synthesized signal. A shift in the fundamental frequency was indeed achieved.

<img src="./docs/espectro_c_sharp_4.png" style="width:500px;"/>

#### Conclusion

In conclusion, pitch shifting was successfully achieved on a Sample. It was possible to perform the shift of the fundamental frequency of the sample while maintaining the duration of the sample. As additional considerations, it is possible to work using different windows such as Barlett or similar and with different width to analyze the different results.  

### Time-scale Modification

Second, temporal scaling is analyzed. The method to perform the scaling is very similar to the method to perform the pitch shifting. The difference is that now we are not interested in changing the Pitch but, what we want is to modify the time of the signal. To achieve this, the TD-PSOLA method is also used. The steps of the method are the same as those described in Pitch Correction and others suffer some changes. Step 1 remains exactly the same, the signal is decomposed into a series of short time analysis signals. Step 2 undergoes a small correction. Remember that now you want to have the same Pitch so the distance between each synthesis signal must have the same distance from each other as the analysis signals. This would be $P_0 = P_1$. From this follows the main problem. Suppose one wants to shorten the signal time. Then, some synthesis signals must be removed so that the total time is reduced but the Pitch remains the same. The opposite happens if you want to increase the signal time. To achieve this, synthesis signals must be repeated to fill the time. Once the position of each synthesis signal is known, it is possible to continue with step 3 and compose the final signal.

Figure below shows an illustration of the time modification method.

<img src="./docs/modificacion_temporal.png" style="width:500px;"/>

#### Implementation

This section explains the implementation of the previously described methods to achieve the synthesis by Òtextit{samples} of a piano. 

First, the samples or samples were searched. To synthesize a piano we consider using the samples of the notes C1,C2,C3,C4,C5,C6. This allows us to synthesize all the samples since we have one sample per octave. That is to say, if you want the note D3 you will use the sample C1 to make the corresponding frequency shift. If A5 is desired, use C5 and so on. As you can see, each octave sample can synthesize 11 notes (each octave is separated by 12 notes). Once we have the samples, we continue to make a spectral analysis of each one to determine its fundamental frequency. Having everything necessary, we continue to apply the methods previously explained.

Figure below shows a modification of a C4 note. The first graph shows the original signal, the third one shows C4 with a two semitone shift and the last one shows a temporal lengthening of the sample. The second graph shows something interesting. Notice that fragments of the signal are repeated to fill the time. This was implemented this way because this is how sample synthesizers work. The user is always given the option to select the fragment of the signal to be repeated in case you want to synthesize a signal with a longer duration than the original signal.

<img src="./docs/key_modification.png" style="width:500px;"/>

### Conclusion

It was possible to understand the basics of sample synthesis, its operation and implementation. It was possible to perform the time shift and the fundamental frequency to synthesize any note of a piano. 

With the knowledge acquired, it was possible to synthesize several instruments such as a steinway piano, an electric piano, a guitar, among others. 

## Additive Synthesis
>[Table of contents](#table-of-contents)

## Sound synthesis using physical models
>[Table of contents](#table-of-contents)

## Waveform synthesis
>[Table of contents](#table-of-contents)

## Random behavior
>[Table of contents](#table-of-contents)

## Digital Effects
>[Table of contents](#table-of-contents)

## Program implementation
>[Table of contents](#table-of-contents)


# Contact
>[Table of contents](#table-of-contents)

Please do not hesitate to reach out to me if you find any issue with the code or if you have any questions.

* Personal email: [ianczdiaz@gmail.com](mailto:ianczdiaz@gmail.com)

* LinkedIn Profile: [https://www.linkedin.com/in/iancraz/](https://www.linkedin.com/in/iancraz/)

# License
>[Table of contents](#table-of-contents)

<a href="https://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1"><img src="./docs/by-nc.png" alt="CC BY-NC 4.0" style="width:200px;"/></a>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/iancraz/Music-Synthesizer">Music Synthesizer</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://www.linkedin.com/in/iancraz/">Ian C. Diaz</a> is licensed under <a href="https://creativecommons.org/licenses/by-nc-sa/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY-NC-SA 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1" alt=""><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1" alt=""><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/nc.svg?ref=chooser-v1" alt=""><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/sa.svg?ref=chooser-v1" alt=""></a></p>

```
You are free to:
    Share — copy and redistribute the material in any medium or format

    Adapt — remix, transform, and build upon the material

The licensor cannot revoke these freedoms as long as you follow the license terms.
Under the following terms:
    Attribution — You must give appropriate credit , provide a link to the license,
    and indicate if changes were made. You may do so in any reasonable manner, but 
    not in any way that suggests the licensor endorses you or your use.

    NonCommercial — You may not use the material for commercial purposes.

    ShareAlike — If you remix, transform, or build upon the material, you must 
    distribute your contributions under the same license as the original.

    No additional restrictions — You may not apply legal terms or technological 
    measures that legally restrict others from doing anything the license permits.

Notices:

You do not have to comply with the license for elements of the material in the 
public domain or where your use is permitted by an applicable exception or 
limitation.

No warranties are given. The license may not give you all of the permissions 
necessary for your intended use. For example, other rights such as publicity, 
privacy, or moral rights may limit how you use the material.
```
