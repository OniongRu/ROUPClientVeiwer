#ifndef GRAPHICFORM_H
#define GRAPHICFORM_H

#include <QWidget>

namespace Ui {
class GraphicForm;
}

class GraphicForm : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicForm(QWidget *parent = nullptr);
    ~GraphicForm();

private:
    Ui::GraphicForm *ui;
};

#endif // GRAPHICFORM_H
