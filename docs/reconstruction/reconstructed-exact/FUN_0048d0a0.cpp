// =============================================================================
// FUN_0048d0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d0a0
// Address:   0x0048d0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d0a0 @ 0x0048d0a0
// Stable ID: aa_0048d0a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0048a940, FUN_0048cca0, FUN_0048d0a0.
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

void __thiscall FUN_0048d0a0(int param_1,int param_2,int param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ *extraout_ECX;

  

  if (*(char *)(param_1 + 0x2c) == '\0') {

    *(int *)(param_1 + 0x30) = param_2;

    *(uint8_t *)(param_1 + 0x2c) = 1;

    pcVar2 = (&PTR_s_No_error_00aef908)[param_2];

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    FUN_0048a940(pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0xffffffff;

    if ((param_3 != 0) && (param_4 != 0)) {

      FUN_0048cca0(param_3,param_5);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = *extraout_ECX;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = extraout_ECX[1];

    }

  }

  return;

}
