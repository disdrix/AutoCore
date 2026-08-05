// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080f210
// -----------------------------------------------------------------------------
// Stable ID: aa_0080f210
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x0080f210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "Enemy not found!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Enemy not found!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00573d50, FUN_007a69d0, FUN_007a6de0, FUN_0080f210, FUN_008f8200.
//  - Strings: "Enemy not found!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_0080f210(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  int unaff_EDI;

  

  FUN_007a69d0();

  if (*(char *)(unaff_EDI + 4) == '\0') {

    uVar3 = FUN_007a6de0("Enemy not found!",0xffffffff);

    if (DAT_00d1b8dc != 0) {

      FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar3,0);

    }

  }

  else {

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    FUN_00573d50(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1),

                 *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc));

    if (*(int **)(unaff_ESI + 0x1038) != (int *)0x0) {

                    /* WARNING: Could not recover jumptable at 0x0080f256. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(unaff_ESI + 0x1038) + 0x448))();

      return;

    }

  }

  return;

}
