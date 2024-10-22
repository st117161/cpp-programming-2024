# TextEditor

This is a simple text editor implemented in C++ as part of my homework at Saint Petersburg University (SPbU) for the thirty semester of programming. The editor allows users to manipulate text using a cursor with various functionalities.

## Features

- **Add Text**: Insert text at the current cursor position.
- **Delete Text**: Remove text from the current cursor position, simulating the "Backspace" key.
- **Move Cursor**: Shift the cursor position left or right by a specified number of characters.
- **Display Text**: View the text with the cursor indicated by a special symbol.

## Functions

- `TextEditor()`: Initializes the editor without any text.
- `void addText(std::string text)`: Adds text at the current cursor position.
- `int deleteText(int k)`: Deletes `k` characters to the left of the cursor and returns the number of characters deleted.
- `std::string cursorLeft(int k)`: Moves the cursor left by `k` characters and returns the text to the left of the cursor.
- `std::string cursorRight(int k)`: Moves the cursor right by `k` characters and returns the text to the right of the cursor.

## Requirements

- C++17 or later
- g++ compiler

## Build Instructions

To build the project, run the following commands in your terminal:

```bash
make
```
This will compile the code and generate the executable file TextEditor.

## Clean Up

To remove the object files and the compiled executable, run:

```bash
make clean
```
##License

This project is licensed under the Apache-2.0 License - see the [LICENSE](LICENSE) file for details.
