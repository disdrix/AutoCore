// =============================================================================
// FUN_004c8780
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8780
// Address:   0x004c8780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c8780 @ 0x004c8780
// Stable ID: aa_004c8780
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×10, while×5, return×3, do×1.
//  - Notable callees: FUN_004bb0d0, FUN_004c8780, FUN_004cb740, Object_ResolveFromTFID.
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

int * __fastcall FUN_004c8780(int param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int *piVar6;

  uint8_t auStack_24 [4];

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ local_4;

  

  piVar5 = (int *)**(int **)(param_1 + 0x158);

  if (piVar5 != *(int **)(param_1 + 0x158)) {

    do {

      piVar3 = Object_ResolveFromTFID((TFID_16 *)(piVar5 + 4));

      piVar6 = piVar5;

      if (piVar3 == (int *)0x0) {

        iVar4 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

        local_4 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x50);

        if (((((TFID_16 *)(piVar5 + 4))->dwCoidLo == *(uint *)(iVar4 + 0x44)) &&

            (piVar5[5] == *(int *)(iVar4 + 0x48))) &&

           ((char)piVar5[6] == (char)*(uint32_t /* width from decompiler */ *)(iVar4 + 0x4c))) {

          (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 600))

                    (DAT_009cb8c0,DAT_009cb8c4,DAT_009cb8c8,DAT_009cb8cc);

        }

        if (*(char *)((int)piVar5 + 0x29) == '\0') {

          piVar6 = (int *)piVar5[2];

          if (*(char *)((int)piVar6 + 0x29) == '\0') {

            cVar1 = *(char *)(*piVar6 + 0x29);

            piVar3 = (int *)*piVar6;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar3 + 0x29);

              piVar6 = piVar3;

              piVar3 = (int *)*piVar3;

            }

          }

          else {

            cVar1 = *(char *)(piVar5[1] + 0x29);

            piVar2 = (int *)piVar5[1];

            piVar3 = piVar5;

            while ((piVar6 = piVar2, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {

              cVar1 = *(char *)(piVar6[1] + 0x29);

              piVar2 = (int *)piVar6[1];

              piVar3 = piVar6;

            }

          }

        }

        FUN_004cb740(auStack_24,piVar5);

      }

      else {

        iVar4 = (**(code **)(*piVar3 + 0x210))(0);

        if (iVar4 != 0) {

          return piVar3;

        }

        iVar4 = (**(code **)(*piVar3 + 0x214))();

        if (iVar4 != 0) {

          uStack_20 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x228);

          uStack_1c = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x22c);

          uStack_18 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x230);

          uStack_14 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x234);

          iVar4 = FUN_004bb0d0(&uStack_20);

          if (iVar4 != 0) {

            return piVar3;

          }

        }

        if (*(char *)((int)piVar5 + 0x29) == '\0') {

          piVar6 = (int *)piVar5[2];

          if (*(char *)((int)piVar6 + 0x29) == '\0') {

            cVar1 = *(char *)(*piVar6 + 0x29);

            piVar5 = (int *)*piVar6;

            while (cVar1 == '\0') {

              cVar1 = *(char *)(*piVar5 + 0x29);

              piVar6 = piVar5;

              piVar5 = (int *)*piVar5;

            }

          }

          else {

            cVar1 = *(char *)(piVar5[1] + 0x29);

            piVar3 = (int *)piVar5[1];

            while ((piVar6 = piVar3, cVar1 == '\0' && (piVar5 == (int *)piVar6[2]))) {

              cVar1 = *(char *)(piVar6[1] + 0x29);

              piVar3 = (int *)piVar6[1];

              piVar5 = piVar6;

            }

          }

        }

      }

      piVar5 = piVar6;

    } while (piVar6 != *(int **)(param_1 + 0x158));

  }

  return (int *)0x0;

}
