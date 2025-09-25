#ifndef OPTIONS_WINDOW_HH
#define OPTIONS_WINDOW_HH

#include <QWidget>

namespace Ui {
class options_window;
}

class options_window : public QWidget
{
    Q_OBJECT

public:
    explicit options_window(QWidget *parent = nullptr);
    ~options_window();

private:
    Ui::options_window *ui;
};

#endif // OPTIONS_WINDOW_HH
