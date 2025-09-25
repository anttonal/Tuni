#ifndef GAMEBOARD_WINDOW_HH
#define GAMEBOARD_WINDOW_HH

#include <QWidget>

namespace Ui {
class gameboard_window;
}

class gameboard_window : public QWidget
{
    Q_OBJECT

public:
    explicit gameboard_window(QWidget *parent = nullptr);
    ~gameboard_window();

private:
    Ui::gameboard_window *ui;
};

#endif // GAMEBOARD_WINDOW_HH
