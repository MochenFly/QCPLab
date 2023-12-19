#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_API.h"

#include "QCustomPlot/QCustomPlot.h"

QT_BEGIN_NAMESPACE
namespace Ui { class APIClass; };
QT_END_NAMESPACE

class API : public QMainWindow
{
    Q_OBJECT

public:
    API(QWidget *parent = nullptr);
    ~API();

private:
    void initialize();
    void initializeUi();
    void initializePlot();

private:
    Ui::APIClass*               ui;
    QCustomPlot*                m_pPlot;
};
