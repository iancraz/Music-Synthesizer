# Leandro: ableton-style audio synthesis software

Leandro is a piece of software that explores different methods of audio synthesis and different audio filters, written entirely in C++, using portaudio and Qt.

It synthesizes notes from MIDI files using its own instruments and audio filters. After importing a .MIDI file, the user can choose from the different synthesizing methods and combine any number of filters and the melody will be generated accordingly.

Everyone loves images, so here's a screenshot of Leandro's main screen in action:

![main screen](https://github.com/assd-grupo-6/TP2---Sintesis-v2/blob/master/Leandro/images/leandro_main.png "Main screen")

Leandro also supports multi-channel MIDI files, and allows for each channel to have its own synthesis method and assortment of audio filters:

![multi channel](https://github.com/assd-grupo-6/TP2---Sintesis-v2/blob/master/Leandro/images/leandro_multichan.png "Multi channel")

After experimenting with different "instruments" and filters, you might like what you hear: the session's recording can be started and stopped at any point, and .wav files can be saved with the contents of those recordings.
