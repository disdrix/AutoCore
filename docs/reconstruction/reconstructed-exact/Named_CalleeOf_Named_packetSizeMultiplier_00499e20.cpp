// =============================================================================
// Named_CalleeOf_Named_packetSizeMultiplier_00499e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00499e20
// Callee of Named_packetSizeMultiplier
// Address:   0x00499e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_packetSizeMultiplier: packet/network helper. Evidence string: "Fluid about to boom?". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Fluid about to boom?"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00499a70, FUN_00499e20, FUN_005b8290, FUN_007a4480, free.
//  - Strings: "Fluid about to boom?".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_packetSizeMultiplier
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

void __fastcall Named_CalleeOf_Named_packetSizeMultiplier_00499e20(uint32_t /* width from decompiler */ *param_1)



{

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a0e99;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_LAB_009c7bcc;

  local_4 = 2;

  if (param_1[0x72] != 0) {

    FUN_007a4480(1,"Fluid about to boom?");

  }

  FUN_00499a70();

  if ((void *)param_1[0x74] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x74]);

  }

  param_1[0x74] = 0;

  param_1[0x75] = 0;

  param_1[0x76] = 0;

  if ((void *)param_1[0x58] != (void *)0x0) {

    free((void *)param_1[0x58]);

  }

  param_1[0x58] = 0;

  param_1[0x59] = 0;

  param_1[0x5a] = 0;

  local_4 = 0xffffffff;

  FUN_005b8290();

  ExceptionList = local_c;

  return;

}
