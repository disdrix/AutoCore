// =============================================================================
// FUN_005aa5c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005aa5c0
// Address:   0x005aa5c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005aa5c0 @ 0x005aa5c0
// Stable ID: aa_005aa5c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, goto×2, while×2, return×1.
//  - Notable callees: FUN_00403450, FUN_00541a80, FUN_005aa5c0, block.
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

/* WARNING: Removing unreachable block (ram,0x005aa654) */



void __fastcall FUN_005aa5c0(int param_1)



{

  char cVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  char *pcVar5;

  char local_80 [128];

  

  uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0xfc);

  iVar3 = FUN_00541a80();

  iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & uVar2) * 4) + 4);

  if (iVar3 == 0) {

LAB_005aa604:

    iVar3 = 0;

  }

  else {

    do {

      if (uVar2 == *(uint *)(iVar3 + 0x10)) {

        if (iVar3 == 0) goto LAB_005aa604;

        iVar3 = *(int *)(iVar3 + 8);

        goto LAB_005aa60b;

      }

      iVar3 = *(int *)(iVar3 + 0xc);

    } while (iVar3 != 0);

    iVar3 = 0;

  }

LAB_005aa60b:

  if (iVar3 != 0) {

    pcVar5 = local_80;

    uVar4 = (*(code *)PTR_FUN_00af8c9c)();

    FUN_00403450(iVar3 + 0xb4,uVar4);

    param_1 = param_1 - (int)pcVar5;

    do {

      cVar1 = *pcVar5;

      pcVar5[param_1 + 0xc] = cVar1;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

  }

  return;

}
