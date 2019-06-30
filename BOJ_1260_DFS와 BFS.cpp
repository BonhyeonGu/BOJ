#include<stdio.h>
int main()
{
   int numnum, gansun, startnum, a, b;
   scanf("%d %d %d", &numnum, &gansun, &startnum);
   int **injup = new int*[numnum + 1];
   for (int i = 0; i < numnum + 1; i++)
   {
      injup[i] = new int[numnum + 1];
      for (int j = 0; j < numnum + 1; j++)
         injup[i][j] = 0;
   }
   for (int i = 0; i < gansun; i++)
   {
      scanf("%d %d", &a, &b);
      injup[a][b] = 1;
      injup[b][a] = 1;
   }
   //int dfs_bangmun[1002], bangmun_index = 1;

   int dfs_take[1002] = { 0, }, stack[1002] = { 0, }, stack_index = 1;//dfs start
   stack[1] = startnum;
   dfs_take[startnum] = 1;
   printf("%d ", startnum);
   while (stack_index != 0)
   {
      int ok = true;
      for (int i = 1; i <= numnum; i++)
      {
         if (injup[stack[stack_index]][i] == 1 && dfs_take[i] == 0)
         {
            //dfs_bangmun[bangmun_index++] = i;
            stack[++stack_index] = i;
            printf("%d ", stack[stack_index]);
            dfs_take[stack[stack_index]] = 1;
            ok = false;
            break;
         }
      }
      if (ok == true)
         stack_index--;
   }
   printf("\n");//dfs end

   int bfs_take[1002] = { 0, }, queue[1002] = { 0, }, front = 1, rear = 1;//bfs start
   queue[1] = startnum;
   bfs_take[startnum] = 1;
   printf("%d ", startnum);
   while (rear != 0)
   {
      for (int i = 1; i <= numnum; i++)
      {
         if (injup[queue[rear]][i] == 1 && bfs_take[i] == 0)
         {
            //dfs_bangmun[bangmun_index++] = i;
            front = ++front % (numnum + 1);
            queue[front] = i;
            printf("%d ", queue[front]);
            bfs_take[queue[front]] = 1;
         }
      }
      rear = ++rear % (numnum + 1);
   }
   printf("\n");//bfs end

   for (int i = 0; i < numnum + 1; i++)
      delete[] injup[i];
   delete[] injup;
   return 0;
}