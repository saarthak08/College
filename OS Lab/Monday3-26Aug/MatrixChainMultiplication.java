import java.util.*;

public class MatrixChainMultiplication{
    private static Scanner sc=new Scanner(System.in);
    private static int[][] matrices;
    public static void main(String[] args){
        int n,i=0,j;
        System.out.println("Enter the number of matrices:");
        n=sc.nextInt();
        matrices=new int[n][2];
        while(i<n){
            System.out.println("Enter the number of rows & columns of matrix "+(i+1)+":");
            matrices[i][0]=sc.nextInt();
            if(i!=0){
                if(matrices[i][0]!=matrices[i-1][1]){
                    System.out.println("\n\nError!In order to multipy, number of rows of the matrix should be equal to the number of column of the previous matrix. Try again!\n\n");
                    continue;
                }
            }
            matrices[i][1]=sc.nextInt();
            i++;
        }
        printMatrices(n);
        chainMultilply(n);
    }

    private static void printMatrices(int n){
        int i;
        System.out.println("\n\nRows & columns of matrices: ");
        for(i=0;i<n;i++){
            System.out.print("Matrix "+(i+1)+":    "+matrices[i][0]+"\t");
            System.out.print(matrices[i][1]);
            System.out.println();
        }
    }


    private static void chainMultilply(int n){
        int i,j,k,l,q=0;
        int minMultiply[][]=new int[n+1][n+1];
        int order[][]=new int[n+1][n+1];
        int[] dimensionMatrix=new int[n+1];
        for(i=0;i<=n;i++){
            if(i==n){
                dimensionMatrix[i]=matrices[i-1][1];
                break;
            }
            dimensionMatrix[i]=matrices[i][0];

        }

        //Setting the values of same indices to 0
        for(i=1;i<=n;i++){
            minMultiply[i][i]=0;
        }

        for(l=2;l<=n;l++){
            for(i=1;i<=(n-l+1);i++){
                j=i+l-1;
                minMultiply[i][j]=Integer.MAX_VALUE;
                for(k=i;k<=j-1;k++){
                    q=minMultiply[i][k]+minMultiply[k+1][j] + dimensionMatrix[i-1]*dimensionMatrix[k]*dimensionMatrix[j];
                if(q<minMultiply[i][j]){
                    minMultiply[i][j]=q;
                    order[i][j]=k;
                    }
                }
            }
        }

        System.out.println("\n\nMultiplication Matrix:");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                System.out.print(minMultiply[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println("\n\nMinimum Multiplications: "+minMultiply[1][n]);

        System.out.println("\n\nOrder Matrix:");
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                System.out.print(order[i][j]+"\t");
            }
            System.out.println();
        }

        System.out.println("\n\nOrder of multiplication of matrices:");
        printParenthesis(1,n,order);
        System.out.println();


    }


    private static void printParenthesis(int i,int j,int order[][]){
    	if (i == j)
    	{
			System.out.print("M "+i+" ");
    	}
        else{

		System.out.print("(");
    	printParenthesis(i,order[i][j], order);
    	printParenthesis(order[i][j] + 1, j, order);
    	System.out.print(")");
        }
    }


}
