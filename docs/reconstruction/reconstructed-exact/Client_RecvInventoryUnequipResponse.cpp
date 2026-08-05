// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_RecvInventoryUnequipResponse, OutputDebugStringA, sprintf.
//  - Return sites: 1.

// =============================================================================
// Client_RecvInventoryUnequipResponse
// -----------------------------------------------------------------------------
// Purpose:  S2C InventoryUnequipResponse (opcode 0x203F). On failure
//           (success byte == 0) prints an unsync debug line with item COID;
//           success is a no-op (no inventory mutation on the client).
//
// Address:  0x008087e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008087e0
// System:   inventory-transfer
//
// Convention: Packet pointer in EAX (decomp in_EAX / dispatch thunk).
//
// Packet layout:
//   +0x08  u32  item COID (failure message)
//   +0x10  u8   success (0 = fail → debug string only)
//
// Control flow summary:
//   1) if success@+0x10 == 0:
//        sprintf unsync message with COID@+0x08
//        OutputDebugStringA
//   2) return (success path empty)
//
// Exactness: Trivial CF mirrors raw. Bit-for-bit deferred.
// Dual reviews: not required (debug-only failure path).
// =============================================================================

extern "C" void OutputDebugStringA(const char*);

/// @note packet arrives in EAX (retail dispatch).
void Client_RecvInventoryUnequipResponse(void)
{
    int pPacket = 0; // EAX at entry (decompiler in_EAX)
    char szMsg[128];

    // Only failure path is observable in this unit.
    if (*(char*)(pPacket + 0x10) == '\0') {
        sprintf(
            szMsg,
            "Your Inventory is unsynchronized. VOGClient::InventoryUnequip_Response Failed on coid: %i\n",
            *(unsigned*)(pPacket + 8));
        OutputDebugStringA(szMsg);
    }
}
