// =============================================================================
// FUN_00770490
// -----------------------------------------------------------------------------
// Stable ID: aa_00770490
// Address:   0x00770490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00770490 @ 0x00770490
// Stable ID: aa_00770490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00770490, realloc.
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

uint32_t /* width from decompiler */ FUN_00770490(void)



{

  uint in_EAX;

  uint uVar1;

  void *pvVar2;

  int iVar3;

  int unaff_ESI;

  int iVar4;

  

  if (*(int *)(unaff_ESI + 4) < (int)in_EAX) {

    uVar1 = in_EAX & 0x8000003f;

    if ((int)uVar1 < 0) {

      uVar1 = (uVar1 - 1 | 0xffffffc0) + 1;

    }

    iVar4 = in_EAX + (0x80 - uVar1);

    pvVar2 = realloc(*(void **)(unaff_ESI + 0xc),iVar4 * 4);

    if (pvVar2 == (void *)0x0) {

      return 0xfffffffe;

    }

    *(void **)(unaff_ESI + 0xc) = pvVar2;

    iVar3 = *(int *)(unaff_ESI + 4);

    *(int *)(unaff_ESI + 4) = iVar4;

    if (iVar3 < iVar4) {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0xc) + iVar3 * 4) = 0;

        iVar3 = iVar3 + 1;

      } while (iVar3 < *(int *)(unaff_ESI + 4));

    }

  }

  return 0;

}
