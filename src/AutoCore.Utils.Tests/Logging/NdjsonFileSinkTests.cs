using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Utils.Tests.Logging;

using System.Text.Json;
using AutoCore.Utils.Logging;

[TestClass]
public class NdjsonFileSinkTests
{
    private string _path;

    [TestInitialize]
    public void Init()
    {
        _path = Path.Combine(Path.GetTempPath(), $"autocore-ndjson-{Guid.NewGuid():N}.ndjson");
    }

    [TestCleanup]
    public void Cleanup()
    {
        LogContext.ClearForTests();

        foreach (var file in ExistingSinkFiles())
        {
            try { File.Delete(file); } catch (IOException) { /* best effort */ }
        }
    }

    [TestMethod]
    public void WriteAndFlush_ProducesOneParseableLinePerRecord()
    {
        using (var sink = new NdjsonFileSink(_path))
        {
            sink.Write(StructuredLogRecord.Create(StructuredLogLevel.Info, "EventOne", audit: false));
            sink.Write(StructuredLogRecord.Create(StructuredLogLevel.Warning, "EventTwo", audit: false));
            sink.Flush(TimeSpan.FromSeconds(5));
        }

        var lines = File.ReadAllLines(_path).Where(l => !string.IsNullOrWhiteSpace(l)).ToArray();

        Assert.AreEqual(2, lines.Length, "Each record must become exactly one NDJSON line.");

        using var first = JsonDocument.Parse(lines[0]);
        using var second = JsonDocument.Parse(lines[1]);

        Assert.AreEqual("EventOne", first.RootElement.GetProperty("EventName").GetString());
        Assert.AreEqual("EventTwo", second.RootElement.GetProperty("EventName").GetString());
    }

    /// <summary>
    /// The sink is called from gameplay threads; it must never block or throw, even when
    /// the destination path is unwritable. Console keeps working, structured logging degrades.
    /// </summary>
    [TestMethod]
    public void Ctor_WithUnwritablePath_DoesNotThrow_AndWritesAreNoOps()
    {
        var unwritable = Path.Combine(Path.GetTempPath(),
            $"autocore-missing-dir-{Guid.NewGuid():N}", "nested", "log.ndjson");

        NdjsonFileSink sink = null;
        try
        {
            sink = new NdjsonFileSink(unwritable, createDirectories: false);
            sink.Write(StructuredLogRecord.Create(StructuredLogLevel.Info, "Dropped", audit: false));
            sink.Flush(TimeSpan.FromSeconds(2));
        }
        catch (Exception ex)
        {
            Assert.Fail($"Sink must degrade, not throw, on an unwritable path; got {ex.GetType().Name}.");
        }
        finally
        {
            sink?.Dispose();
        }
    }

    [TestMethod]
    public void Write_NullRecord_DoesNotThrow()
    {
        using var sink = new NdjsonFileSink(_path);

        sink.Write(null);
        sink.Flush(TimeSpan.FromSeconds(2));

        Assert.AreEqual(0, ReadRecordLines().Length, "A null record is dropped, not serialized.");
    }

    [TestMethod]
    public void Write_WhenQueueFull_DropsAndCounts_InsteadOfBlocking()
    {
        using var sink = new NdjsonFileSink(_path, queueCapacity: 4, startWriterForTests: false);

        for (var i = 0; i < 10; i++)
            sink.Write(StructuredLogRecord.Create(StructuredLogLevel.Info, $"Event{i}", audit: false));

        Assert.AreEqual(6, sink.DroppedCount,
            "Records beyond queue capacity must be dropped and counted, never block the game thread.");
    }

    [TestMethod]
    public void RollsToNewFile_WhenMaxSizeExceeded()
    {
        using (var sink = new NdjsonFileSink(_path, maxFileBytes: 200, maxRolledFiles: 3))
        {
            for (var i = 0; i < 20; i++)
            {
                sink.Write(StructuredLogRecord.Create(
                    StructuredLogLevel.Info, "RollEvent", audit: false, ("Padding", new string('x', 64))));
                sink.Flush(TimeSpan.FromSeconds(5));
            }
        }

        Assert.IsTrue(ExistingSinkFiles().Count() > 1,
            "Exceeding maxFileBytes must roll to a new file so one playtest night cannot fill the disk unbounded.");
    }

    [TestMethod]
    public void Dispose_FlushesPendingRecords()
    {
        var sink = new NdjsonFileSink(_path);
        sink.Write(StructuredLogRecord.Create(StructuredLogLevel.Info, "FinalEvent", audit: false));
        sink.Dispose();

        Assert.IsTrue(ReadRecordLines().Any(l => l.Contains("FinalEvent")),
            "Dispose must drain the queue so shutdown does not lose the last records.");
    }

    private string[] ReadRecordLines()
    {
        if (!File.Exists(_path))
            return Array.Empty<string>();

        // FileShare.ReadWrite: the sink may still hold the file open for writing.
        using var stream = new FileStream(_path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
        using var reader = new StreamReader(stream);

        var lines = new List<string>();

        while (reader.ReadLine() is { } line)
        {
            if (!string.IsNullOrWhiteSpace(line))
                lines.Add(line);
        }

        return lines.ToArray();
    }

    private IEnumerable<string> ExistingSinkFiles()
    {
        var directory = Path.GetDirectoryName(_path);
        var stem = Path.GetFileNameWithoutExtension(_path);

        return Directory.Exists(directory)
            ? Directory.EnumerateFiles(directory, stem + "*")
            : Enumerable.Empty<string>();
    }
}
