// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0058e1f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058e1f0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0058e1f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0058e1f0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0058e1f0(int param_1,float param_2)



{

  float *pfVar1;

  float fVar2;

  

  fVar2 = param_2;

  if (*(float *)(param_1 + 0x790) <= param_2 && param_2 != *(float *)(param_1 + 0x790)) {

    fVar2 = *(float *)(param_1 + 0x790);

  }

  pfVar1 = *(float **)(param_1 + 0x28);

  *(float *)(param_1 + 0x790) = fVar2;

  fVar2 = 0.0;

  do {

    if (fVar2 <= param_2) {

      fVar2 = *pfVar1 + fVar2;

      if (param_2 < fVar2) {

        *pfVar1 = param_2 - (fVar2 - *pfVar1);

      }

    }

    else {

      *pfVar1 = 0.0;

    }

    pfVar1 = (float *)pfVar1[0xbd];

  } while (pfVar1 != (float *)(param_1 + 0x3bc));

  if (param_2 < *(float *)(param_1 + 0x788)) {

    *(float *)(param_1 + 0x788) = param_2;

  }

  return;

}
