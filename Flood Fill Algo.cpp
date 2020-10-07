// FLOOD FILL ALGORITHM
#include<iostream> 
using namespace std; 
  
// Setting the dimensions of the paint 
#define M 8   //preproceesor directive
#define N 8   // preprocessor directive
  
void floodFillfunction(int output[][N], int x, int y, int prevC, int newC) 
{  
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (output[x][y] != prevC) 
        return; 
    if (output[x][y] == newC)  
        return;  
  
    // Colour replacement at x,y 
    output[x][y] = newC; 
  
    floodFillfunction(output, x+1, y, prevC, newC); 
    floodFillfunction(output, x-1, y, prevC, newC); 
    floodFillfunction(output, x, y+1, prevC, newC); 
    floodFillfunction(output, x, y-1, prevC, newC); 
} 
  
void floodFill(int output[][N], int x, int y, int newC) 
{ 
    int prevC = output[x][y]; 
    floodFillfunction(output, x, y, prevC, newC); 
} 
  

int main()   // main function: the execution of the program starts from here
{ 
    int output[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                      {1, 1, 1, 1, 1, 1, 0, 0}, 
                      {1, 0, 0, 1, 1, 0, 1, 1}, 
                      {1, 2, 2, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 0, 1, 0}, 
                      {1, 1, 1, 2, 2, 2, 2, 0}, 
                      {1, 1, 1, 1, 1, 2, 1, 1}, 
                      {1, 1, 1, 1, 1, 2, 2, 1}, 
                     }; 
    int x = 4, y = 4, newC = 3; 
    floodFill(output, x, y, newC); 
  
    cout << "Updated output screen after call to floodFill: \n"; 
    for (int i=0; i<M; i++) 
    { 
        for (int j=0; j<N; j++) 
           cout << output[i][j] << " "; 
        cout << endl; 
    } 
} 
