// =============================================================================
// FUN_007ae720
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae720
// Address:   0x007ae720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ae720 @ 0x007ae720
// Stable ID: aa_007ae720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×2, do×2, for×2.
//  - Notable callees: FUN_00423f40×2, FUN_004294f0, FUN_007ae720, LeaveCriticalSection.
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

uint8_t * __fastcall FUN_007ae720(int *param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  uint8_t *puVar7;

  char *pcVar8;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar7 = (uint8_t *)0x0;

  if (param_1[0x83] != 0) {

    local_8 = (int *)0x0;

    local_4 = 0;

    iVar3 = (**(code **)(*param_1 + 0x26c))();

    if (iVar3 == 0) {

      return (uint8_t *)0x0;

    }

    puVar7 = operator_new__(iVar3 + 1);

    *puVar7 = 0;

    FUN_004294f0();

    iVar3 = FUN_00423f40(&local_8);

    while (iVar3 == 0) {

      if (((*local_8 == 1) && (pcVar8 = (char *)local_8[1], pcVar8 != (char *)0x0)) &&

         (pcVar4 = pcVar8, *pcVar8 != '\0')) {

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        uVar5 = (int)pcVar4 - (int)pcVar8;

        pcVar4 = puVar7 + -1;

        do {

          pcVar1 = pcVar4 + 1;

          pcVar4 = pcVar4 + 1;

        } while (*pcVar1 != '\0');

        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar8;

          pcVar8 = pcVar8 + 4;

          pcVar4 = pcVar4 + 4;

        }

        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

          *pcVar4 = *pcVar8;

          pcVar8 = pcVar8 + 1;

          pcVar4 = pcVar4 + 1;

        }

      }

      iVar3 = FUN_00423f40(&local_8);

    }

    if ((char)param_1[0x84] != '\0') {

      *(uint8_t *)(param_1 + 0x84) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));

    }

  }

  return puVar7;

}
