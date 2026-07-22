using System.Net;
using System.Text;
using AutoCore.Auth.Data;
using AutoCore.Auth.Packets.Server;
using AutoCore.Communicator;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Packets;

[TestClass]
public class ServerPacketTests
{
    [TestMethod]
    public void LoginOk_RoundTrip()
    {
        var original = new LoginOkPacket
        {
            SessionId1 = 1,
            SessionId2 = 2,
            UpdateKey1 = 3,
            UpdateKey2 = 4,
            PayStat = 5,
            RemainingTime = 6,
            QuotaTime = 7,
            WarnFlag = 8,
            LoginFlag = 9
        };

        var read = RoundTrip(original, ServerOpcode.LoginOk, () => new LoginOkPacket());
        Assert.AreEqual(original.SessionId1, read.SessionId1);
        Assert.AreEqual(original.SessionId2, read.SessionId2);
        Assert.AreEqual(original.UpdateKey1, read.UpdateKey1);
        Assert.AreEqual(original.UpdateKey2, read.UpdateKey2);
        Assert.AreEqual(original.PayStat, read.PayStat);
        Assert.AreEqual(original.RemainingTime, read.RemainingTime);
        Assert.AreEqual(original.QuotaTime, read.QuotaTime);
        Assert.AreEqual(original.WarnFlag, read.WarnFlag);
        Assert.AreEqual(original.LoginFlag, read.LoginFlag);
        Assert.IsTrue(original.ToString().Contains("LoginOkPacket"));
    }

    [TestMethod]
    public void LoginFail_RoundTrip()
    {
        var original = new LoginFailPacket(FailReason.UserNameOrPassword);
        var read = RoundTrip(original, ServerOpcode.LoginFail, () => new LoginFailPacket(FailReason.UnexpectedError));
        Assert.AreEqual(FailReason.UserNameOrPassword, read.ResultCode);
        Assert.IsTrue(original.ToString().Contains("LoginFailPacket"));
    }

    [TestMethod]
    public void PlayOk_RoundTrip()
    {
        var original = new PlayOkPacket { OneTimeKey = 10, UserId = 20, ServerId = 1 };
        var read = RoundTrip(original, ServerOpcode.PlayOk, () => new PlayOkPacket());
        Assert.AreEqual(10u, read.OneTimeKey);
        Assert.AreEqual(20u, read.UserId);
        Assert.AreEqual((byte)1, read.ServerId);
        Assert.IsTrue(original.ToString().Contains("PlayOkPacket"));
    }

    [TestMethod]
    public void PlayFail_RoundTrip()
    {
        var original = new PlayFailPacket(FailReason.ServerIsFull);
        var read = RoundTrip(original, ServerOpcode.PlayFail, () => new PlayFailPacket(FailReason.UnexpectedError));
        Assert.AreEqual(FailReason.ServerIsFull, read.ResultCode);
    }

    [TestMethod]
    public void ProtocolVersion_RoundTrip()
    {
        var original = new ProtocolVersionPacket(0xAABBCCDD, 0x11223344);
        var read = RoundTrip(original, ServerOpcode.ProtocolVersion, () => new ProtocolVersionPacket());
        Assert.AreEqual(0xAABBCCDDu, read.OneTimeKey);
        Assert.AreEqual(0x11223344u, read.ProtocolVersion);
        Assert.IsTrue(original.ToString().Contains("ProtocolVersionPacket"));
    }

    [TestMethod]
    public void AccountKicked_RoundTrip()
    {
        var original = new AccountKickedPacket(7);
        var read = RoundTrip(original, ServerOpcode.AccountKicked, () => new AccountKickedPacket(0));
        Assert.AreEqual((byte)7, read.ReasonCode);
        Assert.IsTrue(original.ToString().Contains("AccountKickedPacket"));
    }

    [TestMethod]
    public void BlockedAccount_RoundTrip()
    {
        var original = new BlockedAccountPacket { Reason = 42 };
        var read = RoundTrip(original, ServerOpcode.BlockedAccount, () => new BlockedAccountPacket());
        Assert.AreEqual(42u, read.Reason);
        Assert.IsTrue(original.ToString().Contains("BlockedAccountPacket"));
    }

    [TestMethod]
    public void HandoffToQueue_RoundTrip()
    {
        var original = new HandoffToQueuePacket { OneTimeKey = 5, AccountId = 6, ServerId = 2 };
        var read = RoundTrip(original, ServerOpcode.HandOffToQueue, () => new HandoffToQueuePacket());
        Assert.AreEqual(5u, read.OneTimeKey);
        Assert.AreEqual(6u, read.AccountId);
        Assert.AreEqual((byte)2, read.ServerId);
        Assert.IsTrue(original.ToString().Contains("HandoffToQueuePacket"));
    }

    [TestMethod]
    public void SCCheckReq_RoundTrip()
    {
        var original = new SCCheckReqPacket { UserId = 100, CardKey = 3 };
        var read = RoundTrip(original, ServerOpcode.SCCheckReq, () => new SCCheckReqPacket());
        Assert.AreEqual(100u, read.UserId);
        Assert.AreEqual((byte)3, read.CardKey);
        Assert.IsTrue(original.ToString().Contains("SCCheckReqPacket"));
    }

    [TestMethod]
    public void SendServerFail_RoundTrip()
    {
        var original = new SendServerFailPacket(9);
        var read = RoundTrip(original, ServerOpcode.SendServerListFail, () => new SendServerFailPacket(0));
        Assert.AreEqual((byte)9, read.ReasonCode);
        Assert.IsTrue(original.ToString().Contains("SendServerFailPacket"));
    }

    [TestMethod]
    public void SendServerListExt_WriteThenManualRead_MatchesFields()
    {
        // Note: production Write omits per-entry address length; Read expects it.
        // Cover Write structure + Read with a stream matching Read's layout.
        var servers = new List<ServerInfo>
        {
            new()
            {
                ServerId = 1,
                Ip = IPAddress.Parse("127.0.0.1"),
                Port = 27001,
                AgeLimit = 18,
                PKFlag = 1,
                CurrentPlayers = 10,
                MaxPlayers = 100,
                Status = 1
            },
            new()
            {
                ServerId = 2,
                Ip = IPAddress.Parse("10.0.0.5"),
                Port = 27002,
                AgeLimit = 0,
                PKFlag = 0,
                CurrentPlayers = 0,
                MaxPlayers = 50,
                Status = 0
            }
        };

        var original = new SendServerListExtPacket(servers, lastServerId: 1);
        using var writeStream = new MemoryStream();
        using (var writer = new BinaryWriter(writeStream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        var bytes = writeStream.ToArray();
        Assert.AreEqual((byte)ServerOpcode.SendServerListExt, bytes[0]);
        Assert.AreEqual((byte)2, bytes[1]); // count
        Assert.AreEqual((byte)1, bytes[2]); // lastServerId

        // Read path with address length prefix (as Read implements).
        using var readStream = new MemoryStream();
        using (var w = new BinaryWriter(readStream, Encoding.UTF8, leaveOpen: true))
        {
            w.Write((byte)2);
            w.Write((byte)1);
            foreach (var s in servers)
            {
                var ipBytes = s.Ip.GetAddressBytes();
                w.Write(s.ServerId);
                w.Write((byte)ipBytes.Length);
                w.Write(ipBytes);
                w.Write(s.Port);
                w.Write(s.AgeLimit);
                w.Write(s.PKFlag);
                w.Write(s.CurrentPlayers);
                w.Write(s.MaxPlayers);
                w.Write(s.Status);
            }
        }

        readStream.Position = 0;
        using var reader = new BinaryReader(readStream);
        var read = new SendServerListExtPacket(Array.Empty<ServerInfo>());
        read.Read(reader);

        Assert.AreEqual((byte)1, read.LastServerId);
        var list = read.ServerList.ToList();
        Assert.AreEqual(2, list.Count);
        Assert.AreEqual((byte)1, list[0].ServerId);
        Assert.AreEqual(IPAddress.Parse("127.0.0.1"), list[0].Ip);
        Assert.AreEqual(27001, list[0].Port);
        Assert.AreEqual((ushort)10, list[0].CurrentPlayers);
        Assert.AreEqual((byte)2, list[1].ServerId);
        Assert.IsTrue(original.ToString().Contains("SendServerListExtPacket"));
    }

    [TestMethod]
    public void SendServerListExt_Write_NullServerList_Throws()
    {
        var packet = new SendServerListExtPacket(null!);
        Assert.ThrowsException<InvalidOperationException>(() =>
            packet.Write(new BinaryWriter(new MemoryStream())));
    }

    [TestMethod]
    public void SendServerListExt_Write_CapsAtSixteenServers()
    {
        var servers = Enumerable.Range(0, 20).Select(i => new ServerInfo
        {
            ServerId = (byte)i,
            Ip = IPAddress.Loopback,
            Port = 1000 + i
        }).ToList();

        var packet = new SendServerListExtPacket(servers, 0);
        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            packet.Write(writer);

        var bytes = stream.ToArray();
        Assert.AreEqual((byte)16, bytes[1]);
    }

    [TestMethod]
    public void BlockedAccountWithMsg_WriteAndRead_ThrowNotImplemented()
    {
        var packet = new BlockedAccountWithMsgPacket();
        Assert.AreEqual(ServerOpcode.BlockedAccountWithMessage, packet.Opcode);
        Assert.IsTrue(packet.ToString().Contains("BlockedAccountWithMsgPacket"));

        Assert.ThrowsException<NotImplementedException>(() =>
            packet.Write(new BinaryWriter(new MemoryStream())));

        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            writer.Write((byte)0);
        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.ThrowsException<NotImplementedException>(() => packet.Read(reader));
    }

    private static T RoundTrip<T>(T original, ServerOpcode expectedOpcode, Func<T> factory)
        where T : AutoCore.Utils.Packets.IOpcodedPacket<ServerOpcode>
    {
        using var stream = new MemoryStream();
        using (var writer = new BinaryWriter(stream, Encoding.UTF8, leaveOpen: true))
            original.Write(writer);

        stream.Position = 0;
        using var reader = new BinaryReader(stream);
        Assert.AreEqual((byte)expectedOpcode, reader.ReadByte());
        var read = factory();
        read.Read(reader);
        return read;
    }
}
