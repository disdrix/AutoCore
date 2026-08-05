// =============================================================================
// Named_CalleeOf_Named_Starting_ShutDown_on_Client_007f9c10
// -----------------------------------------------------------------------------
// Stable ID: aa_007f9c10
// Callee of Named_Starting_ShutDown_on_Client
// Address:   0x007f9c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Starting_ShutDown_on_Client: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007f9c10, SetCursor.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Starting_ShutDown_on_Client
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_Starting_ShutDown_on_Client_007f9c10(void)



{

  int iVar1;

  int unaff_ESI;

  

  if (*(char *)(unaff_ESI + 0x489) != '\0') {

    SetCursor((HCURSOR)0x0);

    if ((*(char *)(DAT_00d1f058 + 4) != '\0') && (*(char *)(DAT_00d1f058 + 6) == '\0')) {

      iVar1 = (**(code **)(*(int *)*DAT_00d1f044 + 0x30))

                        ((int *)*DAT_00d1f044,*(char *)(unaff_ESI + 0x48a) != '\0');

      if (-1 < iVar1) {

        return 1;

      }

    }

  }

  return 0;

}
