// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CVOGTacArc_SetStateColor, FUN_009700f0, FUN_009733d0.
//  - Strings: "MatZFailColor".
//  - Return sites: 1.

// =============================================================================
// CVOGTacArc_SetStateColor
// -----------------------------------------------------------------------------
// Stable ID: aa_00632a20
// Address:   0x00632a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall CVOGTacArc_SetStateColor(int param_1,int param_2)



{

  uint8_t local_10 [16];

  

  *(int *)(param_1 + 0x24) = param_2;

  *(uint8_t *)(param_1 + 0x33) = 0x66;

  if (param_2 == 0) {

    *(uint8_t *)(param_1 + 0x32) = 0x1d;

    *(uint8_t *)(param_1 + 0x31) = 0x50;

    *(uint8_t *)(param_1 + 0x30) = 0xff;

    *(uint8_t *)(param_1 + 0x36) = 8;

    *(uint8_t *)(param_1 + 0x35) = 0x14;

    *(uint8_t *)(param_1 + 0x34) = 0x3d;

    *(uint8_t *)(param_1 + 0x37) = 0x53;

  }

  else if (param_2 == 1) {

    *(uint8_t *)(param_1 + 0x32) = 0x6b;

    *(uint8_t *)(param_1 + 0x31) = 0xff;

    *(uint8_t *)(param_1 + 0x30) = 0x40;

    *(uint8_t *)(param_1 + 0x36) = 0x14;

    *(uint8_t *)(param_1 + 0x35) = 0x33;

    *(uint8_t *)(param_1 + 0x34) = 0xc;

    *(uint8_t *)(param_1 + 0x37) = 0x4b;

  }

  else if (param_2 == 2) {

    *(uint8_t *)(param_1 + 0x32) = 0xfb;

    *(uint8_t *)(param_1 + 0x31) = 0x7d;

    *(uint8_t *)(param_1 + 0x30) = 10;

    *(uint8_t *)(param_1 + 0x36) = 0x33;

    *(uint8_t *)(param_1 + 0x35) = 0x17;

    *(uint8_t *)(param_1 + 0x34) = 2;

    *(uint8_t *)(param_1 + 0x37) = 0x4e;

  }

  else {

    *(uint8_t *)(param_1 + 0x32) = 0;

    *(uint8_t *)(param_1 + 0x31) = 0x33;

    *(uint8_t *)(param_1 + 0x30) = 0xff;

    *(uint8_t *)(param_1 + 0x36) = 0xd;

    *(uint8_t *)(param_1 + 0x35) = 0;

    *(uint8_t *)(param_1 + 0x34) = 0x33;

    *(uint8_t *)(param_1 + 0x37) = 0x5a;

  }

  if (*(int *)(param_1 + 0x1c) != 0) {

    FUN_009733d0(param_1 + 0x34);

    FUN_009700f0("MatZFailColor",local_10);

  }

  return;

}
