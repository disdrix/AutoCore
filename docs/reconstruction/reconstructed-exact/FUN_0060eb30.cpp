// =============================================================================
// FUN_0060eb30
// -----------------------------------------------------------------------------
// Stable ID: aa_0060eb30
// Address:   0x0060eb30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060eb30 @ 0x0060eb30
// Stable ID: aa_0060eb30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×1, return×1.
//  - Notable callees: FUN_0060eb30.
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

void __thiscall FUN_0060eb30(int param_1,char *param_2)



{

  char *pcVar1;

  char cVar2;

  char *pcVar3;

  char *pcVar4;

  

  if (*(void **)(param_1 + 0x18) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x18));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  pcVar1 = param_2 + 1;

  pcVar3 = param_2;

  do {

    cVar2 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar2 != '\0');

  pcVar4 = operator_new__((uint)(pcVar3 + (1 - (int)pcVar1)));

  *(char **)(param_1 + 0x18) = pcVar4;

  do {

    cVar2 = *param_2;

    *pcVar4 = cVar2;

    param_2 = param_2 + 1;

    pcVar4 = pcVar4 + 1;

  } while (cVar2 != '\0');

  pcVar3[*(int *)(param_1 + 0x18) - (int)pcVar1] = '\0';

  return;

}
