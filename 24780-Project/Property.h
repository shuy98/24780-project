#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>

class Property {
  private:
    const std::string name;
    int ownerID;
    int price;
    int rent;
    int position;

  public:
    Property(std::string name, int price, int rent, int pos)
        : name(name), price(price), rent(rent), position(pos) {
        ownerID = -1;
    }
    std::string getName() const { return name; }
    int getPrice() const { return price; }
    void upgradeRent() { rent = rent * 2; }
    int getRent() const { return rent; }
    int getOwnerID() const { return ownerID; }
    void setOwnerID(int id) { ownerID = id; }
    int getPosition() const { return position; }
};

#endif