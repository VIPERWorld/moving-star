#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "customgraphicsview.hpp"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
    void moveObject();
    void clickedDraw();
    void getClickedPoint(QPoint point);

private:
    Ui::Window *ui;
    QTimer *timer;
    QGraphicsPixmapItem *pixmapitem;
    QGraphicsScene *scene;
    QPixmap pixmap;
    QList<QPoint> points;
    CustomGraphicsView *gView;
};

#endif // WINDOW_HPP
