#include "texteditor.h"
#include <gtest/gtest.h>

// 1. Default constructor
TEST(TextEditorTest, DefaultConstructor)
{
    TextEditor editor;
    EXPECT_EQ(editor.deleteText(10), 0);
    EXPECT_EQ(editor.cursorLeft(5), "");
    EXPECT_EQ(editor.cursorRight(5), "");
}

// 2. String constructor
TEST(TextEditorTest, StringConstructor)
{
    TextEditor editor("Hello");
    EXPECT_EQ(editor.cursorLeft(5), "Hello");
}

// 3. Copy constructor
TEST(TextEditorTest, CopyConstructor)
{
    TextEditor editor1("Hello");
    TextEditor editor2(editor1);
    EXPECT_EQ(editor2.cursorLeft(5), "Hello");
}

// 4. Move constructor
TEST(TextEditorTest, MoveConstructor)
{
    TextEditor editor1("Hello");
    TextEditor editor2(std::move(editor1));
    EXPECT_EQ(editor2.cursorLeft(5), "Hello");
    EXPECT_EQ(editor1.cursorLeft(5), "");
}

// 5. Add text
TEST(TextEditorTest, AddText)
{
    TextEditor editor;
    editor.addText("Hello");
    EXPECT_EQ(editor.cursorLeft(5), "Hello");
}

// 6. Delete text
TEST(TextEditorTest, DeleteText)
{
    TextEditor editor("Hello");
    EXPECT_EQ(editor.deleteText(3), 3);
    EXPECT_EQ(editor.cursorLeft(2), "He");
}

// 7. Move cursor left
TEST(TextEditorTest, CursorLeft)
{
    TextEditor editor("Hello");
    EXPECT_EQ(editor.cursorLeft(3), "llo");
    EXPECT_EQ(editor.cursorLeft(5), "He");
}

// 8. Move cursor right
TEST(TextEditorTest, CursorRight)
{
    TextEditor editor("Hello");
    editor.cursorLeft(5);
    EXPECT_EQ(editor.cursorRight(3), "Hel");
}

// 9. Combined actions
TEST(TextEditorTest, CombinedActions)
{
    TextEditor editor;
    editor.addText("HelloWorld");
    EXPECT_EQ(editor.cursorLeft(5), "World");
    EXPECT_EQ(editor.deleteText(3), 3);
    EXPECT_EQ(editor.cursorRight(2), "Wo");
}

// 10. Delete more than exists
TEST(TextEditorTest, DeleteMoreThanExists)
{
    TextEditor editor("Hi");
    EXPECT_EQ(editor.deleteText(10), 2);
    EXPECT_EQ(editor.cursorLeft(1), "");
}
