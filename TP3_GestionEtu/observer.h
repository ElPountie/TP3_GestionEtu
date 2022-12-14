#pragma once

/**
 * @brief abstract Observer class
*/
class Observer {
public:
  virtual ~Observer() {}
  virtual void update() = 0;
};
/**
 * @brief Abstract Observable class
*/
class Observable {
public:
  virtual ~Observable() {}
  virtual void addObserver(Observer* observer) = 0;
  virtual void removeObserver(Observer* observer) = 0;
  virtual void notifyObserver() const = 0;
};
