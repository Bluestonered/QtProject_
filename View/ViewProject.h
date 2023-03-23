#ifndef VIEWPROJECT_H
#define VIEWPROJECT_H

#include <QWidget>
#include <QGraphicsView>

class ViewProject : public QGraphicsView
{
public:
    ViewProject();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // VIEWPROJECT_H
