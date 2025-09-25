#ifndef VICTORY_WINDOW_HH
#define VICTORY_WINDOW_HH

#include <QWidget>

namespace Ui {
class victory_window;
}

class victory_window : public QWidget
{
    Q_OBJECT

public:
    explicit victory_window(QWidget *parent = nullptr);
    ~victory_window();

private:
    Ui::victory_window *ui;
};

#endif // VICTORY_WINDOW_HH
