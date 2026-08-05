// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_0079a120
// -----------------------------------------------------------------------------
// Stable ID: aa_0079a120
// Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
// Address:   0x0079a120  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CONCAT44, FUN_0079a120, QueryPerformanceCounter.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_Input_PollBoundActions
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_Input_PollB_0079a120(int param_1,int param_2)



{

  char *pcVar1;

  float *pfVar2;

  LARGE_INTEGER *lpPerformanceCount;

  uint *puVar3;

  float fVar4;

  

  pcVar1 = (char *)(param_2 + 0x20 + param_1);

  *pcVar1 = *pcVar1 + -1;

  if (*pcVar1 < '\0') {

    *(uint8_t *)(param_2 + 0x20 + param_1) = 0;

  }

  if (*(char *)(param_2 + 0x20 + param_1) == '\0') {

    lpPerformanceCount = (LARGE_INTEGER *)(param_1 + 0x1b8 + param_2 * 8);

    QueryPerformanceCounter(lpPerformanceCount);

    puVar3 = (uint *)(param_1 + 0x148 + param_2 * 8);

    fVar4 = (float)CONCAT44(((lpPerformanceCount->s).HighPart -

                            *(int *)(param_1 + 0x14c + param_2 * 8)) -

                            (uint)((lpPerformanceCount->s).LowPart < *puVar3),

                            (lpPerformanceCount->s).LowPart - *puVar3) * *(float *)(param_1 + 0x14);

    *(float *)(param_1 + 0x30 + param_2 * 4) = fVar4;

    if (*(float *)(param_1 + 0xd8 + param_2 * 4) < fVar4) {

      *(float *)(param_1 + 0xd8 + param_2 * 4) = fVar4;

    }

    fVar4 = *(float *)(param_1 + 0x110 + param_2 * 4);

    pfVar2 = (float *)(param_1 + 0x30 + param_2 * 4);

    if (*pfVar2 <= fVar4 && fVar4 != *pfVar2) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x110 + param_2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30 + param_2 * 4)

      ;

    }

  }

  return;

}
