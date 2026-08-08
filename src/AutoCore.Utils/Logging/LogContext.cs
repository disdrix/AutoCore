namespace AutoCore.Utils.Logging;

/// <summary>
/// Ambient diagnostic context for structured logging: an immutable linked chain of
/// key/value scopes carried in an <see cref="AsyncLocal{T}"/>.
/// <para>
/// A scope pushed at a boundary (packet handler, auth dispatch, command handler) is
/// automatically visible to every structured log record created further down the call
/// chain — including across <c>await</c> and <c>Task.Run</c>. Work handed to plain
/// threads, timers or queues does NOT inherit the context automatically; those sites
/// must call <see cref="Capture"/> at enqueue time and <see cref="Restore"/> in the worker.
/// </para>
/// <para>
/// Same contract as <see cref="Logger"/> (SS-06): every member is total and never throws.
/// Scopes are immutable, so readers on other threads are always safe.
/// </para>
/// </summary>
public sealed class LogContext
{
    private static readonly AsyncLocal<Node> Ambient = new();

    private readonly Node _node;

    private LogContext(Node node)
    {
        _node = node;
    }

    /// <summary>A node in the immutable scope chain. Child values shadow parent values.</summary>
    private sealed class Node
    {
        public Node Parent;
        public KeyValuePair<string, object>[] Properties;
    }

    /// <summary>
    /// Pushes a scope whose properties are ambient until the returned handle is disposed.
    /// Later scopes shadow earlier values for the same key.
    /// </summary>
    public static IDisposable Push(params (string Key, object Value)[] properties)
    {
        var previous = Ambient.Value;

        try
        {
            var cleaned = Clean(properties);

            if (cleaned.Length > 0)
                Ambient.Value = new Node { Parent = previous, Properties = cleaned };
        }
        catch
        {
            // Context is diagnostics, never control flow: on any failure keep the previous
            // scope rather than throwing out of a boundary that was setting up logging.
            Ambient.Value = previous;
        }

        return new Scope(previous);
    }

    /// <summary>Snapshots the current ambient chain for hand-off to a queue or plain thread.</summary>
    public static LogContext Capture() => new(Ambient.Value);

    /// <summary>
    /// Re-establishes a captured snapshot on the current thread until the returned handle
    /// is disposed. A null snapshot yields an empty context (never throws).
    /// </summary>
    public static IDisposable Restore(LogContext snapshot)
    {
        var previous = Ambient.Value;
        Ambient.Value = snapshot?._node;
        return new Scope(previous);
    }

    /// <summary>
    /// The flattened ambient properties, innermost scope winning per key.
    /// Returns an empty list when no scope is active.
    /// </summary>
    public static IReadOnlyList<KeyValuePair<string, object>> CurrentProperties
    {
        get
        {
            var node = Ambient.Value;

            if (node == null)
                return Array.Empty<KeyValuePair<string, object>>();

            var seen = new HashSet<string>(StringComparer.Ordinal);
            var result = new List<KeyValuePair<string, object>>();

            for (; node != null; node = node.Parent)
            {
                foreach (var pair in node.Properties)
                {
                    if (seen.Add(pair.Key))
                        result.Add(pair);
                }
            }

            return result;
        }
    }

    /// <summary>Test seam: drops any ambient chain leaked by a failing test.</summary>
    internal static void ClearForTests() => Ambient.Value = null;

    private static KeyValuePair<string, object>[] Clean((string Key, object Value)[] properties)
    {
        if (properties == null || properties.Length == 0)
            return Array.Empty<KeyValuePair<string, object>>();

        var cleaned = new List<KeyValuePair<string, object>>(properties.Length);

        foreach (var (key, value) in properties)
        {
            if (!string.IsNullOrEmpty(key))
                cleaned.Add(new KeyValuePair<string, object>(key, value));
        }

        return cleaned.ToArray();
    }

    private sealed class Scope : IDisposable
    {
        private readonly Node _previous;
        private bool _disposed;

        public Scope(Node previous)
        {
            _previous = previous;
        }

        public void Dispose()
        {
            if (_disposed)
                return;

            _disposed = true;
            Ambient.Value = _previous;
        }
    }
}
