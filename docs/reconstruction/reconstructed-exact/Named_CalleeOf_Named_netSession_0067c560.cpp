// =============================================================================
// Named_CalleeOf_Named_netSession_0067c560
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c560
// Callee of Named_netSession
// Address:   0x0067c560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0067c560.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_netSession
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

void __thiscall Named_CalleeOf_Named_netSession_0067c560(int param_1,char param_2)



{

  int iVar1;

  

  iVar1 = 0;

  if (*(byte *)(param_1 + 6) != 0) {

    do {

      if (*(char *)(param_1 + 7 + iVar1) == param_2) {

        return;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 6));

  }

  *(char *)(*(byte *)(param_1 + 6) + 7 + param_1) = param_2;

  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';

  return;

}
