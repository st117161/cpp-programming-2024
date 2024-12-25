#include "texteditor.h"

TextEditor::TextEditor() : positionCursor(0), size(0) {}

TextEditor::TextEditor(const TextEditor &text)
    : left(text.left),
      right(text.right),
      positionCursor(text.positionCursor),
      size(text.size) {}

TextEditor::TextEditor(TextEditor &&text)
    : left(std::move(text.left)),
      right(std::move(text.right)),
      positionCursor(text.positionCursor),
      size(text.size) {
  text.positionCursor = 0;
  text.size = 0;
}
TextEditor::TextEditor(std::string ourString)
    : positionCursor(ourString.size()), size(ourString.size()) {
  for (char ch : ourString) {
    left.push(std::string(1, ch));
  }
}
TextEditor::~TextEditor() {}

void TextEditor::addText(const std::string &text) {
  for (char ch : text) {
    left.push(std::string(1, ch));
  }
  positionCursor += text.size();
  size += text.size();
}

int TextEditor::deleteText(int k)
{
    int deletedCount = 0;
    while (k > 0 && !left.empty())
    {
        left.pop();
        --k;
        --positionCursor;
        --size;
        ++deletedCount;
    }
    return deletedCount;
}

std::string TextEditor::cursorLeft(int k)
{
  std::string result;
  while (k > 0 && !left.empty()) {
    std::string top = left.top();
    left.pop();
    right.push(top);
    result = top + result;
    --k;
    --positionCursor;
    }
    return result;
}

std::string TextEditor::cursorRight(int k)
{
    std::string result;
    while (k > 0 && !right.empty())
    {
        std::string top = right.top();
        right.pop();
        left.push(top);
        result += top;
        --k;
        ++positionCursor;
    }
    return result;
}
