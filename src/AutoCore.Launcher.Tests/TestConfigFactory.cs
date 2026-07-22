namespace AutoCore.Launcher.Tests;

using AutoCore.Auth.Config;
using AutoCore.Global.Config;
using AutoCore.Sector.Config;
using GlobalGameConfig = AutoCore.Global.Config.GameConfig;
using SectorGameConfig = AutoCore.Sector.Config.GameConfig;

internal static class TestConfigFactory
{
    public const string ExistingGamePath = @"C:\AutoCore\TestGamePath";

    public static AuthConfig CreateValidAuth() => new()
    {
        AuthDatabaseConnectionString = "Server=localhost;Port=3306;Database=autocore_auth;Uid=test;Password=test",
        AuthSocketPort = 2106,
        CommunicatorPort = 2107,
    };

    public static GlobalConfig CreateValidGlobal(string? gamePath = ExistingGamePath) => new()
    {
        CharDatabaseConnectionString = "Server=localhost;Port=3306;Database=autocore_char;Uid=test;Password=test",
        WorldDatabaseConnectionString = "Server=localhost;Port=3306;Database=autocore_world;Uid=test;Password=test",
        CommunicatorAddress = "127.0.0.1",
        CommunicatorPort = 2107,
        GamePath = gamePath ?? string.Empty,
        GameConfig = new GlobalGameConfig
        {
            Port = 26880,
            PublicAddress = "127.0.0.1",
            AllowMissingCBID = true,
        },
    };

    public static SectorConfig CreateValidSector(string? gamePath = ExistingGamePath) => new()
    {
        CharDatabaseConnectionString = "Server=localhost;Port=3306;Database=autocore_char;Uid=test;Password=test",
        WorldDatabaseConnectionString = "Server=localhost;Port=3306;Database=autocore_world;Uid=test;Password=test",
        GamePath = gamePath ?? string.Empty,
        GameConfig = new SectorGameConfig
        {
            Port = 27001,
            PublicAddress = "127.0.0.1",
        },
    };

    public static Func<string, bool> PathExistsFor(params string[] existingPaths)
    {
        var set = new HashSet<string>(existingPaths, StringComparer.OrdinalIgnoreCase);
        return path => set.Contains(path);
    }
}
