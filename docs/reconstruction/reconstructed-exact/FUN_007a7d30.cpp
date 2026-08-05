// =============================================================================
// FUN_007a7d30
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7d30
// Address:   0x007a7d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a7d30 @ 0x007a7d30
// Stable ID: aa_007a7d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007a7d30.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall

FUN_007a7d30(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uStack_38;

  uint8_t *puStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint8_t local_18 [24];

  

  if (*(char *)((int)param_1 + 0xc3) != '\0') {

    return 1;

  }

  uStack_2c = param_4;

  uStack_30 = param_3;

  puStack_34 = local_18;

  uStack_38 = 0x7a7d64;

  piVar3 = (int *)(**(code **)(*param_1 + 0x120))();

  iVar1 = *piVar3;

  uStack_38 = param_4;

  iVar4 = (**(code **)(*param_1 + 0x120))(&stack0xffffffdc,param_3);

  piVar3 = *(int **)(iVar4 + 4);

  piVar5 = (int *)(**(code **)(*param_1 + 0x140))(&uStack_30,param_3);

  iVar4 = *piVar5;

  iVar6 = (**(code **)(*param_1 + 0x140))(&uStack_38,param_3);

  iVar2 = *piVar3;

  if ((((iVar1 <= iVar2) && (iVar2 < iVar4 + iVar1)) &&

      (iVar1 = piVar3[1], (int)puStack_34 <= iVar1)) &&

     (iVar1 < (int)(puStack_34 + *(int *)(iVar6 + 4)))) {

    return 1;

  }

  return 0;

}
