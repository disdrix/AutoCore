namespace AutoCore.Game.Managers;

using AutoCore.Utils;

/// <summary>
/// Loud, greppable diagnostics when a partial handler exercises a path it does not fully implement.
/// Always logs as Error so messages show even when Debug is filtered.
/// Prefix: INCOMPLETE[HandlerName]
/// </summary>
public static class IncompleteHandlerLog
{
    public const string Prefix = "INCOMPLETE";

    /// <summary>Keys already warned this process (hot paths must not Error every tick).</summary>
    static readonly HashSet<string> s_onceKeys = new();

    /// <summary>Test hook: receives the full message body (no timestamp).</summary>
    internal static Action<string> TestSink { get; set; }

    /// <summary>
    /// Returns true the first time <paramref name="key"/> is seen; false thereafter.
    /// Used so incomplete warnings fire once per logical site, not every AutoPatrol frame.
    /// </summary>
    public static bool TryMarkOnce(string key)
    {
        if (string.IsNullOrEmpty(key))
            return false;
        lock (s_onceKeys)
            return s_onceKeys.Add(key);
    }

    /// <summary>Test hook: clear once-keys between tests.</summary>
    internal static void ResetOnceKeysForTests()
    {
        lock (s_onceKeys)
            s_onceKeys.Clear();
    }

    /// <summary>
    /// Report a partial/stub implementation hit.
    /// </summary>
    /// <param name="handler">Short handler id, e.g. AutoPatrol, Reaction.Create, Mission.CompleteObjective</param>
    /// <param name="context">Runtime ids/state that identify the hit</param>
    /// <param name="gap">What the current code does not do</param>
    /// <param name="todo">Concrete work needed for a generic handler</param>
    public static void Warn(string handler, string context, string gap, string todo)
    {
        var message = $"{Prefix}[{handler}] {context} | gap: {gap} | TODO: {todo}";
        TestSink?.Invoke(message);
        Logger.WriteLog(LogType.Error, message);
    }
}
