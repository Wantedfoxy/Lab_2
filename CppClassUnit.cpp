#pragma once

#include "Base/ClassUnit.cpp"

class CppClassUnit : public ClassUnit {
public:
    // Конструктор, который принимает строку name в качестве аргумента и передает ее базовому
    // классу ClassUnit для инициализации имени класса
    explicit CppClassUnit(const std::string &name) : ClassUnit(name) {}

    // Метод для формирования строкового представления класса со всеми его подэлементами,
    // учитывая модификаторы доступа и вложенность, level Уровень вложенности элемента
    std::string compile(unsigned int level = 0) const override {
        // Создание переменной, которая будет содержать сгенерированный результат
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        // Цикл, который проходит по доступным модификаторам класса
        for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
            // Если вектор, содержащий подэлементы класса для текущего модификатора, пуст, то
            // пропускается текущая итерация цикла
            if (m_fields[i].empty()) {
                continue;
            }
            // Если есть поля для текущего модификатора, то в строку result добавляется ключевое
            // слово модификатора (public:, protected:, private:) для разделения секций полей.
            result += ACCESS_MODIFIERS[i] + ":\n";
            // Затем происходит обход каждого поля в текущей секции. Для каждого поля вызывается
            // метод compile для генерации кода этого поля.
            for (const auto &f: m_fields[i]) {
                result += f->compile(level + 1) + "\n";
            }
            // После завершения обхода полей каждого модификатора добавляется пустая строка для
            // разделения секций полей
            result += "\n";
        }
        // Формируется строка окончания класса
        result += generateShift(level) + "};\n";
        return result;
    }
};
