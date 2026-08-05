// =============================================================================
// FUN_0048af90
// -----------------------------------------------------------------------------
// Stable ID: aa_0048af90
// Address:   0x0048af90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048af90 @ 0x0048af90
// Stable ID: aa_0048af90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, for×1, if×1, return×1.
//  - Notable callees: FUN_0048a940×2, FUN_0048af90.
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

void __thiscall FUN_0048af90(int param_1,int param_2)



{

  char cVar1;

  int *piVar2;

  char *pcVar3;

  int iVar4;

  char *pcVar5;

  

  pcVar5 = (char *)(*(int *)(param_1 + 0x20) + 8);

  pcVar3 = pcVar5;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(pcVar5,(int)pcVar3 - (*(int *)(param_1 + 0x20) + 9));

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint8_t *)(param_2 + 0x2c) = *(uint8_t *)(param_1 + 0x2c);

  pcVar5 = (char *)(*(int *)(param_1 + 0x34) + 8);

  pcVar3 = pcVar5;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  FUN_0048a940(pcVar5,(int)pcVar3 - (*(int *)(param_1 + 0x34) + 9));

  for (piVar2 = *(int **)(param_1 + 0x18); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[10]) {

    iVar4 = (**(code **)(*piVar2 + 0x40))();

    *(int *)(iVar4 + 0x10) = param_2;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x1c);

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x28) = 0;

    if (*(int *)(param_2 + 0x1c) == 0) {

      *(int *)(param_2 + 0x18) = iVar4;

    }

    else {

      *(int *)(*(int *)(param_2 + 0x1c) + 0x28) = iVar4;

    }

    *(int *)(param_2 + 0x1c) = iVar4;

  }

  return;

}
