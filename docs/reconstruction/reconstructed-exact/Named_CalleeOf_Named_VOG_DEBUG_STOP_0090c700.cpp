// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c700
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0090c700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0090c700.
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

void Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700(void)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *unaff_EDI;

  

  piVar3 = unaff_EDI + 0x150;

  iVar2 = 0x18;

  do {

    if (*piVar3 != 0) {

      cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*unaff_EDI + 0xb0))(*piVar3);

      }

      if ((uint32_t /* width from decompiler */ *)*piVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar3)(1);

      }

      *piVar3 = 0;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
