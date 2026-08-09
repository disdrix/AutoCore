using System.Linq;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Inventory.Fakes;
using AutoCore.Sim.Clone;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Clone;

[TestClass]
public class CloneManagerTests
{
    private const int ChassisCbid = 810_001;
    private const int WheelsetCbid = 810_002;
    private const int DriverCbid = 810_003;

    [TestInitialize]
    public void Init()
    {
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
        AssetManagerTestHelper.ClearRegisteredCloneBases();
    }

    private static SectorMap CreateFieldMap(int continentId)
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_clone_{continentId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static Character DrivingCharacter(SectorMap map, long coid = 9001)
    {
        var vehicle = new Vehicle();
        vehicle.LoadCloneBase(ChassisCbid);
        vehicle.SetupCBFields();

        var character = new Character();
        character.GMLevel = 1;
        character.SetCoid(coid, true);
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(map);
        return character;
    }

    [TestMethod]
    public void Toggle_NullCharacter_ReturnsNoCharacterMessage()
    {
        var manager = new CloneManager();

        var message = manager.Toggle(null);

        StringAssert.Contains(message, "No character");
    }

    [TestMethod]
    public void Toggle_OnFootInTown_ReturnsDrivingRequiredMessage()
    {
        var continent = new AutoCore.Database.World.Models.ContinentObject
        {
            Id = 8202,
            MapFileName = "tm_clone_town",
            DisplayName = "town",
            IsTown = true,
            IsPersistent = true,
        };
        var town = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
        var character = DrivingCharacter(town);
        var manager = new CloneManager();

        var message = manager.Toggle(character);

        StringAssert.Contains(message.ToLowerInvariant(), "driving");
        Assert.AreEqual(0, manager.ActiveCloneCount);
    }

    [TestMethod]
    public void Toggle_Driving_SpawnsCloneOnMap()
    {
        var map = CreateFieldMap(8203);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        var message = manager.Toggle(character);

        Assert.AreEqual(1, manager.ActiveCloneCount, $"expected spawn, got: {message}");
        var clone = map.Objects.Values.OfType<Vehicle>().Single(v => v != character.CurrentVehicle);
        Assert.AreEqual(ChassisCbid, clone.CBID);
        Assert.IsNotNull(clone.WheelSet, "clone must carry a wheelset for the client renderer");
        Assert.IsTrue(MapNpcIdentity.IsMapNpcIdentity(clone.ObjectId),
            "clone must use the map-NPC global COID namespace");
        Assert.IsTrue(map.NpcAiEntities.Contains(clone),
            "clone must register in NpcAiEntities (NpcAi assigned before SetMap)");
        Assert.IsTrue(clone.IsInvincible, "clone must be excluded from combat damage");
    }

    [TestMethod]
    public void Toggle_SecondCall_DespawnsClone()
    {
        var map = CreateFieldMap(8204);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        manager.Toggle(character);
        var message = manager.Toggle(character);

        Assert.AreEqual(0, manager.ActiveCloneCount, $"expected despawn, got: {message}");
        Assert.AreEqual(0, map.Objects.Values.OfType<Vehicle>().Count(v => v != character.CurrentVehicle));
        Assert.AreEqual(0, map.NpcAiEntities.OfType<Vehicle>().Count());
    }

    [TestMethod]
    public void Tick_OwnerLeftMap_DespawnsClone()
    {
        var map = CreateFieldMap(8205);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();

        manager.Toggle(character);
        character.SetMap(null);
        manager.Tick(nowMs: 0, dt: 0.05f);

        Assert.AreEqual(0, manager.ActiveCloneCount);
        Assert.AreEqual(0, map.Objects.Values.OfType<Vehicle>().Count(v => v != character.CurrentVehicle));
    }

    [TestMethod]
    public void Tick_StationaryOwner_CloneOrbitsWithinAnnulus()
    {
        var map = CreateFieldMap(8207);
        var character = DrivingCharacter(map);
        var player = new AutoCore.Game.Structures.Vector3(100f, 0f, 100f);
        character.CurrentVehicle.Position = player;
        var manager = new CloneManager();
        manager.Toggle(character);
        var clone = map.NpcAiEntities.OfType<Vehicle>().Single();

        var angleCovered = 0f;
        var prevAngle = float.NaN;
        for (var i = 0; i < 900; i++) // 45 s: enter Orbit and circle
        {
            manager.Tick(nowMs: i * 50, dt: 0.05f);
            if (i < 400)
                continue;

            var dx = clone.Position.X - player.X;
            var dz = clone.Position.Z - player.Z;
            var r = MathF.Sqrt(dx * dx + dz * dz);
            Assert.IsTrue(r is > 2f and < 20f, $"clone left the orbit annulus at step {i}: r={r}");

            var angle = MathF.Atan2(dx, dz);
            if (!float.IsNaN(prevAngle))
            {
                var d = angle - prevAngle;
                if (d > MathF.PI) d -= 2f * MathF.PI;
                if (d < -MathF.PI) d += 2f * MathF.PI;
                angleCovered += MathF.Abs(d);
            }
            prevAngle = angle;
        }

        Assert.IsTrue(angleCovered > 2f * MathF.PI,
            $"clone must orbit the stationary player (covered {angleCovered} rad)");
    }

    [TestMethod]
    public void StartPath_PicksTheNearestMapPath_AndFollowResumes()
    {
        var map = CreateFieldMap(8211);
        var far = new AutoCore.Game.EntityTemplates.MapPathTemplate { COID = 901, PathName = "far" };
        far.Points.Add(new AutoCore.Game.EntityTemplates.MapPathTemplate.MapPathPoint
        { Position = new AutoCore.Game.Structures.Vector3(500f, 0f, 500f) });
        far.Points.Add(new AutoCore.Game.EntityTemplates.MapPathTemplate.MapPathPoint
        { Position = new AutoCore.Game.Structures.Vector3(600f, 0f, 500f) });
        var near = new AutoCore.Game.EntityTemplates.MapPathTemplate { COID = 902, PathName = "near" };
        near.Points.Add(new AutoCore.Game.EntityTemplates.MapPathTemplate.MapPathPoint
        { Position = new AutoCore.Game.Structures.Vector3(120f, 0f, 100f) });
        near.Points.Add(new AutoCore.Game.EntityTemplates.MapPathTemplate.MapPathPoint
        { Position = new AutoCore.Game.Structures.Vector3(160f, 0f, 100f) });
        map.MapData.Templates.Add(far.COID, far);
        map.MapData.Templates.Add(near.COID, near);

        var character = DrivingCharacter(map);
        character.CurrentVehicle.Position = new AutoCore.Game.Structures.Vector3(100f, 0f, 100f);
        var manager = new CloneManager();
        manager.Toggle(character);

        var message = manager.StartPath(character);
        StringAssert.Contains(message, "near", "must pick the closest path to the clone");
        Assert.IsTrue(manager.BrainForTests(character).HasPathRoute);

        var resume = manager.SetHold(character, hold: false);
        Assert.IsFalse(manager.BrainForTests(character).HasPathRoute,
            "/clonefollow must clear the path route and resume following");
        StringAssert.Contains(resume.ToLowerInvariant(), "follow");
    }

    /// <summary>
    /// Live 2026-08-09 11:38: the clone must RAM soft destructibles like a player vehicle —
    /// damage + destruction replicate through the normal pipeline (VehicleMapPropRam).
    /// </summary>
    [TestMethod]
    public void Tick_CloneRamsSoftDestructiblePropsInItsWay()
    {
        var previous = AutoCore.Game.Diagnostics.ServerConfig.EnableRamming;
        AutoCore.Game.Diagnostics.ServerConfig.EnableRamming = true;
        AutoCore.Game.Combat.VehicleMapPropRam.ResetCooldownsForTests();
        try
        {
            const int propCbid = 810_050;
            AssetManagerTestHelper.RegisterCloneBase(propCbid, CloneBaseObjectType.ObjectGraphicsPhysics);

            var map = CreateFieldMap(8213);
            var character = DrivingCharacter(map);
            character.CurrentVehicle.Position = new AutoCore.Game.Structures.Vector3(100f, 0f, 100f);
            var manager = new CloneManager();
            manager.Toggle(character);
            var clone = map.NpcAiEntities.OfType<Vehicle>().Single();

            // Drop a fragile prop right on the clone's orbit circle.
            var prop = new AutoCore.Game.Entities.GraphicsObject(
                AutoCore.Game.Entities.GraphicsObjectType.GraphicsPhysics);
            prop.SetCoid(770_001, false);
            prop.LoadCloneBase(propCbid);
            prop.InitializeHealthForTests(3);
            prop.Position = new AutoCore.Game.Structures.Vector3(100f, 0f, 92f);
            prop.SetMap(map);

            var startHp = prop.GetCurrentHP();
            for (var i = 0; i < 900 && prop.GetCurrentHP() >= startHp; i++)
            {
                map.Grid.RebucketSweep();
                manager.Tick(nowMs: i * 50, dt: 0.05f);
            }

            Assert.IsTrue(prop.GetCurrentHP() < startHp,
                "the clone must ram-damage soft props it passes through");
        }
        finally
        {
            AutoCore.Game.Diagnostics.ServerConfig.EnableRamming = previous;
        }
    }

    [TestMethod]
    public void StartPath_NoPathsOnMap_ReportsFriendlyMessage()
    {
        var map = CreateFieldMap(8212);
        var character = DrivingCharacter(map);
        var manager = new CloneManager();
        manager.Toggle(character);

        var message = manager.StartPath(character);

        StringAssert.Contains(message.ToLowerInvariant(), "no map paths");
    }

    [TestMethod]
    public void Tick_AttachesLazilyBuiltHullWorldToTheBrain()
    {
        var map = CreateFieldMap(8210);
        map.MapData.Templates.Add(555, new AutoCore.Game.EntityTemplates.GraphicsObjectTemplate(
            AutoCore.Game.Entities.GraphicsObjectType.GraphicsPhysics)
        {
            CBID = 777,
            COID = 555,
            Location = new AutoCore.Game.Structures.Vector4(120f, 0f, 120f, 0f),
            Rotation = new AutoCore.Game.Structures.Quaternion(0f, 0f, 0f, 1f),
            Scale = 1f,
            OriginalIsActive = true,
        });

        var boxBytes = File.ReadAllBytes(
            Path.Combine(AppContext.BaseDirectory, "Fixtures", "hulls", "box.cache"));
        var worlds = new AutoCore.Sim.Collision.MapCollisionWorlds
        {
            PhysicsNameByCbid = cbid => cbid == 777 ? "box" : null,
            HullEntryNames = () => new[] { "box.cache" },
            HullBytesByName = _ => boxBytes,
        };
        var manager = new CloneManager(worlds);
        var character = DrivingCharacter(map);
        manager.Toggle(character);
        var clone = map.NpcAiEntities.OfType<Vehicle>().Single();

        // Background build: tick until the world flips in (bounded wait).
        AutoCore.Sim.Ai.CloneDriveBrain brain = null;
        for (var i = 0; i < 200; i++)
        {
            manager.Tick(nowMs: i * 50, dt: 0.05f);
            brain = manager.BrainForTests(character);
            if (brain?.Obstacles != null)
                break;
            Thread.Sleep(10);
        }

        Assert.IsNotNull(brain?.Obstacles, "hull world must attach after the background build");
        Assert.AreEqual(1, brain.Obstacles.InstanceCount);
    }

    /// <summary>
    /// Height is fully data-driven (user decision 2026-08-09, no owner calibration): published
    /// Y = sim ground pose + per-chassis ride height from VehicleGroundMetricsCache (wheel
    /// radius − hardpoint Y, from clonebase.wad) + /clonetrim.
    /// </summary>
    [TestMethod]
    public void Tick_PublishesDataDrivenRideHeightFromGroundMetrics()
    {
        var metricsSource = new Dictionary<int, AutoCore.Game.CloneBases.CloneBase>();
        var cv = (AutoCore.Game.CloneBases.CloneBaseVehicle)System.Runtime.CompilerServices.RuntimeHelpers
            .GetUninitializedObject(typeof(AutoCore.Game.CloneBases.CloneBaseVehicle));
        cv.CloneBaseSpecific = new AutoCore.Game.CloneBases.Specifics.CloneBaseSpecific
        {
            Type = (int)CloneBaseObjectType.Vehicle,
            CloneBaseId = ChassisCbid,
        };
        cv.SimpleObjectSpecific = new AutoCore.Game.CloneBases.Specifics.SimpleObjectSpecific { Mass = 900f };
        cv.VehicleSpecific = new AutoCore.Game.CloneBases.Specifics.VehicleSpecific
        {
            WheelRadius = new[] { 0.5f, 0.5f, 0.5f, 0.5f, 0f, 0f },
            WheelHardPoints = new[]
            {
                new AutoCore.Game.Structures.Vector3(-0.9f, 0.2f, 1.5f),
                new AutoCore.Game.Structures.Vector3(0.9f, 0.2f, 1.5f),
                new AutoCore.Game.Structures.Vector3(-0.9f, 0.2f, -1.5f),
                new AutoCore.Game.Structures.Vector3(0.9f, 0.2f, -1.5f),
                new AutoCore.Game.Structures.Vector3(0f, 0f, 0f),
                new AutoCore.Game.Structures.Vector3(0f, 0f, 0f),
            },
        };
        metricsSource[ChassisCbid] = cv;
        AutoCore.Game.Npc.VehicleGroundMetricsCache.BuildFromCloneBases(metricsSource);
        try
        {
            var expectedRide = AutoCore.Game.Npc.VehicleGroundMetricsCache.GetRideHeight(ChassisCbid);
            Assert.AreEqual(0.3f, expectedRide, 0.01f, "test setup: radius 0.5 − hardpointY 0.2");

            var map = CreateFieldMap(8209);
            var character = DrivingCharacter(map);
            character.CurrentVehicle.Position = new AutoCore.Game.Structures.Vector3(100f, 50f, 100f);
            var manager = new CloneManager();
            manager.Toggle(character);
            var clone = map.NpcAiEntities.OfType<Vehicle>().Single();

            for (var i = 0; i < 100; i++)
                manager.Tick(nowMs: i * 50, dt: 0.05f);

            // No heightfield on test maps: the sim drives a flat plane at spawn height (50),
            // so the published Y must be plane + data-driven ride height.
            Assert.AreEqual(50f + expectedRide, clone.Position.Y, 0.15f,
                $"published Y {clone.Position.Y} must include the chassis ride height {expectedRide}");
        }
        finally
        {
            AutoCore.Game.Npc.VehicleGroundMetricsCache.Clear();
        }
    }

    /// <summary>
    /// Live report 2026-08-08: wheels animated the wrong way. The retail wire convention
    /// (VehicleDriveController.ComputeAxes, brake-spec.md pedal derivation) is NEGATIVE
    /// throttle = drive forward and steer = baseDir·lateral, so the sim's positive-forward /
    /// positive-right inputs must be negated at the publish boundary.
    /// </summary>
    [TestMethod]
    public void Tick_PublishesRetailSignConventionOnTheWire()
    {
        var map = CreateFieldMap(8208);
        var character = DrivingCharacter(map);
        character.CurrentVehicle.Position = new AutoCore.Game.Structures.Vector3(100f, 0f, 100f);
        // Player cruising forward so the clone chases at meaningful throttle. ApplyServerMove is
        // the sanctioned velocity write path.
        character.CurrentVehicle.ApplyServerMove(
            character.CurrentVehicle.Position, character.CurrentVehicle.Rotation,
            new AutoCore.Game.Structures.Vector3(0f, 0f, 10f), 0.05f, null, null, null, null);
        var manager = new CloneManager();
        manager.Toggle(character);
        var clone = map.NpcAiEntities.OfType<Vehicle>().Single();

        for (var i = 0; i < 60; i++)
        {
            character.CurrentVehicle.Position = new AutoCore.Game.Structures.Vector3(
                100f, 0f, 100f + i * 0.5f);
            manager.Tick(nowMs: i * 50, dt: 0.05f);
        }

        Assert.IsTrue(clone.Acceleration < -0.1f,
            $"forward drive must publish NEGATIVE Acceleration (retail wire), was {clone.Acceleration}");
    }

    [TestMethod]
    public void Toggle_TwoPlayers_HaveIndependentClones()
    {
        var map = CreateFieldMap(8206);
        var first = DrivingCharacter(map, coid: 9001);
        var second = DrivingCharacter(map, coid: 9002);
        var manager = new CloneManager();

        manager.Toggle(first);
        manager.Toggle(second);

        Assert.AreEqual(2, manager.ActiveCloneCount);

        manager.Toggle(first);

        Assert.AreEqual(1, manager.ActiveCloneCount);
    }
}
