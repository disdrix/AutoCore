// =============================================================================
// FUN_0077d2d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0077d2d0
// Address:   0x0077d2d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0077d2d0 @ 0x0077d2d0
// Stable ID: aa_0077d2d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~81 non-empty decompiler lines.
//  - Control keywords: if×7, do×6, while×6, return×5, for×1.
//  - Notable callees: FUN_0077bf80×2, FUN_0077c610×2, FUN_0077cc20, FUN_0077d2d0.
//  - Return sites: 5.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



int FUN_0077d2d0(void)



{

  int iVar1;

  undefined *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  bool bVar6;

  int local_10c8 [8];

  uint32_t /* width from decompiler */ local_10a8 [1063];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x77d2e0;

  puVar2 = &DAT_00a23784;

  do {

    puVar4 = local_10a8;

    for (iVar1 = 0x428; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    iVar1 = FUN_0077cc20(puVar2,*(uint32_t /* width from decompiler */ *)(puVar2 + -4),0,local_10a8);

    if (iVar1 != 0) {

      return iVar1;

    }

    FUN_0077c610(puVar2 + 0x20,local_10c8,local_10a8);

    FUN_0077bf80(local_10c8,local_10c8 + 4,local_10a8);

    iVar1 = 4;

    bVar6 = true;

    piVar3 = local_10c8;

    piVar5 = (int *)(puVar2 + 0x30);

    do {

      if (iVar1 == 0) break;

      iVar1 = iVar1 + -1;

      bVar6 = *piVar3 == *piVar5;

      piVar3 = piVar3 + 1;

      piVar5 = piVar5 + 1;

    } while (bVar6);

    if (!bVar6) {

      return 5;

    }

    iVar1 = 4;

    bVar6 = true;

    piVar3 = local_10c8 + 4;

    piVar5 = (int *)(puVar2 + 0x20);

    do {

      if (iVar1 == 0) break;

      iVar1 = iVar1 + -1;

      bVar6 = *piVar3 == *piVar5;

      piVar3 = piVar3 + 1;

      piVar5 = piVar5 + 1;

    } while (bVar6);

    if (!bVar6) {

      return 5;

    }

    local_10c8[0] = 0;

    local_10c8[1] = 0;

    local_10c8[2] = 0;

    local_10c8[3] = 0;

    iVar1 = 1000;

    do {

      FUN_0077c610(local_10c8,local_10c8,local_10a8);

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

    iVar1 = 1000;

    do {

      FUN_0077bf80(local_10c8,local_10c8,local_10a8);

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

    iVar1 = 0;

    do {

      if (*(char *)((int)local_10c8 + iVar1) != '\0') {

        return 5;

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < 0x10);

    puVar2 = puVar2 + 0x44;

    if (0xa2384f < (int)puVar2) {

      return 0;

    }

  } while( true );

}
