class BSTnode <K>
{
	private K key;
	private BSTnode<K> left, right;

	/********************************** constructor **********************************/
	public BSTnode(K key, BSTnode<K> left, BSTnode<K> right)
	{
		this.key = key;
		this.left = left;
		this.right = right;
	}

	/********************************** functions **********************************/
	public BSTnode<K> get_left()
	{
		return this.left;
	}

	public BSTnode<K> get_right()
	{
		return this.right;
	}

	public K get_key()
	{
		return this.key;
	}

	public void set_key(K new_key)
	{
		this.key = new_key;
	}

	public void set_left(BSTnode<K> new_left)
	{
		this.left = new_left;
	}

	public void set_right(BSTnode<K> new_right)
	{
		this.right = new_right;
	}

}


class BST<K extends Comparable<K>>
{
	private BSTnode<K> root;

	/* constructor */
	public BST()
	{
		this.root = null;
	}


	/********************************** insert function **********************************/
	private BSTnode<K> insert(BSTnode<K> node, K key)
	{
		if (node == null)
		{
			return new BSTnode<K> (key, null, null);
		}

		if (key.compareTo(node.get_key()) < 0)
		{
			node.set_left(insert(node.get_left(), key));
			return node;
		}
		else
		{
			node.set_right(insert(node.get_right(), key));
			return node;
		}
	}

	public void insert(K key)
	{
		this.root = insert(this.root, key);
	}


	/********************************** see if a key is in a tree **********************************/
	private boolean look_up(BSTnode<K> node, K key)
	{
		if (node == null)
		{
			return false;
		}

		if (node.get_key().equals(key))
		{
        	return true;
    	}

		if (key.compareTo(node.get_key()) < 0)
		{
			return look_up(node.get_left(), key);
		}

		else
		{
			return look_up(node.get_right(), key);
		}
	}

	public boolean look_up(K key)
	{
		return this.look_up(this.root, key);
	}

	public BSTnode<K> smallest(BSTnode<K> node)
	{
		if (node.get_left() == null)
		{
			return node;
		}

		return smallest(node.get_left());
	}
	/********************************** delete **********************************/
	private BSTnode<K> delete(BSTnode<K> node, K key)
	{
		if (node == null)
		{
			return null;
		}

		if (node.get_key().equals(key))
		{
			if (node.get_left() == null && node.get_right() == null)
			{
				return null;
			}

			if (node.get_left() == null && node.get_right() != null)
			{
				return node.get_right();
			}

			if (node.get_left() != null && node.get_right() == null)
			{
				return node.get_left();
			}

			BSTnode<K> smallest_node = smallest(node);
			node.set_key(smallest_node.get_key());
			node.set_right(delete(node.get_right(), smallest_node.get_key()));
			return node;
		}

		if (key.compareTo(node.get_key()) < 0)
		{
			node.set_left(delete(node.get_left(), key));
			return node;
		}

		else
		{
			node.set_right(delete(node.get_right(), key));
			return node;
		}
	}

	public void delete(K key)
	{
		delete(this.root, key);
	}
	

}
























