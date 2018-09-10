public class BSTnode
{
	private int key;
	private BSTnode left;
	private BSTnode right;
	private BSTnode parent;

	public BSTnode(int key)
	{
		this.key = key;
		this.left = null;
		this.right = null;
		this.parent = null;
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
		if (this.left != null)
			this.left.setParent(this);
	}

	public void setRight(BSTnode right)
	{
		this.right = right;
		if (this.right != null)
			this.right.setParent(this);
	}

	public void setKey(int key)
	{
		this.key = key;
	}

	public BSTnode getParent()
	{
		return this.parent;
	}

	public void setParent(BSTnode parent)
	{
		this.parent = parent;
	}

}