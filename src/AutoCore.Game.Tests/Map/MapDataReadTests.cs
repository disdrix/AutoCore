using AutoCore.Database.World.Models;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

/// <summary>
/// Synthetic .fam binary coverage for <see cref="MapData.Read"/> without GLM archives.
/// </summary>
[TestClass]
public class MapDataReadTests
{
    [TestMethod]
    public void Read_InvalidMapVersion_Throws()
    {
        var map = NewMapData();
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            w.Write(3); // below valid range 4..62

        ms.Position = 0;
        Assert.ThrowsException<Exception>(() => map.Read(new BinaryReader(ms)));
    }

    [TestMethod]
    public void Read_Version54_ParsesHeaderWeatherRoadsMusicAndSeaPlane()
    {
        var map = NewMapData();
        using var ms = BuildVersion54Fam();
        map.Read(new BinaryReader(ms));

        Assert.AreEqual(54, map.MapVersion);
        Assert.AreEqual(7, map.IterationVersion);
        Assert.AreEqual(32, map.TerrainWidth);
        Assert.AreEqual(48, map.TerrainHeight);
        Assert.AreEqual(16f, map.GridSize);
        Assert.AreEqual((byte)2, map.TileSet);
        Assert.IsTrue(map.UseRoad);
        Assert.AreEqual(3, map.Music.Length);
        Assert.IsTrue(map.UseClouds);
        Assert.IsTrue(map.UseTimeOfDay);
        Assert.AreEqual("sky_box", map.SkyBoxName);
        Assert.AreEqual(1.5f, map.CullingScale);
        Assert.AreEqual(0, map.NumOfImports);
        Assert.AreEqual(10f, map.EntryPoint.X);
        Assert.AreEqual(20f, map.EntryPoint.Y);
        Assert.AreEqual(30f, map.EntryPoint.Z);
        Assert.AreEqual(1f, map.EntryPoint.W);
        Assert.AreEqual(0, map.NumModulePlacements);
        Assert.AreEqual(0, map.NumOfVOGOs);
        Assert.AreEqual(0, map.NumOfClientVOGOs);
        Assert.AreEqual(900, map.HighestCoid);
        Assert.AreEqual(111L, map.PerPlayerLoadTrigger);
        Assert.AreEqual(222L, map.CreatorLoadTrigger);
        Assert.AreEqual(333L, map.OnKillTrigger);
        Assert.AreEqual(444L, map.LastTeamTrigger);
        Assert.AreEqual("weather_fx", map.WeatherStrEffect);
        Assert.AreEqual(1, map.WeatherInfos.Count);
        Assert.IsTrue(map.WeatherInfos.ContainsKey(1));
        Assert.AreEqual(1, map.WeatherInfos[1].Weathers.Count);
        Assert.AreEqual("region_fx", map.WeatherInfos[1].Effect);
        Assert.AreEqual(4, map.WeatherInfos[1].Environments.Count);
        Assert.IsNotNull(map.SeaPlane);
        Assert.AreEqual(5f, map.SeaPlane.Coords.X);
        Assert.AreEqual(1, map.SeaPlane.CoordsList.Count);
        Assert.AreEqual(0xABCD, map.Flags);
        Assert.AreEqual(1, map.MissionStrings.Count);
        Assert.AreEqual("hello", map.MissionStrings[42].Text);
        Assert.AreEqual(1, map.VisualWaypoints.Count);
        Assert.AreEqual(15, map.VisualWaypoints[15].Id);
        Assert.AreEqual(1, map.Variables.Count);
        Assert.AreEqual(9, map.Variables[9].Id);
        Assert.AreEqual(2, map.RoadNodes.Count);
        Assert.IsInstanceOfType(map.RoadNodes[0], typeof(RoadNode));
        Assert.IsInstanceOfType(map.RoadNodes[1], typeof(RiverNode));
        Assert.AreEqual(1, map.MusicTriggers.Count);
        Assert.AreEqual("theme", map.MusicTriggers[0].Name);
    }

    [TestMethod]
    public void Read_Version10_MinimalHeader_NoOptionalBlocks()
    {
        var map = NewMapData();
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(10); // MapVersion — no Iteration, no clouds block
            w.Write(8);  // TerrainWidth
            w.Write(8);  // TerrainHeight
            w.Write(4f); // GridSize
            w.Write((byte)0);
            w.Write(false);
            w.Write((short)0); w.Write((short)0); w.Write((short)0);

            // EntryPoint
            w.Write(0f); w.Write(0f); w.Write(0f); w.Write(1f);
            w.Write(0); // NumModulePlacements
            w.Write(0); // NumOfVOGOs
            w.Write(0); // NumOfClientVOGOs
            w.Write(10); // HighestCoid
            w.Write(0L); // PerPlayerLoad
            w.Write(0L); // CreatorLoad
            // no OnKill / LastTeam

            w.Write(0); // mission strings
            w.Write(0); // visual waypoints
            w.Write(0); // variables
            // no weather / no seaplane before objects
            // 0 objects
            // no flags
            w.Write(0); // roads
            // seaplane after roads when version < 38 — no-op for v10 (<35)
        }

        ms.Position = 0;
        map.Read(new BinaryReader(ms));

        Assert.AreEqual(10, map.MapVersion);
        Assert.AreEqual(0, map.IterationVersion);
        Assert.AreEqual(8, map.TerrainWidth);
        Assert.AreEqual(0, map.MissionStrings.Count);
        Assert.AreEqual(0, map.WeatherInfos.Count);
        Assert.IsNull(map.SeaPlane);
        Assert.AreEqual(0, map.Flags);
        Assert.AreEqual(0, map.MusicTriggers.Count);
    }

    [TestMethod]
    public void SetEventTriggerCoidsForTests_AndSetHeightfield_AreVisible()
    {
        var map = NewMapData();
        map.SetEventTriggerCoidsForTests(perPlayerLoad: 1, creatorLoad: 2, onKill: 3, lastTeam: 4);
        Assert.AreEqual(1L, map.PerPlayerLoadTrigger);
        Assert.AreEqual(2L, map.CreatorLoadTrigger);
        Assert.AreEqual(3L, map.OnKillTrigger);
        Assert.AreEqual(4L, map.LastTeamTrigger);

        // Heightfield seam: null attachment is a no-op assignment path.
        map.SetHeightfield(null);
        Assert.IsNull(map.Heightfield);
    }

    [TestMethod]
    public void Read_Version35_SeaPlaneAbsentFlag_LeavesSeaPlaneNull()
    {
        var map = NewMapData();
        using var ms = new MemoryStream();
        using (var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            w.Write(35);
            w.Write(11); // IterationVersion (>=27)
            w.Write(4); w.Write(4); w.Write(2f);
            w.Write((byte)1);
            w.Write(false);
            w.Write((short)1); w.Write((short)2); w.Write((short)3);
            w.Write(false); // UseClouds
            w.Write(false); // UseTimeOfDay
            w.WriteLengthedString("sky");
            // no culling (needs >=36), no imports (>=45)

            w.Write(0f); w.Write(0f); w.Write(0f); w.Write(1f);
            w.Write(0); w.Write(0); w.Write(0); w.Write(1);
            w.Write(0L); w.Write(0L);
            w.Write(0L); // OnKill (>=33)
            w.Write(0L); // LastTeam (>=34) — v35 includes this

            w.Write(0); w.Write(0); w.Write(0);

            // SeaPlane after roads when version < 38.
            // 0 objects, no flags, roads empty, then seaplane: present flag = 0
            w.Write(0); // roads
            w.Write((byte)0); // no seaplane payload
        }

        ms.Position = 0;
        map.Read(new BinaryReader(ms));
        Assert.AreEqual(35, map.MapVersion);
        Assert.IsNull(map.SeaPlane);
        Assert.AreEqual(0L, map.LastTeamTrigger);
    }

    private static MapData NewMapData()
    {
        return new MapData(new ContinentObject
        {
            Id = 1,
            MapFileName = "test_map_data_read",
            DisplayName = "Test",
            IsTown = false,
            IsPersistent = true
        });
    }

    private static MemoryStream BuildVersion54Fam()
    {
        var ms = new MemoryStream();
        using var w = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true);

        w.Write(54); // MapVersion
        w.Write(7);  // IterationVersion
        w.Write(32); // TerrainWidth
        w.Write(48); // TerrainHeight
        w.Write(16f);
        w.Write((byte)2);
        w.Write(true); // UseRoad
        w.Write((short)10); w.Write((short)20); w.Write((short)30);
        w.Write(true); // UseClouds
        w.Write(true); // UseTimeOfDay
        w.WriteLengthedString("sky_box");
        w.Write(1.5f); // CullingScale
        w.Write(0);    // NumOfImports

        // EntryPoint
        w.Write(10f); w.Write(20f); w.Write(30f); w.Write(1f);
        w.Write(0); // modules
        w.Write(0); // vogos
        w.Write(0); // client vogos
        w.Write(900);
        w.Write(111L);
        w.Write(222L);
        w.Write(333L); // OnKill
        w.Write(444L); // LastTeam

        // Mission strings (mapVersion >= 18 includes type)
        w.Write(1);
        w.Write(42); // StringId
        w.Write(7);  // OwnerId
        w.Write((byte)1);
        w.WriteLengthedString("hello");

        // Visual waypoints
        w.Write(1);
        w.Write(0);  // discarded
        w.Write(15); // Id
        w.Write((byte)2);
        w.Write(1f); w.Write(2f); w.Write(3f);
        w.Write(100L);
        w.Write(200L);
        w.Write(0); // objective count

        // Variables (mapVersion >= 46 has UniqueForImport)
        w.Write(1);
        w.Write(9); // Id
        w.Write((byte)1);
        w.Write(1.0f);
        w.Write(0.0f);
        w.Write(false); // UniqueForImport
        w.WriteUtf8StringOn("varname", 64);

        // Weather (>=47)
        w.WriteLengthedString("weather_fx");
        w.Write(1u); // regionCount
        w.Write((byte)1); // regionId
        w.Write(1u); // weatherCount
        w.Write(1u); // SpecialType
        w.Write(2u); // Type
        w.Write(0.5f);
        w.Write(0); // SpecialEventSkill
        w.Write((byte)3);
        w.Write(10u);
        w.Write(20u);
        w.Write(0xFFu); // LayerBits (>=54)
        w.WriteLengthedString("fx");
        w.WriteLengthedString("region_fx");
        w.WriteLengthedString("e0");
        w.WriteLengthedString("e1");
        w.WriteLengthedString("e2");
        w.WriteLengthedString("e3");

        // SeaPlane before objects (>=38)
        w.Write((byte)1); // present
        w.Write(1); // planeCount used for CoordsList length
        w.Write(5f); w.Write(6f); w.Write(7f); w.Write(1f); // Coords
        w.Write(8f); w.Write(9f); w.Write(10f); w.Write(1f); // list[0]

        // 0 objects
        w.Write(0xABCD); // Flags (>=43)

        // Roads: plain + river
        w.Write(2);

        // RoadNode type 0
        WriteRoadPayload(w, type: 0, payload: writer =>
        {
            writer.Write(1); // UniqueId
            writer.Write(1f); writer.Write(2f); writer.Write(3f);
            writer.WriteUtf8StringOn("road.dat", 260);
            writer.Write(0);
        });

        // RiverNode type 2
        WriteRoadPayload(w, type: 2, payload: writer =>
        {
            writer.Write(2);
            writer.Write(0f); writer.Write(0f); writer.Write(0f);
            writer.WriteUtf8StringOn("river.dat", 260);
            writer.Write(0);
            writer.Write(4.5f); // WaterDepth
            writer.Write(0x11223344u);
            writer.Write(0x55667788u);
        });

        // Music regions (>=42)
        w.Write(1);
        w.Write(0); // discarded size int
        w.WriteLengthedString("theme");
        w.Write(true);
        w.Write(false);
        w.Write(1.0f);
        w.Write(0.5f);
        w.Write(0.25f);
        w.Write(50f);
        w.Write(10f); w.Write(20f); w.Write(30f);
        w.Write((int)Music.MusicType.Foreground);

        // Mini catalog (>=49, >=52): empty external path (no bytes)

        ms.Position = 0;
        return ms;
    }

    private static void WriteRoadPayload(BinaryWriter outer, byte type, Action<BinaryWriter> payload)
    {
        using var payloadMs = new MemoryStream();
        using (var pw = new BinaryWriter(payloadMs, System.Text.Encoding.UTF8, leaveOpen: true))
            payload(pw);

        outer.Write((int)payloadMs.Length);
        outer.Write(type);
        outer.Write(payloadMs.ToArray());
    }
}
