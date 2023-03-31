//
// Created by blue on 23/03/23.
//

#ifndef QTPROJECT_MYGRAPHICSVIEW_H
#define QTPROJECT_MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include "../Controller/SlotController.h"

class MyGraphicsView :public QGraphicsView {

    void mousePressEvent(QMouseEvent *event) override;

private:
    int row;
    int col;
    int colorSelect;

public:
    int getRow();
    void setRow(int row);
    int getCol();
    void setCol(int col);
    int getColorSelect();
    void setColorSelect(int colorselect);

    void UpdateColor();


};


#endif //QTPROJECT_MYGRAPHICSVIEW_H
