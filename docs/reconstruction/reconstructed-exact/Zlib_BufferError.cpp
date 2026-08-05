// =============================================================================
// Zlib_BufferError
// -----------------------------------------------------------------------------
// Stable ID: aa_0047a620
// Address:   0x0047a620  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Zlib_BufferError @ 0x0047a620
// Stable ID: aa_0047a620
// Embedded strings (evidence for future rename):
//   - "Unknown zTXt compression type %d"
//   - "Incomplete compressed datastream in %s chunk"
//   - "Data error in compressed datastream in %s chunk"
//   - "Buffer error in compressed datastream in %s chunk"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~244 non-empty decompiler lines.
//  - Control keywords: if×26, for×14, return×8, goto×8, while×1.
//  - Notable callees: FUN_00476cc0×5, FUN_00477710×5, FUN_00476d60×3, FUN_00477740×2, FUN_00478d10×2, free×2, malloc×2, sprintf×2.
//  - Strings: "Unknown zTXt compression type %d"; "Incomplete compressed datastream in %s chunk"; "Data error in compressed datastream in %s chunk"; "Buffer error in compressed datastream in %s chunk".
//  - Return sites: 8.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Buffer error in compressed datastream in %s chunk"
 * Domain alias of FUN_0047a620 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ *

Zlib_BufferError(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint8_t *param_4,uint *param_5)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint8_t *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  char *pcVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ *local_44;

  uint32_t /* width from decompiler */ *local_40;

  char local_34 [52];

  

  if (in_EAX != 0) {

    sprintf(local_34,"Unknown zTXt compression type %d");

    FUN_00476d60();

    *(uint8_t *)((int)param_2 + (int)param_4) = 0;

    *param_5 = (uint)param_4;

    return param_2;

  }

  *(uint8_t **)(param_1 + 0x74) = (uint8_t *)((int)param_2 + (int)param_4);

  puVar5 = (uint8_t *)0x0;

  *(int *)(param_1 + 0x78) = param_3 - (int)param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  local_44 = (uint32_t /* width from decompiler */ *)0x0;

  if (param_3 - (int)param_4 == 0) {

LAB_0047a66e:

    pcVar9 = "Incomplete compressed datastream in %s chunk";

LAB_0047a67f:

    sprintf(local_34,pcVar9,param_1 + 0x11c);

    FUN_00476d60();

    if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

      local_44 = (uint32_t /* width from decompiler */ *)FUN_00477740();

      if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

        FUN_00477710();

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(param_1);

      }

      puVar6 = param_2;

      puVar7 = local_44;

      for (uVar4 = (uint)param_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = (uint)param_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

    }

    *(uint8_t *)((int)local_44 + (int)param_4) = 0;

    puVar5 = param_4;

LAB_0047aa0a:

    FUN_00478d10();

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

    if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

      if (*(code **)(param_1 + 0x24c) != (code *)0x0) {

        (**(code **)(param_1 + 0x24c))(param_1);

        *param_5 = (uint)puVar5;

        return local_44;

      }

      free(param_2);

    }

    *param_5 = (uint)puVar5;

    return local_44;

  }

  while ((iVar2 = FUN_00478f50(param_1 + 0x74,1), iVar2 == 0 || (iVar2 == 1))) {

    iVar1 = *(int *)(param_1 + 0x84);

    if ((iVar1 != 0) && (iVar2 != 1)) goto LAB_0047a8ab;

    if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

      uVar4 = *(uint *)(param_1 + 0x6c);

      puVar5 = param_4 + (*(int *)(param_1 + 0xb0) - iVar1);

      *(uint *)(param_1 + 0x6c) = uVar4 | 0x100000;

      if (puVar5 + 1 == (uint8_t *)0x0) {

        local_44 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        if (*(code **)(param_1 + 0x248) == (code *)0x0) {

          local_44 = malloc((size_t)(puVar5 + 1));

        }

        else {

          local_44 = (uint32_t /* width from decompiler */ *)(**(code **)(param_1 + 0x248))(param_1);

        }

        if ((local_44 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) {

LAB_0047a74f:

                    /* WARNING: Subroutine does not return */

          FUN_00476cc0(param_1);

        }

      }

      *(uint *)(param_1 + 0x6c) = uVar4;

      if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

        FUN_00477710();

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(param_1);

      }

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xac);

      puVar7 = (uint32_t /* width from decompiler */ *)(param_4 + (int)local_44);

      for (uVar4 = (uint)((int)puVar5 - (int)param_4) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = (int)puVar5 - (int)param_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      puVar6 = param_2;

      puVar7 = local_44;

      for (uVar4 = (uint)param_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = (uint)param_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

    }

    else {

      uVar4 = *(uint *)(param_1 + 0x6c);

      *(uint *)(param_1 + 0x6c) = uVar4 | 0x100000;

      if (puVar5 + *(int *)(param_1 + 0xb0) + (1 - iVar1) == (uint8_t *)0x0) {

        local_40 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        if (*(code **)(param_1 + 0x248) == (code *)0x0) {

          local_40 = malloc((size_t)(puVar5 + *(int *)(param_1 + 0xb0) + (1 - iVar1)));

        }

        else {

          local_40 = (uint32_t /* width from decompiler */ *)(**(code **)(param_1 + 0x248))(param_1);

        }

        if ((local_40 == (uint32_t /* width from decompiler */ *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0))

        goto LAB_0047a74f;

      }

      *(uint *)(param_1 + 0x6c) = uVar4;

      if (local_40 == (uint32_t /* width from decompiler */ *)0x0) {

        FUN_00477710();

        FUN_00477710();

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(param_1);

      }

      puVar6 = local_44;

      puVar7 = local_40;

      for (uVar4 = (uint)puVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar4 = (uint)puVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      if (local_44 != (uint32_t /* width from decompiler */ *)0x0) {

        if (*(code **)(param_1 + 0x24c) == (code *)0x0) {

          free(local_44);

        }

        else {

          (**(code **)(param_1 + 0x24c))(param_1);

        }

      }

      uVar3 = *(int *)(param_1 + 0xb0) - *(int *)(param_1 + 0x84);

      puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xac);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)local_40 + (int)puVar5);

      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

      }

      puVar5 = puVar5 + (*(int *)(param_1 + 0xb0) - *(int *)(param_1 + 0x84));

      local_44 = local_40;

    }

    *(uint8_t *)((int)local_44 + (int)puVar5) = 0;

    if (iVar2 == 1) goto LAB_0047aa0a;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xac);

LAB_0047a8ab:

    if (*(int *)(param_1 + 0x78) == 0) goto LAB_0047a8b5;

  }

  FUN_00476d60();

  FUN_00478d10();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = 0;

  if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar5 = param_4 + 0x20;

    local_44 = (uint32_t /* width from decompiler */ *)FUN_00477740();

    if (local_44 == (uint32_t /* width from decompiler */ *)0x0) {

      FUN_00477710();

                    /* WARNING: Subroutine does not return */

      FUN_00476cc0(param_1);

    }

    puVar6 = param_2;

    puVar7 = local_44;

    for (uVar4 = (uint)param_4 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    for (uVar4 = (uint)param_4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar6;

      puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

  }

  *(uint8_t *)((int)local_44 + (int)(puVar5 + -1)) = 0;

  puVar5 = (uint8_t *)((int)param_2 + param_3 + (-1 - (int)local_44));

  if ((uint8_t *)0x1e < puVar5) {

    puVar5 = (uint8_t *)0x1f;

  }

  pcVar9 = s_Error_decoding_compressed_text_00afa948;

  pcVar8 = param_4 + (int)local_44;

  for (uVar4 = (uint)(puVar5 + 1) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

    *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar9;

    pcVar9 = pcVar9 + 4;

    pcVar8 = pcVar8 + 4;

  }

  for (uVar4 = (uint)(puVar5 + 1) & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

    *pcVar8 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    pcVar8 = pcVar8 + 1;

  }

LAB_0047a8b5:

  if (iVar2 == 1) goto LAB_0047aa0a;

  if (iVar2 != -5) {

    if (iVar2 == -3) {

      pcVar9 = "Data error in compressed datastream in %s chunk";

      goto LAB_0047a67f;

    }

    goto LAB_0047a66e;

  }

  pcVar9 = "Buffer error in compressed datastream in %s chunk";

  goto LAB_0047a67f;

}
