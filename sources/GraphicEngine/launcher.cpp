//
// launcher.cpp for  in /home/soidik_d/Semestre_04/cpp/cpp_bomberman/sources/GraphicEngine
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Jun 23 14:52:33 2015 SOIDIKI Djamil
// Last update Tue Jun 23 15:59:13 2015 SOIDIKI Djamil
//

#include	"../../includes/GraphicEngine/launcher.h"
#include	"../../includes/GraphicEngine/ui_launcher.h"
#include        "../../includes/GameEngine/Options.hh"
#include        "../../includes/GameEngine/GameEngine.hh"
#include	<unistd.h>
#include	<stdlib.h>

Launcher::Launcher(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Launcher)
{
    ui->setupUi(this);
    QPixmap pix("./utils/Background.jpg");
    ui->Background->setStyleSheet("border-image:url(./utils/Background.jpg);");
    ui->Background->setPixmap(pix);
    ui->labelP2->setStyleSheet("border-image:url(./utils/Background.jpg);");
    ui->labelP2->setPixmap(pix);
    ui->OptionBack->setStyleSheet("border-image:url(./utils/Background.jpg);");
    ui->OptionBack->setPixmap(pix);

    QStringList     list;


    struct dirent *lecture;
    DIR *rep;
    rep = opendir("./map/");
    while ((lecture = readdir(rep))) {
        list.push_back(lecture->d_name);
    }
    closedir(rep);
    list.pop_front();
    list.pop_front();
    ui->listWidget->addItems(list);
}

Launcher::~Launcher()
{
    delete ui;
}

void Launcher::on_Play_clicked()
{
    /*QIcon *ico = new QIcon();
    ico->addPixmap(QPixmap("PlayOn.png"),QIcon::Normal,QIcon::On);
    ico->addPixmap(QPixmap("PlayOff.png"),QIcon::Normal,QIcon::Off);
    ui->Play->setIcon(*ico);
    ui->Play->setCheckable(true);*/

    ui->Start->setCurrentIndex(1);
}

void Launcher::on_Exit_clicked()
{
    qApp->quit();
}

void Launcher::on_Back_clicked()
{
    ui->Start->setCurrentIndex(0);
}



void Launcher::on_Back_2_clicked()
{
    ui->Start->setCurrentIndex(0);
}

void Launcher::on_Option_clicked()
{
    ui->Start->setCurrentIndex(2);
    if (ui->DefinedMap->isChecked() == true)
    {
        //QString str = ui->listWidget->currentItem()->text();
        //str.toAscii();
    }
    else if (ui->DefineMap->isChecked() == true)
    {
        ui->X->value();
        ui->Y->value();
    }
}

void Launcher::on_Load_clicked()
{

}

#include "../../includes/common/CreateMap.hh"

void Launcher::on_StartGame_clicked()
{
  Options	opt(ui->Players->value(),
		    ui->IA->value(),
		    ui->X->value(),
		    ui->Y->value(),
		    ui->DefineMap->isChecked());

  opt.setIALevel(ui->IALevel->value());
  if (ui->DefineMap->isChecked() == true)
    {
      CreateMap creatormap;
      
      creatormap.create_map(ui->X->value(), ui->Y->value());
      opt.setMap(std::string("random.xml"));
    }
  else
    opt.setMap(std::string("level1.xml"));
    
  delete ui;
  this->close();

  GameEngine eng(&opt);
  if (eng.initialize() == false)
    exit(0);
  while (eng.update()) {
    eng.draw();
  }
}
