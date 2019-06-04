#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QPushButton>
#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtCharts/QChart>
#include <qt5/QtCharts/QChartView>
#include <qt5/QtCharts/QSplineSeries>
#include <iostream>
#include <chrono>
#include "../include/sampling.h"

int main(int argc, char** argv) {
        QApplication app{ argc, argv };
        
        constexpr int samp_size = 1000000;

        std::cout << "Calculating " << samp_size 
                << " samples using rejection sampling ..." << std::flush;
        auto start = std::chrono::steady_clock::now();
        std::map<double, int>samp_rej = RejectionSampling(samp_size);
        auto end = std::chrono::steady_clock::now();
        std::cout << " done" << std::endl;
        std::cout << "Took: " 
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                << " ms" << std::endl;

        QtCharts::QSplineSeries s_rej{ };

        for (auto i : samp_rej) {
                s_rej.append(i.first, i.second);
        }
        
        QtCharts::QChart c_rej{ };
        c_rej.legend()->hide();
        c_rej.addSeries(&s_rej);
        c_rej.setTitle("Rejection Sampling");
        c_rej.createDefaultAxes();
        c_rej.axes(Qt::Vertical).first()->setRange(0, 1000);
        c_rej.axes(Qt::Horizontal).first()->setRange(1, 6);

        QtCharts::QChartView cv_rej{ &c_rej };
        cv_rej.setRenderHint(QPainter::Antialiasing);

        std::cout << "Calculating " << samp_size 
                << " samples using inversion sampling ..." << std::flush;
        start = std::chrono::steady_clock::now();
        std::map<double, int>samp_inverse = InversionSampling(samp_size);
        end = std::chrono::steady_clock::now();
        std::cout << " done" << std::endl;
        std::cout << "Took: " 
                << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                << " ms" << std::endl;
        QtCharts::QSplineSeries s_inverse{ };

        for (auto i : samp_inverse) {
                s_inverse.append(i.first, i.second);
        }
        
        QtCharts::QChart c_inverse{ };
        c_inverse.legend()->hide();
        c_inverse.addSeries(&s_inverse);
        c_inverse.setTitle("Inversion Sampling");
        c_inverse.createDefaultAxes();
        c_inverse.axes(Qt::Vertical).first()->setRange(0, 1000);
        c_inverse.axes(Qt::Horizontal).first()->setRange(1, 6);

        QtCharts::QChartView cv_inverse{ &c_inverse };
        cv_inverse.setRenderHint(QPainter::Antialiasing);

        QMainWindow w_rej{ };
        w_rej.setCentralWidget(&cv_rej);
        w_rej.resize(500, 500);
        w_rej.show();

        QMainWindow w_inverse{ };
        w_inverse.setCentralWidget(&cv_inverse);
        w_inverse.resize(500, 500);
        w_inverse.show();
        
        return app.exec();
}
