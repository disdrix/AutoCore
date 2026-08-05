// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00933a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00933a10
// Callee of Named_Client_InitInstance
// Address:   0x00933a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "floating point original settings = 0x%.4x". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "floating point original settings = 0x%.4x"
//   - "0.1 * 0.1 = %.15e"
//   - "setting precision to 24-bit:     = 0x%.4x"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_007a4480×4, _control87×2, FUN_00933a10.
//  - Strings: "floating point original settings = 0x%.4x"; "0.1 * 0.1 = %.15e"; "setting precision to 24-bit:     = 0x%.4x".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Named_Client_InitInstance_00933a10(void)



{

  uint uVar1;

  

  uVar1 = _control87(0,0);

  FUN_007a4480(0xffffffff,"floating point original settings = 0x%.4x",uVar1);

  FUN_007a4480(0xffffffff,"0.1 * 0.1 = %.15e",_DAT_00aaa9c8);

  uVar1 = _control87(0x20000,0x30000);

  FUN_007a4480(0xffffffff,"setting precision to 24-bit:     = 0x%.4x",uVar1);

  FUN_007a4480(0xffffffff,"0.1 * 0.1 = %.15e",_DAT_00aaa9c8);

  return;

}
