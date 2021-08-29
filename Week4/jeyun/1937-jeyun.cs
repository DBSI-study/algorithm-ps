using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

class Program
{
    static int n, result = 0;
    static int[,] forest;
    static int[,] max_result;

    static void Main(string[] args)
    {
        int max1 = 0, max2;
        n = int.Parse(Console.ReadLine());
        forest = new int[n,n];
        max_result = new int[n, n];
        for (int i = 0; i < n; i++)
        {
            string[] read_s = Console.ReadLine().Split(' ');

            for (int j = 0; j < n; j++)
                forest[i, j] = int.Parse(read_s[j]);
        }
        // 0 1 2 3 상 하 좌 우
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int[] cur = new int[] { i, j };
                int t = forest[cur[0], cur[1]];
                max1 = Math.Max(DFS_recur(cur, t, 0, forest), DFS_recur(cur, t, 1, forest));
                max2 = Math.Max(DFS_recur(cur, t, 2, forest), DFS_recur(cur, t, 3, forest));
                max1 = Math.Max(max1, max2);
                result = Math.Max(result, max1);
            }
        }

        Console.WriteLine(result);
    }

    static int DFS_recur(int[] cur, int cur_num, int next, int[,] cur_forest)
    {
        int next_num, max = 1;
        int x_move = next == 0 ? -1 : next == 1 ? 1 : 0
            , y_move = next == 2 ? -1 : next == 3 ? 1 : 0;

        if (cur[0] + x_move >= 0 && cur[0] + x_move < n && 
            cur[1] + y_move >= 0 && cur[1] + y_move < n)
        {
            if (max_result[cur[0] + x_move, cur[1] + y_move] > 0)
                return max + max_result[cur[0] + x_move, cur[1] + y_move];
            else
            {
                next_num = cur_forest[cur[0] + x_move, cur[1] + y_move];
                if (next_num > cur_num)
                {
                    cur_forest[cur[0], cur[1]] = 0;
                    cur[0] += x_move;
                    cur[1] += y_move;
                    if (next == 0)
                    {
                        max = Math.Max(DFS_recur(cur, next_num, 0, cur_forest), DFS_recur(cur, next_num, 2, cur_forest));
                        max = Math.Max(max, DFS_recur(cur, next_num, 3, cur_forest));
                        max_result[cur[0], cur[1]] = max;
                    }
                    else if (next == 1)
                    {
                        max = Math.Max(DFS_recur(cur, next_num, 1, cur_forest), DFS_recur(cur, next_num, 2, cur_forest));
                        max = Math.Max(max, DFS_recur(cur, next_num, 3, cur_forest));
                        max_result[cur[0], cur[1]] = max;
                    }
                    else if (next == 2)
                    {
                        max = Math.Max(DFS_recur(cur, next_num, 0, cur_forest), DFS_recur(cur, next_num, 1, cur_forest));
                        max = Math.Max(max, DFS_recur(cur, next_num, 2, cur_forest));
                        max_result[cur[0], cur[1]] = max;
                    }
                    else if (next == 3)
                    {
                        max = Math.Max(DFS_recur(cur, next_num, 0, cur_forest), DFS_recur(cur, next_num, 1, cur_forest));
                        max = Math.Max(max, DFS_recur(cur, next_num, 3, cur_forest));
                        max_result[cur[0], cur[1]] = max;
                    }

                    max += 1;
                    cur[0] -= x_move;
                    cur[1] -= y_move;

                    cur_forest[cur[0], cur[1]] = cur_num;
                }
            }
        }
        return max;
    }
}
