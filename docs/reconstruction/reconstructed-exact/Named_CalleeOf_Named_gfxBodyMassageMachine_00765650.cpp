// =============================================================================
// Named_CalleeOf_Named_gfxBodyMassageMachine_00765650
// -----------------------------------------------------------------------------
// Stable ID: aa_00765650
// Callee of Named_gfxBodyMassageMachine
// Address:   0x00765650  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: block×9, FUN_00763370, FUN_00765650, FUN_00995ae0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxBodyMassageMachine
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

/* WARNING: Removing unreachable block (ram,0x007656a5) */

/* WARNING: Removing unreachable block (ram,0x007656b0) */

/* WARNING: Removing unreachable block (ram,0x007656c1) */

/* WARNING: Removing unreachable block (ram,0x007656d9) */

/* WARNING: Removing unreachable block (ram,0x007656bd) */

/* WARNING: Removing unreachable block (ram,0x007656e6) */

/* WARNING: Removing unreachable block (ram,0x007656fa) */

/* WARNING: Removing unreachable block (ram,0x0076570b) */

/* WARNING: Removing unreachable block (ram,0x00765716) */



void Named_CalleeOf_Named_gfxBodyMassageMachine_00765650(int param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b31a0;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00763370();

  local_4 = 0;

  FUN_00995ae0(param_1 + 0xbc);

  ExceptionList = pvStack_c;

  return;

}
