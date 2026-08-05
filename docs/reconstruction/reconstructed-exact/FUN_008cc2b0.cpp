// =============================================================================
// FUN_008cc2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_008cc2b0
// Address:   0x008cc2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cc2b0 @ 0x008cc2b0
// Stable ID: aa_008cc2b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_008cc2b0.
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

void FUN_008cc2b0(void)



{

  int iVar1;

  char cVar2;

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int *piVar5;

  

  cVar2 = (**(code **)(*in_EAX + 0x3d8))();

  if (cVar2 != '\0') {

    piVar4 = in_EAX + 0x167;

    piVar5 = &DAT_00d1b6dc;

    do {

      if ((*piVar5 != 0) && (*piVar4 != 0)) {

        iVar1 = *(int *)*piVar4;

        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(*piVar5 + 4) + 4) + 4 + *piVar5) + 0x160))

                          (1,0);

        (**(code **)(iVar1 + 0x1d8))(uVar3);

        (**(code **)(*(int *)*piVar4 + 0x34c))();

      }

      piVar5 = piVar5 + 1;

      piVar4 = piVar4 + 1;

    } while ((int)piVar5 < 0xd1b70c);

  }

  return;

}
