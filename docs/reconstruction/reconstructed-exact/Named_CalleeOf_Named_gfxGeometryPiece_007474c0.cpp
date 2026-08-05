// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPiece_007474c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007474c0
// Callee of Named_gfxGeometryPiece
// Address:   0x007474c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPiece: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, goto×3, while×2, return×1, do×1.
//  - Notable callees: FUN_0044cc30, FUN_00746910, FUN_007474c0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPiece
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxGeometryPiece_007474c0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint uVar6;

  int unaff_EDI;

  uint local_4;

  

  uVar6 = *(uint *)(in_EAX + 4);

  local_4 = *(int *)(in_EAX + 8) - 8;

joined_r0x007474d2:

  if (uVar6 == local_4) {

    local_4 = local_4 & 0xffffff00;

    iVar5 = *(int *)(unaff_EDI + 8) + -8;

    FUN_0044cc30(*(int *)(unaff_EDI + 4),iVar5,iVar5 - *(int *)(unaff_EDI + 4) >> 3,local_4);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = 0;

    FUN_00746910();

    return 0;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 8);

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_EDI + 4);

  puVar1 = puVar2 + -2;

  if (puVar4 != puVar1) {

    do {

      if ((*(char *)((int)puVar4 + 6) == *(char *)(uVar6 + 6)) &&

         (puVar3 = puVar4, *(char *)((int)puVar4 + 7) == *(char *)(uVar6 + 7)))

      goto joined_r0x00747500;

      puVar4 = puVar4 + 2;

    } while (puVar4 != puVar1);

  }

  goto LAB_0074751d;

joined_r0x00747500:

  while (puVar3 = puVar3 + 2, puVar3 != puVar2) {

    *puVar4 = *puVar3;

    puVar4[1] = puVar3[1];

    puVar4 = puVar4 + 2;

  }

  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + -8;

LAB_0074751d:

  uVar6 = uVar6 + 8;

  goto joined_r0x007474d2;

}
