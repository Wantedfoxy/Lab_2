#include "Base/MethodUnit.cpp"

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        FINAL = 1 << 2,
        ABSTRACT = 1 << 3,
    };

    // Конструктор класса CppMethodUnit, name - имя метода, returnType - Тип возвращаемого значения
    // flags - Флаги для определения модификаторов метода
    // Конструктор передает эти значения базовому классу MethodUnit для инициализации имени метода,
    // типа возвращаемого значения и флагов
    explicit JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}

    // Метод для формирования строкового представления метода со всеми его подэлементами,
    // учитывая модификаторы доступа и вложенность, level Уровень вложенности элемента
    std::string compile(unsigned int level = 0) const override {
        // Создание переменной, которая будет содержать сгенерированный результат, добавляем отступ,
        // зависящий от вложенности
        std::string result = generateShift(level);
        // Если флаг ABSTRACT в m_flags установлен, то добавляется ключевое слово abstract
        if (m_flags & ABSTRACT) {
            result += "abstract ";
        }
        // Затем вызывается метод MethodUnit::compile(level), чтобы сгенерировать код для базового
        // метода MethodUnit
        result += MethodUnit::compile(level);
        return result;
    }
};
