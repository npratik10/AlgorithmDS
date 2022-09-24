#pragma once

#include "includes.h"

class nqueens
{
public:
    class matched_row_col
    {
    public:
        int row{ -1 };
        int col{ -1 };
    };

    std::vector<matched_row_col> matched_vector;

    void print_vec2d(std::vector<std::vector<int>>& result_vect)
    {
        for (auto vec1d : result_vect)
        {
            for (auto val : vec1d)
            {
                std::cout << " " << val;
            }
            std::cout << "\n";
        }
    }

    bool check_valid(std::vector<std::vector<int>>& result_vect, int& row, int& col)
    {
        bool ret_val = true;
        for (auto placed_row_col : matched_vector)
        {
            if (placed_row_col.col == col)
            {
                ret_val = false;
                break;
            }
            else if (placed_row_col.row == row)
            {
                ret_val = false;
                break;
            }

            float  slope = ((float)col - (float)placed_row_col.col) / ((float)row - (float)placed_row_col.row);
            if ((slope == 1) || (slope == -1))
            {
                ret_val = false;
                break;
            }
        }
        return ret_val;
    }

    void solve(std::vector<std::vector<int>>& result_vect, int row, int& n)
    {
        if (row == n)
        {
            print_vec2d(result_vect);
            std::cout << "\n";
            return;
        }

        for (int col = 0; col < n; col++)
        {
            result_vect.at(row).at(col) = 1;

            if (check_valid(result_vect, row, col))
            {
                matched_vector.push_back(matched_row_col{row, col});
                solve(result_vect, ++row, n);
                row--;
                matched_vector.pop_back();
                result_vect.at(row).at(col) = 0;
            }
            else
                result_vect.at(row).at(col) = 0;
        }
    }

    std::vector<std::vector<int>> solveNQueens(int n)
    {
        std::vector<std::vector<int>> result_vect(n, std::vector<int>(n, 0));
        int row = 0;
        solve(result_vect, row, n);
        return result_vect;
    }
};
