using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.NpcAi;

using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Map;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;

/// <summary>
/// NpcTicker hands vehicle movement to AutoCore.Sim through the NpcVehicleSimControl hook
/// seam (Game cannot reference Sim). A claimed vehicle is not moved by the legacy movers;
/// creatures always stay on the legacy foot movers.
/// </summary>
[TestClass]
public class NpcTickerSimGateTests
{
    private const int ContId = 951;
    private const long PathCoid = 95110;
    private const int ChassisCbid = 813_001;
    private const int WheelsetCbid = 813_002;

    [TestInitialize]
    public void SetUp()
    {
        NpcVehicleSimControl.TrySimDrive = null;
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        AssetManagerTestHelper.RegisterCloneBase(WheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterVehicleCloneBase(ChassisCbid, defaultWheelsetCbid: WheelsetCbid);
    }

    [TestCleanup]
    public void TearDown()
    {
        NpcVehicleSimControl.TrySimDrive = null;
        AssetManagerTestHelper.ClearRegisteredCloneBases();
    }

    private static SectorMap CreateFieldMap()
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = ContId,
            MapFileName = $"tm_sim_gate_{ContId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static Vehicle PlacePathNpcVehicle(SectorMap map, Vector3 position)
    {
        var path = new MapPathTemplate { COID = (int)PathCoid };
        path.Points.Add(new MapPathTemplate.MapPathPoint
        { Position = position, AcceptDistance = 1f });
        path.Points.Add(new MapPathTemplate.MapPathPoint
        { Position = new Vector3(position.X + 100f, position.Y, position.Z), AcceptDistance = 1f });
        map.MapData.Templates[PathCoid] = path;

        var vehicle = new Vehicle();
        vehicle.SetCoid(map.LocalCoidCounter++, false);
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();
        vehicle.Position = position;
        vehicle.CoidCurrentPath = PathCoid;
        vehicle.NpcAi = new NpcAiState { HomePosition = position };
        vehicle.SetMap(map);
        return vehicle;
    }

    [TestMethod]
    public void SimHookClaimsVehicle_LegacyMoversLeaveItAlone()
    {
        var map = CreateFieldMap();
        var vehicle = PlacePathNpcVehicle(map, new Vector3(0f, 0f, 0f));
        Vehicle claimed = null;
        NpcVehicleSimControl.TrySimDrive = v => { claimed = v; return true; };

        for (var i = 0; i < 10; i++)
            NpcTicker.Tick(map, nowMs: 100_000 + i * 50, dt: 0.05f);

        Assert.AreSame(vehicle, claimed, "the hook must be consulted for pathed NPC vehicles");
        Assert.AreEqual(0f, vehicle.Position.X, 1e-3f,
            "a sim-claimed vehicle must not be moved by the legacy path movers");
    }

    [TestMethod]
    public void HookDeclines_LegacyMoverStillDrivesThePath()
    {
        var map = CreateFieldMap();
        var vehicle = PlacePathNpcVehicle(map, new Vector3(0f, 0f, 0f));
        NpcVehicleSimControl.TrySimDrive = _ => false;

        for (var i = 0; i < 40; i++)
            NpcTicker.Tick(map, nowMs: 100_000 + i * 50, dt: 0.05f);

        Assert.IsTrue(vehicle.Position.X > 1f,
            "when the sim declines (setting off / no path) the legacy mover keeps working");
    }
}
