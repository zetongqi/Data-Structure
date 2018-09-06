import java.util.*;

public class Heap <T>
{
	private ArrayList<Heap_node> heap = new ArrayList<Heap_node>();

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
}