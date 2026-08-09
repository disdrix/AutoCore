using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AutoCore.Game.Tests.TNL;

using AutoCore.Game.Entities;
using AutoCore.Game.TNL;

/// <summary>
/// SS-32 tripwires: a VehicleMoved/CreatureMoved arriving before the character (or vehicle) is
/// bound must be dropped, not NRE into the dispatch catch as a NET-002 "malformed packet" —
/// that silently loses the whole move+fire+target update.
/// </summary>
[TestClass]
public class VehicleMovedNullGuardTests
{
    // VehicleMoved wire payload after the opcode: 92-byte ObjectMoved base + 32-byte vehicle tail.
    private const int VehicleMovedPayloadSize = 124;

    private static BinaryReader ZeroPayload(int size) =>
        new(new MemoryStream(new byte[size]));

    [TestMethod]
    public void VehicleMoved_NoCharacterBound_IsDroppedWithoutThrowing()
    {
        var conn = new TNLConnection { CurrentCharacter = null };

        conn.HandleVehicleMovedPacket(ZeroPayload(VehicleMovedPayloadSize));
    }

    [TestMethod]
    public void VehicleMoved_CharacterWithoutVehicle_IsDroppedWithoutThrowing()
    {
        var conn = new TNLConnection();
        var character = new Character();
        character.SetCoid(96001, true);
        conn.CurrentCharacter = character;

        conn.HandleVehicleMovedPacket(ZeroPayload(VehicleMovedPayloadSize));
    }

    [TestMethod]
    public void CreatureMoved_NoCharacterBound_IsDroppedWithoutThrowing()
    {
        var conn = new TNLConnection { CurrentCharacter = null };

        conn.HandleCreatureMovedPacket(ZeroPayload(VehicleMovedPayloadSize));
    }
}
