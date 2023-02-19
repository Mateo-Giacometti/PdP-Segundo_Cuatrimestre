#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include <tuple>

/*
a) Un vagón de un tren tiene 40 asientos, cada uno de ellos puede estar ocupado o vacante. El
vagón puede ser de primera o segunda clase. Cree una clase Carriage para representar esta
información. En el constructor se supondrá que todos los asientos inicialmente están vacantes.
Escriba los métodos apropiados de acceso y actualización y un método que vaya ocupando
los asientos de la siguiente forma: si el vagón es de primera hay un 10% de probabilidad que
los asientos sean ocupados; si es de segunda clase hay un 40% de probabilidad que los
asientos sean ocupados. Escriba una función main() que contenga un objeto Carriage,
llénelo aleatoriamente e imprima el estado de cada asiento.

b) Un tren consta de un cierto número de vagones, tiene una estación de partida y una de llegada,
un cierto precio para los tickets de primera y otro para los de segunda. Cree una clase Train
que contenga esta información. Añada una función que llene los asientos de los vagones
aleatoriamiente. Cree un método que calcule el total de ventas de tickets. Ajuste su función
main para probar lo hecho.
*/

using std::cout;
using std::endl;

class Carriage {
    private:
        bool asientos [40];
        bool primera;
    public:
        Carriage() {};
        Carriage(bool prim);
        bool getAsiento(int ind) { return asientos[ind]; }
        bool getPrimera() { return primera; }
        void setPrimera(bool p) { primera = p; }
        void ocupar();
};

Carriage::Carriage(bool prim) {
    primera = prim;
    for(int i = 0; i < 40; i++) asientos[i] = 0;
}

void Carriage::ocupar() {
    double probabilidad = primera ? 0.1 : 0.4;
    for(int i = 0; i < 40; i++) asientos[i] = double(rand())/RAND_MAX < probabilidad;
}
class Train {
    private:
        Carriage * carriages;
        int numPri;
        int numSeg;
        char * salida;
        char * destino;
        int precioPrimera;
        int precioSegunda;
    public: //lista inicializadores
        Train(int nP, int nS, char * sal, char * dest, int pP, int pS):
        numPri(nP), numSeg(nS), salida(sal), destino(dest), precioPrimera(pP), precioSegunda(pS) {
        carriages = new Carriage[nP + nS];
        for(int i = 0; i < nP + nS; i++) carriages[i].setPrimera(i < nP);
        };
        ~Train() { delete [] carriages; }
        Carriage getCarriage(int i) { return carriages[i]; }
        void llenar();
        int totalVentas();
};

int Train::totalVentas() {
    int acum = 0;
    for(int i = 0; i < numPri + numSeg; i++)
        if (carriages[i].getPrimera())
            for(int j = 0; j < 40; j++)
                acum += carriages[i].getAsiento(j) * precioPrimera;
        else for(int j = 0; j < 40; j++)
                acum += carriages[i].getAsiento(j) * precioSegunda;
    return acum;
    }

void Train::llenar() {
    for(int i = 0; i < numPri + numSeg; i++)
        carriages[i].ocupar();
}

int main(void) {
    Train t(4, 7, "Rosario", "Tucuman", 20, 10);
    t.llenar();
    cout << endl << endl << t.totalVentas() << endl;
    return EXIT_SUCCESS;
}