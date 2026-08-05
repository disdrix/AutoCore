// =============================================================================
// FUN_0096be60
// -----------------------------------------------------------------------------
// Stable ID: aa_0096be60
// Address:   0x0096be60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096be60 @ 0x0096be60
// Stable ID: aa_0096be60
// Embedded strings (evidence for future rename):
//   - "Failed to lock texture surface."
//   - "%s - %s\r\n%s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×9, return×2, goto×1.
//  - Notable callees: CONCAT31, FUN_006a5dac, FUN_006b7a5a, FUN_0076cec0, FUN_0096be60, vog_LogMessage.
//  - Strings: "Failed to lock texture surface."; "%s - %s\r\n%s".
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

uint32_t /* width from decompiler */ __thiscall

FUN_0096be60(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint param_5)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uVar1 = ~(param_5 << 8) & 0x800;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  if ((param_5 & 1) != 0) {

    uVar1 = (uint)(byte)((byte)(uVar1 >> 8) | 0x20) << 8;

  }

  if ((param_5 & 2) != 0) {

    uVar1 = uVar1 | 0x1000;

  }

  if ((param_5 & 4) != 0) {

    uVar1 = CONCAT31((int3)(uVar1 >> 8),0x10);

  }

  if ((param_5 & 0x10) != 0) {

    uVar1 = uVar1 | 0x4000;

  }

  if ((param_5 & 0x20) != 0) {

    uVar1 = uVar1 | 0x8000;

  }

  uVar3 = *(uint *)(param_1 + 0x2c) & 0xf;

  if (uVar3 == 1) {

    iVar4 = (**(code **)(**(int **)(param_1 + 0x10) + 0x4c))

                      (*(int **)(param_1 + 0x10),param_2,&local_c,param_3,uVar1);

    uStack_4 = uStack_8;

  }

  else if (uVar3 == 2) {

    iVar4 = (**(code **)(**(int **)(param_1 + 0x10) + 0x4c))

                      (*(int **)(param_1 + 0x10),param_4,param_2,&local_c,param_3,uVar1);

    uStack_4 = uStack_8;

  }

  else {

    if (uVar3 != 4) {

      iVar4 = -1;

      goto LAB_0096bf33;

    }

    iVar4 = (**(code **)(**(int **)(param_1 + 0x10) + 0x4c))

                      (*(int **)(param_1 + 0x10),param_2,&local_c,param_3,uVar1);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = uStack_8;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = local_c;

  if (-1 < iVar4) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = param_4;

    return uStack_4;

  }

LAB_0096bf33:

  uVar2 = FUN_006b7a5a(iVar4,"Failed to lock texture surface.");

  uVar2 = FUN_006a5dac(iVar4,uVar2);

  uVar2 = FUN_0076cec0(&stack0x00000000,"%s - %s\r\n%s",uVar2);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",0x3fe,

                 1,uVar2);

  return 0;

}
