/*
    A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.
    
    Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.
    
    You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
    
    BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
    BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
    Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.
    
    For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.
    
     
    
    Example 1:
    
    
    
    Input: mat = [[0,0],[1,1]]
    Output: 0
    Example 2:
    
    
    
    Input: mat = [[0,0],[0,1]]
    Output: 1
    Example 3:
    
    
    
    Input: mat = [[0,0],[0,0]]
    Output: -1
    Example 4:
    
    
    
    Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
    Output: 1
     
    
    Constraints:
    
    1 <= mat.length, mat[i].length <= 100
    mat[i][j] is either 0 or 1.
    mat[i] is sorted in a non-decreasing way.
*/



/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
       //get rows and col in the matrix
        int n = binaryMatrix.dimensions()[0], m = binaryMatrix.dimensions()[1];
        int x = m-1, y = 0, one=0;
		
	// we start with the top-right index of matrix and move our way through to bottom left
        while(x >= 0 and y < n){
            if(y == n || x < 0) // if we anytime we hit the bottom or left border of matrix, time to break, should have answer by now
                break;
            if(binaryMatrix.get(y,x)){  // follow the path of '1', if current element is 1, move left
                one++; x--;
            }
            else  //if the current element is a '0' move down
                y++;
        }
        if(one) return x+1; //this is to check the corner case when the matrix is entirely '0', there should be atleast one '1' for a valid answer, else return -1
        return -1;
    }
};
