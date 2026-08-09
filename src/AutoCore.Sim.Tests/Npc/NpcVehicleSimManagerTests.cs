using System.Linq;
using AutoCore.Game.Constants;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Map;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Sim.Npc;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Npc;

/// <summary>
/// AutoCore.Sim as the server's NPC vehicle mover (serverConfig.yaml sim.npcVehicles,
/// default ON): adopted path vehicles drive with RaycastCar physics + avoidance instead of
/// the legacy kinematic movers. Creatures (bipeds/animals) are never adopted.
/// </summary>
[TestClass]
public class NpcVehicleSimManagerTests
{
    private const int ChassisCbid = 812_001;
    private const int WheelsetCbid = 812_002;
    private const int DriverCbid = 812_003;
    private const long PathCoid = 812_100;

    [TestInitialize]
    public void Init()
    {
        ServerConfig.ResetToDefaults();
        AssetManagerTestHelper.ClearRegisteredCloneBases();
        AssetManagerTestHelper.RegisterCloneBase(WheelsetCbid, CloneBaseObjectType.WheelSet);
        AssetManagerTestHelper.RegisterVehicleCloneBase(
            ChassisCbid,
            defaultDriverCbid: DriverCbid,
            defaultWheelsetCbid: WheelsetCbid);
        AssetManagerTestHelper.RegisterCreatureCloneBase(DriverCbid, baseLevel: 5);
    }

    [TestCleanup]
    public void Cleanup()
    {
        ServerConfig.ResetToDefaults();
        AssetManagerTestHelper.ClearRegisteredCloneBases();
    }

    private static SectorMap CreateFieldMap(int continentId)
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_npcsim_{continentId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static MapPathTemplate SeedPath(SectorMap map, long coid, int waitTimeMs, params Vector3[] points)
    {
        var path = new MapPathTemplate { COID = (int)coid, PathName = "patrol" };
        foreach (var p in points)
        {
            path.Points.Add(new MapPathTemplate.MapPathPoint
            {
                Position = p,
                AcceptDistance = 6f,
                WaitTime = waitTimeMs,
            });
        }

        map.MapData.Templates[coid] = path;
        return path;
    }

    private static Vehicle PlacePathNpcVehicle(SectorMap map, Vector3 position, long pathCoid)
    {
        var vehicle = new Vehicle();
        vehicle.SetCoid(map.LocalCoidCounter++, false);
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();
        vehicle.Position = position;
        vehicle.CoidCurrentPath = pathCoid;
        vehicle.NpcAi = new NpcAiState { HomePosition = position };
        vehicle.SetMap(map);
        return vehicle;
    }

    [TestMethod]
    public void TryAdopt_PathedVehicle_DrivesItAlongThePathWithPhysics()
    {
        var map = CreateFieldMap(8501);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();

        Assert.IsTrue(manager.TryAdopt(vehicle), "pathed NPC vehicle must be adopted");
        Assert.AreEqual(1, manager.ActiveVehicleCount);

        for (var i = 0; i < 400; i++)
            manager.Tick(nowMs: i * 50, dt: 0.05f);

        Assert.IsTrue(vehicle.Position.X > 130f,
            $"vehicle must make physics-driven progress along its path (X={vehicle.Position.X:F1})");
        var speed = MathF.Sqrt(
            vehicle.Velocity.X * vehicle.Velocity.X + vehicle.Velocity.Z * vehicle.Velocity.Z);
        Assert.IsTrue(speed > 1f, "published velocity must reflect the sim, not a snap");
    }

    [TestMethod]
    public void TryAdopt_SettingDisabled_ReturnsFalse()
    {
        ServerConfig.SimNpcVehiclesEnabled = false;
        var map = CreateFieldMap(8502);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();

        Assert.IsFalse(manager.TryAdopt(vehicle), "sim.npcVehicles=false must leave legacy movers in charge");
        Assert.AreEqual(0, manager.ActiveVehicleCount);
    }

    [TestMethod]
    public void TryAdopt_PathlessVehicle_ReturnsFalse()
    {
        var map = CreateFieldMap(8503);
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), pathCoid: -1);
        var manager = new NpcVehicleSimManager();

        Assert.IsFalse(manager.TryAdopt(vehicle));
    }

    /// <summary>
    /// Legacy NpcPathFollower.Advance semantics: ReverseDirection=false paths ALWAYS wrap
    /// (after the last waypoint the NPC heads back to waypoint 0), regardless of endpoint
    /// distance; only ReverseDirection=true ping-pongs. Live 2026-08-09: guessing loop from
    /// endpoint proximity made open paths ping-pong, so patrol direction looked random.
    /// </summary>
    [TestMethod]
    public void PathLoopSemantics_FollowTheAuthoredReverseDirectionFlag()
    {
        var map = CreateFieldMap(8510);
        var wrap = SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f)); // open ends, no flag
        var pingPong = SeedPath(map, PathCoid + 1, waitTimeMs: 0,
            new Vector3(100f, 0f, 300f), new Vector3(300f, 0f, 300f));
        pingPong.ReverseDirection = true;

        var wrapVehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var pingPongVehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 300f), PathCoid + 1);
        var manager = new NpcVehicleSimManager();
        manager.TryAdopt(wrapVehicle);
        manager.TryAdopt(pingPongVehicle);

        Assert.IsTrue(manager.BrainForTests(wrapVehicle).PathLoops,
            "ReverseDirection=false must wrap (loop) like legacy Advance, even with open ends");
        Assert.IsFalse(manager.BrainForTests(pingPongVehicle).PathLoops,
            "ReverseDirection=true is the authored ping-pong flag");
    }

    [TestMethod]
    public void WaypointWait_HoldsThenResumes()
    {
        var map = CreateFieldMap(8504);
        // Middle waypoint carries the authored wait; the ends have none.
        var path = SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(160f, 0f, 100f), new Vector3(260f, 0f, 100f));
        path.Points[1].WaitTime = 4_000;
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();
        manager.TryAdopt(vehicle);

        // Drive until the middle waypoint is passed and the wait engages.
        long nowMs = 0;
        var held = false;
        for (var i = 0; i < 1200 && !held; i++)
        {
            nowMs += 50;
            manager.Tick(nowMs, dt: 0.05f);
            held = manager.BrainForTests(vehicle).Hold;
        }

        Assert.IsTrue(held, "passing the authored wait waypoint must hold the vehicle");
        var heldX = vehicle.Position.X;
        Assert.IsTrue(heldX > 130f && heldX < 220f, $"hold engages near the middle waypoint (X={heldX:F1})");

        // The wait expires 4 s later and the vehicle drives on.
        for (var i = 0; i < 400; i++)
        {
            nowMs += 50;
            manager.Tick(nowMs, dt: 0.05f);
        }

        Assert.IsFalse(manager.BrainForTests(vehicle).Hold, "wait must expire");
        Assert.IsTrue(vehicle.Position.X > heldX + 20f, "vehicle must resume down the path after the wait");
    }

    [TestMethod]
    public void WaypointReaction_FiresOncePerPass()
    {
        var map = CreateFieldMap(8505);
        var path = SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(160f, 0f, 100f), new Vector3(260f, 0f, 100f));
        path.Points[1].ReactionCoid = 777_001;
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();
        var fired = new System.Collections.Generic.List<long>();
        manager.FireReactionOverride = (v, coid) => fired.Add(coid);
        manager.TryAdopt(vehicle);

        for (var i = 0; i < 900 && fired.Count == 0; i++)
            manager.Tick(nowMs: i * 50, dt: 0.05f);

        Assert.AreEqual(1, fired.Count, "authored waypoint reaction must fire when the vehicle passes it");
        Assert.AreEqual(777_001, fired[0]);
    }

    [TestMethod]
    public void CombatOwnedTicks_PauseSimDriving()
    {
        var map = CreateFieldMap(8506);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();
        manager.TryAdopt(vehicle);

        vehicle.NpcAi.PursuingThisTick = true;
        var before = vehicle.Position;
        for (var i = 0; i < 40; i++)
            manager.Tick(nowMs: i * 50, dt: 0.05f);

        Assert.AreEqual(before.X, vehicle.Position.X, 0.001f,
            "combat-owned ticks (pursuit/flee/return-home) must not be double-driven by the sim");

        // Combat releases the vehicle: the sim reseats at the live pose and resumes the path.
        vehicle.NpcAi.PursuingThisTick = false;
        for (var i = 40; i < 440; i++)
            manager.Tick(nowMs: i * 50, dt: 0.05f);

        Assert.IsTrue(vehicle.Position.X > 120f, "sim must resume path driving after combat releases");
    }

    [TestMethod]
    public void VehicleRemovedFromMap_DropsHandle()
    {
        var map = CreateFieldMap(8507);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();
        manager.TryAdopt(vehicle);

        vehicle.SetMap(null);
        manager.Tick(nowMs: 50, dt: 0.05f);

        Assert.AreEqual(0, manager.ActiveVehicleCount, "handles must not outlive the vehicle's map");
    }

    [TestMethod]
    public void DebugLogGate_Off_LeavesBrainDebugLogUnwired()
    {
        var map = CreateFieldMap(8508);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();

        ServerConfig.SimDebugLogs = false;
        manager.TryAdopt(vehicle);
        Assert.IsNull(manager.BrainForTests(vehicle).DebugLog,
            "sim.debugLogs=false (default) must not wire per-vehicle debug logging");
    }

    [TestMethod]
    public void DebugLogGate_On_WiresBrainDebugLog()
    {
        var map = CreateFieldMap(8509);
        SeedPath(map, PathCoid, waitTimeMs: 0,
            new Vector3(100f, 0f, 100f), new Vector3(300f, 0f, 100f));
        var vehicle = PlacePathNpcVehicle(map, new Vector3(100f, 0f, 100f), PathCoid);
        var manager = new NpcVehicleSimManager();

        ServerConfig.SimDebugLogs = true;
        manager.TryAdopt(vehicle);
        Assert.IsNotNull(manager.BrainForTests(vehicle).DebugLog);
    }
}
