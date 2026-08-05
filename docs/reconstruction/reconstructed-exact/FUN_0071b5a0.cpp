// =============================================================================
// FUN_0071b5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071b5a0
// Address:   0x0071b5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071b5a0 @ 0x0071b5a0
// Stable ID: aa_0071b5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×4, do×3, while×3, for×1, return×1.
//  - Notable callees: FUN_0071b5a0.
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

void FUN_0071b5a0(void)



{

  byte *pbVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint uVar8;

  int local_c;

  uint local_8;

  int local_4;

  

  puVar7 = &DAT_00d11658;

  for (iVar3 = 0x400; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar7 = 0;

    puVar7 = puVar7 + 1;

  }

  local_4 = 0;

  local_c = 0;

  do {

    uVar4 = 0;

    do {

      local_8 = 0;

      uVar6 = 3;

      uVar8 = 2;

      uVar5 = 1;

      do {

        uVar2 = (int)*(char *)(uVar5 + 0xafcd47) - 1;

        if (((int)uVar2 >> 3 == local_4) &&

           ((*(uint *)(&DAT_00afcd68 + (uVar2 & 7) * 4) & uVar4) != 0)) {

          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)local_8 >> 3));

          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(local_8 & 7) * 4];

        }

        if (((int)((int)(char)(&DAT_00afcd48)[uVar5] - 1U) >> 3 == local_4) &&

           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar5] - 1U & 7) * 4) & uVar4) !=

            0)) {

          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar5 >> 3));

          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar5 & 7) * 4];

        }

        if (((int)((int)(char)(&DAT_00afcd48)[uVar8] - 1U) >> 3 == local_4) &&

           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar8] - 1U & 7) * 4) & uVar4) !=

            0)) {

          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar8 >> 3));

          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar8 & 7) * 4];

        }

        if (((int)((int)(char)(&DAT_00afcd48)[uVar6] - 1U) >> 3 == local_4) &&

           ((*(uint *)(&DAT_00afcd68 + ((int)(char)(&DAT_00afcd48)[uVar6] - 1U & 7) * 4) & uVar4) !=

            0)) {

          pbVar1 = (byte *)((int)&DAT_00d11658 + (local_c + uVar4) * 4 + ((int)uVar6 >> 3));

          *pbVar1 = *pbVar1 | (&DAT_00afcd68)[(uVar6 & 7) * 4];

        }

        local_8 = local_8 + 4;

        uVar5 = uVar5 + 4;

        uVar8 = uVar8 + 4;

        uVar6 = uVar6 + 4;

      } while ((int)uVar5 < 0x21);

      uVar4 = uVar4 + 1;

    } while ((int)uVar4 < 0x100);

    local_c = local_c + 0x100;

    local_4 = local_4 + 1;

  } while (local_c < 0x400);

  return;

}
