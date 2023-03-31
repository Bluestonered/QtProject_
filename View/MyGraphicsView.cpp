//
// Created by blue on 23/03/23.
//

#include <iostream>
#include "MyGraphicsView.h"
#include "QDebug"
#include "QMouseEvent"
#include "QGraphicsItem"

void MyGraphicsView::mousePressEvent(QMouseEvent *event) {
    QPointF pos = mapToScene(event->pos());

    int row = pos.y() / 95;
    int col = pos.x() / 95;

    std::cout << row << std::endl;
    std::cout << col << std::endl;
}
