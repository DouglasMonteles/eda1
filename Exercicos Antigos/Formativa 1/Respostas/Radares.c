double calculaVelocidadeMedia(int tA, int tB, double distancia);
int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima);

double calculaVelocidadeMedia(int tA, int tB, double distancia){

	float tempo_final;

	tempo_final = tB - tA;
	tempo_final /= 3600.0;

	return distancia / tempo_final;
}

int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima){
	double velocidade_motorista;
	int multa;

	velocidade_motorista = calculaVelocidadeMedia(tA, tB, distancia);

	if(velocidade_motorista <= velocidadeMaxima){
		multa = 0;
	}

	else if(velocidade_motorista > velocidadeMaxima){
		multa = 1;
	}

	return multa;
}
