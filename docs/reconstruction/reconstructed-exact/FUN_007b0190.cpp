// =============================================================================
// FUN_007b0190
// -----------------------------------------------------------------------------
// Stable ID: aa_007b0190
// Address:   0x007b0190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b0190 @ 0x007b0190
// Stable ID: aa_007b0190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0041c7e0, FUN_00797d70, FUN_007b0190.
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

void __thiscall

FUN_007b0190(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  piVar4 = operator_new(0x2c);

  *piVar4 = param_2;

  piVar4[5] = 0;

  piVar4[6] = 0;

  piVar4[7] = 0;

  piVar4[8] = 0;

  piVar4[3] = 0;

  piVar4[4] = 0;

  piVar4[9] = 0;

  piVar4[10] = 0;

  piVar4[1] = *param_3;

  piVar4[2] = param_3[1];

  if (param_4 == (int *)0x0) {

    if ((int *)*piVar4 != (int *)0x0) {

      iVar1 = *(int *)*piVar4;

      iVar2 = *(int *)(iVar1 + 0x20);

      iVar1 = *(int *)(iVar1 + 0x1c);

      piVar4[5] = 0;

      piVar4[6] = 0;

      piVar4[7] = iVar1;

      piVar4[8] = iVar2;

    }

  }

  else {

    piVar4[5] = *param_4;

    piVar4[6] = param_4[1];

    piVar4[7] = param_4[2];

    piVar4[8] = param_4[3];

  }

  if (param_5 != (int *)0x0) {

    piVar4[3] = *param_5;

    piVar4[4] = param_5[1];

  }

  if (param_6 != (int *)0x0) {

    piVar4[9] = *param_6;

    piVar4[10] = param_6[1];

  }

  puVar5 = operator_new(8);

  if (puVar5 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar5 = 0;

    puVar5[1] = 0;

  }

  *puVar5 = 0xb;

  puVar5[1] = piVar4;

  FUN_0041c7e0(param_1 + 0x1e8,puVar5);

  pvVar3 = *(void **)(param_1 + 0x28c);

  if (pvVar3 != (void *)0x0) {

    FUN_00797d70(pvVar3);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar3);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28c) = 0;

  return;

}
