using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Game.Constants;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;

/// <summary>
/// SS-33 tripwires for the 0x2023 DamagePacket throttle. The throttle exists to stop floater
/// floods (multi-slot + splash), but keyed per attacker only it also ate the visible feedback
/// for every OTHER target hit within the window — "my shots do nothing" while HP was applied.
/// </summary>
[TestClass]
public class DamagePacketThrottleTests
{
    private readonly List<BasePacket> _sent = new();
    private TNLConnection _conn;
    private Character _attacker;

    [TestInitialize]
    public void SetUp()
    {
        _sent.Clear();
        TNLConnection.TestPacketSink = (_, p) => _sent.Add(p);
        Vehicle.ClearCombatThrottleForTests();
        ServerConfig.ResetToDefaults();

        _conn = new TNLConnection();
        _conn.SetGhostFrom(true);
        _conn.SetGhostTo(false);
        _attacker = new Character();
        _attacker.SetCoid(96100, true);
        _attacker.SetOwningConnection(_conn);
        _conn.CurrentCharacter = _attacker;
    }

    [TestCleanup]
    public void TearDown()
    {
        TNLConnection.TestPacketSink = null;
        Vehicle.ClearCombatThrottleForTests();
        ServerConfig.ResetToDefaults();
    }

    private static GraphicsObject Victim(long coid)
    {
        var v = new GraphicsObject(GraphicsObjectType.Graphics);
        v.InitializeHealthForTests(10);
        v.SetCoid(coid, false);
        return v;
    }

    private void Send(long attackerVehicleCoid, params GraphicsObject[] victims)
    {
        var packet = new DamagePacket { Source = new TFID(attackerVehicleCoid, true) };
        foreach (var v in victims)
            packet.AddHit(v.ObjectId, 5);
        Vehicle.TrySendDamagePacketMulti(_attacker, packet, new TFID(attackerVehicleCoid, true), victims);
    }

    [TestMethod]
    public void SameTarget_WithinWindow_SecondPacketDropped()
    {
        var victim = Victim(96200);

        Send(96101, victim);
        Send(96101, victim);

        Assert.AreEqual(1, _sent.OfType<DamagePacket>().Count(),
            "flood protection: same attacker→target pair within the window must coalesce");
    }

    [TestMethod]
    public void DifferentTargets_WithinWindow_AreNotSuppressed()
    {
        var first = Victim(96201);
        var second = Victim(96202);

        Send(96101, first);
        Send(96101, second);

        Assert.AreEqual(2, _sent.OfType<DamagePacket>().Count(),
            "a hit on a DIFFERENT target must not be eaten by the attacker-keyed throttle");
    }

    [TestMethod]
    public void ThrottleWindow_Configurable_ZeroDisablesThrottle()
    {
        ServerConfig.DamagePacketThrottleMs = 0;
        var victim = Victim(96203);

        Send(96101, victim);
        Send(96101, victim);

        Assert.AreEqual(2, _sent.OfType<DamagePacket>().Count(),
            "window 0 must disable the throttle entirely");
    }

    [TestMethod]
    public void MultiHitPacket_WithOneFreshTarget_IsSent()
    {
        var first = Victim(96204);
        var second = Victim(96205);

        Send(96101, first);
        Send(96101, first, second); // first is throttled, second is fresh — packet must still ship

        Assert.AreEqual(2, _sent.OfType<DamagePacket>().Count(),
            "a multi-hit packet containing any un-throttled target must be sent");
    }
}
