public class Heap_node <T>
{
	private T value;
	private int priority;

	public Heap_node(T value, int priority)
	{
		this.value = value;
		this.priority = priority;
	}

	public T getValue()
	{
		return this.value;
	}

	public int getPriority()
	{
		return this.priority;
	}
}