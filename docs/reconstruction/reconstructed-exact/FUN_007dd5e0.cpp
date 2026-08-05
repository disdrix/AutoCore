// =============================================================================
// FUN_007dd5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007dd5e0
// Address:   0x007dd5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007dd5e0 @ 0x007dd5e0
// Stable ID: aa_007dd5e0
// Embedded strings (evidence for future rename):
//   - "//tContinentExploredAreas/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~169 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, while×2, for×1, do×1.
//  - Notable callees: block×15, FUN_004231d0×4, CONCAT31×2, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, _com_issue_error×2, FUN_004048e0.
//  - Strings: "//tContinentExploredAreas/row".
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

/* WARNING: Removing unreachable block (ram,0x007dd98d) */

/* WARNING: Removing unreachable block (ram,0x007dd91c) */

/* WARNING: Removing unreachable block (ram,0x007dd93a) */

/* WARNING: Removing unreachable block (ram,0x007dd94f) */

/* WARNING: Removing unreachable block (ram,0x007dd955) */

/* WARNING: Removing unreachable block (ram,0x007dd978) */

/* WARNING: Removing unreachable block (ram,0x007dd993) */

/* WARNING: Removing unreachable block (ram,0x007dd9bf) */

/* WARNING: Removing unreachable block (ram,0x007dd9d4) */

/* WARNING: Removing unreachable block (ram,0x007dd9da) */

/* WARNING: Removing unreachable block (ram,0x007dd9f9) */

/* WARNING: Removing unreachable block (ram,0x007dda0e) */

/* WARNING: Removing unreachable block (ram,0x007dda14) */

/* WARNING: Removing unreachable block (ram,0x007dda3b) */

/* WARNING: Removing unreachable block (ram,0x007dda3d) */



uint32_t /* width from decompiler */ __fastcall FUN_007dd5e0(char *param_1)



{

  IUnknown *This;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  ULONG UVar3;

  int *piVar4;

  IUnknown *This_00;

  uint32_t /* width from decompiler */ *puVar5;

  int *piStack_1bc;

  int *local_1b8;

  uint32_t /* width from decompiler */ uStack_1b4;

  int local_1b0;

  int *local_1ac;

  uint8_t *local_1a8;

  IUnknown *local_1a4;

  uint32_t /* width from decompiler */ local_198;

  uint32_t /* width from decompiler */ local_194;

  int *local_190;

  uint32_t /* width from decompiler */ local_18c;

  int local_188;

  uint32_t /* width from decompiler */ local_184;

  uint32_t /* width from decompiler */ *local_180;

  uint32_t /* width from decompiler */ local_17c;

  uint32_t /* width from decompiler */ local_178;

  uint32_t /* width from decompiler */ local_174;

  BSTR local_170;

  BSTR local_16c;

  uint32_t /* width from decompiler */ local_160;

  int local_f0;

  uint32_t /* width from decompiler */ local_ec [27];

  wchar_t local_80 [52];

  void *pvStack_18;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  local_c = 0xffffffff;

  puStack_10 = &LAB_009aede6;

  local_14 = ExceptionList;

  if (DAT_00d1793c == '\0') {

    if (*param_1 == '\0') {

      return 0x80004004;

    }

    local_180 = &local_198;

    local_198 = 0;

    local_194 = 0;

    local_190 = (int *)0x0;

    local_18c = 0;

    local_188 = 0;

    local_184 = 0;

    local_178 = 0;

    local_17c = 0;

    local_174 = 0;

    local_170 = (BSTR)0x0;

    local_c = 0;

    ExceptionList = &local_14;

    iVar1 = FUN_0041a810(local_180,param_1 + 0x28,0);

    local_190 = &local_1b0;

    if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(), iVar1 < 0)) || (iVar1 = FUN_004231d0(), iVar1 < 0)

        ) || (((iVar1 = FUN_004231d0(), iVar1 < 0 || (iVar1 = FUN_004231d0(), iVar1 < 0)) ||

              (local_188 == 0)))) {

      FUN_00423170();

      FUN_007a4480();

      local_c = 0xffffffff;

      FUN_0041a3e0();

    }

    else {

      iVar1 = FUN_0041c000();

      while (iVar1 == 0) {

        local_160._0_1_ = uStack_1b4._3_1_;

        wcscpy((wchar_t *)((int)&local_160 + 2),local_80);

        local_f0 = local_1b0;

        puVar2 = &local_160;

        puVar5 = local_ec;

        for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {

          *puVar5 = *puVar2;

          puVar2 = puVar2 + 1;

          puVar5 = puVar5 + 1;

        }

        FUN_0041bd00();

        iVar1 = FUN_0041c000();

      }

      if (local_188 != 0) {

        FUN_00422de0();

        FUN_0041bf70();

      }

      FUN_00423170();

      local_c = 0xffffffff;

      FUN_0041a3e0();

    }

  }

  else {

    ExceptionList = &local_14;

    local_16c = SysAllocString(L"//tContinentExploredAreas/row");

    if (local_16c == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_1a4 = (IUnknown *)0x0;

    local_1b8 = (int *)0x0;

    local_1a8 = &stack0xfffffe34;

    local_c._0_1_ = 3;

    local_c._1_3_ = 0;

    FUN_00419ca0();

    local_c._0_1_ = 4;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_c = CONCAT31(local_c._1_3_,3);

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00419ed0();

    This = (IUnknown *)*puVar2;

    This_00 = (IUnknown *)0x0;

    if (This != (IUnknown *)0x0) {

      local_1a4 = This;

      (*This->lpVtbl->AddRef)(This);

      This_00 = local_1a4;

    }

    if (local_1ac != (int *)0x0) {

      (**(code **)(*local_1ac + 8))();

    }

    if (This_00 == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_1b0 = 0;

    UVar3 = (*This_00->lpVtbl[2].Release)(This_00);

    if ((int)UVar3 < 0) {

      _com_issue_errorex(UVar3,This_00,(_GUID *)&DAT_00a86118);

    }

    local_1b0 = 0;

    piVar4 = piStack_1bc;

    if (0 < uStack_1b4) {

      do {

        iVar1 = local_1b0;

        if (piStack_1bc != (int *)0x0) {

          (**(code **)(*piStack_1bc + 8))();

        }

        local_1b0 = 0;

        (*This_00->lpVtbl[2].AddRef)(This_00);

        piVar4 = (int *)0x0;

        local_1b0 = iVar1 + 1;

        piStack_1bc = local_1b8;

      } while (local_1b0 < uStack_1b4);

    }

    puStack_10._0_1_ = 2;

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 8))();

    }

    puStack_10 = (uint8_t *)CONCAT31(puStack_10._1_3_,1);

    (*This_00->lpVtbl->Release)(This_00);

    SysFreeString(local_170);

  }

  ExceptionList = pvStack_18;

  return 0;

}
