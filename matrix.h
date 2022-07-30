#include<stdio.h>
#include<unistd.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define ROW 10
#define COLUMN 10

void welcome();
int menu();

int takeIntegerChoice();

int ChoiceyourOperation( int choice );

void Matrix_Addition( int** arr , int** arr2 , int ,int ,int , int);
void matrix_Subtraction( int** arr1 , int** arr2 , int ,int ,int , int );
void Matrix_Multiplication( int** arr1 , int** arr2 , int ,int ,int , int );
void Transpose_Matrix(int** arr,int,int,int **result);
void Inverse_of_Matrix();
int cofactor_matrix(int** matrix,int **cofactor ,int r , int  c);
int determinant(int  **matrix , int r , int c);




void welcome() {

    puts("\t\t\t\t---------------------------------------------------------------------");
    puts("\t\t\t\t|                                                                   |");
    puts("\t\t\t\t|                              WEL COME                             |");
    puts("\t\t\t\t|                                 TO                                |");
    puts("\t\t\t\t|                  Matrix And Determinant Calculator                |");
    puts("\t\t\t\t|                                                                   |");
    puts("\t\t\t\t---------------------------------------------------------------------\n\n\n");

}

int menu() {

    usleep(1000000);

    puts("\t\t\t\t            MATRIX OERATION: \n");
    puts("\t\t\t\t               1. Matrix addition of two matrix");
    puts("\t\t\t\t               2. Matrix Subtraction of two matrix");
    puts("\t\t\t\t               3. Matrix multiplication of two matrix");
    puts("\t\t\t\t               4. Transpose of matrix");
    puts("\t\t\t\t               5. Inverse of matrix");
    puts("\t\t\t\t               6. Find Cofactor Matrix");
    puts("\t\t\t\t               7. Find Adjoint Matrix\n");

    puts("\t\t\t\t            DETERMINANT OPERATION\n");
    puts("\t\t\t\t               8. Find determinant");
    puts("\n\t\t\t\t               9. Turn Off \n\n");

    usleep(1000000);

    start:
    printf("\t\t\t\tEnter your choice: ");
    int choice = takeIntegerChoice();

    if ( choice <= 9 && choice > 0 ) {

        return choice;

    } else {

        printf("\t\t\t\tYour choice between 1 to 9 \n\n");
        fflush(stdin);
        goto start;
    }

}

int takeIntegerChoice() {

    int n;

    while ( !scanf("%d",&n)) {

        usleep(1000000);
        printf("\n\t\t\t\tPlease enter an integer value.\n");
        printf("\t\t\t\tTry again......\n\n");
        fflush(stdin);
        usleep(1000000);
        printf("\t\t\t\tEnter your choice: ");
    }

    return n;
}

int ChoiceyourOperation( int choice) {

    system("cls");
    usleep(1000000);
    welcome();

    if ( choice == 9 ) {
        goto last;
    }

    //if start //Find Determinant *******************************************

    if ( choice == 8 ) {


        int det,**matrix,r,c;

        printf("\n\t\t\t\tEnter the row of a matrix: ");
        scanf("%d",&r);

        printf("\t\t\t\tEnter the column of a matrix: ");
        scanf("%d",&c);

        matrix = (int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            matrix[i] = (int *) malloc( c * sizeof( int ));
        }

        printf("\n\n\t\t\t\tEnter matrix element\n");

        for ( int i = 0 ; i < r ; i++ )
        {
            for ( int j = 0 ; j < c ; j++ )
            {
                printf("\t\t\t\ta%d%d = ",i,j);
                scanf("%d",&matrix[i][j]);
            }
        }

        printf("\n\t\t\t\tMatrix is\n\n");

        for ( int i = 0 ; i < r ; i++ )
        {
            printf("\t\t\t\t");

            for ( int j = 0 ; j < c ; j++ )
            {
                printf("   %d    ",matrix[i][j]);
            }
            printf("\n");
        }

        det = determinant(matrix,r,c);

        printf("\n\n\t\t\t\tDeterminant is %d",det);

        goto determinant;
     }

     //if end *************************************************************

     //inverse ***********************-----------------

     if ( choice == 5 ) {
         goto inverse;
     } //End /**************************************----

     //find transpose *******************************************************

     if( choice == 4) {

            int r,c,arr[10][10],result[10][10];

            printf("\n\t\t\t\tEnter the row of a matrix: ");
            scanf("%d",&r);

            printf("\t\t\t\tEnter the column of a matrix: ");
            scanf("%d",&c);

            printf("\n\t\t\t\tEnter elements of a matrix:\n\n");
            for ( int i = 0 ; i < r ; i++ )
            {
                for ( int j = 0 ; j < c ; j++ )
                {
                    printf("\t\t\t\ta%d%d = ",i,j);
                    scanf("%d",&arr[i][j]);
                }
            }

            printf("\n\t\t\t\tMatrix is:\n\n");
            for ( int i = 0 ; i < r ; i++ )
            {
                printf("\n\t\t\t\t");

                for ( int j = 0 ; j < c ; j++ )
                {
                    printf("   %d   ",arr[i][j]);
                }

                printf("\n");
            }

             //transpose

            for ( int i = 0 ; i < c ; i++ )
            {
                for ( int j = 0 ; j < r ; j++ )
                {
                    result[i][j] = arr[j][i];
                }
            }


            printf("\n\t\t\t\tAfter Transpose , Matrix is:\n\n");

            for ( int i = 0 ; i < c ; i++ )
            {
                printf("\n\t\t\t\t");

                for ( int j = 0 ; j < r ; j++ )
                {
                    printf("   %d   ",result[i][j]);
                }

                printf("\n");
            }

                goto transpose;

     } //End of Transpose*******************************************************************

     //Cofactor Matrix

     if ( choice == 6 ) {

        int r,c;
        int **mtr,**cofactor;

        printf("\n\t\t\t\tEnter the row of matrix: ");
        scanf("%d",&r);

        printf("\t\t\t\tEnter the column of matrix: ");
        scanf("%d",&c);

        mtr = ( int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            mtr[i] = (int *) malloc( c * sizeof( int ));
        }

        cofactor = ( int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            cofactor[i] = (int *) malloc( c * sizeof( int ));
        }

         printf("\n\t\t\t\tEnter elements of matrix:\n\n");
        for ( int i = 0 ; i < r ; i++ )
        {
            for ( int j = 0 ; j < c ; j++ )
            {
                printf("\t\t\t\ta%d%d = ",i,j);
                scanf("%d",&mtr[i][j]);
            }
        }


        printf("\n\t\t\t\tmatrix is:\n\n");
        for ( int i = 0 ; i < r ; i++ )
        {
            printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("   %d   ",mtr[i][j]);
        }

            printf("\n");
        }



        cofactor_matrix(mtr,cofactor,r,c);

        printf("\n\t\t\t\tCofactor Matrix is:\n\n");

        for ( int i = 0 ; i < r ; i++ )
        {
            printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("   %d   ",cofactor[i][j]);
        }

            printf("\n");
        }

        goto cof;
     }

     //Adjoint matrix

     if ( choice == 7 ) {

        int r,c;
        int **mtr,**cofactor,**transpose;

        printf("\n\t\t\t\tEnter the row of matrix: ");
        scanf("%d",&r);

        printf("\t\t\t\tEnter the column of matrix: ");
        scanf("%d",&c);

        mtr = ( int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            mtr[i] = (int *) malloc( c * sizeof( int ));
        }

        cofactor = ( int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            cofactor[i] = (int *) malloc( c * sizeof( int ));
        }

        transpose = ( int **) malloc( r * sizeof( int* ));

        for ( int i = 0 ; i < c ; i++ )
        {
            transpose[i] = (int *) malloc( c * sizeof( int ));
        }


        printf("\n\t\t\t\tEnter elements of matrix:\n\n");
        for ( int i = 0 ; i < r ; i++ )
        {
            for ( int j = 0 ; j < c ; j++ )
            {
                printf("\t\t\t\ta%d%d = ",i,j);
                scanf("%d",&mtr[i][j]);
            }
        }


        printf("\n\t\t\t\tmatrix is:\n\n");
        for ( int i = 0 ; i < r ; i++ )
        {
            printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("   %d   ",mtr[i][j]);
        }

            printf("\n");
        }

        cofactor_matrix(mtr,cofactor,r,c);
        Transpose_Matrix(cofactor,r,c,transpose);

        printf("\n\t\t\t\tAdjoint Matrix is:\n\n");

        for ( int i = 0 ; i < r ; i++ )
        {
            printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("   %d   ",transpose[i][j]);
        }

            printf("\n");
        }

        goto adjoint;
     }




    //Enter Two Matrix ---------------------------------------------------------------------------


    int r1,c1,r2,c2;
    int **mtr1,**mtr2;

    printf("\n\t\t\t\tEnter the row of 1st matrix: ");
    scanf("%d",&r1);

    printf("\t\t\t\tEnter the column of 1st matrix: ");
    scanf("%d",&c1);

    mtr1 = ( int **) malloc( r1 * sizeof( int* ));

    for ( int i = 0 ; i < r1 ; i++ )
    {
        mtr1[i] = (int *) malloc( c1 * sizeof( int ));
    }

    printf("\n\t\t\t\tEnter elements of 1st matrix:\n\n");
    for ( int i = 0 ; i < r1 ; i++ )
    {
        for ( int j = 0 ; j < c1 ; j++ )
        {
            printf("\t\t\t\ta%d%d = ",i,j);
            scanf("%d",&mtr1[i][j]);
        }
    }

    printf("\n\t\t\t\tEnter the row of 2nd matrix: ");
    scanf("%d",&r2);

    printf("\t\t\t\tEnter the column of 2nd matrix: ");
    scanf("%d",&c2);

    mtr2 = ( int **) malloc( r1 * sizeof( int* ));

    for ( int i = 0 ; i < r1 ; i++ )
    {
        mtr2[i] = (int *) malloc( c1 * sizeof( int ));
    }

    printf("\n\t\t\t\tEnter elements of 2nd matrix: \n\n");
    for ( int i = 0 ; i < r2 ; i++ )
    {
        for ( int j = 0 ; j < c2 ; j++ )
        {
            printf("\t\t\t\tb%d%d = ",i,j);
            scanf("%d",&mtr2[i][j]);
        }
    }

    printf("\n\t\t\t\t1st matrix is:\n\n");
    for ( int i = 0 ; i < r1 ; i++ )
    {
        printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c1 ; j++ )
        {
            printf("   %d   ",mtr1[i][j]);
        }

        printf("\n");
    }

    printf("\n\t\t\t\t2nd matrix is:\n\n");
    for ( int i = 0 ; i < r2 ; i++ )
    {
        printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c2 ; j++ )
        {
            printf("   %d   ",mtr2[i][j]);
        }

        printf("\n");
    }

    //End of Enter Two matrix  ---------------------------------------------------------------------------

    usleep(1000000);
    getch();
    system("cls");
    welcome();


    switch (choice)
    {
    case 1:
        {
            Matrix_Addition(mtr1 , mtr2 , r1 , c1 , r2 , c2);
            break;
        }
    case 2:
        {
            matrix_Subtraction(mtr1 , mtr2 , r1, c1 , r2 , c2 );
            break;
        }
    case 3:
        {
            Matrix_Multiplication( mtr1 , mtr2 , r1, c1 , r2 , c2 );
            break;
        }
    case 8:
        {
            determinant:
            break;
        }
    case 5:
        {
            inverse:
            Inverse_of_Matrix();
            break;
        }
    case 4:
        {
            transpose:
            break;
        }
    case 9:
        {
            last:
            exit(9);
        }
    case 6:
        {
            cof:
            break;
        }
    case 7:
        {
            adjoint:
            break;
        }
    }
}

void Matrix_Addition( int** arr1 , int** arr2 , int r1 , int c1 , int r2 , int c2 ) {

    int result[ROW][COLUMN];

    if ( r1 == r2 && c1 == c2) {

        for ( int i = 0 ; i < r1 ; i++ )
        {
            for ( int j = 0 ; j < c1 ; j++ )
            {
                result[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        printf("\n\t\t\t\tAfter Addition Matrix is:\n\n");
        for ( int i = 0 ; i < r2 ; i++ )
        {
             printf("\n\t\t\t\t");
             for ( int j = 0 ; j < c2 ; j++ )
             {
                  printf("    %d    ",result[i][j]);
             }
             printf("\n");
        }

    } else {

        printf("\n\n\t\t\t\tMatrix order should be same.So addition is not possible\n");
        exit(0);
    }
}

void matrix_Subtraction( int** arr1 , int** arr2 , int r1 , int c1 , int r2 , int c2 ) {

    int result[ROW][COLUMN];

    if ( r1 == r2 && c1 == c2) {

        for ( int i = 0 ; i < r1 ; i++ )
        {
            for ( int j = 0 ; j < c1 ; j++ )
            {
                result[i][j] = arr1[i][j] - arr2[i][j];
            }
        }

        printf("\n\t\t\t\tAfter Subtraction Matrix is:\n\n");
        for ( int i = 0 ; i < r2 ; i++ )
        {
             printf("\n\t\t\t\t");
             for ( int j = 0 ; j < c2 ; j++ )
             {
                  printf("    %d    ",result[i][j]);
             }
             printf("\n");
        }

    } else {

        printf("\n\n\t\t\t\tMatrix order should be same.So Subtraction is not possible\n");
        exit(0);
    }
}

void Matrix_Multiplication( int** arr1 , int** arr2 , int r1 , int c1 , int r2 , int c2 ) {

     int result[ROW][COLUMN],r,c,sum = 0;

     if ( c1 == r2 ) {

        r = r1;
        c = c2;
     } else {
        printf("\n\n\t\t\t\tMatrix multiplication is not possible.\n\t\t\t\tYour 1st matrix column should be equal to 2nd matrix row\n");
     }

     for ( int i = 0 ; i < r ; i++ )
     {
         for ( int j = 0 ; j < c ; j++ )
         {
             sum = 0;

             for ( int k = 0 ; k < c1 ; k++ )
             {
                    sum += ( arr1[i][k] * arr2[k][j] );
             }
             result[i][j] = sum;
         }
     }

        printf("\n\t\t\t\tAfter Multiplication Matrix is:\n\n");
        for ( int i = 0 ; i < r ; i++ )
        {
             printf("\n\t\t\t\t");
             for ( int j = 0 ; j < c ; j++ )
             {
                  printf("   %d   ",result[i][j]);
             }
             printf("\n");
        }
}

int determinant(int **matrix , int r , int c ) {

    int **minor,i,row,column,minor_row,minor_column,j,k,sum = 0;

    minor = ( int **) malloc( (r) * sizeof( int *) );

    for ( int i = 0 ; i < c  ; i++ )
    {
        minor[i] = ( int* ) malloc( c * sizeof(int));
    }

    if ( r != c ) {

        printf("\n\t\t\t\tDeterminant Can not determined of a non- square matrix\n");
        exit(0);

    } else if ( r == 1 && c == 1 ) {

        return matrix[0][0];

    } else if ( r == 2 && c == 2 ) {

        return ( ( matrix[0][0] * matrix[1][1] )  -  ( matrix[0][1] * matrix[1][0] ) ) ;

    } else {

        for ( i = 0 ; i < c ; i++ )
        {
            j = 0;

            for ( row = 1 ; row < r ; row++ )
            {
                k = 0;

                for ( column = 0 ; column < c ; column++ )
                {
                    if ( column == i )
                    {
                        continue;
                    }
                    else
                    {
                        minor[j][k] = matrix[row][column];
                        k++;
                    }
                }
                j++;
            }

            if ( i % 2 == 0 )
            {
                sum += matrix[0][i] * determinant(minor,r - 1 , c - 1);
            }
            else
            {
                sum -= matrix[0][i] * determinant(minor,r-1,c-1);

            }
        }
    }

    return sum;
}

void Inverse_of_Matrix() {

    int r,c;
    int **mtr,**cofactor,**transpose;
    float **inverse;

    printf("\n\t\t\t\tEnter the row of 1st matrix: ");
    scanf("%d",&r);

    printf("\t\t\t\tEnter the column of 1st matrix: ");
    scanf("%d",&c);

    mtr = ( int **) malloc( r * sizeof( int* ));

    for ( int i = 0 ; i < c ; i++ )
    {
        mtr[i] = (int *) malloc( c * sizeof( int ));
    }

    cofactor = ( int **) malloc( r * sizeof( int* ));

    for ( int i = 0 ; i < c ; i++ )
    {
        cofactor[i] = (int *) malloc( c * sizeof( int ));
    }

    transpose = ( int **) malloc( r * sizeof( int* ));

    for ( int i = 0 ; i < c ; i++ )
    {
        transpose[i] = (int *) malloc( c * sizeof( int ));
    }



    printf("\n\t\t\t\tEnter elements of  matrix:\n\n");
    for ( int i = 0 ; i < r ; i++ )
    {
        for ( int j = 0 ; j < c ; j++ )
        {
            printf("\t\t\t\ta%d%d = ",i,j);
            scanf("%d",&mtr[i][j]);
        }
    }

    printf("\n\t\t\t\tmatrix is:\n\n");
    for ( int i = 0 ; i < r ; i++ )
    {
        printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("   %d   ",mtr[i][j]);
        }

        printf("\n");
    }

    if ( determinant(mtr,r,c) == 0 ) {

        printf("\n\t\t\t\tInverse of that matrix is not possible\n");

    } else {

        cofactor_matrix(mtr,cofactor,r,c);
    }


    inverse = ( float **) malloc( r * sizeof( float* ));

    for ( int i = 0 ; i < c ; i++ )
    {
        inverse[i] = (float *) malloc( c * sizeof( float ));
    }

    //adjoint matrix

    Transpose_Matrix(cofactor,r,c,transpose);

    //Inverse of a matrix

    for ( int i = 0 ; i < r ; i++ )
    {
        for ( int j = 0 ; j < c ; j++ )
        {
            inverse[i][j] = (float) transpose[i][j] / (float) determinant(mtr,r,c);
        }
    }

    printf("\n\t\t\t\tInverse matrix is:\n\n");
    for ( int i = 0 ; i < r ; i++ )
    {
        printf("\n\t\t\t\t");

        for ( int j = 0 ; j < c ; j++ )
        {
            printf("  %.2f   ",inverse[i][j]);
        }

        printf("\n");
    }

}

int cofactor_matrix(int** matrix,int **cofactor ,int r , int  c) {

    int **minor, m,n;

   minor = (int**) malloc(  r  * sizeof( int* ) );

    for ( int i = 0 ; i < c  ; i++ )
    {
        minor[i] = (int *) calloc( c , (sizeof( int )));
    }

   for ( int i = 0 ; i < r ; i++ )
   {
       for ( int j = 0 ; j < c ; j++ )
       {
           m = 0;
           n = 0;

           for ( int p = 0 ; p < r ; p++ )
           {
               for ( int q = 0 ; q < c ; q++ )
               {
                   if ( i != p && j != q ) {

                       minor[m][n] = matrix[p][q];

                       if ( n < ( c - 2))
                       {
                           n++;
                       }
                       else
                       {
                           n = 0;
                           m++;
                       }
                   }
               }
           }

           cofactor[i][j] = pow( -1 , ( i + j ) ) * determinant( minor , r - 1, c - 1 );
       }
   }
}

void Transpose_Matrix(int ** cofactor , int r , int c , int ** transpose) {

    for ( int i = 0 ; i < c ; i++ )
    {
        for ( int j = 0 ; j < r ; j++ )
        {
            transpose[i][j] = cofactor[j][i];
        }
    }
}
