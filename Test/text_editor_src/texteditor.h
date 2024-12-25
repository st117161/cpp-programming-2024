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
        std::stack<std::string> leftCopy = texteditor.left;
        std::stack<std::string> rightCopy = texteditor.right;

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

        stream << "\033[31m|\033[0m";

        while (!rightCopy.empty())
        {
            stream << rightCopy.top();
            rightCopy.pop();
        }

        return stream;
    }
    friend TextEditor operator+(const TextEditor &lhs, const TextEditor &rhs)
    {
        TextEditor result(lhs);

        std::stack<std::string> rightCopy = rhs.right;
        std::stack<std::string> reversedRight;

        while (!rightCopy.empty())
        {
            reversedRight.push(rightCopy.top());
            rightCopy.pop();
        }

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
