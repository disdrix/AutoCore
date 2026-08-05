// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076b190
// -----------------------------------------------------------------------------
// Stable ID: aa_0076b190
// Callee of Named_CalleeOf_Named_assPackManager
// Address:   0x0076b190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPackManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0076aba0, FUN_0076af70, FUN_0076b190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPackManager
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

void Named_CalleeOf_Named_CalleeOf_Named_assPackManager_0076b190(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  char *unaff_ESI;

  char local_300 [256];

  uint8_t local_200 [256];

  uint8_t local_100 [256];

  

  FUN_0076af70(local_100,local_200,local_300);

  if (local_300[0] == '\0') {

    iVar2 = -(int)unaff_ESI;

    do {

      cVar1 = *unaff_ESI;

      unaff_ESI[(int)(local_300 + iVar2)] = cVar1;

      unaff_ESI = unaff_ESI + 1;

    } while (cVar1 != '\0');

  }

  FUN_0076aba0(param_2,local_200,local_300);

  return;

}
