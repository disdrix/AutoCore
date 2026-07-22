using AutoCore.Game.Structures;
using AutoCore.Game.Structures.Auction;
using AutoCore.Game.Structures.Mail;
using AutoCore.Game.Structures.Social;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Structures;

[TestClass]
public class SocialAuctionMailStructureTests
{
    [TestMethod]
    public void Enemy_PropertyAssignment()
    {
        var enemy = new Enemy
        {
            CoidCharacter = 1,
            CoidEnemyCharacter = 2,
            Level = 30,
            LastContinentId = 4,
            TimesKilled = 5,
            TimesKilledBy = 6,
            Race = 1,
            Class = 2,
            Online = true,
            Name = "Rival"
        };

        Assert.AreEqual(1L, enemy.CoidCharacter);
        Assert.AreEqual(2L, enemy.CoidEnemyCharacter);
        Assert.AreEqual(30, enemy.Level);
        Assert.AreEqual(4, enemy.LastContinentId);
        Assert.AreEqual(5, enemy.TimesKilled);
        Assert.AreEqual(6, enemy.TimesKilledBy);
        Assert.AreEqual((byte)1, enemy.Race);
        Assert.AreEqual((byte)2, enemy.Class);
        Assert.IsTrue(enemy.Online);
        Assert.AreEqual("Rival", enemy.Name);
    }

    [TestMethod]
    public void Friend_PropertyAssignment()
    {
        var friend = new Friend
        {
            CoidCharacter = 10,
            CoidFriendCharacter = 20,
            Level = 15,
            LastContinentId = 1,
            Class = 3,
            Online = false,
            Name = "Pal"
        };

        Assert.AreEqual(10L, friend.CoidCharacter);
        Assert.AreEqual(20L, friend.CoidFriendCharacter);
        Assert.AreEqual(15, friend.Level);
        Assert.AreEqual(1, friend.LastContinentId);
        Assert.AreEqual((byte)3, friend.Class);
        Assert.IsFalse(friend.Online);
        Assert.AreEqual("Pal", friend.Name);
    }

    [TestMethod]
    public void AuctionItemCriteria_PropertyAssignment()
    {
        var c = new AuctionItemCriteria
        {
            Race = 1,
            Class = 2,
            MinLevel = 3,
            MaxLevel = 40,
            ItemType = 5,
            ItemSubType = 6,
            LanguageId = 0,
            BrokenFilter = 1,
            MinValue = 10,
            MaxValue = 1000,
            CoidSeller = 55,
            AuctionHouseFaction = 7,
            SellerName = "S",
            ItemName = "I"
        };

        Assert.AreEqual((sbyte)1, c.Race);
        Assert.AreEqual((sbyte)40, c.MaxLevel);
        Assert.AreEqual(10L, c.MinValue);
        Assert.AreEqual(1000L, c.MaxValue);
        Assert.AreEqual("S", c.SellerName);
        Assert.AreEqual("I", c.ItemName);
    }

    [TestMethod]
    public void AuctionListItem_PropertyAssignment()
    {
        var item = new AuctionListItem
        {
            MailId = 1,
            SenderName = "A",
            ReceiverName = "B",
            HighBid = 10,
            StartingBid = 5,
            Buyout = 20,
            AttachmentId = 30,
            Duration = 60
        };

        Assert.AreEqual(1L, item.MailId);
        Assert.AreEqual("A", item.SenderName);
        Assert.AreEqual("B", item.ReceiverName);
        Assert.AreEqual(10L, item.HighBid);
        Assert.AreEqual(60, item.Duration);
    }

    [TestMethod]
    public void MailListItem_PropertyAssignment()
    {
        var item = new MailListItem
        {
            MailId = 9,
            Subject = "Sub",
            Message = "Msg",
            SenderName = "From",
            Money = 100,
            AttachmentId = 200,
            ExtraInfo = 1,
            TimeRemaining = 999
        };

        Assert.AreEqual(9L, item.MailId);
        Assert.AreEqual("Sub", item.Subject);
        Assert.AreEqual("Msg", item.Message);
        Assert.AreEqual("From", item.SenderName);
        Assert.AreEqual(100L, item.Money);
        Assert.AreEqual(200L, item.AttachmentId);
        Assert.AreEqual((sbyte)1, item.ExtraInfo);
        Assert.AreEqual(999L, item.TimeRemaining);
    }

    [TestMethod]
    public void Reward_PropertyAssignment()
    {
        var reward = new Reward { Level = 5, BaseAmount = 100, NumStops = 3 };
        Assert.AreEqual(5, reward.Level);
        Assert.AreEqual(100, reward.BaseAmount);
        Assert.AreEqual(3, reward.NumStops);
    }

    [TestMethod]
    public void SeaPlane_PropertyAssignment()
    {
        var plane = new SeaPlane
        {
            Coords = new Vector4(1, 2, 3, 4),
            CoordsList = [new Vector4(5, 6, 7, 8)]
        };

        Assert.AreEqual(1f, plane.Coords.X);
        Assert.AreEqual(1, plane.CoordsList.Count);
        Assert.AreEqual(5f, plane.CoordsList[0].X);
    }

    [TestMethod]
    public void TimeCurve_PropertyAssignment()
    {
        var curve = new TimeCurve { NumStops = 4, Percentage = 0.5f };
        Assert.AreEqual(4, curve.NumStops);
        Assert.AreEqual(0.5f, curve.Percentage);
    }
}
