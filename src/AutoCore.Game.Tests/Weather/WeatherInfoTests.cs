using AutoCore.Game.Weather;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Weather;

[TestClass]
public class WeatherInfoTests
{
    [TestMethod]
    public void WeatherInfo_PropertyAssignment()
    {
        var info = new WeatherInfo
        {
            EventTimesPerMinute = 5,
            FxName = "rain",
            LayerBits = 0xFFu,
            MaxTimeToLive = 60,
            MinTimeToLive = 10,
            PercentChance = 0.35f,
            SpecialEventSkill = 12,
            SpecialType = 2,
            Type = 1
        };

        Assert.AreEqual((byte)5, info.EventTimesPerMinute);
        Assert.AreEqual("rain", info.FxName);
        Assert.AreEqual(0xFFu, info.LayerBits);
        Assert.AreEqual(60u, info.MaxTimeToLive);
        Assert.AreEqual(10u, info.MinTimeToLive);
        Assert.AreEqual(0.35f, info.PercentChance);
        Assert.AreEqual(12, info.SpecialEventSkill);
        Assert.AreEqual(2u, info.SpecialType);
        Assert.AreEqual(1u, info.Type);
    }

    [TestMethod]
    public void WeatherContainer_HoldsEffectEnvironmentsAndWeathers()
    {
        var container = new WeatherContainer
        {
            Effect = "storm"
        };
        container.Environments.Add("env1");
        container.Weathers.Add(new WeatherInfo { FxName = "fog", PercentChance = 0.1f });

        Assert.AreEqual("storm", container.Effect);
        Assert.AreEqual(1, container.Environments.Count);
        Assert.AreEqual("env1", container.Environments[0]);
        Assert.AreEqual(1, container.Weathers.Count);
        Assert.AreEqual("fog", container.Weathers[0].FxName);
    }
}
