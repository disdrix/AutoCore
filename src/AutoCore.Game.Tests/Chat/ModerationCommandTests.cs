using AutoCore.Database.Auth;
using AutoCore.Game.Chat;
using AutoCore.Game.Entities;
using AutoCore.Game.Inventory;
using AutoCore.Game.Tests.Fakes;
using AutoCore.Game.TNL;
using AutoCore.Utils.Logging;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using AuthAccount = AutoCore.Database.Auth.Models.Account;
using CharAccount = AutoCore.Database.Char.Models.Account;

namespace AutoCore.Game.Tests.Chat;

[TestClass]
public class ModerationCommandTests
{
    private string _dbName = null!;
    private List<OnlinePlayerSnapshot> _online = null!;
    private List<(OnlinePlayerSnapshot Target, string Reason)> _disconnects = null!;
    private InMemoryLogSink _sink = null!;

    [TestInitialize]
    public void Init()
    {
        _dbName = "mod-cmd-" + Guid.NewGuid().ToString("N");
        _online = new List<OnlinePlayerSnapshot>();
        _disconnects = new List<(OnlinePlayerSnapshot, string)>();
        _sink = new InMemoryLogSink();
        GameLog.ResetForTests();
        LogContext.ClearForTests();
        GameLog.SetSinkForTests(_sink);

        PlayerModerationService.Instance.CreateAuthContext = CreateAuthContext;
        PlayerModerationService.Instance.ListOnline = () => _online;
        PlayerModerationService.Instance.Disconnect = (snap, reason) => _disconnects.Add((snap, reason));

        using var seed = CreateAuthContext();
        seed.Database.EnsureCreated();
    }

    [TestCleanup]
    public void Cleanup()
    {
        PlayerModerationService.Instance.ResetForTests();
        GameLog.ResetForTests();
        LogContext.ClearForTests();
    }

    private AuthContext CreateAuthContext()
    {
        var options = new DbContextOptionsBuilder<AuthContext>()
            .UseInMemoryDatabase(_dbName)
            .Options;
        return new AuthContext(options);
    }

    private void SeedAuth(uint id, string username, bool locked = false)
    {
        using var ctx = CreateAuthContext();
        ctx.Accounts.Add(new AuthAccount
        {
            Id = id,
            Username = username,
            Email = $"{username}@test.local",
            Password = "x",
            Salt = "s",
            JoinDate = DateTime.UtcNow,
            Validated = true,
            Locked = locked,
            Level = 0
        });
        ctx.SaveChanges();
    }

    private static Character Gm(int gmLevel = 1)
    {
        var connection = new TNLConnection();
        connection.SetGhostFrom(true);
        connection.SetGhostTo(false);
        connection.SetNetAddress(new System.Net.IPEndPoint(System.Net.IPAddress.Loopback, 0));
        connection.Account = new CharAccount { Id = 99, Name = "admin", Level = (byte)gmLevel };

        var character = new Character();
        character.SetCoid(9900, true);
        character.AttachTestDataForTests("admin");
        character.GMLevel = (byte)gmLevel;
        character.SetOwningConnection(connection);
        character.AttachInventoryForTests(new InventoryManager());
        connection.CurrentCharacter = character;
        return character;
    }

    [TestMethod]
    public void ListPlayers_Empty_ReportsNone()
    {
        var result = ChatCommandService.Instance.Execute(Gm(), "/listplayers");
        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "no players");
    }

    [TestMethod]
    public void ListPlayers_FormatsAccountAndCharacterFields()
    {
        _online.Add(new OnlinePlayerSnapshot(7, "acctSeven", 42, "Hero"));
        _online.Add(new OnlinePlayerSnapshot(8, "acctEight", 99, "Villain"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/listplayers");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message, "acct=7");
        StringAssert.Contains(result.Message, "char=42");
        StringAssert.Contains(result.Message, "account=acctSeven");
        StringAssert.Contains(result.Message, "character=Hero");
        StringAssert.Contains(result.Message, "acct=8");
        StringAssert.Contains(result.Message, "character=Villain");
    }

    [TestMethod]
    public void Kick_ExactMatch_DisconnectsWithoutLocking()
    {
        SeedAuth(7, "bob");
        _online.Add(new OnlinePlayerSnapshot(7, "bob", 42, "BobHero"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/kick BobHero");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "kicked");
        Assert.AreEqual(1, _disconnects.Count);
        Assert.AreEqual(7u, _disconnects[0].Target.AccountId);
        StringAssert.Contains(_disconnects[0].Reason.ToLowerInvariant(), "kick");

        using var verify = CreateAuthContext();
        Assert.IsFalse(verify.Accounts.Single(a => a.Id == 7).Locked);
        Assert.IsTrue(_sink.Records.Any(r => r.EventName == "PlayerKicked"));
    }

    [TestMethod]
    public void Kick_FuzzyUnique_Works()
    {
        _online.Add(new OnlinePlayerSnapshot(1, "alice", 10, "AliceHero"));
        _online.Add(new OnlinePlayerSnapshot(2, "bob", 20, "Other"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/kick aliceh");

        Assert.IsTrue(result.Handled);
        Assert.AreEqual(1, _disconnects.Count);
        Assert.AreEqual(1u, _disconnects[0].Target.AccountId);
    }

    [TestMethod]
    public void Kick_Ambiguous_DoesNotDisconnect()
    {
        _online.Add(new OnlinePlayerSnapshot(1, "a", 10, "AliceA"));
        _online.Add(new OnlinePlayerSnapshot(2, "b", 20, "AliceB"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/kick Alice");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "ambiguous");
        Assert.AreEqual(0, _disconnects.Count);
    }

    [TestMethod]
    public void Kick_NotFound()
    {
        var result = ChatCommandService.Instance.Execute(Gm(), "/kick nobody");
        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "no player");
        Assert.AreEqual(0, _disconnects.Count);
    }

    [TestMethod]
    public void Kick_MissingArgs_Usage()
    {
        var result = ChatCommandService.Instance.Execute(Gm(), "/kick");
        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message, "Usage:");
    }

    [TestMethod]
    public void Ban_Online_LocksAndDisconnects()
    {
        SeedAuth(7, "bob");
        _online.Add(new OnlinePlayerSnapshot(7, "bob", 42, "BobHero"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/ban bob");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "ban");
        Assert.AreEqual(1, _disconnects.Count);
        StringAssert.Contains(_disconnects[0].Reason.ToLowerInvariant(), "ban");

        using var verify = CreateAuthContext();
        Assert.IsTrue(verify.Accounts.Single(a => a.Id == 7).Locked);
        Assert.IsTrue(_sink.Records.Any(r => r.EventName == "PlayerBanned"));
    }

    [TestMethod]
    public void Ban_Offline_LocksWithoutDisconnect()
    {
        SeedAuth(3, "offlineuser");

        var result = ChatCommandService.Instance.Execute(Gm(), "/ban offlineuser");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "ban");
        Assert.AreEqual(0, _disconnects.Count);

        using var verify = CreateAuthContext();
        Assert.IsTrue(verify.Accounts.Single(a => a.Id == 3).Locked);
    }

    [TestMethod]
    public void Ban_FuzzyCharacterName_Works()
    {
        SeedAuth(7, "acct");
        _online.Add(new OnlinePlayerSnapshot(7, "acct", 42, "UniqueHeroName"));

        var result = ChatCommandService.Instance.Execute(Gm(), "/ban uniquehero");

        Assert.IsTrue(result.Handled);
        Assert.AreEqual(1, _disconnects.Count);
        using var verify = CreateAuthContext();
        Assert.IsTrue(verify.Accounts.Single(a => a.Id == 7).Locked);
    }

    [TestMethod]
    public void Unban_ClearsLock()
    {
        SeedAuth(3, "banneduser", locked: true);

        var result = ChatCommandService.Instance.Execute(Gm(), "/unban banneduser");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "unban");
        using var verify = CreateAuthContext();
        Assert.IsFalse(verify.Accounts.Single(a => a.Id == 3).Locked);
        Assert.IsTrue(_sink.Records.Any(r => r.EventName == "PlayerUnbanned"));
    }

    [TestMethod]
    public void Unban_NotBanned_FriendlyMessage()
    {
        SeedAuth(3, "freeuser", locked: false);

        var result = ChatCommandService.Instance.Execute(Gm(), "/unban freeuser");

        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "not banned");
    }

    [TestMethod]
    public void Unban_NotFound()
    {
        var result = ChatCommandService.Instance.Execute(Gm(), "/unban ghost");
        Assert.IsTrue(result.Handled);
        StringAssert.Contains(result.Message.ToLowerInvariant(), "no");
    }

    [TestMethod]
    public void ListPlayers_Alias_CaseInsensitive()
    {
        var result = ChatCommandService.Instance.Execute(Gm(), "/ListPlayers");
        Assert.IsTrue(result.Handled);
    }
}
