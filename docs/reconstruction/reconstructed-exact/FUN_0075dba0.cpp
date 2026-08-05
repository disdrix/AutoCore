// =============================================================================
// FUN_0075dba0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075dba0
// Address:   0x0075dba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075dba0 @ 0x0075dba0
// Stable ID: aa_0075dba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~143 non-empty decompiler lines.
//  - Control keywords: if×16, return×7, while×1.
//  - Notable callees: FUN_0040d9c0×3, CONCAT31, FUN_0043ba40, FUN_0043c5f0, FUN_0043c6f0, FUN_0043e630, FUN_0043e7f0, FUN_0043e8f0.
//  - Return sites: 7.

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

/* NDResourceCache_LookupOrCreate

   

   Global resource cache keyed by name/type. Returns existing entry when type matches,

   or allocates new 0x3c-byte resource object (FUN_00745d70 / PTR_FUN_00a9e850).

   Used by MSXML document loads and other streamed assets. */



uint32_t /* width from decompiler */ *

NDResourceCache_LookupOrCreate(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int *param_4,int param_5)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *local_64;

  int **ppiStackY_60;

  int *local_48 [4];

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  int iStack_1c;

  uint uStack_18;

  uint uStack_14;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009afe68;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(int *)(param_1 + 0x6c) != 0) {

    ppiStackY_60 = (int **)0x75dbcd;

    ExceptionList = &local_c;

    FUN_00971480();

  }

  ppiStackY_60 = (int **)0x75dbdf;

  FUN_0044e8c0();

  if (local_48[0] == *(int **)(param_1 + 8)) {

    ppiStackY_60 = (int **)0x0;

    local_48[0] = (int *)&local_64;

    local_64 = (uint32_t /* width from decompiler */ *)*param_2;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_0043c6f0();

    local_38 = *puVar3;

    local_34 = puVar3[1];

    local_30 = puVar3[2];

    ppiStackY_60 = local_48;

    local_64 = (uint32_t /* width from decompiler */ *)0x75dc9e;

    FUN_0043ba40();

    local_48[0] = local_48[0] + 3;

  }

  else {

    puVar3 = (uint32_t /* width from decompiler */ *)local_48[0][3];

    local_48[0] = local_48[0] + 3;

    if ((puVar3 != (uint32_t /* width from decompiler */ *)0x0) && (puVar3[3] == param_3)) {

      if (puVar3[5] == 0) {

        if (param_4 == (int *)0x0) {

          ExceptionList = local_c;

          return puVar3;

        }

        if (param_4 != (int *)0x0) {

          ExceptionList = local_c;

          return puVar3;

        }

      }

      else if (param_4 != (int *)0x0) {

        ppiStackY_60 = (int **)0x75dc3e;

        cVar2 = (**(code **)(*param_4 + 8))();

        if (cVar2 != '\0') {

          ExceptionList = local_c;

          return puVar3;

        }

      }

    }

  }

  if (*(int *)(param_1 + 0x6c) != 0) {

    ppiStackY_60 = (int **)param_3;

    local_64 = param_2;

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00970c00();

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      *local_48[0] = (int)puVar3;

      ExceptionList = local_c;

      return puVar3;

    }

    ppiStackY_60 = (int **)0x75dcf0;

    FUN_00970b60();

  }

  iStack_1c = 0;

  uStack_18 = 0;

  uStack_14 = 0;

  iStack_10 = 0;

  uStack_4 = 0;

  ppiStackY_60 = (int **)0x75dd13;

  FUN_0043c5f0();

  uVar5 = uStack_14;

  while( true ) {

    if (uVar5 == iStack_10 + uStack_14) {

      if (param_5 != 1) {

        ppiStackY_60 = (int **)0x75de05;

        puVar3 = operator_new(0x3c);

        uStack_4 = CONCAT31(uStack_4._1_3_,1);

        if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

          puVar3 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          ppiStackY_60 = (int **)param_2;

          local_64 = puVar3;

          FUN_00745d70();

          *puVar3 = &PTR_FUN_00a9e850;

        }

        *local_48[0] = (int)puVar3;

        FUN_0040d9c0();

        ExceptionList = local_c;

        return puVar3;

      }

      FUN_0040d9c0();

      ExceptionList = local_c;

      return (uint32_t /* width from decompiler */ *)0x0;

    }

    uVar4 = uVar5 >> 2;

    iVar1 = uVar4 * -4;

    if (uStack_18 <= uVar4) {

      uVar4 = uVar4 - uStack_18;

    }

    ppiStackY_60 = (int **)param_3;

    local_64 = param_2;

    puVar3 = (uint32_t /* width from decompiler */ *)

             (**(code **)(**(int **)(*(int *)(iStack_1c + uVar4 * 4) + (uVar5 + iVar1) * 4) + 4))();

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) break;

    uVar5 = uVar5 + 1;

  }

  *local_48[0] = (int)puVar3;

  if (*(int *)(param_1 + 0x6c) != 0) {

    ppiStackY_60 = (int **)*param_2;

    local_64 = (uint32_t /* width from decompiler */ *)0x75dd9b;

    FUN_0043e8f0();

    ppiStackY_60 = (int **)0x75ddaa;

    FUN_0043e7f0();

    ppiStackY_60 = (int **)0x75ddb7;

    FUN_0043e630();

  }

  FUN_0040d9c0();

  ExceptionList = local_c;

  return puVar3;

}
