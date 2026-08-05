// =============================================================================
// FUN_0071fed0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fed0
// Address:   0x0071fed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071fed0 @ 0x0071fed0
// Stable ID: aa_0071fed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×4, while×4, do×2, for×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_0071fed0, LeaveCriticalSection.
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

void FUN_0071fed0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  

  iVar5 = (int)param_1;

  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0x170);

  EnterCriticalSection(lpCriticalSection);

  puVar8 = *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x44);

  piVar1 = (int *)((int)param_1 + 0x48);

  param_1 = puVar8;

  if (puVar8 != (uint32_t /* width from decompiler */ *)*piVar1) {

    do {

      if (puVar8[0x2e] == 4) {

        puVar2 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0x48);

        puVar3 = puVar8;

        puVar4 = puVar8;

        while (puVar4 = puVar4 + 0x32, puVar4 != puVar2) {

          puVar7 = puVar3 + 0x32;

          puVar9 = puVar4;

          puVar10 = puVar3;

          for (iVar6 = 0x32; puVar3 = puVar7, puVar8 = param_1, iVar6 != 0; iVar6 = iVar6 + -1) {

            *puVar10 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar10 = puVar10 + 1;

          }

        }

        *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + -200;

      }

      else {

        puVar8 = puVar8 + 0x32;

        param_1 = puVar8;

      }

    } while (puVar8 != *(uint32_t /* width from decompiler */ **)(iVar5 + 0x48));

  }

  puVar8 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0x54);

  param_1 = puVar8;

  if (puVar8 != *(uint32_t /* width from decompiler */ **)(iVar5 + 0x58)) {

    do {

      if (puVar8[0x2e] == 4) {

        puVar2 = *(uint32_t /* width from decompiler */ **)(iVar5 + 0x58);

        puVar3 = puVar8;

        puVar4 = puVar8;

        while (puVar4 = puVar4 + 0x32, puVar4 != puVar2) {

          puVar7 = puVar3 + 0x32;

          puVar9 = puVar4;

          puVar10 = puVar3;

          for (iVar6 = 0x32; puVar3 = puVar7, puVar8 = param_1, iVar6 != 0; iVar6 = iVar6 + -1) {

            *puVar10 = *puVar9;

            puVar9 = puVar9 + 1;

            puVar10 = puVar10 + 1;

          }

        }

        *(int *)(iVar5 + 0x58) = *(int *)(iVar5 + 0x58) + -200;

      }

      else {

        puVar8 = puVar8 + 0x32;

        param_1 = puVar8;

      }

    } while (puVar8 != *(uint32_t /* width from decompiler */ **)(iVar5 + 0x58));

  }

                    /* WARNING: Could not recover jumptable at 0x0071ffb5. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  LeaveCriticalSection(lpCriticalSection);

  return;

}
