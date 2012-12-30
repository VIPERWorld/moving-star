#ifndef CUSTOMGRAPHICSVIEW_HPP
#define CUSTOMGRAPHICSVIEW_HPP

#include <QGraphicsView>
#include <QMouseEvent>

class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CustomGraphicsView(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *event);

signals:
    void mouseClicked(QPoint);

public slots:

};

#endif // CUSTOMGRAPHICSVIEW_HPP
