// =============================================================================
// FUN_00831340
// -----------------------------------------------------------------------------
// Stable ID: aa_00831340
// Address:   0x00831340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00831340 @ 0x00831340
// Stable ID: aa_00831340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00831340.
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

void __fastcall FUN_00831340(byte param_1)



{

  int iVar1;

  uint8_t *puVar2;

  uint8_t uVar3;

  int *unaff_ESI;

  

  if (unaff_ESI != (int *)0x0) {

    uVar3 = 0x80;

    if ((DAT_00af9218 & 1 << (param_1 & 0x1f)) != 0) {

      uVar3 = 0xff;

    }

    (**(code **)(*unaff_ESI + 0x34c))();

    iVar1 = (**(code **)(*unaff_ESI + 0x164))(1);

    *(uint8_t *)(iVar1 + 3) = uVar3;

    *(uint8_t *)((int)unaff_ESI + 0x4a3) = uVar3;

    puVar2 = (uint8_t *)((int)unaff_ESI + 0x4b7);

    iVar1 = 4;

    do {

      *puVar2 = uVar3;

      puVar2 = puVar2 + 4;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  return;

}
