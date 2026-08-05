// =============================================================================
// FUN_00804aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00804aa0
// Address:   0x00804aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00804aa0 @ 0x00804aa0
// Stable ID: aa_00804aa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0048a193, FUN_0048a1d1, FUN_0048a1f8, FUN_0048a217, FUN_00804aa0.
//  - Return sites: 3.

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

void FUN_00804aa0(void)



{

  int iVar1;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14 [5];

  

  if (unaff_ESI[0x21] == -1) {

    iVar1 = FUN_0048a193(unaff_ESI + 0x27);

    if (iVar1 != 0) {

      return;

    }

    unaff_ESI[0x21] = unaff_ESI[0x2c];

    unaff_ESI[0x22] = -1;

  }

  if (unaff_ESI[0x22] != -1) {

    FUN_0048a217(unaff_ESI[0x22]);

    unaff_ESI[0x22] = -1;

  }

  local_24 = 0;

  local_20 = 0;

  local_1c = 0;

  local_18 = 0;

  iVar1 = FUN_0048a1d1(unaff_ESI[0x21],0,&local_24);

  if (iVar1 == 0) {

    local_14[0] = unaff_ESI[0x21];

    local_14[2] = 0;

    local_14[3] = 0;

    local_14[4] = 0;

    local_14[1] = 0;

    iVar1 = FUN_0048a1f8(local_14);

    if (iVar1 == 0) {

      unaff_ESI[0x22] = local_14[4];

      unaff_ESI[0x26] = 0;

    }

  }

  else if (iVar1 != 0x103) {

    (**(code **)(*unaff_ESI + 0x84))(unaff_ESI[0x22]);

    (**(code **)(*unaff_ESI + 0x88))(unaff_ESI[0x21]);

    return;

  }

  return;

}
