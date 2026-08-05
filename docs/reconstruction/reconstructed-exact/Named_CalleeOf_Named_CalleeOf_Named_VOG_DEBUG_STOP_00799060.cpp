// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00799060
// -----------------------------------------------------------------------------
// Stable ID: aa_00799060
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00799060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00799060, swscanf.
//  - Strings: "%f,%f,%f;%f,%f,%f".
//  - Return sites: 2.

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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00799060(uint32_t /* width from decompiler */ *param_1,uint8_t *param_2)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float *unaff_ESI;

  float *unaff_EDI;

  

  iVar3 = swscanf((wchar_t *)*param_1,L"%f,%f,%f;%f,%f,%f");

  if (iVar3 < 6) {

    if (param_2 != (uint8_t *)0x0) {

      *param_2 = 0;

    }

  }

  else {

    fVar1 = unaff_EDI[1];

    fVar2 = unaff_EDI[2];

    *unaff_ESI = *unaff_ESI - *unaff_EDI;

    unaff_ESI[1] = unaff_ESI[1] - fVar1;

    unaff_ESI[2] = unaff_ESI[2] - fVar2;

    if (param_2 != (uint8_t *)0x0) {

      *param_2 = 1;

      return;

    }

  }

  return;

}
