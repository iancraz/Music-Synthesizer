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
#include <QtWidgets/QGroupBox>
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
    QPushButton *addChannelButton;
    QLabel *label_8;
    QListWidget *effectsList;
    QPushButton *setInstrumentButton;
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
    QPushButton *deleteInstrumentButton;
    QLabel *instrumentNameLabel;
    QFrame *line_2;
    QVBoxLayout *framesVLayout;
    QFrame *oscillator1Frame;
    QVBoxLayout *verticalLayout_14;
    QLabel *oscillator1Label;
    QHBoxLayout *oscillator1HLayout;
    QVBoxLayout *oscillator1WaveVLayout;
    QLabel *waveform1Label;
    QComboBox *waveform1ComboBox;
    QHBoxLayout *oscillator1LevelHLayout;
    QLabel *level1Label;
    QDial *levelWF1Dial;
    QFrame *oscillator2Frame;
    QVBoxLayout *verticalLayout_15;
    QLabel *oscillator2Label;
    QHBoxLayout *oscillator2HLayout;
    QVBoxLayout *waveform2VLayout;
    QLabel *waveform2Label;
    QComboBox *waveform2ComboBox;
    QHBoxLayout *oscillator2LevelHLayout;
    QLabel *level2Label;
    QDial *levelWF2Dial;
    QFrame *line;
    QFrame *envelopeParamsFrame;
    QVBoxLayout *verticalLayout_16;
    QLabel *envelopeParamsLabel;
    QHBoxLayout *envelopeParamsHLayout;
    QVBoxLayout *attackVLayout;
    QDial *attackDial;
    QLabel *attackLabel;
    QVBoxLayout *decayVLayout;
    QDial *decayDial;
    QLabel *decayLabel;
    QVBoxLayout *sustainVLayout;
    QDial *sustainLevelDial;
    QLabel *sustainLevelLabel;
    QVBoxLayout *releaseVLayout_5;
    QDial *sustainRateDial;
    QLabel *sustainRateLabel;
    QVBoxLayout *releaseVLayout;
    QDial *releaseDial;
    QLabel *releaseLabel;
    QFrame *additiveInstrumentFrame;
    QGridLayout *gridLayout_7;
    QHBoxLayout *nameHLayout_4;
    QPushButton *deleteInstrumentButton_4;
    QLabel *instrumentNameLabel_4;
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
    QFrame *envelopeParamsFrame_4;
    QVBoxLayout *verticalLayout_25;
    QLabel *envelopeParamsLabel_4;
    QHBoxLayout *envelopeParamsHLayout_4;
    QVBoxLayout *attackVLayout_4;
    QDial *attackDialAdditive;
    QLabel *attackLabel_4;
    QVBoxLayout *decayVLayout_4;
    QDial *delayDialAdditive;
    QLabel *decayLabel_4;
    QVBoxLayout *sustainVLayout_4;
    QDial *sustainLevelDialAdditive;
    QLabel *sustainLabel_4;
    QVBoxLayout *releaseVLayout_6;
    QDial *sustainRateDialAdditive;
    QLabel *sustainRateLabel_2;
    QVBoxLayout *releaseVLayout_4;
    QDial *releaseDialAdditive;
    QLabel *releaseLabel_4;
    QFrame *samplingInstrumentFrame;
    QGridLayout *gridLayout_6;
    QHBoxLayout *nameHLayout_3;
    QPushButton *deleteInstrumentButton_3;
    QLabel *instrumentNameLabel_3;
    QFrame *line_6;
    QVBoxLayout *framesVLayout_3;
    QFrame *oscillator1Frame_3;
    QVBoxLayout *verticalLayout_20;
    QLabel *oscillator1Label_3;
    QHBoxLayout *oscillator1HLayout_3;
    QVBoxLayout *oscillator1WaveVLayout_3;
    QLabel *waveform1Label_3;
    QComboBox *waveform1ComboBox_3;
    QHBoxLayout *oscillator1LevelHLayout_3;
    QLabel *level1Label_3;
    QDial *level1Dial_3;
    QFrame *oscillator2Frame_3;
    QVBoxLayout *verticalLayout_21;
    QLabel *oscillator2Label_3;
    QHBoxLayout *oscillator2HLayout_3;
    QVBoxLayout *waveform2VLayout_3;
    QLabel *waveform2Label_3;
    QComboBox *waveform2ComboBox_3;
    QHBoxLayout *oscillator2LevelHLayout_3;
    QLabel *level2Label_3;
    QDial *level2Dial_3;
    QFrame *line_7;
    QFrame *envelopeParamsFrame_3;
    QVBoxLayout *verticalLayout_22;
    QLabel *envelopeParamsLabel_3;
    QHBoxLayout *envelopeParamsHLayout_3;
    QVBoxLayout *attackVLayout_3;
    QDial *attackDial_3;
    QLabel *attackLabel_3;
    QVBoxLayout *decayVLayout_3;
    QDial *decayDial_3;
    QLabel *decayLabel_3;
    QVBoxLayout *sustainVLayout_3;
    QDial *sustainDial_3;
    QLabel *sustainLabel_3;
    QVBoxLayout *releaseVLayout_3;
    QDial *releaseDial_3;
    QLabel *releaseLabel_3;
    QFrame *karplusInstrumentFrame;
    QGridLayout *gridLayout_5;
    QHBoxLayout *nameHLayout_2;
    QPushButton *deleteInstrumentButton_2;
    QLabel *instrumentNameLabel_2;
    QFrame *line_4;
    QVBoxLayout *framesVLayout_2;
    QFrame *oscillator1Frame_2;
    QVBoxLayout *verticalLayout_17;
    QLabel *oscillator1Label_2;
    QHBoxLayout *oscillator1HLayout_2;
    QVBoxLayout *oscillator1WaveVLayout_2;
    QLabel *waveform1Label_2;
    QComboBox *waveform1ComboBox_2;
    QHBoxLayout *oscillator1LevelHLayout_2;
    QLabel *level1Label_2;
    QDial *level1Dial_2;
    QFrame *oscillator2Frame_2;
    QVBoxLayout *verticalLayout_18;
    QLabel *oscillator2Label_2;
    QHBoxLayout *oscillator2HLayout_2;
    QVBoxLayout *waveform2VLayout_2;
    QLabel *waveform2Label_2;
    QComboBox *waveform2ComboBox_2;
    QHBoxLayout *oscillator2LevelHLayout_2;
    QLabel *level2Label_2;
    QDial *level2Dial_2;
    QFrame *line_5;
    QFrame *envelopeParamsFrame_2;
    QVBoxLayout *verticalLayout_19;
    QLabel *envelopeParamsLabel_2;
    QHBoxLayout *envelopeParamsHLayout_2;
    QVBoxLayout *attackVLayout_2;
    QDial *attackDial_2;
    QLabel *attackLabel_2;
    QVBoxLayout *decayVLayout_2;
    QDial *decayDial_2;
    QLabel *decayLabel_2;
    QVBoxLayout *sustainVLayout_2;
    QDial *sustainDial_2;
    QLabel *sustainLabel_2;
    QVBoxLayout *releaseVLayout_2;
    QDial *releaseDial_2;
    QLabel *releaseLabel_2;
    QScrollArea *effectsScrollArea;
    QWidget *effectsScrollAreaContents;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *effectsScrollAreaLayout;
    QHBoxLayout *effectsHorizontalLayout;
    QFrame *frameEffect1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QFrame *line_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QDial *dial;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *importButton;
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
        LeandroClass->resize(2310, 766);
        LeandroClass->setMinimumSize(QSize(800, 0));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(165, 165, 165, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(135, 135, 135, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(42, 42, 42, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush3);
        QBrush brush4(QColor(90, 90, 90, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(255, 170, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush6(QColor(110, 110, 110, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(255, 181, 50, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        QBrush brush8(QColor(255, 255, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush8);
        QBrush brush9(QColor(195, 195, 195, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(0, 255, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush10);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
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
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush12(QColor(74, 74, 74, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush12);
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

        addChannelButton = new QPushButton(frame_3);
        addChannelButton->setObjectName(QStringLiteral("addChannelButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addChannelButton->sizePolicy().hasHeightForWidth());
        addChannelButton->setSizePolicy(sizePolicy1);
        addChannelButton->setMaximumSize(QSize(16777215, 15));
        QFont font2;
        font2.setPointSize(7);
        addChannelButton->setFont(font2);
        addChannelButton->setAutoFillBackground(true);
        addChannelButton->setFlat(true);

        verticalLayout_2->addWidget(addChannelButton, 0, Qt::AlignHCenter);

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

        setInstrumentButton = new QPushButton(frame_3);
        setInstrumentButton->setObjectName(QStringLiteral("setInstrumentButton"));
        sizePolicy1.setHeightForWidth(setInstrumentButton->sizePolicy().hasHeightForWidth());
        setInstrumentButton->setSizePolicy(sizePolicy1);
        setInstrumentButton->setMaximumSize(QSize(16777215, 15));
        setInstrumentButton->setBaseSize(QSize(0, 0));
        setInstrumentButton->setFont(font2);
        setInstrumentButton->setAutoFillBackground(true);
        setInstrumentButton->setFlat(true);

        verticalLayout_2->addWidget(setInstrumentButton, 0, Qt::AlignHCenter);


        horizontalLayout_5->addWidget(frame_3, 0, Qt::AlignHCenter);

        scrollAreaChannels_2 = new QScrollArea(centralWidget);
        scrollAreaChannels_2->setObjectName(QStringLiteral("scrollAreaChannels_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaChannels_2->sizePolicy().hasHeightForWidth());
        scrollAreaChannels_2->setSizePolicy(sizePolicy2);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        scrollAreaChannels_2->setPalette(palette2);
        scrollAreaChannels_2->setAutoFillBackground(true);
        scrollAreaChannels_2->setFrameShape(QFrame::Panel);
        scrollAreaChannels_2->setFrameShadow(QFrame::Sunken);
        scrollAreaChannels_2->setLineWidth(3);
        scrollAreaChannels_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaChannels_2->setWidgetResizable(true);
        scrollAreaChannelsWidgetContents_2 = new QWidget();
        scrollAreaChannelsWidgetContents_2->setObjectName(QStringLiteral("scrollAreaChannelsWidgetContents_2"));
        scrollAreaChannelsWidgetContents_2->setGeometry(QRect(0, 0, 2152, 294));
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
        palette3.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
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
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
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
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush6);
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
        deleteInstrumentButton = new QPushButton(adsrInstrumentFrame);
        deleteInstrumentButton->setObjectName(QStringLiteral("deleteInstrumentButton"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(deleteInstrumentButton->sizePolicy().hasHeightForWidth());
        deleteInstrumentButton->setSizePolicy(sizePolicy9);
        deleteInstrumentButton->setFocusPolicy(Qt::StrongFocus);
        deleteInstrumentButton->setIcon(icon);
        deleteInstrumentButton->setIconSize(QSize(15, 15));
        deleteInstrumentButton->setFlat(true);

        nameHLayout->addWidget(deleteInstrumentButton);

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

        waveform1ComboBox = new QComboBox(oscillator1Frame);
        waveform1ComboBox->setObjectName(QStringLiteral("waveform1ComboBox"));
        sizePolicy1.setHeightForWidth(waveform1ComboBox->sizePolicy().hasHeightForWidth());
        waveform1ComboBox->setSizePolicy(sizePolicy1);
        waveform1ComboBox->setMaximumSize(QSize(16777215, 15));
        waveform1ComboBox->setAutoFillBackground(true);
        waveform1ComboBox->setFrame(false);

        oscillator1WaveVLayout->addWidget(waveform1ComboBox);


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

        levelWF1Dial = new QDial(oscillator1Frame);
        levelWF1Dial->setObjectName(QStringLiteral("levelWF1Dial"));
        sizePolicy1.setHeightForWidth(levelWF1Dial->sizePolicy().hasHeightForWidth());
        levelWF1Dial->setSizePolicy(sizePolicy1);
        levelWF1Dial->setMaximumSize(QSize(57, 16777215));
        levelWF1Dial->setMaximum(100);
        levelWF1Dial->setValue(1);
        levelWF1Dial->setWrapping(false);
        levelWF1Dial->setNotchesVisible(true);

        oscillator1LevelHLayout->addWidget(levelWF1Dial);


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

        waveform2ComboBox = new QComboBox(oscillator2Frame);
        waveform2ComboBox->setObjectName(QStringLiteral("waveform2ComboBox"));
        sizePolicy1.setHeightForWidth(waveform2ComboBox->sizePolicy().hasHeightForWidth());
        waveform2ComboBox->setSizePolicy(sizePolicy1);
        waveform2ComboBox->setMaximumSize(QSize(16777215, 15));
        waveform2ComboBox->setAutoFillBackground(true);
        waveform2ComboBox->setFrame(false);

        waveform2VLayout->addWidget(waveform2ComboBox);


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

        levelWF2Dial = new QDial(oscillator2Frame);
        levelWF2Dial->setObjectName(QStringLiteral("levelWF2Dial"));
        sizePolicy1.setHeightForWidth(levelWF2Dial->sizePolicy().hasHeightForWidth());
        levelWF2Dial->setSizePolicy(sizePolicy1);
        levelWF2Dial->setMaximumSize(QSize(57, 16777215));
        levelWF2Dial->setMaximum(100);
        levelWF2Dial->setWrapping(false);
        levelWF2Dial->setNotchTarget(3.7);
        levelWF2Dial->setNotchesVisible(true);

        oscillator2LevelHLayout->addWidget(levelWF2Dial);


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
        sizePolicy8.setHeightForWidth(envelopeParamsFrame->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame->setSizePolicy(sizePolicy8);
        envelopeParamsFrame->setFrameShape(QFrame::Panel);
        envelopeParamsFrame->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame->setLineWidth(2);
        verticalLayout_16 = new QVBoxLayout(envelopeParamsFrame);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(-1, 2, -1, 2);
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
        attackDial = new QDial(envelopeParamsFrame);
        attackDial->setObjectName(QStringLiteral("attackDial"));
        sizePolicy8.setHeightForWidth(attackDial->sizePolicy().hasHeightForWidth());
        attackDial->setSizePolicy(sizePolicy8);
        attackDial->setMaximumSize(QSize(60, 60));
        attackDial->setMinimum(5);
        attackDial->setMaximum(15000);
        attackDial->setSingleStep(1);
        attackDial->setNotchesVisible(true);

        attackVLayout->addWidget(attackDial);

        attackLabel = new QLabel(envelopeParamsFrame);
        attackLabel->setObjectName(QStringLiteral("attackLabel"));
        sizePolicy8.setHeightForWidth(attackLabel->sizePolicy().hasHeightForWidth());
        attackLabel->setSizePolicy(sizePolicy8);

        attackVLayout->addWidget(attackLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(attackVLayout);

        decayVLayout = new QVBoxLayout();
        decayVLayout->setSpacing(6);
        decayVLayout->setObjectName(QStringLiteral("decayVLayout"));
        decayDial = new QDial(envelopeParamsFrame);
        decayDial->setObjectName(QStringLiteral("decayDial"));
        sizePolicy8.setHeightForWidth(decayDial->sizePolicy().hasHeightForWidth());
        decayDial->setSizePolicy(sizePolicy8);
        decayDial->setMaximumSize(QSize(60, 16777215));
        decayDial->setMinimum(5);
        decayDial->setMaximum(15000);
        decayDial->setNotchesVisible(true);

        decayVLayout->addWidget(decayDial);

        decayLabel = new QLabel(envelopeParamsFrame);
        decayLabel->setObjectName(QStringLiteral("decayLabel"));
        sizePolicy8.setHeightForWidth(decayLabel->sizePolicy().hasHeightForWidth());
        decayLabel->setSizePolicy(sizePolicy8);

        decayVLayout->addWidget(decayLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(decayVLayout);

        sustainVLayout = new QVBoxLayout();
        sustainVLayout->setSpacing(6);
        sustainVLayout->setObjectName(QStringLiteral("sustainVLayout"));
        sustainLevelDial = new QDial(envelopeParamsFrame);
        sustainLevelDial->setObjectName(QStringLiteral("sustainLevelDial"));
        sizePolicy8.setHeightForWidth(sustainLevelDial->sizePolicy().hasHeightForWidth());
        sustainLevelDial->setSizePolicy(sizePolicy8);
        sustainLevelDial->setMaximumSize(QSize(60, 16777215));
        sustainLevelDial->setNotchesVisible(true);

        sustainVLayout->addWidget(sustainLevelDial);

        sustainLevelLabel = new QLabel(envelopeParamsFrame);
        sustainLevelLabel->setObjectName(QStringLiteral("sustainLevelLabel"));
        sizePolicy8.setHeightForWidth(sustainLevelLabel->sizePolicy().hasHeightForWidth());
        sustainLevelLabel->setSizePolicy(sizePolicy8);

        sustainVLayout->addWidget(sustainLevelLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(sustainVLayout);

        releaseVLayout_5 = new QVBoxLayout();
        releaseVLayout_5->setSpacing(6);
        releaseVLayout_5->setObjectName(QStringLiteral("releaseVLayout_5"));
        sustainRateDial = new QDial(envelopeParamsFrame);
        sustainRateDial->setObjectName(QStringLiteral("sustainRateDial"));
        sizePolicy8.setHeightForWidth(sustainRateDial->sizePolicy().hasHeightForWidth());
        sustainRateDial->setSizePolicy(sizePolicy8);
        sustainRateDial->setMaximumSize(QSize(60, 16777215));
        sustainRateDial->setMaximum(1000);
        sustainRateDial->setNotchesVisible(true);

        releaseVLayout_5->addWidget(sustainRateDial);

        sustainRateLabel = new QLabel(envelopeParamsFrame);
        sustainRateLabel->setObjectName(QStringLiteral("sustainRateLabel"));
        sizePolicy8.setHeightForWidth(sustainRateLabel->sizePolicy().hasHeightForWidth());
        sustainRateLabel->setSizePolicy(sizePolicy8);

        releaseVLayout_5->addWidget(sustainRateLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(releaseVLayout_5);

        releaseVLayout = new QVBoxLayout();
        releaseVLayout->setSpacing(6);
        releaseVLayout->setObjectName(QStringLiteral("releaseVLayout"));
        releaseDial = new QDial(envelopeParamsFrame);
        releaseDial->setObjectName(QStringLiteral("releaseDial"));
        sizePolicy8.setHeightForWidth(releaseDial->sizePolicy().hasHeightForWidth());
        releaseDial->setSizePolicy(sizePolicy8);
        releaseDial->setMaximumSize(QSize(60, 16777215));
        releaseDial->setMinimum(1);
        releaseDial->setMaximum(15000);
        releaseDial->setNotchesVisible(true);

        releaseVLayout->addWidget(releaseDial);

        releaseLabel = new QLabel(envelopeParamsFrame);
        releaseLabel->setObjectName(QStringLiteral("releaseLabel"));
        sizePolicy8.setHeightForWidth(releaseLabel->sizePolicy().hasHeightForWidth());
        releaseLabel->setSizePolicy(sizePolicy8);

        releaseVLayout->addWidget(releaseLabel, 0, Qt::AlignHCenter);


        envelopeParamsHLayout->addLayout(releaseVLayout);


        verticalLayout_16->addLayout(envelopeParamsHLayout);


        framesVLayout->addWidget(envelopeParamsFrame);


        gridLayout_3->addLayout(framesVLayout, 2, 0, 1, 1);


        instrumentLayout->addWidget(adsrInstrumentFrame);

        additiveInstrumentFrame = new QFrame(instrumentFrameFrame);
        additiveInstrumentFrame->setObjectName(QStringLiteral("additiveInstrumentFrame"));
        sizePolicy8.setHeightForWidth(additiveInstrumentFrame->sizePolicy().hasHeightForWidth());
        additiveInstrumentFrame->setSizePolicy(sizePolicy8);
        additiveInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush6);
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
        deleteInstrumentButton_4 = new QPushButton(additiveInstrumentFrame);
        deleteInstrumentButton_4->setObjectName(QStringLiteral("deleteInstrumentButton_4"));
        sizePolicy9.setHeightForWidth(deleteInstrumentButton_4->sizePolicy().hasHeightForWidth());
        deleteInstrumentButton_4->setSizePolicy(sizePolicy9);
        deleteInstrumentButton_4->setFocusPolicy(Qt::StrongFocus);
        deleteInstrumentButton_4->setIcon(icon);
        deleteInstrumentButton_4->setIconSize(QSize(15, 15));
        deleteInstrumentButton_4->setFlat(true);

        nameHLayout_4->addWidget(deleteInstrumentButton_4);

        instrumentNameLabel_4 = new QLabel(additiveInstrumentFrame);
        instrumentNameLabel_4->setObjectName(QStringLiteral("instrumentNameLabel_4"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_4->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_4->setSizePolicy(sizePolicy10);
        instrumentNameLabel_4->setFont(font4);

        nameHLayout_4->addWidget(instrumentNameLabel_4);


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
        sizePolicy10.setHeightForWidth(oscillator2Frame_4->sizePolicy().hasHeightForWidth());
        oscillator2Frame_4->setSizePolicy(sizePolicy10);
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
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(slidersFrame->sizePolicy().hasHeightForWidth());
        slidersFrame->setSizePolicy(sizePolicy11);
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
        sliderH11->setMaximum(100);
        sliderH11->setPageStep(10);
        sliderH11->setValue(100);
        sliderH11->setOrientation(Qt::Vertical);

        verticalLayout_3->addWidget(sliderH11);

        label_2 = new QLabel(slidersFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy12(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy12);

        verticalLayout_3->addWidget(label_2, 0, Qt::AlignHCenter);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_24->addWidget(slidersFrame);


        framesVLayout_4->addWidget(oscillator2Frame_4);

        line_9 = new QFrame(additiveInstrumentFrame);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        framesVLayout_4->addWidget(line_9);

        envelopeParamsFrame_4 = new QFrame(additiveInstrumentFrame);
        envelopeParamsFrame_4->setObjectName(QStringLiteral("envelopeParamsFrame_4"));
        QSizePolicy sizePolicy13(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(envelopeParamsFrame_4->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame_4->setSizePolicy(sizePolicy13);
        envelopeParamsFrame_4->setFrameShape(QFrame::Panel);
        envelopeParamsFrame_4->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame_4->setLineWidth(2);
        verticalLayout_25 = new QVBoxLayout(envelopeParamsFrame_4);
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setContentsMargins(11, 11, 11, 11);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(-1, 2, -1, 2);
        envelopeParamsLabel_4 = new QLabel(envelopeParamsFrame_4);
        envelopeParamsLabel_4->setObjectName(QStringLiteral("envelopeParamsLabel_4"));
        envelopeParamsLabel_4->setMaximumSize(QSize(16777215, 14));
        envelopeParamsLabel_4->setFont(font1);

        verticalLayout_25->addWidget(envelopeParamsLabel_4, 0, Qt::AlignHCenter);

        envelopeParamsHLayout_4 = new QHBoxLayout();
        envelopeParamsHLayout_4->setSpacing(6);
        envelopeParamsHLayout_4->setObjectName(QStringLiteral("envelopeParamsHLayout_4"));
        attackVLayout_4 = new QVBoxLayout();
        attackVLayout_4->setSpacing(6);
        attackVLayout_4->setObjectName(QStringLiteral("attackVLayout_4"));
        attackDialAdditive = new QDial(envelopeParamsFrame_4);
        attackDialAdditive->setObjectName(QStringLiteral("attackDialAdditive"));
        sizePolicy8.setHeightForWidth(attackDialAdditive->sizePolicy().hasHeightForWidth());
        attackDialAdditive->setSizePolicy(sizePolicy8);
        attackDialAdditive->setMaximumSize(QSize(60, 16777215));
        attackDialAdditive->setMinimum(5);
        attackDialAdditive->setMaximum(15000);
        attackDialAdditive->setNotchesVisible(true);

        attackVLayout_4->addWidget(attackDialAdditive, 0, Qt::AlignHCenter);

        attackLabel_4 = new QLabel(envelopeParamsFrame_4);
        attackLabel_4->setObjectName(QStringLiteral("attackLabel_4"));
        sizePolicy8.setHeightForWidth(attackLabel_4->sizePolicy().hasHeightForWidth());
        attackLabel_4->setSizePolicy(sizePolicy8);

        attackVLayout_4->addWidget(attackLabel_4, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_4->addLayout(attackVLayout_4);

        decayVLayout_4 = new QVBoxLayout();
        decayVLayout_4->setSpacing(6);
        decayVLayout_4->setObjectName(QStringLiteral("decayVLayout_4"));
        delayDialAdditive = new QDial(envelopeParamsFrame_4);
        delayDialAdditive->setObjectName(QStringLiteral("delayDialAdditive"));
        sizePolicy8.setHeightForWidth(delayDialAdditive->sizePolicy().hasHeightForWidth());
        delayDialAdditive->setSizePolicy(sizePolicy8);
        delayDialAdditive->setMaximumSize(QSize(60, 16777215));
        delayDialAdditive->setMinimum(5);
        delayDialAdditive->setMaximum(15000);
        delayDialAdditive->setNotchesVisible(true);

        decayVLayout_4->addWidget(delayDialAdditive, 0, Qt::AlignHCenter);

        decayLabel_4 = new QLabel(envelopeParamsFrame_4);
        decayLabel_4->setObjectName(QStringLiteral("decayLabel_4"));
        sizePolicy8.setHeightForWidth(decayLabel_4->sizePolicy().hasHeightForWidth());
        decayLabel_4->setSizePolicy(sizePolicy8);

        decayVLayout_4->addWidget(decayLabel_4, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_4->addLayout(decayVLayout_4);

        sustainVLayout_4 = new QVBoxLayout();
        sustainVLayout_4->setSpacing(6);
        sustainVLayout_4->setObjectName(QStringLiteral("sustainVLayout_4"));
        sustainLevelDialAdditive = new QDial(envelopeParamsFrame_4);
        sustainLevelDialAdditive->setObjectName(QStringLiteral("sustainLevelDialAdditive"));
        sizePolicy8.setHeightForWidth(sustainLevelDialAdditive->sizePolicy().hasHeightForWidth());
        sustainLevelDialAdditive->setSizePolicy(sizePolicy8);
        sustainLevelDialAdditive->setMaximumSize(QSize(60, 16777215));
        sustainLevelDialAdditive->setAutoFillBackground(false);
        sustainLevelDialAdditive->setMinimum(0);
        sustainLevelDialAdditive->setMaximum(99);
        sustainLevelDialAdditive->setNotchesVisible(true);

        sustainVLayout_4->addWidget(sustainLevelDialAdditive, 0, Qt::AlignHCenter);

        sustainLabel_4 = new QLabel(envelopeParamsFrame_4);
        sustainLabel_4->setObjectName(QStringLiteral("sustainLabel_4"));
        sizePolicy8.setHeightForWidth(sustainLabel_4->sizePolicy().hasHeightForWidth());
        sustainLabel_4->setSizePolicy(sizePolicy8);

        sustainVLayout_4->addWidget(sustainLabel_4, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_4->addLayout(sustainVLayout_4);

        releaseVLayout_6 = new QVBoxLayout();
        releaseVLayout_6->setSpacing(6);
        releaseVLayout_6->setObjectName(QStringLiteral("releaseVLayout_6"));
        sustainRateDialAdditive = new QDial(envelopeParamsFrame_4);
        sustainRateDialAdditive->setObjectName(QStringLiteral("sustainRateDialAdditive"));
        sizePolicy8.setHeightForWidth(sustainRateDialAdditive->sizePolicy().hasHeightForWidth());
        sustainRateDialAdditive->setSizePolicy(sizePolicy8);
        sustainRateDialAdditive->setMaximumSize(QSize(60, 16777215));
        sustainRateDialAdditive->setMinimum(5);
        sustainRateDialAdditive->setMaximum(15000);
        sustainRateDialAdditive->setNotchesVisible(true);

        releaseVLayout_6->addWidget(sustainRateDialAdditive);

        sustainRateLabel_2 = new QLabel(envelopeParamsFrame_4);
        sustainRateLabel_2->setObjectName(QStringLiteral("sustainRateLabel_2"));
        sizePolicy8.setHeightForWidth(sustainRateLabel_2->sizePolicy().hasHeightForWidth());
        sustainRateLabel_2->setSizePolicy(sizePolicy8);

        releaseVLayout_6->addWidget(sustainRateLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_4->addLayout(releaseVLayout_6);

        releaseVLayout_4 = new QVBoxLayout();
        releaseVLayout_4->setSpacing(6);
        releaseVLayout_4->setObjectName(QStringLiteral("releaseVLayout_4"));
        releaseDialAdditive = new QDial(envelopeParamsFrame_4);
        releaseDialAdditive->setObjectName(QStringLiteral("releaseDialAdditive"));
        sizePolicy8.setHeightForWidth(releaseDialAdditive->sizePolicy().hasHeightForWidth());
        releaseDialAdditive->setSizePolicy(sizePolicy8);
        releaseDialAdditive->setMaximumSize(QSize(60, 16777215));
        releaseDialAdditive->setMinimum(5);
        releaseDialAdditive->setMaximum(15000);
        releaseDialAdditive->setNotchesVisible(true);

        releaseVLayout_4->addWidget(releaseDialAdditive, 0, Qt::AlignHCenter);

        releaseLabel_4 = new QLabel(envelopeParamsFrame_4);
        releaseLabel_4->setObjectName(QStringLiteral("releaseLabel_4"));
        sizePolicy8.setHeightForWidth(releaseLabel_4->sizePolicy().hasHeightForWidth());
        releaseLabel_4->setSizePolicy(sizePolicy8);

        releaseVLayout_4->addWidget(releaseLabel_4, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_4->addLayout(releaseVLayout_4);


        verticalLayout_25->addLayout(envelopeParamsHLayout_4);


        framesVLayout_4->addWidget(envelopeParamsFrame_4);


        gridLayout_7->addLayout(framesVLayout_4, 2, 0, 1, 1);


        instrumentLayout->addWidget(additiveInstrumentFrame);

        samplingInstrumentFrame = new QFrame(instrumentFrameFrame);
        samplingInstrumentFrame->setObjectName(QStringLiteral("samplingInstrumentFrame"));
        sizePolicy8.setHeightForWidth(samplingInstrumentFrame->sizePolicy().hasHeightForWidth());
        samplingInstrumentFrame->setSizePolicy(sizePolicy8);
        samplingInstrumentFrame->setMinimumSize(QSize(10, 0));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush6);
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
        deleteInstrumentButton_3 = new QPushButton(samplingInstrumentFrame);
        deleteInstrumentButton_3->setObjectName(QStringLiteral("deleteInstrumentButton_3"));
        sizePolicy9.setHeightForWidth(deleteInstrumentButton_3->sizePolicy().hasHeightForWidth());
        deleteInstrumentButton_3->setSizePolicy(sizePolicy9);
        deleteInstrumentButton_3->setFocusPolicy(Qt::StrongFocus);
        deleteInstrumentButton_3->setIcon(icon);
        deleteInstrumentButton_3->setIconSize(QSize(15, 15));
        deleteInstrumentButton_3->setFlat(true);

        nameHLayout_3->addWidget(deleteInstrumentButton_3);

        instrumentNameLabel_3 = new QLabel(samplingInstrumentFrame);
        instrumentNameLabel_3->setObjectName(QStringLiteral("instrumentNameLabel_3"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_3->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_3->setSizePolicy(sizePolicy10);
        instrumentNameLabel_3->setFont(font4);

        nameHLayout_3->addWidget(instrumentNameLabel_3);


        gridLayout_6->addLayout(nameHLayout_3, 0, 0, 1, 1);

        line_6 = new QFrame(samplingInstrumentFrame);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_6->addWidget(line_6, 1, 0, 1, 1);

        framesVLayout_3 = new QVBoxLayout();
        framesVLayout_3->setSpacing(6);
        framesVLayout_3->setObjectName(QStringLiteral("framesVLayout_3"));
        oscillator1Frame_3 = new QFrame(samplingInstrumentFrame);
        oscillator1Frame_3->setObjectName(QStringLiteral("oscillator1Frame_3"));
        oscillator1Frame_3->setFrameShape(QFrame::Panel);
        oscillator1Frame_3->setFrameShadow(QFrame::Sunken);
        oscillator1Frame_3->setLineWidth(2);
        verticalLayout_20 = new QVBoxLayout(oscillator1Frame_3);
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setContentsMargins(11, 11, 11, 11);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        verticalLayout_20->setContentsMargins(-1, 2, -1, 2);
        oscillator1Label_3 = new QLabel(oscillator1Frame_3);
        oscillator1Label_3->setObjectName(QStringLiteral("oscillator1Label_3"));
        oscillator1Label_3->setMaximumSize(QSize(16777215, 14));
        oscillator1Label_3->setFont(font1);

        verticalLayout_20->addWidget(oscillator1Label_3, 0, Qt::AlignHCenter);

        oscillator1HLayout_3 = new QHBoxLayout();
        oscillator1HLayout_3->setSpacing(6);
        oscillator1HLayout_3->setObjectName(QStringLiteral("oscillator1HLayout_3"));
        oscillator1WaveVLayout_3 = new QVBoxLayout();
        oscillator1WaveVLayout_3->setSpacing(6);
        oscillator1WaveVLayout_3->setObjectName(QStringLiteral("oscillator1WaveVLayout_3"));
        waveform1Label_3 = new QLabel(oscillator1Frame_3);
        waveform1Label_3->setObjectName(QStringLiteral("waveform1Label_3"));
        sizePolicy10.setHeightForWidth(waveform1Label_3->sizePolicy().hasHeightForWidth());
        waveform1Label_3->setSizePolicy(sizePolicy10);
        waveform1Label_3->setMaximumSize(QSize(16777215, 10));

        oscillator1WaveVLayout_3->addWidget(waveform1Label_3);

        waveform1ComboBox_3 = new QComboBox(oscillator1Frame_3);
        waveform1ComboBox_3->setObjectName(QStringLiteral("waveform1ComboBox_3"));
        sizePolicy1.setHeightForWidth(waveform1ComboBox_3->sizePolicy().hasHeightForWidth());
        waveform1ComboBox_3->setSizePolicy(sizePolicy1);
        waveform1ComboBox_3->setMaximumSize(QSize(16777215, 15));
        waveform1ComboBox_3->setAutoFillBackground(true);
        waveform1ComboBox_3->setFrame(false);

        oscillator1WaveVLayout_3->addWidget(waveform1ComboBox_3);


        oscillator1HLayout_3->addLayout(oscillator1WaveVLayout_3);

        oscillator1LevelHLayout_3 = new QHBoxLayout();
        oscillator1LevelHLayout_3->setSpacing(6);
        oscillator1LevelHLayout_3->setObjectName(QStringLiteral("oscillator1LevelHLayout_3"));
        level1Label_3 = new QLabel(oscillator1Frame_3);
        level1Label_3->setObjectName(QStringLiteral("level1Label_3"));
        sizePolicy1.setHeightForWidth(level1Label_3->sizePolicy().hasHeightForWidth());
        level1Label_3->setSizePolicy(sizePolicy1);
        level1Label_3->setMaximumSize(QSize(16777215, 11));

        oscillator1LevelHLayout_3->addWidget(level1Label_3);

        level1Dial_3 = new QDial(oscillator1Frame_3);
        level1Dial_3->setObjectName(QStringLiteral("level1Dial_3"));
        sizePolicy1.setHeightForWidth(level1Dial_3->sizePolicy().hasHeightForWidth());
        level1Dial_3->setSizePolicy(sizePolicy1);
        level1Dial_3->setMaximumSize(QSize(57, 16777215));

        oscillator1LevelHLayout_3->addWidget(level1Dial_3);


        oscillator1HLayout_3->addLayout(oscillator1LevelHLayout_3);


        verticalLayout_20->addLayout(oscillator1HLayout_3);


        framesVLayout_3->addWidget(oscillator1Frame_3);

        oscillator2Frame_3 = new QFrame(samplingInstrumentFrame);
        oscillator2Frame_3->setObjectName(QStringLiteral("oscillator2Frame_3"));
        sizePolicy10.setHeightForWidth(oscillator2Frame_3->sizePolicy().hasHeightForWidth());
        oscillator2Frame_3->setSizePolicy(sizePolicy10);
        oscillator2Frame_3->setFrameShape(QFrame::Panel);
        oscillator2Frame_3->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_3->setLineWidth(2);
        verticalLayout_21 = new QVBoxLayout(oscillator2Frame_3);
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setContentsMargins(11, 11, 11, 11);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(-1, 2, -1, 2);
        oscillator2Label_3 = new QLabel(oscillator2Frame_3);
        oscillator2Label_3->setObjectName(QStringLiteral("oscillator2Label_3"));
        oscillator2Label_3->setMaximumSize(QSize(16777215, 14));
        oscillator2Label_3->setFont(font1);

        verticalLayout_21->addWidget(oscillator2Label_3, 0, Qt::AlignHCenter);

        oscillator2HLayout_3 = new QHBoxLayout();
        oscillator2HLayout_3->setSpacing(6);
        oscillator2HLayout_3->setObjectName(QStringLiteral("oscillator2HLayout_3"));
        waveform2VLayout_3 = new QVBoxLayout();
        waveform2VLayout_3->setSpacing(6);
        waveform2VLayout_3->setObjectName(QStringLiteral("waveform2VLayout_3"));
        waveform2Label_3 = new QLabel(oscillator2Frame_3);
        waveform2Label_3->setObjectName(QStringLiteral("waveform2Label_3"));
        sizePolicy10.setHeightForWidth(waveform2Label_3->sizePolicy().hasHeightForWidth());
        waveform2Label_3->setSizePolicy(sizePolicy10);
        waveform2Label_3->setMaximumSize(QSize(16777215, 10));

        waveform2VLayout_3->addWidget(waveform2Label_3);

        waveform2ComboBox_3 = new QComboBox(oscillator2Frame_3);
        waveform2ComboBox_3->setObjectName(QStringLiteral("waveform2ComboBox_3"));
        sizePolicy1.setHeightForWidth(waveform2ComboBox_3->sizePolicy().hasHeightForWidth());
        waveform2ComboBox_3->setSizePolicy(sizePolicy1);
        waveform2ComboBox_3->setMaximumSize(QSize(16777215, 15));
        waveform2ComboBox_3->setAutoFillBackground(true);
        waveform2ComboBox_3->setFrame(false);

        waveform2VLayout_3->addWidget(waveform2ComboBox_3);


        oscillator2HLayout_3->addLayout(waveform2VLayout_3);

        oscillator2LevelHLayout_3 = new QHBoxLayout();
        oscillator2LevelHLayout_3->setSpacing(6);
        oscillator2LevelHLayout_3->setObjectName(QStringLiteral("oscillator2LevelHLayout_3"));
        level2Label_3 = new QLabel(oscillator2Frame_3);
        level2Label_3->setObjectName(QStringLiteral("level2Label_3"));
        sizePolicy1.setHeightForWidth(level2Label_3->sizePolicy().hasHeightForWidth());
        level2Label_3->setSizePolicy(sizePolicy1);
        level2Label_3->setMaximumSize(QSize(16777215, 11));

        oscillator2LevelHLayout_3->addWidget(level2Label_3);

        level2Dial_3 = new QDial(oscillator2Frame_3);
        level2Dial_3->setObjectName(QStringLiteral("level2Dial_3"));
        sizePolicy1.setHeightForWidth(level2Dial_3->sizePolicy().hasHeightForWidth());
        level2Dial_3->setSizePolicy(sizePolicy1);
        level2Dial_3->setMaximumSize(QSize(57, 16777215));

        oscillator2LevelHLayout_3->addWidget(level2Dial_3);


        oscillator2HLayout_3->addLayout(oscillator2LevelHLayout_3);


        verticalLayout_21->addLayout(oscillator2HLayout_3);


        framesVLayout_3->addWidget(oscillator2Frame_3);

        line_7 = new QFrame(samplingInstrumentFrame);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        framesVLayout_3->addWidget(line_7);

        envelopeParamsFrame_3 = new QFrame(samplingInstrumentFrame);
        envelopeParamsFrame_3->setObjectName(QStringLiteral("envelopeParamsFrame_3"));
        sizePolicy8.setHeightForWidth(envelopeParamsFrame_3->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame_3->setSizePolicy(sizePolicy8);
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
        attackVLayout_3 = new QVBoxLayout();
        attackVLayout_3->setSpacing(6);
        attackVLayout_3->setObjectName(QStringLiteral("attackVLayout_3"));
        attackDial_3 = new QDial(envelopeParamsFrame_3);
        attackDial_3->setObjectName(QStringLiteral("attackDial_3"));
        sizePolicy8.setHeightForWidth(attackDial_3->sizePolicy().hasHeightForWidth());
        attackDial_3->setSizePolicy(sizePolicy8);
        attackDial_3->setMaximumSize(QSize(60, 60));

        attackVLayout_3->addWidget(attackDial_3);

        attackLabel_3 = new QLabel(envelopeParamsFrame_3);
        attackLabel_3->setObjectName(QStringLiteral("attackLabel_3"));
        sizePolicy8.setHeightForWidth(attackLabel_3->sizePolicy().hasHeightForWidth());
        attackLabel_3->setSizePolicy(sizePolicy8);

        attackVLayout_3->addWidget(attackLabel_3, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_3->addLayout(attackVLayout_3);

        decayVLayout_3 = new QVBoxLayout();
        decayVLayout_3->setSpacing(6);
        decayVLayout_3->setObjectName(QStringLiteral("decayVLayout_3"));
        decayDial_3 = new QDial(envelopeParamsFrame_3);
        decayDial_3->setObjectName(QStringLiteral("decayDial_3"));
        sizePolicy8.setHeightForWidth(decayDial_3->sizePolicy().hasHeightForWidth());
        decayDial_3->setSizePolicy(sizePolicy8);
        decayDial_3->setMaximumSize(QSize(60, 16777215));

        decayVLayout_3->addWidget(decayDial_3);

        decayLabel_3 = new QLabel(envelopeParamsFrame_3);
        decayLabel_3->setObjectName(QStringLiteral("decayLabel_3"));
        sizePolicy8.setHeightForWidth(decayLabel_3->sizePolicy().hasHeightForWidth());
        decayLabel_3->setSizePolicy(sizePolicy8);

        decayVLayout_3->addWidget(decayLabel_3, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_3->addLayout(decayVLayout_3);

        sustainVLayout_3 = new QVBoxLayout();
        sustainVLayout_3->setSpacing(6);
        sustainVLayout_3->setObjectName(QStringLiteral("sustainVLayout_3"));
        sustainDial_3 = new QDial(envelopeParamsFrame_3);
        sustainDial_3->setObjectName(QStringLiteral("sustainDial_3"));
        sizePolicy8.setHeightForWidth(sustainDial_3->sizePolicy().hasHeightForWidth());
        sustainDial_3->setSizePolicy(sizePolicy8);
        sustainDial_3->setMaximumSize(QSize(60, 16777215));

        sustainVLayout_3->addWidget(sustainDial_3);

        sustainLabel_3 = new QLabel(envelopeParamsFrame_3);
        sustainLabel_3->setObjectName(QStringLiteral("sustainLabel_3"));
        sizePolicy8.setHeightForWidth(sustainLabel_3->sizePolicy().hasHeightForWidth());
        sustainLabel_3->setSizePolicy(sizePolicy8);

        sustainVLayout_3->addWidget(sustainLabel_3, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_3->addLayout(sustainVLayout_3);

        releaseVLayout_3 = new QVBoxLayout();
        releaseVLayout_3->setSpacing(6);
        releaseVLayout_3->setObjectName(QStringLiteral("releaseVLayout_3"));
        releaseDial_3 = new QDial(envelopeParamsFrame_3);
        releaseDial_3->setObjectName(QStringLiteral("releaseDial_3"));
        sizePolicy8.setHeightForWidth(releaseDial_3->sizePolicy().hasHeightForWidth());
        releaseDial_3->setSizePolicy(sizePolicy8);
        releaseDial_3->setMaximumSize(QSize(60, 16777215));

        releaseVLayout_3->addWidget(releaseDial_3);

        releaseLabel_3 = new QLabel(envelopeParamsFrame_3);
        releaseLabel_3->setObjectName(QStringLiteral("releaseLabel_3"));
        sizePolicy8.setHeightForWidth(releaseLabel_3->sizePolicy().hasHeightForWidth());
        releaseLabel_3->setSizePolicy(sizePolicy8);

        releaseVLayout_3->addWidget(releaseLabel_3, 0, Qt::AlignHCenter);


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
        palette8.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush6);
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
        deleteInstrumentButton_2 = new QPushButton(karplusInstrumentFrame);
        deleteInstrumentButton_2->setObjectName(QStringLiteral("deleteInstrumentButton_2"));
        sizePolicy9.setHeightForWidth(deleteInstrumentButton_2->sizePolicy().hasHeightForWidth());
        deleteInstrumentButton_2->setSizePolicy(sizePolicy9);
        deleteInstrumentButton_2->setFocusPolicy(Qt::StrongFocus);
        deleteInstrumentButton_2->setIcon(icon);
        deleteInstrumentButton_2->setIconSize(QSize(15, 15));
        deleteInstrumentButton_2->setFlat(true);

        nameHLayout_2->addWidget(deleteInstrumentButton_2);

        instrumentNameLabel_2 = new QLabel(karplusInstrumentFrame);
        instrumentNameLabel_2->setObjectName(QStringLiteral("instrumentNameLabel_2"));
        sizePolicy10.setHeightForWidth(instrumentNameLabel_2->sizePolicy().hasHeightForWidth());
        instrumentNameLabel_2->setSizePolicy(sizePolicy10);
        instrumentNameLabel_2->setFont(font4);

        nameHLayout_2->addWidget(instrumentNameLabel_2);


        gridLayout_5->addLayout(nameHLayout_2, 0, 0, 1, 1);

        line_4 = new QFrame(karplusInstrumentFrame);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout_5->addWidget(line_4, 1, 0, 1, 1);

        framesVLayout_2 = new QVBoxLayout();
        framesVLayout_2->setSpacing(6);
        framesVLayout_2->setObjectName(QStringLiteral("framesVLayout_2"));
        oscillator1Frame_2 = new QFrame(karplusInstrumentFrame);
        oscillator1Frame_2->setObjectName(QStringLiteral("oscillator1Frame_2"));
        oscillator1Frame_2->setFrameShape(QFrame::Panel);
        oscillator1Frame_2->setFrameShadow(QFrame::Sunken);
        oscillator1Frame_2->setLineWidth(2);
        verticalLayout_17 = new QVBoxLayout(oscillator1Frame_2);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(-1, 2, -1, 2);
        oscillator1Label_2 = new QLabel(oscillator1Frame_2);
        oscillator1Label_2->setObjectName(QStringLiteral("oscillator1Label_2"));
        oscillator1Label_2->setMaximumSize(QSize(16777215, 14));
        oscillator1Label_2->setFont(font1);

        verticalLayout_17->addWidget(oscillator1Label_2, 0, Qt::AlignHCenter);

        oscillator1HLayout_2 = new QHBoxLayout();
        oscillator1HLayout_2->setSpacing(6);
        oscillator1HLayout_2->setObjectName(QStringLiteral("oscillator1HLayout_2"));
        oscillator1WaveVLayout_2 = new QVBoxLayout();
        oscillator1WaveVLayout_2->setSpacing(6);
        oscillator1WaveVLayout_2->setObjectName(QStringLiteral("oscillator1WaveVLayout_2"));
        waveform1Label_2 = new QLabel(oscillator1Frame_2);
        waveform1Label_2->setObjectName(QStringLiteral("waveform1Label_2"));
        sizePolicy10.setHeightForWidth(waveform1Label_2->sizePolicy().hasHeightForWidth());
        waveform1Label_2->setSizePolicy(sizePolicy10);
        waveform1Label_2->setMaximumSize(QSize(16777215, 10));

        oscillator1WaveVLayout_2->addWidget(waveform1Label_2);

        waveform1ComboBox_2 = new QComboBox(oscillator1Frame_2);
        waveform1ComboBox_2->setObjectName(QStringLiteral("waveform1ComboBox_2"));
        sizePolicy1.setHeightForWidth(waveform1ComboBox_2->sizePolicy().hasHeightForWidth());
        waveform1ComboBox_2->setSizePolicy(sizePolicy1);
        waveform1ComboBox_2->setMaximumSize(QSize(16777215, 15));
        waveform1ComboBox_2->setFrame(true);

        oscillator1WaveVLayout_2->addWidget(waveform1ComboBox_2);


        oscillator1HLayout_2->addLayout(oscillator1WaveVLayout_2);

        oscillator1LevelHLayout_2 = new QHBoxLayout();
        oscillator1LevelHLayout_2->setSpacing(6);
        oscillator1LevelHLayout_2->setObjectName(QStringLiteral("oscillator1LevelHLayout_2"));
        level1Label_2 = new QLabel(oscillator1Frame_2);
        level1Label_2->setObjectName(QStringLiteral("level1Label_2"));
        sizePolicy1.setHeightForWidth(level1Label_2->sizePolicy().hasHeightForWidth());
        level1Label_2->setSizePolicy(sizePolicy1);
        level1Label_2->setMaximumSize(QSize(16777215, 11));

        oscillator1LevelHLayout_2->addWidget(level1Label_2);

        level1Dial_2 = new QDial(oscillator1Frame_2);
        level1Dial_2->setObjectName(QStringLiteral("level1Dial_2"));
        sizePolicy1.setHeightForWidth(level1Dial_2->sizePolicy().hasHeightForWidth());
        level1Dial_2->setSizePolicy(sizePolicy1);
        level1Dial_2->setMaximumSize(QSize(57, 16777215));

        oscillator1LevelHLayout_2->addWidget(level1Dial_2);


        oscillator1HLayout_2->addLayout(oscillator1LevelHLayout_2);


        verticalLayout_17->addLayout(oscillator1HLayout_2);


        framesVLayout_2->addWidget(oscillator1Frame_2);

        oscillator2Frame_2 = new QFrame(karplusInstrumentFrame);
        oscillator2Frame_2->setObjectName(QStringLiteral("oscillator2Frame_2"));
        sizePolicy10.setHeightForWidth(oscillator2Frame_2->sizePolicy().hasHeightForWidth());
        oscillator2Frame_2->setSizePolicy(sizePolicy10);
        oscillator2Frame_2->setFrameShape(QFrame::Panel);
        oscillator2Frame_2->setFrameShadow(QFrame::Sunken);
        oscillator2Frame_2->setLineWidth(2);
        verticalLayout_18 = new QVBoxLayout(oscillator2Frame_2);
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setContentsMargins(11, 11, 11, 11);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(-1, 2, -1, 2);
        oscillator2Label_2 = new QLabel(oscillator2Frame_2);
        oscillator2Label_2->setObjectName(QStringLiteral("oscillator2Label_2"));
        oscillator2Label_2->setMaximumSize(QSize(16777215, 14));
        oscillator2Label_2->setFont(font1);

        verticalLayout_18->addWidget(oscillator2Label_2, 0, Qt::AlignHCenter);

        oscillator2HLayout_2 = new QHBoxLayout();
        oscillator2HLayout_2->setSpacing(6);
        oscillator2HLayout_2->setObjectName(QStringLiteral("oscillator2HLayout_2"));
        waveform2VLayout_2 = new QVBoxLayout();
        waveform2VLayout_2->setSpacing(6);
        waveform2VLayout_2->setObjectName(QStringLiteral("waveform2VLayout_2"));
        waveform2Label_2 = new QLabel(oscillator2Frame_2);
        waveform2Label_2->setObjectName(QStringLiteral("waveform2Label_2"));
        sizePolicy10.setHeightForWidth(waveform2Label_2->sizePolicy().hasHeightForWidth());
        waveform2Label_2->setSizePolicy(sizePolicy10);
        waveform2Label_2->setMaximumSize(QSize(16777215, 10));

        waveform2VLayout_2->addWidget(waveform2Label_2);

        waveform2ComboBox_2 = new QComboBox(oscillator2Frame_2);
        waveform2ComboBox_2->setObjectName(QStringLiteral("waveform2ComboBox_2"));
        sizePolicy1.setHeightForWidth(waveform2ComboBox_2->sizePolicy().hasHeightForWidth());
        waveform2ComboBox_2->setSizePolicy(sizePolicy1);
        waveform2ComboBox_2->setMaximumSize(QSize(16777215, 15));
        waveform2ComboBox_2->setFrame(true);

        waveform2VLayout_2->addWidget(waveform2ComboBox_2);


        oscillator2HLayout_2->addLayout(waveform2VLayout_2);

        oscillator2LevelHLayout_2 = new QHBoxLayout();
        oscillator2LevelHLayout_2->setSpacing(6);
        oscillator2LevelHLayout_2->setObjectName(QStringLiteral("oscillator2LevelHLayout_2"));
        level2Label_2 = new QLabel(oscillator2Frame_2);
        level2Label_2->setObjectName(QStringLiteral("level2Label_2"));
        sizePolicy1.setHeightForWidth(level2Label_2->sizePolicy().hasHeightForWidth());
        level2Label_2->setSizePolicy(sizePolicy1);
        level2Label_2->setMaximumSize(QSize(16777215, 11));

        oscillator2LevelHLayout_2->addWidget(level2Label_2);

        level2Dial_2 = new QDial(oscillator2Frame_2);
        level2Dial_2->setObjectName(QStringLiteral("level2Dial_2"));
        sizePolicy1.setHeightForWidth(level2Dial_2->sizePolicy().hasHeightForWidth());
        level2Dial_2->setSizePolicy(sizePolicy1);
        level2Dial_2->setMaximumSize(QSize(57, 16777215));

        oscillator2LevelHLayout_2->addWidget(level2Dial_2);


        oscillator2HLayout_2->addLayout(oscillator2LevelHLayout_2);


        verticalLayout_18->addLayout(oscillator2HLayout_2);


        framesVLayout_2->addWidget(oscillator2Frame_2);

        line_5 = new QFrame(karplusInstrumentFrame);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        framesVLayout_2->addWidget(line_5);

        envelopeParamsFrame_2 = new QFrame(karplusInstrumentFrame);
        envelopeParamsFrame_2->setObjectName(QStringLiteral("envelopeParamsFrame_2"));
        sizePolicy8.setHeightForWidth(envelopeParamsFrame_2->sizePolicy().hasHeightForWidth());
        envelopeParamsFrame_2->setSizePolicy(sizePolicy8);
        envelopeParamsFrame_2->setFrameShape(QFrame::Panel);
        envelopeParamsFrame_2->setFrameShadow(QFrame::Sunken);
        envelopeParamsFrame_2->setLineWidth(2);
        verticalLayout_19 = new QVBoxLayout(envelopeParamsFrame_2);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(-1, 2, -1, 2);
        envelopeParamsLabel_2 = new QLabel(envelopeParamsFrame_2);
        envelopeParamsLabel_2->setObjectName(QStringLiteral("envelopeParamsLabel_2"));
        envelopeParamsLabel_2->setMaximumSize(QSize(16777215, 14));
        envelopeParamsLabel_2->setFont(font1);

        verticalLayout_19->addWidget(envelopeParamsLabel_2, 0, Qt::AlignHCenter);

        envelopeParamsHLayout_2 = new QHBoxLayout();
        envelopeParamsHLayout_2->setSpacing(6);
        envelopeParamsHLayout_2->setObjectName(QStringLiteral("envelopeParamsHLayout_2"));
        attackVLayout_2 = new QVBoxLayout();
        attackVLayout_2->setSpacing(6);
        attackVLayout_2->setObjectName(QStringLiteral("attackVLayout_2"));
        attackDial_2 = new QDial(envelopeParamsFrame_2);
        attackDial_2->setObjectName(QStringLiteral("attackDial_2"));
        sizePolicy8.setHeightForWidth(attackDial_2->sizePolicy().hasHeightForWidth());
        attackDial_2->setSizePolicy(sizePolicy8);
        attackDial_2->setMaximumSize(QSize(60, 60));

        attackVLayout_2->addWidget(attackDial_2);

        attackLabel_2 = new QLabel(envelopeParamsFrame_2);
        attackLabel_2->setObjectName(QStringLiteral("attackLabel_2"));
        sizePolicy8.setHeightForWidth(attackLabel_2->sizePolicy().hasHeightForWidth());
        attackLabel_2->setSizePolicy(sizePolicy8);

        attackVLayout_2->addWidget(attackLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(attackVLayout_2);

        decayVLayout_2 = new QVBoxLayout();
        decayVLayout_2->setSpacing(6);
        decayVLayout_2->setObjectName(QStringLiteral("decayVLayout_2"));
        decayDial_2 = new QDial(envelopeParamsFrame_2);
        decayDial_2->setObjectName(QStringLiteral("decayDial_2"));
        sizePolicy8.setHeightForWidth(decayDial_2->sizePolicy().hasHeightForWidth());
        decayDial_2->setSizePolicy(sizePolicy8);
        decayDial_2->setMaximumSize(QSize(60, 16777215));

        decayVLayout_2->addWidget(decayDial_2);

        decayLabel_2 = new QLabel(envelopeParamsFrame_2);
        decayLabel_2->setObjectName(QStringLiteral("decayLabel_2"));
        sizePolicy8.setHeightForWidth(decayLabel_2->sizePolicy().hasHeightForWidth());
        decayLabel_2->setSizePolicy(sizePolicy8);

        decayVLayout_2->addWidget(decayLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(decayVLayout_2);

        sustainVLayout_2 = new QVBoxLayout();
        sustainVLayout_2->setSpacing(6);
        sustainVLayout_2->setObjectName(QStringLiteral("sustainVLayout_2"));
        sustainDial_2 = new QDial(envelopeParamsFrame_2);
        sustainDial_2->setObjectName(QStringLiteral("sustainDial_2"));
        sizePolicy8.setHeightForWidth(sustainDial_2->sizePolicy().hasHeightForWidth());
        sustainDial_2->setSizePolicy(sizePolicy8);
        sustainDial_2->setMaximumSize(QSize(60, 16777215));

        sustainVLayout_2->addWidget(sustainDial_2);

        sustainLabel_2 = new QLabel(envelopeParamsFrame_2);
        sustainLabel_2->setObjectName(QStringLiteral("sustainLabel_2"));
        sizePolicy8.setHeightForWidth(sustainLabel_2->sizePolicy().hasHeightForWidth());
        sustainLabel_2->setSizePolicy(sizePolicy8);

        sustainVLayout_2->addWidget(sustainLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(sustainVLayout_2);

        releaseVLayout_2 = new QVBoxLayout();
        releaseVLayout_2->setSpacing(6);
        releaseVLayout_2->setObjectName(QStringLiteral("releaseVLayout_2"));
        releaseDial_2 = new QDial(envelopeParamsFrame_2);
        releaseDial_2->setObjectName(QStringLiteral("releaseDial_2"));
        sizePolicy8.setHeightForWidth(releaseDial_2->sizePolicy().hasHeightForWidth());
        releaseDial_2->setSizePolicy(sizePolicy8);
        releaseDial_2->setMaximumSize(QSize(60, 16777215));

        releaseVLayout_2->addWidget(releaseDial_2);

        releaseLabel_2 = new QLabel(envelopeParamsFrame_2);
        releaseLabel_2->setObjectName(QStringLiteral("releaseLabel_2"));
        sizePolicy8.setHeightForWidth(releaseLabel_2->sizePolicy().hasHeightForWidth());
        releaseLabel_2->setSizePolicy(sizePolicy8);

        releaseVLayout_2->addWidget(releaseLabel_2, 0, Qt::AlignHCenter);


        envelopeParamsHLayout_2->addLayout(releaseVLayout_2);


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
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush13(QColor(73, 73, 73, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush13);
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
        effectsScrollAreaContents->setGeometry(QRect(0, 0, 818, 376));
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
        frameEffect1 = new QFrame(effectsScrollAreaContents);
        frameEffect1->setObjectName(QStringLiteral("frameEffect1"));
        frameEffect1->setMaximumSize(QSize(250, 16777215));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        frameEffect1->setPalette(palette10);
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        frameEffect1->setFont(font5);
        frameEffect1->setAutoFillBackground(true);
        frameEffect1->setFrameShape(QFrame::Panel);
        frameEffect1->setFrameShadow(QFrame::Raised);
        frameEffect1->setLineWidth(2);
        frameEffect1->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(frameEffect1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(9, 6, 9, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(frameEffect1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy9.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy9);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(15, 15));
        pushButton_2->setFlat(true);

        horizontalLayout->addWidget(pushButton_2);

        label = new QLabel(frameEffect1);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font4);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(frameEffect1);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy9.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy9);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/006-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(15, 15));
        pushButton_4->setFlat(true);

        horizontalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(frameEffect1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy9.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy9);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/033-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(15, 15));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        line_3 = new QFrame(frameEffect1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        dial = new QDial(frameEffect1);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setMaximumSize(QSize(50, 50));

        verticalLayout_4->addWidget(dial, 0, Qt::AlignHCenter);

        label_4 = new QLabel(frameEffect1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignHCenter);


        gridLayout_4->addLayout(verticalLayout_4, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        effectsHorizontalLayout->addWidget(frameEffect1);

        groupBox_6 = new QGroupBox(effectsScrollAreaContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));

        effectsHorizontalLayout->addWidget(groupBox_6);


        effectsScrollAreaLayout->addLayout(effectsHorizontalLayout);


        horizontalLayout_9->addLayout(effectsScrollAreaLayout);

        effectsScrollArea->setWidget(effectsScrollAreaContents);

        activeChannelAssetsPanel->addWidget(effectsScrollArea);


        verticalLayout_6->addLayout(activeChannelAssetsPanel);


        gridLayout->addLayout(verticalLayout_6, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        importButton = new QPushButton(centralWidget);
        importButton->setObjectName(QStringLiteral("importButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/003-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        importButton->setIcon(icon3);
        importButton->setIconSize(QSize(18, 18));
        importButton->setFlat(true);

        horizontalLayout_10->addWidget(importButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        playButton_2 = new QPushButton(centralWidget);
        playButton_2->setObjectName(QStringLiteral("playButton_2"));
        sizePolicy9.setHeightForWidth(playButton_2->sizePolicy().hasHeightForWidth());
        playButton_2->setSizePolicy(sizePolicy9);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playButton_2->setIcon(icon4);
        playButton_2->setFlat(true);

        horizontalLayout_10->addWidget(playButton_2);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon5);
        pauseButton->setAutoDefault(false);
        pauseButton->setFlat(true);

        horizontalLayout_10->addWidget(pauseButton);

        stopButton_2 = new QPushButton(centralWidget);
        stopButton_2->setObjectName(QStringLiteral("stopButton_2"));
        sizePolicy9.setHeightForWidth(stopButton_2->sizePolicy().hasHeightForWidth());
        stopButton_2->setSizePolicy(sizePolicy9);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton_2->setIcon(icon6);
        stopButton_2->setFlat(true);

        horizontalLayout_10->addWidget(stopButton_2);

        recordButton_2 = new QPushButton(centralWidget);
        recordButton_2->setObjectName(QStringLiteral("recordButton_2"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/rec.svg"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton_2->setIcon(icon7);
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

        pushButton_4->setDefault(false);


        QMetaObject::connectSlotsByName(LeandroClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeandroClass)
    {
        LeandroClass->setWindowTitle(QApplication::translate("LeandroClass", "Leandro", Q_NULLPTR));
        label_7->setText(QApplication::translate("LeandroClass", "Instruments", Q_NULLPTR));
        addChannelButton->setText(QApplication::translate("LeandroClass", "Add to Channel", Q_NULLPTR));
        label_8->setText(QApplication::translate("LeandroClass", "Effects", Q_NULLPTR));
        setInstrumentButton->setText(QApplication::translate("LeandroClass", "Set for Channel", Q_NULLPTR));
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
        deleteInstrumentButton->setText(QString());
        instrumentNameLabel->setText(QApplication::translate("LeandroClass", "ADSR Instrument", Q_NULLPTR));
        oscillator1Label->setText(QApplication::translate("LeandroClass", "Oscillator 1", Q_NULLPTR));
        waveform1Label->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform1ComboBox->clear();
        waveform1ComboBox->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level1Label->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        oscillator2Label->setText(QApplication::translate("LeandroClass", "Oscillator 2", Q_NULLPTR));
        waveform2Label->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform2ComboBox->clear();
        waveform2ComboBox->insertItems(0, QStringList()
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
        deleteInstrumentButton_4->setText(QString());
        instrumentNameLabel_4->setText(QApplication::translate("LeandroClass", "Additive Instrument", Q_NULLPTR));
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
        envelopeParamsLabel_4->setText(QApplication::translate("LeandroClass", "Envelope Parameters", Q_NULLPTR));
        attackLabel_4->setText(QApplication::translate("LeandroClass", "Attack", Q_NULLPTR));
        decayLabel_4->setText(QApplication::translate("LeandroClass", "Decay", Q_NULLPTR));
        sustainLabel_4->setText(QApplication::translate("LeandroClass", "Sustain Level", Q_NULLPTR));
        sustainRateLabel_2->setText(QApplication::translate("LeandroClass", "Sustain Rate", Q_NULLPTR));
        releaseLabel_4->setText(QApplication::translate("LeandroClass", "Release", Q_NULLPTR));
        deleteInstrumentButton_3->setText(QString());
        instrumentNameLabel_3->setText(QApplication::translate("LeandroClass", "el adsr del mati", Q_NULLPTR));
        oscillator1Label_3->setText(QApplication::translate("LeandroClass", "Oscillator 1", Q_NULLPTR));
        waveform1Label_3->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform1ComboBox_3->clear();
        waveform1ComboBox_3->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level1Label_3->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        oscillator2Label_3->setText(QApplication::translate("LeandroClass", "Oscillator 2", Q_NULLPTR));
        waveform2Label_3->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform2ComboBox_3->clear();
        waveform2ComboBox_3->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level2Label_3->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        envelopeParamsLabel_3->setText(QApplication::translate("LeandroClass", "Envelope Parameters", Q_NULLPTR));
        attackLabel_3->setText(QApplication::translate("LeandroClass", "Attack", Q_NULLPTR));
        decayLabel_3->setText(QApplication::translate("LeandroClass", "Decay", Q_NULLPTR));
        sustainLabel_3->setText(QApplication::translate("LeandroClass", "Sustain", Q_NULLPTR));
        releaseLabel_3->setText(QApplication::translate("LeandroClass", "Release", Q_NULLPTR));
        deleteInstrumentButton_2->setText(QString());
        instrumentNameLabel_2->setText(QApplication::translate("LeandroClass", "el adsr del mati", Q_NULLPTR));
        oscillator1Label_2->setText(QApplication::translate("LeandroClass", "Oscillator 1", Q_NULLPTR));
        waveform1Label_2->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform1ComboBox_2->clear();
        waveform1ComboBox_2->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level1Label_2->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        oscillator2Label_2->setText(QApplication::translate("LeandroClass", "Oscillator 2", Q_NULLPTR));
        waveform2Label_2->setText(QApplication::translate("LeandroClass", "Waveform", Q_NULLPTR));
        waveform2ComboBox_2->clear();
        waveform2ComboBox_2->insertItems(0, QStringList()
         << QApplication::translate("LeandroClass", "Sine", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Square", Q_NULLPTR)
         << QApplication::translate("LeandroClass", "Sawtooth", Q_NULLPTR)
        );
        level2Label_2->setText(QApplication::translate("LeandroClass", "Level", Q_NULLPTR));
        envelopeParamsLabel_2->setText(QApplication::translate("LeandroClass", "Envelope Parameters", Q_NULLPTR));
        attackLabel_2->setText(QApplication::translate("LeandroClass", "Attack", Q_NULLPTR));
        decayLabel_2->setText(QApplication::translate("LeandroClass", "Decay", Q_NULLPTR));
        sustainLabel_2->setText(QApplication::translate("LeandroClass", "Sustain", Q_NULLPTR));
        releaseLabel_2->setText(QApplication::translate("LeandroClass", "Release", Q_NULLPTR));
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("LeandroClass", "Effect 1", Q_NULLPTR));
        pushButton_4->setText(QString());
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("LeandroClass", "Setting 1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("LeandroClass", "Effect 2", Q_NULLPTR));
        importButton->setText(QString());
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
