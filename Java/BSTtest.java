import java.util.*;

public class BSTtest
{
	public static void main(String [] args)
	{
		BST bt = new BST();
		BSTnode root = new BSTnode(11);
		bt.setRoot(root);
		BSTnode b1 = new BSTnode(1);
		BSTnode b2 = new BSTnode(2);
		BSTnode b3 = new BSTnode(3);
		BSTnode b4 = new BSTnode(4);
		BSTnode b5 = new BSTnode(5);
		BSTnode b6 = new BSTnode(6);
		BSTnode b7 = new BSTnode(7);
		BSTnode b8 = new BSTnode(8);
		BSTnode b9 = new BSTnode(9);
		BSTnode b10 = new BSTnode(10);
		bt.AVL_Insert(b3);
		bt.AVL_Insert(b2);
		bt.AVL_Insert(b6);
		bt.AVL_Insert(b1);
		bt.AVL_Insert(b4);
		bt.AVL_Insert(b8);
		bt.AVL_Insert(b7);
		bt.AVL_Insert(b9);
		bt.AVL_Insert(b10);
		/*bt.Insert(b3);
		bt.Insert(b2);
		bt.Insert(b6);
		bt.Insert(b1);
		bt.Insert(b4);
		bt.Insert(b8);
		bt.Insert(b7);
		bt.Insert(b9);
		bt.Insert(b10);*/
		System.out.println(bt.getHeight());
		//bt.leftRotate(b6);
		//bt.Print();
		//System.out.println(bt.find_Unbalanced_Node(b9).getKey());
		//ArrayList<BSTnode> al = bt.findPath(b3, b10);
		//for (int i = 0; i < al.size(); i++)
		//	System.out.println(al.get(i).getKey());
		System.out.println(bt.getHeight());
	}
}