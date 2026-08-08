using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

using AutoCore.Game.Map;

/// <summary>
/// The suppress/materialize ledger must be scoped to a map INSTANCE, not a continent id: two
/// instances of the same continent mint identical live-spawn COIDs, so a ledger carried between
/// them would hide/show the wrong objects. Same instance re-binds keep the ledger (early-return).
/// </summary>
[TestClass]
public class CharacterMapPresenceInstanceTests
{
    private const int ContId = 707;

    [TestMethod]
    public void EnsureContinent_SameContinentDifferentInstance_ClearsLedgers()
    {
        var presence = new CharacterMapPresence();
        presence.EnsureContinent(ContId, instanceSerial: 11);
        presence.Suppress(1001);
        presence.Materialize(1002);
        presence.TrackOwnedCombat(1003);
        presence.MarkDeliverTurnInReady(555);
        presence.MarkStalePatrolResync(777);
        presence.NoteAutoPatrolHandled(888, "fp");

        presence.EnsureContinent(ContId, instanceSerial: 12);

        Assert.IsFalse(presence.IsSuppressed(1001),
            "A fresh instance of the same continent must start with a clean ledger.");
        Assert.IsFalse(presence.IsMaterialized(1002));
        Assert.IsFalse(presence.OwnsCombat(1003));
        Assert.IsFalse(presence.IsDeliverTurnInReady(555));
        Assert.IsFalse(presence.HasStalePatrolResync(777));
        Assert.IsFalse(presence.ShouldSkipRedundantAutoPatrol(888, "fp"));
    }

    [TestMethod]
    public void EnsureContinent_SameContinentSameInstance_KeepsLedgers()
    {
        var presence = new CharacterMapPresence();
        presence.EnsureContinent(ContId, instanceSerial: 21);
        presence.Suppress(1001);
        presence.MarkDeliverTurnInReady(555);

        presence.EnsureContinent(ContId, instanceSerial: 21);

        Assert.IsTrue(presence.IsSuppressed(1001), "Re-binding the same instance must keep state.");
        Assert.IsTrue(presence.IsDeliverTurnInReady(555));
    }

    [TestMethod]
    public void Clear_ResetsInstanceBinding()
    {
        var presence = new CharacterMapPresence();
        presence.EnsureContinent(ContId, instanceSerial: 31);
        presence.Suppress(1001);

        presence.Clear();

        Assert.AreEqual(-1, presence.ContinentId);
        Assert.AreEqual(-1, presence.InstanceSerial);
        Assert.IsFalse(presence.IsSuppressed(1001));
    }
}
