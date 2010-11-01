#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);

protected:
    void changeEvent(QEvent *e);
    void exec_lcp(const char* step);
    
    bool has_dataset;
    QString img_type, fprefix;
    int num_imgs;
    
    QString cur_step;
    bool is_job_running;
    
public slots:
        void do_load_dataset();
        void do_complete_analysis();
        void do_extract_lungs();
        void do_vasculature();
        void act_quit();
        void act_about();
        void do_viz();
};

#endif // MAINWINDOW_H
