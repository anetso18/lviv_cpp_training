#include "board.h"
#include <iostream>
#include <thread>
#include <unordered_map>

Board::Board(int width, int height) : nextId_{1}, killAll_{false} {

    if (width <= 0 || height <= 0)
        throw std::invalid_argument("Width and Height parameters should be grater than 0.");
    board_.resize(height);
    for (int i = 0; i < (int)board_.size(); ++i)
    board_[i].resize(width);
}

Board::~Board() {
    for(auto& m: std::move(worms_.getMapper())){
     m.second.join();
    }
   }

void Board::addWorm(WormType type, int x, int y) {
  // TODO: Implement the body of the function. It should add a worm
  // into the board_ and start a new thread which will invoke
  // call operator - operator()(int) - defined in Worm class.
  // Note: there are a few class members (like wormTypes_) that need to be
  // updated as well to have full information about the worm that is being
  // added. They are usually based on worm's id which should be uniquely given
  // here.
     board_[x][y] = nextId_;
    if (type == Lazy)
    {
        LazyWorm w = LazyWorm(x,y,this);
        worms_.add(nextId_,std::thread(std::move(w),nextId_));
    }
    else
    {
        HunterWorm w = HunterWorm(x,y,this);
        worms_.add(nextId_,std::thread(std::move(w),nextId_));
    }
    wormTypes_[nextId_] = type;
    nextId_++;
}

void Board::update(int id, int oldX, int oldY, int newX, int newY) {
  std::lock_guard<std::mutex> lock(mut);
  if(checkKill(id))
       return;
  int targetId = board_[newX][newY];
  if (targetId != 0 && targetId != id)
  killed_.insert(targetId);
  board_[oldX][oldY] = 0;
  board_[newX][newY] = id;
}

bool Board::checkKill(int id) {
  return killAll_ || killed_.find(id) != killed_.end();
}

void Board::killAll() {
  killAll_ = true;
}

void Board::clearDead() {
  for (int i = 0; i < (int)board_.size(); ++i)
    for (int j = 0; j < (int)board_[0].size(); ++j)
      if (killed_.find(board_[i][j]) != killed_.end())
        board_[i][j] = 0;
}


