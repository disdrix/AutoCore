using System.Reflection;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Auth;
using AutoCore.Database.Char;
using AutoCore.Database.World;

internal static class TestHelpers
{
    public static DbContextOptions<TContext> CreateInMemoryOptions<TContext>(string? name = null)
        where TContext : DbContext
    {
        return new DbContextOptionsBuilder<TContext>()
            .UseInMemoryDatabase(name ?? Guid.NewGuid().ToString())
            .Options;
    }

    public static void ResetConnectionString(Type contextType)
    {
        var property = contextType.GetProperty(
            "ConnectionString",
            BindingFlags.Public | BindingFlags.Static);
        Assert.IsNotNull(property, $"{contextType.Name}.ConnectionString property missing.");

        // Auth uses empty string as the unset sentinel; Char/World use null.
        var unset = contextType == typeof(AuthContext) ? string.Empty : null;
        property.SetValue(null, unset);
    }

    public static void ResetAllConnectionStrings()
    {
        ResetConnectionString(typeof(AuthContext));
        ResetConnectionString(typeof(CharContext));
        ResetConnectionString(typeof(WorldContext));
    }
}
