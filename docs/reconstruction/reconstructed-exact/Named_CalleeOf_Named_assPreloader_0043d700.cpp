// =============================================================================
// Named_CalleeOf_Named_assPreloader_0043d700
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d700
// Callee of Named_assPreloader
// Address:   0x0043d700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00437d60, FUN_0043d700, FUN_0043daf0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assPreloader
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

uint32_t /* width from decompiler */ * __fastcall Named_CalleeOf_Named_assPreloader_0043d700(uint *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_EDI;

  uint32_t /* width from decompiler */ local_10 [4];

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      if ((uint)puVar1[3] < *param_1) {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar4 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x15) == '\0');

  }

  if ((puVar4 != *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4)) && ((uint)puVar4[3] <= *param_1)) {

    return puVar4 + 4;

  }

  local_10[0] = 0;

  FUN_00437d60(local_10);

  piVar3 = (int *)FUN_0043daf0(puVar4);

  return (uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

}
