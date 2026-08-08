namespace AutoCore.Utils.Logging;

using System.Threading.Channels;

/// <summary>
/// Structured NDJSON file sink: a bounded in-memory queue drained by one background
/// writer task, with size-based file rotation.
/// <para>
/// Contract for gameplay threads (SS-06 semantics): <see cref="Write"/> never throws and
/// never blocks — when the queue is full the record is dropped and counted
/// (<see cref="DroppedCount"/>) instead of stalling the tick or a packet handler. When the
/// destination is unwritable the sink degrades to a no-op; console logging is unaffected.
/// </para>
/// <para>
/// The writer flushes when the queue drains rather than per line, so bursty logging does
/// not turn into one fsync per record (the legacy Logger's AutoFlush cost).
/// </para>
/// </summary>
public sealed class NdjsonFileSink : ILogSink, IDisposable
{
    private readonly Channel<object> _queue;
    private readonly string _path;
    private readonly long _maxFileBytes;
    private readonly int _maxRolledFiles;
    private readonly Task _writerTask;

    private StreamWriter _writer;
    private long _bytesInCurrentFile;
    private long _dropped;
    private volatile bool _failed;
    private bool _disposed;

    /// <param name="path">Destination file; rolled files are created alongside it.</param>
    /// <param name="queueCapacity">Bounded queue size; overflow is dropped and counted.</param>
    /// <param name="maxFileBytes">Roll to a new file after the current one exceeds this size.</param>
    /// <param name="maxRolledFiles">Rolled files kept before the oldest is deleted.</param>
    /// <param name="createDirectories">Create the parent directory if missing.</param>
    /// <param name="startWriterForTests">Test seam: false leaves the queue undrained so
    /// overflow behavior can be asserted deterministically. Production always passes true.</param>
    public NdjsonFileSink(
        string path,
        int queueCapacity = 8192,
        long maxFileBytes = 256L * 1024 * 1024,
        int maxRolledFiles = 4,
        bool createDirectories = true,
        bool startWriterForTests = true)
    {
        _path = path;
        _maxFileBytes = Math.Max(1, maxFileBytes);
        _maxRolledFiles = Math.Max(0, maxRolledFiles);

        _queue = Channel.CreateBounded<object>(new BoundedChannelOptions(Math.Max(1, queueCapacity))
        {
            SingleReader = true,
            SingleWriter = false,
            FullMode = BoundedChannelFullMode.Wait // combined with TryWrite => non-blocking drop
        });

        OpenWriter(createDirectories);

        _writerTask = startWriterForTests
            ? Task.Run(WriterLoopAsync)
            : Task.CompletedTask;
    }

    /// <summary>Records dropped because the queue was full or the sink had failed.</summary>
    public long DroppedCount => Interlocked.Read(ref _dropped);

    public void Write(StructuredLogRecord record)
    {
        if (record == null)
            return;

        if (_failed || !_queue.Writer.TryWrite(record))
            Interlocked.Increment(ref _dropped);
    }

    /// <summary>
    /// Waits until everything queued before the call has reached the file (or the timeout
    /// elapses). Never throws; safe to call during shutdown and from CrashHandler.
    /// </summary>
    public void Flush(TimeSpan timeout)
    {
        try
        {
            var marker = new TaskCompletionSource(TaskCreationOptions.RunContinuationsAsynchronously);

            if (!_queue.Writer.TryWrite(marker))
                return; // Queue full or completed; nothing stronger we can promise.

            marker.Task.Wait(timeout);
        }
        catch
        {
            // Flush is best-effort by contract.
        }
    }

    public void Dispose()
    {
        if (_disposed)
            return;

        _disposed = true;

        try
        {
            _queue.Writer.TryComplete();
            _writerTask.Wait(TimeSpan.FromSeconds(5));

            DrainRemaining();

            _writer?.Flush();
            _writer?.Dispose();
        }
        catch
        {
            // Disposal is best-effort; there is no caller that can act on a failure here.
        }
        finally
        {
            _writer = null;
        }
    }

    private void OpenWriter(bool createDirectories)
    {
        try
        {
            if (createDirectories)
            {
                var directory = Path.GetDirectoryName(Path.GetFullPath(_path));

                if (!string.IsNullOrEmpty(directory))
                    Directory.CreateDirectory(directory);
            }

            var stream = new FileStream(_path, FileMode.Append, FileAccess.Write, FileShare.Read);
            _bytesInCurrentFile = stream.Length;
            _writer = new StreamWriter(stream);
        }
        catch (Exception ex)
        {
            _failed = true;
            _writer = null;
            Logger.WriteLog(LogType.Warning,
                $"NdjsonFileSink could not open '{_path}'; structured file logging disabled. {ex.GetType().Name}: {ex.Message}");
        }
    }

    private async Task WriterLoopAsync()
    {
        try
        {
            while (await _queue.Reader.WaitToReadAsync().ConfigureAwait(false))
            {
                DrainAvailable();
            }
        }
        catch
        {
            // The reader only throws if the channel is broken; nothing left to drain.
        }
    }

    /// <summary>Writes every currently queued item, then flushes once.</summary>
    private void DrainAvailable()
    {
        var wroteAny = false;

        while (_queue.Reader.TryRead(out var item))
        {
            if (item is TaskCompletionSource marker)
            {
                if (wroteAny)
                {
                    SafeFlush();
                    wroteAny = false;
                }

                marker.TrySetResult();
                continue;
            }

            if (item is StructuredLogRecord record)
                wroteAny |= WriteRecord(record);
        }

        if (wroteAny)
            SafeFlush();
    }

    private void DrainRemaining() => DrainAvailable();

    private bool WriteRecord(StructuredLogRecord record)
    {
        if (_failed || _writer == null)
        {
            Interlocked.Increment(ref _dropped);
            return false;
        }

        try
        {
            var line = NdjsonSerializer.Serialize(record);

            _writer.WriteLine(line);

            // The stream is buffered, so track size ourselves instead of asking the file.
            _bytesInCurrentFile += line.Length + Environment.NewLine.Length;

            if (_bytesInCurrentFile >= _maxFileBytes)
                RollFile();

            return true;
        }
        catch (Exception ex)
        {
            // Disk full, handle closed. Disable rather than throwing per record.
            _failed = true;
            Logger.WriteLog(LogType.Warning,
                $"NdjsonFileSink write failed; structured file logging disabled. {ex.GetType().Name}: {ex.Message}");
            return false;
        }
    }

    private void SafeFlush()
    {
        try
        {
            _writer?.Flush();
        }
        catch (Exception ex)
        {
            _failed = true;
            Logger.WriteLog(LogType.Warning,
                $"NdjsonFileSink flush failed; structured file logging disabled. {ex.GetType().Name}: {ex.Message}");
        }
    }

    private void RollFile()
    {
        _writer.Flush();
        _writer.Dispose();
        _writer = null;

        var directory = Path.GetDirectoryName(Path.GetFullPath(_path)) ?? ".";
        var stem = Path.GetFileNameWithoutExtension(_path);
        var extension = Path.GetExtension(_path);

        var rolledName = Path.Combine(directory,
            $"{stem}.{DateTime.UtcNow:yyyyMMddHHmmssfff}{extension}");

        File.Move(_path, rolledName);

        PruneRolledFiles(directory, stem, extension);

        _writer = new StreamWriter(
            new FileStream(_path, FileMode.Append, FileAccess.Write, FileShare.Read));
        _bytesInCurrentFile = 0;
    }

    private void PruneRolledFiles(string directory, string stem, string extension)
    {
        try
        {
            var rolled = Directory.GetFiles(directory, $"{stem}.*{extension}")
                .Where(f => !string.Equals(Path.GetFullPath(f), Path.GetFullPath(_path), StringComparison.OrdinalIgnoreCase))
                .OrderBy(File.GetCreationTimeUtc)
                .ToList();

            while (rolled.Count > _maxRolledFiles)
            {
                File.Delete(rolled[0]);
                rolled.RemoveAt(0);
            }
        }
        catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
        {
            // Pruning is housekeeping; never let it take down the writer.
        }
    }
}
