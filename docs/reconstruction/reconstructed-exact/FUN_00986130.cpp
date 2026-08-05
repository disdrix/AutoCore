// =============================================================================
// FUN_00986130
// -----------------------------------------------------------------------------
// Stable ID: aa_00986130
// Address:   0x00986130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00986130 @ 0x00986130
// Stable ID: aa_00986130
// Embedded strings (evidence for future rename):
//   - "Light Managers has %d still allocated at shutdown."
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManagerFactory.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, for×2.
//  - Notable callees: FUN_0074e590×2, FUN_0076cec0, FUN_00986130, vog_LogMessage.
//  - Strings: "Light Managers has %d still allocated at shutdown.".
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

void FUN_00986130(void)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  int local_4;

  

  if ((*(int *)(unaff_ESI + 4) != 0) &&

     (iVar2 = *(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 2, iVar2 != 0)) {

    uVar3 = FUN_0076cec0(&local_4,"Light Managers has %d still allocated at shutdown.",iVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightManagerFactory.cpp",0x73,

                   2,uVar3);

    for (puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4); puVar4 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

        puVar4 = puVar4 + 1) {

      pvVar1 = (void *)*puVar4;

      if (pvVar1 != (void *)0x0) {

        FUN_0074e590(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

    }

    if (*(void **)(unaff_ESI + 4) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(unaff_ESI + 4));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = 0;

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x14);

  if ((puVar4 != (uint32_t /* width from decompiler */ *)0x0) &&

     (local_4 = *(int *)(unaff_ESI + 0x18) - (int)puVar4 >> 2, local_4 != 0)) {

    for (; puVar4 != *(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x18); puVar4 = puVar4 + 1) {

      pvVar1 = (void *)*puVar4;

      if (pvVar1 != (void *)0x0) {

        FUN_0074e590(pvVar1);

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

    }

    if (*(void **)(unaff_ESI + 0x14) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(unaff_ESI + 0x14));

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = 0;

  }

  return;

}
