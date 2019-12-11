# Design-patterns
　　设计模式及常见案例
# 什么是设计模式
　　每个模式都描述了一个在我们的环境中不断出现的问题，然后描述了该问题的解决方案的核心，通过这种方式，我们可以无数次地重用那些已有的成功的解决方案，无须再重复相同的工作。
# 基本要素
一般而言，一个模式含有四个基本要素：
- 模式名称（Pattern Name）：用词来描述模式的问题、解决方案和效果；
- 问题（Problem）：描述在何时使用模式；
- 解决方案（Solution）：描述设计的组成成分；
- 效果（Consequences）：描述模式应用的效果及使用模式应权衡的问题。


# 面向对象设计原创表
- 单一职责原则（Single Responsibility Principle, SRP）

　　类的职责单一，对外只提供一种功能，而引起类变化的原因都应该只有一个。
- [开闭原则(Open-Closed Principle, OCP)](https://github.com/SherDick/Design-patterns/tree/master/Open%20Closed%20Principle-%E5%BC%80%E9%97%AD%E5%8E%9F%E5%88%99)

　　类的改动是通过增加代码进行的，而不是修改源代码。
- 里氏代换原则(Liskov Substitution Principle, LSP）


　　任何抽象类出现的地方都可以用他的实现类进行替换，实际就是虚拟机制，语言级别实现面向对象功能。
- 依赖倒转原则(Dependence Inversion Principle, DIP)


　　依赖于抽象(接口)，不要依赖具体的实现(类)，也就是针对接口编程。
- 接口隔离原则(Interface Segregation Principle, ISP）

　　不应该强迫用户的程序依赖他们不需要的接口方法。一个接口应该只提供一种对外功能，不应该把所有操作都封装到一个接口中去。
- 合成复用原则(Composite Reuse Principle, CRP)

　　如果使用继承，会导致父类的任何变换都可能影响到子类的行为。如果使用对象组合，就降低了这种依赖关系。对于继承和组合，优先使用组合。
- 迪米特法则(Law of Demeter, LoD）

　　一个对象应当对其他对象尽可能少的了解，从而降低各个对象之间的耦合，提高系统的可维护性。例如在一个程序中，各个模块之间相互调用时，通常会提供一个统一的接口来实现。这样其他模块不需要了解另外一个模块的内部实现细节，这样当一个模块内部的实现发生改变时，不会影响其他模块的使用。（黑盒原理）


# 准则分类
根据两条准则对模式进行分类：
- 目的准则：模式用来完成什么工作的。
- 范围准则：模式主要是用于类还是用于对象。
![test](https://github.com/SherDick/Design-patterns/raw/master/Pictures/PatternClassification.png)


## 1. 创建型(Creational	Patterns)
　　通过“对象创建” 模式绕开new，来避免对象创建（new）过程中所导致的紧耦合（依赖具体类），从而支持对象创建的稳定。它是接口抽象之后的第一步工作。

### 典型模式
[Factory Method](https://github.com/SherDick/Design-patterns/tree/master/Factory%20Method%20Pattern-%E5%B7%A5%E5%8E%82%E6%96%B9%E6%B3%95%E6%A8%A1%E5%BC%8F)


[Abstract Factory](https://github.com/SherDick/Design-patterns/tree/master/Abstract%20Factory-%E6%8A%BD%E8%B1%A1%E5%B7%A5%E5%8E%82%E6%A8%A1%E5%BC%8F)


Prototype


[Builder](https://github.com/SherDick/Design-patterns/tree/master/Builder-%E7%94%9F%E6%88%90%E5%99%A8)


## 2. 结构型(Structural	Patterns)

### 典型模式

Bridge

Composite

Decorator

Facade

Flyweight

Proxy

## 3. 行为型(Behavioral	Patterns)

### 典型模式

Chain of Responsibility

Command

Mediator

Memento

Observer

Registry

State

Strategy

Template

Visitor