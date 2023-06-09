#include <QCoreApplication>
#include <iostream>
#include "AbstractFactory.cpp"

// Функция для создания класса с использованием указанной фабрики
void createAndCompileClass(const std::shared_ptr<ProgrammFactory>& factory) {
    // Создание объектов классов, методов и операторов вывода с использованием фабрики
    std::shared_ptr<ClassUnit> classUnit = factory->createClassUnit("testClass");
    std::shared_ptr<MethodUnit> methodUnit1 = factory->createMethodUnit("testFunc1", "void", 1);
    std::shared_ptr<MethodUnit> methodUnit2 = factory->createMethodUnit("testFunc2", "void", 0);
    std::shared_ptr<MethodUnit> methodUnit3 = factory->createMethodUnit("testFunc3", "void", 0);
    std::shared_ptr<PrintOperatorUnit> printOperatorUnit = factory->createPrintOperatorUnit(R"(Hello, world!\n)");

    methodUnit2->add(printOperatorUnit);

    classUnit->add(methodUnit1, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit2, ClassUnit::AccessModifier::PUBLIC);
    classUnit->add(methodUnit3, ClassUnit::AccessModifier::PUBLIC);

    std::cout << classUnit->compile() << std::endl;
}

int main() {

    std::shared_ptr<ProgrammFactory> factoryCpp = std::make_shared<ProgrammFactoryCpp>();
    std::shared_ptr<ProgrammFactory> factoryCsharp = std::make_shared<ProgrammFactoryCsharp>();
    std::shared_ptr<ProgrammFactory> factoryJava = std::make_shared<ProgrammFactoryJava>();

    std::cout << "Class on c++:" << std::endl << std::endl;
    // Использование функции createAndCompileClass с указателем на фабрику для C++
    createAndCompileClass(factoryCpp);

    std::cout << "Class on c#:" << std::endl << std::endl;
    // Использование функции createAndCompileClass с указателем на фабрику для C#
    createAndCompileClass(factoryCsharp);

    std::cout << "Class on Java:" << std::endl << std::endl;
    // Использование функции createAndCompileClass с указателем на фабрику для Java
    createAndCompileClass(factoryJava);

    return 0;
}
