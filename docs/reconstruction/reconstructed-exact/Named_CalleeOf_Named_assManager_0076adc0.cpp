// =============================================================================
// Named_CalleeOf_Named_assManager_0076adc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076adc0
// Callee of Named_assManager (+1 other named callers)
// Address:   0x0076adc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, if×2, return×2.
//  - Notable callees: FUN_0076adc0, stat.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_assManager (+1 other named callers)
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

uint Named_CalleeOf_Named_assManager_0076adc0(char *param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint uVar4;

  uint8_t local_128 [6];

  uint local_122;

  char local_104 [260];

  

  iVar2 = -(int)param_1;

  do {

    cVar1 = *param_1;

    param_1[(int)(local_104 + iVar2)] = cVar1;

    param_1 = param_1 + 1;

  } while (cVar1 != '\0');

  pcVar3 = local_104;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if ((pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] == '\\') ||

     (pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] == '/')) {

    pcVar3[(int)(local_104 + (-1 - (int)(local_104 + 1)))] = '\0';

  }

  uVar4 = stat(local_104,local_128);

  if (uVar4 != 0) {

    return uVar4 & 0xffffff00;

  }

  return local_122 >> 0xe & 1;

}
