#ifndef ACTUALPICKER_H
#define ACTUALPICKER_H

#include <QDialog>
#include <KEmoticons>
#include <kemoticons.h>

namespace Ui {
class ActualPicker;
}

class ActualPicker : public QDialog
{
    Q_OBJECT

public:
    explicit ActualPicker(QWidget *parent = 0);
    ~ActualPicker();
    void loadEmotes();
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void clickedEmote();

private:
    Ui::ActualPicker *ui;
};

#endif // ACTUALPICKER_H
