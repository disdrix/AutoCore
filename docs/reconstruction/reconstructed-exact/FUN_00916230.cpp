// =============================================================================
// FUN_00916230
// -----------------------------------------------------------------------------
// Stable ID: aa_00916230
// Address:   0x00916230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00916230 @ 0x00916230
// Stable ID: aa_00916230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_005070d0×2, FUN_00916230, FUN_0092f100.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint8_t FUN_00916230(void)



{

  int *piVar1;

  int iVar2;

  int *extraout_ECX;

  uint8_t uVar3;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009ac60e;

  local_c = ExceptionList;

  uVar3 = 0;

  if (*(int *)(unaff_EDI + 0x60c) == 0) {

    if ((DAT_00d1b6d8 == 0) || (*(int *)(DAT_00d1b6d8 + 8) == 0)) {

      return 0;

    }

    if ((DAT_00d20068 & 1) == 0) {

      DAT_00d20068 = DAT_00d20068 | 1;

      _DAT_00d20064 = DAT_00a1e728;

    }

    if (*(char *)(DAT_00d1b6d8 + 0x304) != '\0') {

      uVar3 = 1;

    }

  }

  else if (*(int *)(unaff_EDI + 0x60c) == 1) {

    if ((*(int *)(unaff_EDI + 0xc70) != 0) &&

       (*(char *)(*(int *)(unaff_EDI + 0xc70) + 0x21) == '\0')) {

      uVar3 = 1;

    }

    if ((((DAT_00d1b6d8 != 0) && (iVar2 = *(int *)(DAT_00d1b6d8 + 0x250), iVar2 != 0)) &&

        (*(int *)(iVar2 + 8) != 0)) && (*(int *)(iVar2 + 0x48) != 0)) {

      ExceptionList = &local_c;

      piVar1 = (int *)FUN_0092f100();

      iVar2 = (**(code **)(*extraout_ECX + 0xc))();

      (**(code **)(*piVar1 + 4))(iVar2 + 0x90,&uStack_14);

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc08) = uStack_14;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc0c) = uStack_10;

      if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x274) != 0) {

        FUN_005070d0();

        FUN_005070d0();

        ExceptionList = local_c;

        return uVar3;

      }

    }

  }

  ExceptionList = local_c;

  return uVar3;

}
