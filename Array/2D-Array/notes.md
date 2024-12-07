## 2D Array Storage in Memory

When we initialize a 2D array `ar[row][col]`, the elements are stored in memory in a 1D format, calculated as `row * col`.

### Column-Major Format

Elements are accessed and stored using the formula `a[i][j] = i * c + j`, where:
- `i` is the row index,
- `j` is the column index,
- `c` is the total number of columns in the array.

### Visualization

Let's visualize how elements are stored in memory:

Assume we have a 2D array `ar[3][4]`:
- `3` rows
- `4` columns

Memory layout:
0 1 2 3 0 [0][0][0][0] 1 [0][0][0][0] 2 [0][0][0][0]

To access or store a value at position `[2][1]`:
- Calculate the index in 1D array format:
  - `i = 2`, `j = 1`
  - `index = i * c + j = 2 * 4 + 1 = 9`

Memory update after storing a value in `[2][1]`:

0 1 2 3 0 [0][0][0][0] 1 [0][0][0][0] 2 [0][9][0][0]


### Conclusion

Defining the number of columns `col` is crucial when initializing a 2D array, as it determines the memory layout and access pattern.
