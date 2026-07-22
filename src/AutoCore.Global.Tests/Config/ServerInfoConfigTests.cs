using Microsoft.Extensions.Configuration;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Global.Tests.Config;

using AutoCore.Global.Config;

[TestClass]
public class ServerInfoConfigTests
{
    [TestMethod]
    public void Defaults_WhenConstructed_AreZeroOrNull()
    {
        var config = new ServerInfoConfig();

        Assert.AreEqual(0, config.Id);
        Assert.IsNull(config.Password);
        Assert.AreEqual(0, config.AgeLimit);
        Assert.AreEqual(0, config.PKFlag);
        Assert.AreEqual(0, config.MaxPlayers);
    }

    [TestMethod]
    public void Bind_FromTempJson_PopulatesAllFields()
    {
        var json = """
            {
              "Id": 3,
              "Password": "secret",
              "AgeLimit": 18,
              "PKFlag": 1,
              "MaxPlayers": 500
            }
            """;

        var config = BindFromTempJson(json);

        Assert.AreEqual(3, config.Id);
        Assert.AreEqual("secret", config.Password);
        Assert.AreEqual(18, config.AgeLimit);
        Assert.AreEqual(1, config.PKFlag);
        Assert.AreEqual(500, config.MaxPlayers);
    }

    [TestMethod]
    public void Bind_MissingPassword_LeavesPasswordNull()
    {
        var json = """
            {
              "Id": 1,
              "MaxPlayers": 100
            }
            """;

        var config = BindFromTempJson(json);

        Assert.IsNull(config.Password);
        Assert.AreEqual(1, config.Id);
        Assert.AreEqual(100, config.MaxPlayers);
    }

    private static ServerInfoConfig BindFromTempJson(string json)
    {
        var path = Path.Combine(Path.GetTempPath(), $"server-info-config-{Guid.NewGuid():N}.json");
        try
        {
            File.WriteAllText(path, json);
            var root = new ConfigurationBuilder().AddJsonFile(path).Build();
            var config = new ServerInfoConfig();
            root.Bind(config);
            return config;
        }
        finally
        {
            if (File.Exists(path))
                File.Delete(path);
        }
    }
}
