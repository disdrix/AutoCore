// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×3, while×3, do×1, for×1, return×1.
//  - Notable callees: FUN_004c8a60, FUN_0051b550.
//  - Return sites: 1.

// =============================================================================
// Skill_Uses_Skill_EnsureLoadedInTree
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Skill_EnsureLoadedInTree"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004c8a60 clean capture (not modernized).
//
// Address:  0x004c8a60  (autoassault.exe, image base 0x400000)
// Stable:   aa_004c8a60
// Stable ID: aa_004c8a60
// System:   skills-abilities
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004c8a60_*.md
//           Original Ghidra symbol: FUN_004c8a60
//
// Exactness: Body mirrors reconstructed-exact/FUN_004c8a60*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Skill_Uses_Skill_EnsureLoadedInTree
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8a60
// Address:   0x004c8a60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Skill_EnsureLoadedInTree"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Skill_Uses_Skill_EnsureLoadedInTree(int param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  uint uVar7;

  

  FUN_0051b550();

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x454 + param_1) + 0x3c);

  piVar3 = *(int **)(iVar2 + 0x520);

  piVar6 = (int *)*piVar3;

  if (piVar6 != piVar3) {

    do {

      iVar5 = 0;

      for (uVar7 = 0; (piVar6[5] != 0 && (uVar7 < (uint)((piVar6[6] - piVar6[5]) / 0x18)));

          uVar7 = uVar7 + 1) {

        Skill_EnsureLoadedInTree

                  ((void *)(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1),

                   *(int *)(piVar6[5] + iVar5),*(short *)(piVar6[5] + 8 + iVar5));

        iVar5 = iVar5 + 0x18;

      }

      if (*(char *)((int)piVar6 + 0x21) == '\0') {

        piVar3 = (int *)piVar6[2];

        if (*(char *)((int)piVar3 + 0x21) == '\0') {

          cVar1 = *(char *)(*piVar3 + 0x21);

          piVar6 = piVar3;

          piVar3 = (int *)*piVar3;

          while (cVar1 == '\0') {

            cVar1 = *(char *)(*piVar3 + 0x21);

            piVar6 = piVar3;

            piVar3 = (int *)*piVar3;

          }

        }

        else {

          cVar1 = *(char *)(piVar6[1] + 0x21);

          piVar4 = (int *)piVar6[1];

          piVar3 = piVar6;

          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {

            cVar1 = *(char *)(piVar6[1] + 0x21);

            piVar4 = (int *)piVar6[1];

            piVar3 = piVar6;

          }

        }

      }

    } while (piVar6 != *(int **)(iVar2 + 0x520));

  }

  return;

}
