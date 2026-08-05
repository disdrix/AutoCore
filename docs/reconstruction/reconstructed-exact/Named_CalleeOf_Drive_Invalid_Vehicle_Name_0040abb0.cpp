// =============================================================================
// Named_CalleeOf_Drive_Invalid_Vehicle_Name_0040abb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040abb0
// Callee of Drive_Invalid_Vehicle_Name
// Address:   0x0040abb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Invalid_Vehicle_Name: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0040abb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Drive_Invalid_Vehicle_Name
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

void __fastcall Named_CalleeOf_Drive_Invalid_Vehicle_Name_0040abb0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  char *in_EAX;

  int iVar2;

  

  if (in_EAX != (char *)0x0) {

    iVar2 = (param_2 + 0x1b0) - (int)in_EAX;

    do {

      cVar1 = *in_EAX;

      in_EAX[iVar2] = cVar1;

      in_EAX = in_EAX + 1;

    } while (cVar1 != '\0');

  }

  return;

}
