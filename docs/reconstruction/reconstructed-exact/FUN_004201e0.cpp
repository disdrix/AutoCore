// =============================================================================
// FUN_004201e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004201e0
// Address:   0x004201e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004201e0 @ 0x004201e0
// Stable ID: aa_004201e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004201e0.
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

void FUN_004201e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  puVar1 = operator_new(0x20);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar1[1] = param_2;

    *puVar1 = param_1;

    puVar1[2] = param_3;

    puVar1[3] = *unaff_ESI;

    puVar1[4] = unaff_ESI[1];

    puVar1[5] = unaff_ESI[2];

    puVar1[6] = unaff_ESI[3];

    *(uint8_t *)(puVar1 + 7) = param_4;

    *(uint8_t *)((int)puVar1 + 0x1d) = 0;

  }

  return;

}
