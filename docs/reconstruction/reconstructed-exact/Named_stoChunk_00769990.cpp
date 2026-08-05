// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×16, return×4, goto×4, while×3, do×1.
//  - Notable callees: FUN_00435f30, FUN_00767d40, FUN_00767fd0, FUN_00768260, FUN_007684e0, FUN_00768760, FUN_007689e0, FUN_00768c60.
//  - Strings: "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp"; "Unhandled block data type".
//  - Return sites: 4.

// =============================================================================
// Named_stoChunk_00769990
// -----------------------------------------------------------------------------
// Stable ID: aa_00769990
// Address:   0x00769990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "stoChunk"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_stoChunk_00769990(int param_1,uint *param_2,int param_3)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  uint *puVar3;

  

  if (*(int *)(param_1 + 0x4044) == 0) {

    iVar2 = 0;

    uVar1 = *param_2;

    while (uVar1 != 0) {

      param_2 = param_2 + 1;

      iVar2 = iVar2 + (uVar1 & 0xff);

      uVar1 = *param_2;

    }

    uVar1 = FUN_00435f30(in_EAX,iVar2 * param_3);

    *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

    return *(uint32_t /* width from decompiler */ *)(param_1 + 0x402c);

  }

  if ((*(int *)(param_1 + 0x4044) != 1) || (param_3 == 0)) {

    return 0xffffffff;

  }

  do {

    param_3 = param_3 + -1;

    uVar1 = *param_2;

    puVar3 = param_2;

    while (uVar1 != 0) {

      uVar1 = *puVar3;

      if ((int)uVar1 < 0x609) {

        if (uVar1 == 0x608) {

          uVar1 = FUN_007684e0(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 8;

        }

        else if ((int)uVar1 < 0x303) {

          if (uVar1 == 0x302) {

            uVar1 = FUN_00768c60(in_EAX);

            *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

            in_EAX = in_EAX + 2;

          }

          else {

            if (uVar1 == 0x101) {

              uVar1 = FUN_007693e0(in_EAX);

              goto LAB_00769ad9;

            }

            if (uVar1 != 0x202) goto LAB_00769b03;

            uVar1 = FUN_00768ee0(in_EAX);

            *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

            in_EAX = in_EAX + 2;

          }

        }

        else if (uVar1 == 0x404) {

          uVar1 = FUN_007689e0(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 4;

        }

        else {

          if (uVar1 != 0x504) goto LAB_00769b03;

          uVar1 = FUN_00768760(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 4;

        }

      }

      else if ((int)uVar1 < 0x909) {

        if (uVar1 == 0x908) {

          uVar1 = FUN_00767d40(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 8;

        }

        else if (uVar1 == 0x708) {

          uVar1 = FUN_00768260(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 8;

        }

        else {

          if (uVar1 != 0x804) goto LAB_00769b03;

          uVar1 = FUN_00767fd0(in_EAX);

          *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

          in_EAX = in_EAX + 4;

        }

      }

      else {

        if (uVar1 != 0xa01) {

LAB_00769b03:

          vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoChunk.cpp",0x316,3,

                         "Unhandled block data type");

          return 0xffffffff;

        }

        uVar1 = FUN_00769160(in_EAX);

LAB_00769ad9:

        *(uint *)(param_1 + 0x402c) = *(uint *)(param_1 + 0x402c) | uVar1;

        in_EAX = in_EAX + 1;

      }

      puVar3 = puVar3 + 1;

      uVar1 = *puVar3;

    }

    if (param_3 == 0) {

      return 0xffffffff;

    }

  } while( true );

}
