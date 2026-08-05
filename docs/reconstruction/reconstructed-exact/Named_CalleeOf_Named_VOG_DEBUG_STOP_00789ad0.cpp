// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00789ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_00789ad0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x00789ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×13, while×3, goto×3, return×1.
//  - Notable callees: FUN_00423f40×6, FUN_00789430×2, FUN_00427d20, FUN_004294f0, FUN_007894a0, FUN_00789ad0, LeaveCriticalSection.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_VOG_DEBUG_STOP_00789ad0(int param_1,uint *param_2,uint param_3,int param_4)



{

  uint *puVar1;

  uint uVar2;

  uint *puVar3;

  char cVar4;

  int iVar5;

  uint *local_8;

  uint *local_4;

  

  uVar2 = param_3;

  local_4 = (uint *)0x0;

  if ((-2 < (int)param_3) && (param_3 < 0x80000000)) {

    iVar5 = FUN_00423f40(&local_8);

    puVar1 = local_8;

    while (local_8 = puVar1, iVar5 == 0) {

      if (((puVar1 != (uint *)0x0) && ((uint *)*puVar1 == param_2)) && (puVar1[1] == uVar2)) {

        local_4 = puVar1;

        FUN_004294f0();

        iVar5 = FUN_00423f40(&param_2);

        if (iVar5 != 0) goto LAB_00789bd3;

        goto LAB_00789b80;

      }

      iVar5 = FUN_00423f40(&local_8);

      puVar1 = local_8;

    }

  }

  goto LAB_00789be7;

  while (iVar5 = FUN_00423f40(&param_2), iVar5 == 0) {

LAB_00789b80:

    if (((param_2 != (uint *)0x0) && (*param_2 == *puVar1)) && (param_2[1] == puVar1[1])) {

      *param_2 = 0xffffffff;

      param_2[1] = 0xffffffff;

      if (param_2[2] != 0) {

        FUN_00789430();

      }

      puVar1[7] = 0;

      break;

    }

  }

LAB_00789bd3:

  if (*(char *)(param_1 + 0x560) != '\0') {

    *(uint8_t *)(param_1 + 0x560) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x53c));

  }

LAB_00789be7:

  if (((-1 < param_4) && (cVar4 = FUN_00427d20(param_4,&param_2), puVar1 = param_2, cVar4 != '\0'))

     && (param_2 != (uint *)0x0)) {

    if ((*param_2 & param_2[1]) != 0xffffffff) {

      iVar5 = FUN_00423f40(&local_8);

      while (iVar5 == 0) {

        if (((local_8 != (uint *)0x0) && (*local_8 == *puVar1)) && (local_8[1] == puVar1[1])) {

          local_8[7] = 0;

          break;

        }

        iVar5 = FUN_00423f40(&local_8);

      }

    }

    puVar3 = local_4;

    if (local_4 == (uint *)0x0) {

      *puVar1 = 0xffffffff;

      puVar1[1] = 0xffffffff;

      if (puVar1[2] != 0) {

        FUN_00789430();

      }

    }

    else {

      *puVar1 = *local_4;

      puVar1[1] = local_4[1];

      if (puVar1[2] != 0) {

        FUN_007894a0();

      }

      puVar3[7] = (uint)puVar1;

    }

    if (puVar1[2] != 0) {

      (**(code **)(*(int *)puVar1[2] + 0x34c))();

    }

  }

  return;

}
