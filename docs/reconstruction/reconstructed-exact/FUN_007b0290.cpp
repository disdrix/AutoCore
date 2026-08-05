// =============================================================================
// FUN_007b0290
// -----------------------------------------------------------------------------
// Stable ID: aa_007b0290
// Address:   0x007b0290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b0290 @ 0x007b0290
// Stable ID: aa_007b0290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_0041c7e0, FUN_00797d70, FUN_007b0290.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_007b0290(int param_1,char *param_2)



{

  char *pcVar1;

  int iVar2;

  char cVar3;

  void *pvVar4;

  float fVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  if (param_2 != (char *)0x0) {

    puVar6 = operator_new(8);

    puVar9 = (uint32_t /* width from decompiler */ *)0x0;

    if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar6 = 0;

      puVar6[1] = 0;

      puVar9 = puVar6;

    }

    *puVar9 = 1;

    pcVar1 = param_2 + 1;

    pcVar7 = param_2;

    do {

      cVar3 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar3 != '\0');

    pcVar8 = operator_new__((uint)(pcVar7 + (1 - (int)pcVar1)));

    puVar9[1] = pcVar8;

    do {

      cVar3 = *param_2;

      *pcVar8 = cVar3;

      param_2 = param_2 + 1;

      pcVar8 = pcVar8 + 1;

    } while (cVar3 != '\0');

    FUN_0041c7e0(param_1 + 0x1e8,puVar9);

    *(int *)(param_1 + 0x128) = (int)(pcVar7 + (*(int *)(param_1 + 0x128) - (int)pcVar1));

    iVar2 = *(int *)(param_1 + 300) + 6 + *(int *)(param_1 + 0x128);

    fVar5 = (float)iVar2;

    if (iVar2 < 0) {

      fVar5 = fVar5 + _DAT_00aaa5dc;

    }

    pvVar4 = *(void **)(param_1 + 0x28c);

    *(float *)(param_1 + 0x2c4) = fVar5;

    if (pvVar4 != (void *)0x0) {

      FUN_00797d70(pvVar4);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar4);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

  }

  return;

}
