namespace AutoCore.Utils.Logging;

/// <summary>
/// Static facade for structured game events — the queryable counterpart of the human-readable
/// <see cref="Logger"/>. Events are named (see <c>LogEvents</c>), carry flat properties, and are
/// automatically enriched with the ambient <see cref="LogContext"/> (session, character,
/// correlation ids) at the call site.
/// <para>
/// Same contract as <see cref="Logger"/> (SS-06): every public member is total — no sink,
/// hostile arguments, or a failing serializer degrade instead of throwing, because these
/// methods are called from catch blocks and packet handlers.
/// </para>
/// </summary>
public static class GameLog
{
    private static ILogSink _sink;
    private static RateLimiter _rateLimiter = new RateLimiter();

    /// <summary>Minimum severity forwarded to the sink. Audit events bypass this filter.</summary>
    public static StructuredLogLevel MinimumLevel { get; set; } = StructuredLogLevel.Info;

    public static void Trace(string eventName, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Trace, eventName, audit: false, errorCode: null, properties);

    public static void Debug(string eventName, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Debug, eventName, audit: false, errorCode: null, properties);

    public static void Info(string eventName, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Info, eventName, audit: false, errorCode: null, properties);

    public static void Warn(string eventName, string errorCode, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Warning, eventName, audit: false, errorCode, properties);

    public static void Error(string eventName, string errorCode, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Error, eventName, audit: false, errorCode, properties);

    public static void Fatal(string eventName, string errorCode, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Fatal, eventName, audit: false, errorCode, properties);

    /// <summary>
    /// Player-action audit-trail event (INFO). Exempt from <see cref="MinimumLevel"/> and
    /// rate limiting: audit events answer "where did this item/money go" and must never be
    /// silently thinned out.
    /// </summary>
    public static void Audit(string eventName, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Info, eventName, audit: true, errorCode: null, properties);

    /// <summary>
    /// Opens a Started/Completed/Failed operation scope: <c>{name}Started</c> is emitted now;
    /// <see cref="OperationScope.Complete"/> emits <c>{name}Completed</c> with
    /// <c>DurationMs</c>; <see cref="OperationScope.Fail"/> — or disposing without either,
    /// e.g. when an exception escapes the body — emits <c>{name}Failed</c>.
    /// </summary>
    public static OperationScope Operation(string operationName, params (string Key, object Value)[] properties)
    {
        var scope = new OperationScope(operationName, properties);

        Emit(StructuredLogLevel.Info, scope.Name + "Started", audit: false, errorCode: null, properties);

        return scope;
    }

    /// <summary>
    /// Mirrors a legacy <see cref="Logger"/> line into the structured pipeline so untouched
    /// call sites stay session-traceable. Called by Logger, not by application code.
    /// </summary>
    internal static void WriteLegacy(LogType type, string message)
    {
        Emit(MapLegacyLevel(type), "Legacy", audit: false, errorCode: null,
            message: message, ("LegacyType", type.ToString()));
    }

    internal static StructuredLogLevel MapLegacyLevel(LogType type) => type switch
    {
        LogType.Debug => StructuredLogLevel.Debug,
        LogType.Test => StructuredLogLevel.Debug,
        LogType.Warning => StructuredLogLevel.Warning,
        LogType.Error => StructuredLogLevel.Error,
        LogType.Fatal => StructuredLogLevel.Fatal,
        _ => StructuredLogLevel.Info
    };

    internal static void Emit(
        StructuredLogLevel level,
        string eventName,
        bool audit,
        string errorCode,
        params (string Key, object Value)[] properties)
    {
        Emit(level, eventName, audit, errorCode, message: null, properties);
    }

    /// <summary>
    /// High-fidelity player-action breadcrumb for bug reports. Always retained in
    /// <see cref="PlayerActionTraceBuffer"/> (even when below MinimumLevel or no NDJSON sink).
    /// Still dual-writes to the sink when level allows.
    /// </summary>
    public static void Action(string eventName, params (string Key, object Value)[] properties)
        => Emit(StructuredLogLevel.Info, eventName, audit: false, errorCode: null,
            message: null, forceTraceBuffer: true, properties);

    private static void Emit(
        StructuredLogLevel level,
        string eventName,
        bool audit,
        string errorCode,
        string message,
        params (string Key, object Value)[] properties)
        => Emit(level, eventName, audit, errorCode, message, forceTraceBuffer: false, properties);

    private static void Emit(
        StructuredLogLevel level,
        string eventName,
        bool audit,
        string errorCode,
        string message,
        bool forceTraceBuffer,
        params (string Key, object Value)[] properties)
    {
        try
        {
            var withCode = errorCode == null
                ? properties
                : Append(properties, ("ErrorCode", errorCode));

            var record = StructuredLogRecord.Create(level, eventName, audit, message, withCode);

            // Bug-report ring is independent of NDJSON min-level / sink availability.
            // Without this, Debug dual-writes and pre-sink boot events never reach /reportbug.
            if (forceTraceBuffer || audit || PlayerActionTraceBuffer.ShouldRetain(record))
                PlayerActionTraceBuffer.Record(record);

            var sink = _sink;
            if (sink == null)
                return;

            // Per-player diagnostics: enrolled sessions pass Debug/Trace regardless of MinimumLevel.
            var elevated = PlayerDiagnostics.IsElevated();
            if (!audit && !forceTraceBuffer && !elevated && level < MinimumLevel)
                return;

            var limiter = _rateLimiter;
            StructuredLogRecord summary = null;
            if (limiter != null && !limiter.Allow(record, out summary))
                return;
            if (summary != null)
                sink.Write(summary);

            sink.Write(record);
        }
        catch
        {
            // Total by contract; there is no safe sink left to report this to.
        }
    }

    internal static (string Key, object Value)[] Append(
        (string Key, object Value)[] properties, (string Key, object Value) extra)
    {
        if (properties == null || properties.Length == 0)
            return new[] { extra };

        var result = new (string Key, object Value)[properties.Length + 1];
        Array.Copy(properties, result, properties.Length);
        result[properties.Length] = extra;
        return result;
    }

    /// <summary>Installs the production sink (called by <see cref="Logger.UpdateConfig"/>).</summary>
    internal static void SetSink(ILogSink sink)
    {
        var previous = Interlocked.Exchange(ref _sink, sink);

        if (!ReferenceEquals(previous, sink) && previous is IDisposable disposable)
        {
            try { disposable.Dispose(); }
            catch { /* Disposal of a dead sink must not fail configuration. */ }
        }
    }

    /// <summary>Best-effort drain of the active sink (shutdown, crash reporting, tests).</summary>
    public static void Flush(TimeSpan timeout)
    {
        try
        {
            (_sink as NdjsonFileSink)?.Flush(timeout);
        }
        catch
        {
            // Flush is best-effort by contract.
        }
    }

    internal static void SetSinkForTests(ILogSink sink) => _sink = sink;

    internal static void FlushForTests(TimeSpan timeout) => Flush(timeout);

    internal static void ResetForTests()
    {
        SetSink(null);
        MinimumLevel = StructuredLogLevel.Info;
        _rateLimiter = new RateLimiter();
        PlayerDiagnostics.Clear();
        PlayerActionTraceBuffer.Clear();
    }

    internal static void SetRateLimiterForTests(RateLimiter limiter) => _rateLimiter = limiter;
}

/// <summary>
/// Disposable handle for an in-flight operation. Not thread-safe; use within one logical flow.
/// </summary>
public sealed class OperationScope : IDisposable
{
    private readonly (string Key, object Value)[] _properties;
    private readonly System.Diagnostics.Stopwatch _stopwatch;
    private bool _finished;

    internal string Name { get; }

    internal OperationScope(string operationName, (string Key, object Value)[] properties)
    {
        Name = string.IsNullOrWhiteSpace(operationName) ? "UnnamedOperation" : operationName;
        _properties = properties ?? Array.Empty<(string, object)>();
        _stopwatch = System.Diagnostics.Stopwatch.StartNew();
    }

    public void Complete(params (string Key, object Value)[] extraProperties)
    {
        if (_finished)
            return;

        _finished = true;

        GameLog.Emit(StructuredLogLevel.Info, Name + "Completed", audit: false, errorCode: null,
            Merge(extraProperties, exception: null));
    }

    public void Fail(Exception exception, params (string Key, object Value)[] extraProperties)
    {
        if (_finished)
            return;

        _finished = true;

        GameLog.Emit(StructuredLogLevel.Error, Name + "Failed", audit: false, errorCode: null,
            Merge(extraProperties, exception));
    }

    public void Dispose()
    {
        if (!_finished)
            Fail(exception: null);
    }

    private (string Key, object Value)[] Merge((string Key, object Value)[] extras, Exception exception)
    {
        var merged = new List<(string Key, object Value)>(_properties);

        if (extras != null)
            merged.AddRange(extras);

        merged.Add(("DurationMs", _stopwatch.ElapsedMilliseconds));

        if (exception != null)
        {
            merged.Add(("ExceptionType", exception.GetType().Name));
            merged.Add(("ExceptionMessage", exception.Message));
        }

        return merged.ToArray();
    }
}
