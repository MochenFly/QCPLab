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

    // ����ͼ�οؼ���Ե��ͼ������ļ��
    m_pPlot->plotLayout()->setMargins(QMargins(0, 0, 0, 0));
    m_pPlot->plotLayout()->setMinimumMargins(QMargins(0, 0, 0, 0));

    // ����ͼ��������ͼ����������ļ��
    // �����Կ��Բ�����Ϊ 0
    // �ϼ����ɼ����Ҫ���㹻�Ŀռ���ʾ����.���ҵĿ̶� label
    // ���������ֵ�Ƚϴ�ʱ��Ĭ�ϼ��ᵼ�����ϡ����ҵĿ̶� label �޷���ʾ
    m_pPlot->axisRect()->setMargins(QMargins(0, 0, 0, 0));
    m_pPlot->axisRect()->setMinimumMargins(QMargins(0, 0, 0, 0));

    // ������������ͼ����������ļ��
    m_pPlot->xAxis->setPadding(0);
    m_pPlot->yAxis->setPadding(0);

    m_pPlot->xAxis->setRange(0, 15000);

    // �̶Ȳ�������
    // tssReadability���ɶ���Ϊ��Ҫ�Ĳ�������
    m_pPlot->xAxis->ticker()->setTickStepStrategy(QCPAxisTicker::tssReadability);
    // tssMeetTickCount������������ setTickCount ���õ�ֵ���ɶ��Բ���
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

    // �����ʾ�Ĵ�С�� pen �Ŀ�ȼ���ɢ��ĳߴ�
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
