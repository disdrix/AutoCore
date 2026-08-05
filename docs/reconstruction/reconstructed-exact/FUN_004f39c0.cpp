// =============================================================================
// FUN_004f39c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f39c0
// Address:   0x004f39c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f39c0 @ 0x004f39c0
// Stable ID: aa_004f39c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004f39c0, FUN_005a5410.
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

void __fastcall FUN_004f39c0(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a2c60;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x284) != (uint32_t /* width from decompiler */ *)0x0) {

    ExceptionList = &pvStack_c;

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x284))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x284) = 0;

  pvVar1 = operator_new(0x70);

  uStack_4 = 0;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_005a5410();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x284) = uVar2;

  ExceptionList = pvStack_c;

  return;

}
