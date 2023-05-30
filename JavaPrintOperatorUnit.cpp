#pragma once

#include "Base/PrintOperatorUnit.cpp"

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    // Конструктор, который принимает строку text в качестве аргумента и инициализирует приватное
    // поле m_text значением этой строки. Поле m_text хранит текст, который будет выведен при
    // выполнении оператора печати
    explicit JavaPrintOperatorUnit(const std::string &text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }

private:
    std::string m_text;
};
