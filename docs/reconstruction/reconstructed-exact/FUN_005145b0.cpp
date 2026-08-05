// =============================================================================
// FUN_005145b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005145b0
// Address:   0x005145b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005145b0 @ 0x005145b0
// Stable ID: aa_005145b0
// Embedded strings (evidence for future rename):
//   - "Template %i Not Found"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, do×1, while×1.
//  - Notable callees: FUN_004eb240×2, FUN_00403450, FUN_004ce940, FUN_00508e20, FUN_005145b0, FUN_007a4480, block.
//  - Strings: "Template %i Not Found".
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x0051467c) */



uint8_t * __fastcall FUN_005145b0(int *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char acStack_80 [128];

  

  if (((*(byte *)(param_1 + 0x5f) & 0x10) == 0) ||

     (iVar2 = (**(code **)(*param_1 + 0x98))(), iVar2 < 0)) {

    if ((uint8_t *)param_1[0x56] != (uint8_t *)0x0) {

      return (uint8_t *)param_1[0x56];

    }

    iVar2 = FUN_004eb240();

    if (iVar2 != 0) {

      uVar3 = FUN_004eb240();

      pcVar5 = acStack_80;

      uVar4 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(uVar3,uVar4);

      iVar2 = (int)&DAT_00b04488 - (int)pcVar5;

      do {

        cVar1 = *pcVar5;

        pcVar5[iVar2] = cVar1;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      return &DAT_00b04488;

    }

  }

  else {

    uVar3 = (**(code **)(*param_1 + 0x98))();

    FUN_004ce940(uVar3);

    iVar2 = FUN_00508e20(uVar3);

    if (iVar2 != 0) {

      return (uint8_t *)(iVar2 + 4);

    }

    uVar3 = (**(code **)(*param_1 + 0x98))();

    FUN_007a4480(1,"Template %i Not Found",uVar3);

  }

  return &DAT_00a1419b;

}
