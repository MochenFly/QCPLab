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

    // 绘制平方曲线
    void drawSquareCurve();

    // 绘制点
    void drawPoint();

    // 绘制圆环
    void drawRing();

private:
    Ui::APIClass*               ui;
    QCustomPlot*                m_pPlot;
    QCPGraph*                   m_pSquareCurve          { nullptr };
    QCPGraph*                   m_pPoint                { nullptr };
    QCPGraph*                   m_pRing                 { nullptr };

};
