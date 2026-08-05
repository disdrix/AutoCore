// =============================================================================
// FUN_00629080
// -----------------------------------------------------------------------------
// Stable ID: aa_00629080
// Address:   0x00629080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00629080 @ 0x00629080
// Stable ID: aa_00629080
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, do×2, while×2, goto×2.
//  - Notable callees: FUN_00629080.
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

void __thiscall FUN_00629080(int param_1,uint8_t *param_2,float *param_3)



{

  int iVar1;

  bool bVar2;

  char *pcVar3;

  int iVar4;

  float fVar5;

  

  *(float *)(param_1 + 0x34) = *param_3 + *(float *)(param_1 + 0x34);

  fVar5 = *(float *)(param_1 + 0x38) + *param_3;

  iVar1 = *(int *)(param_1 + 0x20);

  *(float *)(param_1 + 0x38) = fVar5;

  if (*(float *)(param_1 + 0x34) < *(float *)(iVar1 + 0x30) ||

      *(float *)(param_1 + 0x34) == *(float *)(iVar1 + 0x30)) {

    if (fVar5 < *(float *)(iVar1 + 0x34) || fVar5 == *(float *)(iVar1 + 0x34)) {

LAB_00629186:

      *param_2 = 0;

      return;

    }

    iVar4 = 0;

    *(float *)(param_1 + 0x38) = fVar5 - *(float *)(iVar1 + 0x34);

    bVar2 = true;

    if (0 < *(int *)(param_1 + 0x40)) {

      do {

        iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + iVar4 * 4);

        if ((*(int *)(iVar1 + 0x54) == 0) ||

           (pcVar3 = (char *)(**(code **)(**(int **)(iVar1 + 0x54) + 0x18))(&param_3,iVar1),

           *pcVar3 == '\0')) {

          bVar2 = false;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < *(int *)(param_1 + 0x40));

      if (!bVar2) goto LAB_00629186;

    }

  }

  else {

    iVar4 = 0;

    *(float *)(param_1 + 0x34) = *(float *)(param_1 + 0x34) - *(float *)(iVar1 + 0x30);

    bVar2 = true;

    if (0 < *(int *)(param_1 + 0x40)) {

      do {

        iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + iVar4 * 4);

        if ((*(int *)(iVar1 + 0x54) == 0) ||

           (pcVar3 = (char *)(**(code **)(**(int **)(iVar1 + 0x54) + 0x14))(&param_3,iVar1),

           *pcVar3 == '\0')) {

          bVar2 = false;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < *(int *)(param_1 + 0x40));

      if (!bVar2) goto LAB_00629186;

    }

    if (*(char *)(param_1 + 0x2c) < '\x05') {

      *(char *)(param_1 + 0x2c) = *(char *)(param_1 + 0x2c) + '\x01';

      *param_2 = 0;

      return;

    }

    *(uint8_t *)(param_1 + 0x2c) = 0;

  }

  *param_2 = 1;

  return;

}
