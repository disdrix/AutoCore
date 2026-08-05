// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: wcscpy×2, FUN_00404b30, FUN_00541bb0, FUN_005438c0, FUN_00545690, FUN_005ea260, FUN_007a4480, FUN_007bcb40.
//  - Strings: "Blah blah fill this out"; "VOG_DEBUG_STOP".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00541bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00541bb0
// Address:   0x00541bb0  (autoassault.exe, image base 0x400000)
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

void * Named_VOG_DEBUG_STOP_00541bb0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  byte bVar6;

  void *pvVar7;

  void *pvStack_274;

  int iStack_270;

  int local_26c;

  uint32_t /* width from decompiler */ uStack_268;

  wchar_t *local_264;

  wchar_t local_260 [128];

  uint8_t auStack_160 [4];

  uint32_t /* width from decompiler */ local_15c;

  uint8_t local_158;

  wchar_t awStack_156 [33];

  uint8_t uStack_114;

  wchar_t awStack_112 [129];

  uint32_t /* width from decompiler */ uStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a4011;

  pvStack_c = ExceptionList;

  local_264 = local_260;

  local_15c = param_2;

  local_158 = (uint8_t)param_3;

  ExceptionList = &pvStack_c;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00404b30(param_1,uVar3);

  wcscpy(awStack_156,local_264);

  if (local_264 != local_260) {

    free(local_264);

  }

  uStack_114 = 1;

  uStack_10 = 0xffffffff;

  wcscpy(awStack_112,L"Blah blah fill this out");

  iVar4 = FUN_007bcb40(auStack_160,&uStack_268);

  pvVar7 = (void *)0x0;

  if (iVar4 < 0) {

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    pvVar7 = (void *)0x0;

  }

  else {

    pvStack_274 = operator_new(0x60);

    uStack_4 = 0;

    if (pvStack_274 != (void *)0x0) {

      pvVar7 = (void *)FUN_005ea260(uStack_268,param_3,param_1,param_2);

    }

    uStack_4 = 0xffffffff;

    pvStack_274 = pvVar7;

    FUN_00545690(*(uint32_t /* width from decompiler */ *)((int)pvVar7 + 0x1c),pvVar7,0);

    bVar6 = 1;

    iVar4 = 7;

    iStack_270 = 0x21;

    do {

      if (((*(byte *)((int)pvVar7 + 0x14) & 1) != 0) ||

         ((*(uint *)((int)pvVar7 + 0x14) & 1 << (bVar6 & 0x1f)) != 0)) {

        iVar5 = (*(int *)((int)pvVar7 + 0x18) + 1 + iVar4) * 0x10 + local_26c;

        iVar1 = *(int *)(iVar5 + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(iVar5 + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(iVar5 + 8) - iVar1 >> 2)))

        {

          FUN_005438c0(*(uint32_t /* width from decompiler */ *)(iVar5 + 8),1,&pvStack_274);

        }

        else {

          piVar2 = *(int **)(iVar5 + 8);

          *piVar2 = (int)pvVar7;

          *(int **)(iVar5 + 8) = piVar2 + 1;

        }

      }

      bVar6 = bVar6 + 1;

      iVar4 = iVar4 + 7;

      iStack_270 = iStack_270 + -1;

    } while (iStack_270 != 0);

  }

  ExceptionList = pvStack_c;

  return pvVar7;

}
