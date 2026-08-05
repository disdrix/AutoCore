// READABILITY (auto CF):
//  - Body size: ~190 non-empty decompiler lines.
//  - Control keywords: if×22, return×3, do×2, while×2.
//  - Notable callees: CONCAT22×4, FUN_00435df0×4, FUN_00445170×4, FUN_00768ee0×4, FUN_007693e0×4, FUN_00769e40×3, FUN_00437050×2, FUN_004454f0×2.
//  - Strings: ",0x405

                   ,3,"; ",

                     0x43f,3,".
//  - Return sites: 3.

// =============================================================================
// Named_effVertexDecl
// -----------------------------------------------------------------------------
// Stable ID: aa_00747d30
// Address:   0x00747d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effVertexDecl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_effVertexDecl(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint64_t uVar4;

  uint local_30;

  int local_2c;

  int local_28;

  uint8_t local_24;

  uint8_t local_23;

  uint8_t local_22;

  uint8_t local_21;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1a49;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  iVar3 = 0;

  local_4 = 0;

  if (local_14 != 0x4445434c) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",0x405

                   ,3,"Invalid TAG unserializing effVertexDecl");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  if (local_10 == 1) {

    local_28 = 0;

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050(&local_2c);

    }

    else {

      FUN_00768760(&local_2c);

    }

    FUN_0044ca50();

    FUN_0044c3c0(0,0);

    iVar3 = 0;

    if (0 < local_2c) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + iVar3 * 8);

        *puVar1 = 0;

        puVar1[1] = 0;

        if (*(int *)(param_1 + 0x4044) == 0) {

          if ((*(int *)(param_1 + 0x18) + 2 <= *(int *)(param_1 + 0x20)) ||

             ((iVar2 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), -1 < iVar2

              && (1 < *(int *)(param_1 + 0x20))))) {

            local_30 = CONCAT22(local_30._2_2_,

                                *(uint16_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 2;

          }

        }

        else {

          FUN_00768ee0(&local_30);

        }

        *(uint8_t *)(puVar1 + 1) = (uint8_t)local_30;

        if (*(int *)(param_1 + 0x4044) == 0) {

          if ((*(int *)(param_1 + 0x18) + 2 <= *(int *)(param_1 + 0x20)) ||

             ((iVar2 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), -1 < iVar2

              && (1 < *(int *)(param_1 + 0x20))))) {

            local_30 = CONCAT22(local_30._2_2_,

                                *(uint16_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 2;

          }

        }

        else {

          FUN_00768ee0(&local_30);

        }

        *(uint8_t *)((int)puVar1 + 5) = (uint8_t)local_30;

        if (*(int *)(param_1 + 0x4044) == 0) {

          if ((*(int *)(param_1 + 0x18) + 2 <= *(int *)(param_1 + 0x20)) ||

             ((iVar2 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), -1 < iVar2

              && (1 < *(int *)(param_1 + 0x20))))) {

            local_30 = CONCAT22(local_30._2_2_,

                                *(uint16_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 2;

          }

        }

        else {

          FUN_00768ee0(&local_30);

        }

        *(undefined *)((int)puVar1 + 6) = (&DAT_00a24184)[local_30 & 0xffff];

        if (*(int *)(param_1 + 0x4044) == 0) {

          if ((*(int *)(param_1 + 0x18) + 2 <= *(int *)(param_1 + 0x20)) ||

             ((iVar2 = FUN_00435df0(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x18)), -1 < iVar2

              && (1 < *(int *)(param_1 + 0x20))))) {

            local_30 = CONCAT22(local_30._2_2_,

                                *(uint16_t *)(*(int *)(param_1 + 0x18) + param_1 + 0x2c));

            *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 2;

          }

        }

        else {

          FUN_00768ee0(&local_30);

        }

        *(ushort *)((int)puVar1 + 2) = (ushort)local_28 & 0xff;

        *(uint8_t *)((int)puVar1 + 7) = (uint8_t)local_30;

        uVar4 = FUN_007467b0();

        local_28 = (int)((ulonglong)uVar4 >> 0x20) + (int)uVar4;

        iVar3 = iVar3 + 1;

      } while (iVar3 < local_2c);

    }

    local_28 = 0xff;

    local_24 = 0x11;

    local_23 = 0;

    local_22 = 0;

    local_21 = 0;

    FUN_004454f0();

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = 0;

  }

  else {

    if (local_10 != 2) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",

                     0x43f,3,"Invalid chunk version unserializing effVertexDecl");

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0xffffffff;

    }

    local_30 = 0;

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050(&local_2c);

    }

    else {

      FUN_00768760(&local_2c);

    }

    FUN_0044ca50();

    FUN_0044c3c0(0,0);

    if (0 < local_2c) {

      do {

        puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 4) + iVar3 * 8);

        *puVar1 = 0;

        puVar1[1] = 0;

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00445170(puVar1 + 1);

        }

        else {

          FUN_007693e0(puVar1 + 1);

        }

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00445170((int)puVar1 + 5);

        }

        else {

          FUN_007693e0((int)puVar1 + 5);

        }

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00445170((int)puVar1 + 6);

        }

        else {

          FUN_007693e0((int)puVar1 + 6);

        }

        if (*(int *)(param_1 + 0x4044) == 0) {

          FUN_00445170((int)puVar1 + 7);

        }

        else {

          FUN_007693e0((int)puVar1 + 7);

        }

        *(ushort *)((int)puVar1 + 2) = (ushort)local_30 & 0xff;

        uVar4 = FUN_007467b0();

        local_30 = (int)((ulonglong)uVar4 >> 0x20) + (int)uVar4;

        iVar3 = iVar3 + 1;

      } while (iVar3 < local_2c);

    }

    local_28 = 0xff;

    local_24 = 0x11;

    local_23 = 0;

    local_22 = 0;

    local_21 = 0;

    FUN_004454f0();

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x14) = 0;

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0;

}
