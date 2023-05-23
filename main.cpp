#include <QCoreApplication>
#include <iostream>
#include "Base/ClassUnit.cpp"
#include "Base/MethodUnit.cpp"
#include "PrintOperatorUnit.cpp"
#include "CppClassUnit.cpp"
#include "CppMethodUnit.cpp"
#include "JavaMethodUnit.cpp"
#include "CsharpClassUnit.cpp"

int main(int argc, char *argv[]) {



    // 1. Пример для языка программирования C#:


    // Создается объект csharpClass класса CsharpClassUnit с именем "CsharpClass"
    CsharpClassUnit csharpClass("CsharpClass");
    // Создается QMap под названием csharpMethods, который ассоциирует указатели на объекты
    // MethodUnit с AccessModifier
    QMap<std::shared_ptr<Unit>, CsharpClassUnit::AccessModifier> csharpMethods;
    // В csharpMethods добавляются различные методы с их модификаторами доступа
    csharpMethods.insert(std::make_shared<MethodUnit>("testFunc1", "void", 0),
                         CsharpClassUnit::PUBLIC);
    csharpMethods.insert(std::make_shared<MethodUnit>("testFunc2", "void", MethodUnit::STATIC),
                         CsharpClassUnit::PRIVATE);
    csharpMethods.insert(std::make_shared<MethodUnit>("testFunc3", "void", MethodUnit::FINAL | MethodUnit::CONST),
                         CsharpClassUnit::FILE);

    // Проходится циклом по методам в csharpMethods, и каждый метод добавляется в csharpClass с
    // соответствующим модификатором.
    for (std::shared_ptr<Unit> method: csharpMethods.keys()) {
        csharpClass.add(method, csharpMethods.value(method));
    }
    // Создается объект csharpMethod класса MethodUnit с именем "testFunc4" и модификатором
    // MethodUnit::STATIC. В него добавляется объект PrintOperatorUnit с текстом "Hello, world!\n"
    // auto позволяет компилятору самостоятельно определить тип переменной csharpMethod на основе
    // возвращаемого значения функции std::make_shared<MethodUnit>()
    auto csharpMethod = std::make_shared<MethodUnit>("testFunc4", "void",
                                                     MethodUnit::STATIC);
    csharpMethod->add(std::make_shared<PrintOperatorUnit>(R"(Hello, world!\n)"));
    // csharpMethod добавляется в csharpClass с модификатором ClassUnit::PROTECTED
    csharpClass.add(csharpMethod, ClassUnit::PROTECTED);

    // Затем вызывается метод compile(), и результат выводится на консоль
    std::cout << csharpClass.compile() << std::endl;



    // 2. Пример для языка программирования Java:


    // Создается объект javaClass класса ClassUnit с именем "JavaClass"
    ClassUnit javaClass("JavaClass");
    // Создается QMap под названием javaMethods, который ассоциирует указатели на объекты
    // JavaMethodUnit с AccessModifier
    QMap<std::shared_ptr<Unit>, ClassUnit::AccessModifier> javaMethods;
    // В javaMethods добавляются различные методы с их модификаторами доступа
    javaMethods.insert(std::make_shared<JavaMethodUnit>("testFunc1", "void", 0),
                       ClassUnit::PUBLIC);
    javaMethods.insert(std::make_shared<JavaMethodUnit>("testFunc2", "void", JavaMethodUnit::STATIC),
                       ClassUnit::PRIVATE);
    javaMethods.insert(std::make_shared<JavaMethodUnit>("testFunc3", "void", JavaMethodUnit::ABSTRACT | JavaMethodUnit::CONST),
                       ClassUnit::PUBLIC);

    // Проходится циклом по методам в javaMethods, и каждый метод добавляется в javaClass с
    // соответствующим модификатором
    for (std::shared_ptr<Unit> method: javaMethods.keys()) {
        javaClass.add(method, javaMethods.value(method));
    }
    // Создается объект javaMethod класса MethodUnit с именем "testFunc4" и модификатором
    // MethodUnit::STATIC. В него добавляется объект PrintOperatorUnit с текстом "Hello, world!\n"
    auto javaMethod = std::make_shared<MethodUnit>("testFunc4", "void",
                                                   MethodUnit::STATIC);
    javaMethod->add(std::make_shared<PrintOperatorUnit>(R"(Hello, world!\n)"));
    // javaMethod добавляется в javaClass с модификатором ClassUnit::PROTECTED
    javaClass.add(javaMethod, ClassUnit::PROTECTED);

    //Затем вызывается метод compile(), и результат выводится на консоль
    std::cout << javaClass.compile() << std::endl;



    // 3. Пример для языка программирования C++:


    //Создается объект cppClass класса CppClassUnit с именем "CppClass"
    CppClassUnit cppClass("CppClass");
    // Создается QMap под названием cppMethods, который ассоциирует указатели на объекты
    // CppMethodUnit с AccessModifier
    QMap<std::shared_ptr<Unit>, CppClassUnit::AccessModifier> cppMethods;
    // В cppMethods добавляются различные методы с их модификаторами доступа
    cppMethods.insert(std::make_shared<CppMethodUnit>("testFunc1", "void", 0), CppClassUnit::PUBLIC);
    cppMethods.insert(std::make_shared<CppMethodUnit>("testFunc2", "void", CppMethodUnit::STATIC), CppClassUnit::PRIVATE);
    cppMethods.insert(std::make_shared<CppMethodUnit>("testFunc3", "void", CppMethodUnit::CONST | CppMethodUnit::VIRTUAL),
                      CppClassUnit::PUBLIC);

    // Проходится циклом по методам в cppMethods, и каждый метод добавляется в cppClass с
    // соответствующим модификатором
    for (std::shared_ptr<Unit> method: cppMethods.keys()) {
        cppClass.add(method, cppMethods.value(method));
    }
    // Создается объект cppMethod класса MethodUnit с именем "testFunc4" и модификатором
    // MethodUnit::STATIC. В него добавляется объект PrintOperatorUnit с текстом "Hello, world!\n"
    auto cppMethod = std::make_shared<MethodUnit>("testFunc4", "void",
                                                  MethodUnit::STATIC);
    cppMethod->add(std::make_shared<PrintOperatorUnit>(R"(Hello, world!\n)"));
    // cppMethod добавляется в cppClass с модификатором ClassUnit::PROTECTED
    cppClass.add(cppMethod, ClassUnit::PROTECTED);

    // Затем вызывается метод compile(), и результат выводится на консоль
    std::cout << cppClass.compile() << std::endl;

    return 0;
}
