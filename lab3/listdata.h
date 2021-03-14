#ifndef LISTDATA_H
#define LISTDATA_H

#include <QString>

struct IMaybeIcon {
    virtual bool hasIcon() const = 0;
    virtual QString icon() const = 0;
};

struct IText {
    virtual QString text() const = 0;
};

struct AbstractListItem : IText, IMaybeIcon {};

#endif // LISTDATA_H
