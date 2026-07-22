using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Auth;
using AutoCore.Database.Char;
using AutoCore.Database.World;

[TestClass]
public class ConnectionStringInitTests
{
    [TestInitialize]
    public void ResetStatics()
    {
        TestHelpers.ResetAllConnectionStrings();
    }

    [TestCleanup]
    public void CleanupStatics()
    {
        TestHelpers.ResetAllConnectionStrings();
    }

    // --- AuthContext ---

    [TestMethod]
    public void Auth_InitializeConnectionString_SetsValue()
    {
        AuthContext.InitializeConnectionString("Server=localhost;Database=auth;");
        Assert.AreEqual("Server=localhost;Database=auth;", AuthContext.ConnectionString);
    }

    [TestMethod]
    public void Auth_InitializeConnectionString_NullOrEmpty_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() => AuthContext.InitializeConnectionString(null!));
        Assert.ThrowsException<ArgumentException>(() => AuthContext.InitializeConnectionString(""));
        // Auth uses ThrowIfNullOrEmpty which also rejects whitespace-only differently than Char/World.
        // Empty already covered; leave ConnectionString unset.
        Assert.AreEqual(string.Empty, AuthContext.ConnectionString);
    }

    [TestMethod]
    public void Auth_InitializeConnectionString_SecondCall_Throws()
    {
        AuthContext.InitializeConnectionString("Server=a;");
        var ex = Assert.ThrowsException<ArgumentException>(
            () => AuthContext.InitializeConnectionString("Server=b;"));
        StringAssert.Contains(ex.Message, "already set up for the AuthContext");
        Assert.AreEqual("Server=a;", AuthContext.ConnectionString);
    }

    // --- CharContext ---

    [TestMethod]
    public void Char_InitializeConnectionString_SetsValue()
    {
        CharContext.InitializeConnectionString("Server=localhost;Database=char;");
        Assert.AreEqual("Server=localhost;Database=char;", CharContext.ConnectionString);
    }

    [TestMethod]
    public void Char_InitializeConnectionString_NullOrEmpty_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() => CharContext.InitializeConnectionString(null!));
        Assert.ThrowsException<ArgumentNullException>(() => CharContext.InitializeConnectionString(""));
        Assert.IsTrue(string.IsNullOrEmpty(CharContext.ConnectionString));
    }

    [TestMethod]
    public void Char_InitializeConnectionString_SecondCall_Throws()
    {
        CharContext.InitializeConnectionString("Server=a;");
        var ex = Assert.ThrowsException<ArgumentException>(
            () => CharContext.InitializeConnectionString("Server=b;"));
        StringAssert.Contains(ex.Message, "already set up for the CharContext");
        Assert.AreEqual("Server=a;", CharContext.ConnectionString);
    }

    // --- WorldContext ---

    [TestMethod]
    public void World_InitializeConnectionString_SetsValue()
    {
        WorldContext.InitializeConnectionString("Server=localhost;Database=world;");
        Assert.AreEqual("Server=localhost;Database=world;", WorldContext.ConnectionString);
    }

    [TestMethod]
    public void World_InitializeConnectionString_NullOrEmpty_Throws()
    {
        Assert.ThrowsException<ArgumentNullException>(() => WorldContext.InitializeConnectionString(null!));
        Assert.ThrowsException<ArgumentNullException>(() => WorldContext.InitializeConnectionString(""));
        Assert.IsTrue(string.IsNullOrEmpty(WorldContext.ConnectionString));
    }

    [TestMethod]
    public void World_InitializeConnectionString_SecondCall_Throws()
    {
        WorldContext.InitializeConnectionString("Server=a;");
        var ex = Assert.ThrowsException<ArgumentException>(
            () => WorldContext.InitializeConnectionString("Server=b;"));
        StringAssert.Contains(ex.Message, "already set up for the WorldContext");
        Assert.AreEqual("Server=a;", WorldContext.ConnectionString);
    }
}
