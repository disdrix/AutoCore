using AutoCore.Game.Entities;
using AutoCore.Game.Inventory;
using AutoCore.Game.Managers;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Utils.Logging;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

/// <summary>
/// SS-27 tripwire: kill-loot credits must be routed through the character's bound inventory
/// persistence. The historical bug called <c>CurrencySync.AddCredits(persistence: null, ...)</c>,
/// which granted credits in memory only — they vanished on server restart.
/// </summary>
[TestClass]
public class LootManagerKillLootPersistenceTests
{
    private InMemoryLogSink _sink = null!;

    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    private static (Character Killer, RecordingInventoryPersistence Persistence) CreateKiller(long coid)
    {
        var persistence = new RecordingInventoryPersistence();
        var inventory = new InventoryManager(persistence);
        var killer = new Character();
        killer.SetCoid(coid, true);
        killer.AttachTestDataForTests($"Killer{coid}");
        killer.AttachInventoryForTests(inventory);
        return (killer, persistence);
    }

    /// <summary>
    /// SS-27 tripwire: reverting the fix (persistence: null) makes this fail because the
    /// credit balance never reaches the character's inventory persistence.
    /// </summary>
    [TestMethod]
    public void TryGiveCredits_PersistsBalanceThroughBoundInventoryPersistence()
    {
        var (killer, persistence) = CreateKiller(coid: 4711);
        killer.SetCredits(100);

        LootManager.TryGiveCredits(killer, 250);

        Assert.AreEqual(350L, killer.Credits, "kill-loot credits must apply in memory");
        Assert.AreEqual(1, persistence.CreditsSaves.Count,
            "SS-27: kill-loot credit grant must reach inventory persistence or it vanishes on restart");
        Assert.AreEqual((4711L, 350L), persistence.CreditsSaves[0],
            "persisted balance must be the post-grant absolute value");
    }

    [TestMethod]
    public void TryGiveCredits_AuditsKillLootReason()
    {
        var (killer, _) = CreateKiller(coid: 4712);

        LootManager.TryGiveCredits(killer, 40);

        var record = _sink.Single("CurrencyChanged");
        Assert.AreEqual(CurrencyChangeReason.KillLoot, record.GetProperty("Reason"),
            "kill-loot money must be attributable in the audit trail");
        Assert.AreEqual(40L, record.GetProperty("Delta"));
    }

    [TestMethod]
    public void TryGiveCredits_NoInventory_DoesNotThrow()
    {
        var killer = new Character();
        killer.SetCoid(4713, true);
        killer.AttachTestDataForTests("Killer4713");

        LootManager.TryGiveCredits(killer, 10);

        Assert.AreEqual(10L, killer.Credits, "grant still applies in memory when no inventory is bound");
    }
}
