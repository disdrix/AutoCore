using System.IO;
using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Sector;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Sector;

/// <summary>
/// Round-trip coverage for <see cref="MapInfoPacket"/> manual packing layout.
/// </summary>
[TestClass]
public class MapInfoPacketTests
{
    [TestMethod]
    public void WriteThenRead_RoundTripsCoreFields()
    {
        var original = new MapInfoPacket
        {
            RegionId = 7,
            RegionType = (TilesetType)3,
            RegionLevel = 12,
            LayerId = 4,
            ObjectiveIndex = 2,
            MapName = "tm_arkbay",
            IsTown = true,
            IsArena = false,
            OwningFaction = 1,
            ContinentObjectId = 88,
            IsPersistent = true,
            MapIterationVersion = 5,
            ContestedMissionId = -1,
            Coid = 1001,
            TemporalRandomSeed = 42,
            CoidMap = 2002,
            NumModulePlacements = 2,
            PositionX = 10.5f,
            PositionY = 20.25f,
            PositionZ = -3f,
            WeatherUpdateSize = 4,
        };

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var restored = new MapInfoPacket();
        using (var reader = new BinaryReader(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            restored.Read(reader);

        Assert.AreEqual(original.RegionId, restored.RegionId);
        Assert.AreEqual(original.RegionType, restored.RegionType);
        Assert.AreEqual(original.RegionLevel, restored.RegionLevel);
        Assert.AreEqual(original.LayerId, restored.LayerId);
        Assert.AreEqual(original.ObjectiveIndex, restored.ObjectiveIndex);
        Assert.AreEqual(original.MapName, restored.MapName);
        Assert.IsTrue(restored.IsTown);
        Assert.IsFalse(restored.IsArena);
        Assert.AreEqual(original.OwningFaction, restored.OwningFaction);
        Assert.AreEqual(original.ContinentObjectId, restored.ContinentObjectId);
        Assert.IsTrue(restored.IsPersistent);
        Assert.AreEqual(original.MapIterationVersion, restored.MapIterationVersion);
        Assert.AreEqual(original.ContestedMissionId, restored.ContestedMissionId);
        Assert.AreEqual(original.Coid, restored.Coid);
        Assert.AreEqual(original.TemporalRandomSeed, restored.TemporalRandomSeed);
        Assert.AreEqual(original.CoidMap, restored.CoidMap);
        Assert.AreEqual(original.NumModulePlacements, restored.NumModulePlacements);
        Assert.AreEqual(original.PositionX, restored.PositionX, 1e-5f);
        Assert.AreEqual(original.PositionY, restored.PositionY, 1e-5f);
        Assert.AreEqual(original.PositionZ, restored.PositionZ, 1e-5f);
        Assert.AreEqual(original.WeatherUpdateSize, restored.WeatherUpdateSize);
    }

    [TestMethod]
    public void Write_ZeroModulesAndWeather_RoundTrips()
    {
        var original = new MapInfoPacket
        {
            MapName = "x",
            NumModulePlacements = 0,
            WeatherUpdateSize = 0,
            PositionX = 1f,
            PositionY = 2f,
            PositionZ = 3f,
        };

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        ms.Position = 0;
        var restored = new MapInfoPacket();
        using (var reader = new BinaryReader(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            restored.Read(reader);

        Assert.AreEqual(0, restored.NumModulePlacements);
        Assert.AreEqual(0, restored.WeatherUpdateSize);
        Assert.AreEqual(1f, restored.PositionX, 1e-5f);
        Assert.AreEqual(2f, restored.PositionY, 1e-5f);
        Assert.AreEqual(3f, restored.PositionZ, 1e-5f);
    }
}
