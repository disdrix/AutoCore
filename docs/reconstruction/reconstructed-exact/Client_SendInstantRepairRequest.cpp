// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: Client_SendInstantRepairRequest, GetTickCount, opcode.
//  - Return sites: 1.

// =============================================================================
// Client_SendInstantRepairRequest
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ce00
// Address:   0x0092ce00  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* Client_SendInstantRepairRequest - INC option 1.

   Sends opcode 0x20B6 (EMSG_Sector_InstantRepair_Request), body often just opcode (4 bytes).

   Not implemented in AutoCore yet. */



void Client_SendInstantRepairRequest(void)



{

  int iVar1;

  int in_EAX;

  DWORD DVar2;

  uint32_t /* width from decompiler */ local_4;

  

  if (DAT_00d1b6d8 != 0) {

    local_4 = 0x20b6;

    if (*(int *)(in_EAX + 0xc78) != 0) {

      (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,&local_4,4,0);

    }

    iVar1 = DAT_00d1b6d8;

    DVar2 = GetTickCount();

    *(DWORD *)(iVar1 + 0x620) = DVar2;

  }

  return;

}
