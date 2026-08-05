// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00977000
// -----------------------------------------------------------------------------
// Stable ID: aa_00977000
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x00977000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_00797cc0, FUN_00977000.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00977000(int param_1,int *param_2,int param_3,int param_4)



{

  bool bVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  int local_10 [3];

  int local_4;

  

  if ((param_2 != (int *)0x0) || (param_3 != 0)) {

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

    if (param_4 == 1) {

      iVar3 = 2;

    }

    else if (param_4 == 2) {

      iVar3 = 1;

    }

    else if (param_4 == 3) {

      iVar3 = 0;

    }

    else {

      iVar3 = 3;

    }

    local_10[0] = iVar3 * iVar2;

    local_10[2] = (iVar3 + 1) * iVar2 + -1;

    local_18 = 1;

    local_20 = 1;

    local_4 = (-(uint)bVar1 & 0xfffffff0) + 0x1f;

    local_10[1] = 0;

    local_14 = 0;

    local_1c = 0;

    if (param_2 != (int *)0x0) {

      if (!bVar1) {

        iVar4 = *(int *)(param_1 + 4);

      }

      (**(code **)(*param_2 + 600))(iVar4,&local_28,local_10,&local_18,&local_20);

    }

    if (param_3 != 0) {

      if (bVar1) {

        uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

      }

      else {

        uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

      }

      FUN_00797cc0(param_3,uVar5);

    }

  }

  return;

}
