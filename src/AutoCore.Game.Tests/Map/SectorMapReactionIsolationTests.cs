using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

using AutoCore.Database.World.Models;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Managers;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;

/// <summary>
/// SS-13: reactions are the data-driven "scripting" surface — map content reaches an ~80-case
/// switch in <see cref="Reaction.TriggerIfPossible"/>, so malformed content lands there. One
/// failing reaction must not abort the rest of its batch.
/// </summary>
[TestClass]
public class SectorMapReactionIsolationTests
{
    private const int ContId = 917;
    private const long GoodPathCoid = 91710;
    private const long FirstReactionCoid = 91720;
    private const long BrokenReactionCoid = 91721;
    private const long LastReactionCoid = 91722;
    private const long FirstTargetCoid = 91701;
    private const long LastTargetCoid = 91702;
    private const long ActivatorCoid = 91703;

    [TestInitialize]
    public void SetUp() => TriggerManager.Instance.ClearAllForTests();

    [TestCleanup]
    public void TearDown() => TriggerManager.Instance.ClearAllForTests();

    /// <summary>
    /// SS-13 tripwire: a reaction whose template failed to load (null Template) throws when
    /// triggered. Before per-reaction isolation that aborted the whole batch, silently dropping
    /// every reaction queued after it.
    /// </summary>
    [TestMethod]
    public void TriggerReactions_WhenOneReactionThrows_LaterReactionsInTheBatchStillRun()
    {
        var map = CreateMap();
        SeedMapPath(map, GoodPathCoid);

        var firstTarget = PlaceVehicle(map, FirstTargetCoid);
        var lastTarget = PlaceVehicle(map, LastTargetCoid);
        var activator = PlaceVehicle(map, ActivatorCoid);

        PlaceSetPathReaction(map, FirstReactionCoid, FirstTargetCoid, (int)GoodPathCoid);
        PlaceBrokenReaction(map, BrokenReactionCoid);
        PlaceSetPathReaction(map, LastReactionCoid, LastTargetCoid, (int)GoodPathCoid);

        // Must not throw: the broken reaction is isolated.
        map.TriggerReactions(
            activator,
            new List<long> { FirstReactionCoid, BrokenReactionCoid, LastReactionCoid });

        Assert.AreEqual(
            GoodPathCoid,
            firstTarget.CoidCurrentPath,
            "The reaction ordered before the broken one should have applied.");

        Assert.AreEqual(
            GoodPathCoid,
            lastTarget.CoidCurrentPath,
            "SS-13: the reaction ordered AFTER the broken one must still run. One malformed " +
            "reaction must not silently drop the rest of the batch.");
    }

    /// <summary>
    /// SS-13: the count returned must reflect only the reactions that actually succeeded, so a
    /// failure is observable to callers rather than being reported as success.
    /// </summary>
    [TestMethod]
    public void TriggerReactionsCount_ExcludesTheFailedReaction()
    {
        var map = CreateMap();
        SeedMapPath(map, GoodPathCoid);

        PlaceVehicle(map, FirstTargetCoid);
        PlaceVehicle(map, LastTargetCoid);
        var activator = PlaceVehicle(map, ActivatorCoid);

        PlaceSetPathReaction(map, FirstReactionCoid, FirstTargetCoid, (int)GoodPathCoid);
        PlaceBrokenReaction(map, BrokenReactionCoid);
        PlaceSetPathReaction(map, LastReactionCoid, LastTargetCoid, (int)GoodPathCoid);

        var triggered = map.TriggerReactionsCount(
            activator,
            new List<long> { FirstReactionCoid, BrokenReactionCoid, LastReactionCoid });

        Assert.AreEqual(
            2,
            triggered,
            "Two of the three reactions are valid; the broken one must not be counted as triggered.");
    }

    private static SectorMap CreateMap()
    {
        var continent = new ContinentObject
        {
            Id = ContId,
            MapFileName = $"tm_reaction_isolation_{ContId}",
            DisplayName = "test",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }

    private static MapPathTemplate SeedMapPath(SectorMap map, long pathCoid)
    {
        var path = new MapPathTemplate { COID = (int)pathCoid, ReverseDirection = false };
        map.MapData.Templates[pathCoid] = path;
        return path;
    }

    private static Vehicle PlaceVehicle(SectorMap map, long coid)
    {
        var vehicle = new Vehicle();
        vehicle.SetCoid(coid, false);
        vehicle.Position = new Vector3(0f, 0f, 0f);
        vehicle.SetMap(map);
        return vehicle;
    }

    private static void PlaceSetPathReaction(SectorMap map, long reactionCoid, long objectCoid, int pathCoid)
    {
        var tpl = new ReactionTemplate
        {
            COID = (int)reactionCoid,
            Name = "isolation_set_path",
            ReactionType = ReactionType.SetPath,
            ActOnActivator = false,
            GenericVar1 = pathCoid,
        };
        tpl.Objects.Add(objectCoid);

        var reaction = new Reaction(tpl);
        reaction.SetCoid(reactionCoid, false);
        reaction.SetMap(map);
    }

    /// <summary>
    /// A reaction whose template failed to load. This is what a malformed or truncated .fam
    /// produces, and it throws on the first Template dereference inside TriggerIfPossible.
    /// </summary>
    private static void PlaceBrokenReaction(SectorMap map, long reactionCoid)
    {
        var reaction = new Reaction(null);
        reaction.SetCoid(reactionCoid, false);
        reaction.SetMap(map);
    }
}
