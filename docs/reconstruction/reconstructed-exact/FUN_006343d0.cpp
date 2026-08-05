// =============================================================================
// FUN_006343d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006343d0
// Address:   0x006343d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006343d0 @ 0x006343d0
// Stable ID: aa_006343d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00507350, FUN_006343d0.
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

void __fastcall FUN_006343d0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  iVar1 = param_1[0x13];

  *param_1 = &PTR_FUN_009d4588;

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1[0x12] + iVar1 * 4);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(param_1);

    }

  }

  if (-1 < (int)param_1[0x14]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x12],param_1[0x14] * 4,0x12);

  }

  if (-1 < (int)param_1[0x11]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0xf],param_1[0x11] * 4,0x12);

  }

  FUN_00507350();

  return;

}
