// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007989f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007989f0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x007989f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: FUN_007989f0, swscanf.
//  - Strings: "%d,%d,%d;%d,%d,%d".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_007989f0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint8_t *unaff_EBX;

  uint8_t *unaff_ESI;

  uint8_t *unaff_EDI;

  uint8_t local_18 [4];

  uint8_t local_14 [4];

  uint8_t local_10 [4];

  uint8_t local_c [4];

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  iVar1 = swscanf((wchar_t *)*param_1,L"%d,%d,%d;%d,%d,%d",local_18,local_14,local_10,local_c,

                  local_8,local_4);

  if (iVar1 < 3) {

    return 0;

  }

  unaff_ESI[2] = local_18[0];

  unaff_ESI[1] = local_14[0];

  *unaff_ESI = local_10[0];

  if ((iVar1 < 6) || (unaff_EDI == (uint8_t *)0x0)) {

    if (unaff_EBX != (uint8_t *)0x0) {

      *unaff_EBX = 0;

    }

  }

  else {

    unaff_EDI[2] = local_c[0];

    unaff_EDI[1] = local_8[0];

    *unaff_EDI = local_4[0];

    if (unaff_EBX != (uint8_t *)0x0) {

      *unaff_EBX = 1;

      return 1;

    }

  }

  return 1;

}
