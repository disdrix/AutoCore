using System.Runtime.CompilerServices;
using AutoCore.Game.CloneBases;
using AutoCore.Game.CloneBases.Specifics;
using AutoCore.Game.Structures;
using AutoCore.Sim.Physics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Sim.Tests.Physics;

[TestClass]
public class SimVehicleParamsTests
{
    private static CloneBaseVehicle CloneBase(VehicleSpecific vs, float mass)
    {
        var cb = (CloneBaseVehicle)RuntimeHelpers.GetUninitializedObject(typeof(CloneBaseVehicle));
        cb.VehicleSpecific = vs;
        cb.SimpleObjectSpecific = new SimpleObjectSpecific { Mass = mass };
        return cb;
    }

    [TestMethod]
    public void FromCloneBase_ComputesGearingGovernorTopSpeed()
    {
        // v = R · MaxRPM·(π/30) / (TransmissionRatio · topGear)
        //   = 0.5 · 6000·0.104719758 / (3.0 · 1.0) = 104.72 m/s, clamped by AbsoluteTopSpeed 40.
        var vs = new VehicleSpecific
        {
            WheelRadius = new[] { 0.5f, 0.5f, 0.5f, 0.5f, 0f, 0f },
            MaximumRPMMax = 6000f,
            TransmissionRatio = 3.0f,
            NumberOfGears = 4,
            GearRatios = new[] { 3.5f, 2.2f, 1.5f, 1.0f, 0f },
            AbsoluteTopSpeed = 40f,
            SteeringMaxAngle = 0.6f,
            SteeringFullSpeedLimit = 15f,
        };

        var p = SimVehicleParams.FromCloneBase(CloneBase(vs, mass: 1500f));

        Assert.AreEqual(40f, p.TopSpeed, 0.01f, "AbsoluteTopSpeed must clamp the gearing precompute");
        Assert.AreEqual(1500f, p.MassKg);
        Assert.AreEqual(0.6f, p.SteeringMaxAngleRad);

        vs.AbsoluteTopSpeed = -1f; // retail: −1 = uncapped
        var uncapped = SimVehicleParams.FromCloneBase(CloneBase(vs, mass: 1500f));
        Assert.AreEqual(0.5f * 6000f * 0.104719758f / 3.0f, uncapped.TopSpeed, 0.5f);
    }

    [TestMethod]
    public void FromCloneBase_MissingData_FallsBackToDrivableDefaults()
    {
        var p = SimVehicleParams.FromCloneBase(CloneBase(new VehicleSpecific(), mass: 0f));

        Assert.IsTrue(p.MassKg > 0f);
        Assert.IsTrue(p.TopSpeed is > 5f and < 80f);
        Assert.IsTrue(p.SteeringMaxAngleRad > 0f);
        Assert.IsTrue(p.SuspensionLength > 0f && p.SuspensionStrength > 0f);
        Assert.IsTrue(p.WheelBase > 1f && p.WheelRadius > 0.1f);
    }

    [TestMethod]
    public void FromCloneBase_TireFrictionComesFromWheelset()
    {
        // clonebase.wad probe 2026-08-09: WheelSetSpecific.Friction shorts ARE the mu values
        // (ed_whl_car = [3,2,3,4,3,2]) — using 1.0 gave a third of retail grip live.
        var ws = (CloneBaseWheelSet)System.Runtime.CompilerServices.RuntimeHelpers
            .GetUninitializedObject(typeof(CloneBaseWheelSet));
        ws.WheelSetSpecific = new WheelSetSpecific { Friction = new short[] { 3, 2, 3, 4, 3, 2 } };

        var p = SimVehicleParams.FromCloneBase(CloneBase(new VehicleSpecific(), 900f), ws);

        Assert.AreEqual((3 + 2 + 3 + 4 + 3 + 2) / 6f, p.MuBase, 0.01f);

        var noWheelset = SimVehicleParams.FromCloneBase(CloneBase(new VehicleSpecific(), 900f));
        Assert.AreEqual(3f, noWheelset.MuBase, 0.01f, "fallback must match typical retail mu, not 1.0");
    }

    [TestMethod]
    public void FromCloneBase_WheelBaseFromHardPointSpan()
    {
        var vs = new VehicleSpecific
        {
            WheelHardPoints = new[]
            {
                new Vector3(-0.9f, 0f, 1.6f),
                new Vector3(0.9f, 0f, 1.6f),
                new Vector3(-0.9f, 0f, -1.4f),
                new Vector3(0.9f, 0f, -1.4f),
                new Vector3(0f, 0f, 0f),
                new Vector3(0f, 0f, 0f),
            },
        };

        var p = SimVehicleParams.FromCloneBase(CloneBase(vs, mass: 1200f));

        Assert.AreEqual(3.0f, p.WheelBase, 0.001f);
    }
}
