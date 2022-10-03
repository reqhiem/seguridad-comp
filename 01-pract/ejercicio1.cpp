#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string ejercicio1(string texto);
string ejercicio2(string texto);
string ejercicio3(string texto);
string ejercicio4(string texto);

int main(int argc, char const *argv[])
{
    string texto = "Mi corazón oprimido\n"
                    "Siente junto a la alborada\n"
                    "El dolor de sus amores\n"
                    "Y el sueño de las distancia.\n"
                    "La luz de la aurora lleva\n"
                    "Semilleros de nostalgias\n"
                    "Y la tristeza sin los ojos\n"
                    "De la médula del alma.\n"
                    "La gran tumba de la noche\n"
                    "Su negro velo levanta\n"
                    "Para ocultar con el día\n"
                    "La inmensa cumbre estrellada.\n"
                    "¡Qué haré yo sobre estos campos\n"
                    "Cogiendo niños y ramas\n"
                    "Rodeado de la aurora\n"
                    "Y llena de noche el ama!\n"
                    "¡Qué haré si tienes tus ojos\n"
                    "Muertos a las luces claras\n"
                    "Y no ha de sentir mi carne\n"
                    "El calor de tus miradas!\n"
                    "¿Por qué te perdí por siempre\n"
                    "En aquella tarde clara?\n"
                    "Hoy mi pecho está reseco\n"
                    "Como una estrella apagada.\n"
                    "ALBA, Federico García Lorca\n";

    
    cout << texto << endl;
    string resultado1 = ejercicio1(texto);
    cout << endl;
    cout << resultado1 << endl;
    cout << endl;
    string resultado2 = ejercicio2(resultado1);
    cout << endl;
    cout << resultado2 << endl;
    cout << endl;
    string resultado3 = ejercicio3(resultado2);
    cout << resultado3 << endl;

    cout << endl;
    string resultado4 = ejercicio4(resultado3);
    cout << resultado4 << endl;

    ofstream fileOutput{"POEMA_PRE.txt", ios::out};
    fileOutput << resultado4;
    fileOutput.close();

    /* string test = "u";
    cout << (int)test[0] << endl; */

    return 0;
}

/**
 * @description: Realizar las siguientes sustituciones: jxi, hxi, ñxn, kxl, uxv, wxv, yxz, xxr (tanto mayúsculas como minúsculas).
 * @param: string cadena - Cadena de caracteres a sustituir.
 * @return: string - Cadena de caracteres con las sustituciones realizadas.
 */
string ejercicio1(string texto){
    string salida = "";
    for (int i=0; i<texto.length(); i++){
        if(texto[i] == 'j' || texto[i] == 'J') salida +=  "i";
        else if(texto[i] == 'h' || texto[i] == 'H') salida +=  "i";
        else if((int)texto[i] == -61 && (int)texto[i+1] ==-79){
            salida += "n";
            i++;
        }
        else if(texto[i] == 'k' || texto[i] == 'K') salida += "l";
        else if(texto[i] == 'u' || texto[i] == 'U') salida += "v";
        else if(texto[i] == 'w' || texto[i] == 'W') salida += "v";
        else if(texto[i] == 'y' || texto[i] == 'Y') salida += "z";
        else if(texto[i] == 'x' || texto[i] == 'X') salida += "r";
        else {
            salida += texto[i];
        }
    }
    return salida;
}

/**
 * @description: Elimine las tildes
 * @param: string cadena - Cadena de caracteres a sustituir.
 * @return: string - Cadena de caracteres con las sustituciones realizadas.
 */
string ejercicio2(string texto){
    string salida = "";
    for (int i=0; i < texto.length(); i++){
        if((int)texto[i] == -61){
            if ((int)texto[i+1] == -95) salida += "a";
            else if ((int)texto[i+1] == -127) salida += "A";
            else if ((int)texto[i+1] == -87) salida += "e";
            else if ((int)texto[i+1] == -119) salida += "E";
            else if ((int)texto[i+1] == -83) salida += "i";
            else if ((int)texto[i+1] == -115) salida += "I";
            else if ((int)texto[i+1] == -77) salida += "o";
            else if ((int)texto[i+1] == -109) salida += "O";
            else if ((int)texto[i+1] == -70) salida += "u";
            else if ((int)texto[i+1] == -102) salida += "U";
            i++;
        }else{
            salida += texto[i];
        }
    }
    return salida;
}

/**
 * @description: Convierta todas las letras a mayúsculas
 * @param: string cadena - Cadena de caracteres a sustituir.
 * @return: string - Cadena de caracteres con las sustituciones realizadas.
 */
string ejercicio3(string texto){
    string salida = "";
    for (int i=0; i<texto.length(); i++){
        if((int)texto[i] >= 97 && (int)texto[i] <= 122){
            salida += (int)texto[i] - 32;
        }
        else 
            salida += texto[i];
    }
    return salida;
}

/**
 * @description: Elimine los espacios en blanco y los signos de puntuación Indique cuál sería el alfabeto resultante y cuál su longitud
 * @param: string cadena - Cadena de caracteres a sustituir.
 * @return: string - Cadena de caracteres con las sustituciones realizadas.
 */
string ejercicio4(string texto){
    string salida = "";
    for (int i=0; i<texto.length(); i++){
        if((int)texto[i] >= 65 && (int)texto[i] <= 90){
            salida += texto[i];
        }
    }
    return salida;
}