#include <iostream>
using namespace std;

#include "transformacoes.hpp"

int main(void)
{
	setlocale(LC_ALL, "Portuguese");

	string entrada = "";

	cout<< " * TRANSFORMAÇÕES GEOMÉTRICAS 2D * ";
	cout<< "\n\n * Insira a operação que deseja realizar: ";
	getline(cin, entrada);

	istringstream iss(entrada);

	string operacao;
	iss>> operacao;

	if (operacao == "R") // Rotação
	{
		float graus, x, y;

		iss>> graus;
		
		vector<Vector2f> coordenadas;
		while (iss >> x >> y)
			coordenadas.push_back(Vector2f(x, y));

		vector<Vector2f> resultado = rotacao(coordenadas, graus);
		
		cout<< "\nResultado da rotação:\n";
		mostrarCoordenadas(resultado);
	}
	else if (operacao == "E") // Escala
	{
		float x, y, sx, sy;

		iss>> sx >> sy;

		vector<Vector2f> coordenadas;
		while (iss >> x >> y)
			coordenadas.push_back(Vector2f(x, y));

		vector<Vector2f> resultado = escala(coordenadas, sx, sy);
		
		cout<< "\nResultado da rotação:\n";
		mostrarCoordenadas(resultado);
	}
	else if (operacao == "T") // Translatação
	{
		float x, y, tx, ty;

		iss>> tx >> ty;

		vector<Vector2f> coordenadas;
		while (iss >> x >> y)
			coordenadas.push_back(Vector2f(x, y));

		vector<Vector2f> resultado = translacao(coordenadas, tx, ty);
		
		cout<< "\nResultado da rotação:\n";
		mostrarCoordenadas(resultado);
	}
	else if (operacao == "CI") // Cisalhamento
	{
		float x, y, deslocamento;
		string direcao;

		iss>> direcao >> deslocamento;

		vector<Vector2f> coordenadas;
		while (iss >> x >> y)
			coordenadas.push_back(Vector2f(x, y));

		vector<Vector2f> resultado = cisalhamento(coordenadas, direcao, deslocamento);
		
		cout<< "\nResultado da rotação:\n";
		mostrarCoordenadas(resultado);
	}
	else if (operacao == "RE") // Reflexão
	{
		float x, y;
		string eixo;

		iss>> eixo;

		vector<Vector2f> coordenadas;
		while (iss >> x >> y)
			coordenadas.push_back(Vector2f(x, y));

		vector<Vector2f> resultado = reflexao(coordenadas, eixo);
		
		cout<< "\nResultado da rotação:\n";
		mostrarCoordenadas(resultado);
	}
	else
		cout<< "Operação inválida!";
	
	return EXIT_SUCCESS; 
}
