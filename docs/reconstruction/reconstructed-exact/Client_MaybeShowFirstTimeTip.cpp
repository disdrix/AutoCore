// READABILITY (auto CF):
//  - Body size: ~100 non-empty decompiler lines.
//  - Control keywords: if×16, return×10.
//  - Notable callees: CDlgFirstTime_ctor, Client_MaybeShowFirstTimeTip, Client_SendUpdateFirstTimeFlags, Client_SetFirstTimeTipBit, FUN_0092f000, UI, bit, id.
//  - Strings: "Controls".
//  - Return sites: 10.

// =============================================================================
// Client_MaybeShowFirstTimeTip
// -----------------------------------------------------------------------------
// Stable ID: aa_00801760
// Address:   0x00801760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* Maybe show first-time tip UI (CDlgFirstTime).

   param_2 = tip id (0..0x31).

   Skips if tip bit already set in char+0xD30 dword[id>>5] bit(id&0x1f).

   If FirstFlags1 signed < 0 (hide-tips bit31), marks bit + SendUpdateFirstTimeFlags without showing

   UI.

   Else creates/shows CDlgFirstTime and queues tip.

   AutoCore persists bits on account.FirstFlags1..4. */



void __thiscall Client_MaybeShowFirstTimeTip(int param_1,uint param_2)



{

  int iVar1;

  char cVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b8073;

  local_c = ExceptionList;

  iVar1 = *(int *)(param_1 + 0xe98);

  if (iVar1 == 0) {

    return;

  }

  if (((byte)param_2 < 0x80) &&

     ((*(uint *)(iVar1 + 0xd30 + ((param_2 & 0xff) >> 5) * 4) & 1 << ((byte)param_2 & 0x1f)) != 0))

  {

    return;

  }

  if (0x31 < (int)param_2) {

    return;

  }

  if ("Controls"[param_2 * 0x1e] == '\0') {

    return;

  }

  if (*(int *)(iVar1 + 0xd30) < 0) {

    ExceptionList = &local_c;

    Client_SetFirstTimeTipBit();

    Client_SendUpdateFirstTimeFlags();

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  if (*(int *)(param_1 + 0x1164) == 0) {

    ExceptionList = &local_c;

    pvVar3 = operator_new(0x5b0);

    local_4 = 0;

    if (pvVar3 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = CDlgFirstTime_ctor(pvVar3);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1164) = uVar4;

  }

  local_4 = 0xffffffff;

  cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x3d8))();

  if ((cVar2 != '\0') && (param_2 != 6)) {

    (**(code **)(**(int **)(param_1 + 0x1164) + 0x46c))(param_2,0);

    ExceptionList = unaff_ESI;

    return;

  }

  if (*(int *)(param_1 + 0xf38) == 0) {

    ExceptionList = local_c;

    return;

  }

  if (*(int **)(param_1 + 0xf40) != (int *)0x0) {

    if (**(int **)(param_1 + 0xf40) == *(int *)(param_1 + 0xf38)) {

      cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x3d8))();

      if (cVar2 == '\0') {

        (**(code **)(**(int **)(param_1 + 0xf38) + 0xa8))(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1164));

        (**(code **)(**(int **)(param_1 + 0x1164) + 0x43c))();

      }

      (**(code **)(**(int **)(param_1 + 0x1164) + 0x460))(0);

      (**(code **)(**(int **)(param_1 + 0x1164) + 0x450))(param_2);

      (**(code **)(**(int **)(param_1 + 0x1164) + 0xfc))(1,0x3f000000);

      if (param_2 == 0) {

        (**(code **)(**(int **)(param_1 + 0x1164) + 0x464))(0);

      }

      else if (param_2 == 6) {

        (**(code **)(**(int **)(param_1 + 0x1164) + 0x464))(0);

      }

      cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x468))();

      if ((cVar2 == '\x01') &&

         (((param_2 == 6 ||

           (cVar2 = (**(code **)(**(int **)(param_1 + 0x1164) + 0x470))(6), cVar2 != '\0')) &&

          ((DAT_00d17920 & 0x80) == 0)))) {

        DAT_00d17920 = DAT_00d17920 | 0x80;

      }

      (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))(1);

      FUN_0092f000();

      ExceptionList = local_c;

      return;

    }

    ExceptionList = local_c;

    return;

  }

  ExceptionList = local_c;

  return;

}
