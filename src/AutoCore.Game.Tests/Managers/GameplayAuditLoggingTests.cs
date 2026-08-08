using System.Text;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.Char.Models;
using AutoCore.Database.World.Models;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Map;
using AutoCore.Game.Managers;
using AutoCore.Game.Packets.Global;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.TNL;
using AutoCore.Utils.Logging;

/// <summary>Phase 3F: ObjectUsed / ChatCommandExecuted hooks.</summary>
[TestClass]
public class GameplayAuditLoggingTests
{
    private InMemoryLogSink _sink = null!;
    private readonly List<AutoCore.Game.Packets.BasePacket> _sent = new();

    [TestInitialize]
    public void Init()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);
        _sent.Clear();
        TNLConnection.TestPacketSink = (_, p) => _sent.Add(p);
    }

    [TestCleanup]
    public void Cleanup()
    {
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        TNLConnection.TestPacketSink = null;
        VendorStoreService.ResetSessionsForTests();
    }

    [TestMethod]
    public void ObjectUse_NoHandler_EmitsObjectUsed_None()
    {
        var (conn, character, map) = CreatePlayer();
        var prop = new GraphicsObject(GraphicsObjectType.GraphicsPhysics);
        prop.SetCoid(55501, false);
        prop.Position = new Vector3(0, 0, 0);
        prop.SetMap(map);
        _sink.Clear();

        ObjectUseManager.Handle(conn, new UseObjectPacket
        {
            Target = new TFID(55501, false),
            ObjectiveId = 0,
        });

        var rec = _sink.Single("ObjectUsed");
        Assert.AreEqual("None", rec.GetProperty("Handler"));
        Assert.AreEqual(55501L, Convert.ToInt64(rec.GetProperty("TargetCoid")));
    }

    [TestMethod]
    public void ChatCommand_EmitsChatCommandExecuted_FirstTokenOnly()
    {
        var conn = CreateConnection();
        _sink.Clear();

        using var reader = ChatReader("/listItems 1 2 3");
        ChatManager.Instance.HandleChatPacket(conn, reader);

        var rec = _sink.Single("ChatCommandExecuted");
        Assert.IsTrue(rec.Audit);
        Assert.AreEqual("/listItems", rec.GetProperty("Command"));
    }

    private TNLConnection CreateConnection()
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);
        connection.SetNetAddress(new System.Net.IPEndPoint(System.Net.IPAddress.Loopback, 0));
        connection.Account = new Account { Id = 42, Name = "glog", Level = 0 };

        var character = new Character();
        character.SetCoid(18501, true);
        character.AttachTestDataForTests("glog");
        character.GMLevel = 1;
        character.SetOwningConnection(connection);
        connection.CurrentCharacter = character;
        return connection;
    }

    private static BinaryReader ChatReader(string message)
    {
        var packet = new ChatPacket
        {
            ChatType = ChatType.SectorMessage,
            IsGM = false,
            PrivateRecipientName = "",
            Sender = "tester",
            Message = message ?? "",
            MessageLength = (short)(Encoding.UTF8.GetByteCount(message ?? "") + 1)
        };

        var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            packet.Write(writer);
        stream.Position = 0;
        return new BinaryReader(stream, Encoding.UTF8, leaveOpen: false);
    }

    static (TNLConnection Conn, Character Character, SectorMap Map) CreatePlayer()
    {
        var map = SectorMap.CreateForTests(new ContinentObject
        {
            Id = 8833,
            MapFileName = "t_game_log",
            DisplayName = "t",
            IsPersistent = true,
            IsTown = true,
        }, new Vector4());
        map.LocalCoidCounter = 30000;

        var conn = new TNLConnection();
        conn.SetGhostFrom(true);
        conn.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(18501, true);
        character.AttachTestDataForTests("GLog");
        character.GMLevel = 1;
        character.SetOwningConnection(conn);
        conn.CurrentCharacter = character;

        var vehicle = new Vehicle();
        vehicle.SetCoid(18502, true);
        vehicle.Position = new Vector3(0, 0, 0);
        character.SetCurrentVehicleForTests(vehicle);
        character.SetMap(map);
        vehicle.SetMap(map);
        return (conn, character, map);
    }
}
