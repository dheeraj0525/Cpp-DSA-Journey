#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    // Get matrix dimensions
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    const int size = rows * cols;
    
    // Allocate matrices
    int* matA = new int[size];
    int* matB = new int[size];
    int* result = new int[size];
    
    // Input matrix A
    cout << "\nEnter Matrix A (" << rows << "x" << cols << "):\n";
    for(int i=0; i<size; i++) 
        cin >> *(matA + i);  // Pointer notation
    
    // Input matrix B
    cout << "\nEnter Matrix B (" << rows << "x" << cols << "):\n";
    for(int i=0; i<size; i++) 
        cin >> *(matB + i);
    
    // Add matrices
    for(int i=0; i<size; i++) 
        *(result + i) = *(matA + i) + *(matB + i);
    
    // Output result
    cout << "\nResult Matrix:\n";
    for(int r=0; r<rows; r++) {
        for(int c=0; c<cols; c++) 
            cout << *(result + r*cols + c) << " ";
        cout << endl;
    }
    
    // Cleanup memory
    delete[] matA;
    delete[] matB;
    delete[] result;
}
