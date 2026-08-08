namespace AutoCore.Utils.Timer;

using AutoCore.Utils.Reliability;

/// <summary>
/// Cooperative timer wheel pumped from the server tick (see <c>MainLoop</c>). Not an OS timer:
/// <see cref="Update"/> must be called with the elapsed delta each tick.
/// </summary>
public class Timer
{
    private readonly Dictionary<string, TimedItem> _timedItems = new();

    public void Add(string name, long timer, bool repeating, Action action)
    {
        lock (_timedItems)
        {
            // Cancel the entry being replaced so a superseded action already collected as
            // due for this tick does not still run.
            if (_timedItems.TryGetValue(name, out var existing))
                existing.Cancel();

            _timedItems[name] = new TimedItem(name, timer, repeating, action);
        }
    }

    public void Remove(string name)
    {
        lock (_timedItems)
        {
            if (_timedItems.TryGetValue(name, out var existing))
                existing.Cancel();

            _timedItems.Remove(name);
        }
    }

    /// <summary>
    /// Advances every timer by <paramref name="delta"/> milliseconds and runs the actions
    /// that came due.
    /// <para>
    /// SS-09: due actions are collected under the lock, one-shots are unregistered, and only
    /// then are the actions invoked — outside the lock and individually isolated. Previously
    /// the invoke happened inline inside both the lock and the <c>foreach</c>, which meant a
    /// single throwing action (a) skipped every remaining due timer, (b) skipped the one-shot
    /// cleanup so a failing one-shot re-fired forever, and (c) made it illegal for an action
    /// to schedule follow-up work, because that mutates the dictionary mid-enumeration.
    /// </para>
    /// <para>
    /// <see cref="OperationCanceledException"/> from an action still propagates: cancellation
    /// is control flow and the caller's loop needs to see it.
    /// </para>
    /// </summary>
    public void Update(long delta)
    {
        List<TimedItem> due = null;

        lock (_timedItems)
        {
            List<string> toRemove = null;

            foreach (var item in _timedItems)
            {
                if (!item.Value.Update(delta))
                    continue;

                (due ??= new()).Add(item.Value);

                if (!item.Value.Repeating)
                    (toRemove ??= new()).Add(item.Key);
            }

            // Unregister one-shots before invoking, so a throwing action cannot leave itself
            // registered and re-fire on every subsequent tick.
            if (toRemove != null)
                foreach (var key in toRemove)
                    _timedItems.Remove(key);
        }

        if (due == null)
            return;

        foreach (var item in due)
        {
            // Skip anything unregistered or replaced by an earlier action in this same pass.
            if (item.Cancelled)
                continue;

            Guard.Run($"timed action '{item.Name}'", item.Action);
        }
    }

    public void Schedule(string name, long timer)
    {
        lock (_timedItems)
            if (_timedItems.TryGetValue(name, out var value))
                value.Schedule(timer);
    }

    public void ResetTimer(string name)
    {
        lock (_timedItems)
        {
            if (_timedItems.TryGetValue(name, out var value))
                value.ResetTimer();
        }
    }
}
