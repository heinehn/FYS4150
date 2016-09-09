#include "figure.h"
#include <QDebug>

Figure::Figure(QObject *parent) : QObject(parent)
{
    m_chart = new QChart();
    m_chart->legend()->hide();
    m_chartView = new QChartView(m_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_window.setCentralWidget(m_chartView);
    m_window.resize(1000, 500);
}

void Figure::hold(QString mode)
{

}

void Figure::show()
{
    m_window.show();
}

void Figure::plot(vector<double> &x, vector<double> &y)
{
    if(x.size() != y.size()) {
        qWarning() << "Error in Figure::plot. Vectors x and y do not have the same number of elements.";
        return;
    }

    QLineSeries *lineSeries = new QLineSeries();
    m_series.append(lineSeries);

    for(int i=0; i<x.size(); i++) {
        lineSeries->append(x[i], y[i]);
    }

    m_chart->addSeries(lineSeries);
    m_chart->createDefaultAxes();

    m_chart->axisX()->setTitleText(m_xLabel);
    m_chart->axisY()->setTitleText(m_yLabel);

}

QString Figure::xLabel() const
{
    return m_xLabel;
}

QString Figure::yLabel() const
{
    return m_yLabel;
}

QString Figure::title() const
{
    return m_title;
}

void Figure::setXLabel(QString xLabel)
{
    if (m_xLabel == xLabel)
        return;

    m_xLabel = xLabel;
    m_chart->axisX()->setTitleText(m_xLabel);

    emit xLabelChanged(xLabel);
}

void Figure::setYLabel(QString yLabel)
{
    if (m_yLabel == yLabel)
        return;

    m_yLabel = yLabel;
    m_chart->axisY()->setTitleText(m_yLabel);

    emit yLabelChanged(yLabel);
}

void Figure::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    m_chart->setTitle(title);
    emit titleChanged(title);
}
