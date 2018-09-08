public class BSTnode
{
	private int key;
	private BSTnode left;
	private BSTnode right;

	public BSTnode(int key)
	{
		this.key = key;
		this.left = null;
		this.right = null;
	}

	public int getKey()
	{
		return this.key;
	}

	public BSTnode getLeft()
	{
		return this.left;
	}

	public BSTnode getRight()
	{
		return this.right;
	}

	public void setLeft(BSTnode left)
	{
		this.left = left;
	}

	public void setRight(BSTnode right)
	{
		this.right = right;
	}

	public void setKey(int key)
	{
		this.key = key;
	}

}