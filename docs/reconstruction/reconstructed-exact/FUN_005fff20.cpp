// =============================================================================
// FUN_005fff20
// -----------------------------------------------------------------------------
// Stable ID: aa_005fff20
// Address:   0x005fff20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fff20 @ 0x005fff20
// Stable ID: aa_005fff20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: while×2, if×1, do×1, return×1.
//  - Notable callees: FUN_005fff20.
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

void FUN_005fff20(void)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *in_EAX;

  int iVar4;

  

  iVar3 = in_EAX[1];

  while (iVar3 = iVar3 + -1, -1 < iVar3) {

    if ((*(int *)(*in_EAX + iVar3 * 4) == 0) &&

       (in_EAX[1] = in_EAX[1] + -1, iVar4 = iVar3, iVar3 < in_EAX[1])) {

      do {

        iVar2 = iVar4 * 4;

        iVar1 = iVar4 * 4;

        iVar4 = iVar4 + 1;

        *(uint32_t /* width from decompiler */ *)(*in_EAX + iVar1) = *(uint32_t /* width from decompiler */ *)(*in_EAX + 4 + iVar2);

      } while (iVar4 < in_EAX[1]);

    }

  }

  return;

}
