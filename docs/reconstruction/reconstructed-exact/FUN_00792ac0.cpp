// =============================================================================
// FUN_00792ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00792ac0
// Address:   0x00792ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00792ac0 @ 0x00792ac0
// Stable ID: aa_00792ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00792ac0, FUN_007b5dd0.
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

void __thiscall FUN_00792ac0(int *param_1,uint32_t /* width from decompiler */ *param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *unaff_ESI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b4020;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pvVar1 = operator_new(0x488);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_007b5dd0(pvVar1,0);

  }

  local_4 = 0xffffffff;

  *param_2 = uVar2;

  (**(code **)(*param_1 + 0xa8))(uVar2);

  (**(code **)(*(int *)*param_2 + 0x28))(param_2);

  if (param_2 != (uint32_t /* width from decompiler */ *)0xffffffff) {

    (**(code **)(*(int *)*param_2 + 0x74))(param_2);

  }

  ExceptionList = unaff_ESI;

  return;

}
