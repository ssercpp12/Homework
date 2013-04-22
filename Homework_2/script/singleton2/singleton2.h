#ifndef _WH_SINGLETON_H_
#define _WH_SINGLETON_H_

/* disallow copy constructor and assignment operator */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

class Singleton {
  public:
    static Singleton& GetInstance();
    static bool DeleteInstance();
    void SetValue(int value);
    int GetValue();
  private:
    int value_;
    ~Singleton() {}
    Singleton() {}
    static Singleton* instance_;
    DISALLOW_COPY_AND_ASSIGN(Singleton);
};

#endif  // _WH_SINGLETON_H_
