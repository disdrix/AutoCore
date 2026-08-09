using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

using AutoCore.Game.Map;

/// <summary>
/// Map heightfield from retail map TGA: 32bpp BGRA, height16 = (A&lt;&lt;8)|B, world Y =
/// height16 · 1000 / 65280 (A-channel /255 × 1000 max world height, B = sub-precision).
/// The old ×4/256 decode (level-viewer inference) ran 2% high — live calibration on
/// 2026-08-09 matched this formula to 1–2 cm on two independent maps
/// (h16 8126 → 124.48 obs 124.49; h16 8641 → 132.37 obs 132.35).
/// </summary>
[TestClass]
public class MapTerrainHeightfieldTests
{
    private const float Tol = 0.001f;

    /// <summary>worldY per height16 unit: 1000 / 65280.</summary>
    private const float Scale = 1000f / 65280f;

    [TestMethod]
    public void TryLoad_Parses16BitHeightFromBgraAndSamplesCorners()
    {
        // 2x2 grid, gridSize 10.
        using var stream = BuildHeightTga(2, 2, new ushort[] { 256, 512, 0, 768 });

        Assert.IsTrue(MapTerrainHeightfield.TryLoad(stream, expectedWidth: 2, expectedHeight: 2, gridSize: 10f, out var field, out var error), error);
        Assert.IsNotNull(field);

        Assert.IsTrue(field.TrySample(0f, 0f, out var y00));
        Assert.AreEqual(256f * Scale, y00, Tol);

        Assert.IsTrue(field.TrySample(10f, 0f, out var y10));
        Assert.AreEqual(512f * Scale, y10, Tol);

        Assert.IsTrue(field.TrySample(0f, 10f, out var y01));
        Assert.AreEqual(0f, y01, Tol);

        Assert.IsTrue(field.TrySample(10f, 10f, out var y11));
        Assert.AreEqual(768f * Scale, y11, Tol);
    }

    [TestMethod]
    public void FullScaleAlphaChannel_IsExactlyOneThousandWorldUnits()
    {
        // A=255, B=0 → h16=0xFF00=65280 → 1000.0: the anchor the live calibration pinned.
        using var stream = BuildHeightTga(2, 2, new ushort[] { 65280, 65280, 65280, 65280 });
        Assert.IsTrue(MapTerrainHeightfield.TryLoad(stream, 2, 2, 10f, out var field, out _));

        Assert.IsTrue(field.TrySample(5f, 5f, out var y));
        Assert.AreEqual(1000f, y, Tol);
    }

    [TestMethod]
    public void TrySample_BilinearInterpolatesBetweenCells()
    {
        // Midpoint between h16 256 and 512 at z=0 is 384·Scale.
        using var stream = BuildHeightTga(2, 2, new ushort[] { 256, 512, 0, 768 });
        Assert.IsTrue(MapTerrainHeightfield.TryLoad(stream, 2, 2, 10f, out var field, out _));

        Assert.IsTrue(field.TrySample(5f, 0f, out var y));
        Assert.AreEqual(384f * Scale, y, Tol);
    }

    [TestMethod]
    public void TryLoad_RejectsDimensionMismatch()
    {
        using var stream = BuildHeightTga(2, 2, new ushort[] { 0, 0, 0, 0 });
        Assert.IsFalse(MapTerrainHeightfield.TryLoad(stream, expectedWidth: 4, expectedHeight: 4, gridSize: 5f, out var field, out var error));
        Assert.IsNull(field);
        Assert.IsTrue(error.Contains("dimension", StringComparison.OrdinalIgnoreCase) || error.Contains("match", StringComparison.OrdinalIgnoreCase));
    }

    [TestMethod]
    public void TrySample_ClampsToMapEdge()
    {
        using var stream = BuildHeightTga(2, 2, new ushort[] { 256, 512, 0, 768 });
        Assert.IsTrue(MapTerrainHeightfield.TryLoad(stream, 2, 2, 10f, out var field, out _));

        // Outside world extent — clamp to last cell (1,1) h16=768.
        Assert.IsTrue(field.TrySample(1000f, 1000f, out var y));
        Assert.AreEqual(768f * Scale, y, Tol);
    }

    /// <summary>
    /// Build uncompressed 32bpp TGA in RAW (top-down / file) order: row0 = Z=0, col0 = X=0.
    /// Pixels: h16 encoded as B=low, G=0, R=0, A=high (retail LoadMapImage channel layout).
    /// </summary>
    internal static MemoryStream BuildHeightTga(int width, int height, ushort[] heightsRowMajor)
    {
        Assert.AreEqual(width * height, heightsRowMajor.Length);
        var stream = new MemoryStream();
        using var w = new BinaryWriter(stream, System.Text.Encoding.UTF8, leaveOpen: true);
        w.Write((byte)0); // id length
        w.Write((byte)0); // no colormap
        w.Write((byte)2); // uncompressed truecolor
        w.Write(new byte[5]);
        w.Write((ushort)0);
        w.Write((ushort)0);
        w.Write((ushort)width);
        w.Write((ushort)height);
        w.Write((byte)32);
        w.Write((byte)0); // descriptor; engine treats map TGA as raw order regardless

        foreach (var h16 in heightsRowMajor)
        {
            w.Write((byte)(h16 & 0xFF));        // B = low byte
            w.Write((byte)0);                     // G
            w.Write((byte)0);                     // R
            w.Write((byte)((h16 >> 8) & 0xFF)); // A = high byte
        }

        stream.Position = 0;
        return stream;
    }
}
