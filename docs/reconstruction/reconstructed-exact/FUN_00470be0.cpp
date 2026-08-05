// =============================================================================
// FUN_00470be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00470be0
// Address:   0x00470be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470be0 @ 0x00470be0
// Stable ID: aa_00470be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00476d60×2, FUN_00477740×2, FUN_00470be0, FUN_00477710, strncpy.
//  - Return sites: 2.

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

void FUN_00470be0(int param_1,int param_2,int param_3,int param_4)



{

  char *_Dest;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int local_8;

  

  if (((param_1 != 0) && (param_2 != 0)) && (param_4 != 0)) {

    puVar1 = (uint32_t /* width from decompiler */ *)FUN_00477740();

    if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

      FUN_00476d60();

      return;

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xbc);

    puVar7 = puVar1;

    for (uVar3 = (uint)(*(int *)(param_2 + 0xc0) * 0x14) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *puVar7 = *puVar2;

      puVar2 = puVar2 + 1;

      puVar7 = puVar7 + 1;

    }

    for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {

      *(uint8_t *)puVar7 = *(uint8_t *)puVar2;

      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

      puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

    }

    FUN_00477710();

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc) = 0;

    local_8 = 0;

    if (0 < param_4) {

      puVar6 = (uint *)(param_3 + 0xc);

      do {

        _Dest = (char *)(puVar1 + (*(int *)(param_2 + 0xc0) + local_8) * 5);

        strncpy(_Dest,(char *)(puVar6 + -3),5);

        puVar2 = (uint32_t /* width from decompiler */ *)FUN_00477740();

        *(uint32_t /* width from decompiler */ **)(_Dest + 8) = puVar2;

        if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

          FUN_00476d60();

        }

        else {

          uVar3 = *puVar6;

          puVar7 = (uint32_t /* width from decompiler */ *)puVar6[-1];

          for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

            *puVar2 = *puVar7;

            puVar7 = puVar7 + 1;

            puVar2 = puVar2 + 1;

          }

          for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

            *(uint8_t *)puVar2 = *(uint8_t *)puVar7;

            puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

            puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

          }

          *(uint *)(_Dest + 0xc) = *puVar6;

          _Dest[0x10] = *(char *)(param_1 + 0x68);

        }

        local_8 = local_8 + 1;

        puVar6 = puVar6 + 5;

      } while (local_8 < param_4);

    }

    *(int *)(param_2 + 0xc0) = *(int *)(param_2 + 0xc0) + param_4;

    *(byte *)(param_2 + 0xb9) = *(byte *)(param_2 + 0xb9) | 2;

    *(uint32_t /* width from decompiler */ **)(param_2 + 0xbc) = puVar1;

  }

  return;

}
