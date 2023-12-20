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
