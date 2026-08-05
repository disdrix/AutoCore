// =============================================================================
// Named_CalleeOf_Named_hkWorld_005d4240
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4240
// Callee of Named_hkWorld (+1 other named callers)
// Address:   0x005d4240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_hkWorld (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_005070b0×2, FUN_005070d0×2, CVOGHBAIBase_Default_ctor, FUN_00507420, FUN_005d4050, FUN_005d4110, FUN_005d4240.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkWorld (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_hkWorld_005d4240(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  

  iVar1 = param_2;

  FUN_00507420(param_2);

  *param_1 = &PTR_FUN_009daabc;

  if (*(char *)(iVar1 + 0xb4) == '\a') {

    *(uint8_t *)(param_1 + 0x10) = 1;

    iVar2 = (**(code **)(*DAT_00b05060 + 0x10))(0xd0,0x29);

    *(uint16_t *)(iVar2 + 4) = 0xd0;

    iVar2 = CVOGHBAIBase_Default_ctor(iVar1 + 0x20,iVar1 + 0x30);

    param_1[0xf] = iVar2;

    param_1[5] = iVar2 + 0x60;

  }

  else {

    uVar3 = CVOGHBAI_CreateByAICode

                      ((int)*(char *)(iVar1 + 0xb4),*(uint32_t /* width from decompiler */ *)(iVar1 + 0xa0),iVar1 + 0x60,

                       iVar1 + 0x90);

    param_1[0xf] = uVar3;

    pcVar4 = (char *)FUN_005070b0(&param_2);

    if ((*pcVar4 == '\0') && (param_1[0x11] != 0)) {

      FUN_005070d0();

    }

    (**(code **)(*(int *)param_1[0xf] + 0x50))(iVar1 + 0x40);

    pcVar4 = (char *)FUN_005070b0(&stack0x00000000);

    if ((*pcVar4 == '\0') && (param_1[0x11] != 0)) {

      FUN_005070d0();

    }

    (**(code **)(*(int *)param_1[0xf] + 0x54))(iVar1 + 0x50);

    *(uint32_t /* width from decompiler */ *)(param_1[0xf] + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1[0xf] + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa8);

    param_1[5] = param_1[0xf] + 0x60;

    FUN_005d4050((int)*(char *)(iVar1 + 0xb5));

    if (param_1[3] != 0) {

      FUN_005d4110();

    }

  }

  param_1[0x13] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xac);

  param_1[0x14] = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

  return param_1;

}
