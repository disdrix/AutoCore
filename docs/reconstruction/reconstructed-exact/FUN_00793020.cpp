// =============================================================================
// FUN_00793020
// -----------------------------------------------------------------------------
// Stable ID: aa_00793020
// Address:   0x00793020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00793020 @ 0x00793020
// Stable ID: aa_00793020
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00793020, FUN_0079c860.
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

void __thiscall FUN_00793020(int *param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  int iVar2;

  void *unaff_EDI;

  uint32_t /* width from decompiler */ unaff_retaddr;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7fb9;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x4cc);

  iVar2 = 0;

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    iVar2 = FUN_0079c860();

  }

  local_4 = 0xffffffff;

  *param_2 = iVar2;

  (**(code **)(*param_1 + 0xa8))(iVar2);

  (**(code **)(*(int *)*param_2 + 0x28))(param_2);

  (**(code **)(*(int *)*param_2 + 0x74))(param_3);

  *(uint32_t /* width from decompiler */ *)(*param_2 + 0x498) = unaff_retaddr;

  ExceptionList = unaff_EDI;

  return;

}
