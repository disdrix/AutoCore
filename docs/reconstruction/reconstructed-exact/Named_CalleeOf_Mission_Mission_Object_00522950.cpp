// =============================================================================
// Named_CalleeOf_Mission_Mission_Object_00522950
// -----------------------------------------------------------------------------
// Stable ID: aa_00522950
// Callee of Mission_Mission_Object (+2 other named callers)
// Address:   0x00522950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Mission_Object: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_Mission_Object (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_00522950, _stricmp.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Mission_Mission_Object (+2 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Mission_Mission_Object_00522950(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  

  if (param_2 == 0) {

    return 0;

  }

  pcVar2 = (char *)(param_2 + 0x101);

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  if (pcVar2 != (char *)(param_2 + 0x102)) {

    pcVar2 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) +

                                 0x160))();

    iVar3 = _stricmp((char *)(param_2 + 0x101),pcVar2);

    if (iVar3 != 0) {

      return 0;

    }

  }

  return 1;

}
