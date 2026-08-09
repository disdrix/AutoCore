using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Game.Entities;

/// <summary>
/// Hit-chance rolls used <c>new Random(nowMs ^ Coid)</c> per fire cycle — every slot in the same
/// tick rolled the identical first value (correlated misses), and same-millisecond cycles
/// repeated whole sequences. Each vehicle must keep one persistent RNG.
/// </summary>
[TestClass]
public class CombatRngTests
{
    [TestMethod]
    public void CombatRng_IsPersistentPerVehicle()
    {
        var vehicle = new Vehicle();
        Assert.AreSame(vehicle.CombatRng, vehicle.CombatRng,
            "the combat RNG must persist across fire cycles, not be re-seeded per cycle");
    }

    [TestMethod]
    public void CombatRng_SequencesDifferAcrossVehiclesCreatedTogether()
    {
        var a = new Vehicle();
        var b = new Vehicle();

        var seqA = new[] { a.CombatRng.NextDouble(), a.CombatRng.NextDouble(), a.CombatRng.NextDouble() };
        var seqB = new[] { b.CombatRng.NextDouble(), b.CombatRng.NextDouble(), b.CombatRng.NextDouble() };

        CollectionAssert.AreNotEqual(seqA, seqB,
            "vehicles created in the same tick must not share a roll sequence");
    }
}
