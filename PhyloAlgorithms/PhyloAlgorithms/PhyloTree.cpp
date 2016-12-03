#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Point {
private:
	string name;
	string sequence;
public:
	Point(string title = "Default", string seq = "")
	{
		name = title;
		sequence = seq;
	}

};

string PhyloTreeAlgorithm()
{

}


/*PhyloTreeAlgorithm(){

	2.) Compare each sequence to one another
		- ScoringFn all differences score 1pt except:
			- Transitions (A-G) (T-C) (occurs 66% of the time so) = .66pt
			- Transversions anything else = 1pt

	3.5) If( difference is A-G || T-C)
			score = score + .66;
		ELSE
			score = score + 1;

	3.) Table/list of all scores

	4.) Math

	5.) Output scores in newick format .txt

}*/




int main()
{
	vector<Point> Seqs;
	string name;
	string seq;


	//read in gene sequences
	while (cin) {
		cout << "Please input your Sequence Name followed by the Sequence" << endl;
		cin >> name >> seq;
		Seqs.push_back(Point(name, seq));
	}

	//call algorithm PhyloTreeAlgorithm(GENE_SEQ)
	PhyloTreeAlgorithm();




	//output scores in text template






	//if possible link to website to generate tree


}