#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QtGui/QMainWindow>
#include <sys/types.h>
#include <dirent.h>


namespace Ui
{
    class Launcher;
}

class Launcher : public QMainWindow
{
    Q_OBJECT

public:
    Launcher(QWidget *parent = 0);
    ~Launcher();

private:
    Ui::Launcher *ui;

private slots:
    void on_Load_clicked();
    void on_Option_clicked();
    //void on_listWidget_activated(QModelIndex index);
    void on_Back_2_clicked();
    //void on_Play_3_clicked();
    void on_StartGame_clicked();
    void on_Back_clicked();
    void on_Exit_clicked();
    void on_Play_clicked();
};

#endif // LAUNCHER_H
