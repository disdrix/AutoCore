// =============================================================================
// FUN_0062c0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0062c0b0
// Address:   0x0062c0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0062c0b0 @ 0x0062c0b0
// Stable ID: aa_0062c0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_005b3370×2, FUN_0062c0b0.
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

void FUN_0062c0b0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4,int *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  uint uVar3;

  

  if ((*(uint *)(param_4 + 0x18) & 1) == 0) {

    if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

      FUN_005b3370(param_5,8);

    }

    puVar1 = (uint32_t /* width from decompiler */ *)(*param_5 + param_5[1] * 8);

    param_5[1] = param_5[1] + 1;

    *puVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x18);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18);

    return;

  }

  uVar3 = *(uint *)(param_4 + 0x18) & 0xfffffffe;

  piVar2 = (int *)(uVar3 + 8 + param_1);

  if (*(uint *)(uVar3 + 0xc + param_1) == (*(uint *)(uVar3 + 0x10 + param_1) & 0x7fffffff)) {

    FUN_005b3370(piVar2,4);

  }

  *(uint32_t /* width from decompiler */ *)(*piVar2 + piVar2[1] * 4) = param_3;

  piVar2[1] = piVar2[1] + 1;

  return;

}
