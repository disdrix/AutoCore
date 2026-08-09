using AutoCore.Sim.Ai;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Ai;

/// <summary>
/// Live 2026-08-08: the clone floated 1–2 m regardless of which fixed Y convention we
/// published, so the clone now calibrates its height offset from the OWNER's observed
/// (vehicleY − heightfieldY) delta — whatever makes the player's own vehicle look grounded is,
/// by definition, the convention the client renders.
/// </summary>
[TestClass]
public class GroundOffsetCalibratorTests
{
    [TestMethod]
    public void ConvergesToObservedOwnerDelta()
    {
        var calibrator = new GroundOffsetCalibrator();

        for (var i = 0; i < 100; i++)
            calibrator.Observe(ownerY: 101.2f, terrainYAtOwner: 100f, dt: 0.05f);

        Assert.AreEqual(1.2f, calibrator.Offset, 0.05f);
    }

    [TestMethod]
    public void IgnoresAirborneSpikes()
    {
        var calibrator = new GroundOffsetCalibrator();
        for (var i = 0; i < 100; i++)
            calibrator.Observe(101.0f, 100f, 0.05f);

        // Player jumps a ridge: delta spikes to 8 m — must be rejected, not averaged in.
        for (var i = 0; i < 20; i++)
            calibrator.Observe(108f, 100f, 0.05f);

        Assert.AreEqual(1.0f, calibrator.Offset, 0.1f, "airborne deltas must not drag the offset up");
    }

    [TestMethod]
    public void StartsNeutralUntilFirstObservation()
    {
        Assert.AreEqual(0f, new GroundOffsetCalibrator().Offset);
    }
}
