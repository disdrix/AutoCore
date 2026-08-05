// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006cad30
// -----------------------------------------------------------------------------
// Stable ID: aa_006cad30
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x006cad30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_006cac60, FUN_006cad30.
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_006cad30(int param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  

  uVar3 = param_2;

  if (param_2 != 0) {

    iVar4 = 0;

    if (0 < (int)param_2) {

      do {

        iVar1 = *(int *)(param_1 + 4 + iVar4 * 8);

        iVar2 = *(int *)(param_1 + iVar4 * 8);

        if (*(uint *)(iVar1 + 4) < *(uint *)(iVar2 + 4)) {

          *(int *)(param_1 + iVar4 * 8) = iVar1;

          *(int *)(param_1 + 4 + iVar4 * 8) = iVar2;

        }

        iVar4 = iVar4 + 1;

      } while (iVar4 < (int)param_2);

    }

    param_2 = param_2 & 0xffffff00;

    if (1 < (int)uVar3) {

      FUN_006cac60(param_1,0,uVar3 - 1,param_2);

    }

  }

  return;

}
