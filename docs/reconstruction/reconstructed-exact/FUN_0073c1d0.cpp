// =============================================================================
// FUN_0073c1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073c1d0
// Address:   0x0073c1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073c1d0 @ 0x0073c1d0
// Stable ID: aa_0073c1d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: for×2, if×2, return×1.
//  - Notable callees: FUN_004367f0×2, FUN_0073c1d0.
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

void FUN_0073c1d0(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint uVar4;

  

  for (uVar4 = *(uint *)(unaff_EBX + 0x30);

      (*(int *)(unaff_EBX + 0x38) != 0 &&

      (uVar4 < (uint)(*(int *)(unaff_EBX + 0x3c) - *(int *)(unaff_EBX + 0x38) >> 2)));

      uVar4 = uVar4 + 1) {

    iVar2 = *(int *)(unaff_EBX + 0x38);

    puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + uVar4 * 4);

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(iVar2 + uVar4 * 4) = 0;

  }

  FUN_004367f0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x30),0);

  for (uVar4 = *(uint *)(unaff_EBX + 0x44);

      (*(int *)(unaff_EBX + 0x4c) != 0 &&

      (uVar4 < (uint)(*(int *)(unaff_EBX + 0x50) - *(int *)(unaff_EBX + 0x4c) >> 2)));

      uVar4 = uVar4 + 1) {

    piVar1 = (int *)(*(int *)(unaff_EBX + 0x4c) + uVar4 * 4);

    puVar3 = (uint32_t /* width from decompiler */ *)*piVar1;

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

    *piVar1 = 0;

  }

  FUN_004367f0(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x44),0);

  return;

}
