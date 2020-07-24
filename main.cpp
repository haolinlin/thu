#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//#include "layoutDemo.h"
#include "qwidgetdraw.h"
#include "qwidgetserialtx.h"
#include "qwidgetserialrx.h"

#if 0
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    QWidget *mainWin = new QWidget();
    QWidgetSerialTx *serialTx = new QWidgetSerialTx(mainWin);
    QWidgetSerialRx *serialRx = new QWidgetSerialRx(mainWin);

    mainWin->resize(300,300);
    mainWin->show();

    return a.exec();
}

#endif
/*
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    //创建layout
     QHBoxLayout *layoutUserName = new QHBoxLayout();
     QHBoxLayout *layoutPassword = new QHBoxLayout();
     QVBoxLayout *layoutMain = new QVBoxLayout();

     //layout中添加控件
     layoutUserName->addWidget(new QLabel("用户名"));
     layoutPassword->addWidget(new QLabel("密码"));
//创建文本框控件并加到layout
QLineEdit *lineEditUserName = new QLineEdit();
QLineEdit *lineEditPassword = new QLineEdit();
lineEditPassword->setEchoMode(QLineEdit::Password);
layoutUserName->addWidget(lineEditUserName);
  layoutPassword->addWidget(lineEditPassword);

//子layout添加到主layout
     layoutMain->addLayout(layoutUserName);
     layoutMain->addLayout(layoutPassword);
     QPushButton *btn = new QPushButton("登录");
     layoutMain->addWidget(btn);


//主页main使用layout
     QWidget *widgetMain = new QWidget();
     widgetMain->setLayout(layoutMain);

     widgetMain->resize(600,400);
     widgetMain->show();
    return a.exec();
}
*/
#if 1
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    /************************************************/
    //创建三个波形控件
    QWidgetDraw *drawWidgetEcgI = new QWidgetDraw();
    QWidgetDraw *drawWidgetEcgII = new QWidgetDraw();
    QWidgetDraw *drawWidgetEcgIII = new QWidgetDraw();
    //配置波形控件的
    drawWidgetEcgI->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawWidgetEcgII->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    drawWidgetEcgIII->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
//设置界面中标签内容
     drawWidgetEcgI->setLabelText("ECG   I");
     drawWidgetEcgII->setLabelText("ECG   II");
     drawWidgetEcgIII->setLabelText("ECG   III");

   // drawWidgetEcgI->setStyleSheet("color：red");
    //drawWidgetEcgII->setStyleSheet("color：white");
    // drawWidgetEcgIII->setStyleSheet("color：white");

    QVBoxLayout *layoutWave = new QVBoxLayout();
    //
    layoutWave->addWidget(drawWidgetEcgI);
    layoutWave->addWidget(drawWidgetEcgII);
    layoutWave->addWidget(drawWidgetEcgIII);

    //添加按钮，数据控件布局器
    QLabel *widgetHr = new QLabel();
     QLabel *widgetNibp = new QLabel();

    widgetHr->setText("HR");
     widgetNibp->setText("NiBP");
//创建按钮
     QPushButton *btnUp = new QPushButton("UP");
     QPushButton *btnDown = new QPushButton("DOWN");
//修改按钮啦
      btnUp->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    btnDown->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);

     QVBoxLayout *layoutLabelAndBtn= new QVBoxLayout();

     layoutLabelAndBtn->addWidget(widgetHr);
     layoutLabelAndBtn->addWidget(widgetNibp);
     layoutLabelAndBtn->addWidget(btnUp);
     layoutLabelAndBtn->addWidget(btnDown);

       QHBoxLayout *layoutMain = new QHBoxLayout();
       layoutMain->addLayout(layoutWave);
       layoutMain->addLayout(layoutLabelAndBtn);

       layoutMain->setStretchFactor(layoutWave,2);
       layoutMain->setStretchFactor(layoutLabelAndBtn,1);

    QWidget *mainWin = new QWidget();
    mainWin->setWindowTitle("TeamName 1600 x 600");
    mainWin->setLayout(layoutMain);
    mainWin->resize(1600, 600);

    mainWin->show();

    return a.exec();
}

#endif
