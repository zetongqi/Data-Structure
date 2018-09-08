public class BSTtest
{
	public static void main(String [] args)
	{
		BST bt = new BST();
		BSTnode root = new BSTnode(5);
		bt.setRoot(root);
		bt.Insert(3);
		bt.Insert(2);
		bt.Insert(6);
		bt.Insert(1);
		bt.Insert(4);
		bt.Insert(8);
		bt.Insert(7);
		bt.Insert(9);
		bt.Print();
		if (bt.Search(5))
			System.out.println("found!");
		else
			System.out.println("not found!");
	}
}