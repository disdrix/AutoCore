// =============================================================================
// FUN_0071f5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f5e0
// Address:   0x0071f5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071f5e0 @ 0x0071f5e0
// Stable ID: aa_0071f5e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: fwrite×12, FUN_0071f5e0.
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

void __thiscall FUN_0071f5e0(char *param_1,FILE *param_2)



{

  char cVar1;

  char *pcVar2;

  size_t local_4;

  

  local_4 = 0;

  if (param_1 != (char *)0x0) {

    pcVar2 = param_1;

    do {

      cVar1 = *pcVar2;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

    local_4 = (int)pcVar2 - (int)(param_1 + 1);

  }

  fwrite(&local_4,4,1,param_2);

  if (0 < (int)local_4) {

    fwrite(param_1,1,local_4,param_2);

  }

  fwrite(param_1 + 0xa5,1,1,param_2);

  fwrite(param_1 + 0xa4,1,1,param_2);

  fwrite(param_1 + 0xa0,4,1,param_2);

  fwrite(param_1 + 0x8c,4,1,param_2);

  fwrite(param_1 + 0x90,4,1,param_2);

  fwrite(param_1 + 0x9c,4,1,param_2);

  fwrite(param_1 + 0x80,4,1,param_2);

  fwrite(param_1 + 0x84,4,1,param_2);

  fwrite(param_1 + 0x88,4,1,param_2);

  fwrite(param_1 + 0xb8,4,1,param_2);

  return;

}
