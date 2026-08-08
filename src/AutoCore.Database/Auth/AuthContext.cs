using Microsoft.EntityFrameworkCore;
using System.Linq;

namespace AutoCore.Database.Auth;

using AutoCore.Database.Auth.Models;
using AutoCore.Utils;

public class AuthContext : DbContext
{
    public static string ConnectionString { get; private set; } = string.Empty;

    public DbSet<Account> Accounts { get; set; }
    public DbSet<GlobalServer> GlobalServers { get; set; }
    public DbSet<DiscordAccountLink> DiscordAccountLinks { get; set; }

    public AuthContext()
    {
        Accounts = Set<Account>();
        GlobalServers = Set<GlobalServer>();
        DiscordAccountLinks = Set<DiscordAccountLink>();
    }

    /// <summary>Options-based constructor for unit tests (InMemory / SQLite) without MySQL.</summary>
    public AuthContext(DbContextOptions<AuthContext> options)
        : base(options)
    {
        Accounts = Set<Account>();
        GlobalServers = Set<GlobalServer>();
        DiscordAccountLinks = Set<DiscordAccountLink>();
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<DiscordAccountLink>(entity =>
        {
            entity.HasIndex(e => e.AccountId).IsUnique();
            entity.HasIndex(e => e.DiscordUserId);
        });
    }

    public static void InitializeConnectionString(string connectionString)
    {
        ArgumentException.ThrowIfNullOrEmpty(connectionString);

        if (!string.IsNullOrEmpty(ConnectionString))
            throw new ArgumentException("The data source is already set up for the AuthContext!", nameof(connectionString));

        ConnectionString = connectionString;
    }

    public static void EnsureCreated()
    {
        using var context = new AuthContext();
        context.Database.EnsureCreated();
        // EnsureCreated is a no-op when the database already exists — still add the Discord
        // link table for deployments that predate the optional Discord module.
        EnsureDiscordAccountLinkTable(context);
        SeedDefaultAccount(context);
    }

    /// <summary>
    /// Creates <c>discord_account_link</c> if missing (MySQL). Safe to call repeatedly.
    /// InMemory / non-relational providers no-op after EnsureCreated.
    /// </summary>
    public static void EnsureDiscordAccountLinkTable()
    {
        using var context = new AuthContext();
        EnsureDiscordAccountLinkTable(context);
    }

    internal static void EnsureDiscordAccountLinkTable(AuthContext context)
    {
        try
        {
            // Skip when the provider cannot execute raw SQL (e.g. pure InMemory without relational).
            if (!context.Database.IsRelational())
                return;

            context.Database.ExecuteSqlRaw(
                """
                CREATE TABLE IF NOT EXISTS `discord_account_link` (
                  `Id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
                  `DiscordUserId` BIGINT UNSIGNED NOT NULL,
                  `AccountId` INT UNSIGNED NOT NULL,
                  `CreatedAt` DATETIME(6) NOT NULL,
                  `CreatedByUsername` LONGTEXT NULL,
                  PRIMARY KEY (`Id`),
                  UNIQUE KEY `IX_discord_account_link_AccountId` (`AccountId`),
                  KEY `IX_discord_account_link_DiscordUserId` (`DiscordUserId`)
                ) CHARACTER SET=utf8mb4;
                """);
        }
        catch (Exception ex) when (ex is not OperationCanceledException and not OutOfMemoryException)
        {
            // Log and continue — fresh EnsureCreated already materializes the table via the model.
            Logger.WriteException(LogType.Warning, "ensure discord_account_link table", ex);
        }
    }

    /// <summary>Options-based EnsureCreated for unit tests without MySQL.</summary>
    public static void EnsureCreated(DbContextOptions<AuthContext> options)
    {
        using var context = new AuthContext(options);
        context.Database.EnsureCreated();
        SeedDefaultAccount(context);
    }

    /// <summary>
    /// Password for the bootstrap <c>admin</c> account, supplied by the operator via
    /// configuration (<c>AuthConfig.DefaultAdminPassword</c>). Must be set before
    /// <see cref="EnsureCreated()"/> runs, and only takes effect on a database with no accounts.
    /// <para>
    /// SS-20: this used to be the hard-coded literal <c>"admin"</c>, so every fresh deployment
    /// shipped with a working administrator credential (<c>Level = 255</c>, validated, unlocked)
    /// on a network-reachable auth server. There is now no built-in default: if the operator
    /// supplies nothing, nothing is seeded.
    /// </para>
    /// </summary>
    public static string DefaultAdminPassword { get; set; }

    /// <summary>
    /// Creates the bootstrap admin account, but only on an empty database and only when the
    /// operator explicitly configured a password.
    /// </summary>
    private static void SeedDefaultAccount(AuthContext context)
    {
        // Only consider seeding when no accounts exist at all.
        if (context.Accounts.Any())
            return;

        var password = DefaultAdminPassword;

        if (string.IsNullOrWhiteSpace(password))
        {
            // SS-20: no built-in fallback. Tell the operator exactly how to create the first
            // account instead of silently shipping a known credential.
            Logger.WriteLog(LogType.Warning,
                "No accounts exist and no default admin password is configured, so no account was created. " +
                "Set 'DefaultAdminPassword' in appsettings.auth.json, or create one at the console with: " +
                "auth.create <email> <username> <password>");
            return;
        }

        var salt = Account.CreateSalt();

        context.Accounts.Add(new Account
        {
            Email = "admin@autocore.local",
            Username = "admin",
            Password = Account.Hash(password, salt),
            Salt = salt,
            Level = 255, // Admin level
            JoinDate = DateTime.Now,
            Validated = true,
            Locked = false
        });

        context.SaveChanges();

        // Never log the password itself.
        Logger.WriteLog(LogType.Initialize,
            "Created the bootstrap 'admin' account from the configured default admin password.");
    }

    protected override void OnConfiguring(DbContextOptionsBuilder options)
    {
        // Skip when constructed with DbContextOptions (unit tests inject InMemory/SQLite).
        if (options.IsConfigured)
            return;

        options.UseMySql(ConnectionString, ServerVersion.AutoDetect(ConnectionString));
    }
}
