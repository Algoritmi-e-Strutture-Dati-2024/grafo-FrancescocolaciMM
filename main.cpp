using namespace std;
#include <iostream>
#include <string>
#include "Grafo.cpp"
int main() {
    // Creo il grafo utilizzando i nomi delle città
    Grafo<string> grafo;

    // Aggiungi nodi con i 
    grafo.aggiungiNodo("Milano");
    grafo.aggiungiNodo("Roma");
    grafo.aggiungiNodo("Napoli");
    grafo.aggiungiNodo("Torino");
    grafo.aggiungiNodo("Firenze");

    // Aggiungo archi con peso
    grafo.aggiungiArco("Milano", "Roma", 600);
    grafo.aggiungiArco("Roma", "Napoli", 230);
    grafo.aggiungiArco("Napoli", "Firenze", 500);
    grafo.aggiungiArco("Firenze", "Torino", 400);
    grafo.aggiungiArco("Milano", "Torino", 140);
    grafo.aggiungiArco("Roma", "Torino", 700);

    // Stampo la matrice di adiacenza
    grafo.stampa();

    // Verifico se un nodo esiste nel grafo
    cout << "Esiste il nodo Milano? " << (grafo.esisteNodo("Milano") ? "Sì" : "No") << endl;

    // Stampo nodi adiacenti a Roma
    grafo.nodiAdiacenti("Roma");

    // Verifico se esiste un arco tra Roma e Torino
    cout << "Esiste un arco tra Roma e Torino? " << (grafo.esisteArco("Roma", "Torino") ? "Sì" : "No") << endl;

    // Rimuovo un nodo e i rispettivi archi
    grafo.rimuoviNodo("Torino");

    // Rimuovo un arco in particolare
    grafo.rimuoviArco("Roma", "Napoli");

    // qui stampo la matrice di adiacenza aggiornata
    grafo.stampa();
    
    // Aggiungo un nuovo nodo e arco
    grafo.aggiungiNodo("Lecce");
    grafo.aggiungiArco("Firenze", "Lecce", 800);
    cout << "Matrice di Adiacenza dopo l'aggiunta del nodo Lecce e dell'arco tra Firenze e Lecce:" <<endl;
    grafo.stampa();

    // Verifico connettività tra due nodi
    cout << "Il nodo Milano è connesso al nodo Firenze? " << (grafo.verificaArco("Milano", "Firenze") ? "Sì" : "No") << endl;

    // Trova l'arco con peso minore per un nodo
    int arcoMinimo = grafo.arcoConPesoMinore(Firenze);
    if (arcoMinimo != -1) {
        cout << "L'arco con il peso minimo da Firenze ha peso: " << arcoMinimo <<endl;
    } else {
        cout << "Non ci sono archi uscenti da Firenze." << endl;
    }


 return 0;
}
