// =============================================================================
// FUN_00744970
// -----------------------------------------------------------------------------
// Stable ID: aa_00744970
// Address:   0x00744970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00744970 @ 0x00744970
// Stable ID: aa_00744970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_00426f60, FUN_0044d960, FUN_0044dc00, FUN_00744970.
//  - Return sites: 2.

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

uint FUN_00744970(uint32_t /* width from decompiler */ param_1,int *param_2,int param_3)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint *puVar4;

  uint uVar5;

  

  FUN_00426f60();

  puVar4 = (uint *)FUN_0044d960();

  uVar1 = *puVar4;

  uVar2 = puVar4[1];

  uVar5 = uVar2;

  if (uVar1 != uVar2) {

    iVar3 = *param_2;

    do {

      if (*(int *)(uVar1 + 0x18) == iVar3) {

        *(int *)(uVar1 + 0x20) = *(int *)(uVar1 + 0x20) + 1;

        *(int *)(uVar1 + 0x1c) = *(int *)(uVar1 + 0x1c) + param_3;

        return 1;

      }

      uVar5 = FUN_0044dc00();

    } while (uVar1 != uVar2);

  }

  return uVar5 & 0xffffff00;

}
