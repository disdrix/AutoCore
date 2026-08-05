// =============================================================================
// FUN_00562530
// -----------------------------------------------------------------------------
// Stable ID: aa_00562530
// Address:   0x00562530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00562530 @ 0x00562530
// Stable ID: aa_00562530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_0055f030, FUN_00561370, FUN_00562530.
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

void __thiscall FUN_00562530(int param_1,int param_2,char param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  if (param_2 == 0) {

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0x18,0x22);

    *(uint16_t *)(iVar2 + 4) = 0x18;

    param_2 = FUN_0055f030();

  }

  else {

    *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + 1;

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xd0);

  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

  if (*(short *)((int)puVar1 + 6) == 0) {

    (**(code **)*puVar1)(1);

  }

  *(int *)(param_1 + 0xd0) = param_2;

  if (param_2 == 0) {

    param_2 = 0;

  }

  else {

    param_2 = param_2 + 0xc;

  }

  *(int *)(*(int *)(param_1 + 0xcc) + 4) = param_2;

  if (*(int *)(param_1 + 0xd0) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0xd0) + 0xc;

  }

  *(int *)(param_1 + 0x144) = iVar2;

  if (param_3 != '\0') {

    FUN_00561370();

  }

  return;

}
