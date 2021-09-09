# Leandro: ableton-style audio synthesis software

Leandro is a piece of software that explores different methods of audio synthesis and different audio filters, written entirely in C++, using portaudio and Qt.

It synthesizes notes from MIDI files using its own instruments and audio filters. After importing a .MIDI file, the user can choose from the different synthesizing methods and combine any number of filters and the melody will be generated accordingly.

Everyone loves images, so here's a screenshot of Leandro's main screen in action:

![main screen](https://github.com/assd-grupo-6/TP2---Sintesis-v2/blob/master/Leandro/images/leandro_main.png "Main screen")

Leandro also supports multi-channel MIDI files, and allows for each channel to have its own synthesis method and assortment of audio filters:

![multi channel](https://github.com/assd-grupo-6/TP2---Sintesis-v2/blob/master/Leandro/images/leandro_multichan.png "Multi channel")

After experimenting with different "instruments" and filters, you might like what you hear: the session's recording can be started and stopped at any point, and .wav files can be saved with the contents of those recordings.

# Contact
>[Table of contents](#table-of-contents)

Please do not hesitate to reach out to me if you find any issue with the code or if you have any questions.

* Personal email: [idiaz@itba.edu.ar](mailto:idiaz@itba.edu.ar)

* LinkedIn Profile: [https://www.linkedin.com/in/iancraz/](https://www.linkedin.com/in/iancraz/)

# License
>[Table of contents](#table-of-contents)

```
MIT License

Copyright (c) 2021 Ian Cruz Diaz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
