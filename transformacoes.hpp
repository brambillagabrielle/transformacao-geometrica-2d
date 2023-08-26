#include <Eigen/Dense>
using namespace Eigen;

#define _PI 3.14159265358979323846

float degree2rad(float ang)
{
    return ang * (float)(_PI / 180.0);
}

void mostrarCoordenadas(vector<Vector2f> coords)
{
    char ponto = 65;

    cout.precision(2);

    cout << "\n";
    for (auto c : coords)
    {
        cout << ponto++ << " (";
        cout << fixed << c.transpose() << ")\n";
    }
    cout<< "\n\n";
}

vector<Vector2f> rotacao(vector<Vector2f> coords, float graus)
{
    float grausRad = degree2rad(graus), sinO = sin(grausRad), cosO = cos(grausRad);

    Matrix3f T = Matrix3f::Identity();

    T(0, 0) = cosO;
    T(0, 1) = -sinO;
    T(1, 0) = sinO;
    T(1, 1) = cosO;

    vector<Vector2f> coordsT;

    for (auto c : coords)
    {
        Vector3f cT = T * c.homogeneous();
        coordsT.push_back(cT.hnormalized());
    }

    return coordsT;
}

vector<Vector2f> escala(vector<Vector2f> coords, float sx, float sy)
{
    Matrix3f T = Matrix3f::Identity();

    T(0, 0) = sx;
    T(1, 1) = sy;

    vector<Vector2f> coordsT;

    for (auto c : coords)
    {
        Vector3f cT = T * c.homogeneous();
        coordsT.push_back(cT.hnormalized());
    }

    return coordsT;
}

vector<Vector2f> translacao(vector<Vector2f> coords, float tx, float ty)
{
    Matrix3f T = Matrix3f::Identity();

    T(0, 2) = tx;
    T(1, 2) = ty;

    vector<Vector2f> coordsT;

    for (auto c : coords)
    {
        Vector3f cT = T * c.homogeneous();
        coordsT.push_back(cT.hnormalized());
    }

    return coordsT;
}

vector<Vector2f> cisalhamento(vector<Vector2f> coords, string direcao, float deslocamento)
{
    Matrix3f T = Matrix3f::Identity();

    if (direcao == "H")
        T(0, 1) = deslocamento;
    else if (direcao == "V")
        T(1, 0) = deslocamento;

    vector<Vector2f> coordsT;

    for (auto c : coords)
    {
        Vector3f cT = T * c.homogeneous();
        coordsT.push_back(cT.hnormalized());
    }

    return coordsT;
}

vector<Vector2f> reflexao(vector<Vector2f> coords, string eixo)
{
    Matrix3f T = Matrix3f::Identity();

    if (eixo == "X")
        T(1, 1) = -1;
    else if (eixo == "Y")
        T(0, 0) = -1;

    vector<Vector2f> coordsT;

    for (auto c : coords)
    {
        Vector3f cT = T * c.homogeneous();
        coordsT.push_back(cT.hnormalized());
    }

    return coordsT;
}
