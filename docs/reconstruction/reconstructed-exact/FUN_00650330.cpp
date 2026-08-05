// =============================================================================
// FUN_00650330
// -----------------------------------------------------------------------------
// Stable ID: aa_00650330
// Address:   0x00650330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00650330 @ 0x00650330
// Stable ID: aa_00650330
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: while×2, if×1, return×1.
//  - Notable callees: FUN_00650330.
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

void __thiscall FUN_00650330(int *param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  

  param_1[1] = param_1[1] + -1;

  *(uint32_t /* width from decompiler */ *)(*param_1 + param_2 * 4) = 0;

  uVar6 = param_1[2];

  iVar1 = *param_1;

  uVar4 = uVar6 + param_2 & uVar6;

  iVar2 = *(int *)(iVar1 + uVar4 * 4);

  while (iVar2 != 0) {

    uVar4 = uVar4 + uVar6 & uVar6;

    iVar2 = *(int *)(iVar1 + uVar4 * 4);

  }

  uVar5 = uVar4 + 1 & uVar6;

  uVar4 = param_2 + 1 & uVar6;

  iVar1 = *(int *)(iVar1 + uVar4 * 4);

  while (iVar1 != 0) {

    uVar3 = *(uint *)(*param_1 + uVar4 * 4);

    uVar6 = (uVar3 >> 4) * -0x61c8864f & uVar6;

    if ((((uVar4 < uVar5) || (uVar6 <= param_2)) &&

        ((param_2 <= uVar4 || ((uVar6 <= param_2 && (uVar4 < uVar6)))))) &&

       ((uVar6 <= param_2 || (uVar5 <= uVar6)))) {

      *(uint *)(*param_1 + param_2 * 4) = uVar3;

      *(uint32_t /* width from decompiler */ *)(*param_1 + 4 + (param_1[2] + param_2) * 4) =

           *(uint32_t /* width from decompiler */ *)(*param_1 + 4 + (param_1[2] + uVar4) * 4);

      *(uint32_t /* width from decompiler */ *)(*param_1 + uVar4 * 4) = 0;

      param_2 = uVar4;

    }

    uVar6 = param_1[2];

    uVar4 = uVar4 + 1 & uVar6;

    iVar1 = *(int *)(*param_1 + uVar4 * 4);

  }

  return;

}
