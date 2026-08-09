using AutoCore.Game.Structures;

namespace AutoCore.Sim.Collision;

/// <summary>
/// Parses a physics.glm .cache entry — one convex hull per file. Byte layout (validated on 10
/// real entries, docs/reconstruction/physics/hull-format-findings.md):
///   int32 planeCount; planeCount × float4 (nx,ny,nz,d — unit outward normals, n·v+d ≤ 0);
///   int32 vertCount;  vertCount  × float4 (x,y,z, w = 0xCCCCCCCC uninitialized pad);
///   tail (80 bytes): float volume, float mass(=1.0), 8×0xCC pad, float4 centerOfMass,
///                    3 × float4 unit-mass inertia tensor rows.
/// The tail is parsed but only COM is retained (future: chassis COM for the physics tier).
/// </summary>
public static class CacheHullParser
{
    public static ConvexHull Parse(byte[] data)
    {
        ArgumentNullException.ThrowIfNull(data);
        using var reader = new BinaryReader(new MemoryStream(data, writable: false));

        var planeCount = reader.ReadInt32();
        if (planeCount is <= 0 or > 4096)
            throw new InvalidDataException($"Implausible plane count {planeCount}");

        var planes = new HullPlane[planeCount];
        for (var i = 0; i < planeCount; i++)
        {
            planes[i] = new HullPlane(
                reader.ReadSingle(), reader.ReadSingle(), reader.ReadSingle(), reader.ReadSingle());
        }

        var vertCount = reader.ReadInt32();
        if (vertCount is <= 0 or > 4096)
            throw new InvalidDataException($"Implausible vertex count {vertCount}");

        var vertices = new Vector3[vertCount];
        for (var i = 0; i < vertCount; i++)
        {
            vertices[i] = new Vector3(reader.ReadSingle(), reader.ReadSingle(), reader.ReadSingle());
            reader.ReadSingle(); // w pad (0xCCCCCCCC)
        }

        return new ConvexHull(planes, vertices);
    }
}

/// <summary>
/// Test-support parser for the ASCII .tk source (vertCount, verts, triCount, "3 i0 i1 i2"
/// lines). Used to cross-validate .cache parsing; not part of the runtime path.
/// </summary>
public static class TkHullParser
{
    public static Vector3[] ParseVertices(string text)
    {
        ArgumentNullException.ThrowIfNull(text);
        var tokens = text.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
        var count = int.Parse(tokens[0], System.Globalization.CultureInfo.InvariantCulture);
        var verts = new Vector3[count];
        for (var i = 0; i < count; i++)
        {
            verts[i] = new Vector3(
                ParseF(tokens[1 + i * 3]),
                ParseF(tokens[2 + i * 3]),
                ParseF(tokens[3 + i * 3]));
        }

        return verts;
    }

    private static float ParseF(string token) =>
        float.Parse(token, System.Globalization.CultureInfo.InvariantCulture);
}
