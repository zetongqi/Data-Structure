import java.util.*;

public class Heap <T>
{
	private ArrayList<Heap_node> heap = new ArrayList<Heap_node>();

	// initialize to occupy the element indexed 0
	public Heap()
	{
		this.heap.add(new Heap_node(0, 10000));
	}

	public void Insert(Heap_node hn)
	{
		this.heap.add(hn);
		int index = this.heap.size();
		while (index > 0)
		{
			if (this.heap.get(index/2).getPriority() < this.heap.get(index).getPriority())
			{
				Heap_node temp_hn = this.heap.get(index/2);
				this.heap.set(index/2, this.heap.get(index));
				this.heap.set(index,  temp_hn);
			}
			index = index/2;
		}

	}

	public void removeMax()
	{
		this.heap.set(1, this.heap.get(this.heap.size() - 1));
		this.heap.remove(this.heap.size() - 1);
		int index = 1;
		while (index < this.heap.size())
		{	
			// right branch
			if (this.heap.get(index*2+1).getPriority() > this.heap.get(index).getPriority())
			{
				Heap_node temp_hn = this.heap.get(index);
				this.heap.set(index, this.heap.get(index*2+1));
				this.heap.set(index*2+1, temp_hn);
			}
			// left branch
			if (this.heap.get(index*2).getPriority() > this.heap.get(index).getPriority())
			{
				Heap_node temp_hn = this.heap.get(index);
				this.heap.set(index, this.heap.get(index*2));
				this.heap.set(index*2, temp_hn);
			}
		}
	}
}