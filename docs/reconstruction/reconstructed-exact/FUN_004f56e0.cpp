// =============================================================================
// FUN_004f56e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f56e0
// Address:   0x004f56e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f56e0 @ 0x004f56e0
// Stable ID: aa_004f56e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: FUN_004f56e0.
//  - Return sites: 2.

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

char __thiscall FUN_004f56e0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  char cVar3;

  

  cVar3 = '\0';

  while (((iVar1 = *(int *)(*(int *)(param_1 + 0x260) + cVar3 * 4), iVar1 == 0 ||

          (iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4), *(int *)(iVar2 + 0x164 + iVar1) != param_2))

         || (*(int *)(iVar2 + 0x168 + iVar1) != param_3))) {

    cVar3 = cVar3 + '\x01';

    if ('\x02' < cVar3) {

      return -1;

    }

  }

  return cVar3;

}
