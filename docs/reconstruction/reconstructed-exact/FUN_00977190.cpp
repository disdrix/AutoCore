// =============================================================================
// FUN_00977190
// -----------------------------------------------------------------------------
// Stable ID: aa_00977190
// Address:   0x00977190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00977190 @ 0x00977190
// Stable ID: aa_00977190
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×7, return×1.
//  - Notable callees: FUN_00977190.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00977190(int param_1,int *param_2,int param_3)



{

  bool bVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  int local_10 [3];

  int local_4;

  

  if (param_2 != (int *)0x0) {

    if (in_EAX == (int *)0x0) {

      local_28 = (int)((float)DAT_00d1e818 * DAT_00aaa7b8);

      local_24 = (int)((float)DAT_00d1e81c * _DAT_00aaa7b4);

    }

    else {

      local_28 = *in_EAX;

      local_24 = in_EAX[1];

    }

    iVar4 = *(int *)(param_1 + 8);

    if ((iVar4 == 0) ||

       (((int)((float)DAT_00d1e818 * DAT_00a0f718) < local_28 &&

        ((int)((float)DAT_00d1e81c * _DAT_00aaa7bc) < local_24)))) {

      bVar1 = false;

    }

    else {

      bVar1 = true;

    }

    iVar2 = (-(uint)bVar1 & 0xfffffff0) + 0x20;

    if (param_3 == 1) {

      iVar3 = 2;

    }

    else if (param_3 == 2) {

      iVar3 = 1;

    }

    else if (param_3 == 3) {

      iVar3 = 0;

    }

    else {

      iVar3 = 3;

    }

    local_10[0] = iVar3 * iVar2;

    local_10[2] = (iVar3 + 1) * iVar2 + -1;

    local_4 = (-(uint)bVar1 & 0xfffffff0) + 0x1f;

    local_10[1] = 0;

    local_18 = 1;

    local_14 = 0;

    local_20 = 1;

    local_1c = 0;

    if (!bVar1) {

      iVar4 = *(int *)(param_1 + 4);

    }

    (**(code **)(*param_2 + 600))(iVar4,&local_28,local_10,&local_18,&local_20);

  }

  return;

}
