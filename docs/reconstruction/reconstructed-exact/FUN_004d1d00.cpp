// =============================================================================
// FUN_004d1d00
// -----------------------------------------------------------------------------
// Stable ID: aa_004d1d00
// Address:   0x004d1d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d1d00 @ 0x004d1d00
// Stable ID: aa_004d1d00
// Embedded strings (evidence for future rename):
//   - "allocatenewobjectfromcbid failed %d Get a programmer"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×16, goto×3, do×2, while×2, return×1.
//  - Notable callees: TFID_NotEquals×3, CVOGReaction_GiveItemByCbid×2, FUN_004bb1f0×2, FUN_0052b2e0×2, FUN_007a4480×2, FUN_004bc180, FUN_004d0e90, FUN_004d1d00.
//  - Strings: "allocatenewobjectfromcbid failed %d Get a programmer".
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

void __fastcall FUN_004d1d00(int param_1)



{

  TFID_16 *pTfid;

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  bool bVar7;

  bool bVar8;

  float fVar9;

  float fVar10;

  

  if (((*(int **)(param_1 + 0xe8a0) != (int *)0x0) &&

      (iVar2 = (**(code **)(**(int **)(param_1 + 0xe8a0) + 0x1dc))(), iVar2 != 0)) &&

     (iVar2 = *(int *)(param_1 + 0xe798), iVar2 != *(int *)(param_1 + 0xe79c))) {

    do {

      iVar3 = FUN_004bb1f0(iVar2);

      if ((iVar3 != 0) && (*(char *)(iVar3 + 0xde) != '\0')) {

        cVar1 = FUN_0052b2e0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c));

        bVar7 = cVar1 == '\0';

        if ((bool)*(char *)(iVar2 + 0x38) != bVar7) {

          pTfid = (TFID_16 *)(iVar2 + 0x28);

          iVar4 = TFID_NotEquals(pTfid,&DAT_009cbf68);

          if ((char)iVar4 != '\0') {

            piVar5 = Object_ResolveFromTFID(pTfid);

            if (piVar5 != (int *)0x0) {

              (**(code **)(*piVar5 + 0x2a8))(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe4e8));

              FUN_004d0e90(piVar5);

            }

            pTfid->dwCoidLo = DAT_009cbf68;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x2c) = DAT_009cbf6c;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30) = DAT_009cbf70;

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34) = DAT_009cbf74;

          }

          *(bool *)(iVar2 + 0x38) = bVar7;

          iVar4 = *(int *)(param_1 + 0xe798);

          if (iVar4 != *(int *)(param_1 + 0xe79c)) {

            do {

              if (((iVar4 != iVar2) &&

                  (fVar10 = *(float *)(iVar4 + 0x10) - *(float *)(iVar2 + 0x10),

                  fVar9 = *(float *)(iVar4 + 0x18) - *(float *)(iVar2 + 0x18),

                  fVar10 * fVar10 + fVar9 * fVar9 < DAT_00a0f718)) &&

                 ((iVar6 = FUN_004bb1f0(iVar4), iVar6 != 0 && (*(char *)(iVar6 + 0xde) != '\0')))) {

                cVar1 = FUN_0052b2e0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x1c));

                bVar8 = cVar1 != '\0';

                if (bVar7) {

                  if (!bVar8) {

                    iVar6 = TFID_NotEquals((void *)(iVar4 + 0x28),&DAT_009cbf68);

                    bVar8 = (char)iVar6 != '\0';

                    goto joined_r0x004d1f09;

                  }

LAB_004d1eab:

                  *(uint8_t *)(iVar2 + 0x38) = 0xff;

                  break;

                }

                iVar6 = TFID_NotEquals((void *)(iVar4 + 0x28),&DAT_009cbf68);

                if ((char)iVar6 != '\0') {

joined_r0x004d1f09:

                  if (bVar8) goto LAB_004d1eab;

                }

              }

              iVar4 = iVar4 + 0x40;

            } while (iVar4 != *(int *)(param_1 + 0xe79c));

          }

          if (*(char *)(iVar2 + 0x38) != -1) {

            if (bVar7) {

              piVar5 = (int *)CVOGReaction_GiveItemByCbid(DAT_00af1b60);

              if (piVar5 != (int *)0x0) {

                (**(code **)(*piVar5 + 8))(DAT_00af1b60,param_1,1);

                goto LAB_004d1f69;

              }

              FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",DAT_00af1b60);

            }

            else {

              piVar5 = (int *)CVOGReaction_GiveItemByCbid(DAT_00af1b64);

              if (piVar5 == (int *)0x0) {

                FUN_007a4480(1,"allocatenewobjectfromcbid failed %d Get a programmer",DAT_00af1b64);

              }

              else {

                (**(code **)(*piVar5 + 8))(DAT_00af1b64,param_1,1);

LAB_004d1f69:

                iVar4 = *(int *)(param_1 + 0xe6e8);

                iVar6 = *(int *)(param_1 + 0xe6ec);

                *(uint *)(param_1 + 0xe6ec) = iVar6 - (uint)(iVar4 == 0);

                *(int *)(param_1 + 0xe6e8) = iVar4 + -1;

                FUN_00512160(iVar4,iVar6,0);

                iVar6 = *(int *)(iVar2 + 0x10);

                iVar4 = *(int *)(iVar2 + 0x14);

                piVar5[0x22] = *(int *)(iVar2 + 0x18);

                piVar5[0x20] = iVar6;

                piVar5[0x21] = iVar4;

                piVar5[0x23] = 0;

                FUN_004bc180(piVar5);

                (**(code **)(*piVar5 + 0xb4))();

                iVar4 = (**(code **)(*piVar5 + 0x1cc))();

                if ((iVar4 != 0) &&

                   (iVar4 = (**(code **)(*piVar5 + 0x1cc))(), *(int *)(iVar4 + 8) != 0)) {

                  (**(code **)(*piVar5 + 0xb8))

                            (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xbc + iVar3));

                }

                *(int *)(iVar2 + 0x28) = piVar5[0x58];

                *(int *)(iVar2 + 0x2c) = piVar5[0x59];

                *(int *)(iVar2 + 0x30) = piVar5[0x5a];

                *(int *)(iVar2 + 0x34) = piVar5[0x5b];

              }

            }

          }

        }

      }

      iVar2 = iVar2 + 0x40;

    } while (iVar2 != *(int *)(param_1 + 0xe79c));

  }

  return;

}
