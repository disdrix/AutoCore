using AutoCore.Database.World.Models;
using AutoCore.Game.Constants;
using AutoCore.Game.Entities;
using AutoCore.Game.EntityTemplates;
using AutoCore.Game.Map;
using AutoCore.Game.Structures;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.Map;

/// <summary>
/// Residual pure SectorMap branches: local lookup + reaction materialization.
/// </summary>
[TestClass]
public class SectorMapResidualCoverageTests
{
    [TestMethod]
    public void GetLocalObject_FindsLocalButNotGlobal()
    {
        var map = CreateMap(7701);
        var local = new GraphicsObject(GraphicsObjectType.Graphics);
        local.SetCoid(100, global: false);
        local.SetMap(map);
        map.Objects[local.ObjectId] = local;

        var global = new GraphicsObject(GraphicsObjectType.Graphics);
        global.SetCoid(100, global: true);
        global.SetMap(map);
        map.Objects[global.ObjectId] = global;

        Assert.AreSame(local, map.GetLocalObject(100));
        Assert.IsNull(map.GetLocalObject(999));
    }

    [TestMethod]
    public void GetOrMaterializeReaction_InvalidCoid_ReturnsNull()
    {
        var map = CreateMap(7702);
        Assert.IsNull(map.GetOrMaterializeReaction(0));
        Assert.IsNull(map.GetOrMaterializeReaction(-1));
        Assert.IsNull(map.GetOrMaterializeReaction(42_000));
    }

    [TestMethod]
    public void GetOrMaterializeReaction_ExistingOnMap_ReturnsSame()
    {
        var map = CreateMap(7703);
        var tpl = new ReactionTemplate
        {
            COID = 8801,
            Name = "existing",
            ReactionType = ReactionType.Boost,
        };
        var existing = new Reaction(tpl);
        existing.SetCoid(8801, false);
        existing.SetMap(map);
        map.Objects[existing.ObjectId] = existing;
        map.Reactions[existing.ObjectId] = existing;

        var found = map.GetOrMaterializeReaction(8801);
        Assert.AreSame(existing, found);
    }

    [TestMethod]
    public void GetOrMaterializeReaction_FromTemplate_PlacesReaction()
    {
        var map = CreateMap(7704);
        var tpl = new ReactionTemplate
        {
            COID = 8802,
            Name = "materialize_me",
            ReactionType = ReactionType.Boost,
            ActOnActivator = true,
        };
        map.MapData.Templates[8802] = tpl;

        var placed = map.GetOrMaterializeReaction(8802);
        Assert.IsNotNull(placed);
        Assert.AreEqual(8802, placed!.ObjectId.Coid);
        Assert.AreSame(map, placed.Map);
        // Second call returns the placed instance.
        Assert.AreSame(placed, map.GetOrMaterializeReaction(8802));
    }

    private static SectorMap CreateMap(int continentId)
    {
        var continent = new ContinentObject
        {
            Id = continentId,
            MapFileName = $"tm_residual_{continentId}",
            DisplayName = "residual",
            IsTown = false,
            IsPersistent = true,
        };
        return SectorMap.CreateForTests(continent, new Vector4(0, 0, 0, 0));
    }
}
