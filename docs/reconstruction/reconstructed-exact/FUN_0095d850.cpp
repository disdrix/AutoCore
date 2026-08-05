// =============================================================================
// FUN_0095d850
// -----------------------------------------------------------------------------
// Stable ID: aa_0095d850
// Address:   0x0095d850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095d850 @ 0x0095d850
// Stable ID: aa_0095d850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, goto×4, do×1, return×1, for×1, while×1.
//  - Notable callees: FUN_0095d850.
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

void __fastcall FUN_0095d850(uint32_t /* width from decompiler */ param_1,int param_2,int param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int *piVar2;

  int *piVar3;

  int in_EAX;

  int *piVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  piVar7 = *(int **)(in_EAX + 4);

  piVar2 = *(int **)(in_EAX + 8);

joined_r0x0095d86b:

  do {

    if (piVar7 == piVar2) {

      return;

    }

    piVar3 = *(int **)(param_3 + 0xc);

    iVar6 = 0;

    piVar4 = piVar3;

    if (piVar3 != *(int **)(param_3 + 0x10)) {

LAB_0095d890:

      if (*(int *)(*(int *)(*piVar4 + 0xf4) + 8) != *piVar7) break;

      if (iVar6 != -1) {

        if ((uint32_t /* width from decompiler */ *)*puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

          puVar8 = (uint32_t /* width from decompiler */ *)*puVar1;

          puVar9 = (uint32_t /* width from decompiler */ *)(*(int *)(piVar3[iVar6] + 0xf4) + 0x40);

          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {

            *puVar9 = *puVar8;

            puVar8 = puVar8 + 1;

            puVar9 = puVar9 + 1;

          }

          goto LAB_0095d8cb;

        }

        goto joined_r0x0095d86b;

      }

    }

LAB_0095d8cb:

    piVar7 = piVar7 + 1;

    puVar1 = puVar1 + 1;

  } while( true );

  piVar4 = piVar4 + 1;

  iVar6 = iVar6 + 1;

  if (piVar4 == *(int **)(param_3 + 0x10)) goto LAB_0095d8cb;

  goto LAB_0095d890;

}
