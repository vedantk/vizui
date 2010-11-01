#include <QtGui>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : 
        QMainWindow(parent)
{
        setupUi(this);
        has_dataset = false;
        is_job_running = false;

        connect(load_dataset_button, SIGNAL(clicked()), this, SLOT(do_load_dataset()));
        connect(extract_vasculature_button, SIGNAL(clicked()), this, SLOT(do_vasculature()));
        connect(extract_lungs_button, SIGNAL(clicked()), this, SLOT(do_extract_lungs()));
        connect(run_complete_button, SIGNAL(clicked()), this, SLOT(do_complete_analysis()));
        connect(actionQuit, SIGNAL(triggered()), this, SLOT(act_quit()));
        connect(actionAuthors, SIGNAL(triggered()), this, SLOT(act_about()));
        connect(lung_viz_button, SIGNAL(clicked()), this, SLOT(do_viz()));
        connect(vasc_viz_button, SIGNAL(clicked()), this, SLOT(do_viz()));
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::do_load_dataset() {
        tty->append("Loading dataset...");

        QString rand_img = QFileDialog::getOpenFileName(this,
                tr("Pick one image from the data set."), QDir::homePath(),
                tr("Scan Data (*.pgm *.bmp)"));
                
        if (rand_img != "") {
                tty->append("-->" + rand_img);
        } else {
                tty->append("--> Error: No base image selected.");
                return;
        }             
        
        QFileInfo qfi(rand_img);
        img_type = QString(qfi.suffix());
        fprefix = rand_img;
        fprefix.chop(7);
        dataset_path_edit->setText(fprefix);
        
        // num_imgs = slices_spin->value();        
        QDir dir(qfi.dir());
        QStringList filters;
        QString ifilt = "*." + img_type;
		filters << ifilt;
		dir.setNameFilters(filters);
        num_imgs = dir.count();
        slices_spin->setValue(num_imgs);
        
        tty->append("--> fprefix: " + fprefix);
        tty->append("--> Note: You may want to modify the slice/spacing parameters using the controls above.");
        
        has_dataset = true;
}

void MainWindow::exec_lcp(const char* step) {
        if (!has_dataset) {
                tty->append("Error: No dataset is available.");
                return;
        }
        
        if (is_job_running) {
			tty->append("Error: Please wait for all jobs to finish.");
			return;
		}
		
		cur_step = QString(step);
        
        static char cmd[2048];
        num_imgs = slices_spin->value();
        fprefix = dataset_path_edit->text();
        
        sprintf(cmd, "xterm -e \"./lcp %d %s %s %s %f %f %f\"", num_imgs,
			img_type.toStdString().c_str(),	fprefix.toStdString().c_str(),
			step, dx_spin->value(), dy_spin->value(), dz_spin->value());
                
        tty->append(QString(cmd));
        is_job_running = true;
        system(cmd);
        is_job_running = false;
}

void MainWindow::do_viz() {
	if (is_job_running) {
		tty->append("Error: Please wait for all jobs to finish.");
			return;
		}
	
	tty->append("Please be patient while the 3-D software creates a visualization.");
	tty->append("You may see a blank screen for 1 to 5 minutes, depending on how large the data is.");
	
	static char cmd[1024];
	sprintf(cmd, "./viz3d %s%s %d %f %f %f", fprefix.toStdString().c_str(),
		cur_step == "lungs" ? "__ex_vol/" :
			cur_step == "vasc" ? "__volume/" : "__final/", num_imgs,
			dx_spin->value(), dy_spin->value(), dz_spin->value());
			
	tty->append(QString(cmd));
	is_job_running = true;
	system(cmd);
	is_job_running = false;
}

void MainWindow::do_complete_analysis() {
        tty->append("Starting full analysis...");
        exec_lcp("all");
}

void MainWindow::do_extract_lungs() {
        tty->append("Starting lung extraction...");
        exec_lcp("lungs");
}

void MainWindow::do_vasculature() {
        tty->append("Starting vasculature and nodule analysis...");
        exec_lcp("vasc");
}

void MainWindow::act_quit() {
        exit(0);
}

void MainWindow::act_about() {
        tty->append("lcp - accurate prediction and tracking of lung cancer nodules");
        tty->append("Author/Programmer: Vedant Kumar, Junior, duPont Manual High School");
        tty->append("Mentor: Dr. Ayman S. El-Baz, University of Louisville, Bio-Imaging Dept."); 
}
