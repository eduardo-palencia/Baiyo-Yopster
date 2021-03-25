#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#pragma region 
string variables = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_1234567890";
string operators = "+-*=/^()";
string numbers = "1234567890E";
#pragma endregion

//Metodo que lee el archivo a utilizar y regresa un string con el contenido
string readFile() {

    string tempLine, str;
    fstream file;
    file.open("xd.txt");

    while (getline(file, tempLine))
        str.append(tempLine + "\n");
        
    return str;
}

//Metodo que compruabs si el caracter recibido se encuentra dentro de la cadena recibida y regresa un booleano
bool isInArray(char str, string arr) {

    for (int i = 0; i < arr.length(); i++) {
        if (arr[i] == str)
            return true;
    }

    return false;
}

// Metodo recursivo Regex que avanza a lo largo del string clasificando sus diferentes componentes
void regex(string str, int positionOnStr) {

    string tempStr = "";

    //Si el caracter es un '/' o si muiestra indicios de ser un comentario
    if (str[positionOnStr] == '/') {

        if (str[positionOnStr+1] == '/') {
            
            while (str[positionOnStr] != '\n') {
                tempStr.push_back(str[positionOnStr]);
                positionOnStr++;
            }
            cout << tempStr << " - Comentario" << endl;
        }
        else if (str[positionOnStr-1] != '/' || str[positionOnStr+1] != '/') {
            tempStr.push_back(str[positionOnStr]);
            cout << tempStr << " - Operador" << endl;
            positionOnStr++;
        }
    }
    //
    else if(isInArray(str[positionOnStr], operators)) {
        
        tempStr.push_back(str[positionOnStr]);

        if (str[positionOnStr] == '=')
            cout << tempStr << " - Asignacion" << endl;
        else if (str[positionOnStr] == '+')
            cout << tempStr << " - Suma" << endl;
        else if (str[positionOnStr] == '-')
            cout << tempStr << " - Resta" << endl;
        else if (str[positionOnStr] == '^')
            cout << tempStr << " - Potencia" << endl;
        else if (str[positionOnStr] == '*')
            cout << tempStr << " - Multiplicacion" << endl;
        else if (str[positionOnStr] == '(')
            cout << tempStr << " - Parentesis que abre" << endl;
        else if (str[positionOnStr] == ')')
            cout << tempStr << " - Parentesis que cierra" << endl;
        
        positionOnStr++;
    }
    //Compruba si el caracter es un numero entero
    //falta que detecte negativo y exponenciales
    else if (isInArray(str[positionOnStr], numbers)) {
        
        if (str[positionOnStr - 1] == '-')
            tempStr.push_back(str[positionOnStr - 1]);

        while (isInArray(str[positionOnStr], numbers) || str[positionOnStr] == '.' || str[positionOnStr] == '-') {
            tempStr.push_back(str[positionOnStr]);
            positionOnStr++;
        }

        cout << tempStr << " - Real" << endl;
    }
    //Comprueba si el caracter es una variable
    else if (isInArray(str[positionOnStr], variables)) {

        while (isInArray(str[positionOnStr], variables)) {
            tempStr.push_back(str[positionOnStr]);
            positionOnStr++;
        }
        cout << tempStr << " - Variable" << endl;
    }
    //En caso de que no lo detecte lo salta
    else {
        positionOnStr++;
    }

    if (str.length() > positionOnStr)
        regex(str, positionOnStr);
}

int main() {

    regex(readFile(), 0);
}