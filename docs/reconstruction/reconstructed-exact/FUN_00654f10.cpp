// =============================================================================
// FUN_00654f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00654f10
// Address:   0x00654f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00654f10 @ 0x00654f10
// Stable ID: aa_00654f10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_006523f0, FUN_00654c70, FUN_00654f10.
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

void __fastcall FUN_00654f10(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  

  *param_1 = &PTR_FUN_009e5da0;

  param_1[2] = &PTR_LAB_009e5d98;

  param_1[5] = &PTR_LAB_009e5d88;

  param_1[6] = &PTR_LAB_009e5d80;

  if (param_1[3] != 0) {

    FUN_00654c70(0);

  }

  iVar2 = 0;

  if (0 < (int)param_1[0xb]) {

    iVar1 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(iVar1 + param_1[10]))(0);

      iVar2 = iVar2 + 1;

      iVar1 = iVar1 + 0x70;

    } while (iVar2 < (int)param_1[0xb]);

  }

  if (-1 < (int)param_1[0xc]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],(param_1[0xc] & 0x7fffffff) * 0x70,0x12);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] * 4,0x12);

  }

  param_1[6] = &PTR_LAB_009db1d0;

  param_1[5] = &PTR_LAB_009e3a68;

  FUN_006523f0();

  return;

}
