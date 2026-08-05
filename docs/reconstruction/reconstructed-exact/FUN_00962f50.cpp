// =============================================================================
// FUN_00962f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00962f50
// Address:   0x00962f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00962f50 @ 0x00962f50
// Stable ID: aa_00962f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~136 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: fread×9, FUN_00962f50×4, FUN_0044c1b0×3, FUN_0044c210, FUN_00456960, FUN_0046d4e0.
//  - Return sites: 1.

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

void __thiscall FUN_00962f50(uint32_t /* width from decompiler */ *param_1,FILE *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  FILE *_File;

  uint32_t /* width from decompiler */ uVar3;

  void *_DstBuf;

  uint32_t /* width from decompiler */ *puVar4;

  char local_1d;

  int local_1c;

  uint32_t /* width from decompiler */ *local_18;

  int local_14;

  void *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  _File = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af7ea;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_18 = param_1;

  fread(param_1 + 3,0xc,1,param_2);

  fread(param_1 + 6,0xc,1,_File);

  fread(param_1 + 9,0xc,1,_File);

  fread(param_1 + 0xc,4,1,_File);

  fread(&local_1d,1,1,_File);

  param_1[0xd] = (int)local_1d;

  fread(param_1 + 0xe,4,1,_File);

  fread(&local_1c,4,1,_File);

  FUN_0046d4e0();

  local_14 = 0;

  if (0 < local_1c) {

    do {

      _DstBuf = (void *)FUN_0044c210();

      local_10 = _DstBuf;

      fread(_DstBuf,0x1c,1,_File);

      iVar1 = param_1[0x10];

      if ((iVar1 == 0) || ((uint)(param_1[0x12] - iVar1 >> 2) <= (uint)(param_1[0x11] - iVar1 >> 2))

         ) {

        FUN_00456960(param_1[0x11]);

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x11];

        *puVar4 = _DstBuf;

        param_1[0x11] = puVar4 + 1;

      }

      local_14 = local_14 + 1;

    } while (local_14 < local_1c);

  }

  fread(&param_2,1,1,_File);

  uVar3 = param_3;

  if (((uint)param_2 & 1) != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044c1b0();

    uVar2 = DAT_00aaa630;

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar4 = 0;

      puVar4[1] = 0;

      puVar4[2] = 0;

      puVar4[3] = uVar2;

      puVar4[4] = uVar2;

      puVar4[5] = uVar2;

      uVar2 = DAT_00aaa63c;

      puVar4[6] = DAT_00aaa63c;

      puVar4[7] = uVar2;

      puVar4[8] = uVar2;

      puVar4[0xd] = 0;

      puVar4[0xe] = 0;

      puVar4[0x10] = 0;

      puVar4[0x11] = 0;

      puVar4[0x12] = 0;

    }

    local_4 = 0xffffffff;

    *local_18 = puVar4;

    FUN_00962f50(_File,uVar3);

  }

  if (((uint)param_2 & 2) != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044c1b0();

    uVar2 = DAT_00aaa630;

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar4 = 0;

      puVar4[1] = 0;

      puVar4[2] = 0;

      puVar4[3] = uVar2;

      puVar4[4] = uVar2;

      puVar4[5] = uVar2;

      uVar2 = DAT_00aaa63c;

      puVar4[6] = DAT_00aaa63c;

      puVar4[7] = uVar2;

      puVar4[8] = uVar2;

      puVar4[0xd] = 0;

      puVar4[0xe] = 0;

      puVar4[0x10] = 0;

      puVar4[0x11] = 0;

      puVar4[0x12] = 0;

    }

    local_4 = 0xffffffff;

    local_18[1] = puVar4;

    FUN_00962f50(_File,uVar3);

  }

  if (((uint)param_2 & 4) != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044c1b0();

    uVar2 = DAT_00aaa630;

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      *puVar4 = 0;

      puVar4[1] = 0;

      puVar4[2] = 0;

      puVar4[3] = uVar2;

      puVar4[4] = uVar2;

      puVar4[5] = uVar2;

      uVar2 = DAT_00aaa63c;

      puVar4[6] = DAT_00aaa63c;

      puVar4[7] = uVar2;

      puVar4[8] = uVar2;

      puVar4[0xd] = 0;

      puVar4[0xe] = 0;

      puVar4[0x10] = 0;

      puVar4[0x11] = 0;

      puVar4[0x12] = 0;

    }

    local_4 = 0xffffffff;

    local_18[2] = puVar4;

    FUN_00962f50(_File,uVar3);

  }

  ExceptionList = local_c;

  return;

}
