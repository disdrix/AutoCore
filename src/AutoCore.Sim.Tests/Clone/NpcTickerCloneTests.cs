using System.Linq;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Map;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Sim.Clone;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Clone;

/// <summary>
/// Tripwire: clones live in Map.NpcAiEntities (for lifecycle visibility) but must be driven
/// ONLY by SimHost — if NpcTicker ever starts moving pathless NPC vehicles, clones would be
/// double-driven and fight the sim.
/// </summary>
[TestClass]
public class NpcTickerCloneTests
{
    private const int ChassisCbid = 830_001;
    private const int WheelsetCbid = 830_002;

    [TestInitialize]
    public void Init()
    {
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        AssetManagerTestHelper.RegisterCloneBase(WheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterVehicleCloneBase(ChassisCbid, defaultWheelsetCbid: WheelsetCbid);
    }

    [TestCleanup]
    public void Cleanup()
    {
        AssetManagerTestHelper.ClearRegisteredCloneBases();
    }

    [TestMethod]
    public void NpcTicker_DoesNotMoveCloneEntities()
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = 8401,
            MapFileName = "tm_clone_ticker",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));

        var vehicle = new Vehicle();
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();
        var character = new Character();
        character.GMLevel = 1;
        character.SetCoid(9301, true);
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(map);
        vehicle.Position = new Vector3(50f, 0f, 50f);

        var clone = CloneSpawner.Spawn(character);
        var before = clone.Position;

        NpcTicker.Tick(map, nowMs: 1000, dt: 0.05f);

        Assert.AreEqual(before.X, clone.Position.X, 0.001f);
        Assert.AreEqual(before.Z, clone.Position.Z, 0.001f);
    }
}
