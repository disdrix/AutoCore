using AutoCore.Game.Constants;
using AutoCore.Game.Packets.Mail;
using AutoCore.Game.Structures.Auction;
using AutoCore.Utils.Extensions;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Packets.Mail;

[TestClass]
public class AuctionPacketTests
{
    [TestMethod]
    public void AuctionListRequest_Read_CriteriaFields()
    {
        Assert.AreEqual(MailOpcode.AuctionListRequest, new AuctionListRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(2); // Index
            writer.Write((sbyte)1); // Race
            writer.Write((sbyte)2); // Class
            writer.Write((sbyte)3); // MinLevel
            writer.Write((sbyte)40); // MaxLevel
            writer.Write((sbyte)5); // ItemType
            writer.Write((sbyte)6); // ItemSubType
            writer.Write((sbyte)0); // LanguageId
            writer.Write((sbyte)1); // BrokenFilter
            writer.Write(10L); // MinValue
            writer.Write(1000L); // MaxValue
            writer.Write(55L); // CoidSeller
            writer.Write(7); // AuctionHouseFaction
            writer.WriteUtf8StringOn("Seller", 17);
            writer.WriteUtf8StringOn("Sword", 128);
            writer.Write(new byte[3]); // pad
        }

        ms.Position = 0;
        var packet = new AuctionListRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(2, packet.Index);
        Assert.AreEqual((sbyte)1, packet.Criteria.Race);
        Assert.AreEqual((sbyte)2, packet.Criteria.Class);
        Assert.AreEqual((sbyte)3, packet.Criteria.MinLevel);
        Assert.AreEqual((sbyte)40, packet.Criteria.MaxLevel);
        Assert.AreEqual((sbyte)5, packet.Criteria.ItemType);
        Assert.AreEqual((sbyte)6, packet.Criteria.ItemSubType);
        Assert.AreEqual((sbyte)0, packet.Criteria.LanguageId);
        Assert.AreEqual((sbyte)1, packet.Criteria.BrokenFilter);
        Assert.AreEqual(10L, packet.Criteria.MinValue);
        Assert.AreEqual(1000L, packet.Criteria.MaxValue);
        Assert.AreEqual(55L, packet.Criteria.CoidSeller);
        Assert.AreEqual(7, packet.Criteria.AuctionHouseFaction);
        Assert.AreEqual("Seller", packet.Criteria.SellerName);
        Assert.AreEqual("Sword", packet.Criteria.ItemName);
    }

    [TestMethod]
    public void AuctionListResponse_Write_HeaderAndItems()
    {
        Assert.AreEqual(MailOpcode.AuctionListResponse, new AuctionListResponsePacket().Opcode);

        var packet = new AuctionListResponsePacket
        {
            FullList = true,
            TotalObjs = 5,
            CurrentPage = 1,
            NumObjs = 1,
            Items =
            [
                new AuctionListItem
                {
                    MailId = 9L,
                    SenderName = "A",
                    ReceiverName = "B",
                    HighBid = 100L,
                    StartingBid = 50L,
                    Buyout = 200L,
                    AttachmentId = 300L,
                    Duration = 60
                }
            ]
        };

        using var ms = new MemoryStream(new byte[256]);
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        ms.Position = 0;
        using var reader = new BinaryReader(ms);
        Assert.IsTrue(reader.ReadBoolean());
        reader.ReadByte(); // pad
        Assert.AreEqual((ushort)5, reader.ReadUInt16());
        Assert.AreEqual((ushort)1, reader.ReadUInt16());
        Assert.AreEqual((ushort)1, reader.ReadUInt16());
        reader.ReadUInt16(); // pad
        Assert.AreEqual(9L, reader.ReadInt64());
        Assert.AreEqual("A", reader.ReadUTF8StringOn(17));
        Assert.AreEqual("B", reader.ReadUTF8StringOn(17));
        reader.ReadBytes(6);
        Assert.AreEqual(100L, reader.ReadInt64());
        Assert.AreEqual(50L, reader.ReadInt64());
        Assert.AreEqual(200L, reader.ReadInt64());
        Assert.AreEqual(300L, reader.ReadInt64());
        Assert.AreEqual(60, reader.ReadInt32());
    }

    [TestMethod]
    public void AuctionCreateRequest_Read_Fields()
    {
        Assert.AreEqual(MailOpcode.AuctionCreateRequest, new AuctionCreateRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0); // pad
            writer.Write(11L);
            writer.Write(22L);
            writer.Write(33L);
            writer.Write(120);
            writer.Write(0); // pad
        }

        ms.Position = 0;
        var packet = new AuctionCreateRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(11L, packet.AttachmentId);
        Assert.AreEqual(22L, packet.StartingBid);
        Assert.AreEqual(33L, packet.Buyout);
        Assert.AreEqual(120, packet.Duration);
    }

    [TestMethod]
    public void AuctionCreateResponse_Write_ErrorAndId()
    {
        Assert.AreEqual(MailOpcode.AuctionCreateResponse, new AuctionCreateResponsePacket().Opcode);

        var packet = new AuctionCreateResponsePacket
        {
            Error = AuctionCreateResponsePacket.CreateError.ItemNotTradable,
            AuctionId = 88L
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual((uint)AuctionCreateResponsePacket.CreateError.ItemNotTradable, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(88L, BitConverter.ToInt64(bytes, 4));
    }

    [TestMethod]
    public void AuctionCancelRequest_Read_AuctionId()
    {
        Assert.AreEqual(MailOpcode.AuctionCancelRequest, new AuctionCancelRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
            writer.Write(12345L);

        ms.Position = 0;
        var packet = new AuctionCancelRequestPacket();
        packet.Read(new BinaryReader(ms));
        Assert.AreEqual(12345L, packet.AuctionId);
    }

    [TestMethod]
    public void AuctionCancelResponse_Write_Fields()
    {
        Assert.AreEqual(MailOpcode.AuctionCancelResponse, new AuctionCancelResponsePacket().Opcode);

        var packet = new AuctionCancelResponsePacket
        {
            Error = AuctionCancelResponsePacket.CancelError.AuctionHasBid,
            AuctionId = 1L,
            CancelId = 2L
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual((uint)AuctionCancelResponsePacket.CancelError.AuctionHasBid, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(1L, BitConverter.ToInt64(bytes, 4));
        Assert.AreEqual(2L, BitConverter.ToInt64(bytes, 12));
    }

    [TestMethod]
    public void AuctionBidRequest_Read_Fields()
    {
        Assert.AreEqual(MailOpcode.AuctionBidRequest, new AuctionBidRequestPacket().Opcode);

        using var ms = new MemoryStream();
        using (var writer = new BinaryWriter(ms, System.Text.Encoding.UTF8, leaveOpen: true))
        {
            writer.Write(0);
            writer.Write(70L);
            writer.Write(80L);
        }

        ms.Position = 0;
        var packet = new AuctionBidRequestPacket();
        packet.Read(new BinaryReader(ms));

        Assert.AreEqual(70L, packet.AuctionId);
        Assert.AreEqual(80L, packet.Bid);
    }

    [TestMethod]
    public void AuctionBidResponse_Write_Fields()
    {
        Assert.AreEqual(MailOpcode.AuctionBidResponse, new AuctionBidResponsePacket().Opcode);

        var packet = new AuctionBidResponsePacket
        {
            Error = AuctionBidResponsePacket.BidError.Outbid,
            AuctionId = 9L,
            Bid = 150L
        };
        using var ms = new MemoryStream();
        using var writer = new BinaryWriter(ms);
        packet.Write(writer);

        var bytes = ms.ToArray();
        Assert.AreEqual((uint)AuctionBidResponsePacket.BidError.Outbid, BitConverter.ToUInt32(bytes, 0));
        Assert.AreEqual(9L, BitConverter.ToInt64(bytes, 4));
        Assert.AreEqual(150L, BitConverter.ToInt64(bytes, 12));
    }

    [TestMethod]
    public void AuctionListRequest_Truncated_Throws()
    {
        using var ms = new MemoryStream(new byte[4]);
        Assert.ThrowsException<EndOfStreamException>(() =>
            new AuctionListRequestPacket().Read(new BinaryReader(ms)));
    }
}
