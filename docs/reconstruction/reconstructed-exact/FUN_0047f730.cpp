// =============================================================================
// FUN_0047f730
// -----------------------------------------------------------------------------
// Stable ID: aa_0047f730
// Address:   0x0047f730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047f730 @ 0x0047f730
// Stable ID: aa_0047f730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00477ea0×2, FUN_00477790, FUN_00477ac0, FUN_0047f730.
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

int __fastcall

FUN_0047f730(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  uint8_t local_38 [12];

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  

  local_28 = *param_3;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_2c = param_2;

  iVar1 = FUN_00477790(param_4,8,8,0,0x38);

  if (iVar1 == 0) {

    iVar2 = FUN_00477ac0(local_38,4);

    if (iVar2 == 1) {

      *param_3 = local_24;

      iVar1 = FUN_00477ea0();

    }

    else {

      FUN_00477ea0();

      iVar1 = -5;

      if (iVar2 != 0) {

        return iVar2;

      }

    }

  }

  return iVar1;

}
