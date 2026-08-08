using AutoCore.Game.Constants;
using AutoCore.Game.Diagnostics;
using AutoCore.Game.Entities;
using AutoCore.Game.Structures;
using AutoCore.Game.TNL;
using AutoCore.Game.TNL.Ghost;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using TNL.Entities;
using TNL.Utils;

namespace AutoCore.Game.Tests.TNL.Ghost;

/// <summary>
/// Pack/unpack coverage for plain <see cref="GhostObject"/> (map props / simple objects).
/// </summary>
[TestClass]
public class GhostObjectPackTests
{
    [TestCleanup]
    public void TearDown()
    {
        NetObject.PIsInitialUpdate = false;
        GhostObjectDiag.ResetForTests();
    }

    [TestMethod]
    public void PackUpdate_WithoutParent_Throws()
    {
        var ghost = new GhostObject();
        var stream = new BitStream(new byte[64], 64);
        Assert.ThrowsException<Exception>(() => ghost.PackUpdate(null, GhostObject.InitialMask, stream));
    }

    [TestMethod]
    public void UnpackUpdate_ThrowsNotSupported()
    {
        var ghost = new GhostObject();
        var stream = new BitStream(new byte[16], 16);
        Assert.ThrowsException<NotSupportedException>(() => ghost.UnpackUpdate(null, stream));
    }

    [TestMethod]
    public void PackUpdate_InitialLocal_WritesCoidInt20()
    {
        var prop = MakeProp(coid: 1234, global: false, hp: 50);
        var stream = Pack(prop, GhostObject.InitialMask, initial: true);

        Assert.IsFalse(stream.ReadFlag()); // Global
        Assert.AreEqual(1234u, stream.ReadInt(20));
    }

    [TestMethod]
    public void PackUpdate_InitialGlobal_WritesFullCoid()
    {
        var prop = MakeProp(coid: 9_000_001, global: true, hp: 10);
        var stream = Pack(prop, GhostObject.InitialMask, initial: true);

        Assert.IsTrue(stream.ReadFlag());
        stream.Read(out long coid);
        Assert.AreEqual(9_000_001L, coid);
    }

    [TestMethod]
    public void PackUpdate_HealthMask_Alive_NoCorpseBlock()
    {
        var prop = MakeProp(coid: 50, global: false, hp: 40);
        var stream = Pack(prop, GhostObject.HealthMask, initial: false);

        Assert.IsTrue(stream.ReadFlag()); // HealthMask
        Assert.AreEqual(40u, stream.ReadInt(18));
        Assert.IsFalse(stream.ReadFlag()); // not corpse
        Assert.IsFalse(stream.ReadFlag()); // HealthMaxMask not set
        Assert.IsFalse(stream.ReadFlag()); // PositionMask not set
    }

    [TestMethod]
    public void PackUpdate_HealthMaxMask_WritesMaximumHp()
    {
        var prop = MakeProp(coid: 55, global: false, hp: 40);
        var stream = Pack(prop, GhostObject.HealthMaxMask, initial: false);

        Assert.IsFalse(stream.ReadFlag()); // Health
        Assert.IsTrue(stream.ReadFlag());  // HealthMax
        Assert.AreEqual(40u, stream.ReadInt(18));
        Assert.IsFalse(stream.ReadFlag()); // Position
    }

    [TestMethod]
    public void PackUpdate_HealthMask_Corpse_WritesDeathPayload()
    {
        var prop = MakeProp(coid: 51, global: false, hp: 0);
        prop.OnDeath(DeathType.Violent);
        prop.SetMurderer(new TFID(77, true));

        var stream = Pack(prop, GhostObject.HealthMask, initial: false);
        Assert.IsTrue(stream.ReadFlag());
        Assert.AreEqual(0u, stream.ReadInt(18));
        Assert.IsTrue(stream.ReadFlag()); // corpse
        Assert.IsTrue(stream.ReadFlag()); // recent death payload
        Assert.AreEqual((uint)DeathType.Violent, stream.ReadInt(3));
        stream.Read(out long murderer);
        Assert.AreEqual(77L, murderer);
        Assert.IsTrue(stream.ReadFlag()); // murderer global
    }

    [TestMethod]
    public void PackUpdate_PositionMask_WritesPoseWithZeroVelocityFlags()
    {
        var prop = MakeProp(coid: 52, global: false, hp: 10);
        prop.Position = new Vector3(1f, 2f, 3f);
        prop.Rotation = new Quaternion(0f, 0f, 0f, 1f);

        var stream = Pack(prop, GhostObject.PositionMask, initial: false);
        Assert.IsFalse(stream.ReadFlag()); // Health
        Assert.IsFalse(stream.ReadFlag()); // HealthMax
        Assert.IsTrue(stream.ReadFlag());  // Position
        stream.Read(out float x);
        stream.Read(out float y);
        stream.Read(out float z);
        Assert.AreEqual(1f, x);
        Assert.AreEqual(2f, y);
        Assert.AreEqual(3f, z);
        stream.Read(out float _);
        stream.Read(out float _);
        stream.Read(out float _);
        stream.Read(out float _);
        Assert.IsFalse(stream.ReadFlag()); // linear vel
        Assert.IsFalse(stream.ReadFlag()); // angular vel
    }

    [TestMethod]
    public void PackCommon_WritesIdentityAndFaction()
    {
        var prop = MakeProp(coid: 88, global: true, hp: 25);
        prop.Faction = 12;
        prop.CreateGhost();

        var stream = new BitStream(new byte[256], 256);
        prop.Ghost!.PackCommon(stream);
        stream.SetBitPosition(0);

        stream.Read(out long coid);
        Assert.AreEqual(88L, coid);
        Assert.IsTrue(stream.ReadFlag());
        Assert.AreEqual((uint)prop.CBID & 0xFFFFF, stream.ReadInt(20) & 0xFFFFF);
        Assert.AreEqual(25u, stream.ReadInt(18));
        stream.Read(out short faction);
        Assert.AreEqual((short)12, faction);
    }

    [TestMethod]
    public void PackUpdate_WithDiagEnabled_RecordsPackDelta()
    {
        GhostObjectDiag.Enabled = true;
        var prop = MakeProp(coid: 60, global: false, hp: 5);
        Pack(prop, GhostObject.HealthMask, initial: false);

        var snap = GhostObjectDiag.Snapshot();
        Assert.IsTrue(snap.Any(e => e.Name == "PackDelta"),
            "Plain GhostObject PackUpdate should record PackDelta when diag is on.");
    }

    [TestMethod]
    public void IsGhostVIsibleToMe_WithoutOwningConnection_IsFalse()
    {
        var ghost = new GhostObject();
        Assert.IsFalse(ghost.IsGhostVIsibleToMe(new GhostObject()));
    }

    [TestMethod]
    public void OnGhostAdd_AndOnGhostRemove_LinkParentGhost()
    {
        var prop = MakeProp(coid: 70, global: false, hp: 5);
        prop.CreateGhost();
        var ghost = prop.Ghost!;

        Assert.IsTrue(ghost.OnGhostAdd(new TNLConnection()));
        Assert.AreSame(ghost, prop.Ghost);

        // No live object refs → ClearGhost on remove.
        ghost.OnGhostRemove();
        Assert.IsNull(prop.Ghost);
    }

    [TestMethod]
    public void GetUpdatePriority_NullParents_UsesSkipBoost()
    {
        var ghost = new GhostObject();
        var scope = new GhostObject();
        var p = ghost.GetUpdatePriority(scope, GhostObject.PositionMask, updateSkips: 5);
        Assert.AreEqual(0.05f, p, 0.0001f);
    }

    [TestMethod]
    public void PackSingleSkill_SameParentTargetAndCaster_OmitsIds()
    {
        var prop = MakeProp(coid: 200, global: false, hp: 10);
        var ghost = prop.Ghost!;
        var parentId = prop.ObjectId;
        var skill = new AutoCore.Game.Packets.Sector.CreateSkillHeartbeat
        {
            SkillId = 42,
            SkillLevel = 3,
            SkillType = 1,
            LastTickCount = 100,
            DiceSeed = 7,
            Target = parentId,
            Caster = parentId,
            ForceDeath = false,
            DurationCountdown = 15,
        };

        var stream = new BitStream(new byte[256], 256);
        ghost.PackSingleSkill(stream, skill, size: 56, skillTargetType: 0);
        stream.SetBitPosition(0);

        Assert.AreEqual(42u, stream.ReadInt(14));
        Assert.AreEqual(3u, stream.ReadInt(8));
        Assert.AreEqual(1u, stream.ReadInt(8));
        Assert.IsTrue(stream.ReadFlag()); // skillTargetType & 0x100 == 0
        stream.Read(out int lastTick);
        stream.Read(out int seed);
        Assert.AreEqual(100, lastTick);
        Assert.AreEqual(7, seed);
        Assert.IsFalse(stream.ReadFlag()); // target same as parent
        Assert.IsFalse(stream.ReadFlag()); // force death
        Assert.AreEqual(15u, stream.ReadInt(10));
        Assert.IsFalse(stream.ReadFlag()); // caster same as parent
    }

    [TestMethod]
    public void PackSingleSkill_DifferentTargetAndCaster_WritesTfids()
    {
        var prop = MakeProp(coid: 201, global: true, hp: 10);
        var ghost = prop.Ghost!;
        var skill = new AutoCore.Game.Packets.Sector.CreateSkillHeartbeat
        {
            SkillId = 9,
            SkillLevel = 1,
            SkillType = 2,
            LastTickCount = 1,
            DiceSeed = 2,
            Target = new TFID(999, false),
            Caster = new TFID(888, true),
            ForceDeath = true,
            DurationCountdown = 3,
        };

        var stream = new BitStream(new byte[256], 256);
        ghost.PackSingleSkill(stream, skill, size: 56, skillTargetType: 0);
        stream.SetBitPosition(0);

        Assert.AreEqual(9u, stream.ReadInt(14));
        stream.ReadInt(8);
        stream.ReadInt(8);
        Assert.IsTrue(stream.ReadFlag());
        stream.Read(out int _);
        stream.Read(out int _);
        Assert.IsTrue(stream.ReadFlag()); // different target
        stream.Read(out long targetCoid);
        Assert.AreEqual(999L, targetCoid);
        Assert.IsFalse(stream.ReadFlag()); // target global false
        Assert.IsTrue(stream.ReadFlag()); // force death
        Assert.AreEqual(3u, stream.ReadInt(10));
        Assert.IsTrue(stream.ReadFlag()); // different caster
        stream.Read(out long casterCoid);
        Assert.AreEqual(888L, casterCoid);
        Assert.IsTrue(stream.ReadFlag()); // caster global
    }

    [TestMethod]
    public void PackSingleSkill_SkillTargetTypeBit_SkipsBody()
    {
        var prop = MakeProp(coid: 202, global: false, hp: 5);
        var ghost = prop.Ghost!;
        var skill = new AutoCore.Game.Packets.Sector.CreateSkillHeartbeat
        {
            SkillId = 1,
            SkillLevel = 0,
            SkillType = 0,
            Target = prop.ObjectId,
            Caster = prop.ObjectId,
        };

        var stream = new BitStream(new byte[64], 64);
        ghost.PackSingleSkill(stream, skill, size: 0, skillTargetType: 0x100);
        stream.SetBitPosition(0);
        stream.ReadInt(14);
        stream.ReadInt(8);
        stream.ReadInt(8);
        Assert.IsFalse(stream.ReadFlag()); // body skipped when bit set
    }

    [TestMethod]
    public void PackSkills_ZeroCount_OnlyWritesCountByte()
    {
        var prop = MakeProp(coid: 203, global: false, hp: 5);
        var stream = new BitStream(new byte[32], 32);
        prop.Ghost!.PackSkills(stream, prop);
        stream.SetBitPosition(0);
        // 8 bits of zero skill count
        Assert.AreEqual(0u, stream.ReadInt(8));
    }

    private static GraphicsObject MakeProp(long coid, bool global, int hp)
    {
        var prop = new GraphicsObject(GraphicsObjectType.Graphics);
        prop.SetCoid(coid, global);
        prop.InitializeHealthForTests(Math.Max(1, hp));
        if (hp == 0)
            prop.TakeDamage(prop.GetMaximumHP());
        prop.CreateGhost();
        return prop;
    }

    private static BitStream Pack(GraphicsObject prop, ulong mask, bool initial)
    {
        var stream = new BitStream(new byte[1024], 1024);
        NetObject.PIsInitialUpdate = initial;
        prop.Ghost!.PackUpdate(null, mask, stream);
        stream.SetBitPosition(0);
        return stream;
    }
}
