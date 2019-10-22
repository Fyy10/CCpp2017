# C++学习笔记

# 记录你学习过程中的所见所思！酸甜苦辣！

# 看什么看！ 赶紧填坑啊！ 

模板类的实现必须放在头文件里，因为只有在使用模板类的cpp文件中确定了模板的类型，才能生成相应的库文件。如果模板的实现放在另一个cpp文件里，由于无法确定数据类型，直接编译生成的.o文件中并不会有模板的实现，因此会造成模板类的函数在链接时出现“未定义的引用”等问题。

为模板类重载`<<`运算符，有以下两种方法（因为`<<`运算符实际上是cout的成员函数，在Myclass类外无法访问私有成员，所以设置为友元函数，当然也可以用Myclass的public成员函数获取私有成员数据，此时则不需要设置为友元函数）：

类内定义：

```cpp
template <class T>
class Myclass
{
	//private
public:
	//public member functions
	friend ostream& operator<<(ostream& out, Myclass<T> const& mc)
	{
		//output
		return out;
	}
};
```

类外定义：

```cpp
template <class T> class Myclass;
template <class T> ostream& operator<<(ostream&, Myclass<T>&);

template <class T>
class Myclass
{
public:
	//...
	friend ostream& operator<< <T>(ostream&, Myclass<T>&);
};

template <class T>
ostream& operator<<(ostream& out, Myclass<T> mc)
{
	//output
	return out;
}
```

或者是

```cpp
template <class>
class Myclass
{
	//private
public:
	template <typename J>
	friend ostream& operator<<(ostream& out, Myclass<J>);
};

template <typename J>
ostream& operator<<(ostream& out, Myclass<J> mc)
{
	//output
	return out;
}
```
