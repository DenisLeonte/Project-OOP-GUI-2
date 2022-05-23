#ifndef GUIAPP_H
#define GUIAPP_H

#include "CLIController.h"
#include "ActionManager.h"
#include "Shop.h"

#include <QMainWindow>
#include "ui_guiapp.h"
#include "qmenubar.h"
#include "qmenu.h"
#include "qaction.h"
#include "qcombobox.h"
#include "qpushbutton.h"
#include "qwidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUIApp; }
QT_END_NAMESPACE

class GUIApp : public QMainWindow
{
    Q_OBJECT

public:
    GUIApp(QWidget *parent = nullptr);
    ~GUIApp();

private slots:
    void on_refreshButton_released();

    void on_CPUAdd_released();

    void on_SaveButton_released();

    void on_LoadButton_released();

    void on_UndoButton_released();

    void on_RedoButton_released();

    void on_PrintAllButton_released();

    void on_RemoveButton_released();

    void on_FilterTypeButton_released();

    void on_FilterPriceButton_released();

private:
    Ui::GUIApp *ui;
    void hideInputs();
    CLIController controller;
    ActionManager manager;

};
#endif // GUIAPP_H
