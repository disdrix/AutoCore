// =============================================================================
// Named_CalleeOf_Mission_Mission_Object_005140d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005140d0
// Callee of Mission_Mission_Object (+1 other named callers)
// Address:   0x005140d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Mission_Object: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Mission_Object (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×7, switch×1.
//  - Notable callees: FUN_005140d0.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Mission_Mission_Object (+1 other named callers)
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

void Named_CalleeOf_Mission_Mission_Object_005140d0(uint8_t *param_1,uint16_t param_2)



{

  switch(param_2) {

  case 0:

    param_1[2] = 0x91;

    param_1[1] = 0x91;

    *param_1 = 0x91;

    param_1[3] = 0xff;

    return;

  case 1:

    param_1[2] = 0xff;

    param_1[1] = 0xff;

    *param_1 = 0xff;

    param_1[3] = 0xff;

    return;

  case 2:

    param_1[2] = 0x28;

    param_1[1] = 0x28;

    *param_1 = 0xff;

    param_1[3] = 0xff;

    return;

  case 3:

    param_1[1] = 0x14;

    *param_1 = 0xf0;

    param_1[2] = 0xf0;

    param_1[3] = 0xff;

    return;

  case 4:

    param_1[2] = 0xff;

    param_1[1] = 10;

    *param_1 = 0x23;

    param_1[3] = 0xff;

    return;

  case 5:

    param_1[2] = 0xff;

    param_1[1] = 0x8a;

    *param_1 = 10;

    param_1[3] = 0xff;

    return;

  default:

    param_1[1] = 0xe4;

    *param_1 = 0x3c;

    param_1[2] = 0xf0;

    param_1[3] = 0xff;

    return;

  }

}
