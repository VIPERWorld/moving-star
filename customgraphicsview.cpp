#include "customgraphicsview.hpp"

CustomGraphicsView::CustomGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void CustomGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->type() == QMouseEvent::MouseButtonPress)
    {
        emit mouseClicked(QPoint(event->pos().x(),event->pos().y()));
        event->accept();
    }
}
