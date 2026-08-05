// =============================================================================
// FUN_0048bf60
// -----------------------------------------------------------------------------
// Stable ID: aa_0048bf60
// Address:   0x0048bf60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048bf60 @ 0x0048bf60
// Stable ID: aa_0048bf60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0048a940×4, FUN_0048bf60.
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

void __thiscall FUN_0048bf60(int param_1,int param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  

  pcVar3 = (char *)(*(int *)(param_1 + 0x20) + 8);

  pcVar2 = pcVar3;

  do {

    cVar1 = *pcVar2;

    pcVar2 = pcVar2 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(pcVar3,(int)pcVar2 - (*(int *)(param_1 + 0x20) + 9));

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  FUN_0048a940(*(uint32_t /* width from decompiler */ **)(param_1 + 0x2c) + 2,**(uint32_t /* width from decompiler */ **)(param_1 + 0x2c));

  FUN_0048a940(*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) + 2,**(uint32_t /* width from decompiler */ **)(param_1 + 0x30));

  FUN_0048a940(*(uint32_t /* width from decompiler */ **)(param_1 + 0x34) + 2,**(uint32_t /* width from decompiler */ **)(param_1 + 0x34));

  return;

}
