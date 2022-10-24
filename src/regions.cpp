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

    // DEFININDO PONTOS VÁLIDOS
    std::cout << "Digite o X e Y do Ponto 1: ";
    do
    {
        std::cin >> p1.x >> p1.y;
        image.size();
        if (p1.x < 0 || p1.x > image.rows || p1.y < 0 || p1.y > image.cols)
        {
            std::cout << "Ponto inválido, digite o X e Y do Ponto 1 novamente: ";
        }
        else
        {
            pontoValido = true;
        }
    } while (!pontoValido);

    pontoValido = false;

    std::cout << "Digite o X e Y do Ponto 2: ";
    do
    {
        std::cin >> p2.x >> p2.y;
        if (p2.x < 0 || p2.x > image.rows || p2.y < 0 || p2.y > image.cols)
        {
            std::cout << "Ponto inválido, digite o X e Y do Ponto 2 novamente: ";
        }
        else
        {
            pontoValido = true;
        }
    } while (!pontoValido);

    // TESTE DE INICIO E FIM
    int inicioX, inicioY, finalX, finalY;
    if (p1.x > p2.x)
    {
        inicioX = p2.x;
        finalX = p1.x;
    }
    else
    {
        inicioX = p1.x;
        finalX = p2.x;
    }

    if (p1.y > p2.y)
    {
        inicioY = p2.y;
        finalY = p1.y;
    }
    else
    {
        inicioY = p1.y;
        finalY = p2.y;
    }

    // APLICANDO EFEITO NEGATIVO A REGIÃO
    for (int x = inicioX; x < finalX; x++)
    {
        for (int y = inicioY; y < finalY; y++)
        {
            image.at<uchar>(x, y) = 255 - image.at<uchar>(x, y);
        }
    }

    cv::namedWindow("Imagem Negativa", cv::WINDOW_AUTOSIZE);
    cv::imshow("Imagem Negativa", image);
    cv::waitKey();
    return 0;
}