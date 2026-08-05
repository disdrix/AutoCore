// =============================================================================
// FUN_00837870
// -----------------------------------------------------------------------------
// Stable ID: aa_00837870
// Address:   0x00837870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00837870 @ 0x00837870
// Stable ID: aa_00837870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, do×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_00835240, FUN_00836410, FUN_00837870, LeaveCriticalSection.
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

void FUN_00837870(uint32_t /* width from decompiler */ param_1,char param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  if ((DAT_00d1b6d8 != 0) && (iVar4 = *(int *)(DAT_00d1b6d8 + 0x250), iVar4 != 0)) {

    iVar3 = 0;

    local_4 = iVar4;

    do {

      if ((((iVar3 != 8) && (iVar1 = *(int *)(*(int *)(iVar4 + 0x260) + iVar3), iVar1 != 0)) &&

          (iVar1 = *(int *)(iVar1 + 0x13c), iVar1 != 0)) && (*(int *)(iVar1 + 0x24) != 0)) {

        local_8 = 0;

        local_c = 0;

        FUN_004294f0();

        iVar2 = FUN_004022a0(&local_8,&local_c);

        while (iVar2 == 0) {

          if ((local_c != 0) && (*(int *)(local_c + 4) != 0)) {

            if (param_2 == '\0') {

              FUN_00835240(0);

            }

            else {

              FUN_00836410(param_1,1,1,1,0x3f000000);

            }

          }

          iVar2 = FUN_004022a0(&local_8,&local_c);

          iVar4 = local_4;

        }

        if (*(char *)(iVar1 + 0x28) != '\0') {

          *(uint8_t *)(iVar1 + 0x28) = 0;

          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 4));

        }

      }

      iVar3 = iVar3 + 4;

    } while (iVar3 < 0xc);

  }

  return;

}
