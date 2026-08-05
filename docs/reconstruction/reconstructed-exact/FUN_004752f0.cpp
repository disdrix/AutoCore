// =============================================================================
// FUN_004752f0
// -----------------------------------------------------------------------------
// Stable ID: aa_004752f0
// Address:   0x004752f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004752f0 @ 0x004752f0
// Stable ID: aa_004752f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~172 non-empty decompiler lines.
//  - Control keywords: if×41, return×11, goto×2, while×1.
//  - Notable callees: FUN_00476cc0×9, FUN_00476540×2, FUN_0047cb30×2, FUN_0046d130, FUN_004752f0, FUN_00476c70, FUN_00476d60, FUN_0047a480.
//  - Return sites: 11.

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

void __thiscall FUN_004752f0(uint param_1,int param_2)



{

  byte *pbVar1;

  byte bVar2;

  uint uVar3;

  int in_EAX;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ local_c;

  

  bVar2 = *(byte *)(in_EAX + 300);

  local_c = param_1;

  if (bVar2 < 8) {

    if (*(code **)(in_EAX + 0x50) == (code *)0x0) goto LAB_00475700;

    (**(code **)(in_EAX + 0x50))();

    local_c = param_2 + 0x20;

    *(uint8_t *)(in_EAX + 300) = 8;

    iVar4 = FUN_00476540(local_c);

    if (iVar4 != 0) {

      if ((bVar2 < 4) && (iVar4 = FUN_00476540(local_c), iVar4 != 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0();

      }

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    if (bVar2 < 3) {

      *(byte *)(in_EAX + 0x69) = *(byte *)(in_EAX + 0x69) | 0x10;

    }

  }

  iVar4 = *(int *)(in_EAX + 0x50);

  while (iVar4 != 0) {

    (**(code **)(in_EAX + 0x50))();

    uVar6 = (((local_c & 0xff) * 0x100 + (local_c >> 8 & 0xff)) * 0x100 + (local_c._2_2_ & 0xff)) *

            0x100 + (uint)(local_c._2_2_ >> 8);

    if (0x7fffffff < uVar6) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = 0;

    pbVar1 = (byte *)(in_EAX + 0x11c);

    if (*(code **)(in_EAX + 0x50) == (code *)0x0) break;

    (**(code **)(in_EAX + 0x50))();

    if ((*pbVar1 & 0x20) == 0) {

      if ((*(byte *)(in_EAX + 0x6d) & 8) == 0) goto LAB_00475412;

    }

    else if ((*(uint *)(in_EAX + 0x6c) & 0x300) != 0x300) {

LAB_00475412:

      if (pbVar1 == (byte *)0x0) {

        uVar5 = 0;

      }

      else {

        uVar5 = FUN_0046d130();

      }

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = uVar5;

    }

    if (*(int *)pbVar1 == DAT_00a26598) {

      FUN_0047aaa0(param_2,uVar6);

    }

    else if (*(int *)pbVar1 == DAT_00a265a8) {

      uVar3 = *(uint *)(in_EAX + 0x68);

      if (((uVar3 & 1) == 0) || ((uVar3 & 4) == 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0();

      }

      *(uint *)(in_EAX + 0x68) = uVar3 | 0x18;

      if (uVar6 != 0) {

        FUN_00476d60();

      }

      FUN_0047a480();

    }

    else {

      iVar4 = FUN_00476c70();

      if (iVar4 == 0) {

        if (*(int *)pbVar1 == DAT_00a265b0) {

          FUN_0047abf0(param_2);

        }

        else {

          if (*(int *)pbVar1 == DAT_00a265a0) {

            uVar3 = *(uint *)(in_EAX + 0x68);

            if ((uVar3 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

              FUN_00476cc0();

            }

            if ((*(char *)(in_EAX + 0x126) == '\x03') && ((uVar3 & 2) == 0)) {

                    /* WARNING: Subroutine does not return */

              FUN_00476cc0();

            }

            *(uint *)(in_EAX + 0x10c) = uVar6;

            *(uint *)(in_EAX + 0x68) = uVar3 | 4;

            return;

          }

          if (*(int *)pbVar1 == DAT_00a265b8) {

            FUN_0047bd50(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265c0) {

            FUN_0047b060(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265c8) {

            FUN_0047ad80(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265d0) {

            FUN_0047bf30(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265e8) {

            FUN_0047c140(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265f0) {

            FUN_0047c230(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265f8) {

            FUN_0047c520(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26600) {

            FUN_0047c050(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26608) {

            FUN_0047af00(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26618) {

            FUN_0047b510(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a265d8) {

            FUN_0047b6f0(param_2,uVar6);

          }

          else if (*(int *)pbVar1 == DAT_00a26610) {

            FUN_0047b8c0(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26620) {

            FUN_0047c7b0(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26628) {

            FUN_0047c6b0(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26630) {

            FUN_0047bb70(param_2);

          }

          else if (*(int *)pbVar1 == DAT_00a26638) {

            FUN_0047c940(param_2,uVar6);

          }

          else {

            FUN_0047cb30(param_2);

          }

        }

      }

      else {

        if (*(int *)pbVar1 == DAT_00a265a0) {

          *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 4;

        }

        FUN_0047cb30(param_2);

        if (*(int *)pbVar1 == DAT_00a265b0) {

          *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 2;

        }

        else if (*(int *)pbVar1 == DAT_00a265a0) {

          if ((*(uint *)(in_EAX + 0x68) & 1) == 0) {

                    /* WARNING: Subroutine does not return */

            FUN_00476cc0();

          }

          if ((*(char *)(in_EAX + 0x126) == '\x03') && ((*(uint *)(in_EAX + 0x68) & 2) == 0)) {

                    /* WARNING: Subroutine does not return */

            FUN_00476cc0();

          }

          return;

        }

      }

    }

    iVar4 = *(int *)(in_EAX + 0x50);

  }

LAB_00475700:

                    /* WARNING: Subroutine does not return */

  FUN_00476cc0();

}
