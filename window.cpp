#include "window.hpp"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    timer = new QTimer;
    timer->setInterval(100);
    pixmap = QPixmap(":/star");
    gView = new CustomGraphicsView(this);
    ui->gridGView->addWidget(gView);
    scene = new QGraphicsScene(this);
    pixmapitem = scene->addPixmap(pixmap);
    pixmapitem->setPos(50,50);
    gView->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    gView->setScene(scene);
    gView->show();

    connect(timer, SIGNAL(timeout()), this, SLOT(moveObject()));
    connect(ui->bDraw, SIGNAL(clicked()), this, SLOT(clickedDraw()));
    connect(gView, SIGNAL(mouseClicked(QPoint)), this, SLOT(getClickedPoint(QPoint)));
}

Window::~Window()
{
    delete ui;
}

void Window::moveObject()
{
    if(points.isEmpty())
    {
        timer->stop();
        return;
    }
    pixmapitem->setPos(points.front());
    points.pop_front();
    gView->repaint();
}

void Window::clickedDraw()
{
    points.clear();
    QPoint a(ui->ax->value(),ui->ay->value());
    QPoint b(ui->bx->value(),ui->by->value());
    int dx = b.x() - a.x();
    int dy = b.y() - a.y();
    for(int x=a.x();x<b.x();x+=5)
        points << QPoint(x, a.y() + dy*(x-a.x())/dx);
    timer->start();
}

void Window::getClickedPoint(QPoint point)
{
    if(ui->start->isChecked())
    {
        ui->ax->setValue(point.x());
        ui->ay->setValue(point.y());
    }
    else
    {
        ui->bx->setValue(point.x());
        ui->by->setValue(point.y());
    }
}
