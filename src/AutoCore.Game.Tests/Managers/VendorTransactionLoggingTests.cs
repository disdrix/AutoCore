using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers;

using AutoCore.Database.World.Models;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Inventory;
using AutoCore.Game.Map;
using AutoCore.Game.Managers;
using AutoCore.Game.Packets;
using AutoCore.Game.Packets.Sector;
using AutoCore.Game.Structures;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.TNL;
using AutoCore.Utils.Logging;

/// <summary>
/// Phase 3D: vendor buy/sell flows emit TX-scoped structured audit/reject events.
/// </summary>
[TestClass]
public class VendorTransactionLoggingTests
{
    private const int ContId = 8822;
    private const long StoreCoid = 9820;
    private const int StockCbid = 2663;
    private const long BuyUnitPrice = 400;

    private readonly List<BasePacket> _sent = new();
    private InMemoryLogSink _sink = null!;

    [TestInitialize]
    public void SetUp()
    {
        _sent.Clear();
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sink = new InMemoryLogSink();
        GameLog.SetSinkForTests(_sink);

        TNLConnection.TestPacketSink = (_, packet) => _sent.Add(packet);
        VendorStoreService.ResetSessionsForTests();
        VendorStoreService.TestBuyPriceResolver = cbid => cbid == StockCbid ? BuyUnitPrice : 0;
        VendorStoreService.TestBuyCatalogResolver = cbid =>
            cbid == StockCbid
                ? new InventoryCatalogEntry(cbid, CloneBaseObjectType.Item, "stock-" + cbid)
                : null;
        VendorStoreService.TestItemCreator = new TestBuyItemCreator();
        VendorStoreService.TestSellPriceResolver = cbid => cbid == StockCbid ? 100 : 0;
    }

    [TestCleanup]
    public void TearDown()
    {
        TNLConnection.TestPacketSink = null;
        VendorStoreService.ResetSessionsForTests();
        VendorStoreService.TestBuyPriceResolver = null;
        VendorStoreService.TestBuyCatalogResolver = null;
        VendorStoreService.TestItemCreator = null;
        VendorStoreService.TestSellPriceResolver = null;
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        _sent.Clear();
    }

    [TestMethod]
    public void Buy_Success_EmitsStartedCompleted_WithSharedTransactionId_AndCurrencyAudit()
    {
        var (conn, character, map) = CreatePlayer(credits: 50_000);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);
        var slotCoid = VendorStoreService.GetStockSessionForTests(character.ObjectId.Coid).Keys.First();
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(slotCoid, true),
            StoreCoid = StoreCoid,
            IsBuy = true,
            Quantity = 1,
        });

        var started = _sink.Single("VendorPurchaseStarted");
        var completed = _sink.Single("VendorPurchaseCompleted");
        Assert.IsTrue(started.Audit);
        Assert.IsTrue(completed.Audit);

        var tx = started.GetProperty("TransactionId") as string;
        Assert.IsFalse(string.IsNullOrEmpty(tx));
        Assert.IsTrue(tx!.StartsWith("TX-", StringComparison.Ordinal));
        Assert.AreEqual(tx, completed.GetProperty("TransactionId"));

        var currency = _sink.Single("CurrencyChanged");
        Assert.AreEqual(tx, currency.GetProperty("TransactionId"));
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "VendorPurchaseRejected"));
    }

    [TestMethod]
    public void Buy_InsufficientCredits_EmitsRejected_WithReason_NoCurrencyChange()
    {
        var (conn, character, map) = CreatePlayer(credits: 1);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);
        var slotCoid = VendorStoreService.GetStockSessionForTests(character.ObjectId.Coid).Keys.First();
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(slotCoid, true),
            StoreCoid = StoreCoid,
            IsBuy = true,
            Quantity = 1,
        });

        var rejected = _sink.Single("VendorPurchaseRejected");
        Assert.AreEqual("ECO-001", rejected.GetProperty("ErrorCode"));
        Assert.AreEqual("InsufficientCredits", rejected.GetProperty("Reason"));
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "CurrencyChanged"));
        Assert.AreEqual(0, _sink.Records.Count(r => r.EventName == "VendorPurchaseCompleted"));
    }

    [TestMethod]
    public void Buy_UnknownItem_EmitsRejected_UnknownItem()
    {
        var (conn, character, map) = CreatePlayer(credits: 10_000);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(999999, true),
            IsBuy = true,
            Quantity = 1,
        });

        Assert.AreEqual("UnknownItem", _sink.Single("VendorPurchaseRejected").GetProperty("Reason"));
    }

    [TestMethod]
    public void Buy_NoOpenSession_EmitsRejected_NoSession()
    {
        var (conn, character, map) = CreatePlayer(credits: 10_000);
        PlaceStore(map, StoreCoid, StockCbid);
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(StockCbid, false),
            IsBuy = true,
            Quantity = 1,
        });

        Assert.AreEqual("NoSession", _sink.Single("VendorPurchaseRejected").GetProperty("Reason"));
    }

    [TestMethod]
    public void Sell_Success_EmitsSaleCompleted_WithTransactionId()
    {
        var (conn, character, map) = CreatePlayer(credits: 0);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);

        var itemCoid = 30001L;
        character.Inventory.RestoreCargoWithoutCreate(
            new CharacterInventoryItem(StockCbid, CloneBaseObjectType.Item, "sell-me", itemCoid, 0, 0, 1),
            character.ObjectId.Coid);
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(itemCoid, true),
            StoreCoid = StoreCoid,
            IsBuy = false,
            Quantity = 1,
        });

        var completed = _sink.Single("VendorSaleCompleted");
        Assert.IsTrue(completed.Audit);
        var tx = completed.GetProperty("TransactionId") as string;
        Assert.IsTrue(tx!.StartsWith("TX-", StringComparison.Ordinal));
        Assert.AreEqual(tx, _sink.Single("CurrencyChanged").GetProperty("TransactionId"));
    }

    [TestMethod]
    public void Sell_MissingItem_EmitsSaleRejected()
    {
        var (conn, character, map) = CreatePlayer(credits: 0);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(404404, true),
            IsBuy = false,
            Quantity = 1,
        });

        var rejected = _sink.Single("VendorSaleRejected");
        Assert.AreEqual("ECO-002", rejected.GetProperty("ErrorCode"));
        Assert.AreEqual("UnknownItem", rejected.GetProperty("Reason"));
    }

    [TestMethod]
    public void Buyback_Success_EmitsCompleted_WithBuybackTrue()
    {
        var (conn, character, map) = CreatePlayer(credits: 50_000);
        PlaceStore(map, StoreCoid, StockCbid);
        VendorStoreService.NoteOpened(character, StoreCoid, conn);

        var itemCoid = 30002L;
        character.Inventory.RestoreCargoWithoutCreate(
            new CharacterInventoryItem(StockCbid, CloneBaseObjectType.Item, "sell-me", itemCoid, 0, 0, 1),
            character.ObjectId.Coid);

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(itemCoid, true),
            StoreCoid = StoreCoid,
            IsBuy = false,
            Quantity = 1,
        });
        _sink.Clear();

        VendorStoreService.HandleTransaction(conn, new StoreTransactionRequestPacket
        {
            Item = new TFID(itemCoid, true),
            StoreCoid = StoreCoid,
            IsBuy = true,
            Quantity = 1,
        });

        var completed = _sink.Single("VendorPurchaseCompleted");
        Assert.AreEqual(true, completed.GetProperty("Buyback"));
    }

    static void PlaceStore(SectorMap map, long storeCoid, params int[] cbids)
    {
        var tpl = new StoreTemplate
        {
            COID = (int)storeCoid,
            Name = "test-store",
        };
        foreach (var cbid in cbids)
        {
            tpl.Items.Add(new StoreTemplate.ItemType
            {
                Type = 52,
                CBID = cbid,
                Unlimited = true,
                Value = (int)BuyUnitPrice,
            });
        }

        while (tpl.Items.Count < 10)
            tpl.Items.Add(new StoreTemplate.ItemType());

        map.MapData.Templates[storeCoid] = tpl;

        var store = new GraphicsObject(GraphicsObjectType.GraphicsPhysics);
        store.SetCoid(storeCoid, false);
        store.Position = new Vector3(0, 0, 0);
        store.SetMap(map);
    }

    private sealed class TestBuyItemCreator : IInventoryItemCreator
    {
        public InventoryItemCreateResult Create(InventoryCatalogEntry entry, long coid, byte x, byte y)
        {
            var packet = new CreateSimpleObjectPacket
            {
                CBID = entry.Cbid,
                ObjectId = new TFID(coid, true),
                IsInInventory = true,
                Quantity = 1,
                InventoryPositionX = x,
                InventoryPositionY = y,
                IsIdentified = true,
                Scale = 1f,
            };
            return InventoryItemCreateResult.Success(packet, entry.DisplayName);
        }
    }

    static (TNLConnection Conn, Character Character, SectorMap Map) CreatePlayer(long credits)
    {
        var map = SectorMap.CreateForTests(new ContinentObject
        {
            Id = ContId,
            MapFileName = "t_buy_log",
            DisplayName = "t",
            IsPersistent = true,
            IsTown = true,
        }, new Vector4());
        map.LocalCoidCounter = 20000;

        var conn = new TNLConnection();
        conn.SetGhostFrom(true);
        conn.SetGhostTo(false);

        var character = new Character();
        character.SetCoid(18461, true);
        character.AttachTestDataForTests("BuyerLog");
        character.SetCredits(credits);
        character.SetOwningConnection(conn);
        conn.CurrentCharacter = character;
        character.AttachInventoryForTests(new InventoryManager());

        var vehicle = new Vehicle();
        vehicle.SetCoid(18462, true);
        vehicle.Position = new Vector3(0, 0, 0);
        character.SetCurrentVehicleForTests(vehicle);

        character.SetMap(map);
        vehicle.SetMap(map);
        return (conn, character, map);
    }
}
