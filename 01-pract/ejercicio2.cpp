#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

void kasiski(string text){
    vector<char> trigrams;
    map<vector<char>, int> trigramsFrecuency;
    map<vector<char>, vector<int>> positions;

    for(int i=0; i < text.size() - 2; i++){
        int cont = i;
        while(cont < i+3){
            trigrams.push_back(text[cont]);
            cont++;
        }
        trigramsFrecuency.insert(pair<vector<char>, int>(trigrams, 0));
        positions.insert(pair<vector<char>, vector<int>>(trigrams, 0));
        trigrams.clear();
    }

    for(int i=0; i < text.size() - 2; i++ ){
        int cont = i;
        while(cont < i+3){
            trigrams.push_back(text[cont]);
            cont++;
        }

        map<vector<char>, vector<int>>::iterator it2 = positions.begin();
        for(auto it = trigramsFrecuency.begin(); it != trigramsFrecuency.end(); ++it){
            bool isEquals = true;
            map <vector<char>, int>::iterator index;

            for(int j=0; j < it->first.size(); j++){
                if(trigrams[j] != it->first[j]){
                    isEquals = false;
                    index = it;
                }
            }

            if(isEquals){
                it->second += 1;
                it2->second.push_back(i);
            }
            ++it2;
        }

        trigrams.clear();
    }

    auto it2 = positions.begin();
    for (auto it=trigramsFrecuency.begin(); it!=trigramsFrecuency.end(); ++it){
        if (it2->second.size()>1){
            for(int j = 0; j<it->first.size(); j++) {
                cout<<it->first[j];
            }
            cout << " -> "<< it->second << " : [ ";
            for(int k = 0; k < it2->second.size() ; k++){
                cout<<it2->second[k]<<" ";
            }

            int first = it2->second[0];
            cout<<"] "<<endl;
            cout<<"Distancias: \n";

            for(int l = 1; l < it2->second.size() ; l++){
                cout<<it2->second[l] << " - " << first << " = " << it2->second[l] - first<<endl;
            }
            cout << endl;

        }
        ++it2;
    }

}

void frecuencias(string namefile){
    ifstream fileInput{namefile, ios::in};
    string texto;
    fileInput >> texto;
    fileInput.close();

    map <char, int> frecuencias;
    for (int i = 0; i < texto.length(); i++){
        if (frecuencias.find(texto[i]) == frecuencias.end()){
            frecuencias[texto[i]] = 1;
        }else{
            frecuencias[texto[i]]++;
        }
    }

    cout << texto << endl;

    for (auto it = frecuencias.begin(); it != frecuencias.end(); it++){
        cout << it->first << " -> " << it->second << endl;
    }

    priority_queue <pair<int, char>> pq;
    for (auto it = frecuencias.begin(); it != frecuencias.end(); it++){
        pq.push(make_pair(it->second, it->first));
    }

    cout << endl;
    int cont = 0;
    while (!pq.empty() && cont < 5){
        cout << pq.top().second << " -> " << pq.top().first << endl;
        pq.pop();
        cont++;
    }

    kasiski(texto);
    
}



int main(int argc, char const *argv[])
{
    
    frecuencias("POEMA_PRE.txt");

    return 0;
}