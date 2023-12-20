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

    initializePlot();

    drawSquareCurve();
    drawPoint();
    drawRing();
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

void API::drawSquareCurve()
{
    QVector<double> x(101), y(101);
    for (int i = 0; i < 101; ++i)
    {
        x[i] = i / 50.0 - 1;
        y[i] = x[i] * x[i];
    }

    m_pSquareCurve = m_pPlot->addGraph();
    m_pSquareCurve->setData(x, y);

    m_pPlot->xAxis->setLabel("x");
    m_pPlot->yAxis->setLabel("y");

    m_pPlot->xAxis->setRange(-1.1, 1.1);
    m_pPlot->yAxis->setRange(0, 1.1);
}

void API::drawPoint()
{
    m_pPoint = m_pPlot->addGraph();
    
    QVector<double> xValue;
    xValue << -1 << -0.5 << 0 << 0.5 << 1;
    QVector<double> yValue;
    yValue << 0.5 << 1 << 0.5 << 0 << 0.5;
	m_pPoint->setData(xValue, yValue);

    // 最后显示的大小是 pen 的宽度加上散点的尺寸
    QPen pen(Qt::red, 2.0, Qt::DashLine);
    m_pPoint->setPen(pen);
    m_pPoint->setLineStyle(QCPGraph::lsImpulse);
	m_pPoint->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 6));
}

void API::drawRing()
{
    m_pRing = m_pPlot->addGraph();
    QVector<double> xValue;
    xValue << -1 << -0.5 << 0 << 0.5 << 1;
    QVector<double> yValue;
    yValue << 0.5 << 1 << 0.5 << 0 << 0.5;
	m_pRing->setData(xValue, yValue);

    QPen pen(Qt::green, 2.0, Qt::SolidLine);
    m_pRing->setPen(pen);
    m_pRing->setLineStyle(QCPGraph::lsNone);
	m_pRing->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
}
