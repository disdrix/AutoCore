// =============================================================================
// FUN_00646490
// -----------------------------------------------------------------------------
// Stable ID: aa_00646490
// Address:   0x00646490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00646490 @ 0x00646490
// Stable ID: aa_00646490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×11, do×2, while×2, return×1.
//  - Notable callees: FUN_005b3370×6, FUN_00632750, FUN_00646490.
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

void FUN_00646490(int *param_1,int param_2)



{

  ushort uVar1;

  int *unaff_EBX;

  int iVar2;

  int *unaff_ESI;

  int *unaff_EDI;

  uint8_t local_1d;

  int iStack_1c;

  int *piStack_18;

  int local_14;

  int iStack_10;

  int local_c;

  int local_8;

  int local_4;

  

  local_c = 0;

  local_8 = 0;

  local_4 = -0x80000000;

  FUN_00632750(&local_1d,&local_c);

  local_14 = 0;

  if (0 < local_8) {

    do {

      iStack_1c = (**(code **)(*param_1 + 0x20))(*(uint32_t /* width from decompiler */ *)(local_c + local_14 * 4));

      if (*(short *)(iStack_1c + 8) == 0x12) {

        uVar1 = *(ushort *)(iStack_1c + 0xe);

        if (unaff_EDI[1] == (unaff_EDI[2] & 0x7fffffffU)) {

          FUN_005b3370();

        }

        *(uint *)(*unaff_EDI + unaff_EDI[1] * 4) = (uint)uVar1 + param_2;

        unaff_EDI[1] = unaff_EDI[1] + 1;

        if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {

          FUN_005b3370();

        }

        *(int *)(*unaff_ESI + unaff_ESI[1] * 4) = iStack_1c;

        unaff_ESI[1] = unaff_ESI[1] + 1;

        if (unaff_EBX[1] == (unaff_EBX[2] & 0x7fffffffU)) {

          FUN_005b3370();

        }

        *(uint32_t /* width from decompiler */ *)(*unaff_EBX + unaff_EBX[1] * 4) = 0;

        unaff_EBX[1] = unaff_EBX[1] + 1;

      }

      else if (*(short *)(iStack_1c + 8) == 0x13) {

        piStack_18 = (int *)((uint)*(ushort *)(iStack_1c + 0xe) + param_2);

        iVar2 = 0;

        if (0 < piStack_18[1]) {

          do {

            iStack_10 = *piStack_18 + iVar2 * 4;

            if (unaff_EDI[1] == (unaff_EDI[2] & 0x7fffffffU)) {

              FUN_005b3370();

            }

            *(int *)(*unaff_EDI + unaff_EDI[1] * 4) = iStack_10;

            unaff_EDI[1] = unaff_EDI[1] + 1;

            if (unaff_ESI[1] == (unaff_ESI[2] & 0x7fffffffU)) {

              FUN_005b3370();

            }

            *(int *)(*unaff_ESI + unaff_ESI[1] * 4) = iStack_1c;

            unaff_ESI[1] = unaff_ESI[1] + 1;

            if (unaff_EBX[1] == (unaff_EBX[2] & 0x7fffffffU)) {

              FUN_005b3370();

            }

            *(int *)(*unaff_EBX + unaff_EBX[1] * 4) = iVar2;

            unaff_EBX[1] = unaff_EBX[1] + 1;

            iVar2 = iVar2 + 1;

          } while (iVar2 < piStack_18[1]);

        }

      }

      local_14 = local_14 + 1;

    } while (local_14 < local_8);

  }

  if (-1 < local_4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 * 4,0x12);

  }

  return;

}
