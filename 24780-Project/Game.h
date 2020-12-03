#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Property.h"
#include <iostream>
#include <vector>

#define DEFAULT_BALANCE 600
#define PROPERTY_AMOUNT 4

enum class TileType { START, EARN_MONEY, LOSE_MONEY, PROPERTY, EMPTY, UNKNOWN };

class Game {
  private:
    int playerNum;
    std::vector<Player> players;
    std::vector<Property> properties;
    int currPlayerID;

  public:
    Game(int playerNumbers) {
        currPlayerID = 0;
        playerNum = playerNumbers;
        for (int i = 0; i < playerNum; i++) {
            players.push_back(Player(i, DEFAULT_BALANCE));
            switch (i) {
            case 0:
                players.at(i).setPlayerName("Panda");
                break;
            case 1:
                players.at(i).setPlayerName("Rabbit");
                break;
            case 2:
                players.at(i).setPlayerName("Squirrel");
                break;
            case 3:
                players.at(i).setPlayerName("Monkey");
                break;
            default:
                break;
            }
        }
        properties.push_back(Property("Company", 100, 50, 2));
        properties.push_back(Property("Water Works", 100, 50, 6));
        properties.push_back(Property("Park Place", 100, 50, 9));
        properties.push_back(Property("Fifth Ave", 100, 50, 15));
        properties.push_back(Property("Forbes Ave", 100, 50, 18));
    }
    int getCurrPlayerID() const { return currPlayerID; }
    Player getCurrPlayer() { return players.at(currPlayerID); }
    Property getProperty(int propertyPos) {
        for (Property &p : properties) {
            if (propertyPos == p.getPosition()) {
                return p;
            }
        }
    }
    void nextPlayer() {
        currPlayerID++;
        if (currPlayerID >= playerNum) {
            currPlayerID = 0;
        }
    }
    std::vector<Player> getPlayers() { return players; }
    std::vector<Property> getProperties() { return properties; }
    void setPlayerBalance(int playerID, int num) {
        for (Player &p : players) {
            if (playerID == p.getID()) {
                p.setBalance(num);
                std::cout << playerID << " balance: " << p.getBalance()
                          << std::endl;
                return;
            }
        }
    }
    void setPropertyOwner(int propertyPos, int ownerID) {
        for (Property &p : properties) {
            if (propertyPos == p.getPosition()) {
                p.setOwnerID(ownerID);
                return;
            }
        }
    }
    void upgradePropertyRent(int propertyPos) {
        for (Property &p : properties) {
            if (propertyPos == p.getPosition()) {
                p.upgradeRent();
                return;
            }
        }
    }
    void setLastLocation(int playerID, int pos, int steps) {
        for (Player &p : players) {
            if (currPlayerID == p.getID()) {
                p.setLastPosition(pos);
                p.setLastTotalSteps(steps);
                return;
            }
        }
    }
    void movePlayer(int playerID, int steps) {
        for (Player &p : players) {
            if (currPlayerID == p.getID()) {
                p.move(steps);
                return;
            }
        }
    }
    TileType getTileType(int position) const {
        TileType result = TileType::UNKNOWN;
        switch (position) {
        case 0:
            result = TileType::START;
            break;
        case 1:
        case 4:
        case 12:
        case 16:
            result = TileType::EARN_MONEY;
            break;
        case 2:
        case 6:
        case 9:
        case 15:
        case 18:
            result = TileType::PROPERTY;
            break;
        case 3:
        case 5:
        case 8:
        case 11:
        case 14:
        case 17:
            result = TileType::EMPTY;
            break;
        case 7:
        case 10:
        case 13:
        case 19:
            result = TileType::LOSE_MONEY;
            break;
        default:
            std::cout << "Unkown tile type" << std::endl;
            break;
        }
        return result;
    }
};

#endif GAME_H