using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Entities;

using AutoCore.Game.Constants;
using AutoCore.Game.Entities;

/// <summary>
/// SS-34 tripwires: <c>SimpleObject.DirtyHealthMasks</c> was <c>Ghost?.SetMaskBits</c> — for a
/// creature whose ghost was not created/scoped yet, the health dirty bit was silently discarded
/// and the client never saw the HP change. The mask must latch and flush on ghost creation.
/// </summary>
[TestClass]
public class DirtyHealthMaskDeliveryTests
{
    [TestMethod]
    public void TakeDamage_BeforeGhostExists_LatchesHealthMasks()
    {
        var obj = new SimpleObject(GraphicsObjectType.Graphics);
        obj.InitializeHealthForTests(10);

        obj.TakeDamage(3);

        Assert.AreEqual(3, 10 - obj.GetCurrentHP());
        Assert.AreNotEqual(0UL, obj.PendingGhostMasksForTests,
            "with no ghost, health dirty bits must latch instead of being discarded");
    }

    [TestMethod]
    public void CreateGhost_FlushesLatchedMasks()
    {
        var obj = new SimpleObject(GraphicsObjectType.Graphics);
        obj.InitializeHealthForTests(10);
        obj.TakeDamage(3);

        obj.CreateGhost();

        Assert.AreEqual(0UL, obj.PendingGhostMasksForTests,
            "latched masks must be delivered to the ghost on creation");
    }

    [TestMethod]
    public void CreatureCreateGhost_FlushesLatchedMasks()
    {
        var creature = new Creature();
        creature.InitializeHealthForTests(10);
        creature.TakeDamage(4);

        creature.CreateGhost();

        Assert.AreEqual(0UL, creature.PendingGhostMasksForTests);
    }

    [TestMethod]
    public void TakeDamage_NegativeAmount_DoesNotHeal()
    {
        var obj = new SimpleObject(GraphicsObjectType.Graphics);
        obj.InitializeHealthForTests(10);

        var dealt = obj.TakeDamage(-5);

        Assert.AreEqual(0, dealt);
        Assert.AreEqual(10, obj.GetCurrentHP(),
            "negative damage must not heal (GraphicsObject/Vehicle already guard this)");
    }
}
