namespace AutoCore.Utils.Timer;

public class TimedItem
{
    public string Name { get; }
    public bool Repeating { get; }
    public long Timer { get; }
    public long CurrentTimer { get; private set; }
    public Action Action { get; }

    /// <summary>
    /// True once this item has been removed or replaced.
    /// <para>
    /// SS-09: due actions are invoked outside the dictionary lock, so an item can be
    /// unregistered after it was collected as due but before it runs. This flag preserves the
    /// original semantics — a timer removed earlier in the same pass does not fire.
    /// </para>
    /// </summary>
    public bool Cancelled { get; private set; }

    internal void Cancel() => Cancelled = true;

    public TimedItem(string name, long timer, bool repeating, Action action)
    {
        Name = name;
        Repeating = repeating;
        CurrentTimer = Timer = timer;
        Action = action;
    }

    public bool Update(long delta)
    {
        if (CurrentTimer <= delta)
        {
            CurrentTimer = Timer - (delta - CurrentTimer);
            return true;
        }

        CurrentTimer -= delta;
        return false;
    }

    public void Schedule(long timer) => CurrentTimer = timer;
    public void ResetTimer() => CurrentTimer = Timer;
}
