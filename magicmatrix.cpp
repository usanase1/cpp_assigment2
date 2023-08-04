# include <iostream>
bool is_magic(int s, int k[][100]);
using namespace std;
int main ()
{
    int n, i, j;

    cout<<"\n\t Hello enter the dimension to get its  correspondng magic matrix\t:";
    cin>> n;
    if (n % 2 == 0)
    {
        cout<<"\n\t we don't support matrix with even order\n\n";
    }
    else{
         int m[100][100];

        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                cout<<"\n\t well done now enter the number at possition "<<"["<<i<<"]["<<j<<"]\t:";
                cin>>m[i][j];
            }
        }
        if (is_magic(n, m)){
            cout<<"\n\t That is a magic square of order "<<n<<"\n\n";
        }
        else{
            cout<<"\n\t In order "<<n<<" That isn't a magic square\n\n";
        }
    }

    return 0;
}
bool is_magic(int s, int k[][100]){

    int mdiagonal = 0;
    int sdiagonal = 0;
    int col_sum = 0;
    int row_sum = 0;
    int column[s];
    int rows[s];
    bool match = false;

    for (int r = 0; r < s; r++){
        mdiagonal += k[r][r];
    }
    for (int r = 0; r < s; r++){
        sdiagonal += k[r][s-r-1];
    }
    if (mdiagonal != sdiagonal) //return value basing on sum of diagonal.
    {
        return false;
    }
   for (int r = 0; r < s; r++)
   {
    for (int c = 0; c < s; c++)
    {
        row_sum += k[r][c];
        col_sum += k[c][r];
    }
        rows[r] = row_sum;
        column[r] = col_sum;
   }
   for (int i = 0; i < s; i++)
   {
    if (rows[i] != column[i]){
        match = true;
   }
   
      if (match){
           return false;
        }
   
}
    return true;
}

	
