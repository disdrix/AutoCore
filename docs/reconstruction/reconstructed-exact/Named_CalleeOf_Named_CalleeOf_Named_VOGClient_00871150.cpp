// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871150
// -----------------------------------------------------------------------------
// Stable ID: aa_00871150
// Callee of Named_CalleeOf_Named_VOGClient (+1 other named callers)
// Address:   0x00871150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOGClient: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOGClient (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×20, return×3, goto×2.
//  - Notable callees: sprintf×4, FUN_0051f910, FUN_0051fa10, FUN_007fd970, FUN_008705c0, FUN_00871150.
//  - Strings: "%d/%s/%s"; "%d/%d".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOGClient (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_VOGClient_00871150(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  char cVar4;

  int *in_EAX;

  int *piVar5;

  int aiStack_134 [2];

  char acStack_100 [256];

  

  cVar4 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar4 == '\0') {

    return;

  }

  if (param_1 == (int *)0x0) {

    return;

  }

  FUN_007fd970();

  iVar1 = param_1[2];

  iVar2 = param_1[3];

  if (in_EAX[0x17a] != 0) {

    sprintf(acStack_100,"%d");

    (**(code **)(*(int *)in_EAX[0x17a] + 0x45c))();

    aiStack_134[1] = 0;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x17a] + 0x460))(iVar1);

    (**(code **)(*(int *)in_EAX[0x17a] + 0x464))(iVar1,iVar2,1,&stack0xfffffedc);

    (**(code **)(*(int *)in_EAX[0x17a] + 0x34c))();

  }

  if (in_EAX[0x17b] != 0) {

    (**(code **)(*(int *)in_EAX[0x17b] + 0x45c))();

    aiStack_134[1] = 1;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x17b] + 0x464))(iVar1);

    (**(code **)(*(int *)in_EAX[0x17b] + 0x34c))();

  }

  if (in_EAX[0x17c] != 0) {

    FUN_0051fa10();

    FUN_0051f910();

    aiStack_134[1] = 0x871291;

    sprintf(acStack_100,"%d/%s/%s");

    (**(code **)(*(int *)in_EAX[0x17c] + 0x45c))();

    aiStack_134[1] = 0;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x17c] + 0x460))(iVar1);

    (**(code **)(*(int *)in_EAX[0x17c] + 0x464))(iVar1,iVar2,1,&stack0xfffffedc);

    (**(code **)(*(int *)in_EAX[0x17c] + 0x34c))();

  }

  if (in_EAX[0x17d] == 0) goto LAB_00871374;

  if (in_EAX[0x143] == -1) {

    piVar5 = (int *)in_EAX[0x17d];

    if (*param_1 == 0) {

LAB_00871347:

      (**(code **)(*piVar5 + 0x45c))();

    }

    else {

      (**(code **)(*piVar5 + 0x45c))();

    }

  }

  else {

    piVar5 = (int *)in_EAX[0x17d];

    if (in_EAX[0x143] != (int)(short)param_1[7]) goto LAB_00871347;

    (**(code **)(*piVar5 + 0x45c))();

  }

  aiStack_134[1] = 1;

  aiStack_134[0] = iVar2;

  (**(code **)(*(int *)in_EAX[0x17d] + 0x464))(iVar1);

  (**(code **)(*(int *)in_EAX[0x17d] + 0x34c))();

LAB_00871374:

  if (in_EAX[0x180] != 0) {

    FUN_008705c0();

    (**(code **)(*(int *)in_EAX[0x180] + 0x45c))();

    aiStack_134[1] = 0;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x180] + 0x460))(iVar1);

    (**(code **)(*(int *)in_EAX[0x180] + 0x464))(iVar1,iVar2,1,&stack0xfffffedc);

    (**(code **)(*(int *)in_EAX[0x180] + 0x34c))();

  }

  if (in_EAX[0x17f] != 0) {

    sprintf(acStack_100,"%d/%d");

    (**(code **)(*(int *)in_EAX[0x17f] + 0x45c))();

    aiStack_134[1] = 0;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x17f] + 0x460))(iVar1);

    (**(code **)(*(int *)in_EAX[0x17f] + 0x460))(iVar1,iVar2,1,-(uint)*(ushort *)(param_1 + 5));

    (**(code **)(*(int *)in_EAX[0x17f] + 0x464))(iVar1,iVar2,1,aiStack_134);

  }

  if (in_EAX[0x17e] != 0) {

    sprintf(acStack_100,"%d");

    (**(code **)(*(int *)in_EAX[0x17e] + 0x45c))();

    aiStack_134[1] = 0;

    aiStack_134[0] = iVar2;

    (**(code **)(*(int *)in_EAX[0x17e] + 0x460))(iVar1);

    (**(code **)(*(int *)in_EAX[0x17e] + 0x464))(iVar1,iVar2,1,&stack0xfffffedc);

  }

  if (((DAT_00d1b6d8 != 0) &&

      (iVar3 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4),

      iVar1 == *(int *)(iVar3 + 0x164 + DAT_00d1b6d8))) &&

     (iVar2 == *(int *)(iVar3 + 0x168 + DAT_00d1b6d8))) {

    if (in_EAX[0x17a] != 0) {

      (**(code **)(*(int *)in_EAX[0x17a] + 0x464))();

    }

    if (in_EAX[0x17b] != 0) {

      (**(code **)(*(int *)in_EAX[0x17b] + 0x464))();

    }

    if (in_EAX[0x17c] != 0) {

      (**(code **)(*(int *)in_EAX[0x17c] + 0x464))();

    }

    if (in_EAX[0x17d] != 0) {

      (**(code **)(*(int *)in_EAX[0x17d] + 0x464))();

    }

    if (in_EAX[0x180] != 0) {

      (**(code **)(*(int *)in_EAX[0x180] + 0x464))();

    }

    if (in_EAX[0x17f] != 0) {

      (**(code **)(*(int *)in_EAX[0x17f] + 0x464))();

    }

    if (in_EAX[0x17e] != 0) {

      (**(code **)(*(int *)in_EAX[0x17e] + 0x464))();

    }

  }

  return;

}
