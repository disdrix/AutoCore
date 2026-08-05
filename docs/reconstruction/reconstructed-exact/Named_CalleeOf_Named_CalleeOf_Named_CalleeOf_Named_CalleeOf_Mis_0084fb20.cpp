// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0084fb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0084fb20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
// Address:   0x0084fb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, return×2.
//  - Notable callees: FUN_0040e490×4, FUN_0084fb20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0084fb20(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *unaff_EDI;

  

  if (unaff_EDI[0x18c] != 0) {

    cVar1 = (**(code **)(*unaff_EDI + 0x3d8))();

    if (cVar1 == '\0') {

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040e490(unaff_EDI + 0x189);

      while (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)*puVar2)(1);

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040e490(unaff_EDI + 0x189);

      }

      unaff_EDI[0x18c] = 0;

      return;

    }

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040e490(unaff_EDI + 0x189);

    while (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      cVar1 = (**(code **)(*unaff_EDI + 0xbc))(puVar2);

      if ((cVar1 == '\0') && (puVar2 != (uint32_t /* width from decompiler */ *)0x0)) {

        (**(code **)*puVar2)(1);

      }

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_0040e490(unaff_EDI + 0x189);

    }

  }

  return;

}
