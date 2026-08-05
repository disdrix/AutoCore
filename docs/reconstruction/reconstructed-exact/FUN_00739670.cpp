// =============================================================================
// FUN_00739670
// -----------------------------------------------------------------------------
// Stable ID: aa_00739670
// Address:   0x00739670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739670 @ 0x00739670
// Stable ID: aa_00739670
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp"
//   - "Error locking Source Vertex buffer in PrepareForSoftwareMorphing!"
//   - "Error locking Destination Vertex buffer in PrepareForSoftwareMorphing!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: block×4, FUN_00414a50×3, vog_LogMessage×2, FUN_00414c20, FUN_00440110, FUN_0044bfb0, FUN_007391c0, FUN_00739670.
//  - Strings: ",

                   0x28e,3,"; ",

                     0x29a,3,

                     ".
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

/* WARNING: Removing unreachable block (ram,0x007397c7) */

/* WARNING: Removing unreachable block (ram,0x007397cc) */

/* WARNING: Removing unreachable block (ram,0x0073977b) */

/* WARNING: Removing unreachable block (ram,0x00739780) */



void FUN_00739670(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int unaff_ESI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b2e73;

  local_c = ExceptionList;

  local_4 = 0;

  if (*(int *)(unaff_ESI + 0x14) == 0) {

    uVar4 = 0;

  }

  else {

    uVar4 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x14) + 0x18);

  }

  ExceptionList = &local_c;

  FUN_00414c20(uVar4,*(int *)(unaff_ESI + 0x14) + 0x24,9,0);

  iVar2 = *(int *)(unaff_ESI + 0x14);

  if ((*(int *)(iVar2 + 0x10) == 0) ||

     (iVar2 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x18),4),

     iVar2 == 0)) {

    FUN_00414a50();

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",

                   0x28e,3,"Error locking Source Vertex buffer in PrepareForSoftwareMorphing!");

  }

  else {

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      uVar4 = 0;

    }

    else {

      iVar1 = *(int *)(*(int *)(unaff_ESI + 0x14) + 0x10);

      if (iVar1 == 0) {

        uVar4 = 0;

      }

      else {

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 8);

      }

    }

    if (*(int *)(unaff_ESI + 0x14) == 0) {

      uVar3 = 0;

    }

    else {

      uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x14) + 0x18);

    }

    iVar2 = FUN_00440110(iVar2,uVar3,uVar4);

    if (iVar2 == -1) {

      FUN_00414a50();

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",

                     0x29a,3,

                     "Error locking Destination Vertex buffer in PrepareForSoftwareMorphing!");

    }

    else {

      FUN_00414a50();

      *(uint *)(unaff_ESI + 0xbc) = *(uint *)(unaff_ESI + 0xbc) | 1;

      FUN_0044bfb0();

      FUN_007391c0(unaff_ESI);

      *(uint *)(unaff_ESI + 0xbc) = *(uint *)(unaff_ESI + 0xbc) | 0x10;

    }

  }

  ExceptionList = local_c;

  return;

}
