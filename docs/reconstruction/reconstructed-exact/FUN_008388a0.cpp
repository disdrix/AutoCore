// =============================================================================
// FUN_008388a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008388a0
// Address:   0x008388a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008388a0 @ 0x008388a0
// Stable ID: aa_008388a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_00867a20×2, FUN_00867bd0×2, FUN_008388a0, __RTDynamicCast.
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

void FUN_008388a0(char param_1,char param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  short sVar4;

  short *psVar5;

  int unaff_EDI;

  

  if (*(int **)(unaff_EDI + 0x518) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x518) + 0x1d4))();

    iVar2 = *(int *)(unaff_EDI + 0x518);

    iVar3 = *(int *)(*(int *)(iVar2 + 0xa8) + 0x38);

    if (((iVar3 == 0x12) || ((iVar3 == 0xe && (iVar2 = *(int *)(iVar2 + 0xac), iVar2 != 0)))) &&

       (iVar2 = __RTDynamicCast(iVar2,0,&CVOGClonedObjectBase::RTTI_Type_Descriptor,

                                &CVOGCreature::RTTI_Type_Descriptor,0), iVar2 != 0)) {

      if ((param_2 != '\0') && (*(int *)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) != 0))

      {

        iVar3 = (-(uint)(param_1 != '\0') & 999) + 1;

        FUN_00867bd0(iVar3,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x510),*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x514),0);

        FUN_00867a20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4),iVar3,0);

        (**(code **)(**(int **)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) + 0xcc))(1);

        (**(code **)(**(int **)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) + 0x34c))();

        *(int *)(unaff_EDI + 0x548) = *(int *)(unaff_EDI + 0x548) + 1;

      }

      iVar3 = 0;

      psVar5 = (short *)(iVar2 + 0x1ac);

      do {

        if (iVar3 != 2) {

          sVar4 = *psVar5;

          if ((iVar1 != 0) && (*(int **)(iVar1 + 0x254) != (int *)0x0)) {

            iVar2 = (**(code **)(**(int **)(iVar1 + 0x254) + 0x38))();

            sVar4 = sVar4 + *(short *)(iVar2 + iVar3 * 2);

          }

          if (param_1 == '\0') {

            if ((0 < sVar4) && (sVar4 < 1000)) goto LAB_00838a2b;

          }

          else if (999 < sVar4) {

LAB_00838a2b:

            if (*(int *)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) != 0) {

              FUN_00867bd0(sVar4,*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x510),

                           *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x514),1);

              FUN_00867a20(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4),

                           sVar4,0);

              (**(code **)(**(int **)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) + 0xcc))

                        (1);

              (**(code **)(**(int **)(unaff_EDI + 0x54c + *(int *)(unaff_EDI + 0x548) * 4) + 0x34c))

                        ();

            }

            *(int *)(unaff_EDI + 0x548) = *(int *)(unaff_EDI + 0x548) + 1;

          }

        }

        iVar3 = iVar3 + 1;

        psVar5 = psVar5 + 1;

      } while (iVar3 < 6);

    }

  }

  return;

}
