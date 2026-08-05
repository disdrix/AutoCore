// =============================================================================
// FUN_0065a140
// -----------------------------------------------------------------------------
// Stable ID: aa_0065a140
// Address:   0x0065a140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065a140 @ 0x0065a140
// Stable ID: aa_0065a140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0065a0a0×3, FUN_00638180×2, FUN_0062d9d0, FUN_00638060, FUN_006380a0, FUN_006381a0, FUN_006599f0, FUN_0065a140.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_0065a140(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  char *local_14;

  

  FUN_0062d9d0(*(int *)(*(int *)(param_1 + 0xc) + -0xc) + 1);

  iVar2 = FUN_006599f0(local_14,*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),param_2);

  if (iVar2 == -1) {

    FUN_0065a0a0();

    return 1;

  }

  if ((local_14 != (char *)0x0) && (*local_14 != '\0')) {

    iVar3 = FUN_00638060(local_14);

    iVar2 = *(int *)(param_1 + 0xc);

    if ((*(int *)(iVar2 + -8) < iVar3) || (0 < *(int *)(iVar2 + -4))) {

      piVar1 = (int *)(iVar2 + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      iVar2 = FUN_006381a0(iVar3);

      *(int *)(param_1 + 0xc) = iVar2 + 0xc;

    }

    FUN_006380a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),local_14,iVar3 + 1);

    *(int *)(*(int *)(param_1 + 0xc) + -0xc) = iVar3;

    FUN_0065a0a0();

    return 0;

  }

  piVar1 = (int *)(*(int *)(param_1 + 0xc) + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  DAT_00d02c6c = DAT_00d02c6c + 1;

  *(undefined **)(param_1 + 0xc) = &DAT_00d02c70;

  FUN_0065a0a0();

  return 0;

}
