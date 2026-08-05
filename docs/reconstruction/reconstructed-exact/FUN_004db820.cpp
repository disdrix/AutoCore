// =============================================================================
// FUN_004db820
// -----------------------------------------------------------------------------
// Stable ID: aa_004db820
// Address:   0x004db820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004db820 @ 0x004db820
// Stable ID: aa_004db820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, return×1, for×1, goto×1, while×1.
//  - Notable callees: FUN_004db820, FUN_004e7900.
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

void __thiscall FUN_004db820(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  uint *puVar1;

  uint uVar2;

  int iVar3;

  uint *puVar4;

  

  puVar4 = *(uint **)(param_2 + 4);

  puVar1 = *(uint **)(param_2 + 8);

  do {

    if (puVar4 == puVar1) {

      return;

    }

    uVar2 = *puVar4;

    for (iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe520) + 0x10) +

                                  (*(uint *)(*(int *)(param_1 + 0xe520) + 8) & uVar2) * 4) + 4);

        iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

      if ((uVar2 == *(uint *)(iVar3 + 0x18)) && (puVar4[1] == *(uint *)(iVar3 + 0x1c))) {

        if ((iVar3 != 0) && (*(int *)(iVar3 + 0xc) != 0)) goto LAB_004db893;

        break;

      }

    }

    FUN_004e7900(uVar2,puVar4[1],param_3,0);

LAB_004db893:

    puVar4 = puVar4 + 2;

  } while( true );

}
