// =============================================================================
// FUN_00781530
// -----------------------------------------------------------------------------
// Stable ID: aa_00781530
// Address:   0x00781530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00781530 @ 0x00781530
// Stable ID: aa_00781530
// Embedded strings (evidence for future rename):
//   - "LogGhostConnection"
//   - "Ghosting activated - %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_007814c0, FUN_00781530, FUN_00783aa0, FUN_00783b60.
//  - Strings: "LogGhostConnection"; "Ghosting activated - %d".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00781530(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (*(int *)(param_1 + 0x208) != 0) {

    *(int *)(param_1 + 0x218) = *(int *)(param_1 + 0x218) + 1;

    if ((_DAT_00d207f0 & 1) == 0) {

      _DAT_00d207f0 = _DAT_00d207f0 | 1;

      DAT_00d207ec = FUN_00783b60("LogGhostConnection");

    }

    if (*(char *)(DAT_00d207ec + 4) != '\0') {

      DAT_00d179a0 = DAT_00d207ec;

      FUN_00783aa0("Ghosting activated - %d",*(uint32_t /* width from decompiler */ *)(param_1 + 0x218));

      DAT_00d179a0 = 0;

    }

    iVar2 = 0;

    iVar4 = 0;

    iVar3 = 2;

    do {

      *(int *)(iVar2 + *(int *)(param_1 + 0x208)) = *(int *)(param_1 + 0x220) + iVar4;

      *(int *)(*(int *)(iVar2 + *(int *)(param_1 + 0x208)) + 0x34) = iVar3 + -2;

      *(int *)(iVar2 + 4 + *(int *)(param_1 + 0x208)) = iVar4 + 0x38 + *(int *)(param_1 + 0x220);

      *(int *)(*(int *)(iVar2 + 4 + *(int *)(param_1 + 0x208)) + 0x34) = iVar3 + -1;

      *(int *)(iVar2 + 8 + *(int *)(param_1 + 0x208)) = iVar4 + 0x70 + *(int *)(param_1 + 0x220);

      *(int *)(*(int *)(iVar2 + 8 + *(int *)(param_1 + 0x208)) + 0x34) = iVar3;

      *(int *)(iVar2 + 0xc + *(int *)(param_1 + 0x208)) = *(int *)(param_1 + 0x220) + iVar4 + 0xa8;

      *(int *)(*(int *)(iVar2 + 0xc + *(int *)(param_1 + 0x208)) + 0x34) = iVar3 + 1;

      iVar1 = iVar3 + 2;

      iVar4 = iVar4 + 0xe0;

      iVar2 = iVar2 + 0x10;

      iVar3 = iVar3 + 4;

    } while (iVar1 < 0x400);

    *(uint8_t *)(param_1 + 0x215) = 1;

    FUN_007814c0(param_1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x218));

  }

  return;

}
