/*
Approach:
---------
To validate a Sudoku board, we must ensure:
1. No duplicate numbers in any row
2. No duplicate numbers in any column
3. No duplicate numbers in any of the 3×3 sub-boxes

We maintain 3 matrices:
- rows[r][num]  → whether 'num' already appeared in row r
- cols[c][num]  → whether 'num' already appeared in column c
- boxes[b][num] → whether 'num' already appeared in box b

Box index is computed using:
    boxIdx = (row / 3) * 3 + (col / 3)
which uniquely maps each cell to a 0–8 box.

We iterate through each cell:
- Skip if '.'
- If the number is already present in row/col/box → invalid
- Otherwise mark it present

Time Complexity:  O(9×9) = O(1) constant work  
Space Complexity: O(9×9) = O(1) constant extra space  
Sudoku board size is always fixed (9×9), so it’s constant.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        // Track presence of numbers for each row, column, and box
        vector<vector<int>> rows(n, vector<int>(10, 0));
        vector<vector<int>> cols(n, vector<int>(10, 0));
        vector<vector<int>> boxes(n, vector<int>(10, 0));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == '.') continue;  // skip empty cells

                int num = board[r][c] - '0';

                // Check row
                if (rows[r][num] == 1) return false;
                rows[r][num] = 1;

                // Check column
                if (cols[c][num] == 1) return false;
                cols[c][num] = 1;

                // Compute unique box index (0 to 8)
                int boxIdx = (r / 3) * 3 + (c / 3);

                // Check box
                if (boxes[boxIdx][num] == 1) return false;
                boxes[boxIdx][num] = 1;
            }
        }
        return true;
    }
};

/*
Approach 2: Slightly less optimal approach
---------
We store for each digit (1–9) a list of all coordinates where it appears.

For each new occurrence of that digit:
- Compare with all previous positions
- The digit is invalid if:
    1. Same row
    2. Same column
    3. Same 3×3 box → checked by comparing their box indices

Box index formula:
    boxIdx = (row / 3) * 3 + (col / 3)

Time Complexity:
    Worst case: For each cell, we may compare with up to O(9) previous ones.
    So ~ 81 × 9 → O(1) because Sudoku is fixed size, but in generic terms O(n²)

Space Complexity:
    Storing coordinates of all digits → O(1) for fixed 9×9 board.
*/
/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, vector<pair<int,int>>> hm; // {digit → list of positions}

        int n = board.size();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == '.') continue;

                char digit = board[r][c];

                // If digit exists before, check against all previous occurrences
                if (hm.count(digit)) {
                    int currBox = (r / 3) * 3 + (c / 3);

                    for (auto& [pr, pc] : hm[digit]) {
                        int prevBox = (pr / 3) * 3 + (pc / 3);

                        // Same row, column, or 3×3 box → invalid
                        if (pr == r || pc == c || prevBox == currBox)
                            return false;
                    }
                }

                // Add current position
                hm[digit].push_back({r, c});
            }
        }

        return true;
    }
};
*/
*/