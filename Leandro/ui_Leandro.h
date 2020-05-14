/********************************************************************************
** Form generated from reading UI file 'Leandro.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEANDRO_H
#define UI_LEANDRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeandroClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QListWidget *instrumentsList;
    QPushButton *setInstrumentButton;
    QLabel *label_8;
    QListWidget *effectsList;
    QPushButton *addEffectButton;
    QScrollArea *scrollAreaChannels_2;
    QWidget *scrollAreaChannelsWidgetContents_2;
    QHBoxLayout *channelsContainerLayout;
    QFrame *frameChannel1;
    QVBoxLayout *verticalLayoutFrameChannel1;
    QHBoxLayout *channelTopLayout;
    QLabel *nameLabelChannel1;
    QPushButton *closeButtonChannel1;
    QPushButton *setActiveButtonChannel1_2;
    QSpacerItem *verticalSpacerChannel1;
    QComboBox *inputComboBoxChannel1_2;
    QListWidget *midiListChannel1_2;
    QDial *levelDialChannel1_2;
    QLabel *levelLabelChannel1_2;
    QFrame *frame_2;
    QHBoxLayout *activeChannelAssetsPanel;
    QFrame *instrumentFrameFrame;
    QGridLayout *gridLayout_2;
    QHBoxLayout *instrumentLayoutLayout;
    QHBoxLayout *instrumentLayout;
    QFrame *adsrInstrumentFrame;
    QGridLayout *gridLayout_3;
    QHBoxLayout *nameHLayout;
    QPushButton *deleteADSRButton;
    QLabel *instrumentNameLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *InstrumentNameADSR;
    QFrame *line_2;
    QVBoxLayout *framesVLayout;
    QFrame *oscillator1Frame;
    QVBoxLayout *verticalLayout_14;
    QLabel *oscillator1Label;
    QHBoxLayout *oscillator1HLayout;
    QVBoxLayout *oscillator1WaveVLayout;
    QLabel *waveform1Label;
    QComboBox *waveform1ComboBoxADSR;
    QHBoxLayout *oscillator1LevelHLayout;
    QLabel *level1Label;
    QDial *levelWF1DialADSR;
    QFrame *oscillator2Frame;
    QVBoxLayout *verticalLayout_15;
    QLabel *oscillator2Label;
    QHBoxLayout *oscillator2HLayout;
    QVBoxLayout *waveform2VLayout;
    QLabel *waveform2Label;
    QComboBox *waveform2ComboBoxADSR;
    QHBoxLayout *oscillator2LevelHLayout;
    QLabel *level2Label;
    QDial *levelWF2DialADSR;
    QFrame *line;
    QFrame *envelopeParamsFrame;
    QVBoxLayout *verticalLayout_16;
    QSpacerItem *verticalSpacer_9;
    QLabel *envelopeParamsLabel;
    QHBoxLayout *envelopeParamsHLayout;
    QVBoxLayout *attackVLayout;
    QDial *attackDialADSR;
    QLabel *attackLabel;
    QVBoxLayout *decayVLayout;
    QDial *decayDialADSR;
    QLabel *decayLabel;
    QVBoxLayout *sustainVLayout;
    QDial *sustainLevelDialADSR;
    QLabel *sustainLevelLabel;
    QVBoxLayout *releaseVLayout_5;
    QDial *sustainRateDialADSR;
    QLabel *sustainRateLabel;
    QVBoxLayout *releaseVLayout;
    QDial *releaseDialADSR;
    QLabel *releaseLabel;
    QSpacerItem *verticalSpacer_10;
    QFrame *additiveInstrumentFrame;
    QGridLayout *gridLayout_7;
    QHBoxLayout *nameHLayout_4;
    QPushButton *deleteAdditiveButton;
    QLabel *instrumentNameLabel_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *instrumentNameAdditive;
    QFrame *line_8;
    QVBoxLayout *framesVLayout_4;
    QFrame *oscillator2Frame_4;
    QVBoxLayout *verticalLayout_24;
    QLabel *oscillator2Label_4;
    QFrame *slidersFrame;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_39;
    QSlider *sliderH0;
    QLabel *sliderLabelH0;
    QVBoxLayout *verticalLayout_42;
    QSlider *sliderH1;
    QLabel *label_29;
    QVBoxLayout *verticalLayout_8;
    QSlider *sliderH2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_33;
    QSlider *sliderH3;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_40;
    QSlider *sliderH4;
    QLabel *label_27;
    QVBoxLayout *verticalLayout_34;
    QSlider *sliderH5;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_35;
    QSlider *sliderH6;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_41;
    QSlider *sliderH7;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_36;
    QSlider *sliderH8;
    QLabel *label_23;
    QVBoxLayout *verticalLayout_37;
    QSlider *sliderH9;
    QLabel *label_24;
    QVBoxLayout *verticalLayout_38;
    QSlider *sliderH10;
    QLabel *label_25;
    QVBoxLayout *verticalLayout_3;
    QSlider *sliderH11;
    QLabel *label_2;
    QFrame *line_9;
    QFrame *samplingInstrumentFrame;
    QGridLayout *gridLayout_6;
    QHBoxLayout *nameHLayout_3;
    QPushButton *deleteSamplingButton;
    QLabel *instrumentNameLabel_3;
    QSpacerItem *horizontalSpacer_11;
    QLabel *instrumentNameSampling;
    QFrame *line_6;
    QVBoxLayout *framesVLayout_3;
    QFrame *line_7;
    QFrame *envelopeParamsFrame_3;
    QVBoxLayout *verticalLayout_22;
    QLabel *envelopeParamsLabel_3;
    QHBoxLayout *envelopeParamsHLayout_3;
    QVBoxLayout *sustainVLayout_3;
    QSpacerItem *verticalSpacer_5;
    QDial *samplingLoopStartDial;
    QLabel *sustainLabel_3;
    QSpacerItem *verticalSpacer_7;
    QVBoxLayout *releaseVLayout_3;
    QSpacerItem *verticalSpacer_6;
    QDial *samplingLoopEndDial;
    QLabel *releaseLabel_3;
    QSpacerItem *verticalSpacer_8;
    QFrame *karplusInstrumentFrame;
    QGridLayout *gridLayout_5;
    QHBoxLayout *nameHLayout_2;
    QPushButton *deleteKarplusButton;
    QLabel *instrumentNameLabel_2;
    QSpacerItem *horizontalSpacer_10;
    QLabel *instrumentNameKarplus;
    QFrame *line_4;
    QVBoxLayout *framesVLayout_2;
    QFrame *envelopeParamsFrame_2;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *envelopeParamsHLayout_2;
    QVBoxLayout *decayVLayout_2;
    QSlider *karplusStretchSlider;
    QLabel *decayLabel_2;
    QVBoxLayout *releaseVLayout_2;
    QSlider *karplusDecaySlider;
    QLabel *releaseLabel_2;
    QVBoxLayout *sustainVLayout_2;
    QSlider *karplusBlendSlider;
    QLabel *sustainLabel_2;
    QScrollArea *effectsScrollArea;
    QWidget *effectsScrollAreaContents;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *effectsScrollAreaLayout;
    QHBoxLayout *effectsHorizontalLayout;
    QFrame *eq8Frame;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *delete8EqButton;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *eq8MoveLeftButton;
    QPushButton *eq8MoveRightButton;
    QFrame *line_10;
    QFrame *oscillator2Frame_6;
    QVBoxLayout *verticalLayout_27;
    QLabel *oscillator2Label_6;
    QFrame *slidersFrame_3;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_50;
    QSlider *eqSlider100;
    QLabel *sliderLabelH0_3;
    QVBoxLayout *verticalLayout_51;
    QSlider *eqSlider200;
    QLabel *label_35;
    QVBoxLayout *verticalLayout_10;
    QSlider *eqSlider400;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_52;
    QSlider *eqSlider800;
    QLabel *label_36;
    QVBoxLayout *verticalLayout_53;
    QSlider *eqSlider1k4;
    QLabel *label_37;
    QVBoxLayout *verticalLayout_54;
    QSlider *eqSlider2k7;
    QLabel *label_38;
    QVBoxLayout *verticalLayout_55;
    QSlider *eqSlider5k;
    QLabel *label_39;
    QVBoxLayout *verticalLayout_56;
    QSlider *eqSlider10k;
    QLabel *label_40;
    QFrame *reverbEffectFrame;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *deleteReverbButton;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *reverbMoveLeftButton;
    QPushButton *reverbMoveRightButton;
    QFrame *line_11;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_12;
    QComboBox *reverbTypeComboBox;
    QFrame *oscillator2Frame_7;
    QVBoxLayout *verticalLayout_28;
    QLabel *oscillator2Label_7;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_13;
    QDial *reverbDelayDial;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_23;
    QDial *reverbAttnDial;
    QLabel *label_14;
    QFrame *flangerEffectFrame;
    QVBoxLayout *verticalLayout_31;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteFlangerButton;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *flangerMoveLeftButton;
    QPushButton *flangerMoveRightButton;
    QFrame *line_12;
    QFrame *oscillator2Frame_8;
    QVBoxLayout *verticalLayout_32;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_43;
    QDial *flangerGFBDial;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_44;
    QDial *flangerMwDial;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_45;
    QDial *flangerM0Dial;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_46;
    QDial *flangerGFFDial;
    QLabel *label_30;
    QVBoxLayout *verticalLayout_47;
    QSlider *flangerF0Slider;
    QLabel *label_31;
    QFrame *vibratoEffectFrame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteVibratoButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *vibratoMoveLeftButton;
    QPushButton *vibratoMoveRightButton;
    QFrame *line_3;
    QFrame *oscillator2Frame_5;
    QVBoxLayout *verticalLayout_26;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_5;
    QSlider *vibratoF0Slider;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_3;
    QDial *vibratoMAvgDial;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer;
    QDial *vibratoWidthDial;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_2;
    QFrame *wahwahEffectFrame;
    QVBoxLayout *verticalLayout_29;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *deleteWahwahButton;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *wahwahMoveLeftButton;
    QPushButton *wahwahMoveRightButton;
    QFrame *line_13;
    QFrame *oscillator2Frame_9;
    QVBoxLayout *verticalLayout_30;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_48;
    QSlider *wahwahFMinSlider;
    QLabel *label_32;
    QVBoxLayout *verticalLayout_49;
    QSlider *wahwahLFOSlider;
    QLabel *label_33;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *newChannelButton;
    QPushButton *importMidiButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *playButton_2;
    QPushButton *pauseButton;
    QPushButton *stopButton_2;
    QPushButton *recordButton_2;
    QSpacerItem *horizontalSpacer_4;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeandroClass)
    {
        if (LeandroClass->objectName().isEmpty())
            LeandroClass->setObjectName(QStringLiteral("LeandroClass"));
        LeandroClass->resize(2989, 783);
        LeandroClass->setMinimumSize(QSize(800, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(253, 180, 50, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(165, 165, 165, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(135, 135, 135, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(42, 42, 42, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(90, 90, 90, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 170, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush7(QColor(110, 110, 110, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush8(QColor(255, 181, 50, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush8);
        QBrush brush9(QColor(255, 255, 255, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush9);
        QBrush brush10(QColor(195, 195, 195, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(0, 255, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush11);
        QBrush brush12(QColor(255, 255, 220, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush12);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        LeandroClass->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Helvetica World"));
        LeandroClass->setFont(font);
        LeandroClass->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(LeandroClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(20, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush13(QColor(74, 74, 74, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        frame_3->setPalette(palette1);
        frame_3->setAutoFillBackground(true);
        frame_3->setFrameShape(QFrame::Panel);
        frame_3->setFrameShadow(QFrame::Sunken);
        frame_3->setLineWidth(3);
        verticalLayout_2 = new QVBoxLayout(frame_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 5, -1, -1);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_7->setFont(font1);

        verticalLayout_2->addWidget(label_7, 0, Qt::AlignHCenter);

        instrumentsList = new QListWidget(frame_3);
        instrumentsList->setObjectName(QStringLiteral("instrumentsList"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(instrumentsList->sizePolicy().hasHeightForWidth());
        instrumentsList->setSizePolicy(sizePolicy);
        instrumentsList->setMaximumSize(QSize(100, 16777215));
        instrumentsList->setDragEnabled(false);
        instrumentsList->setDragDropMode(QAbstractItemView::DragOnly);

        verticalLayout_2->addWidget(instrumentsList);

        setInstrumentButton = new QPushButton(frame_3);
        setInstrumentButton->setObjectName(QStringLiteral("setInstrumentButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(setInstrumentButton->sizePolicy().hasHeightForWidth());
        setInstrumentButton->setSizePolicy(sizePolicy1);
        setInstrumentButton->setMaximumSize(QSize(16777215, 15));
        setInstrumentButton->setBaseSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(7);
        setInstrumentButton->setFont(font2);
        setInstrumentButton->setAutoFillBackground(true);
        setInstrumentButton->setFlat(true);

        verticalLayout_2->addWidget(setInstrumentButton, 0, Qt::AlignHCenter);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        verticalLayout_2->addWidget(label_8, 0, Qt::AlignHCenter);

        effectsList = new QListWidget(frame_3);
        effectsList->setObjectName(QStringLiteral("effectsList"));
        sizePolicy.setHeightForWidth(effectsList->sizePolicy().hasHeightForWidth());
        effectsList->setSizePolicy(sizePolicy);
        effectsList->setMinimumSize(QSize(0, 0));
        effectsList->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(effectsList);

        addEffectButton = new QPushButton(frame_3);
        addEffectButton->setObjectName(QStringLiteral("addEffectButton"));
        sizePolicy1.setHeightForWidth(addEffectButton->sizePolicy().hasHeightForWidth());
        addEffectButton->setSizePolicy(sizePolicy1);
        addEffectButton->setMaximumSize(QSize(16777215, 15));
        addEffectButton->setFont(font2);
        addEffectButton->setAutoFillBackground(true);
        addEffectButton->setFlat(true);

        verticalLayout_2->addWidget(addEffectButton, 0, Qt::AlignHCenter);


        horizontalLayout_5->addWidget(frame_3, 0, Qt::AlignHCenter);

        scrollAreaChannels_2 = new QScrollArea(centralWidget);
        scrollAreaChannels_2->setObjectName(QStringLiteral("scrollAreaChannels_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaChannels_2->sizePolicy().hasHeightForWidth());
        scrollAreaChannels_2->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        scrollAreaChannels_2->setPalette(palette2);
        scrollAreaChannels_2->setAutoFillBackground(true);
        scrollAreaChannels_2->setFrameShape(QFrame::Panel);
        scrollAreaChannels_2->setFrameShadow(QFrame::Sunken);
        scrollAreaChannels_2->setLineWidth(3);
        scrollAreaChannels_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaChannels_2->setWidgetResizable(true);
        scrollAreaChannelsWidgetContents_2 = new QWidget();
        scrollAreaChannelsWidgetContents_2->setObjectName(QStringLiteral("scrollAreaChannelsWidgetContents_2"));
        scrollAreaChannelsWidgetContents_2->setGeometry(QRect(0, 0, 2831, 283));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaChannelsWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaChannelsWidgetContents_2->setSizePolicy(sizePolicy3);
        channelsContainerLayout = new QHBoxLayout(scrollAreaChannelsWidgetContents_2);
        channelsContainerLayout->setSpacing(6);
        channelsContainerLayout->setContentsMargins(11, 11, 11, 11);
        channelsContainerLayout->setObjectName(QStringLiteral("channelsContainerLayout"));
        channelsContainerLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        frameChannel1 = new QFrame(scrollAreaChannelsWidgetContents_2);
        frameChannel1->setObjectName(QStringLiteral("frameChannel1"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frameChannel1->sizePolicy().hasHeightForWidth());
        frameChannel1->setSizePolicy(sizePolicy4);
        frameChannel1->setMaximumSize(QSize(125, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        frameChannel1->setPalette(palette3);
        frameChannel1->setAutoFillBackground(true);
        frameChannel1->setFrameShape(QFrame::Panel);
        frameChannel1->setFrameShadow(QFrame::Raised);
        frameChannel1->setLineWidth(3);
        verticalLayoutFrameChannel1 = new QVBoxLayout(frameChannel1);
        verticalLayoutFrameChannel1->setSpacing(6);
        verticalLayoutFrameChannel1->setContentsMargins(11, 11, 11, 11);
        verticalLayoutFrameChannel1->setObjectName(QStringLiteral("verticalLayoutFrameChannel1"));
        channelTopLayout = new QHBoxLayout();
        channelTopLayout->setSpacing(6);
        channelTopLayout->setObjectName(QStringLiteral("channelTopLayout"));
        nameLabelChannel1 = new QLabel(frameChannel1);
        nameLabelChannel1->setObjectName(QStringLiteral("nameLabelChannel1"));
        nameLabelChannel1->setFont(font1);
        nameLabelChannel1->setAlignment(Qt::AlignCenter);

        channelTopLayout->addWidget(nameLabelChannel1);

        closeButtonChannel1 = new QPushButton(frameChannel1);
        closeButtonChannel1->setObjectName(QStringLiteral("closeButtonChannel1"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(closeButtonChannel1->sizePolicy().hasHeightForWidth());
        closeButtonChannel1->setSizePolicy(sizePolicy5);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/037-minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeButtonChannel1->setIcon(icon);
        closeButtonChannel1->setIconSize(QSize(12, 12));
        closeButtonChannel1->setFlat(true);

        channelTopLayout->addWidget(closeButtonChannel1);


        verticalLayoutFrameChannel1->addLayout(channelTopLayout);

        setActiveButtonChannel1_2 = new QPushButton(frameChannel1);
        setActiveButtonChannel1_2->setObjectName(QStringLiteral("setActiveButtonChannel1_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(setActiveButtonChannel1_2->sizePolicy().hasHeightForWidth());
        setActiveButtonChannel1_2->setSizePolicy(sizePolicy6);
        setActiveButtonChannel1_2->setMinimumSize(QSize(0, 17));
        setActiveButtonChannel1_2->setFont(font2);
        setActiveButtonChannel1_2->setAutoFillBackground(true);
        setActiveButtonChannel1_2->setFlat(true);

        verticalLayoutFrameChannel1->addWidget(setActiveButtonChannel1_2, 0, Qt::AlignHCenter);

        verticalSpacerChannel1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFrameChannel1->addItem(verticalSpacerChannel1);

        inputComboBoxChannel1_2 = new QComboBox(frameChannel1);
        inputComboBoxChannel1_2->setObjectName(QStringLiteral("inputComboBoxChannel1_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(inputComboBoxChannel1_2->sizePolicy().hasHeightForWidth());
        inputComboBoxChannel1_2->setSizePolicy(sizePolicy7);
        inputComboBoxChannel1_2->setMinimumSize(QSize(0, 17));
        inputComboBoxChannel1_2->setFont(font2);
        inputComboBoxChannel1_2->setContextMenuPolicy(Qt::DefaultContextMenu);
        inputComboBoxChannel1_2->setAutoFillBackground(true);
        inputComboBoxChannel1_2->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        inputComboBoxChannel1_2->setIconSize(QSize(16, 10));
        inputComboBoxChannel1_2->setFrame(false);

        verticalLayoutFrameChannel1->addWidget(inputComboBoxChannel1_2, 0, Qt::AlignHCenter);

        midiListChannel1_2 = new QListWidget(frameChannel1);
        new QListWidgetItem(midiListChannel1_2);
        midiListChannel1_2->setObjectName(QStringLiteral("midiListChannel1_2"));
        sizePolicy4.setHeightForWidth(midiListChannel1_2->sizePolicy().hasHeightForWidth());
        midiListChannel1_2->setSizePolicy(sizePolicy4);
        midiListChannel1_2->setMaximumSize(QSize(100, 16777215));
        midiListChannel1_2->setFont(font);
        midiListChannel1_2->setFrameShape(QFrame::Panel);
        midiListChannel1_2->setLineWidth(2);

        verticalLayoutFrameChannel1->addWidget(midiListChannel1_2, 0, Qt::AlignHCenter);

        levelDialChannel1_2 = new QDial(frameChannel1);
        levelDialChannel1_2->setObjectName(QStringLiteral("levelDialChannel1_2"));
        sizePolicy4.setHeightForWidth(levelDialChannel1_2->sizePolicy().hasHeightForWidth());
        levelDialChannel1_2->setSizePolicy(sizePolicy4);

        verticalLayoutFrameChannel1->addWidget(levelDialChannel1_2);

        levelLabelChannel1_2 = new QLabel(frameChannel1);
        levelLabelChannel1_2->setObjectName(QStringLiteral("levelLabelChannel1_2"));
        QFont font3;
        font3.setFamily(QStringLiteral("Oxygen"));
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        font3.setStyleStrategy(QFont::PreferAntialias);
        levelLabelChannel1_2->setFont(font3);
        levelLabelChannel1_2->setAlignment(Qt::AlignCenter);

        verticalLayoutFrameChannel1->addWidget(levelLabelChannel1_2);


        channelsContainerLayout->addWidget(frameChannel1);

        frame_2 = new QFrame(scrollAreaChannelsWidgetContents_2);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        channelsContainerLayout->addWidget(frame_2);

        scrollAreaChannels_2->setWidget(scrollAreaChannelsWidgetContents_2);

        horizontalLayout_5->addWidget(scrollAreaChannels_2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        activeChannelAssetsPanel = new QHBoxLayout();
        activeChannelAssetsPanel->setSpacing(6);
        activeChannelAssetsPanel->setObjectName(QStringLiteral("activeChannelAssetsPanel"));
        instrumentFrameFrame = new QFrame(centralWidget);
        instrumentFrameFrame->setObjectName(QStringLiteral("instrumentFrameFrame"));
        instrumentFrameFrame->setMinimumSize(QSize(20, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        instrumentFrameFrame->setPalette(palette4);
        instrumentFrameFrame->setAutoFillBackground(true);
        instrumentFrameFrame->setFrameShape(QFrame::Panel);
        instrumentFrameFrame->setFrameShadow(QFrame::Sunken);
        instrumentFrameFrame->setLineWidth(3);
        gridLayout_2 = new QGridLayout(instrumentFrameFrame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        instrumentLayoutLayout = new QHBoxLayout();
        instrumentLayoutLayout->setSpacing(6);
        instrumentLayoutLayout->setObjectName(QStringLiteral("instrumentLayoutLayout"));
        instrumentLayout = new QHBoxLayout();
        instrumentLayout->setSpacing(6);
        instrumentLayout->setObjectName(QStringLiteral("instrumentLayout"));
        adsrInstrumentFrame = new QFrame(instrumentFrameFrame);
        adsrInstrumentFrame->setObjectName(QStringLiteral("adsrInstrumentFrame"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(adsrInstrumentFrame->sizePolicy().hasHeightForWidth());
        adsrInstrumentFrame->setSizePolicy(sizePolicy8);
        adsrInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        adsrInstrumentFrame->setPalette(palette5);
        adsrInstrumentFrame->setAutoFillBackground(true);
        adsrInstrumentFrame->setFrameShape(QFrame::Panel);
        adsrInstrumentFrame->setFrameShadow(QFrame::Raised);
        adsrInstrumentFrame->setLineWidth(2);
        gridLayout_3 = new QGridLayout(adsrInstrumentFrame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(9, 6, 9, 9);
        nameHLayout = new QHBoxLayout();
        nameHLayout->setSpacing(6);
        nameHLayout->setObjectName(QStringLiteral("nameHLayout"));
        deleteADSRButton = new QPushButton(adsrInstrumentFrame);
        deleteADSRButton->setObjectName(QStringLiteral("deleteADSRButton"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(deleteADSRButton->sizePolicy().hasHeightForWidth());
        deleteADSRButton->setSizePolicy(sizePolicy9);
        deleteADSRButton->setFocusPolicy(Qt::StrongFocus);
        deleteADSRButton->setIcon(icon);
        deleteADSRButton->setIconSize(QSize(15, 15));
        deleteADSRButton->setFlat(true);

        nameHLayout->addWidget(deleteADSRButton);

        instrumentNameLabel = new QLabel(adsrInstrumentFrame);
        instrumentNameLabel->setObjectName(QStringLiteral("instrumentNameLabel"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(instrumentNameLabel->sizePolicy().hasHeightForWidth());
        instrumentNameLabel->setSizePolicy(sizePolicy10);
        QFont font4;
        font4.setFamily(QStringLiteral("Helvetica World"));
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(75);
        instrumentNameLabel->setFont(font4);

        nameHLayout->addWidget(instrumentNameLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        nameHLayout->addItem(horizontalSpacer_3);

        InstrumentNameADSR = new QLabel(adsrInstrumentFrame);
        InstrumentNameADSR->setObjectName(QStringLiteral("InstrumentNameADSR"));

        nameHLayout->addWidget(InstrumentNameADSR, 0, Qt::AlignLeft);


        gridLayout_3->addLayout(nameHLayout, 0, 0, 1, 1);

        line_2 = new QFrame(adsrInstrumentFrame);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 1, 0, 1, 1);

        framesVLayout = new QVBoxLayout();
        framesVLayout->setSpacing(6);
        framesVLayout->setObjectName(QStringLiteral("framesVLayout"));
        oscillator1Frame = new QFrame(adsrInstrumentFrame);
        oscillator1Frame->setObjectName(QStringLiteral("oscillator1Frame"));
        oscillator1Frame->setFrameShape(QFrame::Panel);
        oscillator1Frame->setFrameShadow(QFrame::Sunken);
        oscillator1Frame->setLineWidth(2);
        verticalLayout_14 = new QVBoxLayout(oscillator1Frame);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(-1, 2, -1, 2);
        oscillator1Label = new QLabel(oscillator1Frame);
        oscillator1Label->setObjectName(QStringLiteral("oscillator1Label"));
        oscillator1Label->setMaximumSize(QSize(16777215, 14));
        oscillator1Label->setFont(font1);

        verticalLayout_14->addWidget(oscillator1Label, 0, Qt::AlignHCenter);

        oscillator1HLayout = new QHBoxLayout();
        oscillator1HLayout->setSpacing(6);
        oscillator1HLayout->setObjectName(QStringLiteral("oscillator1HLayout"));
        oscillator1WaveVLayout = new QVBoxLayout();
        oscillator1WaveVLayout->setSpacing(6);
        oscillator1WaveVLayout->setObjectName(QStringLiteral("oscillator1WaveVLayout"));
        waveform1Label = new QLabel(oscillator1Frame);
        waveform1Label->setObjectName(QStringLiteral("waveform1Label"));
        sizePolicy10.setHeightForWidth(waveform1Label->sizePolicy().hasHeightForWidth());
        waveform1Label->setSizePolicy(sizePolicy10);
        waveform1Label->setMaximumSize(QSize(16777215, 10));

        oscillator1WaveVLayout->addWidget(waveform1Label);

        waveform1ComboBoxADSR = new QComboBox(oscillator1Frame);
        waveform1ComboBoxADSR->setObjectName(QStringLiteral("waveform1ComboBoxADSR"));
        sizePolicy1.setHeightForWidth(waveform1ComboBoxADSR->sizePolicy().hasHeightForWidth());
        waveform1ComboBoxADSR->setSizePolicy(sizePolicy1);
        waveform1ComboBoxADSR->setMaximumSize(QSize(16777215, 15));
        waveform1ComboBoxADSR->setAutoFillBackground(true);
        waveform1ComboBoxADSR->setFrame(false);

        oscillator1WaveVLayout->addWidget(waveform1ComboBoxADSR);


        oscillator1HLayout->addLayout(oscillator1WaveVLayout);

        oscillator1LevelHLayout = new QHBoxLayout();
        oscillator1LevelHLayout->setSpacing(6);
        oscillator1LevelHLayout->setObjectName(QStringLiteral("oscillator1LevelHLayout"));
        level1Label = new QLabel(oscillator1Frame);
        level1Label->setObjectName(QStringLiteral("level1Label"));
        sizePolicy1.setHeightForWidth(level1Label->sizePolicy().hasHeightForWidth());
        level1Label->setSizePolicy(sizePolicy1);
        level1Label->setMaximumSize(QSize(16777215, 11));

        oscillator1LevelHLayout->addWidget(level1Label);

        levelWF1DialADSR = new QDial(oscillator1Frame);
        levelWF1DialADSR->setObjectName(QStringLiteral("levelWF1DialADSR"));
        sizePolicy1.setHeightForWidth(levelWF1DialADSR->sizePolicy().hasHeightForWidth());
        levelWF1DialADSR->setSizePolicy(sizePolicy1);
        levelWF1DialADSR->setMaximumSize(QSize(57, 16777215));
        levelWF1DialADSR->setMaximum(100);
        levelWF1DialADSR->setValue(1);
        levelWF1DialADSR->setWrapping(false);
        levelWF1DialADSR->setNotchesVisible(true);

        oscillator1LevelHLayout->addWidget(levelWF1DialADSR);


        oscillator1HLayout->addLayout(oscillator1LevelHLayout);


        verticalLayout_14->addLayout(oscillator1HLayout);


        framesVLayout->addWidget(oscillator1Frame);

        oscillator2Frame = new QFrame(adsrInstrumentFrame);
        oscillator2Frame->setObjectName(QStringLiteral("oscillator2Frame"));
        sizePolicy10.setHeightForWidth(oscillator2Frame->sizePolicy().hasHeightForWidth());
        oscillator2Frame->setSizePolicy(sizePolicy10);
        oscillator2Frame->setFrameShape(QFrame::Panel);
        oscillator2Frame->setFrameShadow(QFrame::Sunken);
        oscillator2Frame->setLineWidth(2);
        verticalLayout_15 = new QVBoxLayout(oscillator2Frame);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(-1, 2, -1, 2);
        oscillator2Label = new QLabel(oscillator2Frame);
        oscillator2Label->setObjectName(QStringLiteral("oscillator2Label"));
        oscillator2Label->setMaximumSize(QSize(16777215, 14));
        oscillator2Label->setFont(font1);

        verticalLayout_15->addWidget(oscillator2Label, 0, Qt::AlignHCenter);

        oscillator2HLayout = new QHBoxLayout();
        oscillator2HLayout->setSpacing(6);
        oscillator2HLayout->setObjectName(QStringLiteral("oscillator2HLayout"));
        waveform2VLayout = new QVBoxLayout();
        waveform2VLayout->setSpacing(6);
        waveform2VLayout->setObjectName(QStringLiteral("waveform2VLayout"));
        waveform2Label = new QLabel(oscillator2Frame);
        waveform2Label->setObjectName(QStringLiteral("waveform2Label"));
        sizePolicy10.setHeightForWidth(waveform2Label->sizePolicy().hasHeightForWidth());
        waveform2Label->setSizePolicy(sizePolicy10);
        waveform2Label->setMaximumSize(QSize(16777215, 10));

        waveform2VLayout->addWidget(waveform2Label);

        waveform2ComboBoxADSR = new QComboBox(oscillator2Frame);
        waveform2ComboBoxADSR->setObjectName(QStringLiteral("waveform2ComboBoxADSR"));
        sizePolicy1.setHeightForWidth(waveform2ComboBoxADSR->sizePolicy().hasHeightForWidth());
        waveform2ComboBoxADSR->setSizePolicy(sizePolicy1);
        waveform2ComboBoxADSR->setMaximumSize(QSize(16777215, 15));
        waveform2ComboBoxADSR->setAutoFillBackground(true);
        waveform2ComboBoxADSR->setFrame(false);

        waveform2VLayout->addWidget(waveform2ComboBoxADSR);


        oscillator2HLayout->addLayout(waveform2VLayout);

        oscillator2LevelHLayout = new QHBoxLayout();
        oscillator2LevelHLayout->setSpacing(6);
        oscillator2LevelHLayout->setObjectName(QStringLiteral("oscillator2LevelHLayout"));
        level2Label = new QLabel(oscillator2Frame);
        level2Label->setObjectName(QStringLiteral("level2Label"));
        sizePolicy1.setHeightForWidth(level2Label->sizePolicy().hasHeightForWidth());
        level2Label->setSizePolicy(sizePolicy1);
        level2Label->setMaximumSize(QSize(16777215, 11));

        oscillator2LevelHLayout->addWidget(level2Label);

        levelWF2DialADSR = new QDial(oscillator2Frame);
        levelWF2DialADSR->setObjectName(QStringLiteral("levelWF2DialADSR"));
        sizePolicy1.setHeightForWidth(levelWF2DialADSR->sizePolicy().hasHeightForWidth());
        levelWF2DialADSR->setSizePolicy(sizePolicy1);
        levelWF2DialADSR->setMaximumSize(QSize(57, 16777215));
        levelWF2DialADSR->setMaximum(100);
        levelWF2DialADSR->setWrapping(false);
        levelWF2DialADSR->setNotchTarget(3.7);
        levelWF2DialADSR->setNotchesVisible(true);

        oscillator2LevelHLayout->addWidget(levelWF2DialADSR);


        oscillator2HLayout->addLayout(oscillator2LevelHLayout);


        verticalLayout_15->addLayout(oscillator2HLayout);


        framesVLayout->addWidget(oscillator2Frame);

        line = new QFrame(adsrInstrumentFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        framesVLayout->addWidget(line);

        envelopeParamsFrame = new QFrame(adsrInstrumentFrame);
        envelopeParamsFrame->setObjectName(QStringLiteral("envelopeParamsFrame"));
        QSizePolicy sizePolicy11(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(envelopeParamsFrame->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame->setSizePolicy(sizePolicy11);
        envelopeParamsFrame->setFrameShape(QFrame::Panel);
        envelopeParamsFrame->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame->setLineWidth(2);
        envelopeParamsFrame->setMidLineWidth(0);
        verticalLayout_16 = new QVBoxLayout(envelopeParamsFrame);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(-1, 2, -1, 2);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_9);

        envelopeParamsLabel = new QLabel(envelopeParamsFrame);
        envelopeParamsLabel->setObjectName(QStringLiteral("envelopeParamsLabel"));
        envelopeParamsLabel->setMaximumSize(QSize(16777215, 14));
        envelopeParamsLabel->setFont(font1);

        verticalLayout_16->addWidget(envelopeParamsLabel, 0, Qt::AlignHCenter);

        envelopeParamsHLayout = new QHBoxLayout();
        envelopeParamsHLayout->setSpacing(6);
        envelopeParamsHLayout->setObjectName(QStringLiteral("envelopeParamsHLayout"));
        attackVLayout = new QVBoxLayout();
        attackVLayout->setSpacing(6);
        attackVLayout->setObjectName(QStringLiteral("attackVLayout"));
        attackDialADSR = new QDial(envelopeParamsFrame);
        attackDialADSR->setObjectName(QStringLiteral("attackDialADSR"));
        sizePolicy8.setHeightForWidth(attackDialADSR->sizePolicy().hasHeightForWidth());
        attackDialADSR->setSizePolicy(sizePolicy8);
        attackDialADSR->setMaximumSize(QSize(60, 175885));
        attackDialADSR->setMinimum(5);
        attackDialADSR->setMaximum(15000);
        attackDialADSR->setSingleStep(1);
        attackDialADSR->setNotchesVisible(true);

        attackVLayout->addWidget(attackDialADSR);

        attackLabel = new QLabel(envelopeParamsFrame);
        attackLabel->setObjectName(QStringLiteral("attackLabel"));
        sizePolicy8.setHeightForWidth(attackLabel->sizePolicy().hasHeightForWidth());
        attackLabel->setSizePolicy(sizePolicy8);

        attackVLayout->addWidget(attackLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(attackVLayout);

        decayVLayout = new QVBoxLayout();
        decayVLayout->setSpacing(6);
        decayVLayout->setObjectName(QStringLiteral("decayVLayout"));
        decayDialADSR = new QDial(envelopeParamsFrame);
        decayDialADSR->setObjectName(QStringLiteral("decayDialADSR"));
        sizePolicy8.setHeightForWidth(decayDialADSR->sizePolicy().hasHeightForWidth());
        decayDialADSR->setSizePolicy(sizePolicy8);
        decayDialADSR->setMaximumSize(QSize(60, 16777215));
        decayDialADSR->setMinimum(5);
        decayDialADSR->setMaximum(15000);
        decayDialADSR->setNotchesVisible(true);

        decayVLayout->addWidget(decayDialADSR);

        decayLabel = new QLabel(envelopeParamsFrame);
        decayLabel->setObjectName(QStringLiteral("decayLabel"));
        sizePolicy8.setHeightForWidth(decayLabel->sizePolicy().hasHeightForWidth());
        decayLabel->setSizePolicy(sizePolicy8);

        decayVLayout->addWidget(decayLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(decayVLayout);

        sustainVLayout = new QVBoxLayout();
        sustainVLayout->setSpacing(6);
        sustainVLayout->setObjectName(QStringLiteral("sustainVLayout"));
        sustainLevelDialADSR = new QDial(envelopeParamsFrame);
        sustainLevelDialADSR->setObjectName(QStringLiteral("sustainLevelDialADSR"));
        sizePolicy8.setHeightForWidth(sustainLevelDialADSR->sizePolicy().hasHeightForWidth());
        sustainLevelDialADSR->setSizePolicy(sizePolicy8);
        sustainLevelDialADSR->setMaximumSize(QSize(60, 16777215));
        sustainLevelDialADSR->setNotchesVisible(true);

        sustainVLayout->addWidget(sustainLevelDialADSR);

        sustainLevelLabel = new QLabel(envelopeParamsFrame);
        sustainLevelLabel->setObjectName(QStringLiteral("sustainLevelLabel"));
        sizePolicy8.setHeightForWidth(sustainLevelLabel->sizePolicy().hasHeightForWidth());
        sustainLevelLabel->setSizePolicy(sizePolicy8);

        sustainVLayout->addWidget(sustainLevelLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(sustainVLayout);

        releaseVLayout_5 = new QVBoxLayout();
        releaseVLayout_5->setSpacing(6);
        releaseVLayout_5->setObjectName(QStringLiteral("releaseVLayout_5"));
        sustainRateDialADSR = new QDial(envelopeParamsFrame);
        sustainRateDialADSR->setObjectName(QStringLiteral("sustainRateDialADSR"));
        sizePolicy8.setHeightForWidth(sustainRateDialADSR->sizePolicy().hasHeightForWidth());
        sustainRateDialADSR->setSizePolicy(sizePolicy8);
        sustainRateDialADSR->setMaximumSize(QSize(60, 16777215));
        sustainRateDialADSR->setMaximum(1000);
        sustainRateDialADSR->setNotchesVisible(true);

        releaseVLayout_5->addWidget(sustainRateDialADSR);

        sustainRateLabel = new QLabel(envelopeParamsFrame);
        sustainRateLabel->setObjectName(QStringLiteral("sustainRateLabel"));
        sizePolicy8.setHeightForWidth(sustainRateLabel->sizePolicy().hasHeightForWidth());
        sustainRateLabel->setSizePolicy(sizePolicy8);

        releaseVLayout_5->addWidget(sustainRateLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(releaseVLayout_5);

        releaseVLayout = new QVBoxLayout();
        releaseVLayout->setSpacing(6);
        releaseVLayout->setObjectName(QStringLiteral("releaseVLayout"));
        releaseDialADSR = new QDial(envelopeParamsFrame);
        releaseDialADSR->setObjectName(QStringLiteral("releaseDialADSR"));
        sizePolicy8.setHeightForWidth(releaseDialADSR->sizePolicy().hasHeightForWidth());
        releaseDialADSR->setSizePolicy(sizePolicy8);
        releaseDialADSR->setMaximumSize(QSize(60, 16777215));
        releaseDialADSR->setMinimum(1);
        releaseDialADSR->setMaximum(15000);
        releaseDialADSR->setNotchesVisible(true);

        releaseVLayout->addWidget(releaseDialADSR);

        releaseLabel = new QLabel(envelopeParamsFrame);
        releaseLabel->setObjectName(QStringLiteral("releaseLabel"));
        sizePolicy8.setHeightForWidth(releaseLabel->sizePolicy().hasHeightForWidth());
        releaseLabel->setSizePolicy(sizePolicy8);

        releaseVLayout->addWidget(releaseLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(releaseVLayout);


        verticalLayout_16->addLayout(envelopeParamsHLayout);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_16->addItem(verticalSpacer_10);


        framesVLayout->addWidget(envelopeParamsFrame);


        gridLayout_3->addLayout(framesVLayout, 2, 0, 1, 1);


        instrumentLayout->addWidget(adsrInstrumentFrame);

        additiveInstrumentFrame = new QFrame(instrumentFrameFrame);
        additiveInstrumentFrame->setObjectName(QStringLiteral("additiveInstrumentFrame"));
        sizePolicy8.setHeightForWidth(additiveInstrumentFrame->sizePolicy().hasHeightForWidth());
        additiveInstrumentFrame->setSizePolicy(sizePolicy8);
        additiveInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        additiveInstrumentFrame->setPalette(palette6);
        additiveInstrumentFrame->setAutoFillBackground(true);
        additiveInstrumentFrame->setFrameShape(QFrame::Panel);
        additiveInstrumentFrame->setFrameShadow(QFrame::Raised);
        additiveInstrumentFrame->setLineWidth(2);
        gridLayout_7 = new QGridLayout(additiveInstrumentFrame);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(9, 6, 9, 9);
        nameHLayout_4 = new QHBoxLayout();
        nameHLayout_4->setSpacing(6);
        nameHLayout_4->setObjectName(QStringLiteral("nameHLayout_4"));
        deleteAdditiveButton = new QPushButton(additiveInstrumentFrame);
        deleteAdditiveButton->setObjectName(QStringLiteral("deleteAdditiveButton"));
        sizePolicy9.setHeightForWidth(deleteAdditiveButton->sizePolicy().hasHeightForWidth());
        deleteAdditiveButton->setSizePolicy(sizePolicy9);
        deleteAdditiveButton->setFocusPolicy(Qt::StrongFocus);
        deleteAdditiveButton->setIcon(icon);
        deleteAdditiveButton->setIconSize(QSize(15, 15));
        deleteAdditiveButton->setFlat(true);

        nameHLayout_4->addWidget(deleteAdditiveButton);

        instrumentNameLabel_4 = new QLabel(additiveInstrumentFrame);
        instrumentNameLabel_4->setObjectName(QStringLiteral("instrumentNameLabel_4"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_4->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_4->setSizePolicy(sizePolicy10);
        instrumentNameLabel_4->setFont(font4);

        nameHLayout_4->addWidget(instrumentNameLabel_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        nameHLayout_4->addItem(horizontalSpacer_5);

        instrumentNameAdditive = new QLabel(additiveInstrumentFrame);
        instrumentNameAdditive->setObjectName(QStringLiteral("instrumentNameAdditive"));

        nameHLayout_4->addWidget(instrumentNameAdditive);


        gridLayout_7->addLayout(nameHLayout_4, 0, 0, 1, 1);

        line_8 = new QFrame(additiveInstrumentFrame);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout_7->addWidget(line_8, 1, 0, 1, 1);

        framesVLayout_4 = new QVBoxLayout();
        framesVLayout_4->setSpacing(6);
        framesVLayout_4->setObjectName(QStringLiteral("framesVLayout_4"));
        oscillator2Frame_4 = new QFrame(additiveInstrumentFrame);
        oscillator2Frame_4->setObjectName(QStringLiteral("oscillator2Frame_4"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(oscillator2Frame_4->sizePolicy().hasHeightForWidth());
        oscillator2Frame_4->setSizePolicy(sizePolicy12);
        oscillator2Frame_4->setFrameShape(QFrame::Panel);
        oscillator2Frame_4->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_4->setLineWidth(2);
        verticalLayout_24 = new QVBoxLayout(oscillator2Frame_4);
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setContentsMargins(11, 11, 11, 11);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        verticalLayout_24->setContentsMargins(4, 2, 4, 2);
        oscillator2Label_4 = new QLabel(oscillator2Frame_4);
        oscillator2Label_4->setObjectName(QStringLiteral("oscillator2Label_4"));
        oscillator2Label_4->setMaximumSize(QSize(16777215, 14));
        oscillator2Label_4->setFont(font1);

        verticalLayout_24->addWidget(oscillator2Label_4, 0, Qt::AlignHCenter);

        slidersFrame = new QFrame(oscillator2Frame_4);
        slidersFrame->setObjectName(QStringLiteral("slidersFrame"));
        QSizePolicy sizePolicy13(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(slidersFrame->sizePolicy().hasHeightForWidth());
        slidersFrame->setSizePolicy(sizePolicy13);
        slidersFrame->setFrameShape(QFrame::StyledPanel);
        slidersFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(slidersFrame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setSpacing(6);
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        sliderH0 = new QSlider(slidersFrame);
        sliderH0->setObjectName(QStringLiteral("sliderH0"));
        sliderH0->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH0->setMaximum(100);
        sliderH0->setValue(100);
        sliderH0->setOrientation(Qt::Vertical);
        sliderH0->setInvertedAppearance(false);
        sliderH0->setTickPosition(QSlider::NoTicks);

        verticalLayout_39->addWidget(sliderH0);

        sliderLabelH0 = new QLabel(slidersFrame);
        sliderLabelH0->setObjectName(QStringLiteral("sliderLabelH0"));

        verticalLayout_39->addWidget(sliderLabelH0, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_39);

        verticalLayout_42 = new QVBoxLayout();
        verticalLayout_42->setSpacing(6);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        sliderH1 = new QSlider(slidersFrame);
        sliderH1->setObjectName(QStringLiteral("sliderH1"));
        sliderH1->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH1->setMaximum(100);
        sliderH1->setValue(100);
        sliderH1->setOrientation(Qt::Vertical);

        verticalLayout_42->addWidget(sliderH1);

        label_29 = new QLabel(slidersFrame);
        label_29->setObjectName(QStringLiteral("label_29"));

        verticalLayout_42->addWidget(label_29, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_42);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        sliderH2 = new QSlider(slidersFrame);
        sliderH2->setObjectName(QStringLiteral("sliderH2"));
        sliderH2->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH2->setMaximum(100);
        sliderH2->setValue(100);
        sliderH2->setOrientation(Qt::Vertical);

        verticalLayout_8->addWidget(sliderH2);

        label_3 = new QLabel(slidersFrame);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_8->addWidget(label_3, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        sliderH3 = new QSlider(slidersFrame);
        sliderH3->setObjectName(QStringLiteral("sliderH3"));
        sliderH3->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH3->setMaximum(100);
        sliderH3->setValue(100);
        sliderH3->setOrientation(Qt::Vertical);

        verticalLayout_33->addWidget(sliderH3);

        label_20 = new QLabel(slidersFrame);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout_33->addWidget(label_20, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_33);

        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setSpacing(6);
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        sliderH4 = new QSlider(slidersFrame);
        sliderH4->setObjectName(QStringLiteral("sliderH4"));
        sliderH4->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH4->setMaximum(100);
        sliderH4->setValue(100);
        sliderH4->setOrientation(Qt::Vertical);

        verticalLayout_40->addWidget(sliderH4);

        label_27 = new QLabel(slidersFrame);
        label_27->setObjectName(QStringLiteral("label_27"));

        verticalLayout_40->addWidget(label_27, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_40);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        sliderH5 = new QSlider(slidersFrame);
        sliderH5->setObjectName(QStringLiteral("sliderH5"));
        sliderH5->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH5->setMaximum(100);
        sliderH5->setValue(100);
        sliderH5->setOrientation(Qt::Vertical);

        verticalLayout_34->addWidget(sliderH5);

        label_21 = new QLabel(slidersFrame);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_34->addWidget(label_21, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_34);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setSpacing(6);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        sliderH6 = new QSlider(slidersFrame);
        sliderH6->setObjectName(QStringLiteral("sliderH6"));
        sliderH6->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH6->setMaximum(100);
        sliderH6->setValue(100);
        sliderH6->setOrientation(Qt::Vertical);

        verticalLayout_35->addWidget(sliderH6);

        label_22 = new QLabel(slidersFrame);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_35->addWidget(label_22, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_35);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setSpacing(6);
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        sliderH7 = new QSlider(slidersFrame);
        sliderH7->setObjectName(QStringLiteral("sliderH7"));
        sliderH7->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH7->setMaximum(100);
        sliderH7->setValue(100);
        sliderH7->setOrientation(Qt::Vertical);

        verticalLayout_41->addWidget(sliderH7);

        label_28 = new QLabel(slidersFrame);
        label_28->setObjectName(QStringLiteral("label_28"));

        verticalLayout_41->addWidget(label_28, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_41);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setSpacing(6);
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        sliderH8 = new QSlider(slidersFrame);
        sliderH8->setObjectName(QStringLiteral("sliderH8"));
        sliderH8->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH8->setMaximum(100);
        sliderH8->setValue(100);
        sliderH8->setOrientation(Qt::Vertical);

        verticalLayout_36->addWidget(sliderH8);

        label_23 = new QLabel(slidersFrame);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_36->addWidget(label_23, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_36);

        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setSpacing(6);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        sliderH9 = new QSlider(slidersFrame);
        sliderH9->setObjectName(QStringLiteral("sliderH9"));
        sliderH9->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH9->setMaximum(100);
        sliderH9->setValue(100);
        sliderH9->setOrientation(Qt::Vertical);

        verticalLayout_37->addWidget(sliderH9);

        label_24 = new QLabel(slidersFrame);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_37->addWidget(label_24, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_37);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setSpacing(6);
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        sliderH10 = new QSlider(slidersFrame);
        sliderH10->setObjectName(QStringLiteral("sliderH10"));
        sliderH10->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH10->setMaximum(100);
        sliderH10->setValue(100);
        sliderH10->setOrientation(Qt::Vertical);

        verticalLayout_38->addWidget(sliderH10);

        label_25 = new QLabel(slidersFrame);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_38->addWidget(label_25, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_38);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        sliderH11 = new QSlider(slidersFrame);
        sliderH11->setObjectName(QStringLiteral("sliderH11"));
        sliderH11->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        sliderH11->setMaximum(100);
        sliderH11->setPageStep(10);
        sliderH11->setValue(100);
        sliderH11->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(sliderH11);

        label_2 = new QLabel(slidersFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy14(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy14.setHorizontalStretch(0);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy14);

        verticalLayout_3->addWidget(label_2, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_24->addWidget(slidersFrame);


        framesVLayout_4->addWidget(oscillator2Frame_4);

        line_9 = new QFrame(additiveInstrumentFrame);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        framesVLayout_4->addWidget(line_9);


        gridLayout_7->addLayout(framesVLayout_4, 2, 0, 1, 1);


        instrumentLayout->addWidget(additiveInstrumentFrame);

        samplingInstrumentFrame = new QFrame(instrumentFrameFrame);
        samplingInstrumentFrame->setObjectName(QStringLiteral("samplingInstrumentFrame"));
        sizePolicy8.setHeightForWidth(samplingInstrumentFrame->sizePolicy().hasHeightForWidth());
        samplingInstrumentFrame->setSizePolicy(sizePolicy8);
        samplingInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        samplingInstrumentFrame->setPalette(palette7);
        samplingInstrumentFrame->setAutoFillBackground(true);
        samplingInstrumentFrame->setFrameShape(QFrame::Panel);
        samplingInstrumentFrame->setFrameShadow(QFrame::Raised);
        samplingInstrumentFrame->setLineWidth(2);
        gridLayout_6 = new QGridLayout(samplingInstrumentFrame);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(9, 6, 9, 9);
        nameHLayout_3 = new QHBoxLayout();
        nameHLayout_3->setSpacing(6);
        nameHLayout_3->setObjectName(QStringLiteral("nameHLayout_3"));
        deleteSamplingButton = new QPushButton(samplingInstrumentFrame);
        deleteSamplingButton->setObjectName(QStringLiteral("deleteSamplingButton"));
        sizePolicy9.setHeightForWidth(deleteSamplingButton->sizePolicy().hasHeightForWidth());
        deleteSamplingButton->setSizePolicy(sizePolicy9);
        deleteSamplingButton->setFocusPolicy(Qt::StrongFocus);
        deleteSamplingButton->setIcon(icon);
        deleteSamplingButton->setIconSize(QSize(15, 15));
        deleteSamplingButton->setFlat(true);

        nameHLayout_3->addWidget(deleteSamplingButton);

        instrumentNameLabel_3 = new QLabel(samplingInstrumentFrame);
        instrumentNameLabel_3->setObjectName(QStringLiteral("instrumentNameLabel_3"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_3->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_3->setSizePolicy(sizePolicy10);
        instrumentNameLabel_3->setFont(font4);

        nameHLayout_3->addWidget(instrumentNameLabel_3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        nameHLayout_3->addItem(horizontalSpacer_11);

        instrumentNameSampling = new QLabel(samplingInstrumentFrame);
        instrumentNameSampling->setObjectName(QStringLiteral("instrumentNameSampling"));

        nameHLayout_3->addWidget(instrumentNameSampling);


        gridLayout_6->addLayout(nameHLayout_3, 0, 0, 1, 1);

        line_6 = new QFrame(samplingInstrumentFrame);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 1, 0, 1, 1);

        framesVLayout_3 = new QVBoxLayout();
        framesVLayout_3->setSpacing(6);
        framesVLayout_3->setObjectName(QStringLiteral("framesVLayout_3"));
        line_7 = new QFrame(samplingInstrumentFrame);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        framesVLayout_3->addWidget(line_7);

        envelopeParamsFrame_3 = new QFrame(samplingInstrumentFrame);
        envelopeParamsFrame_3->setObjectName(QStringLiteral("envelopeParamsFrame_3"));
        sizePolicy2.setHeightForWidth(envelopeParamsFrame_3->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame_3->setSizePolicy(sizePolicy2);
        envelopeParamsFrame_3->setFrameShape(QFrame::Panel);
        envelopeParamsFrame_3->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame_3->setLineWidth(2);
        verticalLayout_22 = new QVBoxLayout(envelopeParamsFrame_3);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        verticalLayout_22->setContentsMargins(-1, 2, -1, 2);
        envelopeParamsLabel_3 = new QLabel(envelopeParamsFrame_3);
        envelopeParamsLabel_3->setObjectName(QStringLiteral("envelopeParamsLabel_3"));
        envelopeParamsLabel_3->setMaximumSize(QSize(16777215, 14));
        envelopeParamsLabel_3->setFont(font1);

        verticalLayout_22->addWidget(envelopeParamsLabel_3, 0, Qt::AlignHCenter);

        envelopeParamsHLayout_3 = new QHBoxLayout();
        envelopeParamsHLayout_3->setSpacing(6);
        envelopeParamsHLayout_3->setObjectName(QStringLiteral("envelopeParamsHLayout_3"));
        sustainVLayout_3 = new QVBoxLayout();
        sustainVLayout_3->setSpacing(6);
        sustainVLayout_3->setObjectName(QStringLiteral("sustainVLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        sustainVLayout_3->addItem(verticalSpacer_5);

        samplingLoopStartDial = new QDial(envelopeParamsFrame_3);
        samplingLoopStartDial->setObjectName(QStringLiteral("samplingLoopStartDial"));
        sizePolicy8.setHeightForWidth(samplingLoopStartDial->sizePolicy().hasHeightForWidth());
        samplingLoopStartDial->setSizePolicy(sizePolicy8);
        samplingLoopStartDial->setMaximumSize(QSize(60, 16777215));
        samplingLoopStartDial->setMaximum(100);
        samplingLoopStartDial->setNotchesVisible(true);

        sustainVLayout_3->addWidget(samplingLoopStartDial, 0, Qt::AlignHCenter);

        sustainLabel_3 = new QLabel(envelopeParamsFrame_3);
        sustainLabel_3->setObjectName(QStringLiteral("sustainLabel_3"));
        sizePolicy8.setHeightForWidth(sustainLabel_3->sizePolicy().hasHeightForWidth());
        sustainLabel_3->setSizePolicy(sizePolicy8);

        sustainVLayout_3->addWidget(sustainLabel_3, 0, Qt::AlignHCenter);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        sustainVLayout_3->addItem(verticalSpacer_7);


        envelopeParamsHLayout_3->addLayout(sustainVLayout_3);

        releaseVLayout_3 = new QVBoxLayout();
        releaseVLayout_3->setSpacing(6);
        releaseVLayout_3->setObjectName(QStringLiteral("releaseVLayout_3"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        releaseVLayout_3->addItem(verticalSpacer_6);

        samplingLoopEndDial = new QDial(envelopeParamsFrame_3);
        samplingLoopEndDial->setObjectName(QStringLiteral("samplingLoopEndDial"));
        sizePolicy8.setHeightForWidth(samplingLoopEndDial->sizePolicy().hasHeightForWidth());
        samplingLoopEndDial->setSizePolicy(sizePolicy8);
        samplingLoopEndDial->setMaximumSize(QSize(60, 16777215));
        samplingLoopEndDial->setMaximum(100);
        samplingLoopEndDial->setNotchesVisible(true);

        releaseVLayout_3->addWidget(samplingLoopEndDial, 0, Qt::AlignHCenter);

        releaseLabel_3 = new QLabel(envelopeParamsFrame_3);
        releaseLabel_3->setObjectName(QStringLiteral("releaseLabel_3"));
        sizePolicy8.setHeightForWidth(releaseLabel_3->sizePolicy().hasHeightForWidth());
        releaseLabel_3->setSizePolicy(sizePolicy8);

        releaseVLayout_3->addWidget(releaseLabel_3, 0, Qt::AlignHCenter);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        releaseVLayout_3->addItem(verticalSpacer_8);


        envelopeParamsHLayout_3->addLayout(releaseVLayout_3);


        verticalLayout_22->addLayout(envelopeParamsHLayout_3);


        framesVLayout_3->addWidget(envelopeParamsFrame_3);


        gridLayout_6->addLayout(framesVLayout_3, 2, 0, 1, 1);


        instrumentLayout->addWidget(samplingInstrumentFrame);

        karplusInstrumentFrame = new QFrame(instrumentFrameFrame);
        karplusInstrumentFrame->setObjectName(QStringLiteral("karplusInstrumentFrame"));
        sizePolicy8.setHeightForWidth(karplusInstrumentFrame->sizePolicy().hasHeightForWidth());
        karplusInstrumentFrame->setSizePolicy(sizePolicy8);
        karplusInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        karplusInstrumentFrame->setPalette(palette8);
        karplusInstrumentFrame->setAutoFillBackground(true);
        karplusInstrumentFrame->setFrameShape(QFrame::Panel);
        karplusInstrumentFrame->setFrameShadow(QFrame::Raised);
        karplusInstrumentFrame->setLineWidth(2);
        gridLayout_5 = new QGridLayout(karplusInstrumentFrame);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(9, 6, 9, 9);
        nameHLayout_2 = new QHBoxLayout();
        nameHLayout_2->setSpacing(6);
        nameHLayout_2->setObjectName(QStringLiteral("nameHLayout_2"));
        deleteKarplusButton = new QPushButton(karplusInstrumentFrame);
        deleteKarplusButton->setObjectName(QStringLiteral("deleteKarplusButton"));
        sizePolicy9.setHeightForWidth(deleteKarplusButton->sizePolicy().hasHeightForWidth());
        deleteKarplusButton->setSizePolicy(sizePolicy9);
        deleteKarplusButton->setFocusPolicy(Qt::StrongFocus);
        deleteKarplusButton->setIcon(icon);
        deleteKarplusButton->setIconSize(QSize(15, 15));
        deleteKarplusButton->setFlat(true);

        nameHLayout_2->addWidget(deleteKarplusButton);

        instrumentNameLabel_2 = new QLabel(karplusInstrumentFrame);
        instrumentNameLabel_2->setObjectName(QStringLiteral("instrumentNameLabel_2"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_2->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_2->setSizePolicy(sizePolicy10);
        instrumentNameLabel_2->setFont(font4);

        nameHLayout_2->addWidget(instrumentNameLabel_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        nameHLayout_2->addItem(horizontalSpacer_10);

        instrumentNameKarplus = new QLabel(karplusInstrumentFrame);
        instrumentNameKarplus->setObjectName(QStringLiteral("instrumentNameKarplus"));

        nameHLayout_2->addWidget(instrumentNameKarplus);


        gridLayout_5->addLayout(nameHLayout_2, 0, 0, 1, 1);

        line_4 = new QFrame(karplusInstrumentFrame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 1, 0, 1, 1);

        framesVLayout_2 = new QVBoxLayout();
        framesVLayout_2->setSpacing(6);
        framesVLayout_2->setObjectName(QStringLiteral("framesVLayout_2"));
        envelopeParamsFrame_2 = new QFrame(karplusInstrumentFrame);
        envelopeParamsFrame_2->setObjectName(QStringLiteral("envelopeParamsFrame_2"));
        sizePolicy2.setHeightForWidth(envelopeParamsFrame_2->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame_2->setSizePolicy(sizePolicy2);
        envelopeParamsFrame_2->setFrameShape(QFrame::Panel);
        envelopeParamsFrame_2->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame_2->setLineWidth(2);
        verticalLayout_19 = new QVBoxLayout(envelopeParamsFrame_2);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(-1, 2, -1, 2);
        envelopeParamsHLayout_2 = new QHBoxLayout();
        envelopeParamsHLayout_2->setSpacing(6);
        envelopeParamsHLayout_2->setObjectName(QStringLiteral("envelopeParamsHLayout_2"));
        decayVLayout_2 = new QVBoxLayout();
        decayVLayout_2->setSpacing(6);
        decayVLayout_2->setObjectName(QStringLiteral("decayVLayout_2"));
        karplusStretchSlider = new QSlider(envelopeParamsFrame_2);
        karplusStretchSlider->setObjectName(QStringLiteral("karplusStretchSlider"));
        karplusStretchSlider->setAutoFillBackground(false);
        karplusStretchSlider->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        karplusStretchSlider->setMinimum(1);
        karplusStretchSlider->setMaximum(50);
        karplusStretchSlider->setValue(1);
        karplusStretchSlider->setSliderPosition(1);
        karplusStretchSlider->setOrientation(Qt::Vertical);
        karplusStretchSlider->setInvertedAppearance(false);
        karplusStretchSlider->setTickPosition(QSlider::TicksBothSides);
        karplusStretchSlider->setTickInterval(2);

        decayVLayout_2->addWidget(karplusStretchSlider, 0, Qt::AlignHCenter);

        decayLabel_2 = new QLabel(envelopeParamsFrame_2);
        decayLabel_2->setObjectName(QStringLiteral("decayLabel_2"));
        sizePolicy8.setHeightForWidth(decayLabel_2->sizePolicy().hasHeightForWidth());
        decayLabel_2->setSizePolicy(sizePolicy8);

        decayVLayout_2->addWidget(decayLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(decayVLayout_2);

        releaseVLayout_2 = new QVBoxLayout();
        releaseVLayout_2->setSpacing(6);
        releaseVLayout_2->setObjectName(QStringLiteral("releaseVLayout_2"));
        karplusDecaySlider = new QSlider(envelopeParamsFrame_2);
        karplusDecaySlider->setObjectName(QStringLiteral("karplusDecaySlider"));
        karplusDecaySlider->setAutoFillBackground(false);
        karplusDecaySlider->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        karplusDecaySlider->setMaximum(1000);
        karplusDecaySlider->setValue(0);
        karplusDecaySlider->setSliderPosition(0);
        karplusDecaySlider->setOrientation(Qt::Vertical);
        karplusDecaySlider->setInvertedAppearance(false);
        karplusDecaySlider->setTickPosition(QSlider::TicksBothSides);
        karplusDecaySlider->setTickInterval(50);

        releaseVLayout_2->addWidget(karplusDecaySlider, 0, Qt::AlignHCenter);

        releaseLabel_2 = new QLabel(envelopeParamsFrame_2);
        releaseLabel_2->setObjectName(QStringLiteral("releaseLabel_2"));
        sizePolicy8.setHeightForWidth(releaseLabel_2->sizePolicy().hasHeightForWidth());
        releaseLabel_2->setSizePolicy(sizePolicy8);

        releaseVLayout_2->addWidget(releaseLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(releaseVLayout_2);

        sustainVLayout_2 = new QVBoxLayout();
        sustainVLayout_2->setSpacing(6);
        sustainVLayout_2->setObjectName(QStringLiteral("sustainVLayout_2"));
        karplusBlendSlider = new QSlider(envelopeParamsFrame_2);
        karplusBlendSlider->setObjectName(QStringLiteral("karplusBlendSlider"));
        karplusBlendSlider->setAutoFillBackground(false);
        karplusBlendSlider->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        karplusBlendSlider->setMaximum(1000);
        karplusBlendSlider->setValue(0);
        karplusBlendSlider->setSliderPosition(0);
        karplusBlendSlider->setOrientation(Qt::Vertical);
        karplusBlendSlider->setInvertedAppearance(false);
        karplusBlendSlider->setTickPosition(QSlider::TicksBothSides);
        karplusBlendSlider->setTickInterval(50);

        sustainVLayout_2->addWidget(karplusBlendSlider, 0, Qt::AlignHCenter);

        sustainLabel_2 = new QLabel(envelopeParamsFrame_2);
        sustainLabel_2->setObjectName(QStringLiteral("sustainLabel_2"));
        sizePolicy8.setHeightForWidth(sustainLabel_2->sizePolicy().hasHeightForWidth());
        sustainLabel_2->setSizePolicy(sizePolicy8);

        sustainVLayout_2->addWidget(sustainLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(sustainVLayout_2);


        verticalLayout_19->addLayout(envelopeParamsHLayout_2);


        framesVLayout_2->addWidget(envelopeParamsFrame_2);


        gridLayout_5->addLayout(framesVLayout_2, 2, 0, 1, 1);


        instrumentLayout->addWidget(karplusInstrumentFrame);


        instrumentLayoutLayout->addLayout(instrumentLayout);


        gridLayout_2->addLayout(instrumentLayoutLayout, 0, 0, 1, 1);


        activeChannelAssetsPanel->addWidget(instrumentFrameFrame);

        effectsScrollArea = new QScrollArea(centralWidget);
        effectsScrollArea->setObjectName(QStringLiteral("effectsScrollArea"));
        sizePolicy2.setHeightForWidth(effectsScrollArea->sizePolicy().hasHeightForWidth());
        effectsScrollArea->setSizePolicy(sizePolicy2);
        effectsScrollArea->setMinimumSize(QSize(0, 180));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush7);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush14(QColor(73, 73, 73, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush14);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush14);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush14);
        effectsScrollArea->setPalette(palette9);
        effectsScrollArea->setAcceptDrops(false);
        effectsScrollArea->setAutoFillBackground(true);
        effectsScrollArea->setFrameShape(QFrame::Panel);
        effectsScrollArea->setFrameShadow(QFrame::Sunken);
        effectsScrollArea->setLineWidth(3);
        effectsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        effectsScrollArea->setWidgetResizable(true);
        effectsScrollAreaContents = new QWidget();
        effectsScrollAreaContents->setObjectName(QStringLiteral("effectsScrollAreaContents"));
        effectsScrollAreaContents->setGeometry(QRect(0, 0, 1603, 401));
        horizontalLayout_9 = new QHBoxLayout(effectsScrollAreaContents);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        effectsScrollAreaLayout = new QHBoxLayout();
        effectsScrollAreaLayout->setSpacing(6);
        effectsScrollAreaLayout->setObjectName(QStringLiteral("effectsScrollAreaLayout"));
        effectsHorizontalLayout = new QHBoxLayout();
        effectsHorizontalLayout->setSpacing(6);
        effectsHorizontalLayout->setObjectName(QStringLiteral("effectsHorizontalLayout"));
        eq8Frame = new QFrame(effectsScrollAreaContents);
        eq8Frame->setObjectName(QStringLiteral("eq8Frame"));
        eq8Frame->setMaximumSize(QSize(250, 16777215));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        eq8Frame->setPalette(palette10);
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        eq8Frame->setFont(font5);
        eq8Frame->setAutoFillBackground(true);
        eq8Frame->setFrameShape(QFrame::Panel);
        eq8Frame->setFrameShadow(QFrame::Raised);
        eq8Frame->setLineWidth(2);
        eq8Frame->setMidLineWidth(0);
        verticalLayout_4 = new QVBoxLayout(eq8Frame);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(9, 6, 9, 7);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        delete8EqButton = new QPushButton(eq8Frame);
        delete8EqButton->setObjectName(QStringLiteral("delete8EqButton"));
        sizePolicy9.setHeightForWidth(delete8EqButton->sizePolicy().hasHeightForWidth());
        delete8EqButton->setSizePolicy(sizePolicy9);
        delete8EqButton->setIcon(icon);
        delete8EqButton->setIconSize(QSize(15, 15));
        delete8EqButton->setFlat(true);

        horizontalLayout_4->addWidget(delete8EqButton);

        label_5 = new QLabel(eq8Frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font4);

        horizontalLayout_4->addWidget(label_5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        eq8MoveLeftButton = new QPushButton(eq8Frame);
        eq8MoveLeftButton->setObjectName(QStringLiteral("eq8MoveLeftButton"));
        sizePolicy9.setHeightForWidth(eq8MoveLeftButton->sizePolicy().hasHeightForWidth());
        eq8MoveLeftButton->setSizePolicy(sizePolicy9);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/006-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        eq8MoveLeftButton->setIcon(icon1);
        eq8MoveLeftButton->setIconSize(QSize(15, 15));
        eq8MoveLeftButton->setFlat(true);

        horizontalLayout_4->addWidget(eq8MoveLeftButton);

        eq8MoveRightButton = new QPushButton(eq8Frame);
        eq8MoveRightButton->setObjectName(QStringLiteral("eq8MoveRightButton"));
        sizePolicy9.setHeightForWidth(eq8MoveRightButton->sizePolicy().hasHeightForWidth());
        eq8MoveRightButton->setSizePolicy(sizePolicy9);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/033-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        eq8MoveRightButton->setIcon(icon2);
        eq8MoveRightButton->setIconSize(QSize(15, 15));
        eq8MoveRightButton->setFlat(true);

        horizontalLayout_4->addWidget(eq8MoveRightButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        line_10 = new QFrame(eq8Frame);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_10);

        oscillator2Frame_6 = new QFrame(eq8Frame);
        oscillator2Frame_6->setObjectName(QStringLiteral("oscillator2Frame_6"));
        QSizePolicy sizePolicy15(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy15.setHorizontalStretch(0);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(oscillator2Frame_6->sizePolicy().hasHeightForWidth());
        oscillator2Frame_6->setSizePolicy(sizePolicy15);
        oscillator2Frame_6->setFrameShape(QFrame::Panel);
        oscillator2Frame_6->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_6->setLineWidth(2);
        verticalLayout_27 = new QVBoxLayout(oscillator2Frame_6);
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setContentsMargins(11, 11, 11, 11);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        verticalLayout_27->setContentsMargins(4, 2, 4, 2);
        oscillator2Label_6 = new QLabel(oscillator2Frame_6);
        oscillator2Label_6->setObjectName(QStringLiteral("oscillator2Label_6"));
        oscillator2Label_6->setMaximumSize(QSize(16777215, 14));
        oscillator2Label_6->setFont(font1);

        verticalLayout_27->addWidget(oscillator2Label_6, 0, Qt::AlignHCenter);

        slidersFrame_3 = new QFrame(oscillator2Frame_6);
        slidersFrame_3->setObjectName(QStringLiteral("slidersFrame_3"));
        sizePolicy13.setHeightForWidth(slidersFrame_3->sizePolicy().hasHeightForWidth());
        slidersFrame_3->setSizePolicy(sizePolicy13);
        slidersFrame_3->setFrameShape(QFrame::StyledPanel);
        slidersFrame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(slidersFrame_3);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_50 = new QVBoxLayout();
        verticalLayout_50->setSpacing(6);
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        eqSlider100 = new QSlider(slidersFrame_3);
        eqSlider100->setObjectName(QStringLiteral("eqSlider100"));
        eqSlider100->setAutoFillBackground(false);
        eqSlider100->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider100->setMaximum(100);
        eqSlider100->setValue(50);
        eqSlider100->setSliderPosition(50);
        eqSlider100->setOrientation(Qt::Vertical);
        eqSlider100->setInvertedAppearance(false);
        eqSlider100->setTickPosition(QSlider::NoTicks);

        verticalLayout_50->addWidget(eqSlider100);

        sliderLabelH0_3 = new QLabel(slidersFrame_3);
        sliderLabelH0_3->setObjectName(QStringLiteral("sliderLabelH0_3"));

        verticalLayout_50->addWidget(sliderLabelH0_3, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_50);

        verticalLayout_51 = new QVBoxLayout();
        verticalLayout_51->setSpacing(6);
        verticalLayout_51->setObjectName(QStringLiteral("verticalLayout_51"));
        eqSlider200 = new QSlider(slidersFrame_3);
        eqSlider200->setObjectName(QStringLiteral("eqSlider200"));
        eqSlider200->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider200->setMaximum(100);
        eqSlider200->setValue(50);
        eqSlider200->setSliderPosition(50);
        eqSlider200->setOrientation(Qt::Vertical);

        verticalLayout_51->addWidget(eqSlider200);

        label_35 = new QLabel(slidersFrame_3);
        label_35->setObjectName(QStringLiteral("label_35"));

        verticalLayout_51->addWidget(label_35, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_51);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        eqSlider400 = new QSlider(slidersFrame_3);
        eqSlider400->setObjectName(QStringLiteral("eqSlider400"));
        eqSlider400->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider400->setMaximum(100);
        eqSlider400->setValue(50);
        eqSlider400->setSliderPosition(50);
        eqSlider400->setOrientation(Qt::Vertical);

        verticalLayout_10->addWidget(eqSlider400);

        label_6 = new QLabel(slidersFrame_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_10->addWidget(label_6, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_10);

        verticalLayout_52 = new QVBoxLayout();
        verticalLayout_52->setSpacing(6);
        verticalLayout_52->setObjectName(QStringLiteral("verticalLayout_52"));
        eqSlider800 = new QSlider(slidersFrame_3);
        eqSlider800->setObjectName(QStringLiteral("eqSlider800"));
        eqSlider800->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider800->setMaximum(100);
        eqSlider800->setValue(50);
        eqSlider800->setSliderPosition(50);
        eqSlider800->setOrientation(Qt::Vertical);

        verticalLayout_52->addWidget(eqSlider800);

        label_36 = new QLabel(slidersFrame_3);
        label_36->setObjectName(QStringLiteral("label_36"));

        verticalLayout_52->addWidget(label_36, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_52);

        verticalLayout_53 = new QVBoxLayout();
        verticalLayout_53->setSpacing(6);
        verticalLayout_53->setObjectName(QStringLiteral("verticalLayout_53"));
        eqSlider1k4 = new QSlider(slidersFrame_3);
        eqSlider1k4->setObjectName(QStringLiteral("eqSlider1k4"));
        eqSlider1k4->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider1k4->setMaximum(100);
        eqSlider1k4->setValue(50);
        eqSlider1k4->setSliderPosition(50);
        eqSlider1k4->setOrientation(Qt::Vertical);

        verticalLayout_53->addWidget(eqSlider1k4);

        label_37 = new QLabel(slidersFrame_3);
        label_37->setObjectName(QStringLiteral("label_37"));

        verticalLayout_53->addWidget(label_37, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_53);

        verticalLayout_54 = new QVBoxLayout();
        verticalLayout_54->setSpacing(6);
        verticalLayout_54->setObjectName(QStringLiteral("verticalLayout_54"));
        eqSlider2k7 = new QSlider(slidersFrame_3);
        eqSlider2k7->setObjectName(QStringLiteral("eqSlider2k7"));
        eqSlider2k7->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider2k7->setMaximum(100);
        eqSlider2k7->setValue(50);
        eqSlider2k7->setSliderPosition(50);
        eqSlider2k7->setOrientation(Qt::Vertical);

        verticalLayout_54->addWidget(eqSlider2k7);

        label_38 = new QLabel(slidersFrame_3);
        label_38->setObjectName(QStringLiteral("label_38"));

        verticalLayout_54->addWidget(label_38, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_54);

        verticalLayout_55 = new QVBoxLayout();
        verticalLayout_55->setSpacing(6);
        verticalLayout_55->setObjectName(QStringLiteral("verticalLayout_55"));
        eqSlider5k = new QSlider(slidersFrame_3);
        eqSlider5k->setObjectName(QStringLiteral("eqSlider5k"));
        eqSlider5k->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider5k->setMaximum(100);
        eqSlider5k->setValue(50);
        eqSlider5k->setSliderPosition(50);
        eqSlider5k->setOrientation(Qt::Vertical);

        verticalLayout_55->addWidget(eqSlider5k);

        label_39 = new QLabel(slidersFrame_3);
        label_39->setObjectName(QStringLiteral("label_39"));

        verticalLayout_55->addWidget(label_39, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_55);

        verticalLayout_56 = new QVBoxLayout();
        verticalLayout_56->setSpacing(6);
        verticalLayout_56->setObjectName(QStringLiteral("verticalLayout_56"));
        eqSlider10k = new QSlider(slidersFrame_3);
        eqSlider10k->setObjectName(QStringLiteral("eqSlider10k"));
        eqSlider10k->setStyleSheet(QStringLiteral("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}"));
        eqSlider10k->setMaximum(100);
        eqSlider10k->setValue(50);
        eqSlider10k->setSliderPosition(50);
        eqSlider10k->setOrientation(Qt::Vertical);

        verticalLayout_56->addWidget(eqSlider10k);

        label_40 = new QLabel(slidersFrame_3);
        label_40->setObjectName(QStringLiteral("label_40"));

        verticalLayout_56->addWidget(label_40, 0, Qt::AlignHCenter);


        horizontalLayout_6->addLayout(verticalLayout_56);


        verticalLayout_27->addWidget(slidersFrame_3);


        verticalLayout_4->addWidget(oscillator2Frame_6);


        effectsHorizontalLayout->addWidget(eq8Frame);

        reverbEffectFrame = new QFrame(effectsScrollAreaContents);
        reverbEffectFrame->setObjectName(QStringLiteral("reverbEffectFrame"));
        reverbEffectFrame->setMaximumSize(QSize(250, 16777215));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        reverbEffectFrame->setPalette(palette11);
        reverbEffectFrame->setFont(font5);
        reverbEffectFrame->setAutoFillBackground(true);
        reverbEffectFrame->setFrameShape(QFrame::Panel);
        reverbEffectFrame->setFrameShadow(QFrame::Raised);
        reverbEffectFrame->setLineWidth(2);
        reverbEffectFrame->setMidLineWidth(0);
        verticalLayout_11 = new QVBoxLayout(reverbEffectFrame);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(9, 6, 9, 7);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        deleteReverbButton = new QPushButton(reverbEffectFrame);
        deleteReverbButton->setObjectName(QStringLiteral("deleteReverbButton"));
        sizePolicy9.setHeightForWidth(deleteReverbButton->sizePolicy().hasHeightForWidth());
        deleteReverbButton->setSizePolicy(sizePolicy9);
        deleteReverbButton->setIcon(icon);
        deleteReverbButton->setIconSize(QSize(15, 15));
        deleteReverbButton->setFlat(true);

        horizontalLayout_8->addWidget(deleteReverbButton);

        label_10 = new QLabel(reverbEffectFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font4);

        horizontalLayout_8->addWidget(label_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        reverbMoveLeftButton = new QPushButton(reverbEffectFrame);
        reverbMoveLeftButton->setObjectName(QStringLiteral("reverbMoveLeftButton"));
        sizePolicy9.setHeightForWidth(reverbMoveLeftButton->sizePolicy().hasHeightForWidth());
        reverbMoveLeftButton->setSizePolicy(sizePolicy9);
        reverbMoveLeftButton->setIcon(icon1);
        reverbMoveLeftButton->setIconSize(QSize(15, 15));
        reverbMoveLeftButton->setFlat(true);

        horizontalLayout_8->addWidget(reverbMoveLeftButton);

        reverbMoveRightButton = new QPushButton(reverbEffectFrame);
        reverbMoveRightButton->setObjectName(QStringLiteral("reverbMoveRightButton"));
        sizePolicy9.setHeightForWidth(reverbMoveRightButton->sizePolicy().hasHeightForWidth());
        reverbMoveRightButton->setSizePolicy(sizePolicy9);
        reverbMoveRightButton->setIcon(icon2);
        reverbMoveRightButton->setIconSize(QSize(15, 15));
        reverbMoveRightButton->setFlat(true);

        horizontalLayout_8->addWidget(reverbMoveRightButton);


        verticalLayout_11->addLayout(horizontalLayout_8);

        line_11 = new QFrame(reverbEffectFrame);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_11->addWidget(line_11);

        frame_4 = new QFrame(reverbEffectFrame);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy12.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy12);
        frame_4->setFrameShape(QFrame::Panel);
        frame_4->setFrameShadow(QFrame::Sunken);
        frame_4->setLineWidth(2);
        verticalLayout_12 = new QVBoxLayout(frame_4);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(4, 2, 4, 2);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        horizontalLayout_11->addWidget(label_12);

        reverbTypeComboBox = new QComboBox(frame_4);
        reverbTypeComboBox->setObjectName(QStringLiteral("reverbTypeComboBox"));
        sizePolicy5.setHeightForWidth(reverbTypeComboBox->sizePolicy().hasHeightForWidth());
        reverbTypeComboBox->setSizePolicy(sizePolicy5);
        reverbTypeComboBox->setMaximumSize(QSize(16777215, 17));

        horizontalLayout_11->addWidget(reverbTypeComboBox);


        verticalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_11->addWidget(frame_4);

        oscillator2Frame_7 = new QFrame(reverbEffectFrame);
        oscillator2Frame_7->setObjectName(QStringLiteral("oscillator2Frame_7"));
        sizePolicy15.setHeightForWidth(oscillator2Frame_7->sizePolicy().hasHeightForWidth());
        oscillator2Frame_7->setSizePolicy(sizePolicy15);
        oscillator2Frame_7->setFrameShape(QFrame::Panel);
        oscillator2Frame_7->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_7->setLineWidth(2);
        verticalLayout_28 = new QVBoxLayout(oscillator2Frame_7);
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setContentsMargins(11, 11, 11, 11);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        verticalLayout_28->setContentsMargins(4, 2, 4, 2);
        oscillator2Label_7 = new QLabel(oscillator2Frame_7);
        oscillator2Label_7->setObjectName(QStringLiteral("oscillator2Label_7"));
        oscillator2Label_7->setMaximumSize(QSize(16777215, 14));
        oscillator2Label_7->setFont(font1);

        verticalLayout_28->addWidget(oscillator2Label_7, 0, Qt::AlignHCenter);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        reverbDelayDial = new QDial(oscillator2Frame_7);
        reverbDelayDial->setObjectName(QStringLiteral("reverbDelayDial"));
        reverbDelayDial->setMaximumSize(QSize(60, 16777215));
        reverbDelayDial->setMaximum(300);
        reverbDelayDial->setNotchTarget(9.7);
        reverbDelayDial->setNotchesVisible(true);

        verticalLayout_13->addWidget(reverbDelayDial, 0, Qt::AlignHCenter);

        label_13 = new QLabel(oscillator2Frame_7);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_13->addWidget(label_13, 0, Qt::AlignHCenter);


        horizontalLayout_12->addLayout(verticalLayout_13);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        reverbAttnDial = new QDial(oscillator2Frame_7);
        reverbAttnDial->setObjectName(QStringLiteral("reverbAttnDial"));
        reverbAttnDial->setMaximumSize(QSize(60, 16777215));
        reverbAttnDial->setNotchesVisible(true);

        verticalLayout_23->addWidget(reverbAttnDial, 0, Qt::AlignHCenter);

        label_14 = new QLabel(oscillator2Frame_7);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_23->addWidget(label_14, 0, Qt::AlignHCenter);


        horizontalLayout_12->addLayout(verticalLayout_23);


        verticalLayout_28->addLayout(horizontalLayout_12);


        verticalLayout_11->addWidget(oscillator2Frame_7);


        effectsHorizontalLayout->addWidget(reverbEffectFrame);

        flangerEffectFrame = new QFrame(effectsScrollAreaContents);
        flangerEffectFrame->setObjectName(QStringLiteral("flangerEffectFrame"));
        flangerEffectFrame->setMaximumSize(QSize(250, 16777215));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        flangerEffectFrame->setPalette(palette12);
        flangerEffectFrame->setFont(font5);
        flangerEffectFrame->setAutoFillBackground(true);
        flangerEffectFrame->setFrameShape(QFrame::Panel);
        flangerEffectFrame->setFrameShadow(QFrame::Raised);
        flangerEffectFrame->setLineWidth(2);
        flangerEffectFrame->setMidLineWidth(0);
        verticalLayout_31 = new QVBoxLayout(flangerEffectFrame);
        verticalLayout_31->setSpacing(6);
        verticalLayout_31->setContentsMargins(11, 11, 11, 11);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        verticalLayout_31->setContentsMargins(9, 6, 9, 7);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        deleteFlangerButton = new QPushButton(flangerEffectFrame);
        deleteFlangerButton->setObjectName(QStringLiteral("deleteFlangerButton"));
        sizePolicy9.setHeightForWidth(deleteFlangerButton->sizePolicy().hasHeightForWidth());
        deleteFlangerButton->setSizePolicy(sizePolicy9);
        deleteFlangerButton->setIcon(icon);
        deleteFlangerButton->setIconSize(QSize(15, 15));
        deleteFlangerButton->setFlat(true);

        horizontalLayout_3->addWidget(deleteFlangerButton);

        label_17 = new QLabel(flangerEffectFrame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font4);

        horizontalLayout_3->addWidget(label_17);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        flangerMoveLeftButton = new QPushButton(flangerEffectFrame);
        flangerMoveLeftButton->setObjectName(QStringLiteral("flangerMoveLeftButton"));
        sizePolicy9.setHeightForWidth(flangerMoveLeftButton->sizePolicy().hasHeightForWidth());
        flangerMoveLeftButton->setSizePolicy(sizePolicy9);
        flangerMoveLeftButton->setIcon(icon1);
        flangerMoveLeftButton->setIconSize(QSize(15, 15));
        flangerMoveLeftButton->setFlat(true);

        horizontalLayout_3->addWidget(flangerMoveLeftButton);

        flangerMoveRightButton = new QPushButton(flangerEffectFrame);
        flangerMoveRightButton->setObjectName(QStringLiteral("flangerMoveRightButton"));
        sizePolicy9.setHeightForWidth(flangerMoveRightButton->sizePolicy().hasHeightForWidth());
        flangerMoveRightButton->setSizePolicy(sizePolicy9);
        flangerMoveRightButton->setIcon(icon2);
        flangerMoveRightButton->setIconSize(QSize(15, 15));
        flangerMoveRightButton->setFlat(true);

        horizontalLayout_3->addWidget(flangerMoveRightButton);


        verticalLayout_31->addLayout(horizontalLayout_3);

        line_12 = new QFrame(flangerEffectFrame);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout_31->addWidget(line_12);

        oscillator2Frame_8 = new QFrame(flangerEffectFrame);
        oscillator2Frame_8->setObjectName(QStringLiteral("oscillator2Frame_8"));
        sizePolicy12.setHeightForWidth(oscillator2Frame_8->sizePolicy().hasHeightForWidth());
        oscillator2Frame_8->setSizePolicy(sizePolicy12);
        oscillator2Frame_8->setFrameShape(QFrame::Panel);
        oscillator2Frame_8->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_8->setLineWidth(2);
        verticalLayout_32 = new QVBoxLayout(oscillator2Frame_8);
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setContentsMargins(11, 11, 11, 11);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        verticalLayout_32->setContentsMargins(4, 2, 4, 2);
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        verticalLayout_43 = new QVBoxLayout();
        verticalLayout_43->setSpacing(6);
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        flangerGFBDial = new QDial(oscillator2Frame_8);
        flangerGFBDial->setObjectName(QStringLiteral("flangerGFBDial"));
        flangerGFBDial->setMaximumSize(QSize(60, 16777215));
        flangerGFBDial->setNotchesVisible(true);

        verticalLayout_43->addWidget(flangerGFBDial, 0, Qt::AlignHCenter);

        label_18 = new QLabel(oscillator2Frame_8);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_43->addWidget(label_18, 0, Qt::AlignHCenter);


        gridLayout_8->addLayout(verticalLayout_43, 0, 3, 1, 1);

        verticalLayout_44 = new QVBoxLayout();
        verticalLayout_44->setSpacing(6);
        verticalLayout_44->setObjectName(QStringLiteral("verticalLayout_44"));
        flangerMwDial = new QDial(oscillator2Frame_8);
        flangerMwDial->setObjectName(QStringLiteral("flangerMwDial"));
        flangerMwDial->setMaximumSize(QSize(60, 16777215));
        flangerMwDial->setNotchesVisible(true);

        verticalLayout_44->addWidget(flangerMwDial, 0, Qt::AlignHCenter);

        label_19 = new QLabel(oscillator2Frame_8);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_44->addWidget(label_19, 0, Qt::AlignHCenter);


        gridLayout_8->addLayout(verticalLayout_44, 0, 0, 1, 1);

        verticalLayout_45 = new QVBoxLayout();
        verticalLayout_45->setSpacing(6);
        verticalLayout_45->setObjectName(QStringLiteral("verticalLayout_45"));
        flangerM0Dial = new QDial(oscillator2Frame_8);
        flangerM0Dial->setObjectName(QStringLiteral("flangerM0Dial"));
        flangerM0Dial->setMaximumSize(QSize(60, 16777215));
        flangerM0Dial->setNotchesVisible(true);

        verticalLayout_45->addWidget(flangerM0Dial, 0, Qt::AlignHCenter);

        label_26 = new QLabel(oscillator2Frame_8);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout_45->addWidget(label_26, 0, Qt::AlignHCenter);


        gridLayout_8->addLayout(verticalLayout_45, 1, 0, 1, 1);

        verticalLayout_46 = new QVBoxLayout();
        verticalLayout_46->setSpacing(6);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        flangerGFFDial = new QDial(oscillator2Frame_8);
        flangerGFFDial->setObjectName(QStringLiteral("flangerGFFDial"));
        flangerGFFDial->setMaximumSize(QSize(60, 16777215));
        flangerGFFDial->setNotchesVisible(true);

        verticalLayout_46->addWidget(flangerGFFDial, 0, Qt::AlignHCenter);

        label_30 = new QLabel(oscillator2Frame_8);
        label_30->setObjectName(QStringLiteral("label_30"));

        verticalLayout_46->addWidget(label_30, 0, Qt::AlignHCenter);


        gridLayout_8->addLayout(verticalLayout_46, 1, 3, 1, 1);

        verticalLayout_47 = new QVBoxLayout();
        verticalLayout_47->setSpacing(6);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        flangerF0Slider = new QSlider(oscillator2Frame_8);
        flangerF0Slider->setObjectName(QStringLiteral("flangerF0Slider"));
        flangerF0Slider->setStyleSheet(QLatin1String("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}\n"
""));
        flangerF0Slider->setMinimum(10);
        flangerF0Slider->setMaximum(500);
        flangerF0Slider->setOrientation(Qt::Vertical);
        flangerF0Slider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_47->addWidget(flangerF0Slider, 0, Qt::AlignHCenter);

        label_31 = new QLabel(oscillator2Frame_8);
        label_31->setObjectName(QStringLiteral("label_31"));

        verticalLayout_47->addWidget(label_31, 0, Qt::AlignHCenter);


        gridLayout_8->addLayout(verticalLayout_47, 0, 2, 2, 1);


        verticalLayout_32->addLayout(gridLayout_8);


        verticalLayout_31->addWidget(oscillator2Frame_8);


        effectsHorizontalLayout->addWidget(flangerEffectFrame);

        vibratoEffectFrame = new QFrame(effectsScrollAreaContents);
        vibratoEffectFrame->setObjectName(QStringLiteral("vibratoEffectFrame"));
        vibratoEffectFrame->setMaximumSize(QSize(250, 16777215));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        vibratoEffectFrame->setPalette(palette13);
        vibratoEffectFrame->setFont(font5);
        vibratoEffectFrame->setAutoFillBackground(true);
        vibratoEffectFrame->setFrameShape(QFrame::Panel);
        vibratoEffectFrame->setFrameShadow(QFrame::Raised);
        vibratoEffectFrame->setLineWidth(2);
        vibratoEffectFrame->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(vibratoEffectFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 6, 9, 7);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        deleteVibratoButton = new QPushButton(vibratoEffectFrame);
        deleteVibratoButton->setObjectName(QStringLiteral("deleteVibratoButton"));
        sizePolicy9.setHeightForWidth(deleteVibratoButton->sizePolicy().hasHeightForWidth());
        deleteVibratoButton->setSizePolicy(sizePolicy9);
        deleteVibratoButton->setIcon(icon);
        deleteVibratoButton->setIconSize(QSize(15, 15));
        deleteVibratoButton->setFlat(true);

        horizontalLayout->addWidget(deleteVibratoButton);

        label = new QLabel(vibratoEffectFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font4);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        vibratoMoveLeftButton = new QPushButton(vibratoEffectFrame);
        vibratoMoveLeftButton->setObjectName(QStringLiteral("vibratoMoveLeftButton"));
        sizePolicy9.setHeightForWidth(vibratoMoveLeftButton->sizePolicy().hasHeightForWidth());
        vibratoMoveLeftButton->setSizePolicy(sizePolicy9);
        vibratoMoveLeftButton->setIcon(icon1);
        vibratoMoveLeftButton->setIconSize(QSize(15, 15));
        vibratoMoveLeftButton->setFlat(true);

        horizontalLayout->addWidget(vibratoMoveLeftButton);

        vibratoMoveRightButton = new QPushButton(vibratoEffectFrame);
        vibratoMoveRightButton->setObjectName(QStringLiteral("vibratoMoveRightButton"));
        sizePolicy9.setHeightForWidth(vibratoMoveRightButton->sizePolicy().hasHeightForWidth());
        vibratoMoveRightButton->setSizePolicy(sizePolicy9);
        vibratoMoveRightButton->setIcon(icon2);
        vibratoMoveRightButton->setIconSize(QSize(15, 15));
        vibratoMoveRightButton->setFlat(true);

        horizontalLayout->addWidget(vibratoMoveRightButton);


        verticalLayout->addLayout(horizontalLayout);

        line_3 = new QFrame(vibratoEffectFrame);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        oscillator2Frame_5 = new QFrame(vibratoEffectFrame);
        oscillator2Frame_5->setObjectName(QStringLiteral("oscillator2Frame_5"));
        sizePolicy12.setHeightForWidth(oscillator2Frame_5->sizePolicy().hasHeightForWidth());
        oscillator2Frame_5->setSizePolicy(sizePolicy12);
        oscillator2Frame_5->setFrameShape(QFrame::Panel);
        oscillator2Frame_5->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_5->setLineWidth(2);
        verticalLayout_26 = new QVBoxLayout(oscillator2Frame_5);
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setContentsMargins(11, 11, 11, 11);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        verticalLayout_26->setContentsMargins(4, 2, 4, 2);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        vibratoF0Slider = new QSlider(oscillator2Frame_5);
        vibratoF0Slider->setObjectName(QStringLiteral("vibratoF0Slider"));
        vibratoF0Slider->setStyleSheet(QLatin1String("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}\n"
""));
        vibratoF0Slider->setMinimum(50);
        vibratoF0Slider->setMaximum(2000);
        vibratoF0Slider->setOrientation(Qt::Vertical);
        vibratoF0Slider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_5->addWidget(vibratoF0Slider, 0, Qt::AlignHCenter);

        label_16 = new QLabel(oscillator2Frame_5);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_5->addWidget(label_16, 0, Qt::AlignHCenter);


        gridLayout_4->addLayout(verticalLayout_5, 0, 2, 2, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_3);

        vibratoMAvgDial = new QDial(oscillator2Frame_5);
        vibratoMAvgDial->setObjectName(QStringLiteral("vibratoMAvgDial"));
        vibratoMAvgDial->setMaximumSize(QSize(60, 16777215));
        vibratoMAvgDial->setNotchesVisible(true);

        verticalLayout_9->addWidget(vibratoMAvgDial, 0, Qt::AlignHCenter);

        label_4 = new QLabel(oscillator2Frame_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_9->addWidget(label_4, 0, Qt::AlignHCenter);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_4);


        gridLayout_4->addLayout(verticalLayout_9, 0, 3, 2, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        vibratoWidthDial = new QDial(oscillator2Frame_5);
        vibratoWidthDial->setObjectName(QStringLiteral("vibratoWidthDial"));
        vibratoWidthDial->setMaximumSize(QSize(60, 16777215));
        vibratoWidthDial->setNotchesVisible(true);

        verticalLayout_7->addWidget(vibratoWidthDial, 0, Qt::AlignHCenter);

        label_9 = new QLabel(oscillator2Frame_5);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_7->addWidget(label_9, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        gridLayout_4->addLayout(verticalLayout_7, 0, 0, 2, 1);


        verticalLayout_26->addLayout(gridLayout_4);


        verticalLayout->addWidget(oscillator2Frame_5);


        effectsHorizontalLayout->addWidget(vibratoEffectFrame);

        wahwahEffectFrame = new QFrame(effectsScrollAreaContents);
        wahwahEffectFrame->setObjectName(QStringLiteral("wahwahEffectFrame"));
        wahwahEffectFrame->setMaximumSize(QSize(250, 16777215));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush7);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush7);
        wahwahEffectFrame->setPalette(palette14);
        wahwahEffectFrame->setFont(font5);
        wahwahEffectFrame->setAutoFillBackground(true);
        wahwahEffectFrame->setFrameShape(QFrame::Panel);
        wahwahEffectFrame->setFrameShadow(QFrame::Raised);
        wahwahEffectFrame->setLineWidth(2);
        wahwahEffectFrame->setMidLineWidth(0);
        verticalLayout_29 = new QVBoxLayout(wahwahEffectFrame);
        verticalLayout_29->setSpacing(6);
        verticalLayout_29->setContentsMargins(11, 11, 11, 11);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        verticalLayout_29->setContentsMargins(9, 6, 9, 7);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        deleteWahwahButton = new QPushButton(wahwahEffectFrame);
        deleteWahwahButton->setObjectName(QStringLiteral("deleteWahwahButton"));
        sizePolicy9.setHeightForWidth(deleteWahwahButton->sizePolicy().hasHeightForWidth());
        deleteWahwahButton->setSizePolicy(sizePolicy9);
        deleteWahwahButton->setIcon(icon);
        deleteWahwahButton->setIconSize(QSize(15, 15));
        deleteWahwahButton->setFlat(true);

        horizontalLayout_7->addWidget(deleteWahwahButton);

        label_11 = new QLabel(wahwahEffectFrame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font4);

        horizontalLayout_7->addWidget(label_11);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);

        wahwahMoveLeftButton = new QPushButton(wahwahEffectFrame);
        wahwahMoveLeftButton->setObjectName(QStringLiteral("wahwahMoveLeftButton"));
        sizePolicy9.setHeightForWidth(wahwahMoveLeftButton->sizePolicy().hasHeightForWidth());
        wahwahMoveLeftButton->setSizePolicy(sizePolicy9);
        wahwahMoveLeftButton->setIcon(icon1);
        wahwahMoveLeftButton->setIconSize(QSize(15, 15));
        wahwahMoveLeftButton->setFlat(true);

        horizontalLayout_7->addWidget(wahwahMoveLeftButton);

        wahwahMoveRightButton = new QPushButton(wahwahEffectFrame);
        wahwahMoveRightButton->setObjectName(QStringLiteral("wahwahMoveRightButton"));
        sizePolicy9.setHeightForWidth(wahwahMoveRightButton->sizePolicy().hasHeightForWidth());
        wahwahMoveRightButton->setSizePolicy(sizePolicy9);
        wahwahMoveRightButton->setIcon(icon2);
        wahwahMoveRightButton->setIconSize(QSize(15, 15));
        wahwahMoveRightButton->setFlat(true);

        horizontalLayout_7->addWidget(wahwahMoveRightButton);


        verticalLayout_29->addLayout(horizontalLayout_7);

        line_13 = new QFrame(wahwahEffectFrame);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout_29->addWidget(line_13);

        oscillator2Frame_9 = new QFrame(wahwahEffectFrame);
        oscillator2Frame_9->setObjectName(QStringLiteral("oscillator2Frame_9"));
        sizePolicy12.setHeightForWidth(oscillator2Frame_9->sizePolicy().hasHeightForWidth());
        oscillator2Frame_9->setSizePolicy(sizePolicy12);
        oscillator2Frame_9->setFrameShape(QFrame::Panel);
        oscillator2Frame_9->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_9->setLineWidth(2);
        verticalLayout_30 = new QVBoxLayout(oscillator2Frame_9);
        verticalLayout_30->setSpacing(6);
        verticalLayout_30->setContentsMargins(11, 11, 11, 11);
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        verticalLayout_30->setContentsMargins(4, 2, 4, 2);
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setSpacing(6);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalLayout_48 = new QVBoxLayout();
        verticalLayout_48->setSpacing(6);
        verticalLayout_48->setObjectName(QStringLiteral("verticalLayout_48"));
        wahwahFMinSlider = new QSlider(oscillator2Frame_9);
        wahwahFMinSlider->setObjectName(QStringLiteral("wahwahFMinSlider"));
        wahwahFMinSlider->setStyleSheet(QLatin1String("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}\n"
""));
        wahwahFMinSlider->setMinimum(200);
        wahwahFMinSlider->setMaximum(1000);
        wahwahFMinSlider->setOrientation(Qt::Vertical);
        wahwahFMinSlider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_48->addWidget(wahwahFMinSlider, 0, Qt::AlignHCenter);

        label_32 = new QLabel(oscillator2Frame_9);
        label_32->setObjectName(QStringLiteral("label_32"));

        verticalLayout_48->addWidget(label_32, 0, Qt::AlignHCenter);


        gridLayout_9->addLayout(verticalLayout_48, 0, 1, 2, 1);

        verticalLayout_49 = new QVBoxLayout();
        verticalLayout_49->setSpacing(6);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        wahwahLFOSlider = new QSlider(oscillator2Frame_9);
        wahwahLFOSlider->setObjectName(QStringLiteral("wahwahLFOSlider"));
        wahwahLFOSlider->setStyleSheet(QLatin1String("QSlider::handle:vertical {background-color: rgb(255, 181, 50);}\n"
""));
        wahwahLFOSlider->setMinimum(20);
        wahwahLFOSlider->setMaximum(500);
        wahwahLFOSlider->setValue(20);
        wahwahLFOSlider->setOrientation(Qt::Vertical);
        wahwahLFOSlider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_49->addWidget(wahwahLFOSlider, 0, Qt::AlignHCenter);

        label_33 = new QLabel(oscillator2Frame_9);
        label_33->setObjectName(QStringLiteral("label_33"));

        verticalLayout_49->addWidget(label_33, 0, Qt::AlignHCenter);


        gridLayout_9->addLayout(verticalLayout_49, 0, 2, 2, 1);


        verticalLayout_30->addLayout(gridLayout_9);


        verticalLayout_29->addWidget(oscillator2Frame_9);


        effectsHorizontalLayout->addWidget(wahwahEffectFrame);


        effectsScrollAreaLayout->addLayout(effectsHorizontalLayout);


        horizontalLayout_9->addLayout(effectsScrollAreaLayout);

        effectsScrollArea->setWidget(effectsScrollAreaContents);

        activeChannelAssetsPanel->addWidget(effectsScrollArea);


        verticalLayout_6->addLayout(activeChannelAssetsPanel);


        gridLayout->addLayout(verticalLayout_6, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        newChannelButton = new QPushButton(centralWidget);
        newChannelButton->setObjectName(QStringLiteral("newChannelButton"));
        QFont font6;
        font6.setPointSize(8);
        font6.setBold(true);
        font6.setWeight(75);
        newChannelButton->setFont(font6);
        newChannelButton->setAutoFillBackground(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/003-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        newChannelButton->setIcon(icon3);
        newChannelButton->setIconSize(QSize(18, 18));
        newChannelButton->setFlat(true);

        horizontalLayout_10->addWidget(newChannelButton);

        importMidiButton = new QPushButton(centralWidget);
        importMidiButton->setObjectName(QStringLiteral("importMidiButton"));
        importMidiButton->setFont(font1);
        importMidiButton->setAutoFillBackground(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/043-add folder.svg"), QSize(), QIcon::Normal, QIcon::Off);
        importMidiButton->setIcon(icon4);
        importMidiButton->setFlat(true);

        horizontalLayout_10->addWidget(importMidiButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        playButton_2 = new QPushButton(centralWidget);
        playButton_2->setObjectName(QStringLiteral("playButton_2"));
        sizePolicy9.setHeightForWidth(playButton_2->sizePolicy().hasHeightForWidth());
        playButton_2->setSizePolicy(sizePolicy9);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playButton_2->setIcon(icon5);
        playButton_2->setFlat(true);

        horizontalLayout_10->addWidget(playButton_2);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon6);
        pauseButton->setAutoDefault(false);
        pauseButton->setFlat(true);

        horizontalLayout_10->addWidget(pauseButton);

        stopButton_2 = new QPushButton(centralWidget);
        stopButton_2->setObjectName(QStringLiteral("stopButton_2"));
        sizePolicy9.setHeightForWidth(stopButton_2->sizePolicy().hasHeightForWidth());
        stopButton_2->setSizePolicy(sizePolicy9);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton_2->setIcon(icon7);
        stopButton_2->setFlat(true);

        horizontalLayout_10->addWidget(stopButton_2);

        recordButton_2 = new QPushButton(centralWidget);
        recordButton_2->setObjectName(QStringLiteral("recordButton_2"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/icons/rec.svg"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton_2->setIcon(icon8);
        recordButton_2->setFlat(true);

        horizontalLayout_10->addWidget(recordButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

        LeandroClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LeandroClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LeandroClass->setStatusBar(statusBar);

        retranslateUi(LeandroClass);

        eq8MoveLeftButton->setDefault(false);
        reverbMoveLeftButton->setDefault(false);
        flangerMoveLeftButton->setDefault(false);
        vibratoMoveLeftButton->setDefault(false);
        wahwahMoveLeftButton->setDefault(false);


        QMetaObject::connectSlotsByName(LeandroClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeandroClass)
    {
        LeandroClass->setWindowTitle(QApplication::translate("LeandroClass", "Leandro", Q_NULLPTR));
        label_7->setText(QApplication::translate("LeandroClass", "Instruments", Q_NULLPTR));
        setInstrumentButton->setText(QApplication::translate("LeandroClass", "Set for Channel", Q_NULLPTR));
        label_8->setText(QApplication::translate("LeandroClass", "Effects", Q_NULLPTR));
        addEffectButton->setText(QApplication::translate("LeandroClass", "Add to Channel", Q_NULLPTR));
        nameLabelChannel1->setText(QApplication::translate("LeandroClass", "Channel 1", Q_NULLPTR));
        closeButtonChannel1->setText(QString());
        setActiveButtonChannel1_2->setText(QApplication::translate("LeandroClass", "Set Active", Q_NULLPTR));
        inputComboBoxChannel1_2->clear();
        inputComboBoxChannel1_2->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "MIDI Track", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "PC Keyboard", Q_NULLPTR)
        );

        const bool __sortingEnabled = midiListChannel1_2->isSortingEnabled();
        midiListChannel1_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = midiListChannel1_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("LeandroClass", "MIDI 1 - Track 1", Q_NULLPTR));
        midiListChannel1_2->setSortingEnabled(__sortingEnabled);

        levelLabelChannel1_2->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        deleteADSRButton->setText(QString());
        instrumentNameLabel->setText(QApplication::translate("LeandroClass", "Waveform + ADSR", Q_NULLPTR));
        InstrumentNameADSR->setText(QApplication::translate("LeandroClass", "InstrumentName", Q_NULLPTR));
        oscillator1Label->setText(QApplication::translate("LeandroClass", "Oscillator 1", Q_NULLPTR));
        waveform1Label->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform1ComboBoxADSR->clear();
        waveform1ComboBoxADSR->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level1Label->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        oscillator2Label->setText(QApplication::translate("LeandroClass", "Oscillator 2", Q_NULLPTR));
        waveform2Label->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform2ComboBoxADSR->clear();
        waveform2ComboBoxADSR->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level2Label->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        envelopeParamsLabel->setText(QApplication::translate("LeandroClass", "Envelope Parameters", Q_NULLPTR));
        attackLabel->setText(QApplication::translate("LeandroClass", "Attack", Q_NULLPTR));
        decayLabel->setText(QApplication::translate("LeandroClass", "Decay", Q_NULLPTR));
        sustainLevelLabel->setText(QApplication::translate("LeandroClass", "Sustain Level", Q_NULLPTR));
        sustainRateLabel->setText(QApplication::translate("LeandroClass", "Sustain Rate", Q_NULLPTR));
        releaseLabel->setText(QApplication::translate("LeandroClass", "Release", Q_NULLPTR));
        deleteAdditiveButton->setText(QString());
        instrumentNameLabel_4->setText(QApplication::translate("LeandroClass", "Harmonic Addition", Q_NULLPTR));
        instrumentNameAdditive->setText(QApplication::translate("LeandroClass", "InstrumentName", Q_NULLPTR));
        oscillator2Label_4->setText(QApplication::translate("LeandroClass", "Harmonic Level Control", Q_NULLPTR));
        sliderLabelH0->setText(QApplication::translate("LeandroClass", "0", Q_NULLPTR));
        label_29->setText(QApplication::translate("LeandroClass", "1", Q_NULLPTR));
        label_3->setText(QApplication::translate("LeandroClass", "2", Q_NULLPTR));
        label_20->setText(QApplication::translate("LeandroClass", "3", Q_NULLPTR));
        label_27->setText(QApplication::translate("LeandroClass", "4", Q_NULLPTR));
        label_21->setText(QApplication::translate("LeandroClass", "5", Q_NULLPTR));
        label_22->setText(QApplication::translate("LeandroClass", "6", Q_NULLPTR));
        label_28->setText(QApplication::translate("LeandroClass", "7", Q_NULLPTR));
        label_23->setText(QApplication::translate("LeandroClass", "8", Q_NULLPTR));
        label_24->setText(QApplication::translate("LeandroClass", "9", Q_NULLPTR));
        label_25->setText(QApplication::translate("LeandroClass", "10", Q_NULLPTR));
        label_2->setText(QApplication::translate("LeandroClass", "11", Q_NULLPTR));
        deleteSamplingButton->setText(QString());
        instrumentNameLabel_3->setText(QApplication::translate("LeandroClass", "Sampling", Q_NULLPTR));
        instrumentNameSampling->setText(QApplication::translate("LeandroClass", "InstrumentName", Q_NULLPTR));
        envelopeParamsLabel_3->setText(QApplication::translate("LeandroClass", "Sample Playback Parameters", Q_NULLPTR));
        sustainLabel_3->setText(QApplication::translate("LeandroClass", "Loop Start", Q_NULLPTR));
        releaseLabel_3->setText(QApplication::translate("LeandroClass", "Loop End", Q_NULLPTR));
        deleteKarplusButton->setText(QString());
        instrumentNameLabel_2->setText(QApplication::translate("LeandroClass", "Karplus-Strong", Q_NULLPTR));
        instrumentNameKarplus->setText(QApplication::translate("LeandroClass", "InstrumentName", Q_NULLPTR));
        decayLabel_2->setText(QApplication::translate("LeandroClass", "Stretch", Q_NULLPTR));
        releaseLabel_2->setText(QApplication::translate("LeandroClass", "Decay Loss", Q_NULLPTR));
        sustainLabel_2->setText(QApplication::translate("LeandroClass", "Blend", Q_NULLPTR));
        delete8EqButton->setText(QString());
        label_5->setText(QApplication::translate("LeandroClass", "8-Band Equalizer", Q_NULLPTR));
        eq8MoveLeftButton->setText(QString());
        eq8MoveRightButton->setText(QString());
        oscillator2Label_6->setText(QApplication::translate("LeandroClass", "Gain Control", Q_NULLPTR));
        sliderLabelH0_3->setText(QApplication::translate("LeandroClass", "100", Q_NULLPTR));
        label_35->setText(QApplication::translate("LeandroClass", "200", Q_NULLPTR));
        label_6->setText(QApplication::translate("LeandroClass", "400", Q_NULLPTR));
        label_36->setText(QApplication::translate("LeandroClass", "800", Q_NULLPTR));
        label_37->setText(QApplication::translate("LeandroClass", "1.4k", Q_NULLPTR));
        label_38->setText(QApplication::translate("LeandroClass", "2.7k", Q_NULLPTR));
        label_39->setText(QApplication::translate("LeandroClass", "5k", Q_NULLPTR));
        label_40->setText(QApplication::translate("LeandroClass", "10k", Q_NULLPTR));
        deleteReverbButton->setText(QString());
        label_10->setText(QApplication::translate("LeandroClass", "Reverb", Q_NULLPTR));
        reverbMoveLeftButton->setText(QString());
        reverbMoveRightButton->setText(QString());
        label_12->setText(QApplication::translate("LeandroClass", "Reverb Type", Q_NULLPTR));
        reverbTypeComboBox->clear();
        reverbTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Plain", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Echo", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Low-Pass", Q_NULLPTR)
        );
        oscillator2Label_7->setText(QApplication::translate("LeandroClass", "Parameters", Q_NULLPTR));
        label_13->setText(QApplication::translate("LeandroClass", "Delay", Q_NULLPTR));
        label_14->setText(QApplication::translate("LeandroClass", "Attenuation", Q_NULLPTR));
        deleteFlangerButton->setText(QString());
        label_17->setText(QApplication::translate("LeandroClass", "Flanger", Q_NULLPTR));
        flangerMoveLeftButton->setText(QString());
        flangerMoveRightButton->setText(QString());
        label_18->setText(QApplication::translate("LeandroClass", "GFB", Q_NULLPTR));
        label_19->setText(QApplication::translate("LeandroClass", "Mw", Q_NULLPTR));
        label_26->setText(QApplication::translate("LeandroClass", "M0", Q_NULLPTR));
        label_30->setText(QApplication::translate("LeandroClass", "GFF", Q_NULLPTR));
        label_31->setText(QApplication::translate("LeandroClass", "F0", Q_NULLPTR));
        deleteVibratoButton->setText(QString());
        label->setText(QApplication::translate("LeandroClass", "Vibrato", Q_NULLPTR));
        vibratoMoveLeftButton->setText(QString());
        vibratoMoveRightButton->setText(QString());
        label_16->setText(QApplication::translate("LeandroClass", "F0", Q_NULLPTR));
        label_4->setText(QApplication::translate("LeandroClass", "Mavg", Q_NULLPTR));
        label_9->setText(QApplication::translate("LeandroClass", "Width", Q_NULLPTR));
        deleteWahwahButton->setText(QString());
        label_11->setText(QApplication::translate("LeandroClass", "Wah-Wah", Q_NULLPTR));
        wahwahMoveLeftButton->setText(QString());
        wahwahMoveRightButton->setText(QString());
        label_32->setText(QApplication::translate("LeandroClass", "Fmin", Q_NULLPTR));
        label_33->setText(QApplication::translate("LeandroClass", "LFO Frequency", Q_NULLPTR));
        newChannelButton->setText(QApplication::translate("LeandroClass", "Add Channel", Q_NULLPTR));
        importMidiButton->setText(QApplication::translate("LeandroClass", " Import MIDI File...", Q_NULLPTR));
        playButton_2->setText(QString());
        pauseButton->setText(QString());
        stopButton_2->setText(QString());
        recordButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LeandroClass: public Ui_LeandroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEANDRO_H
