#include <QCoreApplication>
#include <iostream>
#include "Base/ClassUnit.cpp"
#include "Base/MethodUnit.cpp"
#include "CsharpClassUnit.cpp"
#include "CsharpPrintOperatorUnit.cpp"
#include "JavaMethodUnit.cpp"
#include "JavaPrintOperatorUnit.cpp"
#include "CppClassUnit.cpp"
#include "CppMethodUnit.cpp"
#include "CppPrintOperatorUnit.cpp"

// Объявление интерфейса ProgrammFactory
class ProgrammFactory {
public:
    virtual ~ProgrammFactory() {}
    // Методы создания объектов классов, методов и операторов вывода
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) = 0;
};

// Класс ProgrammFactoryCpp, реализующий конкретную фабрику для языка C++
class ProgrammFactoryCpp : public ProgrammFactory {
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CppClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) override {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

// Класс ProgrammFactoryCsharp, реализующий конкретную фабрику для языка C#
class ProgrammFactoryCsharp : public ProgrammFactory {
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<CsharpClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) override {
        return std::make_shared<MethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<CsharpPrintOperatorUnit>(text);
    }
};

// Класс ProgrammFactoryJava, реализующий конкретную фабрику для языка Java
class ProgrammFactoryJava : public ProgrammFactory {
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override {
        return std::make_shared<ClassUnit>(name);
    }

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, int flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }

    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};
