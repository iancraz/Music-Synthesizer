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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LeandroClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *playButton_2;
    QPushButton *stopButton_2;
    QPushButton *recordButton_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QListView *instrumentsList_2;
    QPushButton *pushButton_7;
    QLabel *label_8;
    QListView *effectsList_2;
    QPushButton *pushButton_8;
    QScrollArea *scrollAreaChannels_2;
    QWidget *scrollAreaChannelsWidgetContents_2;
    QHBoxLayout *horizontalLayout_7;
    QGroupBox *groupBoxChannel1_2;
    QGridLayout *gridLayoutChannel1_2;
    QVBoxLayout *verticalLayoutChannel1_2;
    QPushButton *setActiveButtonChannel1_2;
    QLabel *InputLabelChannel1_2;
    QComboBox *inputComboBoxChannel1_2;
    QListWidget *midiListChannel1_2;
    QDial *levelDialChannel1_2;
    QLabel *levelLabelChannel1_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
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
    QGroupBox *groupBox_5;
    QGroupBox *groupBox_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LeandroClass)
    {
        if (LeandroClass->objectName().isEmpty())
            LeandroClass->setObjectName(QStringLiteral("LeandroClass"));
        LeandroClass->resize(851, 594);
        centralWidget = new QWidget(LeandroClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        playButton_2 = new QPushButton(centralWidget);
        playButton_2->setObjectName(QStringLiteral("playButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(playButton_2->sizePolicy().hasHeightForWidth());
        playButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(playButton_2);

        stopButton_2 = new QPushButton(centralWidget);
        stopButton_2->setObjectName(QStringLiteral("stopButton_2"));
        sizePolicy.setHeightForWidth(stopButton_2->sizePolicy().hasHeightForWidth());
        stopButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(stopButton_2);

        recordButton_2 = new QPushButton(centralWidget);
        recordButton_2->setObjectName(QStringLiteral("recordButton_2"));

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
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_8->addWidget(label_7);

        instrumentsList_2 = new QListView(centralWidget);
        instrumentsList_2->setObjectName(QStringLiteral("instrumentsList_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(instrumentsList_2->sizePolicy().hasHeightForWidth());
        instrumentsList_2->setSizePolicy(sizePolicy1);
        instrumentsList_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_8->addWidget(instrumentsList_2);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_8->addWidget(pushButton_7);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_8->addWidget(label_8);

        effectsList_2 = new QListView(centralWidget);
        effectsList_2->setObjectName(QStringLiteral("effectsList_2"));
        sizePolicy1.setHeightForWidth(effectsList_2->sizePolicy().hasHeightForWidth());
        effectsList_2->setSizePolicy(sizePolicy1);
        effectsList_2->setMaximumSize(QSize(100, 16777215));

        verticalLayout_8->addWidget(effectsList_2);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        verticalLayout_8->addWidget(pushButton_8);


        horizontalLayout_5->addLayout(verticalLayout_8);

        scrollAreaChannels_2 = new QScrollArea(centralWidget);
        scrollAreaChannels_2->setObjectName(QStringLiteral("scrollAreaChannels_2"));
        scrollAreaChannels_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaChannels_2->setWidgetResizable(true);
        scrollAreaChannelsWidgetContents_2 = new QWidget();
        scrollAreaChannelsWidgetContents_2->setObjectName(QStringLiteral("scrollAreaChannelsWidgetContents_2"));
        scrollAreaChannelsWidgetContents_2->setGeometry(QRect(0, 0, 719, 298));
        horizontalLayout_7 = new QHBoxLayout(scrollAreaChannelsWidgetContents_2);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        groupBoxChannel1_2 = new QGroupBox(scrollAreaChannelsWidgetContents_2);
        groupBoxChannel1_2->setObjectName(QStringLiteral("groupBoxChannel1_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBoxChannel1_2->sizePolicy().hasHeightForWidth());
        groupBoxChannel1_2->setSizePolicy(sizePolicy2);
        gridLayoutChannel1_2 = new QGridLayout(groupBoxChannel1_2);
        gridLayoutChannel1_2->setSpacing(6);
        gridLayoutChannel1_2->setContentsMargins(11, 11, 11, 11);
        gridLayoutChannel1_2->setObjectName(QStringLiteral("gridLayoutChannel1_2"));
        verticalLayoutChannel1_2 = new QVBoxLayout();
        verticalLayoutChannel1_2->setSpacing(6);
        verticalLayoutChannel1_2->setObjectName(QStringLiteral("verticalLayoutChannel1_2"));
        setActiveButtonChannel1_2 = new QPushButton(groupBoxChannel1_2);
        setActiveButtonChannel1_2->setObjectName(QStringLiteral("setActiveButtonChannel1_2"));

        verticalLayoutChannel1_2->addWidget(setActiveButtonChannel1_2);

        InputLabelChannel1_2 = new QLabel(groupBoxChannel1_2);
        InputLabelChannel1_2->setObjectName(QStringLiteral("InputLabelChannel1_2"));

        verticalLayoutChannel1_2->addWidget(InputLabelChannel1_2);

        inputComboBoxChannel1_2 = new QComboBox(groupBoxChannel1_2);
        inputComboBoxChannel1_2->setObjectName(QStringLiteral("inputComboBoxChannel1_2"));

        verticalLayoutChannel1_2->addWidget(inputComboBoxChannel1_2);

        midiListChannel1_2 = new QListWidget(groupBoxChannel1_2);
        new QListWidgetItem(midiListChannel1_2);
        midiListChannel1_2->setObjectName(QStringLiteral("midiListChannel1_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(midiListChannel1_2->sizePolicy().hasHeightForWidth());
        midiListChannel1_2->setSizePolicy(sizePolicy3);
        midiListChannel1_2->setMaximumSize(QSize(100, 16777215));

        verticalLayoutChannel1_2->addWidget(midiListChannel1_2);

        levelDialChannel1_2 = new QDial(groupBoxChannel1_2);
        levelDialChannel1_2->setObjectName(QStringLiteral("levelDialChannel1_2"));

        verticalLayoutChannel1_2->addWidget(levelDialChannel1_2);

        levelLabelChannel1_2 = new QLabel(groupBoxChannel1_2);
        levelLabelChannel1_2->setObjectName(QStringLiteral("levelLabelChannel1_2"));
        QFont font;
        font.setFamily(QStringLiteral("Oxygen"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferAntialias);
        levelLabelChannel1_2->setFont(font);
        levelLabelChannel1_2->setAlignment(Qt::AlignCenter);

        verticalLayoutChannel1_2->addWidget(levelLabelChannel1_2);


        gridLayoutChannel1_2->addLayout(verticalLayoutChannel1_2, 0, 0, 1, 1);


        horizontalLayout_7->addWidget(groupBoxChannel1_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        scrollAreaChannels_2->setWidget(scrollAreaChannelsWidgetContents_2);

        horizontalLayout_5->addWidget(scrollAreaChannels_2);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        scrollArea_3 = new QScrollArea(centralWidget);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        sizePolicy3.setHeightForWidth(scrollArea_3->sizePolicy().hasHeightForWidth());
        scrollArea_3->setSizePolicy(sizePolicy3);
        scrollArea_3->setMinimumSize(QSize(0, 180));
        scrollArea_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 827, 201));
        horizontalLayout_9 = new QHBoxLayout(scrollAreaWidgetContents_3);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        dial_5 = new QDial(groupBox_2);
        dial_5->setObjectName(QStringLiteral("dial_5"));

        verticalLayout_9->addWidget(dial_5);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_9->addWidget(label_9);


        gridLayout_5->addLayout(verticalLayout_9, 0, 2, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        dial_6 = new QDial(groupBox_2);
        dial_6->setObjectName(QStringLiteral("dial_6"));

        verticalLayout_10->addWidget(dial_6);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_10->addWidget(label_10);


        gridLayout_5->addLayout(verticalLayout_10, 0, 1, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        dial_7 = new QDial(groupBox_2);
        dial_7->setObjectName(QStringLiteral("dial_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dial_7->sizePolicy().hasHeightForWidth());
        dial_7->setSizePolicy(sizePolicy4);
        dial_7->setMaximumSize(QSize(16777215, 16777215));
        dial_7->setWrapping(false);

        verticalLayout_11->addWidget(dial_7);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_11);


        gridLayout_5->addLayout(verticalLayout_11, 0, 0, 1, 1);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        dial_8 = new QDial(groupBox_2);
        dial_8->setObjectName(QStringLiteral("dial_8"));

        verticalLayout_12->addWidget(dial_8);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_12->addWidget(label_12);


        gridLayout_5->addLayout(verticalLayout_12, 1, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_5, 0, 0, 1, 1);


        horizontalLayout_9->addWidget(groupBox_2);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));

        horizontalLayout_9->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));

        horizontalLayout_9->addWidget(groupBox_6);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        horizontalLayout_8->addWidget(scrollArea_3);


        verticalLayout_6->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_6, 1, 0, 1, 1);

        LeandroClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LeandroClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 851, 21));
        LeandroClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LeandroClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LeandroClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LeandroClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LeandroClass->setStatusBar(statusBar);

        retranslateUi(LeandroClass);

        QMetaObject::connectSlotsByName(LeandroClass);
    } // setupUi

    void retranslateUi(QMainWindow *LeandroClass)
    {
        LeandroClass->setWindowTitle(QApplication::translate("LeandroClass", "Leandro", Q_NULLPTR));
        playButton_2->setText(QApplication::translate("LeandroClass", "Play", Q_NULLPTR));
        stopButton_2->setText(QApplication::translate("LeandroClass", "Stop", Q_NULLPTR));
        recordButton_2->setText(QApplication::translate("LeandroClass", "Record", Q_NULLPTR));
        label_7->setText(QApplication::translate("LeandroClass", "Instruments", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("LeandroClass", "Set for Channel", Q_NULLPTR));
        label_8->setText(QApplication::translate("LeandroClass", "Effects", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("LeandroClass", "Add to Channel", Q_NULLPTR));
        groupBoxChannel1_2->setTitle(QApplication::translate("LeandroClass", "Channel 1", Q_NULLPTR));
        setActiveButtonChannel1_2->setText(QApplication::translate("LeandroClass", "Set Active", Q_NULLPTR));
        InputLabelChannel1_2->setText(QApplication::translate("LeandroClass", "Input", Q_NULLPTR));
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
        groupBox_2->setTitle(QApplication::translate("LeandroClass", "Instrument", Q_NULLPTR));
        label_9->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("LeandroClass", "Setting 1", Q_NULLPTR));
        label_12->setText(QApplication::translate("LeandroClass", "TextLabel", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("LeandroClass", "Effect 1", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("LeandroClass", "Effect 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LeandroClass: public Ui_LeandroClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEANDRO_H
