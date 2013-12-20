#ifndef _SINGLETON_H_
#define _SINGLETON_H_

/* Generic template for a singleton class */
template <class T> class Singleton
{
  public:
    static T& GetInstance() {
      static T _instance;
      return _instance;
    }
  private:
    Singleton();
    ~Singleton();
    Singleton(Singleton const&);
    Singleton& operator=(Singleton const&);
};

#endif
