using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

using AutoCore.Database.World.Models;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;

/// <summary>
/// Instance identity scaffolding for per-player map instancing (continents 698/707/708).
/// Every <see cref="SectorMap"/> carries a process-unique <c>InstanceSerial</c> so singleton
/// state (trigger latches, presence ledgers, combat cooldowns) can be keyed per map copy, and
/// <see cref="InstancedContinents"/> gates which continents are instanced — off by default so
/// the Global process can never allocate per-player instances.
/// </summary>
[TestClass]
public class InstanceIdentityTests
{
    private static SectorMap CreateTestMap(int continentId) =>
        SectorMap.CreateForTests(
            new ContinentObject
            {
                Id = continentId,
                MapFileName = $"tm_instance_identity_{continentId}",
                DisplayName = "test",
                IsTown = false,
                IsPersistent = true,
            },
            new Vector4(0, 0, 0, 0));

    [TestCleanup]
    public void Cleanup() => InstancedContinents.SetForTests(null);

    [TestMethod]
    public void InstanceSerial_IsUniquePerConstruction()
    {
        var a = CreateTestMap(9911);
        var b = CreateTestMap(9911);

        Assert.AreNotEqual(a.InstanceSerial, b.InstanceSerial,
            "Two maps of the same continent must have distinct instance serials.");
    }

    [TestMethod]
    public void NewMap_IsNotAnInstanceByDefault()
    {
        var map = CreateTestMap(9912);

        Assert.IsFalse(map.IsInstance);
        Assert.AreEqual(0, map.InstanceOwnerCoid);
    }

    [TestMethod]
    public void IsInstanced_DefaultOff_GlobalSafety()
    {
        // ActiveSet is null unless EnableForSector()/SetForTests ran — the Global process
        // never enables instancing, so 707 must not be instanced by default.
        Assert.IsFalse(InstancedContinents.IsInstanced(707));
        Assert.IsFalse(InstancedContinents.IsInstanced(698));
        Assert.IsFalse(InstancedContinents.IsInstanced(708));
    }

    [TestMethod]
    public void IsInstanced_AfterEnable_CoversExactlyTheThreeStartingAreas()
    {
        InstancedContinents.SetForTests(new HashSet<int> { 698, 707, 708 });

        Assert.IsTrue(InstancedContinents.IsInstanced(698));
        Assert.IsTrue(InstancedContinents.IsInstanced(707));
        Assert.IsTrue(InstancedContinents.IsInstanced(708));
        Assert.IsFalse(InstancedContinents.IsInstanced(42), "Non-listed continents stay shared.");
    }

    [TestMethod]
    public void EnableForSector_ActivatesTheDefaultSet()
    {
        InstancedContinents.EnableForSector();

        Assert.IsTrue(InstancedContinents.IsInstanced(707));
        Assert.IsFalse(InstancedContinents.IsInstanced(1));
    }
}
