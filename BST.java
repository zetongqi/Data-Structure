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

	public BSTnode getRoot()
	{
		return this.root;
	}

	private BSTnode Insert(BSTnode node, BSTnode n)
	{
		if (node == null)
		{
			return n;
		}
		if (n.getKey() <= node.getKey())
		{
			node.setLeft(this.Insert(node.getLeft(), n));
			return node;
		}
		else
		{
			node.setRight(this.Insert(node.getRight(), n));
			return node;
		}
	}

	public void Insert(BSTnode n)
	{
		this.Insert(this.root, n);
	}

	private BSTnode findSmallest(BSTnode node)
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

	private BSTnode getMax(BSTnode node)
	{
		if (node.getRight() == null)
		{
			return node;
		}
		else
			return getMax(node.getRight());
	}

	public BSTnode getMax()
	{
		return getMax(this.root);
	}

	private BSTnode getMin(BSTnode node)
	{
		if (node.getLeft() == null)
		{
			return node;
		}
		else
			return getMin(node.getLeft());
	}

	public BSTnode getMin()
	{
		return getMin(this.root);
	}

	private int getHeight(BSTnode node, int leftHeight, int rightHeight)
	{
		if (node == null)
		{
			return 0;
		}
		else
		{
			leftHeight = getHeight(node.getLeft(), leftHeight, rightHeight);
			rightHeight = getHeight(node.getRight(), leftHeight, rightHeight);
			leftHeight++;
			rightHeight++;
			if (rightHeight >= leftHeight)
				return rightHeight;
			else
				return leftHeight;
		}
	}

	public int getHeight()
	{
		return getHeight(this.root, 0, 0);
	}

	public void rightRotate(BSTnode node)
	{
		BSTnode tempT3 = node.getRight();
		node.setRight(node.getLeft());
		int tempNodeKey = node.getKey();
		node.setKey(node.getRight().getKey());
		node.getRight().setKey(tempNodeKey);
		node.setLeft(node.getRight().getLeft());
		node.getRight().setLeft(node.getRight().getRight());
		node.getRight().setRight(tempT3);
	}

	public void leftRotate(BSTnode node)
	{
		BSTnode tempT1 = node.getLeft();
		node.setLeft(node.getRight());
		int tempNodeKey = node.getKey();
		node.setKey(node.getLeft().getKey());
		node.getLeft().setKey(tempNodeKey);
		node.setRight(node.getLeft().getRight());
		node.getLeft().setRight(node.getLeft().getLeft());
		node.getLeft().setLeft(tempT1);
	}

	public BSTnode find_Unbalanced_Node(BSTnode node)
	{
		while (node.getParent() != null)
		{
			node = node.getParent();
			int rightHeight = getHeight(node.getRight(), 0, 0);
			int leftHeight = getHeight(node.getLeft(), 0, 0);
			if (java.lang.Math.abs(rightHeight-leftHeight) > 1)
				return node;
		}
		return null;
	}

	public ArrayList<BSTnode> findPath(BSTnode top, BSTnode down)
	{
		ArrayList<BSTnode> nodeList = new ArrayList<BSTnode>();
		BSTnode pointer = down;
		while (pointer != top)
		{
			nodeList.add(pointer);
			pointer = pointer.getParent();
		}
		Collections.reverse(nodeList);
		return nodeList;
	}

	public int findRelation(BSTnode parent, BSTnode child)
	{
		if (parent.getRight() != null)
		{	
			if (parent.getRight() == child)
				return 1;
		}
		if(parent.getLeft() != null)
			if (parent.getLeft() == child)
				return 2;
		return 0;
	}

	public void AVL_Insert(BSTnode node)
	{
		this.Insert(node);
		BSTnode unbalanced = this.find_Unbalanced_Node(node);
		if (unbalanced == null)
			return;
		ArrayList<BSTnode> connection = this.findPath(unbalanced, node);
		/*for (int i = 0; i < connection.size(); i++)
		{
			System.out.println(connection.get(i).getKey());
		}*/
		int firstRelation = this.findRelation(unbalanced, connection.get(0));
		int secondRelation = this.findRelation(connection.get(0), connection.get(1));
		if (firstRelation == 2 && secondRelation == 2)
			this.rightRotate(unbalanced);
		if (firstRelation == 2 && secondRelation == 1)
		{
			this.leftRotate(connection.get(0));
			this.rightRotate(unbalanced);
		}
		if (firstRelation == 1 && secondRelation == 2)
		{
			this.rightRotate(connection.get(0));
			this.leftRotate(unbalanced);
		}
		if (firstRelation == 1 && secondRelation == 1)
			this.leftRotate(unbalanced);
	}

}