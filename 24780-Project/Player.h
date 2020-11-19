#ifndef PLAYER_H
#define PLAYER_H

class Player {
  private:
    int balance;
    int position;
    int totalSteps;
    int playerID;

  public:
    Player(int id, int balance)
        : playerID(id), balance(balance), position(0), totalSteps(0) {}
    int getID() const { return playerID; }
    int getBalance() const { return balance; }
    void setBalance(int num) { balance = num; }
    void move(int steps) {
        position = (position + steps) % 20;
        totalSteps += steps;
    }
    int getPassNum() const { return totalSteps % 20; }
    int getPosition() const { return position; }
};

#endif