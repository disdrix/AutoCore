// =============================================================================
// Named_CalleeOf_Drive_dcVehicle_Open_004230d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004230d0
// Callee of Drive_dcVehicle_Open (+2 other named callers)
// Address:   0x004230d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_dcVehicle_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Drive_dcVehicle_Open (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0042312a×2, FUN_004230d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_dcVehicle_Open (+2 other named callers)
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

void Named_CalleeOf_Drive_dcVehicle_Open_004230d0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvStack_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009bc2f0;

  pvStack_10 = ExceptionList;

  local_8 = 0;

  ExceptionList = &pvStack_10;

  puVar1 = operator_new(0x14);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0xc) = puVar1;

    FUN_0042312a();

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  FUN_0042312a();

  return;

}
