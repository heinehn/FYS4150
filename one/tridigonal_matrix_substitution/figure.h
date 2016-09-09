#ifndef FIGURE_H
#define FIGURE_H

#include <QList>
#include <QChart>
#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QXYSeries>
#include <QtCharts/QLineSeries>
#include <QMainWindow>
#include <vector>
using std::vector;
using namespace QtCharts;
class Figure : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString xLabel READ xLabel WRITE setXLabel NOTIFY xLabelChanged)
    Q_PROPERTY(QString yLabel READ yLabel WRITE setYLabel NOTIFY yLabelChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

public:
    explicit Figure(QObject *parent = 0);
    void hold(QString mode);
    void show();
    void plot(vector<double> &x, vector<double> &y);
    QString xLabel() const;
    QString yLabel() const;
    QString title() const;


public slots:
    void setXLabel(QString xLabel);
    void setYLabel(QString yLabel);
    void setTitle(QString title);

signals:
    void xLabelChanged(QString xLabel);
    void yLabelChanged(QString yLabel);
    void titleChanged(QString title);

private:
    QMainWindow m_window;
    bool m_holdOn = true;
    QChart *m_chart = nullptr;
    QChartView *m_chartView = nullptr;
    QVector<QXYSeries*> m_series;
    QString m_xLabel;
    QString m_yLabel;
    QString m_title;
};

#endif // FIGURE_H
