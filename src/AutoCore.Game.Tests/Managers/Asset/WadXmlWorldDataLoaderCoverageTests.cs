using AutoCore.Game.Constants;
using AutoCore.Game.Managers.Asset;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Managers.Asset;

/// <summary>
/// Covers remaining <see cref="WadXmlWorldDataLoader"/> tables and parse soft-fails
/// not already exercised by loot/XP-focused suites.
/// </summary>
[TestClass]
public class WadXmlWorldDataLoaderCoverageTests
{
    private string _tempXmlPath = null!;

    [TestInitialize]
    public void Init()
    {
        _tempXmlPath = Path.Combine(Path.GetTempPath(), $"wad-cov-{Guid.NewGuid():N}.xml");
    }

    [TestCleanup]
    public void Cleanup()
    {
        if (File.Exists(_tempXmlPath))
            File.Delete(_tempXmlPath);
    }

    [TestMethod]
    public void LoadConfigNewCharacters_ParsesAndSkipsInvalidRaceClass()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tConfigNewCharacters>
                <row>
                  <IDRace>1</IDRace><IDClass>2</IDClass>
                  <CBIDVehicle>10</CBIDVehicle><CBIDTrailer>11</CBIDTrailer>
                  <CBIDWeapon>12</CBIDWeapon><CBIDArmor>13</CBIDArmor>
                  <CBIDPowerPlant>14</CBIDPowerPlant><CBIDRaceItem>15</CBIDRaceItem>
                  <IDStartingTown>3</IDStartingTown><IDStartingSkill1>7</IDStartingSkill1>
                  <IDOptionCode>9</IDOptionCode>
                  <IDSkillBattleMode1>1</IDSkillBattleMode1>
                  <IDSkillBattleMode2>2</IDSkillBattleMode2>
                  <IDSkillBattleMode3>3</IDSkillBattleMode3>
                </row>
                <row>
                  <IDRace>-1</IDRace><IDClass>1</IDClass>
                </row>
              </tConfigNewCharacters>
            </wad>
            """);

        var dict = WadXmlWorldDataLoader.LoadConfigNewCharacters(_tempXmlPath);
        Assert.AreEqual(1, dict.Count);
        var cfg = dict[Tuple.Create((byte)1, (byte)2)];
        Assert.AreEqual(10, cfg.Vehicle);
        Assert.AreEqual(11, cfg.Trailer);
        Assert.AreEqual(12, cfg.Weapon);
        Assert.AreEqual(13, cfg.Armor);
        Assert.AreEqual(14, cfg.PowerPlant);
        Assert.AreEqual(15, cfg.RaceItem);
        Assert.AreEqual(3, cfg.StartTown);
        Assert.AreEqual(7u, cfg.StartSkill);
        Assert.AreEqual(9, cfg.OptionCode);
        Assert.AreEqual(1u, cfg.SkillBattleMode1);
        Assert.AreEqual(2u, cfg.SkillBattleMode2);
        Assert.AreEqual(3u, cfg.SkillBattleMode3);
    }

    [TestMethod]
    public void LoadConfigNewCharacters_MissingSection_ReturnsEmpty()
    {
        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadConfigNewCharacters(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadContinentObjects_ParsesBoolsAndSkipsInvalidIds()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tContinentObject>
                <row>
                  <IDContinentObject>5</IDContinentObject>
                  <intCoordinates>1</intCoordinates>
                  <IDOwningFaction>2</IDOwningFaction>
                  <bitIsPersistent>Tr</bitIsPersistent>
                  <bitIsTown>Fa</bitIsTown>
                  <strMapFilename>plateau</strMapFilename>
                  <CBIDImage>99</CBIDImage>
                  <bitIsClientOnly>Tr</bitIsClientOnly>
                  <rlRotation>1.5</rlRotation>
                  <IDObjective>4</IDObjective>
                  <rlPositionX>10.5</rlPositionX>
                  <rlPositionZ>-3.25</rlPositionZ>
                  <strDisplayName>Plateau</strDisplayName>
                  <bitIsArena>Fa</bitIsArena>
                  <intMinLevel>1</intMinLevel>
                  <intMaxLevel>50</intMaxLevel>
                  <intContestedMission>8</intContestedMission>
                  <intMaxPlayers>32</intMaxPlayers>
                  <bitPlayCreateSounds>Tr</bitPlayCreateSounds>
                  <bitDropCommodities>Tr</bitDropCommodities>
                  <bitDropBrokenItems>Fa</bitDropBrokenItems>
                  <intMinVersion>1</intMinVersion>
                  <intMaxVersion>99</intMaxVersion>
                </row>
                <row><IDContinentObject>0</IDContinentObject></row>
                <row><IDContinentObject>-3</IDContinentObject></row>
              </tContinentObject>
            </wad>
            """);

        var dict = WadXmlWorldDataLoader.LoadContinentObjects(_tempXmlPath);
        Assert.AreEqual(1, dict.Count);
        var co = dict[5];
        Assert.AreEqual("plateau", co.MapFileName);
        Assert.AreEqual("Plateau", co.DisplayName);
        Assert.IsTrue(co.IsPersistent);
        Assert.IsFalse(co.IsTown);
        Assert.IsTrue(co.IsClientOnly);
        Assert.IsFalse(co.IsArena);
        Assert.AreEqual(1.5f, co.Rotation, 0.0001f);
        Assert.AreEqual(10.5f, co.PositionX, 0.0001f);
        Assert.AreEqual(-3.25f, co.PositionZ, 0.0001f);
        Assert.AreEqual(32, co.MaxPlayers);
        Assert.IsTrue(co.PlayCreateSounds);
        Assert.IsTrue(co.DropCommodities);
        Assert.IsFalse(co.DropBrokenItems);
    }

    [TestMethod]
    public void LoadContinentObjects_MissingSection_ReturnsEmpty()
    {
        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadContinentObjects(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadContinentAreas_ParsesAndSkipsOutOfRange()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tContinentExploredAreas>
                <row>
                  <IDContinentObject>5</IDContinentObject>
                  <IDExploredArea>2</IDExploredArea>
                  <strExploredAreaName>North</strExploredAreaName>
                  <intXPLevel>7</intXPLevel>
                </row>
                <row>
                  <IDContinentObject>5</IDContinentObject>
                  <IDExploredArea>300</IDExploredArea>
                </row>
                <row>
                  <IDContinentObject>0</IDContinentObject>
                  <IDExploredArea>1</IDExploredArea>
                </row>
              </tContinentExploredAreas>
            </wad>
            """);

        var dict = WadXmlWorldDataLoader.LoadContinentAreas(_tempXmlPath);
        Assert.AreEqual(1, dict.Count);
        var area = dict[Tuple.Create(5, (byte)2)];
        Assert.AreEqual("North", area.AreaName);
        Assert.AreEqual(7, area.XPLevel);
    }

    [TestMethod]
    public void LoadContinentAreas_MissingSection_ReturnsEmpty()
    {
        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadContinentAreas(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadLootTables_ParsesCoreFields()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tLootTable>
                <row>
                  <IDLootTable>3</IDLootTable>
                  <strLootTableName>bandit</strLootTableName>
                  <sinLootRolls>2</sinLootRolls>
                  <rlDropChance>0.5</rlDropChance>
                  <rlConsumableDropChance>0.1</rlConsumableDropChance>
                  <rlDropLevelOffset>1.5</rlDropLevelOffset>
                  <sinMaxLevelOffset>4</sinMaxLevelOffset>
                  <rlLevelOffsetMultiplier>0.25</rlLevelOffsetMultiplier>
                  <sinMaxEnhancementComplexity>3</sinMaxEnhancementComplexity>
                  <intBaseChanceEnhanced>10</intBaseChanceEnhanced>
                  <intChanceEnhancedModifierPerLevel>2</intChanceEnhancedModifierPerLevel>
                  <intChanceWeapon>20</intChanceWeapon>
                  <intChanceArmor>15</intChanceArmor>
                  <intChancePowerPlant>5</intChancePowerPlant>
                  <intChanceWheelSet>1</intChanceWheelSet>
                  <intChanceVehicle>0</intChanceVehicle>
                  <intChanceGadget>3</intChanceGadget>
                  <intChanceTinkeringKit>2</intChanceTinkeringKit>
                  <intChanceAccessory>4</intChanceAccessory>
                  <intChanceRaceItem>1</intChanceRaceItem>
                  <intChanceOrnament>1</intChanceOrnament>
                  <intChanceOther>9</intChanceOther>
                  <intChanceRarity_0>50</intChanceRarity_0>
                  <intChanceRarity_1>30</intChanceRarity_1>
                  <intChanceRarity_2>10</intChanceRarity_2>
                  <intChanceRarity_3>5</intChanceRarity_3>
                  <intChanceRarity_4>3</intChanceRarity_4>
                  <intChanceRarity_5>1</intChanceRarity_5>
                  <intChanceRarity_6>1</intChanceRarity_6>
                  <intChanceRarity_7>0</intChanceRarity_7>
                  <intChanceRarity_8>0</intChanceRarity_8>
                  <rlDropCreditsChance>0.4</rlDropCreditsChance>
                  <intMinCreditsDrop>10</intMinCreditsDrop>
                  <intMaxCreditsDrop>100</intMaxCreditsDrop>
                  <rlWeaponBrokenModifier>0.5</rlWeaponBrokenModifier>
                  <rlArmorBrokenModifier>0.5</rlArmorBrokenModifier>
                  <rlPowerPlantBrokenModifier>0.5</rlPowerPlantBrokenModifier>
                  <rlWheelsetBrokenModifier>0.5</rlWheelsetBrokenModifier>
                  <rlVehicleBrokenModifier>0.5</rlVehicleBrokenModifier>
                  <rlGadgetBrokenModifier>0.5</rlGadgetBrokenModifier>
                  <rlTinkeringKitBrokenModifier>0.5</rlTinkeringKitBrokenModifier>
                  <rlAccessoryBrokenModifier>0.5</rlAccessoryBrokenModifier>
                  <rlRaceItemBrokenModifier>0.5</rlRaceItemBrokenModifier>
                  <rlOrnamentBrokenModifier>0.5</rlOrnamentBrokenModifier>
                  <rlOtherBrokenModifier>0.5</rlOtherBrokenModifier>
                </row>
                <row><IDLootTable>-1</IDLootTable></row>
              </tLootTable>
            </wad>
            """);

        var tables = WadXmlWorldDataLoader.LoadLootTables(_tempXmlPath);
        Assert.AreEqual(1, tables.Count);
        var lt = tables[3];
        Assert.AreEqual("bandit", lt.Name);
        Assert.AreEqual((short)2, lt.LootRolls);
        Assert.AreEqual(0.5f, lt.DropChance, 0.0001f);
        Assert.AreEqual(20, lt.ChanceWeapon);
        Assert.AreEqual(50, lt.ChanceRarity0);
        Assert.AreEqual(10, lt.MinCreditsDrop);
        Assert.AreEqual(100, lt.MaxCreditsDrop);
        Assert.AreEqual(0.5f, lt.WeaponBrokenModifier, 0.0001f);
    }

    [TestMethod]
    public void LoadLootTables_MissingSection_ReturnsEmpty()
    {
        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadLootTables(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadLootWeights_SkipsInvalidAndZeroWeight_MissingEmpty()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tLootWeights>
                <row><CBIDDestroyed>1</CBIDDestroyed><CBIDLoot>2</CBIDLoot><sinWeight>0</sinWeight></row>
                <row><CBIDDestroyed>0</CBIDDestroyed><CBIDLoot>2</CBIDLoot><sinWeight>5</sinWeight></row>
                <row><CBIDDestroyed>1</CBIDDestroyed><CBIDLoot>0</CBIDLoot><sinWeight>5</sinWeight></row>
                <row><CBIDDestroyed>9</CBIDDestroyed><CBIDLoot>8</CBIDLoot><sinWeight>not-a-number</sinWeight></row>
              </tLootWeights>
            </wad>
            """);

        var weights = WadXmlWorldDataLoader.LoadLootWeights(_tempXmlPath);
        Assert.AreEqual(0, weights.Count);

        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadLootWeights(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadConsumables_SkipsInvalid_MissingEmpty()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tConsumables>
                <row><CBIDItem>0</CBIDItem></row>
                <row><CBIDItem>-5</CBIDItem></row>
              </tConsumables>
            </wad>
            """);
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadConsumables(_tempXmlPath).Count);

        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadConsumables(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadVehicleTemplates_MissingAndInvalidSkipped()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tVehicleTemplate>
                <row><IDVehicleTemplate>-1</IDVehicleTemplate></row>
              </tVehicleTemplate>
            </wad>
            """);
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadVehicleTemplates(_tempXmlPath).Count);

        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadVehicleTemplates(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadCreatureAiProfiles_UnknownCodeDefaults_AndMissingEmpty()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tCreatureAI>
                <row>
                  <AIID>99</AIID>
                  <AICode>99999</AICode>
                  <strDescInternal>weird</strDescInternal>
                  <val1>not-float</val1>
                </row>
                <row><AIID>-1</AIID></row>
              </tCreatureAI>
            </wad>
            """);

        var profiles = WadXmlWorldDataLoader.LoadCreatureAiProfiles(_tempXmlPath);
        Assert.AreEqual(1, profiles.Count);
        Assert.AreEqual(HBAICode.Default, profiles[99].AiCode);
        Assert.AreEqual("weird", profiles[99].DescInternal);
        Assert.AreEqual(0f, profiles[99].Vals[0]);

        File.WriteAllText(_tempXmlPath, "<wad/>");
        Assert.AreEqual(0, WadXmlWorldDataLoader.LoadCreatureAiProfiles(_tempXmlPath).Count);
    }

    [TestMethod]
    public void LoadExperienceLevels_InvalidParseDefaults()
    {
        File.WriteAllText(_tempXmlPath, """
            <wad>
              <tExperienceLevel>
                <row>
                  <IDLevel>2</IDLevel>
                  <intExperience>not-int</intExperience>
                  <iSkillPoints></iSkillPoints>
                  <iAttributePoints>x</iAttributePoints>
                  <iResearchPoints>1</iResearchPoints>
                </row>
                <row><IDLevel>300</IDLevel></row>
              </tExperienceLevel>
            </wad>
            """);

        var levels = WadXmlWorldDataLoader.LoadExperienceLevels(_tempXmlPath);
        Assert.AreEqual(1, levels.Count);
        Assert.AreEqual(0u, levels[2].Experience);
        Assert.AreEqual(0, levels[2].SkillPoints);
        Assert.AreEqual(0, levels[2].AttributePoints);
        Assert.AreEqual(1, levels[2].ResearchPoints);
    }
}
