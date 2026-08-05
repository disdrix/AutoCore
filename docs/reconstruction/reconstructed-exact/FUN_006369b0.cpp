// =============================================================================
// FUN_006369b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006369b0
// Address:   0x006369b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006369b0 @ 0x006369b0
// Stable ID: aa_006369b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×10, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_006369b0.
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

void __fastcall FUN_006369b0(uint32_t /* width from decompiler */ *param_1)



{

  *param_1 = &PTR_FUN_009e3b44;

  if ((uint32_t /* width from decompiler */ *)param_1[4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[4])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[3] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[3])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[5] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[5])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[6] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[6])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[7] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[7])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[8] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[8])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[9] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[9])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[10] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[10])(1);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0xb] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xb])(1);

  }

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
