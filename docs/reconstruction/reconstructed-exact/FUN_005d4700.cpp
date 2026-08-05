// =============================================================================
// FUN_005d4700
// -----------------------------------------------------------------------------
// Stable ID: aa_005d4700
// Address:   0x005d4700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d4700 @ 0x005d4700
// Stable ID: aa_005d4700
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, goto×1, return×1.
//  - Notable callees: FUN_005070b0×2, FUN_005070d0×2, FUN_005d4050, FUN_005d4440, FUN_005d4700.
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

void __thiscall FUN_005d4700(int param_1,int param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  

  iVar2 = param_2;

  FUN_005d4440((int)*(char *)(param_2 + 0xb4));

  iVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))();

  if (iVar3 != 7) {

    pcVar4 = (char *)FUN_005070b0(&param_2);

    if ((*pcVar4 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(iVar2 + 0x40);

    pcVar4 = (char *)FUN_005070b0(&stack0x00000000);

    if ((*pcVar4 == '\0') && (*(int *)(param_1 + 0x44) != 0)) {

      FUN_005070d0();

    }

    (**(code **)(**(int **)(param_1 + 0x3c) + 0x54))(iVar2 + 0x50);

    iVar3 = (**(code **)(**(int **)(param_1 + 0x3c) + 0x18))();

    if (iVar3 != 6) {

      (**(code **)(**(int **)(param_1 + 0x3c) + 0x2c))(iVar2 + 0x60);

      (**(code **)(**(int **)(param_1 + 0x3c) + 0x3c))(iVar2 + 0x90);

      (**(code **)(**(int **)(param_1 + 0x3c) + 0x1c))(*(uint32_t /* width from decompiler */ *)(iVar2 + 0xa0));

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x3c) + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xa8);

    if (*(int **)(param_1 + 0x54) != (int *)0x0) {

      cVar1 = *(char *)(iVar2 + 0xb5);

      iVar3 = (**(code **)(**(int **)(param_1 + 0x54) + 0x1c))();

      if (iVar3 == cVar1) goto LAB_005d47f1;

    }

    FUN_005d4050((int)*(char *)(iVar2 + 0xb5));

  }

LAB_005d47f1:

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xac);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb0);

  return;

}
