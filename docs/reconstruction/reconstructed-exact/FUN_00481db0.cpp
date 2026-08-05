// =============================================================================
// FUN_00481db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00481db0
// Address:   0x00481db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00481db0 @ 0x00481db0
// Stable ID: aa_00481db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0047a370×2, FUN_00478d60, FUN_00478f50, FUN_00481db0.
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

int __fastcall FUN_00481db0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint8_t local_38 [4];

  int local_34;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_28 = *unaff_EDI;

  local_18 = 0;

  local_14 = 0;

  local_2c = param_2;

  iVar1 = FUN_00478d60(0x38);

  if (iVar1 == 0) {

    iVar1 = FUN_00478f50(local_38,4);

    if (iVar1 != 1) {

      FUN_0047a370();

      if ((iVar1 != 2) && ((iVar1 != -5 || (local_34 != 0)))) {

        return iVar1;

      }

      return -3;

    }

    *unaff_EDI = local_24;

    iVar1 = FUN_0047a370();

  }

  return iVar1;

}
