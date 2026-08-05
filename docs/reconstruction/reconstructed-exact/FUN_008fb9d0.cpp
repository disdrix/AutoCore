// =============================================================================
// FUN_008fb9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008fb9d0
// Address:   0x008fb9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fb9d0 @ 0x008fb9d0
// Stable ID: aa_008fb9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×1, return×1.
//  - Notable callees: FUN_008fb9d0.
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

void FUN_008fb9d0(int param_1)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  int unaff_EBX;

  int *piVar5;

  int iVar6;

  

  *(int *)(param_1 + 0x660) = unaff_EBX;

  iVar2 = (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x164))(0);

  piVar5 = (int *)(param_1 + 0x548);

  iVar6 = 6;

  do {

    *(uint8_t *)(iVar2 + 3) = 0x32;

    *(uint32_t /* width from decompiler */ *)(*piVar5 + 0xf8) = 0x32;

    (**(code **)(*(int *)*piVar5 + 0x154))(0,iVar2);

    (**(code **)(*(int *)*piVar5 + 0x34c))();

    piVar5 = piVar5 + 1;

    iVar6 = iVar6 + -1;

  } while (iVar6 != 0);

  *(uint8_t *)(iVar2 + 3) = 0x96;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x548 + unaff_EBX * 4) + 0xf8) = 0x96;

  (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x154))(0,iVar2);

  (**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x34c))();

  pcVar3 = (char *)(**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x1dc))();

  pcVar4 = pcVar3 + 1;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if (pcVar3 != pcVar4) {

    pcVar3 = (char *)(**(code **)(**(int **)(param_1 + 0x548 + unaff_EBX * 4) + 0x1dc))();

    pcVar4 = (char *)(param_1 + 0x560);

    do {

      cVar1 = *pcVar3;

      *pcVar4 = cVar1;

      pcVar3 = pcVar3 + 1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
