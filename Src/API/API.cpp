#include "API.h"

API::API(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::APIClass())
{
    initialize();
}

API::~API()
{
    delete ui;
}

void API::initialize()
{
    initializeUi();
}

void API::initializeUi()
{
    ui->setupUi(this);

    this->setStyleSheet("border: 1px solid red;");
    initializePlot();
}

void API::initializePlot()
{
    m_pPlot = new QCustomPlot(this);
    ui->hLMain->addWidget(m_pPlot);

    // 设置图形控件边缘与图形区域的间距
    m_pPlot->plotLayout()->setMargins(QMargins(0, 0, 0, 0));
    m_pPlot->plotLayout()->setMinimumMargins(QMargins(0, 0, 0, 0));

    // 设置图形区域与图形内容区域的间距
    // 该属性可以不设置为 0
    // 上间距和由间距需要有足够的空间显示最上.最右的刻度 label
    // 横坐标最大值比较大时。默认间距会导致最上、最右的刻度 label 无法显示
    m_pPlot->axisRect()->setMargins(QMargins(0, 0, 0, 0));
    m_pPlot->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));

    // 设置坐标轴与图形内容区域的间距
    m_pPlot->xAxis->setPadding(0);
    m_pPlot->yAxis->setPadding(0);

    m_pPlot->xAxis->setRange(0, 15000);

    // 刻度步长策略
    // tssReadability：可读性为主要的步长策略
    m_pPlot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);
    // tssMeetTickCount：尽可能满足 setTickCount 设置的值，可读性不好
    //m_pPlot->xAxis->ticker()->setTickCount(6);
    //m_pPlot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
}
