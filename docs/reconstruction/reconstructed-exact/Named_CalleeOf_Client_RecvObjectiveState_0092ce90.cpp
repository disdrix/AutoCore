// =============================================================================
// Named_CalleeOf_Client_RecvObjectiveState_0092ce90
// -----------------------------------------------------------------------------
// Stable ID: aa_0092ce90
// Callee of Client_RecvObjectiveState (+2 other named callers)
// Address:   0x0092ce90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvObjectiveState: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvObjectiveState (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0092ce90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvObjectiveState (+2 other named callers)
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

void Named_CalleeOf_Client_RecvObjectiveState_0092ce90(void)



{

  int *piVar1;

  char cVar2;

  int unaff_EDI;

  

  piVar1 = *(int **)(unaff_EDI + 0x107c);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        (**(code **)(*piVar1 + 0x448))();

      }

    }

  }

  piVar1 = *(int **)(unaff_EDI + 0x10b8);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd0))();

    if (cVar2 != '\0') {

      cVar2 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar2 != '\0') {

        *(uint8_t *)(piVar1 + 0x148) = 1;

      }

    }

  }

  return;

}
