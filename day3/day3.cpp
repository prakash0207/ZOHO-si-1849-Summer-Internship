#include <iostream>
#include <memory>
#include <cassert>
using namespace std;
static int counter_for_check;
static int sum;
static int counter_for_group=0;
int R = 5;
int C = 5;
//int R;
//int C

//class Matrix is used to create matrix using dynamically allocated memory with shared pointer(one of the smart pointers). Automatic deallocation of memory.
class Matrix
{
private:
    int rows;
    int cols;
    shared_ptr<shared_ptr<int>> Mat;

public:
    Matrix() = default;

    Matrix(const int& rows, const int& cols) : rows(rows), cols(cols)
    {

        Mat.reset(new shared_ptr<int>[rows], [](shared_ptr<int>* p) { delete[] p; });
        for (int i = 0; i < rows; ++i)
        {
            Mat.get()[i].reset(new int[cols], [](int* p) { delete[] p; });
        }
        for (int i = 0; i < (*this).rows; ++i)
            for (int j = 0; j < (*this).cols; ++j)
                (*this)[i][j] = 0;
    }

    int* operator[](const int& index) const
    {
        return Mat.get()[index].get();
    }
};

void findLeader(int *p)
{
    int leader;
    leader = p[0];
    for(int i=1;i<counter_for_group;i++)
    {
        if(leader<p[i])
        {
            leader = p[i];
        }
    }
    cout<<"The Leader is: "<<leader<<endl;
    delete p;
}

bool isSafe(Matrix buildings, int x, int y, Matrix sol, Matrix vis)
{
	if (x >= 0 && x < R && y >= 0 && y < C && buildings[x][y] > 0)
    {
        if(sol[x][y] == 0)
        {
            sum += buildings[x][y];
            vis[x][y] = 1;
        }
        return true;
    }
	return false;
}


bool solveBuildingUtil(Matrix buildings, int x, int y, Matrix sol, Matrix vis)
{
	if (counter_for_check == 16)
    {
		sol[x][y] = 1;
		return true;
	}
	if (isSafe(buildings, x, y, sol, vis) == true)
    {
		counter_for_check += 1;
		if (sol[x][y] == 1)
			return false;
		sol[x][y] = 1;
		if (solveBuildingUtil(buildings, x + 1, y, sol, vis) == true)
		{
			return true;
		}
		if (solveBuildingUtil(buildings, x, y + 1, sol, vis) == true)
        {
			return true;
        }

        if (solveBuildingUtil(buildings, x-1, y, sol, vis) == true)
        {
			return true;
        }

        if (solveBuildingUtil(buildings, x, y-1, sol, vis) == true)
        {
			return true;
        }
		sol[x][y] = 0;
		return false;
	}
	return false;
}


bool solveBuildings(Matrix buildings, Matrix sol, Matrix vis)
{
    int *p = new int[R*C];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(buildings[i][j]>0 && vis[i][j]== 0)
            {
                if (solveBuildingUtil(buildings, i, j, sol, vis) == false)
                {
                    cout<<sum<<endl;
                    p[counter_for_group] = sum;
                    counter_for_group += 1;
                    sum = 0;
                    counter_for_check = 0;
                }
            }
        }
    }
    findLeader(p);
    return true;
}


int main()
{
/* Input can be obtained from the user

    cout<<"Enter No of rows: "<<endl;
    cin>>R;
    cout<<"Enter No of columns: "<<endl;
    cin>>C;
    Matrix a(R,C);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>a[i][j];
        }
    }
*/
    //Hard coded data for easier execution
    Matrix a(R, C);
    a[0][0] = 0;
    a[0][1] = 2;
    a[0][2] = 0;
    a[0][3] = 3;
    a[0][4] = 1;

    a[1][0] = 4;
    a[1][1] = 1;
    a[1][2] = 2;
    a[1][3] = 0;
    a[1][4] = 0;

    a[2][0] = 2;
    a[2][1] = 0;
    a[2][2] = 0;
    a[2][3] = 0;
    a[2][4] = 0;

    a[3][0] = 0;
    a[3][1] = 1;
    a[3][2] = 0;
    a[3][3] = 2;
    a[3][4] = 3;

    a[4][0] = 0;
    a[4][1] = 0;
    a[4][2] = 1;
    a[4][3] = 1;
    a[4][4] = 0;



    Matrix b(R,C);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            b[i][j] = 0;
        }
    }
    Matrix c(R,C);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            c[i][j] = 0;
        }
    }

    solveBuildings(a,b,c);

}
