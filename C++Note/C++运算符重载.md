>若对象内包含指针，将造成不良后果:指针的值被丢弃了，但指针指向的内容并未释放。指针的值被复制了，但指针所指内容并未复制。 因此，包含动态分配成员的类除提供拷贝构造函数外，还应该考虑重载"="赋值操作符号。 

```
Base & operator = (const Base &base);/*声明*/
```

```
Base & Base::operator=(const Base & base)
{
	int *temp = new int(*base.p);  /*赋值指针指向的内容*/
	delete this->p;
	p = temp;
	return *this;
}
```