#### static_cast

用于执行非多态类型的转换,如基本数据类型间的转换,向上转型及避免隐式类型转换.  

```cpp
double douNum = 3.14;
int intNum = static_cast<int>(a);
```

​    

#### dynamic_cast

用于在多态类型间进行安全的向下转型,即将基类指针或引用转换为派生类指针或引用,

```cpp
class Base{
    public:
    	virtual void foo() {}
};

class Derived : public Base {
    public:
    	void bar() {}
};

Base *basePtr = new Derived;
Derived *derivedPtr = dynamic_cast<Derived>(basePtr);
```



#### const_cast

用于移除表达式的const性质.通常用于在函数中去除const性质,或使常量指针/引用可以修改其指向的值.

```cpp
// ptr -> 通过修改*b进行修改a的值
const int a = 10;
int *b = const_cast<int*>(&a);
// ref -> 通过修改d进行修改a的值
const int c = 10;
int &d = const_cast<int&>(c);
```



#### reinterpret_cast

用于对指针值进行位模式上的转换,也用于自上下文无关的类型转换,通常被认为是不安全的转换.可以将一个指针转换为一个整数,也可以将一个整数转换为一个指针.

```cpp
int *intPtr = new int(65);
char *charPtr = reinterpret_cast<char*>(intPtr);
```

