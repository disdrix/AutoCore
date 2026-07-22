using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Login;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Login;

[TestClass]
public class LoginNewCharacterPacketTests
{
    [TestMethod]
    public void Opcode_IsLoginNewCharacter()
    {
        Assert.AreEqual(GameOpcode.LoginNewCharacter, new LoginNewCharacterPacket().Opcode);
    }

    [TestMethod]
    public void Read_PopulatesAllCharacterAndVehicleFields()
    {
        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(1001); // CBID
            writer.WriteUtf8StringOn("AccountName", 33);
            writer.WriteUtf8StringOn("CharName", 51);
            writer.Write(11); // HeadId
            writer.Write(12); // BodyId
            writer.Write(13); // HeadDetail1
            writer.Write(14); // HeadDetail2
            writer.Write(15); // HelmetId
            writer.Write(16); // EyesId
            writer.Write(17); // MouthId
            writer.Write(18); // HairId
            writer.Write(0x11111111u); // PrimaryColor
            writer.Write(0x22222222u); // SecondaryColor
            writer.Write(0x33333333u); // EyesColor
            writer.Write(0x44444444u); // HairColor
            writer.Write(0x55555555u); // SkinColor
            writer.Write(0x66666666u); // SpecialityColor
            writer.Write(3); // ShardId
            writer.Write(0xAAAAu); // VehiclePrimaryColor
            writer.Write(0xBBBBu); // VehicleSecondaryColor
            writer.Write((byte)7); // VehicleTrim
            writer.Write(new byte[3]); // pad
            writer.Write(1.25f); // ScaleOffset
            writer.Write(2002); // WheelsetCBID
            writer.WriteUtf8StringOn("MyRide", 33);
        }

        ms.Position = 0;
        var packet = new LoginNewCharacterPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(1001, packet.CBID);
        Assert.AreEqual("AccountName", packet.PlayerName);
        Assert.AreEqual("CharName", packet.CharacterName);
        Assert.AreEqual(11, packet.HeadId);
        Assert.AreEqual(12, packet.BodyId);
        Assert.AreEqual(13, packet.HeadDetail1);
        Assert.AreEqual(14, packet.HeadDetail2);
        Assert.AreEqual(15, packet.HelmetId);
        Assert.AreEqual(16, packet.EyesId);
        Assert.AreEqual(17, packet.MouthId);
        Assert.AreEqual(18, packet.HairId);
        Assert.AreEqual(0x11111111u, packet.PrimaryColor);
        Assert.AreEqual(0x22222222u, packet.SecondaryColor);
        Assert.AreEqual(0x33333333u, packet.EyesColor);
        Assert.AreEqual(0x44444444u, packet.HairColor);
        Assert.AreEqual(0x55555555u, packet.SkinColor);
        Assert.AreEqual(0x66666666u, packet.SpecialityColor);
        Assert.AreEqual(3, packet.ShardId);
        Assert.AreEqual(0xAAAAu, packet.VehiclePrimaryColor);
        Assert.AreEqual(0xBBBBu, packet.VehicleSecondaryColor);
        Assert.AreEqual((byte)7, packet.VehicleTrim);
        Assert.AreEqual(1.25f, packet.ScaleOffset);
        Assert.AreEqual(2002, packet.WheelsetCBID);
        Assert.AreEqual("MyRide", packet.VehicleName);
    }

    [TestMethod]
    public void Read_TruncatedBuffer_Throws()
    {
        using var ms = new MemoryStream(new byte[20]);
        var packet = new LoginNewCharacterPacket();
        Assert.ThrowsException<EndOfStreamException>(() => packet.Read(new BinaryReader(ms)));
    }
}
