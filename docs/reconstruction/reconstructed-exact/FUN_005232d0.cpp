// =============================================================================
// FUN_005232d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005232d0
// Address:   0x005232d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005232d0 @ 0x005232d0
// Stable ID: aa_005232d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00403450, FUN_00523200, FUN_005232d0, FUN_0074e800, FUN_0074e910, FUN_007b6730, FUN_007b6a20, block.
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

/* WARNING: Removing unreachable block (ram,0x00523324) */



void __thiscall FUN_005232d0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char local_180 [128];

  char acStack_100 [256];

  

  pcVar3 = local_180;

  (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450();

  iVar2 = -(int)pcVar3;

  do {

    cVar1 = *pcVar3;

    pcVar3[(int)(acStack_100 + iVar2)] = cVar1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  if ((acStack_100[0] != '\0') && (acStack_100[0] != ' ')) {

    FUN_007b6a20();

    FUN_007b6730();

    if (*(int *)(param_1 + 0x48) != 0) {

      if (*(int *)(param_1 + 0x6c) != 0) {

        FUN_0074e800();

      }

      (**(code **)(*(int *)(param_1 + 0x40) + 4))();

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6f8) = *param_2;

    (*(code *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x40))(1);

    (**(code **)(*(int *)(param_1 + 0x40) + 0x20))();

    if (*(int *)(param_1 + 0x6c) != 0) {

      FUN_0074e910(0,param_3);

    }

    FUN_00523200();

  }

  return;

}
