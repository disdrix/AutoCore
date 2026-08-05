// =============================================================================
// Named_u_u_umax
// -----------------------------------------------------------------------------
// Stable ID: aa_00785e40
// Address:   0x00785e40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_u_u_umax @ 0x00785e40
// Stable ID: aa_00785e40
// Embedded strings (evidence for future rename):
//   - "%s%s (%u/%u=%u) (%umax)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, do×3, while×3, return×1.
//  - Notable callees: Named_u_u_umax×2, s, sprintf.
//  - Strings: "%s%s (%u/%u=%u) (%umax)\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "%s%s (%u/%u=%u) (%umax)
"
 * Domain alias of FUN_00785e40 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_u_u_umax(int param_1,uint *param_2,uint32_t /* width from decompiler */ *param_3)



{

  char cVar1;

  uint uVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ local_218 [66];

  char local_110 [268];

  

  if (param_3[0xe] != 0) {

    uVar2 = 0;

    if (0 < (int)*param_2) {

      uVar2 = *param_2;

      puVar7 = local_218;

      for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = 0x2b2b2b2b;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = 0x2b;

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

    }

    uVar4 = param_3[0x11];

    *(uint8_t *)((int)local_218 + uVar2) = 0;

    uVar2 = uVar4;

    if ((int)uVar4 < 1) {

      uVar2 = 1;

    }

    sprintf(local_110,"%s%s (%u/%u=%u) (%umax)\n",local_218,*param_3,param_3[0xc],uVar4,

            (uint)param_3[0xc] / uVar2,param_3[0xe]);

    pcVar3 = local_110;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    uVar2 = (int)pcVar3 - (int)local_110;

    pcVar3 = (char *)(param_1 + -1);

    do {

      pcVar5 = pcVar3 + 1;

      pcVar3 = pcVar3 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = local_110;

    for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar3 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar3 = pcVar3 + 4;

    }

    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *pcVar3 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar3 = pcVar3 + 1;

    }

    *param_2 = *param_2 + 1;

    if (((param_3[4] != 0) && (iVar8 = (int)(param_3[5] - param_3[4]) >> 2, 0 < iVar8)) &&

       (iVar6 = 0, 0 < iVar8)) {

      do {

        Named_u_u_umax(param_1,param_2,*(uint32_t /* width from decompiler */ *)(param_3[4] + iVar6 * 4));

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar8);

    }

    *param_2 = *param_2 - 1;

  }

  return;

}
