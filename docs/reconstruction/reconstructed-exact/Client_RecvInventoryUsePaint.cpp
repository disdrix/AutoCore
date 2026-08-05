// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: Client_RecvInventoryUsePaint, FUN_004faaf0, FUN_004fab40, FUN_004fcd80, FUN_0051f4e0, Object_ResolveFromTFID.
//  - Return sites: 1.

// =============================================================================
// Client_RecvInventoryUsePaint
// -----------------------------------------------------------------------------
// Purpose:  S2C apply vehicle paint / color from an inventory-use path. Resolves
//           target TFID, requires clone type 0x0E (vehicle), applies paint
//           channel helpers, optional local-vehicle refresh.
//
// Address:  0x008095f0  (autoassault.exe, image base 0x400000)
// Stable:   aa_008095f0
// System:   inventory-transfer
//
// Convention: pGameState stack arg; packet base in EDI (unaff_EDI).
//
// Packet fields:
//   +0x10  TFID target vehicle
//   +0x20  u8   paint / color byte
//   +0x21  u8   paint path selector (0 → FUN_004faaf0, 1 → FUN_004fab40)
//
// Control flow summary:
//   1) obj = Object_ResolveFromTFID(packet+0x10); null → return
//   2) require clone type @ obj link +0x38 == 0x0E (vehicle)
//   3) vtbl+0x1d4 body/handle must be non-null
//   4) path@+0x21: 0 → FUN_004faaf0(color); 1 → FUN_004fab40(color)
//   5) if obj == local vehicle char+0xcd0 → FUN_0051f4e0(0)
//   6) FUN_004fcd80(0) terminal refresh
//
// Exactness: CF mirrors raw; body vcall width noted. Bit-for-bit deferred.
// Dual reviews: pending (paint specialty path).
// =============================================================================

extern int* Object_ResolveFromTFID(void* pTfid);
extern void FUN_004faaf0(unsigned char paintByte);
extern void FUN_004fab40(unsigned char paintByte);
extern void FUN_0051f4e0(int);
extern void FUN_004fcd80(int);

/// @param pGameState  Client / game state host.
/// @note packet base = unaff_EDI at entry.
void Client_RecvInventoryUsePaint(int pGameState)
{
    int* pObj;
    int nBody;
    int pPacket = 0; // EDI residual holding packet

    pObj = Object_ResolveFromTFID((void*)(pPacket + 0x10));
    if (pObj == 0) {
        return;
    }
    // clonebase type @ obj[0x2a]+0x38 must be 0x0E (vehicle)
    if (*(int*)(pObj[0x2a] + 0x38) != 0x0E) {
        return;
    }
    // raw: nBody = (**(code **)(*pObj + 0x1d4))(); null → return
    nBody = 0;
    (void)nBody;

    if (*(char*)(pPacket + 0x21) == 0) {
        FUN_004faaf0(*(unsigned char*)(pPacket + 0x20));
    } else if (*(char*)(pPacket + 0x21) == 1) {
        FUN_004fab40(*(unsigned char*)(pPacket + 0x20));
    }

    if (pObj == *(int**)(*(int*)(pGameState + 0xe98) + 0xcd0)) {
        FUN_0051f4e0(0);
    }
    FUN_004fcd80(0);
}
