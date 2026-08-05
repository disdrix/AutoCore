// =============================================================================
// FUN_007156b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007156b0
// Address:   0x007156b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007156b0 @ 0x007156b0
// Stable ID: aa_007156b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_00714520, FUN_00715340, FUN_007156b0, FUN_00715980.
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

void FUN_007156b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4,

                 int param_5,int *param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  float fVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  float10 fVar5;

  int local_190 [100];

  

  FUN_00714520(param_1,param_2,0x100,param_3);

  FUN_00715340(param_3,0,0x100,param_7,local_190,param_6);

  iVar3 = 0;

  if (0 < *param_6) {

    puVar4 = param_4;

    do {

      iVar1 = *(int *)((int)puVar4 + ((int)local_190 - (int)param_4));

      fVar5 = (float10)FUN_00715980(param_3[iVar1 + -1],param_3[iVar1],param_3[iVar1 + 1],puVar4);

      iVar3 = iVar3 + 1;

      puVar4 = puVar4 + 1;

      *(float *)((param_5 - (int)param_4) + -4 + (int)puVar4) = (float)(fVar5 + (float10)iVar1);

    } while (iVar3 < *param_6);

  }

  if (*param_6 < 4) {

    param_5 = param_5 - (int)param_4;

    iVar3 = 0x24;

    fVar2 = DAT_00a111b0;

    do {

      param_3 = param_3 + 7;

      *(float *)((int)param_4 + param_5) = fVar2;

      fVar2 = fVar2 + DAT_00a111b0;

      *param_4 = *param_3;

      param_4 = param_4 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    *param_6 = 0x24;

  }

  return;

}
