// =============================================================================
// FUN_0047efa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047efa0
// Address:   0x0047efa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047efa0 @ 0x0047efa0
// Stable ID: aa_0047efa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~168 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_0047efa0.
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

void FUN_0047efa0(int param_1,int param_2)



{

  ushort uVar1;

  int iVar2;

  int in_EAX;

  byte bVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  int iVar9;

  uint uVar10;

  

  uVar4 = 0;

  if (*(int *)(in_EAX + 0x1698) != 0) {

    do {

      uVar7 = (uint)*(ushort *)(*(int *)(in_EAX + 0x169c) + uVar4 * 2);

      uVar8 = (uint)*(byte *)(uVar4 + *(int *)(in_EAX + 0x1690));

      uVar4 = uVar4 + 1;

      iVar5 = *(int *)(in_EAX + 0x16b4);

      bVar3 = (byte)iVar5;

      if (uVar7 == 0) {

        uVar7 = (uint)*(ushort *)(param_1 + 2 + uVar8 * 4);

        if ((int)(0x10 - uVar7) < iVar5) {

          uVar1 = *(ushort *)(param_1 + uVar8 * 4);

          *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar3 & 0x1f);

          *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

               *(uint8_t *)(in_EAX + 0x16b0);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

               *(uint8_t *)(in_EAX + 0x16b1);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          iVar5 = *(int *)(in_EAX + 0x16b4) + -0x10 + uVar7;

          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);

        }

        else {

          *(ushort *)(in_EAX + 0x16b0) =

               *(ushort *)(in_EAX + 0x16b0) | *(short *)(param_1 + uVar8 * 4) << (bVar3 & 0x1f);

          iVar5 = iVar5 + uVar7;

        }

LAB_0047f2dc:

        *(int *)(in_EAX + 0x16b4) = iVar5;

      }

      else {

        uVar6 = (uint)(byte)(&DAT_00a278d0)[uVar8];

        uVar10 = (uint)*(ushort *)(param_1 + 0x406 + uVar6 * 4);

        if ((int)(0x10 - uVar10) < iVar5) {

          uVar1 = *(ushort *)(param_1 + 0x404 + uVar6 * 4);

          *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << (bVar3 & 0x1f);

          *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

               *(uint8_t *)(in_EAX + 0x16b0);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

               *(uint8_t *)(in_EAX + 0x16b1);

          iVar5 = *(int *)(in_EAX + 0x16b4);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar10;

          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);

        }

        else {

          *(ushort *)(in_EAX + 0x16b0) =

               *(ushort *)(in_EAX + 0x16b0) |

               *(short *)(param_1 + 0x404 + uVar6 * 4) << (bVar3 & 0x1f);

          *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar10;

        }

        iVar5 = *(int *)(&DAT_00a27088 + uVar6 * 4);

        if (iVar5 != 0) {

          iVar9 = uVar8 - *(int *)(&DAT_00a279d0 + uVar6 * 4);

          iVar2 = *(int *)(in_EAX + 0x16b4);

          if (0x10 - iVar5 < iVar2) {

            *(ushort *)(in_EAX + 0x16b0) =

                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));

            *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

                 *(uint8_t *)(in_EAX + 0x16b0);

            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

            *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

                 *(uint8_t *)(in_EAX + 0x16b1);

            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

            iVar2 = *(int *)(in_EAX + 0x16b4) + -0x10;

            *(ushort *)(in_EAX + 0x16b0) =

                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);

          }

          else {

            *(ushort *)(in_EAX + 0x16b0) =

                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));

          }

          *(int *)(in_EAX + 0x16b4) = iVar2 + iVar5;

        }

        uVar8 = uVar7 - 1;

        if (uVar8 < 0x100) {

          bVar3 = (&DAT_00a276cf)[uVar7];

        }

        else {

          bVar3 = (&DAT_00a277d0)[uVar8 >> 7];

        }

        uVar6 = (uint)bVar3;

        uVar7 = (uint)*(ushort *)(param_2 + 2 + uVar6 * 4);

        iVar5 = *(int *)(in_EAX + 0x16b4);

        if ((int)(0x10 - uVar7) < iVar5) {

          uVar1 = *(ushort *)(param_2 + uVar6 * 4);

          *(ushort *)(in_EAX + 0x16b0) =

               *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar5 & 0x1f);

          *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

               *(uint8_t *)(in_EAX + 0x16b0);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

               *(uint8_t *)(in_EAX + 0x16b1);

          iVar5 = *(int *)(in_EAX + 0x16b4);

          *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

          *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar7;

          *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);

        }

        else {

          *(ushort *)(in_EAX + 0x16b0) =

               *(ushort *)(in_EAX + 0x16b0) |

               *(short *)(param_2 + uVar6 * 4) << ((byte)iVar5 & 0x1f);

          *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar7;

        }

        iVar5 = *(int *)(&DAT_00a27100 + uVar6 * 4);

        if (iVar5 != 0) {

          iVar2 = *(int *)(in_EAX + 0x16b4);

          iVar9 = uVar8 - *(int *)(&DAT_00a27a48 + uVar6 * 4);

          if (0x10 - iVar5 < iVar2) {

            *(ushort *)(in_EAX + 0x16b0) =

                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));

            *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

                 *(uint8_t *)(in_EAX + 0x16b0);

            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

            *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

                 *(uint8_t *)(in_EAX + 0x16b1);

            *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

            iVar5 = *(int *)(in_EAX + 0x16b4) + -0x10 + iVar5;

            *(ushort *)(in_EAX + 0x16b0) =

                 (ushort)iVar9 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);

          }

          else {

            *(ushort *)(in_EAX + 0x16b0) =

                 *(ushort *)(in_EAX + 0x16b0) | (ushort)(iVar9 << ((byte)iVar2 & 0x1f));

            iVar5 = iVar2 + iVar5;

          }

          goto LAB_0047f2dc;

        }

      }

    } while (uVar4 < *(uint *)(in_EAX + 0x1698));

  }

  uVar4 = (uint)*(ushort *)(param_1 + 0x402);

  iVar5 = *(int *)(in_EAX + 0x16b4);

  if (iVar5 <= (int)(0x10 - uVar4)) {

    *(ushort *)(in_EAX + 0x16b0) =

         *(ushort *)(in_EAX + 0x16b0) | *(short *)(param_1 + 0x400) << ((byte)iVar5 & 0x1f);

    *(uint *)(in_EAX + 0x16b4) = iVar5 + uVar4;

    *(uint *)(in_EAX + 0x16ac) = (uint)*(ushort *)(param_1 + 0x402);

    return;

  }

  uVar1 = *(ushort *)(param_1 + 0x400);

  *(ushort *)(in_EAX + 0x16b0) = *(ushort *)(in_EAX + 0x16b0) | uVar1 << ((byte)iVar5 & 0x1f);

  *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = *(uint8_t *)(in_EAX + 0x16b0)

  ;

  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

  *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) = *(uint8_t *)(in_EAX + 0x16b1)

  ;

  iVar5 = *(int *)(in_EAX + 0x16b4);

  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

  *(uint *)(in_EAX + 0x16b4) = iVar5 + -0x10 + uVar4;

  *(ushort *)(in_EAX + 0x16b0) = uVar1 >> (0x10U - (char)iVar5 & 0x1f);

  *(uint *)(in_EAX + 0x16ac) = (uint)*(ushort *)(param_1 + 0x402);

  return;

}
