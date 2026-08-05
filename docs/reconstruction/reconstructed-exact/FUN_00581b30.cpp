// =============================================================================
// FUN_00581b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00581b30
// Address:   0x00581b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00581b30 @ 0x00581b30
// Stable ID: aa_00581b30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004e8830, FUN_004e88a0, FUN_00516be0, FUN_00581b30.
//  - Return sites: 1.

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

void __fastcall FUN_00581b30(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_004e88a0(*(int *)(*(int *)(param_1 + -0x8c) + 4) + -0xc + param_1,&local_1c);

  FUN_004e8830(*(int *)(*(int *)(param_1 + -0x8c) + 4) + 4 + param_1,&local_10);

  cVar1 = (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + -0x90))

                    (1,local_1c,local_18,local_14,local_10,local_c,local_8,local_4,1);

  if (cVar1 != '\0') {

    (**(code **)(*(int *)(param_1 + -0x90) + 0x20))();

  }

  param_1 = *(int *)(*(int *)(param_1 + -0x8c) + 4) + param_1;

  (**(code **)(*(int *)(param_1 + -0x8c) + 0xb8))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c));

  FUN_00516be0();

  return;

}
