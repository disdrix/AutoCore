// =============================================================================
// FUN_009730e0
// -----------------------------------------------------------------------------
// Stable ID: aa_009730e0
// Address:   0x009730e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009730e0 @ 0x009730e0
// Stable ID: aa_009730e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_00435b40×2, FUN_0076ed20×2, FUN_00972e50×2, FUN_009730e0.
//  - Return sites: 4.

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

int __fastcall FUN_009730e0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  

  if (*(char *)(param_1 + 0xb8) == '\0') {

    if ((*(byte *)(param_1 + 0xbc) & 1) != 0) {

      FUN_00972e50();

      FUN_00435b40();

      *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;

      return param_1 + 0x40;

    }

    FUN_00435b40();

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;

    return param_1 + 0x40;

  }

  if ((*(byte *)(param_1 + 0xbc) & 1) != 0) {

    uVar1 = FUN_00972e50();

    FUN_0076ed20(param_1 + 0x40,uVar1);

    *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;

    return param_1 + 0x40;

  }

  FUN_0076ed20(param_1 + 0x40,param_1);

  *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) & 0xfffffffd;

  return param_1 + 0x40;

}
