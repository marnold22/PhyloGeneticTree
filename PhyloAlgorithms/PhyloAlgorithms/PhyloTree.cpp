#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;


#define TABLE_SIZE 100

class Point {
private:
    
public:
    string name;
    string sequence;
    Point(string title = "Default", string seq = "")
    {
        name = title;
        sequence = seq;
    }
    
};

/*
 string PhyloTreeAlgorithm(vector<Point> Seqs)
 {
	vector<int> scorefinal;
	int score = 0;
	vector<vector<int>> dp;
	
	int cases = Seqs.size();
	for (int i = 0; i < cases; i++) {//Changes seq compared to all others
 dp.clear(); 	//clear vector dp after each sequence
 for (int m = 0; m < Seqs[i].sequence.size(); m++) {// iterates through Seq A comparing to later seq
 
 for (int j = i+1; j < cases; j++) {//Changes seq being compared to
 for (int n = 0; n < Seqs[j].sequence.size(); n++) {//iterates through Seq B being compared to
 if (Seqs[i].sequence[m] == Seqs[j].sequence[n]) {
 score += 1;
 }
 else if ((Seqs[i].sequence[m]=='A' || Seqs[i].sequence[m] == 'G') && ( Seqs[j].sequence[n]=='G'  || Seqs[j].sequence[n] == 'A')) { // checks for A-G transversions
 score -= .66;
 }
 else if((Seqs[i].sequence[m] == 'T' || Seqs[i].sequence[m] == 'C') && (Seqs[j].sequence[n] == 'C' || Seqs[j].sequence[n] == 'T')) { // checks for C-T transversions
 score -= .66;
 }
 else {
 score -= 1;   //// need to add another else if for gaps....
 }
 if (m > 1 && n > 1)
 score = max(dp[m - 1][n], dp[m - 1][n - 1]) + score;
 else if (m == 0);
 //score += score;
 else if (n == 0)
 score += dp[m - 1][n];
 
 
 
 dp[m][n] = score;
 
 }
 }
 }
 scorefinal.push_back(score);
	}
 
 
	//do math with all the final scores to output the map format
	return "success";
 }
 */


string PhyloTreeAlgorithm(vector<Point> Seqs)
{
    vector<int> scorefinal;
    
    vector<vector<int>> dp;
    
    int cases = Seqs.size();
    for (int i = 0; i < cases-1; i++)
    {
        for (int j = i + 1; j < cases; j++)
        {
            int table[TABLE_SIZE][TABLE_SIZE] = { {0} };
            for (int m = 0; m < Seqs[i].sequence.size(); m++) // go through entire string
            {
                for (int n = 0; n < Seqs[j].sequence.size(); n++) //compare with entire other string
                {
                    if (Seqs[i].sequence[m] == Seqs[j].sequence[n]) //if equal, score is 1
                        table[m][n] = 1;
                    else if ((Seqs[i].sequence[m] == 'A' || Seqs[i].sequence[m] == 'G') && (Seqs[j].sequence[n] == 'G' || Seqs[j].sequence[n] == 'A')) //if one is A and other is G (or vice verca)
                        table[m][n] = -0.66;
                    else if ((Seqs[i].sequence[m] == 'T' || Seqs[i].sequence[m] == 'C') && (Seqs[j].sequence[n] == 'C' || Seqs[j].sequence[n] == 'T')) //if one is A and other is G (or vice verca)
                        table[m][n] = -0.66;
                    else
                        table[m][n] = -1;
                }
            }
            int m = 0, n = 0;
            int score = 0;
            while (m < TABLE_SIZE && n < TABLE_SIZE)
            {
                //3 cases, go right if values equal or if right is better, go diagnol if diagnol is better
                if (table[m][n + 1] <= table[m + 1][n + 1])
                {
                    score += table[m + 1][n + 1];
                    m++;
                    n++;
                }
                else
                {
                    score += table[m][n + 1];
                    n++;
                }
            }
            scorefinal.push_back(score);
        }
    }
    return "succeed";
}




/*PhyloTreeAlgorithm(){
 
 2.) Compare each sequence to one another
 - ScoringFn all differences score 1pt except:
 - Transitions (A-G) (T-C) (occurs 66% of the time so) = .66pt
 - Transversions anything else = 1pt
 3.5) If( difference is A-G || T-C)
 score = score - .66;
 ELSE
 score = score - 1;
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
    char escape = 'N';
    int exit = 1;
    while (exit == 1) {
        cout << "Please input your Sequence Name followed by the Sequence" << endl;
        cin >> name >> seq;
        Seqs.push_back(Point(name, seq));
        cout << "Done? : (Y/N) ";
        cin >> escape;
        if (escape == 'Y')
            exit = 0;
    }
    
    //call algorithm PhyloTreeAlgorithm(GENE_SEQ)
    cout << PhyloTreeAlgorithm(Seqs);
    
    Point yolo = (name = "john", seq = "abc");
    
    
    //output scores in text template
    cout << Seqs.front().name << endl;
    cout << Seqs[0].name << endl;
    
    
    
    
    
    //if possible link to website to generate tree
    
    
}
