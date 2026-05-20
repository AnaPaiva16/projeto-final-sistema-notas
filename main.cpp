#include <iostream> 
#include <string>
using namespace std;

int main( ) {

    // Entrada - Declaração das Variáveis
    string nomes[20];
    int qtdAlunos;
    
    //Processamento
    cout << "=== SISTEMAS DE NOTAS v4.0 ===" << endl;
    do {
        cout << "Quantidade de Alunos (1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20); 

    cin.ignore( );

    for (int i = 0; i < qtdAlunos; i++) 
    {
        cout << "Nome do Aluno " << i + 1 << ": ";
        getline (cin, nomes[i]);
    }

    //Saída
    cout << "Alunos cadastrados: " << endl; 
    
    for (int i = 0; i < qtdAlunos; i++)     
    {
        cout << "  " << i + 1 << ". " << nomes[i] << endl;
    }
    
    return 0;
}