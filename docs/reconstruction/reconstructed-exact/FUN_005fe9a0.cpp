// =============================================================================
// FUN_005fe9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005fe9a0
// Address:   0x005fe9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fe9a0 @ 0x005fe9a0
// Stable ID: aa_005fe9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_005fe9a0.
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

void __thiscall FUN_005fe9a0(int param_1,float param_2)



{

  short *psVar1;

  short sVar2;

  int iVar3;

  

  if ((param_2 <= DAT_009c8354) || (DAT_009d2f7c <= param_2)) {

    psVar1 = (short *)(param_1 + 0xb6);

    iVar3 = 6;

    do {

      sVar2 = (short)(int)((float)(int)*psVar1 * param_2);

      *psVar1 = sVar2;

      if (sVar2 < 0) {

        *psVar1 = 0;

      }

      psVar1 = psVar1 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

  }

  return;

}
