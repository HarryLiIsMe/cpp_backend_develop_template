#pragma once

#include <memory>

template <class T>
class SingleTon {
 public:
  inline static T& instance() {
    static T inst;
    return inst;
  }

 protected:
  SingleTon(void) {}
  virtual ~SingleTon(void) {}
  SingleTon(const SingleTon<T>&) = delete;
  SingleTon<T>& operator=(const SingleTon<T>&) = delete;
};

template <class T>
class PSingleTon {
 public:
  inline static std::shared_ptr<T> getInstance() {
    static std::shared_ptr<T> inst(new T());
    return inst;
  }

 protected:
  PSingleTon(void) {}
  virtual ~PSingleTon(void) {}
  PSingleTon(const PSingleTon<T>&) = delete;
  PSingleTon<T>& operator=(const PSingleTon<T>&) = delete;
};
