// =============================================================================
// FUN_00819b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00819b20
// Address:   0x00819b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00819b20 @ 0x00819b20
// Stable ID: aa_00819b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify×4, FUN_00410420, FUN_00794090, FUN_00819b20.
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

void FUN_00819b20(void)



{

  int unaff_EBX;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ **ppuStack_18;

  uint32_t /* width from decompiler */ *puStack_14;

  uint32_t /* width from decompiler */ *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  if (unaff_EDI != (int *)0x0) {

    uStack_c = 0x9c48;

    puStack_10 = (uint32_t /* width from decompiler */ *)0x819b36;

    (**(code **)(*unaff_EDI + 0x74))();

    if (unaff_EDI[0x24c] != 0) {

      puStack_10 = (uint32_t /* width from decompiler */ *)0x819b47;

      FUN_00794090();

    }

    puStack_10 = (uint32_t /* width from decompiler */ *)0x0;

    puStack_14 = (uint32_t /* width from decompiler */ *)0x0;

    ppuStack_18 = (uint32_t /* width from decompiler */ **)0x819b58;

    FUN_00410420();

    puStack_10 = &DAT_00a2d820;

    puStack_14 = (uint32_t /* width from decompiler */ *)0x819b67;

    uStack_c = (**(code **)(*unaff_EDI + 0x448))();

    puStack_14 = &uStack_c;

    ppuStack_18 = (uint32_t /* width from decompiler */ **)0x819b77;

    CVOGReaction_FailMissionNotify();

    puStack_14 = (uint32_t /* width from decompiler */ *)&DAT_00a7a10c;

    ppuStack_18 = (uint32_t /* width from decompiler */ **)0x819b86;

    puStack_10 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EDI + 0x448))();

    ppuStack_18 = &puStack_10;

    CVOGReaction_FailMissionNotify();

    ppuStack_18 = (uint32_t /* width from decompiler */ **)0xa6a450;

    puStack_14 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EDI + 0x448))();

    CVOGReaction_FailMissionNotify(&puStack_14);

    ppuStack_18 = (uint32_t /* width from decompiler */ **)(**(code **)(*unaff_EDI + 0x448))(&DAT_00a7a110);

    CVOGReaction_FailMissionNotify(&ppuStack_18);

    (**(code **)(*unaff_EDI + 0x45c))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EBX + 0xf28) + DAT_00afa2dc * 4));

  }

  return;

}
