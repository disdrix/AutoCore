using Microsoft.EntityFrameworkCore;

namespace AutoCore.Database.World;

using AutoCore.Database.World.Models;

public class WorldContext : DbContext
{
    public static string ConnectionString { get; private set; }

    public DbSet<ConfigNewCharacter> ConfigNewCharacters { get; set; }
    public DbSet<ContinentArea> ContinentAreas { get; set; }
    public DbSet<ContinentObject> ContinentObjects { get; set; }
    public DbSet<ExperienceLevel> ExperienceLevels { get; set; }

    public WorldContext()
    {
    }

    /// <summary>Options-based constructor for unit tests (InMemory / SQLite) without MySQL.</summary>
    public WorldContext(DbContextOptions<WorldContext> options)
        : base(options)
    {
    }

    public static void InitializeConnectionString(string connectionString)
    {
        if (string.IsNullOrEmpty(connectionString))
            throw new ArgumentNullException(nameof(connectionString));

        if (!string.IsNullOrEmpty(ConnectionString))
            throw new ArgumentException("The data source is already set up for the WorldContext!", nameof(connectionString));

        ConnectionString = connectionString;
    }

    public static void EnsureCreated()
    {
        using var context = new WorldContext();
        context.Database.EnsureCreated();
    }

    /// <summary>Options-based EnsureCreated for unit tests without MySQL.</summary>
    public static void EnsureCreated(DbContextOptions<WorldContext> options)
    {
        using var context = new WorldContext(options);
        context.Database.EnsureCreated();
    }

    protected override void OnConfiguring(DbContextOptionsBuilder options)
    {
        // Skip when constructed with DbContextOptions (unit tests inject InMemory/SQLite).
        if (options.IsConfigured)
            return;

        options.UseMySql(ConnectionString, ServerVersion.AutoDetect(ConnectionString));
    }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<ConfigNewCharacter>().HasKey(cnc => new { cnc.Race, cnc.Class });
        modelBuilder.Entity<ContinentArea>().HasKey(ca => new { ca.ContinentObjectId, ca.Area });
    }
}
