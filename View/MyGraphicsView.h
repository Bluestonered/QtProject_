//
// Created by blue on 23/03/23.
//

#ifndef QTPROJECT_MYGRAPHICSVIEW_H
#define QTPROJECT_MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include "../Controller/SlotController.h"
#include "../Model/SlotModel.h"

class MyGraphicsView :public QGraphicsView {

Q_OBJECT

    void mousePressEvent(QMouseEvent *event) override;

private:
    int row;
    int col;
    int colorSelect;

signals:
    void cellClicked(int row, int col);

public:
    int getRow();
    void setRow(int row);
    int getCol();
    void setCol(int col);
    int getColorSelect();
    void setColorSelect(int colorselect);


};


#endif //QTPROJECT_MYGRAPHICSVIEW_H
