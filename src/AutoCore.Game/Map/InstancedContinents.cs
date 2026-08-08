namespace AutoCore.Game.Map;

/// <summary>
/// Gates which continents get a private per-player <see cref="SectorMap"/> instance instead of
/// the shared copy. Retail instanced the three tutorial/starting areas by default; every player
/// entering one gets their own world copy and never sees other players there.
/// <para>
/// Off by default (<c>ActiveSet == null</c>): the Global process must never allocate per-player
/// instances — its maps exist only to seed a new character's LastTownId/pose before the Sector
/// handoff. Only <c>AutoCore.Sector/Program.cs</c> calls <see cref="EnableForSector"/>.
/// </para>
/// <para>
/// The set is explicit rather than derived from <c>ContinentObject.IsPersistent</c> — the
/// authored wad.xml flags are unverified for these maps.
/// </para>
/// </summary>
public static class InstancedContinents
{
    /// <summary>698 Tierra Roja Dam, 707 Hestia Ark Bay 313, 708 The Wastes.</summary>
    private static readonly HashSet<int> Default = new() { 698, 707, 708 };

    /// <summary>Null = instancing disabled entirely (Global default).</summary>
    internal static IReadOnlySet<int> ActiveSet { get; private set; }

    /// <summary>Activates instancing for the default starting-area set. Sector process only.</summary>
    public static void EnableForSector() => ActiveSet = Default;

    /// <summary>Test seam. Pass null to disable (restore Global-default state).</summary>
    internal static void SetForTests(IReadOnlySet<int> set) => ActiveSet = set;

    /// <summary>True when players entering this continent get a private map instance.</summary>
    public static bool IsInstanced(int continentId) => ActiveSet?.Contains(continentId) == true;
}
