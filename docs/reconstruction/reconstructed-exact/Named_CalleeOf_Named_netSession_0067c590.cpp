// =============================================================================
// Named_CalleeOf_Named_netSession_0067c590
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c590
// Callee of Named_netSession (+1 other named callers)
// Address:   0x0067c590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_netSession (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_0067c590.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_netSession (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_netSession_0067c590(int param_1,char param_2)



{

  int iVar1;

  

  iVar1 = 0;

  if (*(char *)(param_1 + 6) != '\0') {

    do {

      if (*(char *)(param_1 + 7 + iVar1) == param_2) {

        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + -1;

        break;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 6));

  }

  if (iVar1 < (int)(uint)*(byte *)(param_1 + 6)) {

    do {

      *(uint8_t *)(param_1 + 7 + iVar1) = *(uint8_t *)(param_1 + 8 + iVar1);

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 6));

  }

  return;

}
