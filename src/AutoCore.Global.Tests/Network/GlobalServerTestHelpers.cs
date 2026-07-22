using System.Net;
using System.Reflection;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Global.Tests.Network;

using AutoCore.Global.Config;
using AutoCore.Global.Network;
using AutoCore.Utils.Commands;

internal static class GlobalServerTestHelpers
{
    /// <summary>
    /// Builds a config safe for Setup without claiming production ports.
    /// Port 0 binds an ephemeral UDP socket via TNL (not 26880).
    /// </summary>
    public static GlobalConfig CreateSetupConfig(
        int gamePort = 0,
        string publicAddress = "127.0.0.1",
        bool allowVersionMismatch = true,
        int expectedVersion = 0,
        string communicatorAddress = "127.0.0.1",
        int communicatorPort = 2107)
    {
        return new GlobalConfig
        {
            CommunicatorAddress = communicatorAddress,
            CommunicatorPort = communicatorPort,
            CharDatabaseConnectionString = "Server=localhost;Database=char;",
            WorldDatabaseConnectionString = "Server=localhost;Database=world;",
            GamePath = @"C:\Games\AutoAssault",
            GameConfig = new GameConfig
            {
                PublicAddress = publicAddress,
                Port = gamePort,
                AllowVersionMismatch = allowVersionMismatch,
                ExpectedVersion = expectedVersion,
                AllowMissingCBID = true
            },
            ServerInfoConfig = new ServerInfoConfig
            {
                Id = 7,
                Password = "unit-test-password",
                AgeLimit = 13,
                PKFlag = 1,
                MaxPlayers = 250
            }
        };
    }

    public static GlobalServer CreateServer()
    {
        // Constructor registers "exit"; safe to overwrite static CommandProcessor entry.
        return new GlobalServer();
    }

    public static void SafeShutdown(GlobalServer server)
    {
        try
        {
            server.Shutdown();
        }
        catch
        {
            // Best-effort cleanup for tests; production Shutdown is defensive after seam.
        }

        GC.SuppressFinalize(server);
        CommandProcessor.RemoveCommand("global.exit");
        CommandProcessor.RemoveCommand("exit");
    }

    public static object? InvokePrivate(object target, string methodName, params object?[] args)
    {
        var method = target.GetType().GetMethod(
            methodName,
            BindingFlags.Instance | BindingFlags.NonPublic | BindingFlags.Public);

        Assert.IsNotNull(method, $"Expected method '{methodName}' on {target.GetType().Name}.");
        return method!.Invoke(target, args);
    }

    public static Dictionary<string, Action<string[]>> GetRegisteredCommands()
    {
        var field = typeof(CommandProcessor).GetField(
            "Commands",
            BindingFlags.Static | BindingFlags.NonPublic);

        Assert.IsNotNull(field, "CommandProcessor.Commands field must exist.");
        var value = field!.GetValue(null) as Dictionary<string, Action<string[]>>;
        Assert.IsNotNull(value);
        return value!;
    }

    public static void AssertPublicAddress(GlobalServer server, string expected)
    {
        Assert.AreEqual(IPAddress.Parse(expected), server.PublicAddress);
    }
}
