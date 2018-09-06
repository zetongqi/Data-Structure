import java.util.*;

public class Priority_queue <T>
{
	private ArrayList<Priority_node> queue = new ArrayList<Priority_node>();

	public boolean isEmpty()
	{
		return this.queue.isEmpty();
	}

	private void Sort()
	{
		if (this.queue.size() <= 1)
		{
			return;
		}
		else
		{
			Priority_node key;
			int i;
			for (int j=1; j<this.queue.size(); j++)
			{
				key = this.queue.get(j);
				i = j-1;
				while(i>-1 && this.queue.get(i).getPriority() > key.getPriority())
				{
					this.queue.set(i+1, this.queue.get(i));
					i = i-1;
				}
				this.queue.set(i+1, key);
			}
		}
	}

	public void Insert(Priority_node pn)
	{
		this.queue.add(pn);
		this.Sort();
	}

	public void Pop()
	{
		this.queue.remove(0);
	}

	public void printQueue()
	{
		for (int i = 0; i < this.queue.size(); i++)
		{
			System.out.println(this.queue.get(i).getPriority());
		}
	}

}