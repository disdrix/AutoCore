// =============================================================================
// FUN_007a79b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007a79b0
// Address:   0x007a79b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a79b0 @ 0x007a79b0
// Stable ID: aa_007a79b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_007a79b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_007a79b0(int param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  

  if (param_2 != (char *)0x0) {

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    if (*(void **)(param_1 + 0x27c) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x27c));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x27c) = 0;

    pcVar2 = operator_new__((uint)(pcVar2 + (1 - (int)(param_2 + 1))));

    *(char **)(param_1 + 0x27c) = pcVar2;

    do {

      cVar1 = *param_2;

      *pcVar2 = cVar1;

      param_2 = param_2 + 1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
