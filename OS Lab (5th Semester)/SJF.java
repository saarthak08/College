import java.io.*;
import java.util.*;

public class SJF{
    private static BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    private static int jobs;
    private static int sjf[][];
    private static int result[][];
    private static float averageTT;
    private static float averageWT;
    public static void main(String[] args) throws IOException{
        System.out.println("Enter the number of jobs:");
        jobs=Integer.parseInt(reader.readLine());
        init_array();
        SJF_Preemptive(sjf);
        SJF_Non_Preemptive(sjf);
    }


    private static int[][] sortArray(int pre,int sfj[][]){
        int i,j,temp;
        if(pre==1){
            for(i=0;i<jobs-1;i++){
                for(j=0;j<jobs-i-1;j++){
                    if(sjf[j][1]>sjf[j+1][1]){
                        temp=sjf[j][1];
                        sjf[j][1]=sjf[j+1][1];
                        sjf[j+1][1]=temp;
                        temp=sjf[j][2];
                        sjf[j][2]=sjf[j+1][2];
                        sjf[j+1][2]=temp;
                        temp=sjf[j][0];
                        sjf[j][0]=sjf[j+1][0];
                        sjf[j+1][0]=temp;
                    }
                }
            }
            return sjf;
        }
        else if(pre==0){
            for(i=0;i<jobs-1;i++){
                for(j=0;j<jobs-i-1;j++){
                    if(sjf[j][2]>sjf[j+1][2]){
                        temp=sjf[j][1];
                        sjf[j][1]=sjf[j+1][1];
                        sjf[j+1][1]=temp;
                        temp=sjf[j][2];
                        sjf[j][2]=sjf[j+1][2];
                        sjf[j+1][2]=temp;
                        temp=sjf[j][0];
                        sjf[j][0]=sjf[j+1][0];
                        sjf[j+1][0]=temp;
                    }
                }
            }
            return sjf;
        }
        else{
            return null;
        }
    }


    private static void printArray(int pre,int[][] sjf){
        int i,j;
        if(pre==1){
            System.out.println("\n\n\n*******----------- PREEMPTIVE SJF -----------*******");
        }
        else{
            System.out.println("\n\n\n*******----------- NON-PREEMPTIVE SJF -----------*******");
        }
        System.out.println("\n\nTable: ");
        System.out.print("    "+"+");
        for(i=0;i<106;i++){
            if(i==15||i==31||i==47||i==63||i==87||i==105){
                System.out.print("+");
            }
            else{
                System.out.print("-");
            }
        }
        System.out.println("\n    | Job ID\t    | Arrival_Time  | Burst_Time    | Waiting_Time  | Turn_Around_Time      | Completion_Time |");
        System.out.print("    "+"+");
        for(i=0;i<106;i++){
            if(i==15||i==31||i==47||i==63||i==87||i==105){
                System.out.print("+");
            }
            else{
                System.out.print("-");
            }
        }
        System.out.println();
        for(i=0;i<jobs;i++){
            for(j=0;j<6;j++){
                if(j==0){
                    System.out.print("    "+"|"+"\t\b\bJob " +sjf[i][j]+"\t    ");
                }
                else if(j==4){
                    System.out.print("|"+"\t"+sjf[i][j]+"\t\t    ");
                }
                else if(j==5){
                    System.out.print("|"+"\t"+sjf[i][j]+"\t         ");
                }
                else{
                    System.out.print("|"+"\t"+sjf[i][j]+"\t    ");
                }
            }
        System.out.println("\b\b\b|");
        }
        System.out.print("    "+"+");
        for(i=0;i<106;i++){
            if(i==15||i==31||i==47||i==63||i==87||i==105){
                System.out.print("+");
            }
            else{
                System.out.print("-");
            }
        }
        System.out.println();
        System.out.println("\nAverage Waiting Time: "+averageWT);
        System.out.println("\nAverage Turn Around Time: "+averageTT);
    }

    private static void init_array() throws IOException{
        sjf=new int[jobs][6];
        result=new int[20][3];
        System.out.println("Enter the jobs with their arrival times & burst times respectively:\n");
        for(int i=0;i<jobs;i++){
            System.out.println("\nEnter the arrival time for job " + (i+1) +":");
            sjf[i][1]=Integer.parseInt(reader.readLine());
            System.out.println("Enter the burst time for job " +(i+1) +":");
            sjf[i][2]=Integer.parseInt(reader.readLine());
            sjf[i][0]=i+1;
        }
    }


    private static void SJF_Preemptive(int[][] sjf){
        int[][] arr=new int[jobs][6];
        sjf=sortArray(1, sjf);
        int i,j,temp,min,min_index=0,k=0,o,p,temp_burst=0;
        for(i=0;i<jobs;i++){
            for(j=0;j<3;j++){
                arr[i][j]=sjf[i][j];
            }
        }
        for(i=0;i<jobs;i++){
            min=arr[i][2];
            min_index=i;
            for(j=i;j>=0;j--){
                if(arr[j][2]<min){
                    min=arr[j][2];
                    min_index=j;
                }
                if(arr[j][2]==min){
                    if(min_index>j){
                        min_index=j;
                    }
                }
            }
            if(min_index==jobs-1){
                arr[i][2]=Integer.MAX_VALUE;
            }
            else{
                temp_burst=((arr[min_index+1][1])-(arr[min_index][1]));
                temp=(arr[min_index][2])-temp_burst;
                if(temp>0){
                    arr[min_index][2]=temp;
                }
                else{
                    arr[min_index][2]=Integer.MAX_VALUE;
                }
            }
            if(min!=Integer.MAX_VALUE){
                if(k!=0){
                    if(result[k-1][0]!=arr[min_index][0]){
                        result[k][0]=arr[min_index][0];
                        result[k][1]=result[k-1][2];
                        result[k][2]=result[k][1]+result[k][2]+temp_burst;
                        k=k+1;
                    }
                    else{
                        result[k-1][2]=result[k-1][2]+temp_burst;
                    }
                }
                else{
                    result[k][0]=arr[min_index][0];
                    result[k][1]=arr[min_index][1];
                    result[k][2]=result[k][1]+result[k][2]+temp_burst;
                    k=k+1;
                }
            }

        }
        try{
            if(k-1!=0&&arr[result[k-1][0]][2]!=Integer.MAX_VALUE){
                result[k-1][2]=result[k-2][2]+sjf[min_index][2];
            }
            else if(k-1==0&&jobs==2){
                result[k-1][2]=result[k-1][1]+sjf[min_index][2];
            }
        }
        catch(Exception e){}
        for(i=0;i<jobs;i++){
            min=arr[0][2];
            min_index=0;
            for(j=0;j<jobs;j++){
                if(arr[j][2]<min){
                    min=arr[j][2];
                    min_index=j;
                }
                if(arr[j][2]==min){
                    if(min_index>j){
                        min_index=j;
                    }
                }
            }
            if(min!=Integer.MAX_VALUE){
                if(k!=0){
                    if(result[k-1][0]!=arr[min_index][0]){
                        result[k][0]=arr[min_index][0];
                        result[k][1]=result[k-1][2];
                        result[k][2]=result[k][1]+arr[min_index][2];
                        k=k+1;
                    }
                }
                else{
                    result[k][0]=arr[min_index][0];
                    result[k][1]=0;
                    result[k][2]=arr[min_index][2];
                    k=k+1;
                }
            }
            arr[min_index][2]=Integer.MAX_VALUE;
        }

        calculations(sjf,result,k);
        printArray(1,sjf);
        printGantChartPremeptive(sjf,result,k);

    }

    private static void printGantChartPremeptive(int sjf[][],int arr[][],int length){
        int i,j;
        System.out.println("\n\nGant Chart: ");
        System.out.print("    +");
        for(i=1;i<=length*12;i++){
            if(i%12==0){
                System.out.print("+");
            }
            else{
                System.out.print("-");
            }
        }
        System.out.print("\n    ");
        for(i=0;i<length;i++){
            if(arr[i][0]==-1){
                System.out.print("|  "+"CPU IDLE"+" ");
            }
            else{
                System.out.print("|   "+"Job "+arr[i][0]+"   ");
            }
        }
        System.out.println("|");
        System.out.print("    +");
        for(i=1;i<=length*12;i++){
            if(i%12==0){
                System.out.print("+");
            }
            else{
                System.out.print("-");
            }
        }
        System.out.println();
        System.out.print("    "+arr[0][1]+"           ");
        for(i=0;i<length;i++){
            if(arr[i][2]>9){
                System.out.print("\b"+arr[i][2]+"           ");
            }
            else{
                System.out.print(arr[i][2]+"           ");
            }
        }
        System.out.println("\n\n");
    }

    private static void calculations(int sjf[][], int result[][],int length){
        int i,j,x,wt=0,flag=0;
        float totalWt=0, totalTT=0;
        for(i=0;i<jobs;i++){
            x=sjf[i][0];
            for(j=length;j>=0;j--){
                if(result[j][0]==x&&flag==0){
                    wt=result[j][1];
                    flag=1;
                }
                else if(result[j][0]==x&&flag==1){
                    wt=wt-(result[j][2]-result[j][1]);
                }
            }
            wt=wt-sjf[i][1];
            sjf[i][3]=wt;
            totalWt=totalWt+wt;
            flag=0;
        }

        for(i=0;i<jobs;i++){
            x=sjf[i][0];
            for(j=length;j>=0;j--){
                if(x==result[j][0]){
                    sjf[i][5]=result[j][2];
                    break;
                }
            }
        }
        for(i=0;i<jobs;i++){
            sjf[i][4]=sjf[i][5]-sjf[i][1];
            totalTT=totalTT+sjf[i][4];
        }
        averageWT=(totalWt/sjf.length);
        averageTT=(totalTT/sjf.length);
    }


    private static void SJF_Non_Preemptive(int sjf[][]){
        int i,j,arr[][],min,min_index,k=0,x[][];
        float totalTT=0,totalWt=0;
        for(i=0;i<jobs;i++){
            for(j=3;j<6;j++){
                sjf[i][j]=0;
            }
        }
        averageTT=0;
        averageWT=0;
        result=new int[20][3];
        arr=sortArray(0, sjf);
        x=new int[jobs][6];
        for(i=0;i<jobs;i++){
          for(j=0;j<6;j++){
            x[i][j]=arr[i][j];
          }
        }
        min_index=0;
        min=arr[0][1];
        for(i=0;i<jobs;i++){
            if(min>arr[i][1]){
                min=arr[i][1];
                min_index=i;
            }
            if(min==arr[i][1]){
                if(min_index>arr[i][0]){
                    min_index=i;
                }
            }
        }
        result[k][0]=arr[min_index][0];
        result[k][1]=arr[min_index][1];
        result[k][2]=result[k][1]+arr[min_index][2];
        arr[min_index][2]=Integer.MAX_VALUE;
        x[min_index][5]=result[k][2];
        totalTT=totalTT+x[min_index][5];
        x[min_index][3]=x[min_index][5]-x[min_index][1]-x[min_index][2];
        totalWt=totalWt+x[min_index][3];
        x[min_index][4]=x[min_index][5]-x[min_index][1];
        k=k+1;
        for(i=0;i<jobs;i++){
            min=arr[i][2];
            min_index=i;
            for(j=0;j<jobs;j++){
                if(min>arr[i][2]){
                    min=arr[i][2];
                    min_index=i;
                }
                if(min==arr[i][2]){
                    if(min_index>arr[i][0]){
                        min_index=i;
                    }
                }
            }
            if(min!=Integer.MAX_VALUE){
                if(arr[min_index][1]>result[k-1][2]){
                    result[k][0]=-1;
                    result[k][1]=result[k-1][2];
                    result[k][2]=result[k-1][2]+(arr[min_index][1]-result[k-1][2]);
                    k=k+1;
                }
                result[k][0]=arr[min_index][0];
                result[k][1]=result[k-1][2];
                result[k][2]=result[k][1]+arr[min_index][2];
                x[min_index][5]=result[k][2];
                totalTT=totalTT+x[min_index][5];
                x[min_index][4]=x[min_index][5]-x[min_index][1];
                x[min_index][3]=x[min_index][5]-x[min_index][1]-x[min_index][2];
                totalWt=totalWt+x[min_index][3];
                arr[min_index][2]=Integer.MAX_VALUE;
                k=k+1;
            }
        }
        averageTT=(totalTT/x.length);
        averageWT=(totalWt/x.length);

        printArray(0,x);
        printGantChartPremeptive(arr, result, k);
    }
}
