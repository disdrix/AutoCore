// =============================================================================
// FUN_006386a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006386a0
// Address:   0x006386a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006386a0 @ 0x006386a0
// Stable ID: aa_006386a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: free×8, malloc×2, FUN_006386a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_006386a0(uint32_t /* width from decompiler */ *param_1,uint param_2,int param_3,uint param_4)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  code *pcVar4;

  

  pcVar4 = malloc_exref;

  if ((uint)param_1[6] < param_2) {

    param_1[6] = param_2;

    if ((void *)*param_1 != (void *)0x0) {

      free((void *)*param_1);

    }

    pcVar4 = malloc_exref;

    pvVar1 = malloc(param_1[6] << 10);

    *param_1 = pvVar1;

  }

  if ((uint)param_1[4] < param_4) {

    param_1[4] = param_4;

    if ((void *)param_1[1] != (void *)0x0) {

      free((void *)param_1[1]);

    }

    if ((void *)param_1[2] != (void *)0x0) {

      free((void *)param_1[2]);

    }

    uVar2 = (*pcVar4)(param_1[4] * 4);

    param_1[1] = uVar2;

    uVar2 = (*pcVar4)(param_1[4] * 4);

    param_1[2] = uVar2;

  }

  uVar3 = param_1[4] * param_3;

  if ((uint)param_1[5] <= uVar3 && uVar3 - param_1[5] != 0) {

    param_1[5] = uVar3;

    if ((void *)param_1[3] != (void *)0x0) {

      free((void *)param_1[3]);

    }

    pvVar1 = malloc(param_1[5]);

    param_1[3] = pvVar1;

  }

  pvVar1 = (void *)*param_1;

  if (pvVar1 != (void *)0x0) {

    if ((((param_3 == 0) || (param_1[3] != 0)) && (param_1[1] != 0)) && (param_1[2] != 0)) {

      return 1;

    }

    if (pvVar1 != (void *)0x0) {

      free(pvVar1);

      *param_1 = 0;

    }

  }

  if ((void *)param_1[1] != (void *)0x0) {

    free((void *)param_1[1]);

    param_1[1] = 0;

  }

  if ((void *)param_1[2] != (void *)0x0) {

    free((void *)param_1[2]);

    param_1[2] = 0;

  }

  if ((void *)param_1[3] != (void *)0x0) {

    free((void *)param_1[3]);

    param_1[3] = 0;

  }

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  return 0;

}
