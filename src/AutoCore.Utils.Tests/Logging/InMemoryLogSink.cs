namespace AutoCore.Utils.Tests.Logging;

using AutoCore.Utils.Logging;

/// <summary>
/// Recording sink for tests (the structured-logging counterpart of RecordingInventoryPersistence):
/// captures every record in memory so tests can assert on structured event identity and
/// properties instead of human-readable wording.
/// </summary>
public sealed class InMemoryLogSink : ILogSink
{
    private readonly object _lock = new();
    private readonly List<StructuredLogRecord> _records = new();

    public void Write(StructuredLogRecord record)
    {
        if (record == null)
            return;

        lock (_lock)
            _records.Add(record);
    }

    public IReadOnlyList<StructuredLogRecord> Records
    {
        get
        {
            lock (_lock)
                return _records.ToArray();
        }
    }

    public StructuredLogRecord Single(string eventName)
    {
        var matches = Records.Where(r => r.EventName == eventName).ToArray();

        if (matches.Length != 1)
        {
            throw new InvalidOperationException(
                $"Expected exactly one '{eventName}' record, found {matches.Length}. " +
                $"Recorded events: [{string.Join(", ", Records.Select(r => r.EventName))}]");
        }

        return matches[0];
    }

    public void Clear()
    {
        lock (_lock)
            _records.Clear();
    }
}
