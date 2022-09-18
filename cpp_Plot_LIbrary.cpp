#include <iostream>
#include <numeric> // for std::iota

#include "cplotlib/core.hpp"
int main(int argc, char *argv[])
{
    int vecSize = 21;
    std::vector<double> x_vec(vecSize), y_vec(vecSize), y_vec2(vecSize);
    std::iota(x_vec.begin(), x_vec.end(), -10);
    float HI = 100, LO = 25;
    for (int i = 0; i < x_vec.size(); i++)
    {
        //y_vec[i] = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
        y_vec[i] = x_vec[i]*x_vec[i];
        y_vec2[i] = x_vec[i]*x_vec[i]*x_vec[i];
    }

    cplt::Figure fig = cplt::Figure(cv::Size(1000,800));
    int nRows = 1, nCols = 1;

    auto axesManager = fig.addSubplots(nRows, nCols);
    auto ax00 = axesManager->get(0,0);
    ax00->setXlim(-10, 10);
    ax00->setYlim(-100,100);
    ax00->setXticks({-10, - 5, 0, 5, 10});
    ax00->setYticks({-50, -30, -10, 0, 70, 100});
    ax00->setXlabel("X");
    ax00->setYlabel("Y");
    ax00->setTitle("New QWERTYqwert123");

    axesManager->get(0,0)->plot(x_vec,y_vec);
    axesManager->get(0,0)->plot(x_vec,y_vec2, colors::orange, 2);

    cv::namedWindow("figure1");
    fig.save("../figure1.png");
    fig.show("figure1");

    ax00->setOffsets(0.3, 0.3, 0.3, 0.3);
    ax00->getGrid()->setThickness(2);
    fig.show("figure2");
    int key = cv::waitKey(0);
    std::cout <<"END main!" << std::endl;
    return 0;
} // END main
