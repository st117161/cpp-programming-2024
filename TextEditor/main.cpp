#include "helper.h"
#include "texteditor.h"

int main(int argc, char *argv[])
{
    TextEditor editor;
    int choice;

    do
    {
        std::cout << "\n==========================\n";
        std::cout << "       TEXT EDITOR     \n";
        std::cout << "==========================\n";
        std::cout << "  1. Добавить текст\n";
        std::cout << "  2. Удалить текст\n";
        std::cout << "  3. Переместить курсор влево\n";
        std::cout << "  4. Переместить курсор вправо\n";
        std::cout << "  5. Вывести текст\n";
        std::cout << "  6. Выход\n";
        std::cout << "==========================\n";
        std::cout << "Введите ваш выбор: ";
        correct(choice);

        switch (choice)
        {
        case 1: {
            std::string text;
            std::cout << "\nВведите текст для добавления: ";
            std::cin.ignore();
            std::getline(std::cin, text);
            editor.addText(text);
            std::cout << "\nТекст успешно добавлен!\n";
            break;
        }
        case 2: {
            int k;
            std::cout << "\nВведите количество символов для удаления: ";
            correct(k);
            int deletedCount = editor.deleteText(k);
            std::cout << "Удалено " << deletedCount << " символов\n";
            break;
        }
        case 3: {
            int k;
            std::cout << "\nВведите количество символов для перемещения влево: ";
            correct(k);
            std::string leftText = editor.cursorLeft(k);
            std::cout << "Текст слева от курсора: " << leftText << "\n";
            break;
        }
        case 4: {
            int k;
            std::cout << "\nВведите количество символов для перемещения вправо: ";
            correct(k);
            std::string rightText = editor.cursorRight(k);
            std::cout << "Текст справа от курсора: " << rightText << "\n";
            break;
        }
        case 5: {
            std::cout << "\nТекущий текст:\n";
            std::cout << editor;
            break;
        }
        case 6:
            std::cout << "\nВыход из редактора.\n";
            break;
        default:
            std::cout << "\nНеверный выбор. Пожалуйста, выберите число от 1 до 6.\n";
        }
    } while (choice != 6);

    return EXIT_SUCCESS;
}
