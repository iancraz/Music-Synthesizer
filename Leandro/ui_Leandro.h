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
    QHBoxLayout *horizontalLayout_10;
    QPushButton *importButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *playButton_2;
    QPushButton *pauseButton;
    QPushButton *stopButton_2;
    QPushButton *recordButton_2;
    QSpacerItem *horizontalSpacer_4;
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
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *activeChannelAssetsPanel;
    QFrame *frame_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *instrumentLayoutLayout;
    QHBoxLayout *instrumentLayout;
    QFrame *frameInstrument;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_9;
    QDial *dial_5;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_10;
    QDial *dial_6;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_11;
    QDial *dial_7;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_12;
    QDial *dial_8;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QFrame *line_2;
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
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeandroClass)
    {
        if (LeandroClass->objectName().isEmpty())
            LeandroClass->setObjectName(QStringLiteral("LeandroClass"));
        LeandroClass->resize(851, 808);
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
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        importButton = new QPushButton(centralWidget);
        importButton->setObjectName(QStringLiteral("importButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/003-plus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        importButton->setIcon(icon);
        importButton->setIconSize(QSize(18, 18));
        importButton->setFlat(true);

        horizontalLayout_10->addWidget(importButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        playButton_2 = new QPushButton(centralWidget);
        playButton_2->setObjectName(QStringLiteral("playButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playButton_2->sizePolicy().hasHeightForWidth());
        playButton_2->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/icons/play.svg"), QSize(), QIcon::Normal, QIcon::Off);
        playButton_2->setIcon(icon1);
        playButton_2->setFlat(true);

        horizontalLayout_10->addWidget(playButton_2);

        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/icons/pause.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pauseButton->setIcon(icon2);
        pauseButton->setAutoDefault(false);
        pauseButton->setFlat(true);

        horizontalLayout_10->addWidget(pauseButton);

        stopButton_2 = new QPushButton(centralWidget);
        stopButton_2->setObjectName(QStringLiteral("stopButton_2"));
        sizePolicy.setHeightForWidth(stopButton_2->sizePolicy().hasHeightForWidth());
        stopButton_2->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/icons/stop.svg"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton_2->setIcon(icon3);
        stopButton_2->setFlat(true);

        horizontalLayout_10->addWidget(stopButton_2);

        recordButton_2 = new QPushButton(centralWidget);
        recordButton_2->setObjectName(QStringLiteral("recordButton_2"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/icons/rec.svg"), QSize(), QIcon::Normal, QIcon::Off);
        recordButton_2->setIcon(icon4);
        recordButton_2->setFlat(true);

        horizontalLayout_10->addWidget(recordButton_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_10, 0, 0, 1, 1);

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
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(instrumentsList->sizePolicy().hasHeightForWidth());
        instrumentsList->setSizePolicy(sizePolicy1);
        instrumentsList->setMaximumSize(QSize(100, 16777215));
        instrumentsList->setDragEnabled(false);
        instrumentsList->setDragDropMode(QAbstractItemView::DragOnly);

        verticalLayout_2->addWidget(instrumentsList);

        addChannelButton = new QPushButton(frame_3);
        addChannelButton->setObjectName(QStringLiteral("addChannelButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addChannelButton->sizePolicy().hasHeightForWidth());
        addChannelButton->setSizePolicy(sizePolicy2);
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
        sizePolicy1.setHeightForWidth(effectsList->sizePolicy().hasHeightForWidth());
        effectsList->setSizePolicy(sizePolicy1);
        effectsList->setMinimumSize(QSize(0, 0));
        effectsList->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(effectsList);

        setInstrumentButton = new QPushButton(frame_3);
        setInstrumentButton->setObjectName(QStringLiteral("setInstrumentButton"));
        sizePolicy2.setHeightForWidth(setInstrumentButton->sizePolicy().hasHeightForWidth());
        setInstrumentButton->setSizePolicy(sizePolicy2);
        setInstrumentButton->setMaximumSize(QSize(16777215, 15));
        setInstrumentButton->setBaseSize(QSize(0, 0));
        setInstrumentButton->setFont(font2);
        setInstrumentButton->setAutoFillBackground(true);
        setInstrumentButton->setFlat(true);

        verticalLayout_2->addWidget(setInstrumentButton, 0, Qt::AlignHCenter);


        horizontalLayout_5->addWidget(frame_3, 0, Qt::AlignHCenter);

        scrollAreaChannels_2 = new QScrollArea(centralWidget);
        scrollAreaChannels_2->setObjectName(QStringLiteral("scrollAreaChannels_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaChannels_2->sizePolicy().hasHeightForWidth());
        scrollAreaChannels_2->setSizePolicy(sizePolicy3);
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
        scrollAreaChannelsWidgetContents_2->setGeometry(QRect(0, 0, 693, 437));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(scrollAreaChannelsWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaChannelsWidgetContents_2->setSizePolicy(sizePolicy4);
        channelsContainerLayout = new QHBoxLayout(scrollAreaChannelsWidgetContents_2);
        channelsContainerLayout->setSpacing(6);
        channelsContainerLayout->setContentsMargins(11, 11, 11, 11);
        channelsContainerLayout->setObjectName(QStringLiteral("channelsContainerLayout"));
        channelsContainerLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        frameChannel1 = new QFrame(scrollAreaChannelsWidgetContents_2);
        frameChannel1->setObjectName(QStringLiteral("frameChannel1"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(frameChannel1->sizePolicy().hasHeightForWidth());
        frameChannel1->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy6(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(closeButtonChannel1->sizePolicy().hasHeightForWidth());
        closeButtonChannel1->setSizePolicy(sizePolicy6);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/icons/037-minus.svg"), QSize(), QIcon::Normal, QIcon::Off);
        closeButtonChannel1->setIcon(icon5);
        closeButtonChannel1->setIconSize(QSize(12, 12));
        closeButtonChannel1->setFlat(true);

        channelTopLayout->addWidget(closeButtonChannel1);


        verticalLayoutFrameChannel1->addLayout(channelTopLayout);

        setActiveButtonChannel1_2 = new QPushButton(frameChannel1);
        setActiveButtonChannel1_2->setObjectName(QStringLiteral("setActiveButtonChannel1_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(setActiveButtonChannel1_2->sizePolicy().hasHeightForWidth());
        setActiveButtonChannel1_2->setSizePolicy(sizePolicy7);
        setActiveButtonChannel1_2->setMinimumSize(QSize(0, 17));
        setActiveButtonChannel1_2->setFont(font2);
        setActiveButtonChannel1_2->setAutoFillBackground(true);
        setActiveButtonChannel1_2->setFlat(true);

        verticalLayoutFrameChannel1->addWidget(setActiveButtonChannel1_2, 0, Qt::AlignHCenter);

        verticalSpacerChannel1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutFrameChannel1->addItem(verticalSpacerChannel1);

        inputComboBoxChannel1_2 = new QComboBox(frameChannel1);
        inputComboBoxChannel1_2->setObjectName(QStringLiteral("inputComboBoxChannel1_2"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(inputComboBoxChannel1_2->sizePolicy().hasHeightForWidth());
        inputComboBoxChannel1_2->setSizePolicy(sizePolicy8);
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
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(midiListChannel1_2->sizePolicy().hasHeightForWidth());
        midiListChannel1_2->setSizePolicy(sizePolicy9);
        midiListChannel1_2->setMaximumSize(QSize(100, 16777215));
        midiListChannel1_2->setFont(font);
        midiListChannel1_2->setFrameShape(QFrame::Panel);
        midiListChannel1_2->setLineWidth(2);

        verticalLayoutFrameChannel1->addWidget(midiListChannel1_2, 0, Qt::AlignHCenter);

        levelDialChannel1_2 = new QDial(frameChannel1);
        levelDialChannel1_2->setObjectName(QStringLiteral("levelDialChannel1_2"));
        sizePolicy9.setHeightForWidth(levelDialChannel1_2->sizePolicy().hasHeightForWidth());
        levelDialChannel1_2->setSizePolicy(sizePolicy9);

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

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        channelsContainerLayout->addItem(horizontalSpacer_3);

        scrollAreaChannels_2->setWidget(scrollAreaChannelsWidgetContents_2);

        horizontalLayout_5->addWidget(scrollAreaChannels_2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        activeChannelAssetsPanel = new QHBoxLayout();
        activeChannelAssetsPanel->setSpacing(6);
        activeChannelAssetsPanel->setObjectName(QStringLiteral("activeChannelAssetsPanel"));
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setMinimumSize(QSize(20, 0));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        frame_5->setPalette(palette4);
        frame_5->setAutoFillBackground(true);
        frame_5->setFrameShape(QFrame::Panel);
        frame_5->setFrameShadow(QFrame::Sunken);
        frame_5->setLineWidth(3);
        gridLayout_2 = new QGridLayout(frame_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        instrumentLayoutLayout = new QHBoxLayout();
        instrumentLayoutLayout->setSpacing(6);
        instrumentLayoutLayout->setObjectName(QStringLiteral("instrumentLayoutLayout"));
        instrumentLayout = new QHBoxLayout();
        instrumentLayout->setSpacing(6);
        instrumentLayout->setObjectName(QStringLiteral("instrumentLayout"));
        frameInstrument = new QFrame(frame_5);
        frameInstrument->setObjectName(QStringLiteral("frameInstrument"));
        frameInstrument->setMinimumSize(QSize(10, 0));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        frameInstrument->setPalette(palette5);
        frameInstrument->setAutoFillBackground(true);
        frameInstrument->setFrameShape(QFrame::Panel);
        frameInstrument->setFrameShadow(QFrame::Raised);
        frameInstrument->setLineWidth(2);
        gridLayout_3 = new QGridLayout(frameInstrument);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(12, 6, 12, 2);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        dial_5 = new QDial(frameInstrument);
        dial_5->setObjectName(QStringLiteral("dial_5"));
        dial_5->setInvertedAppearance(false);
        dial_5->setWrapping(false);

        verticalLayout_9->addWidget(dial_5);

        label_9 = new QLabel(frameInstrument);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_9->addWidget(label_9);


        gridLayout_5->addLayout(verticalLayout_9, 0, 2, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        dial_6 = new QDial(frameInstrument);
        dial_6->setObjectName(QStringLiteral("dial_6"));

        verticalLayout_10->addWidget(dial_6);

        label_10 = new QLabel(frameInstrument);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_10->addWidget(label_10);


        gridLayout_5->addLayout(verticalLayout_10, 0, 1, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        dial_7 = new QDial(frameInstrument);
        dial_7->setObjectName(QStringLiteral("dial_7"));
        sizePolicy4.setHeightForWidth(dial_7->sizePolicy().hasHeightForWidth());
        dial_7->setSizePolicy(sizePolicy4);
        dial_7->setMaximumSize(QSize(16777215, 16777215));
        dial_7->setWrapping(false);

        verticalLayout_11->addWidget(dial_7);

        label_11 = new QLabel(frameInstrument);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_11);


        gridLayout_5->addLayout(verticalLayout_11, 0, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        dial_8 = new QDial(frameInstrument);
        dial_8->setObjectName(QStringLiteral("dial_8"));

        verticalLayout_12->addWidget(dial_8);

        label_12 = new QLabel(frameInstrument);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_12->addWidget(label_12);


        gridLayout_5->addLayout(verticalLayout_12, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_6 = new QPushButton(frameInstrument);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFocusPolicy(Qt::StrongFocus);
        pushButton_6->setIcon(icon5);
        pushButton_6->setIconSize(QSize(15, 15));
        pushButton_6->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_6);

        label_2 = new QLabel(frameInstrument);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font4;
        font4.setFamily(QStringLiteral("Helvetica World"));
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(75);
        label_2->setFont(font4);

        horizontalLayout_4->addWidget(label_2);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        line_2 = new QFrame(frameInstrument);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 1, 0, 1, 1);


        instrumentLayout->addWidget(frameInstrument);


        instrumentLayoutLayout->addLayout(instrumentLayout);


        gridLayout_2->addLayout(instrumentLayoutLayout, 0, 0, 1, 1);


        activeChannelAssetsPanel->addWidget(frame_5);

        effectsScrollArea = new QScrollArea(centralWidget);
        effectsScrollArea->setObjectName(QStringLiteral("effectsScrollArea"));
        sizePolicy3.setHeightForWidth(effectsScrollArea->sizePolicy().hasHeightForWidth());
        effectsScrollArea->setSizePolicy(sizePolicy3);
        effectsScrollArea->setMinimumSize(QSize(0, 180));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush13(QColor(73, 73, 73, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush13);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush13);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush13);
        effectsScrollArea->setPalette(palette6);
        effectsScrollArea->setAcceptDrops(false);
        effectsScrollArea->setAutoFillBackground(true);
        effectsScrollArea->setFrameShape(QFrame::Panel);
        effectsScrollArea->setFrameShadow(QFrame::Sunken);
        effectsScrollArea->setLineWidth(3);
        effectsScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        effectsScrollArea->setWidgetResizable(true);
        effectsScrollAreaContents = new QWidget();
        effectsScrollAreaContents->setObjectName(QStringLiteral("effectsScrollAreaContents"));
        effectsScrollAreaContents->setGeometry(QRect(0, 0, 441, 275));
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
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        frameEffect1->setPalette(palette7);
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
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setIcon(icon5);
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
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/icons/006-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon6);
        pushButton_4->setIconSize(QSize(15, 15));
        pushButton_4->setFlat(true);

        horizontalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(frameEffect1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/icons/033-chevron.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
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
        importButton->setText(QString());
        playButton_2->setText(QString());
        pauseButton->setText(QString());
        stopButton_2->setText(QString());
        recordButton_2->setText(QString());
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
        label_9->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("LeandroClass", "Setting 1", Q_NULLPTR));
        label_12->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        pushButton_6->setText(QString());
        label_2->setText(QApplication::translate("LeandroClass", "Instrument 1", Q_NULLPTR));
        pushButton_2->setText(QString());
        label->setText(QApplication::translate("LeandroClass", "Effect 1", Q_NULLPTR));
        pushButton_4->setText(QString());
        pushButton->setText(QString());
        label_4->setText(QApplication::translate("LeandroClass", "Setting 1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("LeandroClass", "Effect 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeandroClass: public Ui_LeandroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEANDRO_H
