// =============================================================================
// FUN_00475c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00475c30
// Address:   0x00475c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00475c30 @ 0x00475c30
// Stable ID: aa_00475c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×35, return×5, goto×3, do×1, while×1.
//  - Notable callees: FUN_00476cc0×4, FUN_0047a480×3, FUN_0047cb30×2, FUN_0046d130, FUN_00475c30, FUN_00476c70, FUN_00476d60, FUN_0047aaa0.
//  - Return sites: 5.

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

void __thiscall FUN_00475c30(uint param_1,uint32_t /* width from decompiler */ param_2)



{

  byte *pbVar1;

  uint uVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint16_t uStack_a;

  

  FUN_0047a480();

  do {

    if (*(code **)(in_EAX + 0x50) == (code *)0x0) {

LAB_00475fe0:

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    (**(code **)(in_EAX + 0x50))();

    uStack_a = (ushort)(param_1 >> 0x10);

    uVar5 = (((param_1 & 0xff) * 0x100 + (param_1 >> 8 & 0xff)) * 0x100 + (uStack_a & 0xff)) * 0x100

            + (uint)(uStack_a >> 8);

    if (0x7fffffff < uVar5) {

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0();

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = 0;

    pbVar1 = (byte *)(in_EAX + 0x11c);

    if (*(code **)(in_EAX + 0x50) == (code *)0x0) goto LAB_00475fe0;

    (**(code **)(in_EAX + 0x50))();

    if ((*pbVar1 & 0x20) == 0) {

      if ((*(byte *)(in_EAX + 0x6d) & 8) == 0) goto LAB_00475ccd;

    }

    else if ((*(uint *)(in_EAX + 0x6c) & 0x300) != 0x300) {

LAB_00475ccd:

      if (pbVar1 == (byte *)0x0) {

        uVar3 = 0;

      }

      else {

        uVar3 = FUN_0046d130();

      }

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x110) = uVar3;

    }

    if (*(int *)pbVar1 == DAT_00a26598) {

      FUN_0047aaa0(param_2,uVar5);

    }

    else if (*(int *)pbVar1 == DAT_00a265a8) {

      uVar2 = *(uint *)(in_EAX + 0x68);

      if (((uVar2 & 1) == 0) || ((uVar2 & 4) == 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0();

      }

      *(uint *)(in_EAX + 0x68) = uVar2 | 0x18;

      if (uVar5 != 0) {

        FUN_00476d60();

      }

      FUN_0047a480();

    }

    else {

      iVar4 = FUN_00476c70();

      if (iVar4 == 0) {

        if (*(int *)pbVar1 == DAT_00a265a0) {

          if ((uVar5 != 0) || ((*(byte *)(in_EAX + 0x68) & 8) != 0)) goto LAB_00475d6d;

          FUN_0047a480();

        }

        else if (*(int *)pbVar1 == DAT_00a265b0) {

          FUN_0047abf0(param_2);

        }

        else if (*(int *)pbVar1 == DAT_00a265b8) {

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

          FUN_0047b6f0(param_2,uVar5);

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

          FUN_0047c940(param_2,uVar5);

        }

        else {

          FUN_0047cb30(param_2);

        }

      }

      else {

        if (*(int *)pbVar1 == DAT_00a265a0) {

          if ((uVar5 != 0) || ((*(byte *)(in_EAX + 0x68) & 8) != 0)) {

LAB_00475d6d:

                    /* WARNING: Subroutine does not return */

            FUN_00476cc0();

          }

        }

        else {

          *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 8;

        }

        FUN_0047cb30(param_2);

        if (*(int *)pbVar1 == DAT_00a265b0) {

          *(uint *)(in_EAX + 0x68) = *(uint *)(in_EAX + 0x68) | 2;

        }

      }

    }

    if ((*(byte *)(in_EAX + 0x68) & 0x10) != 0) {

      return;

    }

  } while( true );

}
