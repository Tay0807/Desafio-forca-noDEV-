#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;


int main()
{
	setlocale (LC_ALL,"portuguese");
    const int MAX_WRONG = 8;  // número máximo de palpites errados permitidos

    vector<string> words;  // coleção de palavras para adivinhar
    words.push_back("MARCELO");
    words.push_back("IGOR");
    words.push_back("SENAI");
    words.push_back("SESI");
    words.push_back("CANSEI");
    words.push_back("CELIA");
    words.push_back("ROSIMAR");
    words.push_back("ALEX");
    words.push_back("FABRICIO");
    words.push_back("BRUNA");
    words.push_back("ARNOR");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string THE_WORD = words[0];            // palavra a ser adivinhada
    int wrong = 0;                              // número de palpites errados
    string soFar(THE_WORD.size(), '-');          // parte da palavra adivinhada
    string used = "";                           // letras já adivinhadas

    cout << "Bem-vindo ao jogo da forca. Boa sorte!\n";

    // loop principal
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
    {
        cout << "\nPalavra a ser adivinhada: " << soFar << endl;
        cout << "Letras já usadas: " << used << endl;
        cout << "Palpites errados restantes: " << MAX_WRONG - wrong << endl;

        char guess;
        cout << "\nDigite uma letra: ";
        cin >> guess;
        guess = toupper(guess); // torna a letra maiúscula, caso não seja
        while (used.find(guess) != string::npos)
        {
            cout << "\nVocê já usou a letra " << guess << endl;
            cout << "Digite outra letra: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos)
        {
            cout << "É isso aí! " << guess << " está na palavra.\n";

            // atualiza a string soFar com a nova letra
            for (unsigned int i = 0; i < THE_WORD.length(); ++i)
            {
                if (THE_WORD[i] == guess)
                {
                    soFar[i] = guess;
                }
            }
        }
        else
        {
            cout << "Desculpe, " << guess << " não está na palavra.\n";
            ++wrong;
        }
    }

    // encerramento do jogo
    if (wrong == MAX_WRONG)
    {
        cout << "\nVocê foi enforcado!";
    }
    else
    {
        cout << "\nParabéns! Você adivinhou a palavra!";
    }

    cout << "\nA palavra era " << THE_WORD << endl;

    return 0;
}

