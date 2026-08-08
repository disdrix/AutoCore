using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Utils;
using AutoCore.Utils.Logging;

/// <summary>
/// Phase 2 map-transfer operation scope: MapTransferStarted/Completed/Failed with
/// character + from/to map identity, without changing the transfer's control flow.
/// </summary>
[TestClass]
public class MapTransferLoggingTests
{
    private InMemoryLogSink _sink;
    private Func<int, SectorMap> _previousResolver;
    private bool _previousSuppress;

    [TestInitialize]
    public void Init()
    {
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        _previousResolver = MapManager.Instance.ResolveMapForTests;
        _previousSuppress = MapManager.Instance.SuppressCreatePacketsForTests;
        TNLConnection.TestPacketSink = (_, _) => { };
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        Logger.UpdateConfig(new Logger.LoggerConfig { LogToFile = false });
        MapManager.Instance.ResolveMapForTests = _previousResolver;
        MapManager.Instance.SuppressCreatePacketsForTests = _previousSuppress;
        TNLConnection.TestPacketSink = null;
    }

    [TestMethod]
    public void Transfer_PreconditionFailure_EmitsMapTransferFailed_WithReason()
    {
        var character = new Character();
        character.SetCoid(9_060_000_301L, true);
        // No owning connection → precondition NoConnection.

        Assert.IsFalse(MapManager.Instance.TransferCharacterToMap(character, 693),
            "Existing control flow must be unchanged: precondition failure returns false.");

        var started = _sink.Single("MapTransferStarted");
        Assert.AreEqual(9_060_000_301L, started.GetProperty("CharacterId"),
            "The operation must name the character being transferred.");
        Assert.AreEqual(693, started.GetProperty("ToMapId"),
            "The operation must name the destination map.");

        var failed = _sink.Single("MapTransferFailed");
        Assert.AreEqual("NoConnection", failed.GetProperty("Reason"),
            "Early-return failure paths must state which precondition failed.");
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "MapTransferCompleted"),
            "A failed transfer must not also report Completed.");
    }

    [TestMethod]
    public void Transfer_UnknownMap_EmitsMapTransferFailed_ReasonUnknownMap()
    {
        var (character, _) = CreateTransferableCharacter(sourceContinentId: 558);
        MapManager.Instance.ResolveMapForTests = _ => null;

        Assert.IsFalse(MapManager.Instance.TransferCharacterToMap(character, 12345));

        var failed = _sink.Single("MapTransferFailed");
        Assert.AreEqual("UnknownMap", failed.GetProperty("Reason"),
            "A missing destination map is a content/config problem and must be named as such.");
    }

    [TestMethod]
    public void Transfer_Success_EmitsMapTransferCompleted_WithFromAndToMap()
    {
        var (character, _) = CreateTransferableCharacter(sourceContinentId: 558);
        var destMap = CreateMap(693);
        MapManager.Instance.ResolveMapForTests = _ => destMap;
        MapManager.Instance.SuppressCreatePacketsForTests = true;

        Assert.IsTrue(MapManager.Instance.TransferCharacterToMap(character, 693),
            "The successful transfer path must be unchanged by the logging wrapper.");

        var started = _sink.Single("MapTransferStarted");
        Assert.AreEqual(558, started.GetProperty("FromMapId"),
            "FromMapId records the continent the character left.");
        Assert.AreEqual(693, started.GetProperty("ToMapId"),
            "ToMapId records the destination continent.");

        var completed = _sink.Single("MapTransferCompleted");
        Assert.IsNotNull(completed.GetProperty("DurationMs"),
            "Completed operations carry DurationMs so slow transfers are visible.");
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "MapTransferFailed"),
            "A successful transfer must not also report Failed.");
    }

    // ---- helpers ----

    private static SectorMap CreateMap(int continentId)
    {
        var continent = new ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_xferlog_{continentId}",
            DisplayName = "xfer-log",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0f, 0f, 0f, 0f));
    }

    private static (Character Character, TNLConnection Connection) CreateTransferableCharacter(int sourceContinentId)
    {
        var sourceMap = CreateMap(sourceContinentId);

        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(9_060_000_302L, true);
        character.AttachTestDataForTests();
        character.SetOwningConnection(connection);

        var vehicle = new Vehicle();
        vehicle.SetCoid(9_060_000_303L, true);
        vehicle.AttachTestDataForTests();
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(sourceMap);
        vehicle.SetMap(sourceMap);

        return (character, connection);
    }
}
