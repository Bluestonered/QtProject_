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

    setCol(col);
    setRow(row);

    emit cellClicked(row, col);


    QGraphicsRectItem *rectItem = dynamic_cast<QGraphicsRectItem*>(scene()->itemAt(pos, QTransform()));
    if (rectItem != nullptr) {
        switch (colorSelect) {
            case 0:
                rectItem->setBrush(QBrush(Qt::darkGreen));
                break;
            case 1:
                rectItem->setBrush(QBrush(Qt::darkGray));
                break;
            case 2:
                rectItem->setBrush(QBrush(Qt::darkBlue));
                break;
            case 3:
                rectItem->setBrush(QBrush(Qt::darkYellow));
                break;
            default:
                rectItem->setBrush(QBrush(Qt::darkGreen));
                break;
        }
    }


}

int MyGraphicsView::getCol() {
    return col;
}

void MyGraphicsView::setCol(int colA) {
    col = colA;
}

int MyGraphicsView::getRow() {
    return row;
}

void MyGraphicsView::setRow(int rowA) {
    row = rowA;
}

int MyGraphicsView::getColorSelect() {
    return colorSelect;
}

void  MyGraphicsView::setColorSelect(int colorselect) {
    colorSelect = colorselect;
}
