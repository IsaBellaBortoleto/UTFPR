#include<iostream>

using namespace std;
class Principal;
class Carro;

class Carro{

	private:
		string nome;
		float capacidadeTanque; // L
		float tanque;
		float consumo; // 5l / KM

	public:
		Carro(string nomeCarro, float cap, float tanqueCon, float cons) : nome(nomeCarro),
		capacidadeTanque(cap), tanque(tanqueCon), consumo(cons){}
		~Carro(){}
		void abastecer(float litro){
			tanque+=litro;
			if(tanque>capacidadeTanque){
				tanque = capacidadeTanque;
		
		}
		float distancia(){
			return tanque/consumo;
		}
};


class Principal{

	private:
		Carro Chevette;


	public:
		Principal(){
			Carro Chevette("Papaizinho", 50.0, 25.0, 5.0);
			cout << distancia() << endl;
			abastacer(25.0);
			cout << distancia() << endl;
			
		}

		~Principal(){}

};




int main(){

	Principal ObjetoPrincipal;

	return 0;
}
