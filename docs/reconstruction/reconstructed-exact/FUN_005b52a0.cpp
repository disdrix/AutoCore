// =============================================================================
// FUN_005b52a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005b52a0
// Address:   0x005b52a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b52a0 @ 0x005b52a0
// Stable ID: aa_005b52a0
// Embedded strings (evidence for future rename):
//   - "RenderLeavesForShadows"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~74 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00687220×2, FUN_00752a00×2, FUN_0096f5d0×2, FUN_0096fdf0×2, FUN_005b52a0, FUN_006868a0, FUN_00686d30, FUN_00687230.
//  - Strings: "RenderLeavesForShadows".
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

uint32_t /* width from decompiler */ __thiscall FUN_005b52a0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  ushort uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  float local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a6903;

  local_c = ExceptionList;

  local_28 = DAT_00d1f040;

  ExceptionList = &local_c;

  FUN_0076cf00("RenderLeavesForShadows");

  local_18 = *param_2;

  local_14 = (float)param_2[1] + DAT_00aaa7ac;

  local_10 = param_2[2];

  local_4 = 0;

  local_24 = 0;

  local_20 = DAT_00aaa668;

  local_1c = 0;

  FUN_006892b0(&local_18,&local_24);

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),4,0xffffffff,0xffffffff,0);

  local_2c = 0;

  FUN_006868a0(0);

  FUN_00686d30(0,0xbf800000,0xbf800000);

  uVar3 = FUN_00687230(&local_2c);

  if (**(int **)(param_1 + 0x14) != 0) {

    FUN_0096fe40(*(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x14) + 0xd4),uVar3,local_2c * 4);

    uVar3 = *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x14) + 0xd0);

    cVar1 = FUN_0096fdf0();

    iVar4 = FUN_00752a00(uVar3,&DAT_00b05368);

    if ((iVar4 == -1) && (cVar1 != '\0')) {

      FUN_0096f5d0();

    }

    param_2 = DAT_00aaa8a4;

    uVar3 = *(uint32_t /* width from decompiler */ *)(**(int **)(param_1 + 0x14) + 0xd8);

    cVar1 = FUN_0096fdf0();

    iVar4 = FUN_00752a00(uVar3,&param_2);

    if ((iVar4 == -1) && (cVar1 != '\0')) {

      FUN_0096f5d0();

    }

  }

  uVar6 = 1;

  uVar2 = FUN_00687220();

  if (1 < uVar2) {

    do {

      iVar4 = *(int *)(*(int *)(param_1 + 0x14) + uVar6 * 4);

      if (iVar4 != 0) {

        *(uint8_t *)(iVar4 + 0xcc) = 0;

      }

      uVar6 = uVar6 + 1;

      uVar5 = FUN_00687220();

    } while (uVar6 < (uVar5 & 0xffff));

  }

  if (**(int **)(param_1 + 0x14) != 0) {

    *(uint8_t *)(**(int **)(param_1 + 0x14) + 0xcc) = 1;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 1;

}
