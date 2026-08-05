// =============================================================================
// FUN_0047dda0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047dda0
// Address:   0x0047dda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047dda0 @ 0x0047dda0
// Stable ID: aa_0047dda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×9, while×4, do×3, for×1, return×1.
//  - Notable callees: FUN_0047dda0.
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

void __fastcall FUN_0047dda0(int *param_1)



{

  short sVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int in_EAX;

  uint uVar7;

  int iVar8;

  short *psVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  ushort *puVar13;

  int iVar14;

  uint uVar15;

  int local_20;

  int *local_1c;

  int local_18;

  uint local_14;

  int local_10;

  

  iVar2 = param_1[1];

  iVar3 = *param_1;

  piVar4 = (int *)param_1[2];

  iVar11 = piVar4[1];

  iVar8 = piVar4[2];

  iVar5 = *piVar4;

  uVar10 = piVar4[4];

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb34) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb38) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb3c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb40) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb44) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb48) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb4c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xb50) = 0;

  *(uint16_t *)(iVar3 + 2 + *(int *)(in_EAX + 0xb54 + *(int *)(in_EAX + 0x144c) * 4) * 4) = 0;

  iVar14 = *(int *)(in_EAX + 0x144c) + 1;

  local_18 = 0;

  if (iVar14 < 0x23d) {

    local_1c = (int *)(in_EAX + 0xb54 + iVar14 * 4);

    local_10 = 0x23d - iVar14;

    iVar14 = iVar14 + local_10;

    do {

      iVar6 = *local_1c;

      uVar7 = *(ushort *)(iVar3 + 2 + (uint)*(ushort *)(iVar3 + 2 + iVar6 * 4) * 4) + 1;

      if ((int)uVar10 < (int)uVar7) {

        local_18 = local_18 + 1;

        uVar7 = uVar10;

      }

      *(short *)(iVar3 + 2 + iVar6 * 4) = (short)uVar7;

      if (iVar6 <= iVar2) {

        psVar9 = (short *)(in_EAX + 0xb34 + uVar7 * 2);

        *psVar9 = *psVar9 + 1;

        iVar12 = 0;

        if (iVar8 <= iVar6) {

          iVar12 = *(int *)(iVar11 + (iVar6 - iVar8) * 4);

        }

        uVar15 = (uint)*(ushort *)(iVar3 + iVar6 * 4);

        *(int *)(in_EAX + 0x16a0) = *(int *)(in_EAX + 0x16a0) + (uVar7 + iVar12) * uVar15;

        if (iVar5 != 0) {

          *(int *)(in_EAX + 0x16a4) =

               *(int *)(in_EAX + 0x16a4) +

               ((uint)*(ushort *)(iVar5 + 2 + iVar6 * 4) + iVar12) * uVar15;

        }

      }

      local_1c = local_1c + 1;

      local_10 = local_10 + -1;

    } while (local_10 != 0);

    if (local_18 != 0) {

      iVar11 = uVar10 - 1;

      puVar13 = (ushort *)(in_EAX + 0xb34 + uVar10 * 2);

      do {

        psVar9 = (short *)(in_EAX + 0xb34 + iVar11 * 2);

        sVar1 = *(short *)(in_EAX + 0xb34 + iVar11 * 2);

        iVar8 = iVar11;

        while (sVar1 == 0) {

          psVar9 = psVar9 + -1;

          iVar8 = iVar8 + -1;

          sVar1 = *psVar9;

        }

        psVar9 = (short *)(in_EAX + 0xb34 + iVar8 * 2);

        *psVar9 = *psVar9 + -1;

        psVar9 = (short *)(in_EAX + 0xb36 + iVar8 * 2);

        *psVar9 = *psVar9 + 2;

        *puVar13 = *puVar13 - 1;

        local_18 = local_18 + -2;

        local_20 = iVar14;

      } while (0 < local_18);

      for (; uVar10 != 0; uVar10 = uVar10 - 1) {

        uVar7 = (uint)*puVar13;

        if (uVar7 != 0) {

          iVar11 = in_EAX + 0xb54 + iVar14 * 4;

          local_14 = uVar7;

          do {

            iVar8 = *(int *)(iVar11 + -4);

            iVar14 = local_20 + -1;

            iVar11 = iVar11 + -4;

            if (iVar8 <= iVar2) {

              uVar7 = (uint)*(ushort *)(iVar3 + 2 + iVar8 * 4);

              if (uVar7 != uVar10) {

                *(int *)(in_EAX + 0x16a0) =

                     *(int *)(in_EAX + 0x16a0) +

                     (uVar10 - uVar7) * (uint)*(ushort *)(iVar3 + iVar8 * 4);

                *(short *)(iVar3 + 2 + iVar8 * 4) = (short)uVar10;

              }

              uVar7 = local_14 - 1;

              local_14 = uVar7;

            }

            local_20 = iVar14;

          } while (uVar7 != 0);

        }

        puVar13 = puVar13 + -1;

      }

    }

  }

  return;

}
