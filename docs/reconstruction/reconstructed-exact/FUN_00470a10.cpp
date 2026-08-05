// =============================================================================
// FUN_00470a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00470a10
// Address:   0x00470a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470a10 @ 0x00470a10
// Stable ID: aa_00470a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×10, for×4, return×3, do×3, while×3, goto×1.
//  - Notable callees: malloc×2, FUN_00470a10, FUN_00476cc0, FUN_00476d60, FUN_00477740, free.
//  - Return sites: 3.

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

void FUN_00470a10(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int local_8;

  

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00477740();

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    FUN_00476d60();

    return;

  }

  puVar8 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xd4);

  puVar5 = puVar2;

  for (uVar6 = (uint)(*(int *)(param_2 + 0xd8) << 4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

    *puVar5 = *puVar8;

    puVar8 = puVar8 + 1;

    puVar5 = puVar5 + 1;

  }

  for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

    *(uint8_t *)puVar5 = *(uint8_t *)puVar8;

    puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  if ((param_1 != 0) && (*(void **)(param_2 + 0xd4) != (void *)0x0)) {

    if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

      free(*(void **)(param_2 + 0xd4));

    }

    else {

      (**(code **)(param_1 + 0x24c))(param_1);

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xd4) = 0;

  local_8 = 0;

  if (0 < param_4) {

    do {

      pcVar3 = (char *)*param_3;

      puVar8 = puVar2 + (*(int *)(param_2 + 0xd8) + local_8) * 4;

      pcVar4 = pcVar3 + 1;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      if ((param_1 == 0) || (pcVar3 + (1 - (int)pcVar4) == (char *)0x0)) {

        pcVar4 = (char *)0x0;

      }

      else {

        if (*(code **)(param_1 + 0x248) == (code *)0x0) {

          pcVar4 = malloc((size_t)(pcVar3 + (1 - (int)pcVar4)));

        }

        else {

          pcVar4 = (char *)(**(code **)(param_1 + 0x248))(param_1);

        }

        if ((pcVar4 == (char *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) goto LAB_00470bc7;

      }

      *puVar8 = pcVar4;

      pcVar3 = (char *)*param_3;

      do {

        cVar1 = *pcVar3;

        *pcVar4 = cVar1;

        pcVar3 = pcVar3 + 1;

        pcVar4 = pcVar4 + 1;

      } while (cVar1 != '\0');

      if ((param_1 == 0) || (param_3[3] << 4 == 0)) {

        puVar5 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        if (*(code **)(param_1 + 0x248) == (code *)0x0) {

          puVar5 = malloc(param_3[3] << 4);

        }

        else {

          puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(param_1 + 0x248))(param_1);

        }

        if ((puVar5 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) {

LAB_00470bc7:

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0(param_1);

        }

      }

      puVar8[2] = puVar5;

      puVar9 = (uint32_t /* width from decompiler */ *)param_3[2];

      for (uVar6 = (uint)(param_3[3] << 4) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *puVar5 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar5 = puVar5 + 1;

      }

      for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {

        *(uint8_t *)puVar5 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

      }

      puVar8[3] = param_3[3];

      puVar5 = param_3 + 1;

      local_8 = local_8 + 1;

      param_3 = param_3 + 4;

      *(uint8_t *)(puVar8 + 1) = *(uint8_t *)puVar5;

    } while (local_8 < param_4);

  }

  *(int *)(param_2 + 0xd8) = *(int *)(param_2 + 0xd8) + param_4;

  *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) | 0x20;

  *(uint *)(param_2 + 0xb8) = *(uint *)(param_2 + 0xb8) | 0x20;

  *(uint32_t /* width from decompiler */ **)(param_2 + 0xd4) = puVar2;

  return;

}
