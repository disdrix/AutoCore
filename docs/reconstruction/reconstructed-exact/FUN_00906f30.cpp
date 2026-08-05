// =============================================================================
// FUN_00906f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00906f30
// Address:   0x00906f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00906f30 @ 0x00906f30
// Stable ID: aa_00906f30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00906f30.
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

uint __fastcall FUN_00906f30(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  char cVar4;

  uint uVar5;

  int *unaff_ESI;

  

  cVar4 = (**(code **)(*unaff_ESI + 0x3d8))(param_1);

  if ((((cVar4 != '\0') && (unaff_ESI[0x1a7] != 0)) && (unaff_ESI[0x1a8] != 0)) &&

     ((unaff_ESI[0x1a9] != 0 && (unaff_ESI[0x1aa] != 0)))) {

    piVar1 = (int *)unaff_ESI[0x1a8];

    piVar2 = (int *)unaff_ESI[0x1a9];

    piVar3 = (int *)unaff_ESI[0x1aa];

    cVar4 = (**(code **)(*(int *)unaff_ESI[0x1a7] + 0x3bc))();

    uVar5 = (uint)(cVar4 != '\0');

    cVar4 = (**(code **)(*piVar1 + 0x3bc))();

    uVar5 = uVar5 | -(uint)(cVar4 != '\0') & 2;

    cVar4 = (**(code **)(*piVar2 + 0x3bc))();

    uVar5 = uVar5 | -(uint)(cVar4 != '\0') & 4;

    cVar4 = (**(code **)(*piVar3 + 0x3bc))();

    return uVar5 & 0xff | -(uint)(cVar4 != '\0') & 8;

  }

  return 0xf;

}
