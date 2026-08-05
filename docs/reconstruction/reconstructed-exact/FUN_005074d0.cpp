// =============================================================================
// FUN_005074d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005074d0
// Address:   0x005074d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005074d0 @ 0x005074d0
// Stable ID: aa_005074d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_00507350, FUN_005074d0, FUN_005fff60.
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

void __fastcall FUN_005074d0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  *param_1 = &PTR_FUN_009cd9b0;

  FUN_005fff60(param_1);

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x15];

  if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1,

     *(short *)((int)puVar1 + 6) == 0)) {

    (**(code **)*puVar1)(1);

  }

  if (-1 < (int)param_1[0x27]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x25],param_1[0x27] * 4,0x12);

  }

  if (-1 < (int)param_1[0x24]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x22],param_1[0x24] * 4,0x12);

  }

  if (-1 < (int)param_1[0x21]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1f],param_1[0x21] * 4,0x12);

  }

  if (-1 < (int)param_1[0x1e]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x1c],param_1[0x1e] * 4,0x12);

  }

  if (-1 < (int)param_1[0x1a]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x18],param_1[0x1a] * 4,0x12);

  }

  FUN_00507350();

  return;

}
