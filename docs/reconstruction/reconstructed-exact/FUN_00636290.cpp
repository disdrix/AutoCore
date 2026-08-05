// =============================================================================
// FUN_00636290
// -----------------------------------------------------------------------------
// Stable ID: aa_00636290
// Address:   0x00636290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00636290 @ 0x00636290
// Stable ID: aa_00636290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00507170, FUN_005ffdb0, FUN_00636290.
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

void __fastcall FUN_00636290(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  *param_1 = &PTR_FUN_009e39f4;

  param_1[2] = &PTR_LAB_009e5e78;

  if (param_1[6] != 0) {

    FUN_00507170(param_1);

    puVar1 = (uint32_t /* width from decompiler */ *)param_1[6];

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

    param_1[6] = 0;

  }

  param_1[2] = &PTR_LAB_009e3a68;

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
