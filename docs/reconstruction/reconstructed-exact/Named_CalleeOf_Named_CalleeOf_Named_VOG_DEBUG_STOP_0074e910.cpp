// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e910
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e910
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0074e910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0074e910, _CIfmod.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e910(int param_1,float param_2,float param_3)



{

  float *pfVar1;

  float fVar2;

  float fVar3;

  float *pfVar4;

  float10 fVar5;

  

  pfVar1 = (float *)(param_1 + 0x44);

  *pfVar1 = param_2;

  *(float *)(param_1 + 0x40) = param_3;

  if (*(char *)(param_1 + 0x4c) == '\0') {

    pfVar4 = (float *)(param_1 + 0x48);

    if (0.0 < *pfVar1 || *pfVar1 == 0.0) {

      if (*pfVar1 < *pfVar4 || *pfVar1 == *pfVar4) {

        pfVar4 = pfVar1;

      }

      *pfVar1 = *pfVar4;

    }

    else {

      *pfVar1 = 0.0;

    }

  }

  else {

    fVar5 = (float10)_CIfmod();

    fVar3 = g_flZero;

    fVar2 = (float)fVar5;

    *pfVar1 = fVar2;

    if (fVar2 < fVar3) {

      *pfVar1 = *(float *)(param_1 + 0x48) + fVar2;

    }

  }

  *(float *)(param_1 + 0x34) = param_3 - *pfVar1 / *(float *)(param_1 + 0x3c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(float *)(param_1 + 0x6c) = *pfVar1;

  return;

}
