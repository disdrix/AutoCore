// =============================================================================
// FUN_008a6f20
// -----------------------------------------------------------------------------
// Stable ID: aa_008a6f20
// Address:   0x008a6f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a6f20 @ 0x008a6f20
// Stable ID: aa_008a6f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×2, while×2.
//  - Notable callees: FUN_007900e0×2, FUN_008a6f20.
//  - Return sites: 3.

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

uint8_t __thiscall FUN_008a6f20(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  char cVar2;

  uint8_t uVar3;

  char *pcVar4;

  char *pcVar5;

  

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if (((cVar2 == '\0') || (param_1[0x12f] == 0)) || (param_1[0x12f] != param_1[0x153])) {

    uVar3 = FUN_007900e0(param_2,param_3);

    return uVar3;

  }

  uVar3 = FUN_007900e0(param_2,param_3);

  pcVar4 = (char *)(**(code **)(*(int *)param_1[0x153] + 0x1dc))();

  if (pcVar4 != (char *)0x0) {

    pcVar5 = pcVar4;

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    if (pcVar5 != pcVar4 + 1) {

      iVar1 = 0x4fd - (int)pcVar4;

      do {

        cVar2 = *pcVar4;

        pcVar4[(int)param_1 + iVar1] = cVar2;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      return uVar3;

    }

  }

  *(uint8_t *)((int)param_1 + 0x4fd) = 0;

  return uVar3;

}
