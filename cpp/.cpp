class Solution {
private:
    // 方向数组，表示向右、向下、向左、向上四个移动方向
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    /**
     * 以螺旋顺序遍历矩阵，返回遍历结果。
     * @param matrix 输入的二维矩阵，非空但可能为空矩阵。
     * @return 包含矩阵元素按顺时针螺旋顺序排列的一维数组。
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 如果矩阵为空，直接返回空数组
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }
        
        int rows = matrix.size(), columns = matrix[0].size();
        // 记录每个位置是否已经被访问过
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total); // 存储遍历结果

        int row = 0, column = 0;          // 当前位置
        int directionIndex = 0;            // 当前方向索引，0:右，1:下，2:左，3:上
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            // 计算下一个位置
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            // 如果下一个位置越界或已被访问，则改变方向
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4; // 顺时针转向下一个方向
            }
            // 移动到下一个位置
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};