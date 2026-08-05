// =============================================================================
// Named_CalleeOf_Client_PacketDispatch_0080b3a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080b3a0
// Callee of Client_PacketDispatch
// Address:   0x0080b3a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, do×1, switch×1, return×1.
//  - Notable callees: ROUND×4, FUN_004022a0×2, FUN_004294f0, FUN_0080b3a0, LeaveCriticalSection, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_PacketDispatch
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Client_PacketDispatch_0080b3a0(int param_1)



{

  int iVar1;

  char cVar2;

  int *piVar3;

  int iVar4;

  int *piVar5;

  int unaff_EBX;

  int iVar6;

  float *pfVar7;

  TFID_16 *pTfid;

  uint64_t uVar8;

  int *piStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  float fStack_24;

  int iStack_20;

  float fStack_1c;

  int iStack_18;

  float fStack_14;

  int iStack_10;

  float fStack_c;

  int iStack_8;

  TFID_16 *local_4;

  

  pTfid = (TFID_16 *)(unaff_EBX + 8);

  local_4 = pTfid;

  piVar3 = Object_ResolveFromTFID(pTfid);

  if (piVar3 != (int *)0x0) {

    iVar6 = 0;

    if (*(char *)(unaff_EBX + 0x18) != '\0') {

      pfVar7 = (float *)(unaff_EBX + 0x24);

      do {

        switch(*(uint8_t *)(pfVar7 + -2)) {

        case 0:

          iVar4 = (**(code **)(*piVar3 + 0x1d4))();

          if (iVar4 != 0) {

            fStack_24 = *pfVar7;

            iStack_20 = (int)ROUND(fStack_24);

            iVar4 = (**(code **)(*piVar3 + 0x1d4))();

            *(int *)(iVar4 + 0x150) = iStack_20;

          }

          break;

        case 1:

          iVar4 = (**(code **)(*piVar3 + 0x1d4))();

          if (iVar4 != 0) {

            fStack_1c = *pfVar7;

            iStack_18 = (int)ROUND(fStack_1c);

            uVar8 = (**(code **)(*piVar3 + 0x1d4))(iStack_18);

            Vehicle_SetCurrentShield

                      ((VehicleCombatPools_Inferred *)uVar8,(int)((ulonglong)uVar8 >> 0x20));

          }

          break;

        case 2:

          fStack_14 = *pfVar7;

          iStack_10 = (int)ROUND(fStack_14);

          (**(code **)(*piVar3 + 0x240))(iStack_10);

          break;

        case 3:

          iVar4 = (**(code **)(*piVar3 + 0x1d8))();

          if (iVar4 != 0) {

            piVar5 = (int *)(**(code **)(*piVar3 + 0x1d8))();

            (**(code **)(*piVar5 + 0xac))((int)*pfVar7);

          }

          break;

        case 4:

          fStack_c = *pfVar7;

          iStack_8 = (int)ROUND(fStack_c);

          (**(code **)(*piVar3 + 0x18c))(iStack_8);

          break;

        case 5:

          uStack_28 = 0;

          FUN_004294f0();

          FUN_004022a0(&uStack_28,&piStack_2c);

          while (piStack_2c != (int *)0x0) {

            if ((piStack_2c[7] == 1) && ((float)piStack_2c[0x188] == pfVar7[-1])) {

              (**(code **)(*piStack_2c + 0x4c))(piVar3,(int)*pfVar7);

              break;

            }

            FUN_004022a0(&uStack_28,&piStack_2c);

          }

          iVar4 = piVar3[0x2c];

          if (*(char *)(iVar4 + 0x28) != '\0') {

            *(uint8_t *)(iVar4 + 0x28) = 0;

            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 4));

          }

          break;

        case 6:

          (**(code **)(*piVar3 + 0x220))(pfVar7[-1],0);

        }

        iVar6 = iVar6 + 1;

        pfVar7 = pfVar7 + 3;

        pTfid = local_4;

      } while (iVar6 < (int)(uint)*(byte *)(unaff_EBX + 0x18));

    }

    if (*(int *)(param_1 + 0xe98) != 0) {

      iVar4 = *(int *)(param_1 + 0xe98);

      iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

      iVar6 = iVar1 + 0x164 + iVar4;

      if ((((pTfid->dwCoidLo == *(uint *)(iVar1 + 0x164 + iVar4)) &&

           (pTfid->dwCoidHi == *(uint *)(iVar6 + 4))) && (pTfid->bGlobal == *(byte *)(iVar6 + 8)))

         && ((*(int *)(param_1 + 0x1034) != 0 &&

             (cVar2 = (**(code **)(**(int **)(param_1 + 0x1034) + 0x3d8))(), cVar2 != '\0')))) {

        piVar3 = *(int **)(param_1 + 0x1034);

        (**(code **)(*piVar3 + 0x448))();

        (**(code **)(*piVar3 + 0x34c))();

      }

    }

  }

  return;

}
