/*COMP.CS.110 27.03.2024
 *
 * Project name: Binario_gui
 *
 * About the program:
 *
 * Thi program is a UI for the game Binario. You can do various things in
 * this that were not possible in the non-ui version like resize the board.
 *
 * When run, the program open a start window. In this window you can choose to start
 * or quit. When start is pressed, it opens a new window which is a setup menu.
 * In here you can choose the size of the board and wether you want to use random board
 * or input an already existing one. If you gave a viable seed or board, the continue
 * button becomes availabe and you can start the game.
 *
 * When game starts, you can see that the timer has also started. There are
 * already some boxed filled and you need to put a number on the blank boxes.
 *
 * The rules are:
 * You can't have three of the same number in a row.
 * You can't have more than three of the same numbers in one column or row.
 * You can only use the numbers 1 and 0.
 *
 * You win when every box is filled correctly.
 *
 * The box will turn red if you place a number incorrectly.
 * When put correctly the box will turn grey and you cannot change the number.
 *
 * When you win, the program open a win window wich says that you have won and
 * shows your score wich is 1000 - your playtime in seconds. If your play time
 * takes more than 1000seconds, then your score is 0.
 *
 * The restart button on all windows will take you back to setup menu.
 *
 *
 * Programs creator:
 * Name: Antton Alivuotila
 * Student number: 151259218
 * UserID: bvanal
 * E-Mail: antton.alivuotila@tuni.fi
 */

#include "mainwindow.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
