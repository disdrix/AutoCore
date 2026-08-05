// =============================================================================
// FUN_0096f060
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f060
// Address:   0x0096f060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096f060 @ 0x0096f060
// Stable ID: aa_0096f060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_0043f120, FUN_0096bbb0, FUN_0096c060, FUN_0096f060.
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

uint32_t /* width from decompiler */ FUN_0096f060(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *unaff_EBX;

  

  iVar3 = FUN_0043f120();

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0096bbb0();

    if (iVar3 != 0) {

      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;

      if (*(int *)(iVar3 + 8) == 1) {

        (**(code **)(*(int *)(iVar3 + 4) + 4))();

      }

    }

  }

  iVar2 = *unaff_EBX;

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  *unaff_EBX = iVar3;

  if (iVar3 != 0) {

    uVar4 = FUN_0096c060(param_1,param_2,0xfffffffd);

    return uVar4;

  }

  return 0xffffffff;

}
