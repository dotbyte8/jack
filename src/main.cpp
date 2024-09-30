#include "main.h"

int POWER(int b, int e){
	int tmp = 1;
	for(int i=0; i<=e; i++){
		tmp = tmp*b;
	}
	return tmp;
}

const char* getLogo(){
	return "     _            _    \n    | | __ _  ___| | __\n _  | |/ _` |/ __| |/ /\n| |_| | (_| | (__|   < \n \\___/ \\__,_|\\___|_|\\_\\";
}

void Simple(const char* filename, vector<char>* chars, vector<int>* indicies){
	ofstream outFile(filename);
	int charSize = chars->size();
	cout << "Possibilities: " << POWER(charSize, indicies->size()-1) << endl;
	for(int i=0; i<POWER(charSize, indicies->size()-1); i++){
		for(int j=0; j<indicies->size()-1; j++){
			if(indicies->at(j) == charSize){
				indicies->at(j) = 0;
				indicies->at(j+1)++;
			}
		}
		for(int j=0; j<indicies->size(); j++){
			outFile << chars->at(indicies->at(j));
		}
		outFile << "" << endl;
		indicies->at(0)++;
	}
}

int main(int argc, char* argv[]){
	if(argc <= 1) cout << getLogo() << endl << "v" << VERSION << endl << endl << "use --help for a list of arguments\nor type --config to specify an config file" << endl;
	//vector<char> chrs({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
	vector<char> chrs({'P', 'W', 'S', '2', '0', '4', '5', 'p', 'a', 'e', 'd', 'R', 'S', 'N'});
	vector<int> ind({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
	Simple("output.txt", &chrs, &ind);
	return 0;
}
