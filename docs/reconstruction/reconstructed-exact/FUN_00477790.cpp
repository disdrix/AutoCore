// =============================================================================
// FUN_00477790
// -----------------------------------------------------------------------------
// Stable ID: aa_00477790
// Address:   0x00477790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00477790 @ 0x00477790
// Stable ID: aa_00477790
// Embedded strings (evidence for future rename):
//   - "insufficient memory"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×13, return×5.
//  - Notable callees: FUN_00477790, FUN_00477ea0, FUN_00477fc0, FUN_0047dc00.
//  - Strings: "insufficient memory".
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

uint32_t /* width from decompiler */ __fastcall

FUN_00477790(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)



{

  uint uVar1;

  char *in_EAX;

  int *piVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  

  iVar3 = 1;

  if (((in_EAX == (char *)0x0) || (*in_EAX != '1')) || (param_7 != 0x38)) {

    return 0xfffffffa;

  }

  if (param_2 != 0) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = 0;

    if (*(int *)(param_2 + 0x20) == 0) {

      *(code **)(param_2 + 0x20) = FUN_0047f700;

      *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = 0;

    }

    if (*(int *)(param_2 + 0x24) == 0) {

      *(code **)(param_2 + 0x24) = FUN_0047f720;

    }

    if (param_3 == -1) {

      param_3 = 6;

    }

    if (param_1 < 0) {

      iVar3 = 0;

      param_1 = -param_1;

    }

    else if (0xf < param_1) {

      iVar3 = 2;

      param_1 = param_1 + -0x10;

    }

    if (((((0 < param_5) && (param_5 < 10)) &&

         ((param_4 == 8 && ((7 < param_1 && (param_1 < 0x10)))))) && (-1 < param_3)) &&

       (((param_3 < 10 && (-1 < param_6)) && (param_6 < 4)))) {

      if (param_1 == 8) {

        param_1 = 9;

      }

      piVar2 = (int *)(**(code **)(param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x28),1,0x16b8);

      if (piVar2 != (int *)0x0) {

        *(int **)(param_2 + 0x1c) = piVar2;

        piVar2[6] = iVar3;

        iVar4 = 1 << ((byte)param_1 & 0x1f);

        piVar2[10] = param_1;

        piVar2[0xb] = iVar4 + -1;

        iVar3 = 1 << ((byte)(param_5 + 7) & 0x1f);

        piVar2[0x12] = param_5 + 7;

        piVar2[0x11] = iVar3;

        piVar2[0x13] = iVar3 + -1;

        *piVar2 = param_2;

        piVar2[9] = iVar4;

        piVar2[0x14] = (param_5 + 9U) / 3;

        iVar3 = (**(code **)(param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x28),iVar4,2);

        piVar2[0xc] = iVar3;

        iVar3 = (**(code **)(param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x28),piVar2[9],2);

        piVar2[0xe] = iVar3;

        iVar3 = (**(code **)(param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x28),piVar2[0x11],2);

        piVar2[0xf] = iVar3;

        iVar3 = 1 << ((char)param_5 + 6U & 0x1f);

        piVar2[0x5a5] = iVar3;

        iVar3 = (**(code **)(param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x28),iVar3,4);

        uVar1 = piVar2[0x5a5];

        piVar2[2] = iVar3;

        piVar2[3] = uVar1 * 4;

        if (((piVar2[0xc] != 0) && (piVar2[0xe] != 0)) && ((piVar2[0xf] != 0 && (iVar3 != 0)))) {

          piVar2[0x5a7] = iVar3 + (uVar1 & 0xfffffffe);

          piVar2[0x5a4] = iVar3 + uVar1 * 3;

          piVar2[0x1f] = param_3;

          piVar2[0x20] = param_6;

          *(uint8_t *)((int)piVar2 + 0x1d) = 8;

          if (((param_2 != 0) && (iVar3 = *(int *)(param_2 + 0x1c), iVar3 != 0)) &&

             ((*(int *)(param_2 + 0x20) != 0 && (*(int *)(param_2 + 0x24) != 0)))) {

            *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = 0;

            *(uint32_t /* width from decompiler */ *)(param_2 + 8) = 0;

            *(uint32_t /* width from decompiler */ *)(param_2 + 0x18) = 0;

            *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = 2;

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14) = 0;

            if (*(int *)(iVar3 + 0x18) < 0) {

              *(int *)(iVar3 + 0x18) = -*(int *)(iVar3 + 0x18);

            }

            *(uint *)(iVar3 + 4) = (-(uint)(*(int *)(iVar3 + 0x18) != 0) & 0xffffffb9) + 0x71;

            *(uint *)(param_2 + 0x30) = (uint)(*(int *)(iVar3 + 0x18) != 2);

            *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = 0;

            FUN_0047dc00(unaff_ESI,unaff_EDI);

            FUN_00477fc0();

            return 0;

          }

          return 0xfffffffe;

        }

        piVar2[1] = 0x29a;

        *(char **)(param_2 + 0x18) = "insufficient memory";

        FUN_00477ea0();

      }

      return 0xfffffffc;

    }

  }

  return 0xfffffffe;

}
