// =============================================================================
// FUN_0078e170
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e170
// Address:   0x0078e170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078e170 @ 0x0078e170
// Stable ID: aa_0078e170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0078e170, FUN_00792600, FUN_00795f20, FUN_0079c860, FUN_007b5dd0.
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

void __fastcall FUN_0078e170(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7f4e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  if (*(char *)((int)param_1 + 0x4ff) != '\0') {

    pvVar1 = operator_new(0x488);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      iVar2 = 0;

    }

    else {

      iVar2 = FUN_007b5dd0(pvVar1,0);

    }

    local_4 = 0xffffffff;

    param_1[0x24b] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x24b] + 0x28))((int)param_1 + 0x4ff);

    (**(code **)(*(int *)param_1[0x24b] + 0x74))(0x65);

  }

  if (*(char *)((int)param_1 + 0x603) != '\0') {

    pvVar1 = operator_new(0x4a4);

    iVar2 = 0;

    local_4 = 1;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_00795f20();

    }

    local_4 = 0xffffffff;

    param_1[0x24c] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x24c] + 0x28))((int)param_1 + 0x603);

    (**(code **)(*(int *)param_1[0x24c] + 0x74))(0x66);

  }

  if (*(char *)((int)param_1 + 0x707) != '\0') {

    pvVar1 = operator_new(0x4cc);

    iVar2 = 0;

    local_4 = 2;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_0079c860();

    }

    local_4 = 0xffffffff;

    param_1[0x24d] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x24d] + 0x28))((int)param_1 + 0x707);

    (**(code **)(*(int *)param_1[0x24d] + 0x74))(0x67);

  }

  ExceptionList = pvStack_c;

  return;

}
