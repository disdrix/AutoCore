// =============================================================================
// FUN_00976e10
// -----------------------------------------------------------------------------
// Stable ID: aa_00976e10
// Address:   0x00976e10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00976e10 @ 0x00976e10
// Stable ID: aa_00976e10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00976e10.
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



void __fastcall FUN_00976e10(uint32_t /* width from decompiler */ param_1,char param_2,int param_3,int *param_4,int param_5)



{

  bool bVar1;

  int *in_EAX;

  uint uVar2;

  int iVar3;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  int local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  if (param_4 != (int *)0x0) {

    if (in_EAX == (int *)0x0) {

      local_28 = (int)((float)DAT_00d1e818 * DAT_00aaa7b8);

      local_24 = (int)((float)DAT_00d1e81c * _DAT_00aaa7b4);

    }

    else {

      local_28 = *in_EAX;

      local_24 = in_EAX[1];

    }

    iVar3 = *(int *)(param_3 + 0x10);

    if ((iVar3 == 0) ||

       (((int)((float)DAT_00d1e818 * DAT_00a0f718) < local_28 &&

        ((int)((float)DAT_00d1e81c * _DAT_00aaa7bc) < local_24)))) {

      bVar1 = false;

    }

    else {

      bVar1 = true;

    }

    local_1c = 2;

    uVar2 = (-(uint)bVar1 & 0xfffffff4) + 0x20;

    if (!bVar1) {

      local_1c = 0;

    }

    local_c = local_1c;

    local_10 = uVar2 * param_5;

    local_14 = 0;

    local_1c = 0;

    local_c = (-(uint)(param_2 != '\0') & uVar2) + local_c;

    local_8 = local_10 + uVar2;

    local_4 = local_c + uVar2;

    local_18 = 1;

    local_20 = 1;

    if (!bVar1) {

      iVar3 = *(int *)(param_3 + 0xc);

    }

    (**(code **)(*param_4 + 600))(iVar3,&local_28,&local_10,&local_18,&local_20);

  }

  return;

}
