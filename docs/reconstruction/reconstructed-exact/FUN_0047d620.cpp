// =============================================================================
// FUN_0047d620
// -----------------------------------------------------------------------------
// Stable ID: aa_0047d620
// Address:   0x0047d620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047d620 @ 0x0047d620
// Stable ID: aa_0047d620
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×20, return×6, goto×4, while×3, for×2, do×2.
//  - Notable callees: FUN_00476cc0×4, FUN_00476d60×2, FUN_0046d130, FUN_00478d10, FUN_00478f50, FUN_0047a420, FUN_0047a480, FUN_0047d620.
//  - Return sites: 6.

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

void FUN_0047d620(void)



{

  byte *pbVar1;

  byte bVar2;

  byte bVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint8_t local_5;

  uint32_t /* width from decompiler */ local_4;

  

  *(int *)(in_EAX + 0xe4) = *(int *)(in_EAX + 0xe4) + 1;

  if (*(uint *)(in_EAX + 0xd0) <= *(uint *)(in_EAX + 0xe4)) {

    if (*(char *)(in_EAX + 0x123) != '\0') {

      uVar6 = *(int *)(in_EAX + 0xd8) + 1;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xe4) = 0;

      puVar8 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0xe8);

      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

        *puVar8 = 0;

        puVar8 = puVar8 + 1;

      }

      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint8_t *)puVar8 = 0;

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      do {

        *(char *)(in_EAX + 0x124) = *(char *)(in_EAX + 0x124) + '\x01';

        bVar2 = *(byte *)(in_EAX + 0x124);

        if (6 < bVar2) goto LAB_0047d723;

        uVar6 = (uint)bVar2;

        uVar7 = ((*(int *)(in_EAX + 200) - *(int *)(&DAT_00a26640 + uVar6 * 4)) + -1 +

                *(uint *)(&DAT_00a2665c + uVar6 * 4)) / *(uint *)(&DAT_00a2665c + uVar6 * 4);

        bVar3 = *(byte *)(in_EAX + 0x129);

        *(uint *)(in_EAX + 0xe0) = uVar7;

        if (bVar3 < 8) {

          uVar7 = bVar3 * uVar7 + 7 >> 3;

        }

        else {

          uVar7 = (bVar3 >> 3) * uVar7;

        }

        *(uint *)(in_EAX + 0xdc) = uVar7 + 1;

      } while (((*(byte *)(in_EAX + 0x70) & 2) == 0) &&

              (*(uint *)(in_EAX + 0xd0) =

                    ((*(int *)(in_EAX + 0xcc) - *(int *)(&DAT_00a26678 + uVar6 * 4)) + -1 +

                    *(uint *)(&DAT_00a26694 + uVar6 * 4)) / *(uint *)(&DAT_00a26694 + uVar6 * 4),

              *(int *)(in_EAX + 0xe0) == 0));

      if (bVar2 < 7) {

        return;

      }

    }

LAB_0047d723:

    if ((*(byte *)(in_EAX + 0x6c) & 0x20) == 0) {

      *(uint8_t **)(in_EAX + 0x80) = &local_5;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x84) = 1;

      do {

        if (*(int *)(in_EAX + 0x78) == 0) {

          iVar5 = *(int *)(in_EAX + 0x10c);

          while (iVar5 == 0) {

            FUN_0047a480();

            if (*(code **)(in_EAX + 0x50) == (code *)0x0) {

LAB_0047d8e9:

                    /* WARNING: Subroutine does not return */

              FUN_00476cc0();

            }

            (**(code **)(in_EAX + 0x50))();

            uVar7 = (((local_4 & 0xff) * 0x100 + (local_4 >> 8 & 0xff)) * 0x100 +

                    (local_4._2_2_ & 0xff)) * 0x100 + (uint)(local_4._2_2_ >> 8);

            if (0x7fffffff < uVar7) {

                    /* WARNING: Subroutine does not return */

              FUN_00476cc0();

            }

            *(uint *)(in_EAX + 0x10c) = uVar7;

            *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = 0;

            pbVar1 = (byte *)(in_EAX + 0x11c);

            if (*(code **)(in_EAX + 0x50) == (code *)0x0) goto LAB_0047d8e9;

            (**(code **)(in_EAX + 0x50))();

            if ((*pbVar1 & 0x20) == 0) {

              if ((*(byte *)(in_EAX + 0x6d) & 8) == 0) goto LAB_0047d7f8;

            }

            else if ((*(uint *)(in_EAX + 0x6c) & 0x300) != 0x300) {

LAB_0047d7f8:

              if (pbVar1 == (byte *)0x0) {

                uVar4 = 0;

              }

              else {

                uVar4 = FUN_0046d130();

              }

              *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = uVar4;

            }

            if (*(int *)pbVar1 != DAT_00a265a0) {

                    /* WARNING: Subroutine does not return */

              FUN_00476cc0();

            }

            iVar5 = *(int *)(in_EAX + 0x10c);

          }

          *(uint *)(in_EAX + 0x78) = *(uint *)(in_EAX + 0xb0);

          *(uint32_t /* width from decompiler */ *)(in_EAX + 0x74) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xac);

          if (*(uint *)(in_EAX + 0x10c) < *(uint *)(in_EAX + 0xb0)) {

            *(uint *)(in_EAX + 0x78) = *(uint *)(in_EAX + 0x10c);

          }

          FUN_0047a420();

          *(int *)(in_EAX + 0x10c) = *(int *)(in_EAX + 0x10c) - *(int *)(in_EAX + 0x78);

        }

        iVar5 = FUN_00478f50(in_EAX + 0x74,1);

        if (iVar5 == 1) {

          if (((*(int *)(in_EAX + 0x84) != 0) && (*(int *)(in_EAX + 0x78) == 0)) &&

             (*(int *)(in_EAX + 0x10c) == 0)) goto LAB_0047d895;

          break;

        }

        if (iVar5 != 0) {

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0();

        }

      } while (*(int *)(in_EAX + 0x84) != 0);

      FUN_00476d60();

LAB_0047d895:

      *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 8;

      *(uint *)(in_EAX + 0x6c) = *(uint *)(in_EAX + 0x6c) | 0x20;

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x84) = 0;

    }

    if ((*(int *)(in_EAX + 0x10c) != 0) || (*(int *)(in_EAX + 0x78) != 0)) {

      FUN_00476d60();

    }

    FUN_00478d10();

    *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 8;

  }

  return;

}
