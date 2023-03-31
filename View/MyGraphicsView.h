//
// Created by blue on 23/03/23.
//

#ifndef QTPROJECT_MYGRAPHICSVIEW_H
#define QTPROJECT_MYGRAPHICSVIEW_H

#include <QGraphicsView>

class MyGraphicsView :public QGraphicsView {

    void mousePressEvent(QMouseEvent *event) override;


};


#endif //QTPROJECT_MYGRAPHICSVIEW_H
