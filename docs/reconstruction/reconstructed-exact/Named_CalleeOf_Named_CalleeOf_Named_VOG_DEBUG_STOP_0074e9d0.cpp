// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0074e9d0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0074e9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_0074e9d0.
//  - Return sites: 1.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074e9d0(int param_1,float param_2)



{

  uint uVar1;

  uint uVar2;

  

  if (param_2 != *(float *)(param_1 + 0x10)) {

    *(float *)(param_1 + 0x10) = param_2;

    if (*(int *)(param_1 + 4) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;

    }

    uVar1 = 0;

    if (3 < (int)uVar2) {

      do {

        *(float *)(*(int *)(param_1 + 0x28) + uVar1 * 4) =

             *(float *)(*(int *)(param_1 + 0x18) + uVar1 * 4) * *(float *)(param_1 + 0x10);

        *(float *)(*(int *)(param_1 + 0x28) + 4 + uVar1 * 4) =

             *(float *)(*(int *)(param_1 + 0x18) + 4 + uVar1 * 4) * *(float *)(param_1 + 0x10);

        *(float *)(*(int *)(param_1 + 0x28) + 8 + uVar1 * 4) =

             *(float *)(*(int *)(param_1 + 0x18) + 8 + uVar1 * 4) * *(float *)(param_1 + 0x10);

        *(float *)(*(int *)(param_1 + 0x28) + 0xc + uVar1 * 4) =

             *(float *)(*(int *)(param_1 + 0x18) + 0xc + uVar1 * 4) * *(float *)(param_1 + 0x10);

        uVar1 = uVar1 + 4;

      } while (uVar1 < uVar2 - 3);

    }

    for (; uVar1 < uVar2; uVar1 = uVar1 + 1) {

      *(float *)(*(int *)(param_1 + 0x28) + uVar1 * 4) =

           *(float *)(*(int *)(param_1 + 0x18) + uVar1 * 4) * *(float *)(param_1 + 0x10);

    }

  }

  return;

}
