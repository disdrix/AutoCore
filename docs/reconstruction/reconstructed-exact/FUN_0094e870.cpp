// =============================================================================
// FUN_0094e870
// -----------------------------------------------------------------------------
// Stable ID: aa_0094e870
// Address:   0x0094e870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094e870 @ 0x0094e870
// Stable ID: aa_0094e870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: strtok×2, FUN_0094e870, _atoi64, atoi.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0094e870(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *pcVar1;

  int iVar2;

  longlong lVar3;

  uint32_t /* width from decompiler */ local_18 [2];

  longlong local_10;

  uint8_t local_8;

  uint8_t local_7;

  

  pcVar1 = strtok((char *)0x0,param_3);

  if (*(int *)(param_1 + 0xe98) == 0) {

    return 0;

  }

  if (pcVar1 != (char *)0x0) {

    lVar3 = _atoi64(pcVar1);

    pcVar1 = strtok((char *)0x0,param_3);

    if (pcVar1 == (char *)0x0) {

      param_3._0_1_ = 0;

    }

    else {

      iVar2 = atoi(pcVar1);

      param_3._0_1_ = (uint8_t)iVar2;

    }

    local_18[0] = 0x20a2;

    local_8 = 1;

    if (*(int *)(param_1 + 0xc78) != 0) {

      local_10 = lVar3;

      local_7 = param_3._0_1_;

      (**(code **)(**(int **)(param_1 + 0xc78) + 0x18))(0xffffffff,local_18,0x18,0);

    }

  }

  return 1;

}
