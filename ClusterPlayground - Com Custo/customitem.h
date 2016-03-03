#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QGraphicsItem>
#include <string>

class CustomItem : public QGraphicsItem
{
public:
    CustomItem(QGraphicsItem *parent);
    virtual std::string getName();
    virtual bool isClickable();
};

#endif // CUSTOMITEM_H
