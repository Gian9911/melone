//
// Created by gianluca on 02/07/19.
//

#ifndef ZZ_ITEM_H
#define ZZ_ITEM_H


#include <string>

class Item {
public:


    Item();
    ~Item();


    virtual bool isActived();

    virtual std::string give1Name();

    virtual std::string give2name();



    int getType() const;

    void setType(int type);

    int getStrenght() const;

    void setStrenght(int strenght);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    void setActived(bool actived);

    const std::string &getSecondName() const;

    void setSecondName(const std::string &secondName);

private:
    int Type;
    int strenght;
    std::string firstName;
    std::string secondName;
    bool actived;







};


#endif //ZZ_ITEM_H
