#include <QCoreApplication>
#include <iostream>
#include "AbstractFactory.cpp"

int main() {
    // Создание и использование фабрик для создания объектов классов на разных языках программирования


    // Создаем фабрику для языка C++


    std::shared_ptr<ProgrammFactory> factoryCpp = std::make_shared<ProgrammFactoryCpp>();
    // Создаем фабрику для языка C#
    std::shared_ptr<ProgrammFactory> factoryCsharp = std::make_shared<ProgrammFactoryCsharp>();
    // Создаем фабрику для языка Java
    std::shared_ptr<ProgrammFactory> factoryJava = std::make_shared<ProgrammFactoryJava>();

    // Используем factoryCpp для создания объектов C++ классов
    // Создаем объект класса CppClassUnit с именем "CppClass"
    std::shared_ptr<ClassUnit> cppClass = factoryCpp->createClassUnit("CppClass");
    // Создаем объект метода MethodUnit с именем "testFunc" и возвращаемым типом "void" для C++
    std::shared_ptr<MethodUnit> cppMethod = factoryCpp->createMethodUnit("testFunc", "void", 0);
    // Создаем объект оператора PrintOperatorUnit с текстом "Hello, world!\n" для C++
    std::shared_ptr<PrintOperatorUnit> cppPrintOp = factoryCpp->createPrintOperatorUnit(R"(Hello, world!\n)");

    // Добавляем оператор PrintOperatorUnit в метод cppMethod
    cppMethod->add(cppPrintOp);
    // Добавляем метод cppMethod в класс cppClass с модификатором доступа CppClassUnit::AccessModifier::PUBLIC
    cppClass->add(cppMethod, CppClassUnit::AccessModifier::PUBLIC);

    // Компилируем и выводим на консоль код класса cppClass
    std::cout << cppClass->compile() << std::endl;


    // Используем factoryCsharp для создания объектов C# классов


    // Создаем объект класса CsharpClassUnit с именем "CsharpClass"
    std::shared_ptr<ClassUnit> csharpClass = factoryCsharp->createClassUnit("CsharpClass");
    // Создаем объект метода MethodUnit с именем "testFunc" и возвращаемым типом "void" для C#
    std::shared_ptr<MethodUnit> csharpMethod = factoryCsharp->createMethodUnit("testFunc", "void", 0);
    // Создаем объект оператора PrintOperatorUnit с текстом "Hello, world!\n" для C#
    std::shared_ptr<PrintOperatorUnit> csharpPrintOp = factoryCsharp->createPrintOperatorUnit(R"(Hello, world!\n)");

    // Добавляем оператор PrintOperatorUnit в метод csharpMethod
    csharpMethod->add(csharpPrintOp);
    // Добавляем метод csharpMethod в класс csharpClass с модификатором доступа CsharpClassUnit::AccessModifier::PUBLIC
    csharpClass->add(csharpMethod, CsharpClassUnit::AccessModifier::PUBLIC);

    // Компилируем и выводим на консоль код класса csharpClass
    std::cout << csharpClass->compile() << std::endl;


    // Используем factoryJava для создания объектов Java классов


    // Создаем объект класса JavaClassUnit с именем "JavaClass"
    std::shared_ptr<ClassUnit> javaClass = factoryJava->createClassUnit("JavaClass");
    // Создаем объект метода MethodUnit с именем "testFunc" и возвращаемым типом "void" для Java
    std::shared_ptr<MethodUnit> javaMethod = factoryJava->createMethodUnit("testFunc", "void", 0);
    // Создаем объект оператора PrintOperatorUnit с текстом "Hello, world!\n" для Java
    std::shared_ptr<PrintOperatorUnit> javaPrintOp = factoryJava->createPrintOperatorUnit(R"(Hello, world!\n)");

    // Добавляем оператор PrintOperatorUnit в метод javaMethod
    javaMethod->add(javaPrintOp);
    // Добавляем метод javaMethod в класс javaClass с модификатором доступа ClassUnit::AccessModifier::PUBLIC
    javaClass->add(javaMethod, ClassUnit::AccessModifier::PUBLIC);

    // Компилируем и выводим на консоль код класса javaClass
    std::cout << javaClass->compile() << std::endl;

    return 0;
}
