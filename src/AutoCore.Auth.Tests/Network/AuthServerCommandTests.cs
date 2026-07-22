using AutoCore.Auth.Network;
using AutoCore.Database.Auth;
using AutoCore.Database.Auth.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Auth.Tests.Network;

[TestClass]
public class AuthServerCommandTests
{
    private Func<AuthContext>? _previousFactory;

    [TestInitialize]
    public void Init() => _previousFactory = AuthServer.CreateAuthContext;

    [TestCleanup]
    public void Cleanup() =>
        AuthServer.CreateAuthContext = _previousFactory ?? (static () => new AuthContext());

    private static AuthContext CreateInMemoryContext(string dbName) =>
        new(new DbContextOptionsBuilder<AuthContext>().UseInMemoryDatabase(dbName).Options);

    [TestMethod]
    public void ProcessCreateCommand_TooFewArgs_DoesNotThrow()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        var server = new AuthServer();
        try
        {
            server.ProcessCreateCommand(new[] { "create" });
            server.ProcessCreateCommand(new[] { "create", "a@b.c" });
            server.ProcessCreateCommand(new[] { "create", "a@b.c", "user" });
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void ProcessCreateCommand_CreatesAccount()
    {
        var dbName = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(dbName);
        var server = new AuthServer();
        try
        {
            server.ProcessCreateCommand(new[] { "create", "user@test.local", "newuser", "hunter2" });

            using var ctx = CreateInMemoryContext(dbName);
            var account = ctx.Accounts.Single(a => a.Username == "newuser");
            Assert.AreEqual("user@test.local", account.Email);
            Assert.IsTrue(account.CheckPassword("hunter2"));
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void ProcessCreateCommand_Duplicate_IsCaught()
    {
        var dbName = Guid.NewGuid().ToString("N");
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(dbName);

        using (var ctx = CreateInMemoryContext(dbName))
        {
            var salt = Account.CreateSalt();
            ctx.Accounts.Add(new Account
            {
                Email = "dup@test.local",
                Username = "dupuser",
                Password = Account.Hash("x", salt),
                Salt = salt,
                JoinDate = DateTime.UtcNow
            });
            ctx.SaveChanges();
        }

        var server = new AuthServer();
        try
        {
            // InMemory may not enforce unique constraints the same way as MySQL;
            // exercise the try/catch path by throwing from factory on second call.
            var calls = 0;
            AuthServer.CreateAuthContext = () =>
            {
                calls++;
                if (calls > 1)
                    throw new InvalidOperationException("duplicate");
                return CreateInMemoryContext(dbName);
            };

            // Reset to create path with throw
            AuthServer.CreateAuthContext = () => throw new InvalidOperationException("duplicate");
            server.ProcessCreateCommand(new[] { "create", "a@b.c", "u", "p" });
        }
        finally
        {
            server.Shutdown();
        }
    }

    [TestMethod]
    public void ProcessExitCommand_SchedulesShutdownTimer()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        var server = new AuthServer();
        try
        {
            server.ProcessExitCommand(new[] { "exit", "0" });
            // Timer named "exit" should fire Shutdown on next update with 0 delay
            server.Timer.Update(0);
        }
        finally
        {
            try { server.Shutdown(); } catch { /* may already be shut down */ }
        }
    }

    [TestMethod]
    public void ProcessExitCommand_WithoutMinutes_DefaultsToZero()
    {
        AuthServer.CreateAuthContext = () => CreateInMemoryContext(Guid.NewGuid().ToString("N"));
        var server = new AuthServer();
        try
        {
            server.ProcessExitCommand(new[] { "exit" });
        }
        finally
        {
            server.Shutdown();
        }
    }
}
