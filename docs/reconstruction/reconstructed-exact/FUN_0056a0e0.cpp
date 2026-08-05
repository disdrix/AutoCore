// =============================================================================
// FUN_0056a0e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a0e0
// Address:   0x0056a0e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a0e0 @ 0x0056a0e0
// Stable ID: aa_0056a0e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0056a0e0.
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

void __thiscall FUN_0056a0e0(int param_1,int param_2,char param_3)



{

  short sVar1;

  short *psVar2;

  int iVar3;

  

  psVar2 = (short *)(param_1 + 0x124);

  iVar3 = 0;

  do {

    sVar1 = *(short *)(param_2 + iVar3 * 2);

    if (param_3 == '\0') {

      *psVar2 = *psVar2 + sVar1;

    }

    else {

      *psVar2 = *psVar2 - sVar1;

    }

    if (*psVar2 < 0) {

      *psVar2 = 0;

    }

    iVar3 = iVar3 + 1;

    psVar2 = psVar2 + 1;

  } while (iVar3 < 6);

  return;

}
