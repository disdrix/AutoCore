// =============================================================================
// FUN_0094c430
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c430
// Address:   0x0094c430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094c430 @ 0x0094c430
// Stable ID: aa_0094c430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0094c430.
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

void FUN_0094c430(void)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(unaff_ESI + 0xe98) != 0) {

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    local_18[0] = 0x208d;

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    local_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    local_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    local_8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcd8);

    local_4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcdc);

    if (*(int *)(unaff_ESI + 0xc78) != 0) {

      (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_18,0x18,0);

    }

    iVar1 = *(int *)(unaff_ESI + 0xe98);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcd8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcdc) = 0xffffffff;

  }

  return;

}
