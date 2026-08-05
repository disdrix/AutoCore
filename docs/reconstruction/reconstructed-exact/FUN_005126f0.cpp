// =============================================================================
// FUN_005126f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005126f0
// Address:   0x005126f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005126f0 @ 0x005126f0
// Stable ID: aa_005126f0
// Embedded strings (evidence for future rename):
//   - "obj_money_clink"
//   - "obj_money_scrip"
//   - "obj_money_bars"
//   - "obj_money_orb"
//   - "obj_exit_locked"
//   - "obj_exit_unlocked"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00540350×6, FUN_004c38a0, FUN_005126f0, FUN_00563460, FUN_005749a0, FUN_00579130, FUN_005db160, FUN_005df770.
//  - Strings: "obj_money_clink"; "obj_money_scrip"; "obj_money_bars"; "obj_money_orb".
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

void FUN_005126f0(void)



{

  int iVar1;

  

  FUN_00563460();

  FUN_00605a20();

  FUN_00605250();

  FUN_005db160();

  FUN_00579130();

  FUN_004c38a0();

  FUN_005df770();

  FUN_005749a0();

  iVar1 = FUN_00540350("obj_money_clink");

  if (iVar1 == 0) {

    DAT_00af1b50 = 0xffffffff;

  }

  else {

    DAT_00af1b50 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_money_scrip");

  if (iVar1 == 0) {

    DAT_00af1b54 = 0xffffffff;

  }

  else {

    DAT_00af1b54 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_money_bars");

  if (iVar1 == 0) {

    DAT_00af1b58 = 0xffffffff;

  }

  else {

    DAT_00af1b58 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_money_orb");

  if (iVar1 == 0) {

    DAT_00af1b5c = 0xffffffff;

  }

  else {

    DAT_00af1b5c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_exit_locked");

  if (iVar1 == 0) {

    DAT_00af1b60 = 0xffffffff;

  }

  else {

    DAT_00af1b60 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_exit_unlocked");

  if (iVar1 != 0) {

    DAT_00af1b64 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    return;

  }

  DAT_00af1b64 = 0xffffffff;

  return;

}
