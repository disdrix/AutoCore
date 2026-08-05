// =============================================================================
// FUN_008b5a40
// -----------------------------------------------------------------------------
// Stable ID: aa_008b5a40
// Address:   0x008b5a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b5a40 @ 0x008b5a40
// Stable ID: aa_008b5a40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0085d970, FUN_008b5a40.
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

void FUN_008b5a40(void)



{

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  uint8_t local_104 [260];

  

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x510) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x514) = 0xffffffff;

  if (*(int **)(unaff_ESI + 0x570) != (int *)0x0) {

    if (unaff_EDI == 0) {

      (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x58))();

      (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x15c))();

    }

    else {

      FUN_0085d970();

      iVar1 = **(int **)(unaff_ESI + 0x570);

      (**(code **)(iVar1 + 0x2c8))();

      (**(code **)(iVar1 + 0x50))(local_104);

      (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x15c))(0,&stack0xfffffeec);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x510) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x160);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x514) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x164);

    }

    (**(code **)(**(int **)(unaff_ESI + 0x570) + 0x34c))();

  }

  return;

}
