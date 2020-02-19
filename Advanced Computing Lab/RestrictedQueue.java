import java.util.*;

public class question {

    private static Node front;
    private static Node rear;
    private static int length = 0;
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int temp=0;
        while (temp != -1) {
            System.out.print(
                    "\n\n\nPress \'1\' to print the queue.\nPress \'2\' to insert.\nPress \'3\' to delete from front.\nPress \'4\' to delete from rear.\nPress \'-1\' to exit.\n\n\n\n");
            temp = sc.nextInt();
            if (temp == 1) {
                printQueue();
            } else if (temp == 2) {
                insertIntoQueue();
            } else if (temp == 3) {
                deleteFromFront();
            } else if (temp == 4) {
                deleteFromRear();
            } else if (temp == -1) {
                continue;
            } else {
                System.out.println("\nError! Invalid Input. Try Again!");
            }

        }

    }

    private static void insertIntoQueue() {
        Node temp = new Node();
        int d;
        System.out.println("Enter the number to insert: ");
        d = sc.nextInt();
        temp.data = d;
        if (length == 0) {
            rear = temp;
            front = temp;
        } else {
            rear.previousNode = temp;
            temp.nextNode = rear;
            rear = temp;
        }
        length++;
    }

    private static void deleteFromFront() {
        if (length == 0) {
            System.out.println("\nError! Queue is already empty.");
            return;
        } else {
            Node temp = new Node();
            temp = front.previousNode;
            front.previousNode = null;
            front.nextNode = null;
            front = temp;
            length--;
        }
    }

    private static void deleteFromRear() {
        if (length == 0) {
            System.out.println("\nError! Queue is already empty.");
            return;
        } else {
            Node temp = new Node();
            temp = rear.nextNode;
            rear.nextNode = null;
            rear.previousNode = null;
            rear = temp;
            length--;
        }
    }

    private static void printQueue() {
        if (length == 0) {
            System.out.print("\n\n\nCurrent Queue: Empty");
            return;
        }
        Node temp = rear;
        System.out.println("\n\n\nCurrent Queue:");
        while (temp != front.nextNode) {
            System.out.print(temp.data + "\t");
            temp = temp.nextNode;
        }
    }

}

class Node {
    public int data;
    public Node nextNode = null;
    public Node previousNode = null;
}