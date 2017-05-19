/********************************************************************************
** Form generated from reading UI file 'launcher.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHER_H
#define UI_LAUNCHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Launcher
{
public:
    QWidget *centralWidget;
    QStackedWidget *Start;
    QWidget *Page1;
    QLabel *Background;
    QPushButton *Play;
    QPushButton *Exit;
    QPushButton *Load;
    QPushButton *Option;
    QWidget *page2;
    QLabel *labelP2;
    QPushButton *Back;
    QPushButton *StartGame;
    QSpinBox *Players;
    QSpinBox *IALevel;
    QSpinBox *IA;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *page3;
    QLabel *OptionBack;
    QPushButton *Back_2;
    QListWidget *listWidget;
    QLabel *label;
    QRadioButton *DefinedMap;
    QRadioButton *DefineMap;
    QSpinBox *X;
    QSpinBox *Y;

    void setupUi(QMainWindow *Launcher)
    {
        if (Launcher->objectName().isEmpty())
            Launcher->setObjectName(QString::fromUtf8("Launcher"));
        Launcher->resize(960, 520);
        Launcher->setMinimumSize(QSize(960, 520));
        Launcher->setMaximumSize(QSize(960, 520));
        Launcher->setSizeIncrement(QSize(0, 0));
        centralWidget = new QWidget(Launcher);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Start = new QStackedWidget(centralWidget);
        Start->setObjectName(QString::fromUtf8("Start"));
        Start->setGeometry(QRect(-1, 0, 960, 520));
        Start->setMinimumSize(QSize(960, 520));
        Start->setMaximumSize(QSize(960, 520));
        Start->setFrameShape(QFrame::Panel);
        Start->setFrameShadow(QFrame::Plain);
        Page1 = new QWidget();
        Page1->setObjectName(QString::fromUtf8("Page1"));
        Background = new QLabel(Page1);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 961, 521));
        Background->setPixmap(QPixmap(QString::fromUtf8("debug/Background.jpg")));
        Background->setScaledContents(true);
        Play = new QPushButton(Page1);
        Play->setObjectName(QString::fromUtf8("Play"));
        Play->setGeometry(QRect(560, 280, 169, 81));
        Play->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";"));
        Play->setIconSize(QSize(170, 50));
        Play->setAutoDefault(false);
        Play->setDefault(false);
        Play->setFlat(true);
        Exit = new QPushButton(Page1);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(750, 440, 169, 81));
        Exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";"));
        Exit->setIconSize(QSize(170, 50));
        Exit->setAutoDefault(false);
        Exit->setDefault(false);
        Exit->setFlat(true);
        Load = new QPushButton(Page1);
        Load->setObjectName(QString::fromUtf8("Load"));
        Load->setGeometry(QRect(750, 280, 169, 81));
        Load->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";"));
        Load->setIconSize(QSize(170, 50));
        Load->setAutoDefault(false);
        Load->setDefault(false);
        Load->setFlat(true);
        Option = new QPushButton(Page1);
        Option->setObjectName(QString::fromUtf8("Option"));
        Option->setGeometry(QRect(760, 380, 169, 81));
        Option->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 30pt \"Narkisim\";"));
        Option->setIconSize(QSize(170, 50));
        Option->setAutoDefault(false);
        Option->setDefault(false);
        Option->setFlat(true);
        Start->addWidget(Page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        labelP2 = new QLabel(page2);
        labelP2->setObjectName(QString::fromUtf8("labelP2"));
        labelP2->setGeometry(QRect(0, 0, 961, 521));
        labelP2->setPixmap(QPixmap(QString::fromUtf8("debug/Background.jpg")));
        labelP2->setScaledContents(true);
        Back = new QPushButton(page2);
        Back->setObjectName(QString::fromUtf8("Back"));
        Back->setGeometry(QRect(150, 10, 169, 81));
        Back->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";\n"
""));
        Back->setIconSize(QSize(170, 50));
        Back->setAutoDefault(false);
        Back->setDefault(false);
        Back->setFlat(true);
        StartGame = new QPushButton(page2);
        StartGame->setObjectName(QString::fromUtf8("StartGame"));
        StartGame->setGeometry(QRect(640, 420, 281, 81));
        StartGame->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";\n"
""));
        StartGame->setIconSize(QSize(170, 50));
        StartGame->setAutoDefault(false);
        StartGame->setDefault(false);
        StartGame->setFlat(true);
        Players = new QSpinBox(page2);
        Players->setObjectName(QString::fromUtf8("Players"));
        Players->setGeometry(QRect(540, 330, 71, 31));
        Players->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0.523, y1:0.0113636, x2:0.534, y2:1, stop:0 rgba(0, 54, 196, 255), stop:1 rgba(212, 255, 255, 255));\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"color: rgb(255, 0, 0);"));
        Players->setMaximum(2);
        Players->setValue(1);
        IALevel = new QSpinBox(page2);
        IALevel->setObjectName(QString::fromUtf8("IALevel"));
        IALevel->setGeometry(QRect(810, 330, 71, 31));
        IALevel->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0.523, y1:0.0113636, x2:0.534, y2:1, stop:0 rgba(0, 54, 196, 255), stop:1 rgba(212, 255, 255, 255));\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"color: rgb(255, 0, 0);"));
        IALevel->setMaximum(3);
        IA = new QSpinBox(page2);
        IA->setObjectName(QString::fromUtf8("IA"));
        IA->setGeometry(QRect(680, 330, 71, 31));
        IA->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0.523, y1:0.0113636, x2:0.534, y2:1, stop:0 rgba(0, 54, 196, 255), stop:1 rgba(212, 255, 255, 255));\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"color: rgb(255, 0, 0);"));
        label_2 = new QLabel(page2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(550, 300, 61, 16));
        label_2->setStyleSheet(QString::fromUtf8("color rgb(0, 0, 0);\n"
"font: 75 10pt \"Narkisim\";"));
        label_3 = new QLabel(page2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(820, 300, 61, 16));
        label_3->setStyleSheet(QString::fromUtf8("color rgb(0, 0, 0);\n"
"font: 75 10pt \"Narkisim\";"));
        label_4 = new QLabel(page2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(700, 300, 46, 14));
        label_4->setStyleSheet(QString::fromUtf8("color rgb(0, 0, 0);\n"
"font: 75 10pt \"Narkisim\";"));
        Start->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        OptionBack = new QLabel(page3);
        OptionBack->setObjectName(QString::fromUtf8("OptionBack"));
        OptionBack->setGeometry(QRect(0, 0, 961, 521));
        OptionBack->setPixmap(QPixmap(QString::fromUtf8("debug/Background.jpg")));
        OptionBack->setScaledContents(true);
        Back_2 = new QPushButton(page3);
        Back_2->setObjectName(QString::fromUtf8("Back_2"));
        Back_2->setGeometry(QRect(150, 20, 169, 81));
        Back_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";\n"
""));
        Back_2->setIconSize(QSize(170, 50));
        Back_2->setAutoDefault(false);
        Back_2->setDefault(false);
        Back_2->setFlat(true);
        listWidget = new QListWidget(page3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(669, 250, 251, 91));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"font: 75 20pt \"Narkisim\";\n"
""));
        listWidget->setUniformItemSizes(false);
        listWidget->setWordWrap(false);
        listWidget->setSelectionRectVisible(false);
        listWidget->setSortingEnabled(false);
        label = new QLabel(page3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(700, 200, 121, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 75 40pt \"Narkisim\";\n"
""));
        DefinedMap = new QRadioButton(page3);
        DefinedMap->setObjectName(QString::fromUtf8("DefinedMap"));
        DefinedMap->setGeometry(QRect(550, 270, 121, 31));
        DefinedMap->setStyleSheet(QString::fromUtf8("color rgb(0, 0, 0);\n"
"font: 75 10pt \"Narkisim\";"));
        DefinedMap->setCheckable(true);
        DefinedMap->setChecked(true);
        DefinedMap->setAutoRepeat(false);
        DefinedMap->setAutoExclusive(true);
        DefineMap = new QRadioButton(page3);
        DefineMap->setObjectName(QString::fromUtf8("DefineMap"));
        DefineMap->setGeometry(QRect(550, 360, 141, 31));
        DefineMap->setStyleSheet(QString::fromUtf8("color rgb(0, 0, 0);\n"
"font: 75 10pt \"Narkisim\";"));
        X = new QSpinBox(page3);
        X->setObjectName(QString::fromUtf8("X"));
        X->setGeometry(QRect(720, 360, 61, 31));
        X->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0.523, y1:0.0113636, x2:0.534, y2:1, stop:0 rgba(0, 54, 196, 255), stop:1 rgba(212, 255, 255, 255));\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"color: rgb(255, 0, 0);"));
        X->setMinimum(10);
        X->setMaximum(100000);
        Y = new QSpinBox(page3);
        Y->setObjectName(QString::fromUtf8("Y"));
        Y->setGeometry(QRect(850, 360, 61, 31));
        Y->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0.523, y1:0.0113636, x2:0.534, y2:1, stop:0 rgba(0, 54, 196, 255), stop:1 rgba(212, 255, 255, 255));\n"
"background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0));\n"
"color: rgb(255, 0, 0);"));
        Y->setMinimum(10);
        Y->setMaximum(100000);
        Start->addWidget(page3);
        Launcher->setCentralWidget(centralWidget);

        retranslateUi(Launcher);

        Start->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Launcher);
    } // setupUi

    void retranslateUi(QMainWindow *Launcher)
    {
        Launcher->setWindowTitle(QApplication::translate("Launcher", "Launcher", 0, QApplication::UnicodeUTF8));
        Background->setText(QString());
        Play->setText(QApplication::translate("Launcher", "PLAY", "50", QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("Launcher", "EXIT", "50", QApplication::UnicodeUTF8));
        Load->setText(QApplication::translate("Launcher", "LOAD", "50", QApplication::UnicodeUTF8));
        Option->setText(QApplication::translate("Launcher", "OPTION", "50", QApplication::UnicodeUTF8));
        labelP2->setText(QString());
        Back->setText(QApplication::translate("Launcher", "BACK", "50", QApplication::UnicodeUTF8));
        StartGame->setText(QApplication::translate("Launcher", "START", "50", QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Launcher", "PLAYERS", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Launcher", "IA LEVEL", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Launcher", "IA", 0, QApplication::UnicodeUTF8));
        OptionBack->setText(QString());
        Back_2->setText(QApplication::translate("Launcher", "BACK", "50", QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Launcher", "MAP", 0, QApplication::UnicodeUTF8));
        DefinedMap->setText(QApplication::translate("Launcher", "DEFINED MAP", 0, QApplication::UnicodeUTF8));
        DefineMap->setText(QApplication::translate("Launcher", "DEFINE MAP X AND Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Launcher: public Ui_Launcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHER_H
