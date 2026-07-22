using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.World.Models;

[TestClass]
public class LootTableModelTests
{
    private static LootTable CreateSampleTable() => new()
    {
        Id = 42,
        Name = "CreatureStandard",
        LootRolls = 3,
        DropChance = 0.5f,
        ConsumableDropChance = 0.1f,
        DropLevelOffset = 1.0f,
        MaxLevelOffset = 5,
        LevelOffsetMultiplier = 0.25f,
        MaxEnhancementComplexity = 4,
        BaseChanceEnhanced = 10,
        ChanceEnhancedModifierPerLevel = 2,
        ChanceWeapon = 10,
        ChanceArmor = 20,
        ChancePowerPlant = 5,
        ChanceWheelSet = 5,
        ChanceVehicle = 1,
        ChanceGadget = 4,
        ChanceTinkeringKit = 3,
        ChanceAccessory = 2,
        ChanceRaceItem = 1,
        ChanceOrnament = 1,
        ChanceOther = 8,
        ChanceRarity0 = 50,
        ChanceRarity1 = 25,
        ChanceRarity2 = 15,
        ChanceRarity3 = 5,
        ChanceRarity4 = 3,
        ChanceRarity5 = 1,
        ChanceRarity6 = 1,
        ChanceRarity7 = 0,
        ChanceRarity8 = 0,
        DropCreditsChance = 0.2f,
        MinCreditsDrop = 10,
        MaxCreditsDrop = 100,
        WeaponBrokenModifier = 0.5f,
        ArmorBrokenModifier = 0.5f,
        PowerPlantBrokenModifier = 0.5f,
        WheelSetBrokenModifier = 0.5f,
        VehicleBrokenModifier = 0.5f,
        GadgetBrokenModifier = 0.5f,
        TinkeringKitBrokenModifier = 0.5f,
        AccessoryBrokenModifier = 0.5f,
        RaceItemBrokenModifier = 0.5f,
        OrnamentBrokenModifier = 0.5f,
        OtherBrokenModifier = 0.5f,
    };

    [TestMethod]
    public void GetTotalItemTypeWeight_SumsAllTypeChances()
    {
        var table = CreateSampleTable();
        // 10+20+5+5+1+4+3+2+1+1+8 = 60
        Assert.AreEqual(60, table.GetTotalItemTypeWeight());
    }

    [TestMethod]
    public void GetTotalItemTypeWeight_ZeroWhenUnset()
    {
        var table = new LootTable();
        Assert.AreEqual(0, table.GetTotalItemTypeWeight());
    }

    [TestMethod]
    public void GetTotalRarityWeight_SumsAllRarityChances()
    {
        var table = CreateSampleTable();
        // 50+25+15+5+3+1+1+0+0 = 100
        Assert.AreEqual(100, table.GetTotalRarityWeight());
    }

    [TestMethod]
    public void GetTotalRarityWeight_ZeroWhenUnset()
    {
        var table = new LootTable();
        Assert.AreEqual(0, table.GetTotalRarityWeight());
    }

    [TestMethod]
    public void GetRarityChance_ReturnsIndexedValues()
    {
        var table = CreateSampleTable();
        Assert.AreEqual(50, table.GetRarityChance(0));
        Assert.AreEqual(25, table.GetRarityChance(1));
        Assert.AreEqual(15, table.GetRarityChance(2));
        Assert.AreEqual(5, table.GetRarityChance(3));
        Assert.AreEqual(3, table.GetRarityChance(4));
        Assert.AreEqual(1, table.GetRarityChance(5));
        Assert.AreEqual(1, table.GetRarityChance(6));
        Assert.AreEqual(0, table.GetRarityChance(7));
        Assert.AreEqual(0, table.GetRarityChance(8));
    }

    [TestMethod]
    public void GetRarityChance_OutOfRange_ReturnsZero()
    {
        var table = CreateSampleTable();
        Assert.AreEqual(0, table.GetRarityChance(-1));
        Assert.AreEqual(0, table.GetRarityChance(9));
        Assert.AreEqual(0, table.GetRarityChance(100));
    }

    [TestMethod]
    public void Properties_RoundTrip_Assignments()
    {
        var table = CreateSampleTable();
        Assert.AreEqual(42, table.Id);
        Assert.AreEqual("CreatureStandard", table.Name);
        Assert.AreEqual((short)3, table.LootRolls);
        Assert.AreEqual(0.5f, table.DropChance);
        Assert.AreEqual(0.1f, table.ConsumableDropChance);
        Assert.AreEqual(1.0f, table.DropLevelOffset);
        Assert.AreEqual((short)5, table.MaxLevelOffset);
        Assert.AreEqual(0.25f, table.LevelOffsetMultiplier);
        Assert.AreEqual((short)4, table.MaxEnhancementComplexity);
        Assert.AreEqual(10, table.BaseChanceEnhanced);
        Assert.AreEqual(2, table.ChanceEnhancedModifierPerLevel);
        Assert.AreEqual(0.2f, table.DropCreditsChance);
        Assert.AreEqual(10, table.MinCreditsDrop);
        Assert.AreEqual(100, table.MaxCreditsDrop);
        Assert.AreEqual(0.5f, table.WeaponBrokenModifier);
        Assert.AreEqual(0.5f, table.OtherBrokenModifier);
    }
}
