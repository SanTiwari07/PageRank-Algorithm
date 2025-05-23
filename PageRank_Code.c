#include <stdio.h>

int main()
{
    // asks for total web
    int web;
    int r, c;
    printf("Enter total number of web: ");
    scanf("%d", &web);

    // place where matrix stores
    float input[web][web];
    for (int b1 = 0; b1 < web; b1++)
    {
        for (int d1 = 0; d1 < web; d1++)
        {
            input[b1][d1] = 0;
        }
    }

    // question to user
    printf("If link is 1---->2 please write 2 1\n");
    printf("If you want to end please enter '0 0'\n");
    for (int a = 0; a < web * web; a++)
    {
        printf("Enter %d link: ", a + 1);
        scanf("%d %d", &r, &c);
        if (r > web || c > web || r < 0 || c < 0)
        {
            a--;
            printf("Enter valid !\n");
        }
        if (input[r - 1][c - 1] == 1)
        {
            printf("Already used :( Please put different.\n");
            a--;
            continue;
        }
        if (r == 0 && c == 0)
        {
            break;
        }
        input[r - 1][c - 1] = 1;
    }

    // print input matrix
    printf("Adjacency Matrix:\n");
    for (int b = 0; b < web; b++)
    {
        for (int d = 0; d < web; d++)
        {
            printf("%.2f ", input[b][d]);
        }
        printf("\n");
    }

    // gives sum of column
    int sum[web];
    for (int r = 0; r < web; r++)
    {
        sum[r] = 0;
    }
    for (int q = 0; q < web; q++)
    {
        for (int w = 0; w < web; w++)
        {
            sum[q] += input[w][q];
        }
    }
    // it is matrix which stores 1/freq
    printf("\nTransition Matrix:\n");
    float input2[web][web];
    for (int xx = 0; xx < web; xx++)
    {
        for (int yy = 0; yy < web; yy++)
        {
            input2[xx][yy] = 0;
        }
    }
    for (int stw = 0; stw < web; stw++)
    {
        if (sum[stw] == 0)
        {

            for (int u9 = 0; u9 < web; u9++)
            {
                input2[u9][stw] = 0;
            }
        }
        else
        {
                for (int u = 0; u < web; u++)
                {
                    input2[u][stw] = input[u][stw] / sum[stw];
                }
            
        }
    }

    // prints input2 matrix
    for (int b3 = 0; b3 < web; b3++)
    {
        for (int d3 = 0; d3 < web; d3++)
        {
            printf("%.2f ", input2[b3][d3]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Since your total web is %d\nYour zeroth iteration is equally distributed\nIteration 0 is\n", web);

    // this is iteration 0 matrix
    float iteration0[web][1];
    for (int r1 = 0; r1 < web; r1++)
    {
        iteration0[r1][0] = (1.0 / web);
    }
    for (int rr = 0; rr < web; rr++)
    {
        printf("%.5f\n", iteration0[rr][0]);
    }

    int illu;
    printf("Total iteration you want: ");
    scanf("%d", &illu);

    for (int j7 = 0; j7 < illu; j7++)
    {
        printf("iteration %d: \n", j7 + 1);
        float iteration[web][1];
        for (int i5 = 0; i5 < web; i5++)
        {
            iteration[i5][0] = 0;
        }

        for (int i = 0; i < web; i++)
        {
            for (int k = 0; k < web; k++)
            {
                iteration[i][0] += input2[i][k] * iteration0[k][0];
            }
        }
        for (int i7 = 0; i7 < web; i7++)
        {
            iteration0[i7][0] = iteration[i7][0];
        }

        for (int rrr = 0; rrr < web; rrr++)
        {
            printf("%.5f\n", iteration[rrr][0]);
        }
        printf("\n");
    }
    int rank[web];
    for (int i = 0; i < web; i++)
    {
        rank[i] = 1;
    }

    for (int i = 0; i < web; i++)
    {
        for (int j = 0; j < web; j++)
        {
            if (iteration0[i][0] > iteration0[j][0])
            {
                rank[i]++;
            }
        }
    }
    printf("PageRank is: \n");
    for (int ggf = 0; ggf < web; ggf++)
    {
        printf("%d\n", rank[ggf]);
    }
    return 0;
}
