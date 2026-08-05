// =============================================================================
// FUN_00413ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00413ea0
// Address:   0x00413ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00413ea0 @ 0x00413ea0
// Stable ID: aa_00413ea0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: while×2, do×1, if×1, return×1.
//  - Notable callees: FUN_00413ea0.
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

void FUN_00413ea0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint uVar4;

  

  uVar4 = 0;

  do {

    puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(unaff_EBX + 0x10) + uVar4 * 4) + 4);

    while (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)puVar3[4];

      *puVar3 = &PTR_FUN_00a64758;

      if ((uint32_t /* width from decompiler */ *)puVar3[3] != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)puVar3[3])(1);

      }

      puVar3[3] = 0;

      *puVar3 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20);

      *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x20) = puVar3;

      puVar3 = puVar2;

    }

    iVar1 = uVar4 * 4;

    uVar4 = uVar4 + 1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_EBX + 0x10) + iVar1) + 4) = 0;

  } while (uVar4 <= *(uint *)(unaff_EBX + 8));

  return;

}
