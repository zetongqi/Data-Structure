public class Priority_node <T>
{
	private T value;
	private int priority;

	public Priority_node(T value, int priority)
	{
		this.value = value;
		this.priority = priority;
	}

	public T getValue()
	{
		return this.value;
	}

	public void changeValue(T newValue)
	{
		this.value = newValue;
	}

	public int getPriority()
	{
		return this.priority;
	}

	public void changePriority(int newPriority)
	{
		this.priority = newPriority;
	}
}
