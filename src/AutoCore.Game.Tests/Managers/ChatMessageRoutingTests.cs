using System.Text;
using AutoCore.Database.Char.Models;
using AutoCore.Database.World.Models;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Global;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

/// <summary>
/// Local + Global public chat fan-out (non-command messages).
/// </summary>
[TestClass]
public class ChatMessageRoutingTests
{
    private readonly Dictionary<TNLConnection, List<BasePacket>> _sentByConn = new();
    private long _nextCoid = 9000;

    [TestInitialize]
    public void Init()
    {
        _sentByConn.Clear();
        TNLConnection.TestPacketSink = (conn, packet) =>
        {
            if (!_sentByConn.TryGetValue(conn, out var list))
            {
                list = new List<BasePacket>();
                _sentByConn[conn] = list;
            }

            list.Add(packet);
        };
        ChatManager.Instance.ResetRoutingForTests();
    }

    [TestCleanup]
    public void Cleanup()
    {
        TNLConnection.TestPacketSink = null;
        ChatManager.Instance.ResetRoutingForTests();
    }

    private TNLConnection CreatePlayer(string name, SectorMap map = null)
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);
        connection.SetNetAddress(new System.Net.IPEndPoint(System.Net.IPAddress.Loopback, 0));
        connection.Account = new Account { Id = (uint)(_nextCoid % 1000), Name = name, Level = 0 };

        var character = new Character();
        character.SetCoid(_nextCoid++, true);
        character.AttachTestDataForTests(name);
        character.GMLevel = 0;
        character.SetOwningConnection(connection);
        connection.CurrentCharacter = character;

        var vehicle = new Vehicle();
        vehicle.SetCoid(_nextCoid++, true);
        character.SetCurrentVehicleForTests(vehicle);

        if (map != null)
        {
            character.SetMap(map);
            vehicle.SetMap(map);
        }

        return connection;
    }

    private static SectorMap CreateMap(int continentId = 700)
    {
        var continent = new ContinentObject
        {
            Id = continentId,
            MapFileName = $"chat_route_{continentId}",
            DisplayName = "ChatRoute",
            IsTown = true,
            IsPersistent = true
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static BinaryReader ChatReader(
        string message,
        ChatType type = ChatType.GlobalPublic,
        string sender = "spoofed",
        string privateName = "")
    {
        var packet = new ChatPacket
        {
            ChatType = type,
            IsGM = false,
            PrivateRecipientName = privateName ?? "",
            Sender = sender ?? "",
            Message = message ?? "",
            MessageLength = (short)(Encoding.UTF8.GetByteCount(message ?? "") + 1)
        };

        var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            packet.Write(writer);
        stream.Position = 0;
        return new BinaryReader(stream);
    }

    private static BinaryReader BroadcastReader(
        string message,
        ChatType type = ChatType.LocalMessage,
        string sender = "spoofed",
        ulong senderCoid = 0)
    {
        var packet = new BroadcastPacket
        {
            ChatType = type,
            SenderCoid = senderCoid,
            IsGM = false,
            Sender = sender ?? "",
            Message = message ?? "",
            MessageLength = (short)(Encoding.UTF8.GetByteCount(message ?? "") + 1)
        };

        var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            packet.Write(writer);
        stream.Position = 0;
        return new BinaryReader(stream);
    }

    private List<BasePacket> SentTo(TNLConnection conn) =>
        _sentByConn.TryGetValue(conn, out var list) ? list : new List<BasePacket>();

    [TestMethod]
    public void HandleChatPacket_GlobalPublic_DeliversToAllOnline()
    {
        var alice = CreatePlayer("Alice");
        var bob = CreatePlayer("Bob");
        ChatManager.Instance.ListOnlineForTests = () => new[]
        {
            alice.CurrentCharacter!,
            bob.CurrentCharacter!
        };

        ChatManager.Instance.HandleChatPacket(alice, ChatReader("hello global", ChatType.GlobalPublic));

        var alicePkt = SentTo(alice).OfType<ChatPacket>().Single();
        var bobPkt = SentTo(bob).OfType<ChatPacket>().Single();
        Assert.AreEqual(ChatType.GlobalPublic, alicePkt.ChatType);
        Assert.AreEqual(ChatType.GlobalPublic, bobPkt.ChatType);
        Assert.AreEqual("hello global", alicePkt.Message);
        Assert.AreEqual("hello global", bobPkt.Message);
        Assert.AreEqual("Alice", alicePkt.Sender, "Server must force real sender name.");
        Assert.AreEqual("Alice", bobPkt.Sender);
    }

    [TestMethod]
    public void HandleChatPacket_GlobalPublic_IncludesSenderOnly_WhenAlone()
    {
        var alice = CreatePlayer("Alice");
        ChatManager.Instance.ListOnlineForTests = () => new[] { alice.CurrentCharacter! };

        ChatManager.Instance.HandleChatPacket(alice, ChatReader("solo", ChatType.GlobalPublic));

        Assert.AreEqual(1, SentTo(alice).OfType<ChatPacket>().Count());
        Assert.AreEqual("solo", SentTo(alice).OfType<ChatPacket>().Single().Message);
    }

    [TestMethod]
    public void HandleChatPacket_GlobalPublic_EmptyMessage_SendsNothing()
    {
        var alice = CreatePlayer("Alice");
        ChatManager.Instance.ListOnlineForTests = () => new[] { alice.CurrentCharacter! };

        ChatManager.Instance.HandleChatPacket(alice, ChatReader("   ", ChatType.GlobalPublic));

        Assert.AreEqual(0, SentTo(alice).Count);
    }

    [TestMethod]
    public void HandleChatPacket_GlobalPublic_SkipsOfflineRecipient_SS04()
    {
        var alice = CreatePlayer("Alice");
        var offline = new Character();
        offline.SetCoid(_nextCoid++, true);
        offline.AttachTestDataForTests("Ghost");
        Assert.IsNull(offline.OwningConnection);

        ChatManager.Instance.ListOnlineForTests = () => new[] { alice.CurrentCharacter!, offline };

        ChatManager.Instance.HandleChatPacket(alice, ChatReader("hi", ChatType.GlobalPublic));

        Assert.AreEqual(1, SentTo(alice).OfType<ChatPacket>().Count());
    }

    [TestMethod]
    public void HandleChatPacket_GlobalPublic_ForcesIsGMFromCharacter()
    {
        var gm = CreatePlayer("GM");
        gm.CurrentCharacter!.GMLevel = 1;
        ChatManager.Instance.ListOnlineForTests = () => new[] { gm.CurrentCharacter! };

        ChatManager.Instance.HandleChatPacket(gm, ChatReader("staff", ChatType.GlobalPublic));

        Assert.IsTrue(SentTo(gm).OfType<ChatPacket>().Single().IsGM);
    }

    [TestMethod]
    public void HandleBroadcastPacket_LocalMessage_DeliversToSameMapOnly()
    {
        var mapA = CreateMap(701);
        var mapB = CreateMap(702);
        var alice = CreatePlayer("Alice", mapA);
        var bob = CreatePlayer("Bob", mapA);
        var carol = CreatePlayer("Carol", mapB);

        ChatManager.Instance.HandleBroadcastPacket(
            alice,
            BroadcastReader("local hi", ChatType.LocalMessage, sender: "Fake", senderCoid: 999));

        var alicePkts = SentTo(alice).OfType<BroadcastPacket>().Where(p => p.ChatType == ChatType.LocalMessage).ToList();
        var bobPkts = SentTo(bob).OfType<BroadcastPacket>().Where(p => p.ChatType == ChatType.LocalMessage).ToList();
        var carolPkts = SentTo(carol).OfType<BroadcastPacket>().Where(p => p.ChatType == ChatType.LocalMessage).ToList();

        Assert.AreEqual(1, alicePkts.Count);
        Assert.AreEqual(1, bobPkts.Count);
        Assert.AreEqual(0, carolPkts.Count, "Different map instance must not receive Local.");
        Assert.AreEqual("local hi", alicePkts[0].Message);
        Assert.AreEqual("Alice", alicePkts[0].Sender, "Server must force real sender name.");
        Assert.AreEqual("Alice", bobPkts[0].Sender);
        Assert.AreEqual((ulong)alice.CurrentCharacter!.ObjectId.Coid, alicePkts[0].SenderCoid);
    }

    [TestMethod]
    public void HandleBroadcastPacket_LocalMessage_WithoutMap_SendsSystemNotice()
    {
        var alice = CreatePlayer("Alice", map: null);

        ChatManager.Instance.HandleBroadcastPacket(
            alice,
            BroadcastReader("nowhere", ChatType.LocalMessage));

        Assert.AreEqual(0, SentTo(alice).OfType<BroadcastPacket>().Count(p => p.ChatType == ChatType.LocalMessage));
        var system = SentTo(alice).OfType<BroadcastPacket>().Single(p => p.ChatType == ChatType.SystemMessage);
        StringAssert.Contains(system.Message, "not in a map");
    }

    [TestMethod]
    public void HandleBroadcastPacket_LocalMessage_Empty_SendsNothing()
    {
        var map = CreateMap();
        var alice = CreatePlayer("Alice", map);

        ChatManager.Instance.HandleBroadcastPacket(alice, BroadcastReader("  ", ChatType.LocalMessage));

        Assert.AreEqual(0, SentTo(alice).Count);
    }

    [TestMethod]
    public void HandleBroadcastPacket_SectorMessage_StillEchoesToSenderOnly()
    {
        var map = CreateMap();
        var alice = CreatePlayer("Alice", map);
        var bob = CreatePlayer("Bob", map);

        ChatManager.Instance.HandleBroadcastPacket(
            alice,
            BroadcastReader("sector channel", ChatType.SectorMessage));

        Assert.AreEqual(1, SentTo(alice).OfType<BroadcastPacket>().Count());
        Assert.AreEqual(0, SentTo(bob).Count, "Sector channel is out of scope — echo only.");
    }

    [TestMethod]
    public void HandleChatPacket_LocalMessage_OnGlobalWire_IsIgnored()
    {
        var alice = CreatePlayer("Alice");
        ChatManager.Instance.ListOnlineForTests = () => new[] { alice.CurrentCharacter! };

        ChatManager.Instance.HandleChatPacket(alice, ChatReader("wrong wire", ChatType.LocalMessage));

        Assert.AreEqual(0, SentTo(alice).Count);
    }
}
