// =============================================================================
// FUN_007ad4e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ad4e0
// Address:   0x007ad4e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ad4e0 @ 0x007ad4e0
// Stable ID: aa_007ad4e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×15, return×5, do×4, while×4, goto×3.
//  - Notable callees: FUN_006a3db0×6, FUN_0079ac20, FUN_007ad4e0.
//  - Return sites: 5.

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

void __thiscall FUN_007ad4e0(int *param_1,float param_2)



{

  char cVar1;

  uint8_t uVar2;

  int *piVar3;

  int iVar4;

  uint8_t *puVar5;

  int iStack_24;

  int iStack_20;

  float fStack_10;

  float fStack_c;

  float fStack_4;

  

  iStack_20 = 0x7ad4f3;

  FUN_0079ac20();

  param_2 = (float)param_1[0x51] + param_2;

  param_1[0x51] = (int)param_2;

  if (param_1[0x88] == 1) {

    if (*(float *)(param_1[0xae] + 8) <= 0.0) {

LAB_007ad527:

      iStack_20 = 0x7ad531;

      (**(code **)(*param_1 + 0x100))();

      return;

    }

    if (param_2 < DAT_00afa134) {

      return;

    }

    iStack_20 = 1;

    iStack_24 = 0x7ad584;

    cVar1 = (**(code **)(*param_1 + 0xf0))();

    if (cVar1 != '\0') {

      puVar5 = (uint8_t *)((int)param_1 + 0x22b);

      iVar4 = 3;

      do {

        iStack_24 = 0x7ad5af;

        uVar2 = FUN_006a3db0();

        *puVar5 = uVar2;

        puVar5 = puVar5 + 4;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      iStack_24 = 0x7ad5c3;

      (**(code **)(*param_1 + 0x34c))();

    }

    iStack_24 = 2;

    cVar1 = (**(code **)(*param_1 + 0xf0))();

    if (cVar1 != '\0') {

      (**(code **)(*param_1 + 0x11c))(&stack0xffffffe8);

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(4);

    if (cVar1 != '\0') {

      puVar5 = (uint8_t *)((int)param_1 + 0x229);

      iVar4 = 3;

      do {

        uVar2 = FUN_006a3db0();

        *puVar5 = uVar2;

        uVar2 = FUN_006a3db0();

        puVar5[-1] = uVar2;

        puVar5 = puVar5 + 4;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      (**(code **)(*param_1 + 0x34c))();

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(8);

    if (cVar1 == '\0') goto LAB_007ad985;

    iStack_20 = (int)((float)(param_1[0x5a] - param_1[0x58]) * fStack_c) + param_1[0x58];

    (**(code **)(*param_1 + 0x11c))(&iStack_20);

    piVar3 = (int *)&stack0xffffffe4;

  }

  else {

    if (param_1[0x88] != -1) {

      return;

    }

    if (*(float *)(param_1[0xae] + 8) <= 0.0) goto LAB_007ad527;

    if (param_2 < DAT_00afa134) {

      return;

    }

    iStack_20 = 1;

    iStack_24 = 0x7ad7b0;

    cVar1 = (**(code **)(*param_1 + 0xf0))();

    if (cVar1 != '\0') {

      puVar5 = (uint8_t *)((int)param_1 + 0x22b);

      iVar4 = 3;

      do {

        iStack_24 = 0x7ad7cf;

        uVar2 = FUN_006a3db0();

        *puVar5 = uVar2;

        puVar5 = puVar5 + 4;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      iStack_24 = 0x7ad7e3;

      (**(code **)(*param_1 + 0x34c))();

    }

    iStack_24 = 2;

    cVar1 = (**(code **)(*param_1 + 0xf0))();

    if (cVar1 != '\0') {

      fStack_10 = (float)((int)((float)(param_1[0x5a] - param_1[0x58]) * fStack_4) + param_1[0x58]);

      fStack_c = (float)((int)((float)(param_1[0x5b] - param_1[0x59]) * fStack_4) + param_1[0x59]);

      (**(code **)(*param_1 + 0x11c))(&fStack_10);

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(4);

    if (cVar1 != '\0') {

      puVar5 = (uint8_t *)((int)param_1 + 0x229);

      iVar4 = 3;

      do {

        uVar2 = FUN_006a3db0();

        *puVar5 = uVar2;

        uVar2 = FUN_006a3db0();

        puVar5[-1] = uVar2;

        puVar5 = puVar5 + 4;

        iVar4 = iVar4 + -1;

      } while (iVar4 != 0);

      (**(code **)(*param_1 + 0x34c))();

    }

    cVar1 = (**(code **)(*param_1 + 0xf0))(8);

    if (cVar1 == '\0') goto LAB_007ad985;

    (**(code **)(*param_1 + 0x11c))(&stack0xffffffe8);

    iStack_24 = (int)((float)param_1[0x95] * fStack_10 * (float)DAT_00d1e818 * DAT_00aaa67c);

    iStack_20 = (int)((float)param_1[0x96] * fStack_10 * (float)DAT_00d1e818 * DAT_00aaa67c);

    piVar3 = &iStack_24;

  }

  (**(code **)(*param_1 + 300))(piVar3);

  (**(code **)(*param_1 + 0x34c))();

LAB_007ad985:

  cVar1 = (**(code **)(*param_1 + 0xf0))(0x10);

  if (cVar1 != '\0') {

    (**(code **)(*param_1 + 0x34c))();

  }

  param_1[0x51] = 0;

  return;

}
