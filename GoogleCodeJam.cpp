

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <boost/lexical_cast.hpp>
using namespace std;


string solution(int cred, vector<int> original, vector<int> copy, int size);


int main(int argc, char** argv) {
	ifstream infile;
	infile.open("Credit.txt");
	string line;
	vector<string> inputLines;

	//If infile is open, append each line to the vector
	if(infile.is_open()){
		while(getline(infile, line)){
			inputLines.push_back(line);
		}
	}
	else{
		cout << "Unable to open";
	}
	infile.close();


	ofstream outfile("output.txt", std::ofstream::out);
	//Move counter by 3, because cases are grouped in lines of 3
	for(unsigned int i = 1; i < inputLines.size(); i+= 3){
		int credit = boost::lexical_cast<int>(inputLines[i]);

		vector<int> items;
		vector<int> itemsCopy;
		stringstream stream(inputLines[i+2]);
		int x;
		while(stream >> x){
			items.push_back(x);
			itemsCopy.push_back(x);
		}

		outfile << solution(credit,
							items,
							itemsCopy,
							items.size())
				<< '\n';
	}
	outfile.close();
	return 0;
}

string solution(int cred, vector<int> original, vector<int> copy, int size){
        for(int i = 0; i < size; i++ ){
            for (int ii = 0; ii < size; ii++){
            	if(i != ii){
            		if(original[i] + copy[ii] == cred){
            			return boost::lexical_cast<string>(i+1) + " " + boost::lexical_cast<string>(ii + 1);
                }
            	}
            }
        }
        return "";
    }
