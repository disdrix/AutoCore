// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0042dbf0, FUN_0042dc60, FUN_007833a0, FUN_00783aa0, FUN_00974620.
//  - Strings: "Client puzzle solved in %d ms.".
//  - Return sites: 1.

// =============================================================================
// Named_Client_puzzle_solved_in_d_ms_0042dbf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042dbf0
// Address:   0x0042dbf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Client puzzle solved in %d ms."
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Client_puzzle_solved_in_d_ms_0042dbf0(uint32_t /* width from decompiler */ param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  

  cVar1 = FUN_00974620(in_EAX + 0x14c,in_EAX + 0x138,in_EAX + 0x140,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x148))

  ;

  if (cVar1 != '\0') {

    iVar2 = FUN_007833a0();

    FUN_00783aa0("Client puzzle solved in %d ms.",iVar2 - *(int *)(in_EAX + 0x1a4));

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1b8) = 4;

    FUN_0042dc60(param_1);

  }

  return;

}
