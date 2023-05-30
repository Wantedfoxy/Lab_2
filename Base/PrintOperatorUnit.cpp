#pragma once

#include "Base/Unit.cpp"

class PrintOperatorUnit : public Unit {
public:
    // Конструктор, который принимает строку text в качестве аргумента и инициализирует приватное
    // поле m_text значением этой строки. Поле m_text хранит текст, который будет выведен при
    // выполнении оператора печати

    virtual std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

private:
    std::string m_text;
};
