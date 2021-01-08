//Name: Abanoub Samir Gergis
//ID: 20190001
//Group: G.7
#include <iostream>

using namespace std;

template <class tmp>

class MyMatrix{
private:
    tmp** m;
    int rows,cols;

public:
    MyMatrix(int ,int ); //constructor takes matrix dimensions
    MyMatrix(const MyMatrix &);
    bool addElementAt(int r, int c, tmp elem); //adds an element elem at the specified row r, and column c //returns false if the passed r and c are not within range and true otherwise
    bool getElementAt(int r, int c, tmp element); //gets an element elem at the specified row r, and column c
    //returns false if the passed r and c are not within range and true otherwise
    int getRows(); //returns number of rows
    int getCols(); //returns number of columns
    void displayMatrix(); //displays the 2D array to the screen
    ~MyMatrix();
};

template <class tmp>
MyMatrix<tmp>::MyMatrix(int r,int c){
    rows=r;
    cols=c;
    m= new tmp*[r];
    for(int i=0;i<r;i++){
        m[i]= new tmp[c];
    }
}

template <class tmp>
MyMatrix<tmp>::MyMatrix(const MyMatrix &mat){
    rows=mat.rows;
    cols=mat.cols;
    m= new tmp*[rows];
    for(int i=0;i<rows;i++){
        m[i]= new tmp[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
           m[i][j]=mat.m[i][j];
        }
    }
}

template <class tmp>
bool MyMatrix<tmp>::addElementAt(int r,int c,tmp elem){
    if(r>=rows || c>=cols || r<0 || c<0){
        cout << "out of the range" << endl;
        return false;
    }
    else {
        m[r][c]=elem;
        return true;}
}

template <class tmp>
bool MyMatrix<tmp>::getElementAt(int r, int c, tmp element)
	{
		if (r < rows && c < cols)
		{
			cout << "the element = " << m[r][c];
			return true;
		}
		else
			return false;
	}
template <class tmp>
int MyMatrix<tmp>::getRows(){
    return rows;
}

template <class tmp>
int MyMatrix<tmp>::getCols(){
        return cols;
}

template <class tmp>
void MyMatrix<tmp>::displayMatrix(){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <class tmp>
MyMatrix<tmp>::~MyMatrix(){
    delete[] m;
}

int main(){

 cout << " matrix 1\n";
	cout << "///////////////////////\n";
	MyMatrix <string>M1(3, 2);
	M1.addElementAt(0, 0, "abanob");
	M1.addElementAt(0, 1, "samir");
	M1.addElementAt(1, 0, "abanob");
	M1.addElementAt(1, 1, "samir");
	M1.addElementAt(2, 0, "abanob");
	M1.addElementAt(2, 1, "samir");
	M1.displayMatrix();
	cout << "Rows = " << M1.getRows() << endl;
	cout << "Columns = " << M1.getCols() << endl;
	cout << "matrix 2\n";
	cout << "///////////////////////\n";
	MyMatrix <float>M2(4, 2);
	M2.addElementAt(0, 0, 0.0);
	M2.addElementAt(0, 1, 0.5);
	M2.addElementAt(1, 0, 1.0);
	M2.addElementAt(1, 1, 1.5);
	M2.addElementAt(2, 0, 2.0);
	M2.addElementAt(2, 1, 2.5);
	M2.addElementAt(3, 0, 3.0);
	M2.addElementAt(3, 1, 3.5);
	M2.displayMatrix();
	M2.getElementAt(1, 0, 1.0);
	MyMatrix<float>M3(M2);
	M3.displayMatrix();
    return 0;
}
