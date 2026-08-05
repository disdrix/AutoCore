// =============================================================================
// FUN_0056a2e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a2e0
// Address:   0x0056a2e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a2e0 @ 0x0056a2e0
// Stable ID: aa_0056a2e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~107 non-empty decompiler lines.
//  - Control keywords: if×11, return×2.
//  - Notable callees: FUN_0056a2e0, FUN_005c88b0.
//  - Return sites: 2.

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

void __fastcall FUN_0056a2e0(int param_1)



{

  int iVar1;

  

  FUN_005c88b0();

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x80) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x514);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint8_t *)(param_1 + -0x8c) = *(uint8_t *)(iVar1 + 0x536);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x70) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x508);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x60) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c0);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x5c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c4);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x58) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4c8);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x74) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4fc);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x6c) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x68) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x504);

  iVar1 = *(int *)(*(int *)(param_1 + -0x14c) + 4);

  *(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + -0x8c) =

       *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar1 + -0xa4 + param_1) + 0x3c) + 0x3e4);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -100) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x50c);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x2c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4cc);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x28) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d0);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x24) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4d4);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x20) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4f0);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4f4);

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x18) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x4f8);

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(iVar1 + 0x3c);

  }

  *(uint16_t *)(param_1 + -0x7c) = *(uint16_t *)(iVar1 + 0x532);

  *(uint16_t *)(param_1 + -0x7a) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x40) = 0;

  *(uint16_t *)(param_1 + -0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + -0x30) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0xa4 + param_1);

  if (iVar1 != 0) {

    *(uint16_t *)(param_1 + -0x44) = *(uint16_t *)(*(int *)(iVar1 + 0x3c) + 0x538);

    return;

  }

  *(uint16_t *)(param_1 + -0x44) = uRam00000538;

  return;

}
