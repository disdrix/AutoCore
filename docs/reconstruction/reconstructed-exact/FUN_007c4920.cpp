// =============================================================================
// FUN_007c4920
// -----------------------------------------------------------------------------
// Stable ID: aa_007c4920
// Address:   0x007c4920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007c4920 @ 0x007c4920
// Stable ID: aa_007c4920
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "//tItemTemplate/row"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~238 non-empty decompiler lines.
//  - Control keywords: if×14, return×4, while×3, do×2.
//  - Notable callees: block×52, FUN_004231d0×17, _com_issue_error×3, FUN_0041a3e0×2, FUN_0041c000×2, FUN_00423170×2, CONCAT31, FUN_004048e0.
//  - Strings: "DBReader: %u against %s"; "//tItemTemplate/row".
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x007c4eee) */

/* WARNING: Removing unreachable block (ram,0x007c4f11) */

/* WARNING: Removing unreachable block (ram,0x007c4f26) */

/* WARNING: Removing unreachable block (ram,0x007c4f2c) */

/* WARNING: Removing unreachable block (ram,0x007c4f4d) */

/* WARNING: Removing unreachable block (ram,0x007c4f62) */

/* WARNING: Removing unreachable block (ram,0x007c4f68) */

/* WARNING: Removing unreachable block (ram,0x007c4f8d) */

/* WARNING: Removing unreachable block (ram,0x007c4fa2) */

/* WARNING: Removing unreachable block (ram,0x007c4fa8) */

/* WARNING: Removing unreachable block (ram,0x007c4fcf) */

/* WARNING: Removing unreachable block (ram,0x007c4fe4) */

/* WARNING: Removing unreachable block (ram,0x007c4fea) */

/* WARNING: Removing unreachable block (ram,0x007c500f) */

/* WARNING: Removing unreachable block (ram,0x007c5024) */

/* WARNING: Removing unreachable block (ram,0x007c502a) */

/* WARNING: Removing unreachable block (ram,0x007c504f) */

/* WARNING: Removing unreachable block (ram,0x007c5064) */

/* WARNING: Removing unreachable block (ram,0x007c506a) */

/* WARNING: Removing unreachable block (ram,0x007c508f) */

/* WARNING: Removing unreachable block (ram,0x007c50a4) */

/* WARNING: Removing unreachable block (ram,0x007c50aa) */

/* WARNING: Removing unreachable block (ram,0x007c50cf) */

/* WARNING: Removing unreachable block (ram,0x007c50e4) */

/* WARNING: Removing unreachable block (ram,0x007c50ea) */

/* WARNING: Removing unreachable block (ram,0x007c510f) */

/* WARNING: Removing unreachable block (ram,0x007c5124) */

/* WARNING: Removing unreachable block (ram,0x007c512a) */

/* WARNING: Removing unreachable block (ram,0x007c514f) */

/* WARNING: Removing unreachable block (ram,0x007c5164) */

/* WARNING: Removing unreachable block (ram,0x007c516a) */

/* WARNING: Removing unreachable block (ram,0x007c518f) */

/* WARNING: Removing unreachable block (ram,0x007c51a4) */

/* WARNING: Removing unreachable block (ram,0x007c51aa) */

/* WARNING: Removing unreachable block (ram,0x007c51cf) */

/* WARNING: Removing unreachable block (ram,0x007c51e4) */

/* WARNING: Removing unreachable block (ram,0x007c51ea) */

/* WARNING: Removing unreachable block (ram,0x007c520f) */

/* WARNING: Removing unreachable block (ram,0x007c5224) */

/* WARNING: Removing unreachable block (ram,0x007c522a) */

/* WARNING: Removing unreachable block (ram,0x007c524f) */

/* WARNING: Removing unreachable block (ram,0x007c5264) */

/* WARNING: Removing unreachable block (ram,0x007c526a) */

/* WARNING: Removing unreachable block (ram,0x007c528f) */

/* WARNING: Removing unreachable block (ram,0x007c52a4) */

/* WARNING: Removing unreachable block (ram,0x007c52aa) */

/* WARNING: Removing unreachable block (ram,0x007c52cf) */

/* WARNING: Removing unreachable block (ram,0x007c52e4) */

/* WARNING: Removing unreachable block (ram,0x007c52ea) */

/* WARNING: Removing unreachable block (ram,0x007c5314) */

/* WARNING: Removing unreachable block (ram,0x007c5329) */

/* WARNING: Removing unreachable block (ram,0x007c532f) */



uint32_t /* width from decompiler */ __fastcall FUN_007c4920(char *param_1)



{

  char cVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  ULONG UVar6;

  char *pcVar7;

  int *local_110;

  IUnknown *local_10c;

  uint32_t /* width from decompiler */ local_108;

  int *local_104;

  uint32_t /* width from decompiler */ *local_100;

  uint32_t /* width from decompiler */ local_fc;

  int local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ *local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint8_t *local_dc;

  uint32_t /* width from decompiler */ local_d8;

  int local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  uint32_t /* width from decompiler */ local_c8;

  uint32_t /* width from decompiler */ local_c4;

  int local_c0;

  uint32_t /* width from decompiler */ local_bc;

  uint32_t /* width from decompiler */ local_b8;

  uint32_t /* width from decompiler */ local_b4;

  BSTR local_b0;

  uint32_t /* width from decompiler */ local_ac;

  BSTR local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  char local_8c [128];

  void *local_c;

  uint8_t *puStack_8;

  void *local_4;

  

  local_4 = (void *)0xffffffff;

  puStack_8 = &LAB_009ae320;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    ExceptionList = (void *)0xffffffff;

    return 0x80004004;

  }

  if (DAT_00d1793c == '\0') {

    local_f0 = &local_108;

    local_108 = 0;

    local_104 = (int *)0x0;

    local_100 = (uint32_t /* width from decompiler */ *)0x0;

    local_fc = 0;

    local_f8 = 0;

    local_f4 = 0;

    local_e8 = 0;

    local_ec = 0;

    local_e4 = 0;

    local_e0 = 0;

    local_4 = (void *)0x0;

    ExceptionList = &local_c;

    iVar4 = FUN_0041a810(local_f0,param_1 + 0x28,0,0,&DAT_00a140c8,0);

    local_100 = &local_d8;

    if (((((((-1 < iVar4) && (iVar4 = FUN_004231d0(&local_108,1), -1 < iVar4)) &&

           (iVar4 = FUN_004231d0(&local_108,2), -1 < iVar4)) &&

          ((iVar4 = FUN_004231d0(&local_108,3), -1 < iVar4 &&

           (iVar4 = FUN_004231d0(&local_108,4), -1 < iVar4)))) &&

         ((iVar4 = FUN_004231d0(&local_108,5), -1 < iVar4 &&

          ((iVar4 = FUN_004231d0(&local_108,6), -1 < iVar4 &&

           (iVar4 = FUN_004231d0(&local_108,7), -1 < iVar4)))))) &&

        (iVar4 = FUN_004231d0(&local_108,8), -1 < iVar4)) &&

       (((((iVar4 = FUN_004231d0(&local_108,9), -1 < iVar4 &&

           (iVar4 = FUN_004231d0(&local_108,10), -1 < iVar4)) &&

          (iVar4 = FUN_004231d0(&local_108,0xb), -1 < iVar4)) &&

         (((iVar4 = FUN_004231d0(&local_108,0xc), -1 < iVar4 &&

           (iVar4 = FUN_004231d0(&local_108,0xd), -1 < iVar4)) &&

          ((iVar4 = FUN_004231d0(&local_108,0xe), -1 < iVar4 &&

           ((iVar4 = FUN_004231d0(&local_108,0xf), -1 < iVar4 &&

            (iVar4 = FUN_004231d0(&local_108,0x10), -1 < iVar4)))))))) &&

        (iVar4 = FUN_004231d0(&local_108,0x11), -1 < iVar4)))) {

      if (local_f8 != 0) {

        iVar4 = FUN_0041c000(0);

        while (iVar4 == 0) {

          puVar5 = operator_new(0xc0);

          *puVar5 = local_d8;

          pcVar7 = local_8c;

          iVar4 = 4 - (int)pcVar7;

          do {

            cVar1 = *pcVar7;

            pcVar7[(int)puVar5 + iVar4] = cVar1;

            pcVar7 = pcVar7 + 1;

          } while (cVar1 != '\0');

          puVar5[0x21] = local_bc;

          puVar5[0x22] = local_a8;

          puVar5[0x23] = local_94;

          puVar5[0x24] = local_cc;

          puVar5[0x25] = local_ac;

          puVar5[0x26] = local_c4;

          puVar5[0x27] = local_98;

          puVar5[0x28] = local_d4;

          puVar5[0x29] = local_a4;

          puVar5[0x2a] = local_b4;

          puVar5[0x2b] = local_90;

          puVar5[0x2c] = local_d0;

          puVar5[0x2d] = local_c8;

          puVar5[0x2e] = (uint)(local_c0 == -1);

          puVar5[0x2f] = local_b8;

          FUN_0041b360();

          iVar4 = FUN_0041c000(0);

        }

        if (local_f8 != 0) {

          FUN_00422de0();

          FUN_0041bf70();

        }

        FUN_00423170();

        local_4 = (void *)0xffffffff;

        FUN_0041a3e0();

        ExceptionList = local_4;

        return 0;

      }

      iVar4 = -0x7fffbffb;

    }

    FUN_00423170();

    FUN_007a4480(1,"DBReader: %u against %s",iVar4);

    local_4 = (void *)0xffffffff;

    FUN_0041a3e0();

  }

  else {

    ExceptionList = &local_c;

    local_b0 = SysAllocString(L"//tItemTemplate/row");

    if (local_b0 == (BSTR)0x0) {

                    /* WARNING: Subroutine does not return */

      FUN_004048e0();

    }

    local_dc = &stack0xfffffed4;

    local_4 = (void *)0x1;

    FUN_00419ca0(&stack0xfffffed4);

    local_4._0_1_ = 2;

    if (DAT_00d1e56c == 0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_4._0_1_ = 1;

    FUN_00419ed0(&local_10c);

    local_4 = (void *)CONCAT31(local_4._1_3_,4);

    if (local_10c == (IUnknown *)0x0) {

      _com_issue_error(-0x7fffbffd);

    }

    local_dc = (uint8_t *)0x0;

    UVar6 = (*local_10c->lpVtbl[2].Release)(local_10c);

    if ((int)UVar6 < 0) {

      _com_issue_errorex(UVar6,local_10c,(_GUID *)&DAT_00a86118);

    }

    iVar4 = 0;

    piVar3 = local_110;

    if (0 < local_d4) {

      do {

        local_110 = piVar3;

        if (local_104 == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        piVar2 = local_104;

        if (local_110 != (int *)0x0) {

          (**(code **)(*local_110 + 8))();

        }

        local_110 = (int *)0x0;

        piVar3 = local_110;

        (**(code **)(*piVar2 + 0x1c))();

        local_110 = (int *)0x0;

        iVar4 = iVar4 + 1;

      } while (iVar4 < local_d4);

    }

    if (local_110 != (int *)0x0) {

      (**(code **)(*local_110 + 8))();

    }

    if (local_104 != (int *)0x0) {

      (**(code **)(*local_104 + 8))();

    }

    SysFreeString(local_a8);

  }

  ExceptionList = local_4;

  return 0;

}
