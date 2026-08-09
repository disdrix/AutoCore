using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Combat;

using AutoCore.Database.World.Models;
using AutoCore.Game.Entities;
using AutoCore.Game.Map;
using AutoCore.Game.Npc;
using AutoCore.Game.Structures;

/// <summary>
/// SS-35 tripwire: combat-pool cooling was driven only for player connections
/// (SectorServer iterates Interface.MapConnections), so an NPC vehicle that hit MaxHeat had its
/// weapons silently blocked forever — ProcessCombatInternal early-returns at heat >= max.
/// NPC pools must advance from the NPC AI tick.
/// </summary>
[TestClass]
public class NpcVehicleHeatCoolingTests
{
    [TestMethod]
    public void NpcVehicle_HeatPinnedAtMax_CoolsViaCombatAiTick()
    {
        var continent = new ContinentObject
        {
            Id = 97300,
            MapFileName = "tm_npcheat",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        var map = SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));

        var vehicle = new Vehicle();
        vehicle.SetCoid(97301, true);
        vehicle.SetMap(map);
        vehicle.NpcAi = new NpcAiState();
        vehicle.SetMaximumHeat(100);
        vehicle.SetCurrentHeat(100);
        vehicle.SetCoolRateForTests(10);

        // Six 3000 ms pool pulses of AI tick time: overheat debounce arms, counts down, then cools.
        long now = 1_000_000;
        for (var i = 0; i < 6; i++)
            NpcCombatAi.Tick(map, vehicle, now + (i * 3000), dt: 3f);

        Assert.IsTrue(vehicle.CurrentHeat < 100,
            $"NPC vehicle heat must cool without a player connection (heat={vehicle.CurrentHeat})");
    }
}
