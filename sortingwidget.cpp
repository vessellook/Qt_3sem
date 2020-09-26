#include "sortingwidget.h"
#include <QState>
#include <QPropertyAnimation>
#include <QVariant>

SortingWidget::SortingWidget(QWidget *parent) : QWidget(parent) {
    photo = new QLabel(this);
    photo->setGeometry(0, 0, 40, 40);
    photo->setScaledContents(true);
    photo->setPixmap(QPixmap("D:/download/avatar.jpg"));
    /* creating 2 states */
    QState* st1 = new QState();
    QState* st2 = new QState();

    /* defining photo's properties for each of them */
    st1->assignProperty(photo, "geometry", QRect( 0, 0, 40, 40));
    st2->assignProperty(photo, "geometry", QRect(50, 50, 200, 200));

    /* define transitions between states by clicking on main window*/
    st1->addTransition(this, SIGNAL(clicked()), st2);
    st2->addTransition(this, SIGNAL(clicked()), st1);

    /* adding states to state machine */
    machine.addState(st1);
    machine.addState(st2);
    machine.setInitialState(st1);
    QPropertyAnimation *an = new QPropertyAnimation(photo, "geometry");
    machine.addDefaultAnimation(an);
    /* starting machine */
    machine.start();
}

void SortingWidget::mouseReleaseEvent(QMouseEvent *) {
    emit clicked();
}
