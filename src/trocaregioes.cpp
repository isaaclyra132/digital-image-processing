#include <iostream>
#include <opencv2/opencv.hpp>

struct Point
{
    int x;
    int y;
};

int main(int argc, char **argv)
{
    cv::Mat image;
    Point p1, p2;
    bool pontoValido = false;

    image = cv::imread("./assets/biel.png", cv::IMREAD_GRAYSCALE);
    if (!image.data)
    {
        std::cout << "Não abriu imagem" << std::endl;
    }

    cv::namedWindow("Imagem Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Imagem Original", image);

    cv::namedWindow("Imagem Negativa", cv::WINDOW_AUTOSIZE);
    cv::imshow("Imagem Negativa", image);
    cv::waitKey();
    return 0;
}