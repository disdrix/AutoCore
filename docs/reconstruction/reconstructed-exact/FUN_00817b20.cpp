// =============================================================================
// FUN_00817b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00817b20
// Address:   0x00817b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00817b20 @ 0x00817b20
// Stable ID: aa_00817b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0079c860×2, FUN_00816860, FUN_00816940, FUN_00817a90, FUN_00817b20.
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

void __fastcall FUN_00817b20(int *param_1)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4167;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00817a90();

  if ((char)param_1[0x181] != '\0') {

    pvVar1 = operator_new(0x4cc);

    iVar2 = 0;

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_0079c860();

    }

    local_4 = 0xffffffff;

    param_1[0x203] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x203] + 0x28))(param_1 + 0x181);

    (**(code **)(*(int *)param_1[0x203] + 0x74))(40000);

  }

  if ((char)param_1[0x1c2] != '\0') {

    pvVar1 = operator_new(0x4cc);

    local_4 = 1;

    iVar2 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_0079c860();

    }

    local_4 = 0xffffffff;

    param_1[0x204] = iVar2;

    (**(code **)(*param_1 + 0xa8))(iVar2);

    (**(code **)(*(int *)param_1[0x204] + 0x28))(param_1 + 0x1c2);

    (**(code **)(*(int *)param_1[0x204] + 0x74))(0x9c41);

  }

  FUN_00816940();

  FUN_00816860();

  ExceptionList = pvStack_c;

  return;

}
