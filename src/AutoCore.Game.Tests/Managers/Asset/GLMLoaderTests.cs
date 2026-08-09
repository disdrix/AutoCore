using System.Text;
using AutoCore.Game.Managers.Asset;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers.Asset;

/// <summary>
/// Soft-fail and minimal valid-GLM coverage for <see cref="GLMLoader"/>.
/// Live multi-pack game asset I/O is not exercised here.
/// </summary>
[TestClass]
public class GLMLoaderTests
{
    private string _tempDir = null!;

    [TestInitialize]
    public void Init()
    {
        _tempDir = Path.Combine(Path.GetTempPath(), $"glm-tests-{Guid.NewGuid():N}");
        Directory.CreateDirectory(_tempDir);
    }

    [TestCleanup]
    public void Cleanup()
    {
        // GLMLoader keeps FileStreams open on successfully loaded packs for the process lifetime.
        // Best-effort cleanup; leftover temp dirs are under the OS temp root.
        try
        {
            if (Directory.Exists(_tempDir))
                Directory.Delete(_tempDir, recursive: true);
        }
        catch (IOException)
        {
            // File still locked by open GLM FileStream — acceptable for unit tests.
        }
        catch (UnauthorizedAccessException)
        {
        }
    }

    [TestMethod]
    public void Load_EmptyDirectory_ReturnsFalse()
    {
        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
        Assert.IsFalse(loader.CanGetReader("anything.bin"));
        Assert.IsNull(loader.GetStream("anything.bin"));
    }

    [TestMethod]
    public void Load_TooSmallFile_SkipsAndReturnsFalse()
    {
        File.WriteAllBytes(Path.Combine(_tempDir, "tiny.glm"), new byte[] { 1, 2 });
        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
    }

    [TestMethod]
    public void Load_InvalidHeader_SkipsAndReturnsFalse()
    {
        // 8-byte file: garbage + headerOff=0 pointing at "XXXX"
        using (var fs = File.Create(Path.Combine(_tempDir, "bad.glm")))
        using (var w = new BinaryWriter(fs))
        {
            w.Write(Encoding.ASCII.GetBytes("XXXX"));
            w.Write(0); // headerOff
        }

        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
    }

    [TestMethod]
    public void Load_UnsupportedTextMode_SkipsAndReturnsFalse()
    {
        WriteCorruptChunkHeader(_tempDir, "textmode.glm", opt0: 0, opt1: 76);
        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
    }

    [TestMethod]
    public void Load_BigEndian_SkipsAndReturnsFalse()
    {
        WriteCorruptChunkHeader(_tempDir, "be.glm", opt0: 66, opt1: 0);
        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
    }

    [TestMethod]
    public void Load_EntryCountMismatch_SkipsAndReturnsFalse()
    {
        // Valid-looking header but entryCount != string table names.
        var path = Path.Combine(_tempDir, "mismatch.glm");
        using (var fs = File.Create(path))
        using (var w = new BinaryWriter(fs))
        {
            // payload
            w.Write(Encoding.ASCII.GetBytes("hi"));
            // string table "a\0"
            var strTableOff = (int)fs.Position;
            w.Write((byte)'a');
            w.Write((byte)0);
            var strTableSize = 2;
            // header
            var headerOff = (int)fs.Position;
            w.Write(Encoding.ASCII.GetBytes("CHNK"));
            w.Write((byte)66);
            w.Write((byte)76);
            w.Write((byte)0);
            w.Write((byte)0);
            w.Write(strTableOff);
            w.Write(strTableSize);
            w.Write(2); // claim 2 entries, only 1 name
            // one file entry (will not be reached if count check fails first... actually
            // CreateEntriesByStringTable runs first, then throws on count mismatch)
            w.Write(0); // offset
            w.Write(2); // size
            w.Write(2);
            w.Write(0);
            w.Write((short)0);
            w.Write(0);
            w.Write(headerOff);
        }

        var loader = new GLMLoader();
        Assert.IsFalse(loader.Load(_tempDir));
    }

    [TestMethod]
    public void EnumerateFileNames_ListsEntriesAcrossPacks()
    {
        // Needed by AutoCore.Sim's hull cache: physics.glm entry names differ in CASE from
        // clonebase PhysicsName, so consumers build their own case-insensitive index.
        WriteMinimalGlm(Path.Combine(_tempDir, "packa.glm"), "Obj_Thing.cache", new byte[] { 1 });

        var loader = new GLMLoader();
        Assert.IsTrue(loader.Load(_tempDir));

        var names = loader.EnumerateFileNames().ToList();
        CollectionAssert.Contains(names, "Obj_Thing.cache");
    }

    [TestMethod]
    public void Load_ValidMinimalGlm_CanReadPayload()
    {
        WriteMinimalGlm(Path.Combine(_tempDir, "pack.glm"), "note.txt", Encoding.UTF8.GetBytes("hello"));

        var loader = new GLMLoader();
        Assert.IsTrue(loader.Load(_tempDir));
        Assert.IsTrue(loader.CanGetReader("note.txt"));
        Assert.IsFalse(loader.CanGetReader("missing.txt"));

        using var stream = loader.GetStream("note.txt");
        Assert.IsNotNull(stream);
        using var reader = new StreamReader(stream!, Encoding.UTF8);
        Assert.AreEqual("hello", reader.ReadToEnd());

        using var br = loader.GetReader("note.txt");
        var bytes = br.ReadBytes(5);
        CollectionAssert.AreEqual(Encoding.UTF8.GetBytes("hello"), bytes);
    }

    [TestMethod]
    public void Load_MiscGlmPreferred_OverOtherPacks()
    {
        WriteMinimalGlm(Path.Combine(_tempDir, "other.glm"), "shared.bin", Encoding.UTF8.GetBytes("OTHER"));
        WriteMinimalGlm(Path.Combine(_tempDir, "misc.glm"), "shared.bin", Encoding.UTF8.GetBytes("MISC!"));

        var loader = new GLMLoader();
        Assert.IsTrue(loader.Load(_tempDir));
        Assert.IsTrue(loader.CanGetReader("shared.bin"));

        using var stream = loader.GetStream("shared.bin");
        Assert.IsNotNull(stream);
        using var reader = new StreamReader(stream!, Encoding.UTF8);
        Assert.AreEqual("MISC!", reader.ReadToEnd());
    }

    [TestMethod]
    public void Load_OneGoodOneBad_StillSucceeds()
    {
        File.WriteAllBytes(Path.Combine(_tempDir, "tiny.glm"), new byte[] { 1 });
        WriteMinimalGlm(Path.Combine(_tempDir, "ok.glm"), "a.bin", new byte[] { 9 });

        var loader = new GLMLoader();
        Assert.IsTrue(loader.Load(_tempDir));
        Assert.IsTrue(loader.CanGetReader("a.bin"));
    }

    [TestMethod]
    public void GetStream_FallsBackToNonMiscPack()
    {
        WriteMinimalGlm(Path.Combine(_tempDir, "maps.glm"), "map.fam", Encoding.UTF8.GetBytes("FAM"));

        var loader = new GLMLoader();
        Assert.IsTrue(loader.Load(_tempDir));

        using var stream = loader.GetStream("map.fam");
        Assert.IsNotNull(stream);
        using var reader = new StreamReader(stream!, Encoding.UTF8);
        Assert.AreEqual("FAM", reader.ReadToEnd());
    }

    private static void WriteCorruptChunkHeader(string dir, string fileName, byte opt0, byte opt1)
    {
        var path = Path.Combine(dir, fileName);
        using var fs = File.Create(path);
        using var w = new BinaryWriter(fs);
        var headerOff = 0;
        w.Write(Encoding.ASCII.GetBytes("CHNK"));
        w.Write(opt0);
        w.Write(opt1);
        w.Write((byte)0);
        w.Write((byte)0);
        w.Write(0); // strTableOff
        w.Write(0); // strTableSize
        w.Write(0); // entryCount
        w.Write(headerOff);
    }

    /// <summary>
    /// Builds a single-entry little-endian binary GLM the production reader accepts.
    /// Layout: [payload][string table][CHNK header + FileEntry][headerOff footer].
    /// </summary>
    internal static void WriteMinimalGlm(string path, string entryName, byte[] payload)
    {
        using var fs = File.Create(path);
        using var w = new BinaryWriter(fs);

        // payload
        w.Write(payload);

        // string table: name\0
        var strTableOff = (int)fs.Position;
        var nameBytes = Encoding.ASCII.GetBytes(entryName);
        w.Write(nameBytes);
        w.Write((byte)0);
        var strTableSize = nameBytes.Length + 1;

        // CHNK header
        var headerOff = (int)fs.Position;
        w.Write(Encoding.ASCII.GetBytes("CHNK"));
        w.Write((byte)66); // binary
        w.Write((byte)76); // little-endian
        w.Write((byte)0);
        w.Write((byte)0);
        w.Write(strTableOff);
        w.Write(strTableSize);
        w.Write(1); // entryCount

        // FileEntry
        w.Write(0); // Offset
        w.Write(payload.Length); // Size
        w.Write(payload.Length); // RealSize
        w.Write(0); // ModifiedTime
        w.Write((short)0); // Scheme
        w.Write(0); // padding int32

        // footer
        w.Write(headerOff);
    }
}
