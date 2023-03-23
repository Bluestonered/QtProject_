//
// Created by blue on 23/03/23.
//

#include "MyGraphicsView.h"
#include "QDebug"
#include "QMouseEvent"

void MyGraphicsView::mousePressEvent(QMouseEvent *event) {
    QGraphicsView::mousePressEvent(event);

    QPointF viewPos = event->pos();
    qDebug() << "Position de la souris dans la scène : " << viewPos.x() << ", " << viewPos.y();
    QPointF scenePos = mapToScene(event->pos());
    qDebug() << "Position de la souris dans la scène glob : " << scenePos.x() << ", " << scenePos.y();
}
