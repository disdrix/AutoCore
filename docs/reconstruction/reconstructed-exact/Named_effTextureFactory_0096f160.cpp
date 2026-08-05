// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×10, return×3.
//  - Notable callees: FUN_0096ea60, FUN_0096f160, vog_LogMessage.
//  - Strings: ",

                   0xd9,2,".
//  - Return sites: 3.

// =============================================================================
// Named_effTextureFactory_0096f160
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f160
// Address:   0x0096f160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effTextureFactory"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_effTextureFactory_0096f160(uint *param_1)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint uVar5;

  uint uVar6;

  uint *local_4;

  

  if (*(int *)(*param_1 + 8) < 2) {

    return 0;

  }

  iVar2 = *(int *)(*param_1 + 0x4c);

  if (iVar2 == 0) {

    puVar4 = &DAT_00d1ed24;

  }

  else {

    puVar4 = (uint32_t /* width from decompiler */ *)(iVar2 + 4);

  }

  local_4 = param_1;

  uVar5 = FUN_0096ea60(puVar4,&local_4,0);

  if (uVar5 == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureFactory.cpp",

                   0xd9,2,"Failed to Default Texture!");

    return 0;

  }

  uVar3 = *param_1;

  uVar6 = *(uint *)(uVar3 + 0x50);

  if ((*(uint *)(uVar3 + 0x50) != 0) || (uVar6 = uVar3, uVar3 != 0)) {

    *(int *)(uVar6 + 8) = *(int *)(uVar6 + 8) + 1;

    if (*(int *)(uVar6 + 8) == 1) {

      (**(code **)(*(int *)(uVar6 + 4) + 4))();

    }

  }

  iVar2 = *(int *)(uVar5 + 0x50);

  if (iVar2 != 0) {

    piVar1 = (int *)(iVar2 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(iVar2 + 4) + 8))();

    }

  }

  *(uint *)(uVar5 + 0x50) = uVar6;

  *(int *)(uVar5 + 8) = *(int *)(uVar5 + 8) + 1;

  if (*(int *)(uVar5 + 8) == 1) {

    (**(code **)(*(int *)(uVar5 + 4) + 4))();

  }

  uVar3 = *param_1;

  if (uVar3 != 0) {

    piVar1 = (int *)(uVar3 + 8);

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*(int *)(uVar3 + 4) + 8))();

    }

  }

  *param_1 = uVar5;

  return 1;

}
