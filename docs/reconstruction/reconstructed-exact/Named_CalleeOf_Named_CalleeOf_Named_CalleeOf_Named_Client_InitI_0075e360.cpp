// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0075e360
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e360
// Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
// Address:   0x0075e360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_006a3db0×3, FUN_0075e360.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_Client_InitInstance
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_Client_InitI_0075e360(uint32_t /* width from decompiler */ *param_1)



{

  uint16_t uVar1;

  int iVar2;

  uint16_t local_600 [256];

  uint16_t auStack_400 [256];

  uint16_t auStack_200 [256];

  

  iVar2 = 0;

  do {

    uVar1 = FUN_006a3db0();

    local_600[iVar2] = uVar1;

    uVar1 = FUN_006a3db0();

    auStack_400[iVar2] = uVar1;

    uVar1 = FUN_006a3db0();

    auStack_200[iVar2] = uVar1;

    iVar2 = iVar2 + 1;

  } while (iVar2 < 0x100);

  (**(code **)(*(int *)*param_1 + 0x54))((int *)*param_1,0,0,local_600);

  return;

}
