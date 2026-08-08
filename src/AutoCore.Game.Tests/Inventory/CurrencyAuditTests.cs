using AutoCore.Game.Entities;
using AutoCore.Game.Inventory;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Utils.Logging;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Inventory;

/// <summary>
/// Phase 3 currency audit trail: every money mutation through <see cref="CurrencySync"/>
/// must emit a <c>CurrencyChanged</c> audit record whose arithmetic is self-consistent
/// (Before + Delta == After) and whose Reason names the economy path.
/// </summary>
[TestClass]
public class CurrencyAuditTests
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

    private static Character CreateCharacter(long coid, long credits, InventoryManager inventory = null)
    {
        var character = new Character();
        character.SetCoid(coid, true);
        character.AttachTestDataForTests($"Audit{coid}");
        character.SetCredits(credits);
        if (inventory != null)
            character.AttachInventoryForTests(inventory);
        return character;
    }

    [TestMethod]
    public void AddCredits_EmitsCurrencyChangedAudit_WithConsistentArithmetic()
    {
        var persistence = new RecordingInventoryPersistence();
        var character = CreateCharacter(coid: 42, credits: 100);

        CurrencySync.AddCredits(persistence, character, 50, CurrencyChangeReason.KillLoot);

        var record = _sink.Single("CurrencyChanged");
        Assert.IsTrue(record.Audit, "CurrencyChanged must be an audit record (bypasses level filter)");
        Assert.AreEqual(42L, record.GetProperty("CharacterId"), "audit must carry the character coid");
        Assert.AreEqual(100L, record.GetProperty("Before"), "Before must be the pre-mutation balance");
        Assert.AreEqual(50L, record.GetProperty("Delta"), "Delta must be the applied delta");
        Assert.AreEqual(150L, record.GetProperty("After"), "After must be the post-mutation balance");
        Assert.AreEqual(
            (long)record.GetProperty("Before") + (long)record.GetProperty("Delta"),
            (long)record.GetProperty("After"),
            "audit arithmetic invariant Before + Delta == After");
        Assert.AreEqual(CurrencyChangeReason.KillLoot, record.GetProperty("Reason"));
    }

    [TestMethod]
    public void AddCredits_NegativeFloored_AuditDeltaMatchesAppliedNotRequested()
    {
        var persistence = new RecordingInventoryPersistence();
        var character = CreateCharacter(coid: 7, credits: 30);

        CurrencySync.AddCredits(persistence, character, -100, CurrencyChangeReason.VendorBuy);

        var record = _sink.Single("CurrencyChanged");
        Assert.AreEqual(30L, record.GetProperty("Before"));
        Assert.AreEqual(-30L, record.GetProperty("Delta"), "floored debit must audit the applied delta, not the request");
        Assert.AreEqual(0L, record.GetProperty("After"));
    }

    [TestMethod]
    public void SetCreditsAbsolute_EmitsCurrencyChangedAudit()
    {
        var persistence = new RecordingInventoryPersistence();
        var character = CreateCharacter(coid: 9, credits: 25);

        CurrencySync.SetCreditsAbsolute(persistence, character, 1000, CurrencyChangeReason.AdminCommand);

        var record = _sink.Single("CurrencyChanged");
        Assert.IsTrue(record.Audit, "absolute set is an audit event too");
        Assert.AreEqual(25L, record.GetProperty("Before"));
        Assert.AreEqual(975L, record.GetProperty("Delta"), "absolute set audits the effective delta");
        Assert.AreEqual(1000L, record.GetProperty("After"));
        Assert.AreEqual(CurrencyChangeReason.AdminCommand, record.GetProperty("Reason"));
    }

    [TestMethod]
    public void InventoryManagerForwarder_PropagatesReason()
    {
        var persistence = new RecordingInventoryPersistence();
        var inventory = new InventoryManager(persistence);
        var character = CreateCharacter(coid: 12, credits: 0, inventory);

        inventory.AddCredits(character, 77, CurrencyChangeReason.MissionReward);

        var record = _sink.Single("CurrencyChanged");
        Assert.AreEqual(CurrencyChangeReason.MissionReward, record.GetProperty("Reason"));
        Assert.AreEqual(77L, record.GetProperty("Delta"));
    }

    [TestMethod]
    public void CreditsChatCommand_AuditsAsAdminCommand()
    {
        var persistence = new RecordingInventoryPersistence();
        var character = CreateCharacter(coid: 15, credits: 5);

        var result = CurrencySync.TryApplyCreditsCommand(
            character,
            new[] { "/credits", "0", "0", "0", "123" },
            persistence);

        Assert.IsTrue(result.Success, "denomination set must succeed");
        var record = _sink.Single("CurrencyChanged");
        Assert.AreEqual(CurrencyChangeReason.AdminCommand, record.GetProperty("Reason"));
    }

    [TestMethod]
    public void AddCredits_ZeroAppliedDelta_StillAuditsMutationAttempt()
    {
        var persistence = new RecordingInventoryPersistence();
        var character = CreateCharacter(coid: 3, credits: 10);

        CurrencySync.AddCredits(persistence, character, 0, CurrencyChangeReason.Unknown);

        var record = _sink.Single("CurrencyChanged");
        Assert.AreEqual(0L, record.GetProperty("Delta"));
        Assert.AreEqual(10L, record.GetProperty("After"));
    }
}
