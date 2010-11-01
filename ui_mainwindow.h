/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Jan 18 22:35:14 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAnalysis_Techniques;
    QAction *actionAuthors;
    QWidget *centralWidget;
    QPushButton *load_dataset_button;
    QDoubleSpinBox *dx_spin;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *dy_spin;
    QDoubleSpinBox *dz_spin;
    QLineEdit *dataset_path_edit;
    QPushButton *run_complete_button;
    QPushButton *extract_lungs_button;
    QFrame *line;
    QPushButton *extract_vasculature_button;
    QFrame *line_2;
    QLabel *label_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTextEdit *tty;
    QLabel *label_6;
    QSpinBox *slices_spin;
    QPushButton *lung_viz_button;
    QPushButton *vasc_viz_button;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(553, 473);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAnalysis_Techniques = new QAction(MainWindow);
        actionAnalysis_Techniques->setObjectName(QString::fromUtf8("actionAnalysis_Techniques"));
        actionAuthors = new QAction(MainWindow);
        actionAuthors->setObjectName(QString::fromUtf8("actionAuthors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        load_dataset_button = new QPushButton(centralWidget);
        load_dataset_button->setObjectName(QString::fromUtf8("load_dataset_button"));
        load_dataset_button->setGeometry(QRect(10, 10, 85, 27));
        dx_spin = new QDoubleSpinBox(centralWidget);
        dx_spin->setObjectName(QString::fromUtf8("dx_spin"));
        dx_spin->setGeometry(QRect(30, 50, 62, 25));
        dx_spin->setSingleStep(0.5);
        dx_spin->setValue(1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 21, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 60, 21, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(190, 60, 21, 16));
        dy_spin = new QDoubleSpinBox(centralWidget);
        dy_spin->setObjectName(QString::fromUtf8("dy_spin"));
        dy_spin->setGeometry(QRect(120, 50, 62, 25));
        dy_spin->setSingleStep(0.5);
        dy_spin->setValue(1);
        dz_spin = new QDoubleSpinBox(centralWidget);
        dz_spin->setObjectName(QString::fromUtf8("dz_spin"));
        dz_spin->setGeometry(QRect(210, 50, 62, 25));
        dz_spin->setSingleStep(0.5);
        dz_spin->setValue(1);
        dataset_path_edit = new QLineEdit(centralWidget);
        dataset_path_edit->setObjectName(QString::fromUtf8("dataset_path_edit"));
        dataset_path_edit->setGeometry(QRect(100, 10, 441, 23));
        run_complete_button = new QPushButton(centralWidget);
        run_complete_button->setObjectName(QString::fromUtf8("run_complete_button"));
        run_complete_button->setGeometry(QRect(10, 90, 201, 27));
        extract_lungs_button = new QPushButton(centralWidget);
        extract_lungs_button->setObjectName(QString::fromUtf8("extract_lungs_button"));
        extract_lungs_button->setGeometry(QRect(10, 140, 201, 27));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 120, 601, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        extract_vasculature_button = new QPushButton(centralWidget);
        extract_vasculature_button->setObjectName(QString::fromUtf8("extract_vasculature_button"));
        extract_vasculature_button->setGeometry(QRect(10, 180, 201, 27));
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 210, 601, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 230, 51, 16));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 250, 531, 191));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 529, 189));
        tty = new QTextEdit(scrollAreaWidgetContents);
        tty->setObjectName(QString::fromUtf8("tty"));
        tty->setGeometry(QRect(0, 0, 531, 191));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 60, 51, 16));
        slices_spin = new QSpinBox(centralWidget);
        slices_spin->setObjectName(QString::fromUtf8("slices_spin"));
        slices_spin->setGeometry(QRect(330, 50, 49, 25));
        slices_spin->setMaximum(1000);
        slices_spin->setSingleStep(10);
        slices_spin->setValue(200);
        lung_viz_button = new QPushButton(centralWidget);
        lung_viz_button->setObjectName(QString::fromUtf8("lung_viz_button"));
        lung_viz_button->setGeometry(QRect(220, 140, 81, 27));
        vasc_viz_button = new QPushButton(centralWidget);
        vasc_viz_button->setObjectName(QString::fromUtf8("vasc_viz_button"));
        vasc_viz_button->setGeometry(QRect(220, 180, 81, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 553, 22));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QString::fromUtf8("menuFIle"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFIle->addSeparator();
        menuFIle->addAction(actionQuit);
        menuAbout->addAction(actionAuthors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Lung Cancer Detection and Analysis", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionAnalysis_Techniques->setText(QApplication::translate("MainWindow", "Analysis Techniques", 0, QApplication::UnicodeUTF8));
        actionAuthors->setText(QApplication::translate("MainWindow", "Organizations and Authors", 0, QApplication::UnicodeUTF8));
        load_dataset_button->setText(QApplication::translate("MainWindow", "Load Dataset", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "dx:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "dy:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "dz:", 0, QApplication::UnicodeUTF8));
        run_complete_button->setText(QApplication::translate("MainWindow", "Run Complete Analysis", 0, QApplication::UnicodeUTF8));
        extract_lungs_button->setText(QApplication::translate("MainWindow", "Visualize Extracted Lungs", 0, QApplication::UnicodeUTF8));
        extract_vasculature_button->setText(QApplication::translate("MainWindow", "Visualize Extracted Vasculature", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Output:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "#slices:", 0, QApplication::UnicodeUTF8));
        lung_viz_button->setText(QApplication::translate("MainWindow", "Visualize", 0, QApplication::UnicodeUTF8));
        vasc_viz_button->setText(QApplication::translate("MainWindow", "Visualize", 0, QApplication::UnicodeUTF8));
        menuFIle->setTitle(QApplication::translate("MainWindow", "FIle", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
