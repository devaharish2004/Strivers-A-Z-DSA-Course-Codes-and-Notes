/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
import java.util.*;
public class Code {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null) return "";
        StringBuilder ans = new StringBuilder();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()) {
            TreeNode node = q.poll();
            if(node == null) {
                ans.append("null,");
            }
            else {
                ans.append(node.val + ",");
                q.offer(node.left);
                q.offer(node.right);
            }
        }
        return ans.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length() == 0) return null;
        Queue<TreeNode> q = new LinkedList<>();
        String[] arr = data.split(",");
        int index = 0;
        TreeNode root = new TreeNode(Integer.parseInt(arr[index]));
        q.offer(root);
        index++;
        for(String s : arr) {
            System.out.println(s);
        }
        while(!q.isEmpty()) {
            TreeNode node = q.poll();
            //for left
            if(arr[index].equals("null")) {
                node.left = null;
                index++;
            }
            else {
                TreeNode leftNode = new TreeNode(Integer.parseInt(arr[index]));
                index++;
                node.left = leftNode;
                q.offer(leftNode);
            }

            //for right
            if(arr[index].equals("null")) {
                node.right = null;
                index++;
            }
            else {
                TreeNode rightNode = new TreeNode(Integer.parseInt(arr[index]));
                index++;
                node.right = rightNode;
                q.offer(rightNode);
            }
        }

        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));