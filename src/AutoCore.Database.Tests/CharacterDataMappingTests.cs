using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Database.Tests;

using AutoCore.Database.Char;
using AutoCore.Database.Char.Models;

[TestClass]
public class CharacterDataMappingTests
{
    [TestMethod]
    public void CharacterData_RoundTrip_PersistsProgressAndEconomyFields()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();

        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();

            var simple = new SimpleObjectData
            {
                Coid = 1000,
                Type = 1,
                CBID = 200,
                Faction = 3,
                TeamFaction = 4,
            };
            context.SimpleObjects.Add(simple);

            var vehicleSimple = new SimpleObjectData
            {
                Coid = 2000,
                Type = 2,
                CBID = 300,
                Faction = 3,
                TeamFaction = 4,
            };
            context.SimpleObjects.Add(vehicleSimple);

            var vehicle = new VehicleData
            {
                Coid = 2000,
                CharacterCoid = 1000,
                Name = "Hotrod",
                PositionX = 1f,
                PositionY = 2f,
                PositionZ = 3f,
                RotationX = 0f,
                RotationY = 0f,
                RotationZ = 0f,
                RotationW = 1f,
                Ornament = -1,
                RaceItem = -1,
                PowerPlant = 10,
                Wheelset = 11,
                Armor = 12,
                MeleeWeapon = -1,
                Front = 13,
                Turret = 14,
                Rear = 15,
                PrimaryColor = 0x112233,
                SecondaryColor = 0x445566,
                Trim = 2,
                CurrentHP = 500,
                CurrentShield = 100,
                CurrentPower = 80,
                CurrentHeat = 10,
            };
            context.Vehicles.Add(vehicle);

            context.Characters.Add(new CharacterData
            {
                Coid = 1000,
                AccountId = 7,
                ActiveVehicleCoid = 2000,
                Name = "TestChar",
                HeadId = 1,
                BodyId = 2,
                HeadDetail1 = 3,
                HeadDetail2 = 4,
                HelmetId = 5,
                EyesId = 6,
                MouthId = 7,
                HairId = 8,
                PrimaryColor = 9,
                SecondaryColor = 10,
                EyesColor = 11,
                HairColor = 12,
                SkinColor = 13,
                SpecialityColor = 14,
                LastTownId = 15,
                LastStationId = 16,
                LastStationMapId = 17,
                PositionX = 100.5f,
                PositionY = 200.5f,
                PositionZ = 300.5f,
                RotationX = 0.1f,
                RotationY = 0.2f,
                RotationZ = 0.3f,
                RotationW = 0.9f,
                ScaleOffset = 1.0f,
                Level = 12,
                Experience = 45000,
                SkillPoints = 3,
                AttributePoints = 2,
                ResearchPoints = 1,
                AttributeTech = 5,
                AttributeCombat = 6,
                AttributeTheory = 4,
                AttributePerception = 3,
                Credits = 123456,
                CreditDebt = 50,
                Deleted = false,
                CargoWidth = 6,
                CargoPageCount = 13,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var character = context.Characters
                .Include(c => c.SimpleObjectBase)
                .Include(c => c.ActiveVehicle)
                .Single(c => c.Coid == 1000);

            Assert.AreEqual(7u, character.AccountId);
            Assert.AreEqual("TestChar", character.Name);
            Assert.AreEqual((byte)12, character.Level);
            Assert.AreEqual(45000, character.Experience);
            Assert.AreEqual((short)3, character.SkillPoints);
            Assert.AreEqual((short)2, character.AttributePoints);
            Assert.AreEqual((short)1, character.ResearchPoints);
            Assert.AreEqual((short)5, character.AttributeTech);
            Assert.AreEqual((short)6, character.AttributeCombat);
            Assert.AreEqual((short)4, character.AttributeTheory);
            Assert.AreEqual((short)3, character.AttributePerception);
            Assert.AreEqual(123456L, character.Credits);
            Assert.AreEqual(50L, character.CreditDebt);
            Assert.AreEqual(6, character.CargoWidth);
            Assert.AreEqual(13, character.CargoPageCount);
            Assert.AreEqual(100.5f, character.PositionX);
            Assert.AreEqual(2000L, character.ActiveVehicleCoid);
            Assert.IsNotNull(character.SimpleObjectBase);
            Assert.AreEqual(200, character.SimpleObjectBase.CBID);
            Assert.IsNotNull(character.ActiveVehicle);
            Assert.AreEqual("Hotrod", character.ActiveVehicle.Name);
            Assert.AreEqual(500, character.ActiveVehicle.CurrentHP);
            Assert.AreEqual(100, character.ActiveVehicle.CurrentShield);
            Assert.AreEqual(80, character.ActiveVehicle.CurrentPower);
            Assert.AreEqual(10, character.ActiveVehicle.CurrentHeat);
        }
    }

    [TestMethod]
    public void CharacterData_DefaultAttributeFloors_AreOne()
    {
        var character = new CharacterData();
        Assert.AreEqual((short)1, character.AttributeTech);
        Assert.AreEqual((short)1, character.AttributeCombat);
        Assert.AreEqual((short)1, character.AttributeTheory);
        Assert.AreEqual((short)1, character.AttributePerception);
        Assert.AreEqual((byte)1, character.Level);
        Assert.AreEqual(6, character.CargoWidth);
        Assert.AreEqual(13, character.CargoPageCount);
    }

    [TestMethod]
    public void VehicleData_DefaultCombatPools_AreUnset()
    {
        var vehicle = new VehicleData
        {
            Coid = 1,
            CharacterCoid = 2,
            Name = "v",
        };
        Assert.AreEqual(-1, vehicle.CurrentHP);
        Assert.AreEqual(-1, vehicle.CurrentShield);
        Assert.AreEqual(-1, vehicle.CurrentPower);
        Assert.AreEqual(-1, vehicle.CurrentHeat);
    }

    [TestMethod]
    public void Inventory_RoundTrip_PersistsMissionAndTypeFlags()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();
            context.SimpleObjects.Add(new SimpleObjectData { Coid = 50, Type = 1, CBID = 1 });
            context.Characters.Add(new CharacterData
            {
                Coid = 50,
                AccountId = 1,
                Name = "InvChar",
            });
            context.CharacterInventories.Add(new CharacterInventoryData
            {
                CharacterCoid = 50,
                ItemCoid = 900,
                Cbid = 77,
                Type = 3,
                SlotX = 2,
                SlotY = 4,
                Quantity = 5,
                InventoryType = 3,
                IsMissionItem = true,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var item = context.CharacterInventories
                .Include(i => i.Character)
                .Single(i => i.ItemCoid == 900);

            Assert.AreEqual(50L, item.CharacterCoid);
            Assert.AreEqual(77, item.Cbid);
            Assert.AreEqual((byte)3, item.Type);
            Assert.AreEqual((byte)2, item.SlotX);
            Assert.AreEqual((byte)4, item.SlotY);
            Assert.AreEqual(5, item.Quantity);
            Assert.AreEqual((byte)3, item.InventoryType);
            Assert.IsTrue(item.IsMissionItem);
            Assert.IsNotNull(item.Character);
            Assert.AreEqual("InvChar", item.Character.Name);
        }
    }

    [TestMethod]
    public void Inventory_DefaultQuantityAndType()
    {
        var item = new CharacterInventoryData
        {
            CharacterCoid = 1,
            ItemCoid = 2,
            Cbid = 3,
        };
        Assert.AreEqual(1, item.Quantity);
        Assert.AreEqual((byte)1, item.InventoryType);
        Assert.IsFalse(item.IsMissionItem);
    }

    [TestMethod]
    public void Character_VehicleCollection_LoadsInverseNavigation()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();
            context.SimpleObjects.Add(new SimpleObjectData { Coid = 10, Type = 1, CBID = 1 });
            context.SimpleObjects.Add(new SimpleObjectData { Coid = 20, Type = 2, CBID = 2 });
            context.SimpleObjects.Add(new SimpleObjectData { Coid = 21, Type = 2, CBID = 3 });
            context.Characters.Add(new CharacterData { Coid = 10, AccountId = 1, Name = "Fleet" });
            context.Vehicles.Add(new VehicleData { Coid = 20, CharacterCoid = 10, Name = "A" });
            context.Vehicles.Add(new VehicleData { Coid = 21, CharacterCoid = 10, Name = "B" });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var character = context.Characters
                .Include(c => c.Vehicles)
                .Single(c => c.Coid == 10);
            Assert.AreEqual(2, character.Vehicles.Count);
            CollectionAssert.AreEquivalent(
                new[] { "A", "B" },
                character.Vehicles.Select(v => v.Name).ToArray());
        }
    }

    [TestMethod]
    public void Character_InventoryCollection_LoadsInverseNavigation()
    {
        var options = TestHelpers.CreateInMemoryOptions<CharContext>();
        using (var context = new CharContext(options))
        {
            context.Database.EnsureCreated();
            context.SimpleObjects.Add(new SimpleObjectData { Coid = 30, Type = 1, CBID = 1 });
            context.Characters.Add(new CharacterData { Coid = 30, AccountId = 1, Name = "Packrat" });
            context.CharacterInventories.Add(new CharacterInventoryData
            {
                CharacterCoid = 30,
                ItemCoid = 301,
                Cbid = 1,
                SlotX = 0,
                SlotY = 0,
            });
            context.CharacterInventories.Add(new CharacterInventoryData
            {
                CharacterCoid = 30,
                ItemCoid = 302,
                Cbid = 2,
                SlotX = 1,
                SlotY = 0,
            });
            context.SaveChanges();
        }

        using (var context = new CharContext(options))
        {
            var character = context.Characters
                .Include(c => c.InventoryItems)
                .Single(c => c.Coid == 30);
            Assert.AreEqual(2, character.InventoryItems.Count);
        }
    }
}
