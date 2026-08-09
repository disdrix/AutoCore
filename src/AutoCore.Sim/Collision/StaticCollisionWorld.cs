using AutoCore.Game.Structures;

namespace AutoCore.Sim.Collision;

/// <summary>
/// Immutable oriented-convex-hull world for a map's static objects. Built once (Add* then
/// Build), queried from the sector tick. Broadphase: uniform XZ grid of world-AABB overlaps.
/// Unlike the AABB proxies in CompositeVehicleCollisionQuery, placements keep their rotation
/// and true hull shape.
/// </summary>
public sealed class StaticCollisionWorld
{
    private const float CellSize = 32f;

    private readonly List<Instance> _instances = new();
    private readonly Dictionary<(int, int), List<int>> _grid = new();
    private bool _built;

    public int InstanceCount => _instances.Count;

    public void Add(ConvexHull hull, Vector3 position, Quaternion rotation, float scale)
        => Add(hull, position, rotation, scale, label: null);

    /// <summary>Label identifies the source object in diagnostics (e.g. "physicsName#coid").</summary>
    public void Add(ConvexHull hull, Vector3 position, Quaternion rotation, float scale, string label)
    {
        ArgumentNullException.ThrowIfNull(hull);
        if (_built)
            throw new InvalidOperationException("world already built");
        if (scale <= 0f || !float.IsFinite(scale))
            scale = 1f;

        _instances.Add(new Instance(hull, position, rotation, scale, label));
    }

    // World AABB per instance (SoA) for cheap ray/sphere pre-rejects before the full
    // oriented-hull test — dense cells previously paid an inverse-rotate per candidate.
    private float[] _aabbMinX, _aabbMinY, _aabbMinZ, _aabbMaxX, _aabbMaxY, _aabbMaxZ;

    /// <summary>Freeze and index. Idempotent.</summary>
    public void Build()
    {
        if (_built)
            return;
        _built = true;

        _aabbMinX = new float[_instances.Count];
        _aabbMinY = new float[_instances.Count];
        _aabbMinZ = new float[_instances.Count];
        _aabbMaxX = new float[_instances.Count];
        _aabbMaxY = new float[_instances.Count];
        _aabbMaxZ = new float[_instances.Count];

        for (var i = 0; i < _instances.Count; i++)
        {
            var (min, max) = _instances[i].WorldBounds();
            _aabbMinX[i] = min.X; _aabbMinY[i] = min.Y; _aabbMinZ[i] = min.Z;
            _aabbMaxX[i] = max.X; _aabbMaxY[i] = max.Y; _aabbMaxZ[i] = max.Z;

            var c0 = (int)MathF.Floor(min.X / CellSize);
            var c1 = (int)MathF.Floor(max.X / CellSize);
            var r0 = (int)MathF.Floor(min.Z / CellSize);
            var r1 = (int)MathF.Floor(max.Z / CellSize);
            for (var c = c0; c <= c1; c++)
            {
                for (var r = r0; r <= r1; r++)
                {
                    if (!_grid.TryGetValue((c, r), out var list))
                        _grid[(c, r)] = list = new List<int>();
                    list.Add(i);
                }
            }
        }
    }

    public bool Raycast(Vector3 origin, Vector3 direction, float maxDistance,
        out float distance, out Vector3 normal)
        => Raycast(origin, direction, maxDistance, out distance, out normal, out _);

    // Per-thread visited-stamp dedup: queries run in the sector tick AND (scale-out) from a
    // parallel think phase, so scratch is [ThreadStatic]. Baseline profiling showed the old
    // per-call HashSet + iterator allocated 5-15 KB per vehicle-tick — the dominant GC load.
    [ThreadStatic] private static int[] _visitStamps;
    [ThreadStatic] private static int _visitGeneration;

    private static int[] PrepareStamps(int instanceCount, out int generation)
    {
        var stamps = _visitStamps;
        if (stamps == null || stamps.Length < instanceCount)
        {
            stamps = new int[Math.Max(instanceCount, 256)];
            _visitStamps = stamps;
            _visitGeneration = 0;
        }

        generation = ++_visitGeneration;
        if (generation == int.MaxValue)
        {
            Array.Clear(stamps);
            _visitGeneration = 1;
            generation = 1;
        }

        return stamps;
    }

    public bool Raycast(Vector3 origin, Vector3 direction, float maxDistance,
        out float distance, out Vector3 normal, out string hitLabel)
    {
        distance = float.MaxValue;
        normal = default;
        hitLabel = null;
        if (!_built || _instances.Count == 0 || maxDistance <= 0f)
            return false;

        var stamps = PrepareStamps(_instances.Count, out var generation);
        var endX = origin.X + direction.X * maxDistance;
        var endZ = origin.Z + direction.Z * maxDistance;
        var c0 = (int)MathF.Floor(MathF.Min(origin.X, endX) / CellSize);
        var c1 = (int)MathF.Floor(MathF.Max(origin.X, endX) / CellSize);
        var r0 = (int)MathF.Floor(MathF.Min(origin.Z, endZ) / CellSize);
        var r1 = (int)MathF.Floor(MathF.Max(origin.Z, endZ) / CellSize);

        var found = false;
        for (var c = c0; c <= c1; c++)
        {
            for (var r = r0; r <= r1; r++)
            {
                if (!_grid.TryGetValue((c, r), out var list))
                    continue;
                for (var k = 0; k < list.Count; k++)
                {
                    var index = list[k];
                    if (stamps[index] == generation)
                        continue;
                    stamps[index] = generation;

                    if (!RayIntersectsAabb(index, origin, direction, MathF.Min(maxDistance, distance)))
                        continue;

                    var inst = _instances[index];
                    if (!inst.Raycast(origin, direction, maxDistance, out var d, out var n))
                        continue;
                    if (d < distance)
                    {
                        distance = d;
                        normal = n;
                        hitLabel = inst.Label;
                        found = true;
                    }
                }
            }
        }

        return found;
    }

    public bool SphereOverlap(Vector3 center, float radius)
        => SphereOverlap(center, radius, out _);

    public bool SphereOverlap(Vector3 center, float radius, out string hitLabel)
    {
        hitLabel = null;
        if (!_built)
            return false;

        var stamps = PrepareStamps(_instances.Count, out var generation);
        var c0 = (int)MathF.Floor((center.X - radius) / CellSize);
        var c1 = (int)MathF.Floor((center.X + radius) / CellSize);
        var r0 = (int)MathF.Floor((center.Z - radius) / CellSize);
        var r1 = (int)MathF.Floor((center.Z + radius) / CellSize);
        for (var c = c0; c <= c1; c++)
        {
            for (var r = r0; r <= r1; r++)
            {
                if (!_grid.TryGetValue((c, r), out var list))
                    continue;
                for (var k = 0; k < list.Count; k++)
                {
                    var index = list[k];
                    if (stamps[index] == generation)
                        continue;
                    stamps[index] = generation;
                    if (center.X < _aabbMinX[index] - radius || center.X > _aabbMaxX[index] + radius
                        || center.Y < _aabbMinY[index] - radius || center.Y > _aabbMaxY[index] + radius
                        || center.Z < _aabbMinZ[index] - radius || center.Z > _aabbMaxZ[index] + radius)
                    {
                        continue;
                    }

                    if (_instances[index].SphereOverlap(center, radius))
                    {
                        hitLabel = _instances[index].Label;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    /// <summary>Standard slab test against the instance's world AABB (cheap pre-reject).</summary>
    private bool RayIntersectsAabb(int index, Vector3 origin, Vector3 direction, float maxDistance)
    {
        var tMin = 0f;
        var tMax = maxDistance;

        // X slab
        if (MathF.Abs(direction.X) < 1e-9f)
        {
            if (origin.X < _aabbMinX[index] || origin.X > _aabbMaxX[index])
                return false;
        }
        else
        {
            var inv = 1f / direction.X;
            var t1 = (_aabbMinX[index] - origin.X) * inv;
            var t2 = (_aabbMaxX[index] - origin.X) * inv;
            if (t1 > t2) (t1, t2) = (t2, t1);
            tMin = MathF.Max(tMin, t1);
            tMax = MathF.Min(tMax, t2);
            if (tMin > tMax)
                return false;
        }

        // Y slab
        if (MathF.Abs(direction.Y) < 1e-9f)
        {
            if (origin.Y < _aabbMinY[index] || origin.Y > _aabbMaxY[index])
                return false;
        }
        else
        {
            var inv = 1f / direction.Y;
            var t1 = (_aabbMinY[index] - origin.Y) * inv;
            var t2 = (_aabbMaxY[index] - origin.Y) * inv;
            if (t1 > t2) (t1, t2) = (t2, t1);
            tMin = MathF.Max(tMin, t1);
            tMax = MathF.Min(tMax, t2);
            if (tMin > tMax)
                return false;
        }

        // Z slab
        if (MathF.Abs(direction.Z) < 1e-9f)
        {
            if (origin.Z < _aabbMinZ[index] || origin.Z > _aabbMaxZ[index])
                return false;
        }
        else
        {
            var inv = 1f / direction.Z;
            var t1 = (_aabbMinZ[index] - origin.Z) * inv;
            var t2 = (_aabbMaxZ[index] - origin.Z) * inv;
            if (t1 > t2) (t1, t2) = (t2, t1);
            tMin = MathF.Max(tMin, t1);
            tMax = MathF.Min(tMax, t2);
            if (tMin > tMax)
                return false;
        }

        return true;
    }

    private readonly struct Instance
    {
        private readonly ConvexHull _hull;
        private readonly Vector3 _position;
        private readonly float _scale;

        public string Label { get; }
        // Rotation as quaternion components for vector rotate (q v q^-1).
        private readonly float _qx, _qy, _qz, _qw;

        public Instance(ConvexHull hull, Vector3 position, Quaternion rotation, float scale, string label)
        {
            _hull = hull;
            _position = position;
            _scale = scale;
            Label = label;
            var len = MathF.Sqrt(
                rotation.X * rotation.X + rotation.Y * rotation.Y +
                rotation.Z * rotation.Z + rotation.W * rotation.W);
            if (len < 1e-6f)
            {
                _qx = 0f; _qy = 0f; _qz = 0f; _qw = 1f;
            }
            else
            {
                _qx = rotation.X / len;
                _qy = rotation.Y / len;
                _qz = rotation.Z / len;
                _qw = rotation.W / len;
            }
        }

        public bool Raycast(Vector3 origin, Vector3 direction, float maxDistance,
            out float distance, out Vector3 normal)
        {
            // World → local: inverse-rotate the offset, divide by uniform scale. Distances along
            // a unit direction scale by 1/scale in local space, so convert the budget and the
            // result back with the same factor.
            var localOrigin = InverseRotate(new Vector3(
                origin.X - _position.X, origin.Y - _position.Y, origin.Z - _position.Z));
            localOrigin = new Vector3(localOrigin.X / _scale, localOrigin.Y / _scale, localOrigin.Z / _scale);
            var localDir = InverseRotate(direction);

            if (!_hull.Raycast(localOrigin, localDir, maxDistance / _scale, out var localDist, out var localNormal))
            {
                distance = 0f;
                normal = default;
                return false;
            }

            distance = localDist * _scale;
            normal = Rotate(localNormal);
            return true;
        }

        public bool SphereOverlap(Vector3 center, float radius)
        {
            var local = InverseRotate(new Vector3(
                center.X - _position.X, center.Y - _position.Y, center.Z - _position.Z));
            local = new Vector3(local.X / _scale, local.Y / _scale, local.Z / _scale);
            var localRadius = radius / _scale;

            // Max plane distance decides: inside all planes (≤0) or within radius of the surface.
            var maxD = float.MinValue;
            foreach (var p in _hull.Planes)
            {
                var d = p.NormalX * local.X + p.NormalY * local.Y + p.NormalZ * local.Z + p.D;
                maxD = MathF.Max(maxD, d);
                if (d > localRadius)
                    return false;
            }

            return maxD <= localRadius;
        }

        public (Vector3 Min, Vector3 Max) WorldBounds()
        {
            var min = new Vector3(float.MaxValue, float.MaxValue, float.MaxValue);
            var max = new Vector3(float.MinValue, float.MinValue, float.MinValue);
            var lb = _hull.LocalBoundsMin;
            var ub = _hull.LocalBoundsMax;
            for (var i = 0; i < 8; i++)
            {
                var corner = new Vector3(
                    ((i & 1) == 0 ? lb.X : ub.X) * _scale,
                    ((i & 2) == 0 ? lb.Y : ub.Y) * _scale,
                    ((i & 4) == 0 ? lb.Z : ub.Z) * _scale);
                var world = Rotate(corner);
                world = new Vector3(world.X + _position.X, world.Y + _position.Y, world.Z + _position.Z);
                min = new Vector3(MathF.Min(min.X, world.X), MathF.Min(min.Y, world.Y), MathF.Min(min.Z, world.Z));
                max = new Vector3(MathF.Max(max.X, world.X), MathF.Max(max.Y, world.Y), MathF.Max(max.Z, world.Z));
            }

            return (min, max);
        }

        private Vector3 Rotate(Vector3 v) => RotateBy(_qx, _qy, _qz, _qw, v);

        private Vector3 InverseRotate(Vector3 v) => RotateBy(-_qx, -_qy, -_qz, _qw, v);

        private static Vector3 RotateBy(float qx, float qy, float qz, float qw, Vector3 v)
        {
            // v' = v + 2q×(q×v + w·v)
            var cx = qy * v.Z - qz * v.Y + qw * v.X;
            var cy = qz * v.X - qx * v.Z + qw * v.Y;
            var cz = qx * v.Y - qy * v.X + qw * v.Z;
            return new Vector3(
                v.X + 2f * (qy * cz - qz * cy),
                v.Y + 2f * (qz * cx - qx * cz),
                v.Z + 2f * (qx * cy - qy * cx));
        }
    }
}
