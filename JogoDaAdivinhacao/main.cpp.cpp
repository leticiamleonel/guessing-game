#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    cout << "----------------------------------------" << endl;
    cout << "-- Bem-vindos ao jogo da adivinhacao! --" << endl;
    cout << "----------------------------------------" << endl;

    cout << "Escolha seu nível de dificuldade: " << endl;
    cout << "Facil (f), Medio(m) ou Dificil (d)" << endl;

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() %100;


    bool naoAcertou = true;
    int tentativas = 0;
    double pontos = 1000.0;
    char dificuldade;
    int numDeTentativas;

    if (dificuldade == 'f'){
        numDeTentativas = 15;
    }
    else if(dificuldade == 'm'){
        numDeTentativas =10;
    } else {
        numDeTentativas = 5;
    }

    cin >> dificuldade;


    for(tentativas = 1; tentativas <= numDeTentativas; tentativas++){
        int chute;

        cout << "Tentativa " << tentativas << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        cout << "O valor do seu chute e: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        double pontosPerdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos = pontos - pontosPerdidos;

        if (acertou)
        {
            cout << "Parabens! Voce acertou o numero secreto!" << endl;
            naoAcertou = false;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }

    if(naoAcertou){
        cout << "Voce perdeu! Tente novamente! " << endl;
    } else{
        cout << "Voce acertou o numero secreto em " << tentativas  << " tentativas!" << endl;
        cout << "Sua pontuacao foi de: " << fixed << setprecision(2) << pontos << " pontos." << endl;
    }

}
