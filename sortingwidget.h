#ifndef SORTINGWIDGET_H
#define SORTINGWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QStateMachine>

class SortingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SortingWidget(QWidget *parent = nullptr);


signals:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QStateMachine machine;
    QLabel *photo;
};

#endif // SORTINGWIDGET_H
