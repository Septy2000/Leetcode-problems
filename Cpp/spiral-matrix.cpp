// https://leetcode.com/explore/interview/card/bloomberg/68/array-and-strings/395/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int horiz_start = 0;
        int horiz_end = matrix[0].size();
        int vert_start = 0;
        int vert_end = matrix.size();
        while(horiz_start < horiz_end && vert_start < vert_end) {
            for (int i = horiz_start; i < horiz_end; i++) {
                if (result.size() == matrix.size() * matrix[0].size()) return result;
                result.push_back(matrix[vert_start][i]);
            }
            vert_start++;

            for (int i = vert_start; i < vert_end; i++) {
                if (result.size() == matrix.size() * matrix[0].size()) return result;
                result.push_back(matrix[i][horiz_end - 1]);
            }
            horiz_end--;

            for (int i = horiz_end - 1; i >= horiz_start; i--) {
                if (result.size() == matrix.size() * matrix[0].size()) return result;
                result.push_back(matrix[vert_end - 1][i]);
            } 
            vert_end--;

            for (int i = vert_end - 1; i >= vert_start; i--) {
                if (result.size() == matrix.size() * matrix[0].size()) return result;
                result.push_back(matrix[i][horiz_start]);
            }
            horiz_start++;
        }
        return result;
    }
};