#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <stack>
#include <string>

class TextEditor {
    public:
    TextEditor();
    TextEditor(std::string ourString);
    TextEditor(const TextEditor &text);
    TextEditor(TextEditor &&text);
    ~TextEditor();
    void addText(const std::string &text);
    int deleteText(int k);
    std::string cursorLeft(int k);
    std::string cursorRight(int k);

    friend std::ostream &operator<<(std::ostream &stream, const TextEditor &texteditor)
    {
        // Копируем стеки, чтобы не менять их порядок
        std::stack<std::string> leftCopy = texteditor.left;
        std::stack<std::string> rightCopy = texteditor.right;

        // Выводим символы слева от курсора в правильном порядке
        std::stack<std::string> reverseLeft;
        while (!leftCopy.empty())
        {
            reverseLeft.push(leftCopy.top());
            leftCopy.pop();
        }

        while (!reverseLeft.empty())
        {
            stream << reverseLeft.top();
            reverseLeft.pop();
        }

        // Выводим курсор
        stream << "\033[31m|\033[0m";

        // Выводим символы справа от курсора
        while (!rightCopy.empty())
        {
            stream << rightCopy.top();
            rightCopy.pop();
        }

        return stream;
    }
    friend TextEditor operator+(const TextEditor &lhs, const TextEditor &rhs)
    {
        // Создаем новый объект TextEditor, который будет результатом сложения
        TextEditor result(lhs);

        // Обрабатываем текст справа от курсора правого операнда (rhs)
        std::stack<std::string> rightCopy = rhs.right; // Копируем правый стек для сохранения оригинала
        std::stack<std::string> reversedRight;

        // Перевернем правый стек для правильного добавления текста в порядке
        while (!rightCopy.empty())
        {
            reversedRight.push(rightCopy.top());
            rightCopy.pop();
        }

        // Добавляем перевёрнутый текст в правую часть результирующего редактора
        while (!reversedRight.empty())
        {
            result.addText(reversedRight.top());
            reversedRight.pop();
        }

        return result;
    }

    private:
    std::stack<std::string> left;
    std::stack<std::string> right;
    int positionCursor;
    int size;
};

#endif // TEXTEDITOR_H
