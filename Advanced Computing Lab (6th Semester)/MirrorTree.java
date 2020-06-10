import java.util.*;

public class MirrorTree {
    private static Scanner sc = new Scanner(System.in);
    private static ArrayList<Node> queue = new ArrayList<>();

    public static void main(String[] args) {
        Node rootNode = new Node();
        Node mirrorRootNode = new Node();
        System.out.println("Enter the root node:");
        rootNode.data = sc.nextInt();
        queue.add(rootNode);
        while (!queue.isEmpty()) {
            Node queueNode = queue.remove(0);
            System.out.println("Press \'0\' if you want to enter the left child of " + queueNode.data
                    + " or press anything else to skip.");
            int tempValue = sc.nextInt();
            if (tempValue == 0) {
                System.out.println("Enter the left child of " + queueNode.data);
                Node leftNode = new Node();
                leftNode.data = sc.nextInt();
                queueNode.leftChild = leftNode;
                queue.add(leftNode);
            }
            System.out.println("Press \'0\' if you want to enter the right child of " + queueNode.data
                    + " or press anything else to skip.");
            tempValue = sc.nextInt();
            if (tempValue == 0) {
                System.out.println("Enter the right child of " + queueNode.data);
                Node rightNode = new Node();
                rightNode.data = sc.nextInt();
                queue.add(rightNode);
                queueNode.rightChild = rightNode;
            }
        }
        System.out.println("\n\n\nOriginal Tree: ");
        printTree(rootNode);
        System.out.println("\n\n\nReverse Tree: ");
        mirrorRootNode = rootNode;
        mirrorTree(rootNode);
        printTree(mirrorRootNode);
    }

    private static void printTree(Node node) {
        if (node != null) {
            System.out.println(node.data);
            printTree(node.leftChild);
            printTree(node.rightChild);
        }
    }

    private static void mirrorTree(Node node) {
        if (node != null) {
            mirrorTree(node.leftChild);
            mirrorTree(node.rightChild);
            Node tempNode = node.leftChild;
            node.leftChild = node.rightChild;
            node.rightChild = tempNode;
        }

    }
}

class Node {
    Integer data;
    Node leftChild = null;
    Node rightChild = null;
}