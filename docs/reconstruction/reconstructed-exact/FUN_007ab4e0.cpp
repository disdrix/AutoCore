// =============================================================================
// FUN_007ab4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ab4e0
// Address:   0x007ab4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ab4e0 @ 0x007ab4e0
// Stable ID: aa_007ab4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, goto×1.
//  - Notable callees: FUN_007ab4e0.
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

void __thiscall FUN_007ab4e0(int param_1,int *param_2,char param_3,char param_4)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  uint8_t local_8 [8];

  

  iVar3 = *(int *)(param_1 + 0x78);

  iVar4 = *(int *)(param_1 + 0x7c);

  if ((param_4 != '\0') && (*(int *)(param_1 + 0x2b0) != 0)) {

    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x2b0) + 0x120))(local_8,1,1);

    iVar3 = iVar3 + *piVar1;

    iVar2 = (**(code **)(**(int **)(param_1 + 0x2b0) + 0x120))(&stack0xffffffec,1,1);

    iVar4 = iVar4 + *(int *)(iVar2 + 4);

  }

  if (param_3 == '\0') {

    if (*(char *)(param_1 + 0x1c9) == '\0') {

      if (DAT_00d17944 != 0) {

        fVar5 = ((float)iVar3 * DAT_00aaa674) / (float)DAT_00d1e818;

        iVar3 = DAT_00d1e81c;

        goto LAB_007ab59c;

      }

    }

    else if (DAT_00d17944 != 0) {

      fVar5 = ((float)iVar3 * DAT_00aaa674) / (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80);

      iVar3 = *(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84);

LAB_007ab59c:

      param_2[1] = (int)(((float)iVar4 * DAT_00aaa670) / (float)iVar3);

      *param_2 = (int)fVar5;

      return;

    }

    iVar3 = 0;

    iVar4 = 0;

  }

  param_2[1] = iVar4;

  *param_2 = iVar3;

  return;

}
