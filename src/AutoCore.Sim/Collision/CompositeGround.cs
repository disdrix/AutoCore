using AutoCore.Game.Npc;
using AutoCore.Game.Structures;

namespace AutoCore.Sim.Collision;

/// <summary>
/// Merges the terrain heightfield with hull TOP surfaces so bridges, decks, ramps and low
/// ledges are drivable (live 2026-08-09: hulls were obstacles only, so the clone clipped
/// through bridges instead of driving on them). A downward ray starts step-up above the
/// vehicle's current height, which naturally resolves the two bridge cases:
/// on the deck (ray starts above it → deck is ground) vs under it (ray starts below the deck
/// → deck is ignored, terrain is ground).
/// </summary>
public static class CompositeGround
{
    /// <summary>
    /// Maximum ledge the vehicle can drive up onto (m). Was 1.5 — that made 1.2 m props
    /// "climbable ground," blinding avoidance and the hard block to anything below it
    /// (live 2026-08-09: avoidance/unstuck got worse). Real bridge decks are reached by
    /// ramps, not vertical steps, so kerb height is enough.
    /// </summary>
    public const float StepUpHeight = 0.6f;

    public static TerrainContactPlane.HeightSample Wrap(
        TerrainContactPlane.HeightSample terrain,
        StaticCollisionWorld hulls,
        float referenceY)
    {
        if (hulls == null)
            return terrain;

        var sampler = new Sampler();
        sampler.Update(terrain, hulls, referenceY);
        return sampler.Delegate;
    }

    /// <summary>
    /// Reusable composite sampler: one instance per brain, fields updated per step. The old
    /// per-step closure was a measurable share of the 5-15 KB/vehicle-tick GC load.
    /// </summary>
    public sealed class Sampler
    {
        private TerrainContactPlane.HeightSample _terrain;
        private StaticCollisionWorld _hulls;
        private float _referenceY;

        public Sampler()
        {
            Delegate = Sample;
        }

        public TerrainContactPlane.HeightSample Delegate { get; }

        public void Update(TerrainContactPlane.HeightSample terrain, StaticCollisionWorld hulls, float referenceY)
        {
            _terrain = terrain;
            _hulls = hulls;
            _referenceY = referenceY;
        }

        private bool Sample(float x, float z, out float y)
        {
            var terrain = _terrain;
            var hulls = _hulls;
            var referenceY = _referenceY;

            var hasTerrain = terrain(x, z, out var terrainY);
            if (!hasTerrain)
                terrainY = float.MinValue;

            var rayStart = referenceY + StepUpHeight;
            var rayLength = rayStart - MathF.Min(terrainY, referenceY - 10f);
            if (rayLength > 0f
                && hulls.Raycast(new Vector3(x, rayStart, z), new Vector3(0f, -1f, 0f), rayLength,
                    out var distance, out var normal)
                && normal.Y > 0.3f) // support requires an upward-facing surface, not a wall side
            {
                var hullTop = rayStart - distance;
                if (hullTop > terrainY)
                {
                    y = hullTop;
                    return true;
                }
            }

            y = hasTerrain ? terrainY : 0f;
            return hasTerrain;
        }
    }
}
