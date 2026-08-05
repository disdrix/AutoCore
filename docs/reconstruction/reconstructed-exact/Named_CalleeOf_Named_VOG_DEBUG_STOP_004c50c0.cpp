// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_004c50c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c50c0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x004c50c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_004c50c0, FUN_0074e910, FUN_0074e9d0, FUN_0074ecf0, FUN_0074ed90, FUN_0074ee40, FUN_0079a110, FUN_007b6730.
//  - Return sites: 2.

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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_004c50c0(int *param_1,int *param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  void *pvVar1;

  char cVar2;

  int iVar3;

  float10 fVar4;

  uint8_t *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t *puStack_120;

  uint8_t local_110 [248];

  void *pvStack_18;

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a1bd3;

  pvStack_c = ExceptionList;

  puStack_120 = local_110;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_1 + 0x60))(param_2,param_4);

  puVar5 = &stack0xfffffee4;

  uVar6 = 0xffffffff;

  FUN_007b6a20(puVar5,0xffffffff);

  cVar2 = FUN_007b6730(puVar5,uVar6);

  if (cVar2 != '\0') {

    puStack_120 = operator_new(0x78);

    uStack_10 = 0;

    if (puStack_120 == (uint8_t *)0x0) {

      uVar6 = 0;

    }

    else {

      uVar6 = FUN_0074ed90();

    }

    uStack_10 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_3 + (int)param_2 * 4) = uVar6;

    FUN_00989e00(&puStack_120,&stack0xfffffee4);

    iVar3 = FUN_0074ee40(&puStack_120);

    if (iVar3 < 0) {

      pvVar1 = *(void **)(param_3 + (int)param_2 * 4);

      if (pvVar1 != (void *)0x0) {

        FUN_0074ecf0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(param_3 + (int)param_2 * 4) = 0;

    }

    else {

      fVar4 = (float10)FUN_0079a110();

      FUN_0074e910(0,(float)fVar4);

      *(uint8_t *)(*(int *)(param_3 + (int)param_2 * 4) + 0x4c) = (uint8_t)uStack_4;

      FUN_0074e9d0(0);

      (**(code **)(*param_2 + 0xc))(*(uint32_t /* width from decompiler */ *)(param_3 + (int)param_2 * 4));

      (**(code **)(param_1[0x10] + 0x24))(param_2);

    }

  }

  ExceptionList = pvStack_18;

  return;

}
