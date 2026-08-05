// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, do×2, while×2.
//  - Notable callees: CONCAT31×5, FUN_0071af70×2, vog_LogMessage×2, FUN_0066f000, FUN_0066f910, FUN_0066fcf0, FUN_00671b90, FUN_00671f00.
//  - Strings: "

                   ,0x17d,3,"; "

                 ,0x172,3,".
//  - Return sites: 4.

// =============================================================================
// Named_ChatClientImpl_0066fcf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0066fcf0
// Address:   0x0066fcf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_0066fcf0(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  undefined3 uVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a8fb1;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(int *)(param_1 + 0x1c8) == 4) {

    ExceptionList = &local_c;

    iVar1 = FUN_0066f000();

    if (iVar1 < 0) {

      FUN_0066f910();

      ExceptionList = local_c;

      return 0xffffffff;

    }

    pvVar2 = operator_new__((uint)*(byte *)(param_1 + 0x14) * 4);

    *(void **)(param_1 + 0x208) = pvVar2;

    uVar3 = 0;

    if (*(char *)(param_1 + 0x14) != '\0') {

      do {

        *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x208) + uVar3 * 4) = 0;

        uVar3 = uVar3 + 1;

      } while (uVar3 != *(byte *)(param_1 + 0x14));

    }

  }

  if (*(int *)(param_1 + 0x2c) == 0) {

    pvVar2 = operator_new(0x9b0);

    local_4 = 0;

    if (pvVar2 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_00672de0();

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = uVar4;

  }

  if (*(int *)(param_1 + 0x30) == 0) {

    pvVar2 = operator_new(0x16c);

    local_4 = 1;

    if (pvVar2 == (void *)0x0) {

      uVar4 = 0;

    }

    else {

      uVar4 = FUN_00675010();

    }

    local_4 = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = uVar4;

  }

  iVar1 = FUN_00671f00(*(uint8_t *)(param_1 + 0x28),*(uint8_t *)(param_1 + 0x185),

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f0));

  if (-1 < iVar1) {

    iVar1 = FUN_00673c90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*(uint8_t *)(param_1 + 0x15),

                         *(uint8_t *)(param_1 + 0x14),*(uint32_t /* width from decompiler */ *)(param_1 + 500),

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x200),param_1 + 0x1ec);

    if (-1 < iVar1) {

      FUN_0071af70();

      FUN_0071af70();

      FUN_00671b90(param_1 + 0x5c);

      FUN_00673e00(param_1 + 0x5c);

      pvVar2 = operator_new__((uint)*(byte *)(param_1 + 0x14));

      *(void **)(param_1 + 0x1f8) = pvVar2;

      uVar3 = 0;

      if (*(char *)(param_1 + 0x14) != '\0') {

        do {

          *(uint8_t *)(uVar3 + *(int *)(param_1 + 0x1f8)) = 0;

          uVar3 = uVar3 + 1;

        } while (uVar3 != *(byte *)(param_1 + 0x14));

      }

      uVar5 = (undefined3)((uint)*(uint32_t /* width from decompiler */ *)(param_1 + 0x18) >> 8);

      pvVar2 = (void *)CONCAT31(uVar5,*(uint8_t *)(param_1 + 0x14));

      (**(code **)(**(int **)(param_1 + 0x54) + 0x14))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 8),

                 CONCAT31(uVar5,*(uint8_t *)(param_1 + 0xc)),pvVar2,

                 CONCAT31(uVar5,*(uint8_t *)(param_1 + 0x15)),

                 CONCAT31(uVar5,*(uint8_t *)(param_1 + 0x20)),*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c),

                 CONCAT31((int3)((uint)(param_1 + 0x1d0) >> 8),*(uint8_t *)(param_1 + 0x1c8)),

                 param_1 + 0x1d0);

      ExceptionList = pvVar2;

      return 0;

    }

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                   ,0x17d,3,"Unable to initialize audio output.");

    ExceptionList = local_c;

    return 0xffffffff;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                 ,0x172,3,"Unable to initialize audio input.");

  ExceptionList = local_c;

  return 0xffffffff;

}
