// =============================================================================
// FUN_00969160
// -----------------------------------------------------------------------------
// Stable ID: aa_00969160
// Address:   0x00969160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00969160 @ 0x00969160
// Stable ID: aa_00969160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, return×1.
//  - Notable callees: FUN_00732c50×2, FUN_00969160.
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

uint __thiscall FUN_00969160(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  uint local_4;

  

  iVar3 = param_1[0x31];

  iVar2 = param_1[0x30];

  local_4 = 0;

  while (iVar2 != iVar3) {

    iVar2 = iVar2 + 4;

    uVar1 = 0;

    if (DAT_00afa360 == 1) {

      uVar1 = FUN_00732c50(param_2,param_3);

    }

    else if (DAT_00afa360 != 2) {

      uVar1 = 0xffffffff;

    }

    local_4 = local_4 | uVar1;

  }

  iVar3 = param_1[0x34];

  iVar2 = param_1[0x35];

  while (iVar3 != iVar2) {

    iVar3 = iVar3 + 4;

    uVar1 = 0;

    if (DAT_00afa360 == 1) {

      uVar1 = FUN_00732c50(param_2,param_3);

    }

    else if (DAT_00afa360 != 2) {

      uVar1 = 0xffffffff;

    }

    local_4 = local_4 | uVar1;

  }

  (**(code **)(*param_1 + 0x50))();

  return local_4;

}
