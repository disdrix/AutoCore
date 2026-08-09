using AutoCore.Game.Structures;

namespace AutoCore.Sim.Collision;

/// <summary>Half-space n·p + d = 0, outward normal; inside is n·p + d ≤ 0.</summary>
public readonly struct HullPlane
{
    public HullPlane(float nx, float ny, float nz, float d)
    {
        NormalX = nx;
        NormalY = ny;
        NormalZ = nz;
        D = d;
    }

    public float NormalX { get; }
    public float NormalY { get; }
    public float NormalZ { get; }
    public float D { get; }
}

/// <summary>
/// One convex hull from a physics.glm .cache entry (local space). Raycast is the classic
/// plane-slab clip: enter at the latest front-facing plane, exit at the earliest back-facing
/// one; hit when enter ≤ exit within range (the whole reason .cache is preferred over .tk —
/// planes come precomputed; docs/reconstruction/physics/hull-format-findings.md).
/// </summary>
public sealed class ConvexHull
{
    public ConvexHull(HullPlane[] planes, Vector3[] vertices)
    {
        Planes = planes ?? throw new ArgumentNullException(nameof(planes));
        Vertices = vertices ?? throw new ArgumentNullException(nameof(vertices));

        var min = new Vector3(float.MaxValue, float.MaxValue, float.MaxValue);
        var max = new Vector3(float.MinValue, float.MinValue, float.MinValue);
        foreach (var v in vertices)
        {
            min = new Vector3(MathF.Min(min.X, v.X), MathF.Min(min.Y, v.Y), MathF.Min(min.Z, v.Z));
            max = new Vector3(MathF.Max(max.X, v.X), MathF.Max(max.Y, v.Y), MathF.Max(max.Z, v.Z));
        }

        LocalBoundsMin = min;
        LocalBoundsMax = max;
    }

    public HullPlane[] Planes { get; }
    public Vector3[] Vertices { get; }
    public Vector3 LocalBoundsMin { get; }
    public Vector3 LocalBoundsMax { get; }

    /// <summary>
    /// Local-space raycast. Returns the entry distance along <paramref name="direction"/>
    /// (0 when the origin starts inside) and the entry plane's outward normal.
    /// </summary>
    public bool Raycast(Vector3 origin, Vector3 direction, float maxDistance,
        out float distance, out Vector3 normal)
    {
        distance = 0f;
        normal = default;

        var tEnter = 0f;
        var tExit = maxDistance;
        var enterNormal = default(Vector3);
        var entered = false;

        foreach (var p in Planes)
        {
            var denom = p.NormalX * direction.X + p.NormalY * direction.Y + p.NormalZ * direction.Z;
            var dist = p.NormalX * origin.X + p.NormalY * origin.Y + p.NormalZ * origin.Z + p.D;

            if (MathF.Abs(denom) < 1e-9f)
            {
                if (dist > 0f)
                    return false; // parallel and outside this half-space
                continue;
            }

            var t = -dist / denom;
            if (denom < 0f)
            {
                // Front-facing: entering the half-space at t.
                if (t > tEnter)
                {
                    tEnter = t;
                    enterNormal = new Vector3(p.NormalX, p.NormalY, p.NormalZ);
                    entered = true;
                }
            }
            else
            {
                // Back-facing: exiting at t.
                if (t < tExit)
                    tExit = t;
            }

            if (tEnter > tExit)
                return false;
        }

        distance = tEnter;
        normal = entered ? enterNormal : default;
        return tEnter <= tExit && tEnter <= maxDistance;
    }
}
