using AutoCore.Game.Inventory;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Inventory;

/// <summary>
/// Client parity: FUN_00570840 (CanPlace), FUN_005713a0 (first-fit Y then X).
/// Cargo grid is width 6, page height 13 (VehicleCargoCapacity).
/// </summary>
[TestClass]
public class InventoryGridPlacementTests
{
    private const int Width = VehicleCargoCapacity.GridWidth; // 6
    private const int Height = VehicleCargoCapacity.RowsPerPage; // 13 one page
    private const int PageHeight = VehicleCargoCapacity.RowsPerPage;

    [TestMethod]
    public void EnumerateCells_TwoByTwoAtOrigin_MatchesSlots1_2_7_8()
    {
        // 1-based row-major slots: y*6+x+1 → 1,2,7,8
        var cells = InventoryGridPlacement.EnumerateCells(originX: 0, originY: 0, sizeX: 2, sizeY: 2).ToList();

        Assert.AreEqual(4, cells.Count);
        var asTuples = cells.Select(c => ((int)c.X, (int)c.Y)).ToArray();
        Assert.AreEqual((0, 0), asTuples[0]);
        Assert.AreEqual((1, 0), asTuples[1]);
        Assert.AreEqual((0, 1), asTuples[2]);
        Assert.AreEqual((1, 1), asTuples[3]);

        var oneBased = cells.Select(c => c.Y * Width + c.X + 1).OrderBy(s => s).ToArray();
        CollectionAssert.AreEqual(new[] { 1, 2, 7, 8 }, oneBased);
    }

    [TestMethod]
    public void CanPlace_TwoByTwoAtLastColumn_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied,
            x: 5, y: 0, sizeX: 2, sizeY: 2));
    }

    [TestMethod]
    public void CanPlace_TwoByTwoOnPageBoundary_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        // Page height 13: y=12 + sizeY=2 would span pages
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied,
            x: 0, y: 12, sizeX: 2, sizeY: 2));
    }

    [TestMethod]
    public void CanPlace_PageSpanWithinTallerGrid_FailsWhileInPageFits()
    {
        // Two pages (height 26): bounds allow y=12 sizeY=2, but page rule forbids spanning.
        const int twoPageHeight = PageHeight * 2;
        var occupied = new HashSet<(byte X, byte Y)>();

        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, twoPageHeight, PageHeight, occupied,
            x: 0, y: 12, sizeX: 2, sizeY: 2));

        Assert.IsTrue(InventoryGridPlacement.CanPlace(
            Width, twoPageHeight, PageHeight, occupied,
            x: 0, y: 11, sizeX: 2, sizeY: 2));

        Assert.IsTrue(InventoryGridPlacement.CanPlace(
            Width, twoPageHeight, PageHeight, occupied,
            x: 0, y: 13, sizeX: 2, sizeY: 2));
    }

    [TestMethod]
    public void CanPlace_TwoByTwoOnEmptyGrid_SucceedsAtOrigin()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        Assert.IsTrue(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied,
            x: 0, y: 0, sizeX: 2, sizeY: 2));
    }

    [TestMethod]
    public void CanPlace_OverlappingFootprint_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)> { (1, 0) };

        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied,
            x: 0, y: 0, sizeX: 2, sizeY: 2));
    }

    [TestMethod]
    public void FindFirstFree_EmptyGrid_ReturnsOrigin()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied,
            sizeX: 2, sizeY: 2, out var x, out var y));
        Assert.AreEqual((byte)0, x);
        Assert.AreEqual((byte)0, y);
    }

    [TestMethod]
    public void FindFirstFree_AfterTwoByTwoAtOrigin_NextOneByOneIsAt2_0()
    {
        var occupied = OccupiedFromFootprint(0, 0, 2, 2);

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied,
            sizeX: 1, sizeY: 1, out var x, out var y));
        Assert.AreEqual((byte)2, x);
        Assert.AreEqual((byte)0, y);
    }

    [TestMethod]
    public void FindFirstFree_AfterTwoByTwoAtOrigin_NextTwoByTwoIsAt2_0()
    {
        var occupied = OccupiedFromFootprint(0, 0, 2, 2);

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied,
            sizeX: 2, sizeY: 2, out var x, out var y));
        Assert.AreEqual((byte)2, x);
        Assert.AreEqual((byte)0, y);
    }

    [TestMethod]
    public void FindFirstFree_PacksTwoByTwoAcrossFirstRowThenSecond()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        // (0,0), (2,0), (4,0) then (0,2)
        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 2, 2, out var x0, out var y0));
        Occupy(occupied, x0, y0, 2, 2);
        Assert.AreEqual((0, 0), (x0, y0));

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 2, 2, out var x1, out var y1));
        Occupy(occupied, x1, y1, 2, 2);
        Assert.AreEqual((2, 0), (x1, y1));

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 2, 2, out var x2, out var y2));
        Occupy(occupied, x2, y2, 2, 2);
        Assert.AreEqual((4, 0), (x2, y2));

        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 2, 2, out var x3, out var y3));
        Assert.AreEqual((0, 2), (x3, y3));
    }

    [TestMethod]
    public void FindFirstFree_InvalidSize_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();

        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, sizeX: 0, sizeY: 1, out _, out _));
    }

    [TestMethod]
    public void LinearIndex_MatchesServerRowMajor()
    {
        Assert.AreEqual(0, InventoryGridPlacement.ToLinearIndex(0, 0, Width));
        Assert.AreEqual(1, InventoryGridPlacement.ToLinearIndex(1, 0, Width));
        Assert.AreEqual(6, InventoryGridPlacement.ToLinearIndex(0, 1, Width));
        Assert.AreEqual(7, InventoryGridPlacement.ToLinearIndex(1, 1, Width));
    }

    [TestMethod]
    public void EnumerateCells_ZeroSize_YieldsNothing()
    {
        Assert.AreEqual(0, InventoryGridPlacement.EnumerateCells(0, 0, 0, 1).Count());
        Assert.AreEqual(0, InventoryGridPlacement.EnumerateCells(0, 0, 1, 0).Count());
    }

    [TestMethod]
    public void CanPlace_NullOccupied_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() =>
            InventoryGridPlacement.CanPlace(Width, Height, PageHeight, null!, 0, 0, 1, 1));
    }

    [TestMethod]
    public void CanPlace_InvalidGridDims_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsFalse(InventoryGridPlacement.CanPlace(0, Height, PageHeight, occupied, 0, 0, 1, 1));
        Assert.IsFalse(InventoryGridPlacement.CanPlace(Width, 0, PageHeight, occupied, 0, 0, 1, 1));
        Assert.IsFalse(InventoryGridPlacement.CanPlace(Width, Height, 0, occupied, 0, 0, 1, 1));
    }

    [TestMethod]
    public void CanPlace_ZeroFootprint_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsFalse(InventoryGridPlacement.CanPlace(Width, Height, PageHeight, occupied, 0, 0, 0, 1));
        Assert.IsFalse(InventoryGridPlacement.CanPlace(Width, Height, PageHeight, occupied, 0, 0, 1, 0));
    }

    [TestMethod]
    public void TryFindFirstFree_NullOccupied_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() =>
            InventoryGridPlacement.TryFindFirstFree(Width, Height, PageHeight, null!, 1, 1, out _, out _));
    }

    [TestMethod]
    public void TryFindFirstFree_FullGrid_Fails()
    {
        var occupied = new HashSet<(byte X, byte Y)>();
        for (byte y = 0; y < Height; y++)
        for (byte x = 0; x < Width; x++)
            occupied.Add((x, y));

        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 1, 1, out _, out _));
    }

    [TestMethod]
    public void CanPlace_OriginEmptyButInteriorOccupied_Fails()
    {
        // Origin free, second cell of 2x1 blocked — CanPlace after quick-reject path.
        var occupied = new HashSet<(byte X, byte Y)> { (1, 0) };
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied, 0, 0, 2, 1));
        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 2, 1, out var x, out var y));
        Assert.AreEqual((byte)2, x);
        Assert.AreEqual((byte)0, y);
    }

    [TestMethod]
    public void TryFindFirstFree_ExactFitInOneCellGrid_UsesSubtractionBounds()
    {
        // Kills maxY = height + sizeY / maxX = width + sizeX arithmetic mutants:
        // a 1×1 grid only has origin (0,0); wrong max would search OOB or miss.
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            1, 1, 1, occupied, 1, 1, out var x, out var y));
        Assert.AreEqual((byte)0, x);
        Assert.AreEqual((byte)0, y);

        occupied.Add((0, 0));
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            1, 1, 1, occupied, 1, 1, out _, out _));
    }

    [TestMethod]
    public void EnumerateCells_RequiresBothDimsPositive_NotAnd()
    {
        // sizeX=0 sizeY=2 must yield nothing (OR, not AND).
        Assert.AreEqual(0, InventoryGridPlacement.EnumerateCells(0, 0, 0, 2).Count());
        Assert.AreEqual(0, InventoryGridPlacement.EnumerateCells(0, 0, 2, 0).Count());
        Assert.AreEqual(2, InventoryGridPlacement.EnumerateCells(0, 0, 2, 1).Count());
    }

    [TestMethod]
    public void CanPlace_HeightBoundUsesAdditionNotSubtraction()
    {
        // Kills: y + sizeY > gridHeight → y - sizeY (would accept OOB when page rule is lax).
        var occupied = new HashSet<(byte X, byte Y)>();
        const int gridH = 10;
        const int pageH = 100; // page rule never binds for y+sizeY within gridH

        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, gridH, pageH, occupied, x: 0, y: 9, sizeX: 1, sizeY: 2),
            "y=9 sizeY=2 must exceed gridHeight=10");
        Assert.IsTrue(InventoryGridPlacement.CanPlace(
            Width, gridH, pageH, occupied, x: 0, y: 8, sizeX: 1, sizeY: 2));
    }

    [TestMethod]
    public void CanPlace_WidthBoundUsesAddition()
    {
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied, x: 5, y: 0, sizeX: 2, sizeY: 1));
        Assert.IsTrue(InventoryGridPlacement.CanPlace(
            Width, Height, PageHeight, occupied, x: 4, y: 0, sizeX: 2, sizeY: 1));
    }

    [TestMethod]
    public void CanPlace_ZeroWidthGrid_FailsEvenWhenHeightPositive()
    {
        // Kills: gridWidth < 1 || gridHeight < 1 → && (zero width alone must still reject).
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            gridWidth: 0, gridHeight: Height, pageHeight: PageHeight, occupied, 0, 0, 1, 1));
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            gridWidth: Width, gridHeight: 0, pageHeight: PageHeight, occupied, 0, 0, 1, 1));
        Assert.IsFalse(InventoryGridPlacement.CanPlace(
            gridWidth: Width, gridHeight: Height, pageHeight: 0, occupied, 0, 0, 1, 1));
    }

    [TestMethod]
    public void TryFindFirstFree_ZeroSizeOrOversized_FailsIndependently()
    {
        // Kills compound OR→AND rewrites on size/grid guards.
        var occupied = new HashSet<(byte X, byte Y)>();
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, sizeX: 0, sizeY: 1, out _, out _));
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, sizeX: 1, sizeY: 0, out _, out _));
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, sizeX: 7, sizeY: 1, out _, out _)); // wider than 6
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, sizeX: 1, sizeY: 14, out _, out _)); // taller than 13
    }

    [TestMethod]
    public void TryFindFirstFree_ScanOrderIsYThenX_AndStopsAtFirstCanPlace()
    {
        // Origin (0,0) free but 2×1 only fits at (1,0) because (0,0) and (2,0) blocked for a 2-wide
        // leaves (1,0)+(2,0) — block (0,0) and force next.
        var occupied = new HashSet<(byte X, byte Y)> { (0, 0) };
        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            Width, Height, PageHeight, occupied, 1, 1, out var x, out var y));
        Assert.AreEqual((byte)1, x);
        Assert.AreEqual((byte)0, y);
    }

    [TestMethod]
    public void TryFindFirstFree_MaxScanUsesSubtractionBounds_NotAddition()
    {
        // Kills maxY = gridHeight - sizeY → gridHeight + sizeY (would loop far / timeout).
        // 3×3 grid, 2×2 item: only origins (0,0),(1,0),(0,1),(1,1). Fill all but (1,1).
        var occupied = new HashSet<(byte X, byte Y)>
        {
            (0, 0), (1, 0), (2, 0),
            (0, 1), (1, 1),
            (0, 2), (1, 2), (2, 2),
        };
        // Leave (2,1) free — 2×2 cannot fit; expect false without scanning OOB forever.
        Assert.IsFalse(InventoryGridPlacement.TryFindFirstFree(
            3, 3, 3, occupied, 2, 2, out _, out _));

        occupied.Remove((1, 1));
        occupied.Remove((2, 1));
        occupied.Remove((1, 2));
        occupied.Remove((2, 2));
        Assert.IsTrue(InventoryGridPlacement.TryFindFirstFree(
            3, 3, 3, occupied, 2, 2, out var x, out var y));
        Assert.AreEqual((byte)1, x);
        Assert.AreEqual((byte)1, y);
    }

    private static HashSet<(byte X, byte Y)> OccupiedFromFootprint(byte ox, byte oy, byte w, byte h)
    {
        var set = new HashSet<(byte X, byte Y)>();
        Occupy(set, ox, oy, w, h);
        return set;
    }

    private static void Occupy(HashSet<(byte X, byte Y)> occupied, byte ox, byte oy, byte w, byte h)
    {
        foreach (var cell in InventoryGridPlacement.EnumerateCells(ox, oy, w, h))
            occupied.Add((cell.X, cell.Y));
    }
}
