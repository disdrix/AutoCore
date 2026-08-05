// =============================================================================
// FUN_007475c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007475c0
// Address:   0x007475c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007475c0 @ 0x007475c0
// Stable ID: aa_007475c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×9, do×2, while×2, return×2.
//  - Notable callees: FUN_00445fa0×4, FUN_0045f220×4, FUN_004454f0, FUN_00747390, FUN_007475c0.
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

uint32_t /* width from decompiler */ FUN_007475c0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ local_38;

  uint8_t local_34;

  uint8_t local_33;

  uint8_t local_32;

  uint8_t local_31;

  void *local_2c;

  int local_28;

  int local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ local_c;

  

  puStack_10 = &LAB_009afb68;

  local_14 = ExceptionList;

  if (0 < param_2) {

    local_2c = (void *)0x0;

    local_28 = 0;

    local_24 = 0;

    local_20 = 0;

    local_1c = 0;

    iVar2 = 0;

    local_c = 0;

    ExceptionList = &local_14;

    if (0 < param_2) {

      local_38 = 0;

      local_34 = 2;

      local_33 = 0;

      local_32 = 0;

      local_31 = 0;

      ExceptionList = &local_14;

      do {

        FUN_004454f0();

        cVar1 = (char)iVar2;

        iVar2 = iVar2 + 1;

        *(char *)(local_28 + -1) = cVar1 + '\x01';

      } while (iVar2 < param_2);

    }

    iVar2 = 0;

    pvVar4 = local_2c;

    if (0 < param_2) {

      local_38 = 0;

      local_34 = 2;

      local_33 = 0;

      local_32 = 3;

      local_31 = 0;

      do {

        iVar3 = local_28;

        if ((pvVar4 == (void *)0x0) ||

           ((uint)(local_24 - (int)pvVar4 >> 3) <= (uint)(local_28 - (int)pvVar4 >> 3))) {

          FUN_00445fa0(local_28,&local_38);

          pvVar4 = local_2c;

        }

        else {

          FUN_0045f220(local_38);

          local_28 = iVar3 + 8;

        }

        *(char *)(local_28 + -1) = (char)iVar2 + '\x01';

        iVar2 = iVar2 + 1;

      } while (iVar2 < param_2);

    }

    iVar2 = local_28;

    local_38 = 0;

    local_34 = 4;

    local_33 = 0;

    local_32 = 2;

    local_31 = 0;

    if ((pvVar4 == (void *)0x0) ||

       ((uint)(local_24 - (int)pvVar4 >> 3) <= (uint)(local_28 - (int)pvVar4 >> 3))) {

      FUN_00445fa0(local_28,&local_38);

      pvVar4 = local_2c;

    }

    else {

      FUN_0045f220(0);

      local_28 = iVar2 + 8;

    }

    iVar3 = local_24;

    iVar2 = local_28;

    if (4 < param_2) {

      if ((pvVar4 == (void *)0x0) ||

         ((uint)(local_24 - (int)pvVar4 >> 3) <= (uint)(local_28 - (int)pvVar4 >> 3))) {

        FUN_00445fa0(local_28,&local_38);

        *(uint8_t *)(local_28 + -1) = 1;

        iVar3 = local_24;

        pvVar4 = local_2c;

      }

      else {

        FUN_0045f220(local_38);

        local_28 = iVar2 + 8;

        *(uint8_t *)(iVar2 + 7) = 1;

      }

    }

    iVar2 = local_28;

    local_38 = 0xff;

    local_34 = 0x11;

    local_33 = 0;

    local_32 = 0;

    local_31 = 0;

    if ((pvVar4 == (void *)0x0) ||

       ((uint)(iVar3 - (int)pvVar4 >> 3) <= (uint)(local_28 - (int)pvVar4 >> 3))) {

      FUN_00445fa0(local_28,&local_38);

      pvVar4 = local_2c;

    }

    else {

      FUN_0045f220(0xff);

      local_28 = iVar2 + 8;

    }

    local_20 = 0;

    local_1c = 0;

    FUN_00747390();

    if (pvVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar4);

    }

  }

  ExceptionList = local_14;

  return 0;

}
