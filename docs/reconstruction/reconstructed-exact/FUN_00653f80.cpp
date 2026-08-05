// =============================================================================
// FUN_00653f80
// -----------------------------------------------------------------------------
// Stable ID: aa_00653f80
// Address:   0x00653f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653f80 @ 0x00653f80
// Stable ID: aa_00653f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: FUN_0055e370, FUN_0055e970, FUN_00652320, FUN_006523f0, FUN_00653f80.
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

void __fastcall FUN_00653f80(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  

  puVar1 = param_1 + 5;

  *param_1 = &PTR_FUN_009e5d30;

  param_1[2] = &PTR_LAB_009e5d28;

  *puVar1 = &PTR_LAB_009e5d20;

  if (param_1[3] != 0) {

    FUN_0055e370(puVar1);

    FUN_00652320(0);

    if (param_1[3] != 0) {

      FUN_0055e970(puVar1);

    }

  }

  iVar3 = 0;

  if (0 < (int)param_1[0xb]) {

    iVar2 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(iVar2 + param_1[10]))(0);

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 0x80;

    } while (iVar3 < (int)param_1[0xb]);

  }

  if (-1 < (int)param_1[0xc]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[10],param_1[0xc] << 7,0x12);

  }

  iVar3 = 0;

  if (0 < (int)param_1[8]) {

    iVar2 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(param_1[7] + iVar2))(0);

      iVar3 = iVar3 + 1;

      iVar2 = iVar2 + 0x80;

    } while (iVar3 < (int)param_1[8]);

  }

  if (-1 < (int)param_1[9]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[7],param_1[9] << 7,0x12);

  }

  *puVar1 = &PTR_LAB_009db1d0;

  FUN_006523f0();

  return;

}
