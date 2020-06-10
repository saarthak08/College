import java.util.*;

public class kSmallestInteger{
    private static Scanner sc=new Scanner(System.in);
    private static int[] array1;
    private static int[] array2;

    public static void main(String[] args){
        int size1, size2, k;
        System.out.println("Enter the size of the first array:");
        size1=sc.nextInt();
        System.out.println("Enter the size of the second array:");
        size2=sc.nextInt();
        initializeArrays(size1, size2);
        printArrays(size1,size2);
        System.out.println("\n\nEnter the value of \'k\'':");
        k=sc.nextInt();
        System.out.println("\n\n\n"+k+" smallest integer in the union of the two arrays: "+kthSmallest(0,0,size1,size2,k-1));

    }

    private static void initializeArrays(int size1, int size2){
        int i;
        array1=new int[size1+1];
        array2=new int[size2+1];
        System.out.println("Enter the elements of the first array:");
        for(i=0;i<size1;i++){
            array1[i]=sc.nextInt();
        }
        System.out.println("Enter the elements of the second array:");
        for(i=0;i<size2;i++){
            array2[i]=sc.nextInt();
        }
    }

    private static int kthSmallest(int start1, int start2, int end1, int end2,int k)
    {
        System.out.println("\n\nStart_Index1: "+start1+"\tEnd_Index1: "+end1+"\nStart_Index2: "+start2+"\tEnd_Index2: "+end2+"\nK: "+k);
        System.out.println("First Array:");
        for(int i=start1;i<end1;i++){
            System.out.print(array1[i]+"\t");
        }
        System.out.println("\nSecond Array:");
        for(int i=start2;i<end2;i++){
            System.out.print(array2[i]+"\t");
        }
        if(start1==end1){
            return array2[start2+k];
        }
        if(start2==end2){
            return array1[start1+k];
        }
        
        int mid1=(end1 - start1)/2; 
        int mid2=(end2 - start2)/2; 
        System.out.println("\nMid_Index1: "+mid1+"\nMid_Index2: "+mid2);
        if(mid1+mid2<k) 
        { 
            if(array1[start1+mid1]>array2[start2+mid2]){
                return kthSmallest(start1, start2 + mid2 + 1, end1, end2,k-mid2-1);
            }  
            else{
                return kthSmallest(start1 + mid1 + 1, start2, end1, end2,k-mid1-1);
            } 
        } 
        else
        { 
            if (array1[start1+mid1] > array2[start2+mid2]){
                return kthSmallest(start1, start2, start1 + mid1, end2,k); 
            } 
            else{
                return kthSmallest(start1, start2, end1, start2 + mid2,k); 
            }
        } 
    }


    private static void printArrays(int size1, int size2){
        int i;
        System.out.println("\n\nFirst array:");
        for(i=0;i<size1;i++){
            System.out.print(array1[i]+"\t");
        }
        System.out.println("\nSecond array:");
        for(i=0;i<size2;i++){
            System.out.print(array2[i]+"\t");
        }
    }

}
