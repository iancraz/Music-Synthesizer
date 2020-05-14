#include "Channel.h"
#include "Leandro.h"
#include "MidiFile.h"
#include "ui_Leandro.h"
#include <string>
using namespace std;
using namespace smf;

Channel::Channel(int channelCreationCounter, Leandro* _program) {
	this->program = _program;

	// Variable initialization
	this->ID = channelCreationCounter;
	this->volume = 1.0;
	this->keyboard = false;

	// Pointers init to nullptr
	this->instrument = nullptr;
	this->currentMidiTrack = new midiTrack;
	this->currentMidiTrack->midifile = nullptr;
	this->currentMidiTrack->trackIndex = NULL;
	this->currentMidiTrack->trackName = "";

	//Clear vectors
	this->effects.clear();
	while (!this->events.empty()) this->events.pop();

	// Callback update
	this->updateCallbackData();
}

void Channel::updateCallbackData() { // Function to be called at the end of every setter
	this->callData.effects = &(this->effects);
	this->callData.instrument = this->instrument;
	this->callData.currentMidiTrack = this->currentMidiTrack;
	this->callData.volume = &(this->volume);
	this->callData.events = &(this->events);
}

Channel::~Channel() {}

bool Channel::operator== (Channel const& channel) {
	if (this->ID == channel.ID) return true;
	else return false;
}

void Channel::callback(	// Take midi file, select events in timeframe, synthesize notes into buffer.
	unsigned long frameCount,
	const __int64* currentSample,
	vector<timedBuffer*>* buffers,
	channelCallbackData* data) {
	// Void data type casting

	// Local variable declarations
	midiEvent currentEvent;

	while (true) {
		float* buffer = nullptr;
		bool emptyBufferFound = false;
		if (!(data->events->size() > 0)) break;
		if (data->events->front().startSample < *currentSample + frameCount) { // If the event in front of the midi track event queue is before the end of this timeframe
			currentEvent = data->events->front(); // Set this event as the event to process in this iteration
			data->events->pop(); // Remove the event from the queue

			for (int i = 0; buffer == nullptr && i < buffers->size(); i++) // Run a loop through the current note buffers
				if (buffers->at(i)->buffer[0] == INFINITY) { // If the buffer is free
					buffer = buffers->at(i)->buffer; // Select this buffer to save the result of the event processing
					buffers->at(i)->startingFrame = currentEvent.startSample; // Remember when to play this buffer
					emptyBufferFound = true;
				}
			if (!emptyBufferFound)
			{ // If there were no empty buffers, replace the oldest one with the new data
				__int64 minStartFrame = 9999999999999;
				int bufferToReplace = 0;
				for (int j = 0; buffer == nullptr && j < buffers->size(); j++) // Run a loop through the current note buffers
					if (buffers->at(j)->startingFrame < minStartFrame) // Look for the oldest buffer
					{
						minStartFrame = buffers->at(j)->startingFrame;
						bufferToReplace = j;
					}
				buffers->at(bufferToReplace)->buffer[0] = INFINITY;
				buffer = buffers->at(bufferToReplace)->buffer; // Select this buffer to save the result of the event processing
				buffers->at(bufferToReplace)->startingFrame = currentEvent.startSample; // Remember when to play this buffer
			}

			// First, call the instrument function

			if (data->instrument) {
				data->instrument->synthFunction(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, currentEvent.note, currentEvent.durSeconds, currentEvent.velocity, SAMPLE_RATE);
				for (int i = 0; i < (data->effects->size()); i++)
					data->effects->at(i)->callback(buffer, MAX_NOTE_LENGTH_SECONDS * SAMPLE_RATE, SAMPLE_RATE);
			}
			
			/*
			int s = 0;
			int c = 0;
			bool noteStarted = false;
			while (buffer[s] != INFINITY) {
				if (buffer[s] > 0.5) noteStarted=true;
				if (buffer[s] < 0.005&& buffer[s] > -0.005) c++;
				if (buffer[s] > 0.005 || buffer[s] < -0.005) c=0;
				if (c > 1000 && noteStarted == true) {
					buffer[s] = INFINITY;
					break;
				}
				s++;
			}
			*/
			// Then, iterate through the vector of effects, calling each one of them

			
		}
		else break; // If the next note is out of scope, exit the while loop: no need for processing whole track at this point
	}
}

void Channel::addToGUI(Ui_LeandroClass* programUI) {
	string _strID = to_string(ID);
	char * strID = new char[(_strID.size()) + 1];
	strcpy(strID, _strID.c_str());

	// Brushes
	QBrush brush2(QColor(135, 135, 135, 255));
	brush2.setStyle(Qt::SolidPattern);
	QBrush brush6(QColor(110, 110, 110, 255));
	brush6.setStyle(Qt::SolidPattern);

	// Fonts
	QFont font;
	font.setFamily(QStringLiteral("Helvetica World"));

	QFont font1;
	font1.setBold(true);
	font1.setWeight(75);

	QFont font2;
	font2.setPointSize(7);

	// GUI config

	frameChannel = new QFrame(programUI->scrollAreaChannelsWidgetContents_2);
	frameChannel->setObjectName(QString::fromUtf8(strcat("frameChannel",strID)));
	QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
	sizePolicy5.setHorizontalStretch(0);
	sizePolicy5.setVerticalStretch(0);
	sizePolicy5.setHeightForWidth(frameChannel->sizePolicy().hasHeightForWidth());
	frameChannel->setSizePolicy(sizePolicy5);
	frameChannel->setMaximumSize(QSize(125, 16777215));
	QPalette palette3;
	palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
	palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
	palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
	palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
	palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
	palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
	frameChannel->setPalette(palette3);
	frameChannel->setAutoFillBackground(true);
	frameChannel->setFrameShape(QFrame::Panel);
	frameChannel->setFrameShadow(QFrame::Raised);
	frameChannel->setLineWidth(3);
	verticalLayoutFrameChannel = new QVBoxLayout(frameChannel);
	verticalLayoutFrameChannel->setSpacing(6);
	verticalLayoutFrameChannel->setContentsMargins(11, 11, 11, 11);
	verticalLayoutFrameChannel->setObjectName(QString::fromUtf8(strcat("verticalLayoutFrameChannel", strID)));
	channelTopLayout = new QHBoxLayout();
	channelTopLayout->setSpacing(6);
	channelTopLayout->setObjectName(QStringLiteral("channelTopLayout"));
	nameLabelChannel = new QLabel(frameChannel);
	nameLabelChannel->setObjectName(QString::fromUtf8(strcat("nameLabelChannel", strID)));
	nameLabelChannel->setFont(font1);
	nameLabelChannel->setAlignment(Qt::AlignCenter);

	channelTopLayout->addWidget(nameLabelChannel);

	closeButtonChannel = new QPushButton(frameChannel);
	closeButtonChannel->setObjectName(QStringLiteral("closeButtonChannel1"));
	QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
	sizePolicy6.setHorizontalStretch(0);
	sizePolicy6.setVerticalStretch(0);
	sizePolicy6.setHeightForWidth(closeButtonChannel->sizePolicy().hasHeightForWidth());
	closeButtonChannel->setSizePolicy(sizePolicy6);
	QIcon icon5;
	icon5.addFile(QStringLiteral(":/icons/icons/037-minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
	closeButtonChannel->setIcon(icon5);
	closeButtonChannel->setIconSize(QSize(12, 12));
	closeButtonChannel->setFlat(true);

	channelTopLayout->addWidget(closeButtonChannel);

	verticalLayoutFrameChannel->addItem(channelTopLayout);

	setActiveButtonChannel = new QPushButton(frameChannel);
	setActiveButtonChannel->setObjectName(QString::fromUtf8(strcat("setActiveButtonChannel", strID)));
	QSizePolicy sizePolicy60(QSizePolicy::Minimum, QSizePolicy::Fixed);
	sizePolicy60.setHorizontalStretch(0);
	sizePolicy60.setVerticalStretch(0);
	sizePolicy60.setHeightForWidth(setActiveButtonChannel->sizePolicy().hasHeightForWidth());
	setActiveButtonChannel->setSizePolicy(sizePolicy60);
	setActiveButtonChannel->setMinimumSize(QSize(0, 17));
	setActiveButtonChannel->setFont(font2);
	setActiveButtonChannel->setAutoFillBackground(true);
	setActiveButtonChannel->setFlat(true);

	verticalLayoutFrameChannel->addWidget(setActiveButtonChannel, 0, Qt::AlignHCenter);

	verticalSpacerChannel = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

	verticalLayoutFrameChannel->addItem(verticalSpacerChannel);

	

	

	inputComboBoxChannel = new QComboBox(frameChannel);
	inputComboBoxChannel->setObjectName(QString::fromUtf8(strcat("inputComboBoxChannel", strID)));
	QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
	sizePolicy8.setHorizontalStretch(0);
	sizePolicy8.setVerticalStretch(0);
	sizePolicy8.setHeightForWidth(inputComboBoxChannel->sizePolicy().hasHeightForWidth());
	inputComboBoxChannel->setSizePolicy(sizePolicy8);
	inputComboBoxChannel->setMinimumSize(QSize(0, 17));
	inputComboBoxChannel->setFont(font2);
	inputComboBoxChannel->setContextMenuPolicy(Qt::DefaultContextMenu);
	inputComboBoxChannel->setAutoFillBackground(true);
	inputComboBoxChannel->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
	inputComboBoxChannel->setIconSize(QSize(16, 10));
	inputComboBoxChannel->setFrame(false);

	inputComboBoxLayoutChannel->addWidget(inputComboBoxChannel);


	verticalLayoutFrameChannel->addWidget(inputComboBoxChannel, 0, Qt::AlignHCenter);

	midiListChannel = new QListWidget(frameChannel);
	new QListWidgetItem(midiListChannel);
	midiListChannel->setObjectName(QString::fromUtf8(strcat("midiListChannel", strID)));
	QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Expanding);
	sizePolicy9.setHorizontalStretch(0);
	sizePolicy9.setVerticalStretch(0);
	sizePolicy9.setHeightForWidth(midiListChannel->sizePolicy().hasHeightForWidth());
	midiListChannel->setSizePolicy(sizePolicy9);
	midiListChannel->setMaximumSize(QSize(100, 16777215));
	midiListChannel->setFont(font);
	midiListChannel->setFrameShape(QFrame::Panel);
	midiListChannel->setLineWidth(2);

	verticalLayoutFrameChannel->addWidget(midiListChannel, 0, Qt::AlignHCenter);

	levelDialChannel = new QDial(frameChannel);
	levelDialChannel->setObjectName(QString::fromUtf8(strcat("levelDialChannel", strID)));
	sizePolicy9.setHeightForWidth(levelDialChannel->sizePolicy().hasHeightForWidth());
	levelDialChannel->setSizePolicy(sizePolicy9);

	verticalLayoutFrameChannel->addWidget(levelDialChannel);

	levelLabelChannel = new QLabel(frameChannel);
	levelLabelChannel->setObjectName(QString::fromUtf8(strcat("levelLabelChannel", strID)));
	QFont font3;
	font3.setPointSize(8);
	font3.setBold(false);
	font3.setItalic(false);
	font3.setWeight(50);
	font3.setStrikeOut(false);
	font3.setStyleStrategy(QFont::PreferAntialias);
	levelLabelChannel->setFont(font3);
	levelLabelChannel->setAlignment(Qt::AlignCenter);

	verticalLayoutFrameChannel->addWidget(levelLabelChannel);


	programUI->channelsContainerLayout->addWidget(frameChannel);
	
	
	// Retranslation
	nameLabelChannel->setText(QApplication::translate("LeandroClass", strcat("Channel ", strID) , Q_NULLPTR));
	setActiveButtonChannel->setText(QApplication::translate("LeandroClass", "Set Active", Q_NULLPTR));
	InputLabelChannel->setText(QApplication::translate("LeandroClass", "In", Q_NULLPTR));
	inputComboBoxChannel->clear();
	inputComboBoxChannel->insertItems(0, QStringList()
		<< QApplication::translate("LeandroClass", "MIDI Track", Q_NULLPTR)
		<< QApplication::translate("LeandroClass", "PC Keyboard", Q_NULLPTR)
	);

	midiListChannel->setSortingEnabled(true);

	levelLabelChannel->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));

	// Function connections

	QObject::connect(levelDialChannel, &QDial::valueChanged, this, &Channel::setVolume);
	QObject::connect(inputComboBoxChannel, &QComboBox::currentTextChanged, this, &Channel::setKeyboard);
	QObject::connect(midiListChannel, &QListWidget::currentItemChanged, this, &Channel::updateMidiTrack);
	

}

void Channel::removeFromGUI(Ui_LeandroClass* programUI) {
	programUI->channelsContainerLayout->removeWidget(frameChannel);
	delete(frameChannel);
	delete(verticalLayoutFrameChannel);
	delete(nameLabelChannel);
	delete(setActiveButtonChannel);
	delete(verticalSpacerChannel);
	delete(inputComboBoxLayoutChannel);
	delete(InputLabelChannel);
	delete(inputComboBoxChannel);
	delete(midiListChannel);
	delete(levelDialChannel);
	delete(levelLabelChannel);
}



// Setters

void Channel::setChannelTrack(midiTrack* miditrack) {
	const int track = miditrack->trackIndex;
	const MidiFile* file = (MidiFile*)miditrack->midifile;
	this->currentMidiTrack = miditrack;

	midiEvent tempEvent;

	for (int event = 0; event < (*file)[track].size(); event++) {
		if ((*file)[track][event].isNoteOn()) {
			tempEvent.startSample = ((*file)[track][event].seconds) * SAMPLE_RATE;
			tempEvent.durSample = ((*file)[track][event].getDurationInSeconds()) * SAMPLE_RATE;
			tempEvent.durSeconds = ((*file)[track][event].getDurationInSeconds());
			tempEvent.eventID = event;
			tempEvent.note = (*file)[track][event].getKeyNumber();
			tempEvent.velocity = (*file)[track][event].getVelocity();

			this->events.push(tempEvent);
		}
	}
	this->updateCallbackData();
}

void Channel::setChannelInstrument(Instrument* instrument) {
	this->instrument = instrument;	
	this->updateCallbackData();
}

void Channel::removeChannelInstrument() {
	this->instrument->~Instrument();
	delete(this->instrument);
	this->instrument = nullptr;
}

void Channel::addEffectToChannel(Effect* effect) {
	this->effects.push_back(effect);
	this->updateCallbackData();
}

void Channel::setVolume() {
	this->volume = (1.0/100.0)*(float)levelDialChannel->value();
	this->updateCallbackData();
}

void Channel::setKeyboard() {
	this->keyboard = false;
	if((inputComboBoxChannel->currentText().toStdString()=="PC Keyboard")) this->keyboard = true;
	this->updateCallbackData();
}

void Channel::updateMidiTrack() {
	for (int i =0; i<program->midiTracks.size();i++)
		if ((midiListChannel->currentItem()->text().toStdString() == program->midiTracks.at(i)->trackName)) {
			this->setChannelTrack(program->midiTracks.at(i));
			break;
		}
}

void Channel::setActive() {
	this->program->setActiveChannel(this);
}

