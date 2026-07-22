using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Global;
using AutoCore.Game.Structures.Social;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Global;

[TestClass]
public class SocialAndClanPacketTests
{
    [TestMethod]
    public void GetFriendsResponse_Write_Friends()
    {
        Assert.AreEqual(GameOpcode.GetFriendsResponse, new GetFriendsResponsePacket().Opcode);

        var packet = new GetFriendsResponsePacket
        {
            Friends =
            [
                new Friend
                {
                    CoidCharacter = 1L,
                    CoidFriendCharacter = 2L,
                    Level = 10,
                    LastContinentId = 3,
                    Class = 4,
                    Online = true,
                    Name = "Buddy"
                }
            ]
        };

        using var ms = new MemoryStream(new byte[128]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.AreEqual(1, reader.ReadInt32());
        Assert.AreEqual(1L, reader.ReadInt64());
        Assert.AreEqual(2L, reader.ReadInt64());
        Assert.AreEqual(10, reader.ReadInt32());
        Assert.AreEqual(3, reader.ReadInt32());
        Assert.AreEqual((byte)4, reader.ReadByte());
        Assert.IsTrue(reader.ReadBoolean());
        Assert.AreEqual("Buddy", reader.ReadUTF8StringOn(17));
    }

    [TestMethod]
    public void GetFriendsResponse_Write_TooMany_Throws()
    {
        var packet = new GetFriendsResponsePacket();
        for (var i = 0; i < 21; i++)
            packet.Friends.Add(new Friend { Name = "x" });

        using var ms = new MemoryStream(new byte[4096]);
        using var writer = new BinaryWriter(ms);
        Assert.ThrowsException<InvalidOperationException>(() => packet.Write(writer));
    }

    [TestMethod]
    public void GetEnemiesResponse_Write_Enemies()
    {
        Assert.AreEqual(GameOpcode.GetEnemiesResponse, new GetEnemiesResponsePacket().Opcode);

        var packet = new GetEnemiesResponsePacket
        {
            Enemies =
            [
                new Enemy
                {
                    CoidCharacter = 5L,
                    CoidEnemyCharacter = 6L,
                    Level = 20,
                    LastContinentId = 1,
                    TimesKilled = 2,
                    TimesKilledBy = 3,
                    Race = 1,
                    Class = 2,
                    Online = false,
                    Name = "Foe"
                }
            ]
        };

        using var ms = new MemoryStream(new byte[128]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.AreEqual(1, reader.ReadInt32());
        Assert.AreEqual(5L, reader.ReadInt64());
        Assert.AreEqual(6L, reader.ReadInt64());
        Assert.AreEqual(20, reader.ReadInt32());
        Assert.AreEqual(1, reader.ReadInt32());
        Assert.AreEqual(2, reader.ReadInt32());
        Assert.AreEqual(3, reader.ReadInt32());
        Assert.AreEqual((byte)1, reader.ReadByte());
        Assert.AreEqual((byte)2, reader.ReadByte());
        Assert.IsFalse(reader.ReadBoolean());
        Assert.AreEqual("Foe", reader.ReadUTF8StringOn(17));
    }

    [TestMethod]
    public void GetEnemiesResponse_Write_TooMany_Throws()
    {
        var packet = new GetEnemiesResponsePacket();
        for (var i = 0; i < 21; i++)
            packet.Enemies.Add(new Enemy { Name = "x" });

        using var ms = new MemoryStream(new byte[4096]);
        using var writer = new BinaryWriter(ms);
        Assert.ThrowsException<InvalidOperationException>(() => packet.Write(writer));
    }

    [TestMethod]
    public void ClanUpdatePacket_Read_AllFields()
    {
        Assert.AreEqual(GameOpcode.ClanUpdate, new ClanUpdatePacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(99);
            writer.WriteUtf8StringOn("ClanName", 51);
            writer.WriteUtf8StringOn("MOTD here", 251);
            writer.WriteUtf8StringOn("R1", 51);
            writer.WriteUtf8StringOn("R2", 51);
            writer.WriteUtf8StringOn("R3", 51);
            writer.Write((byte)0); // pad
            writer.Write(100);
            writer.Write(200);
            writer.Write(555L);
            writer.Write(12);
            writer.Write(0); // pad
        }

        ms.Position = 0;
        var packet = new ClanUpdatePacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(99, packet.ClanId);
        Assert.AreEqual("ClanName", packet.ClanName);
        Assert.AreEqual("MOTD here", packet.ClanMOTD);
        Assert.AreEqual("R1", packet.RankOne);
        Assert.AreEqual("R2", packet.RankTwo);
        Assert.AreEqual("R3", packet.RankThree);
        Assert.AreEqual(100, packet.MonthlyDues);
        Assert.AreEqual(200, packet.MonthlyUpkeep);
        Assert.AreEqual(555L, packet.ClanOwnerCoid);
        Assert.AreEqual(12, packet.NumMembers);
    }

    [TestMethod]
    public void ClanUpdateResponse_Write_Result()
    {
        Assert.AreEqual(GameOpcode.ClanUpdateResponse, new ClanUpdateResponsePacket(ClanUpdateResponse.Ok).Opcode);

        var packet = new ClanUpdateResponsePacket(ClanUpdateResponse.BadMOTD);
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        Assert.AreEqual((int)ClanUpdateResponse.BadMOTD, BitConverter.ToInt32(ms.ToArray(), 0));
    }

    [TestMethod]
    public void RequestClanName_Read_CharacterCoid()
    {
        Assert.AreEqual(GameOpcode.RequestClanName, new RequestClanNamePacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0);
            writer.Write(777L);
        }

        ms.Position = 0;
        var packet = new RequestClanNamePacket();
        packet.Read(new BinaryReader(ms));
        Assert.AreEqual(777L, packet.CharacterCoid);
    }

    [TestMethod]
    public void RequestClanNameResponse_Write_Fields()
    {
        Assert.AreEqual(GameOpcode.RequestClanNameResponse, new RequestClanNameResponsePacket(1, "x").Opcode);

        var packet = new RequestClanNameResponsePacket(888L, "MyClan");
        using var ms = new MemoryStream(new byte[128]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        reader.ReadInt32(); // pad
        Assert.AreEqual(888L, reader.ReadInt64());
        Assert.AreEqual("MyClan", reader.ReadUTF8StringOn(52));
    }
}
