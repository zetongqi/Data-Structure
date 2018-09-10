public class BSTtest
{
	public static void main(String [] args)
	{
		BST bt = new BST();
		BSTnode root = new BSTnode(11);
		bt.setRoot(root);
		bt.Insert(3);
		bt.Insert(2);
		bt.Insert(6);
		bt.Insert(1);
		bt.Insert(4);
		bt.Insert(8);
		bt.Insert(7);
		bt.Insert(9);
		bt.Insert(0);
		bt.Insert(-1);
		bt.Insert(-2);
		bt.Print();
		//bt.leftRotate(root);
		//bt.Print();
		System.out.println(bt.find_Unbalanced_Node(root.getLeft().getRight().getRight().getRight()).getKey());
	}
}