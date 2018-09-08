import java.util.*;

public class BST
{
	private BSTnode root;

	public BST()
	{
		this.root = null;
	}

	public void setRoot(BSTnode root)
	{
		this.root = root;
	}

	private BSTnode Insert(BSTnode node, int val)
	{
		if (node == null)
		{
			return new BSTnode(val);
		}
		if (val <= node.getKey())
		{
			node.setLeft(this.Insert(node.getLeft(), val));
			return node;
		}
		else
		{
			node.setRight(this.Insert(node.getRight(), val));
			return node;
		}
	}

	public void Insert(int val)
	{
		this.Insert(this.root, val);
	}

	public BSTnode findSmallest(BSTnode node)
	{
		if (node.getLeft() == null)
		{
			return node;
		}
		else
		{
			return findSmallest(node.getLeft());
		}
	}

	private BSTnode Delete(BSTnode node, int val)
	{
		if (node == null)
		{
			return null;
		}

		if (val == node.getKey())
		{
			if (node.getRight() == null && node.getLeft() == null)
			{
				return null;
			}

			if (node.getRight() == null)
			{
				return node.getLeft();
			}

			if (node.getLeft() == null)
			{
				return node.getRight();
			}

			node.setKey(findSmallest(node.getRight()).getKey());
			node.setRight(Delete(node.getRight(), node.getKey()));
			return node;
		}

		else if (val <= node.getKey())
		{
			node.setLeft(Delete(node.getLeft(), val));
			return node;
		}

		else
		{
			node.setRight(Delete(node.getRight(), val));
			return node;
		}
	}

	public void Delete(int val)
	{
		Delete(this.root, val);
	}

	public boolean Search(BSTnode node, int val)
	{
		if (node == null)
		{
			return false;
		}

		if (val == node.getKey())
		{
			return true;
		}

		if (val <= node.getKey())
		{
			return Search(node.getLeft(), val);
		}

		else
		{
			return Search(node.getRight(), val);
		}
	}

	public Boolean Search(int val)
	{
		return Search(this.root, val);
	}

	private void Print(BSTnode node)
	{
		if (node == null)
		{
			return;
		}
		Print(node.getLeft());
		System.out.println(node.getKey());
		Print(node.getRight());
	}

	public void Print()
	{
		Print(this.root);
	}

}