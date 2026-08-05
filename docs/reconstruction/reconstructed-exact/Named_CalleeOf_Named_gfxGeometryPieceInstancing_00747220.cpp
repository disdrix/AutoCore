// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPieceInstancing_00747220
// -----------------------------------------------------------------------------
// Stable ID: aa_00747220
// Callee of Named_gfxGeometryPieceInstancing
// Address:   0x00747220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPieceInstancing: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00445fa0×2, FUN_0045f220×2, CONCAT13, CONCAT22, FUN_00747220.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPieceInstancing
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_gfxGeometryPieceInstancing_00747220(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *local_18;

  uint8_t local_14;

  uint8_t local_13;

  uint8_t local_12;

  uint8_t local_11;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  

  if ((*(int *)(unaff_ESI + 4) != 0) &&

     (*(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 3 != 0)) {

    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -8;

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

  puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_2 + 8) + -8);

  local_18 = puVar4;

  if (puVar3 != puVar4) {

    do {

      local_10 = *puVar3;

      local_c = puVar3[1];

      if (-1 < param_3) {

        uVar2 = (uint)local_10 >> 0x10;

        local_10 = CONCAT22((short)uVar2,(short)param_3);

      }

      if (-1 < param_4) {

        local_c = CONCAT13((char)param_4,(undefined3)local_c);

      }

      iVar1 = *(int *)(unaff_ESI + 4);

      if ((iVar1 == 0) ||

         ((uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 3) <=

          (uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 3))) {

        FUN_00445fa0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),&local_10);

      }

      else {

        iVar1 = *(int *)(unaff_ESI + 8);

        FUN_0045f220(local_18);

        *(int *)(unaff_ESI + 8) = iVar1 + 8;

        puVar4 = local_18;

      }

      puVar3 = puVar3 + 2;

    } while (puVar3 != puVar4);

  }

  iVar1 = *(int *)(unaff_ESI + 4);

  local_18 = (uint32_t /* width from decompiler */ *)0xff;

  local_14 = 0x11;

  local_13 = 0;

  local_12 = 0;

  local_11 = 0;

  if ((iVar1 != 0) &&

     ((uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 3) < (uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 3))

     ) {

    iVar1 = *(int *)(unaff_ESI + 8);

    FUN_0045f220(0xff);

    *(int *)(unaff_ESI + 8) = iVar1 + 8;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

    return 0;

  }

  FUN_00445fa0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),&local_18);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  return 0;

}
