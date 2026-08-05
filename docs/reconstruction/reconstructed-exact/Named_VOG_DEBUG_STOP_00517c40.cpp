// READABILITY (auto CF):
//  - Body size: ~98 non-empty decompiler lines.
//  - Control keywords: if×10, while×3, do×2, return×2, goto×1.
//  - Notable callees: FUN_00517c40, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00517c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00517c40
// Address:   0x00517c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_VOG_DEBUG_STOP_00517c40(int param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3)



{

  char cVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ **ppuVar8;

  uint *puVar9;

  int local_c;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  puVar9 = (uint *)(param_1 + 0x28);

  local_c = 3;

  do {

    if ((*puVar9 & puVar9[1]) != 0xffffffff) {

      local_8 = (uint32_t /* width from decompiler */ *)param_2[1];

      if (*(char *)((int)local_8[1] + 0x21) == '\0') {

        puVar5 = (uint32_t /* width from decompiler */ *)local_8[1];

        do {

          if (((int)puVar9[1] < (int)puVar5[5]) ||

             (((int)puVar9[1] <= (int)puVar5[5] && (*puVar9 <= (uint)puVar5[4])))) {

            puVar6 = (uint32_t /* width from decompiler */ *)*puVar5;

            local_8 = puVar5;

          }

          else {

            puVar6 = (uint32_t /* width from decompiler */ *)puVar5[2];

          }

          puVar5 = puVar6;

        } while (*(char *)((int)puVar6 + 0x21) == '\0');

      }

      puVar5 = (uint32_t /* width from decompiler */ *)param_2[1];

      if (local_8 == puVar5) {

LAB_00517cb8:

        local_4 = puVar5;

        ppuVar8 = &local_4;

      }

      else {

        if (((int)puVar9[1] < (int)local_8[5]) ||

           (((int)puVar9[1] <= (int)local_8[5] && (*puVar9 < (uint)local_8[4])))) goto LAB_00517cb8;

        ppuVar8 = &local_8;

      }

      puVar6 = *ppuVar8;

      if (puVar6 != puVar5) {

        *puVar9 = puVar6[6];

        puVar9[1] = puVar6[7];

      }

    }

    puVar9 = puVar9 + 2;

    local_c = local_c + -1;

    if (local_c == 0) {

      puVar5 = (uint32_t /* width from decompiler */ *)((uint32_t /* width from decompiler */ *)param_2[1])[1];

      iVar2 = *(int *)(param_1 + 0x164);

      cVar1 = *(char *)((int)puVar5 + 0x21);

      puVar6 = (uint32_t /* width from decompiler */ *)param_2[1];

      while (cVar1 == '\0') {

        if ((iVar2 < (int)puVar5[5]) ||

           ((iVar2 <= (int)puVar5[5] && (*(uint *)(param_1 + 0x160) <= (uint)puVar5[4])))) {

          puVar7 = (uint32_t /* width from decompiler */ *)*puVar5;

        }

        else {

          puVar7 = (uint32_t /* width from decompiler */ *)puVar5[2];

          puVar5 = puVar6;

        }

        puVar6 = puVar5;

        puVar5 = puVar7;

        cVar1 = *(char *)((int)puVar7 + 0x21);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)param_2[1];

      if (((puVar6 == puVar5) || (iVar2 < (int)puVar6[5])) ||

         ((iVar2 <= (int)puVar6[5] && (*(uint *)(param_1 + 0x160) < (uint)puVar6[4])))) {

        local_4 = puVar5;

        ppuVar8 = &local_4;

      }

      else {

        ppuVar8 = &param_2;

      }

      puVar7 = *ppuVar8;

      if (puVar7 == puVar5) {

        param_2 = puVar6;

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        uVar3 = *param_3;

        uVar4 = param_3[1];

        *param_3 = uVar3 + 1;

        param_3[1] = uVar4 + (0xfffffffe < uVar3);

        *(uint *)(param_1 + 0x164) = uVar4;

        *(uint *)(param_1 + 0x160) = uVar3;

        *(uint8_t *)(param_1 + 0x168) = 0;

        return;

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = puVar7[6];

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x164) = puVar7[7];

      return;

    }

  } while( true );

}
