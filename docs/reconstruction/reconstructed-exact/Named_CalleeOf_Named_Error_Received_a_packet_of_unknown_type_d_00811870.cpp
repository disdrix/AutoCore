// =============================================================================
// Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00811870
// -----------------------------------------------------------------------------
// Stable ID: aa_00811870
// Callee of Named_Error_Received_a_packet_of_unknown_type_d_d
// Address:   0x00811870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Error_Received_a_packet_of_unknown_type_d: packet/network helper. Evidence string: "You have been politely asked to leave your convoy.". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You have been politely asked to leave your convoy."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0066e8d0, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_00811870, FUN_0094cc00, FUN_0094dab0.
//  - Strings: "You have been politely asked to leave your convoy.".
//  - Return sites: 1.

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

void Named_CalleeOf_Named_Error_Received_a_packet_of_unknown_type_d_00811870(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  FUN_007a69d0();

  uVar5 = 0;

  uVar4 = 1;

  uVar3 = 0xffffffff;

  uVar2 = FUN_007a6de0("You have been politely asked to leave your convoy.",0xffffffff);

  FUN_007fdfb0(unaff_ESI,uVar2,uVar3,uVar4,uVar5);

  FUN_0094dab0();

  FUN_0066e8d0();

  iVar1 = *(int *)(unaff_ESI + 0x10a0);

  if ((iVar1 != 0) && (DAT_00d1775e = 0, *(int *)(iVar1 + 0x5b4) != 0)) {

    (**(code **)(**(int **)(iVar1 + 0x5b4) + 0x3c8))(0,1);

  }

  FUN_0094cc00();

  return;

}
