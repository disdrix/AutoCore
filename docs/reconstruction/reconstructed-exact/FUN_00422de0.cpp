// =============================================================================
// FUN_00422de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00422de0
// Address:   0x00422de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00422de0 @ 0x00422de0
// Stable ID: aa_00422de0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, for×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0041d7b0, FUN_00422de0, FUN_00437cd0.
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

/* WARNING: Restarted to delay deadcode elimination for space: stack */



int FUN_00422de0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  int *unaff_ESI;

  uint uVar2;

  int local_4;

  

  iVar1 = 0;

  if (unaff_ESI[1] != 0) {

    FUN_00437cd0();

    iVar1 = (**(code **)*in_EAX)();

    if ((-1 < iVar1) && (uVar2 = 0, unaff_ESI[1] != 0)) {

      do {

        (**(code **)(local_4 + 0x18))(&local_4,*(uint32_t /* width from decompiler */ *)(*unaff_ESI + uVar2 * 8),0);

        uVar2 = uVar2 + 1;

      } while (uVar2 < (uint)unaff_ESI[1]);

    }

    unaff_ESI[1] = 0;

    operator_delete__((void *)*unaff_ESI);

    *unaff_ESI = 0;

    FUN_0041d7b0();

  }

  return iVar1;

}
