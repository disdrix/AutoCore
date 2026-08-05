// =============================================================================
// FUN_007533e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007533e0
// Address:   0x007533e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007533e0 @ 0x007533e0
// Stable ID: aa_007533e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×12, return×3.
//  - Notable callees: EnterCriticalSection×2, FUN_00445080×2, LeaveCriticalSection×2, FUN_00444f60, FUN_00444fb0, FUN_0074fd90, FUN_00752a80, FUN_00752ba0.
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

int __thiscall FUN_007533e0(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  bool bVar6;

  uint8_t local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = param_3;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b092b;

  local_c = ExceptionList;

  bVar6 = param_3 == 0;

  param_3 = 0;

  if (bVar6) {

    ExceptionList = &local_c;

    iVar4 = FUN_00445080(&param_3,param_1,0,0);

  }

  else {

    ExceptionList = &local_c;

    FUN_00444f60(local_2c,iVar4);

    local_4 = 0;

    iVar4 = FUN_00445080(&param_3,param_1,local_2c,0);

    local_4 = 0xffffffff;

    FUN_00444fb0(local_2c);

  }

  iVar3 = param_3;

  if (iVar4 < 0) {

    ExceptionList = local_c;

    return iVar4;

  }

  iVar5 = NDResource_AcquireInnerObject();

  if (iVar5 == 0) {

    if (*(char *)(iVar3 + 0x38) != '\0') {

      EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x20));

    }

    if (*(int *)(iVar3 + 0x10) != 0) {

      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;

    }

    if (*(char *)(iVar3 + 0x38) != '\0') {

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x20));

    }

    ExceptionList = local_c;

    return -1;

  }

  FUN_0074fd90();

  *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;

  if (*(int *)(iVar5 + 8) == 1) {

    (**(code **)(*(int *)(iVar5 + 4) + 4))();

  }

  iVar2 = *(int *)(param_2 + 8);

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  *(int *)(param_2 + 8) = iVar5;

  if (*(char *)(iVar3 + 0x38) != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x20));

  }

  if (*(int *)(iVar3 + 0x10) != 0) {

    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;

  }

  if (*(char *)(iVar3 + 0x38) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x20));

  }

  FUN_00752ba0();

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + 0x24);

  FUN_00752a80();

  ExceptionList = local_c;

  return iVar4;

}
