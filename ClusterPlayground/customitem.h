#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QGraphicsItem>
#include <string>

class CustomItem : public QGraphicsItem
{
    bool m_clickeable;
public:
    CustomItem(QGraphicsItem *parent);
    virtual std::string getName();

    void setClickeable(bool);

    bool isClickeable();
};

#endif // CUSTOMITEM_H
