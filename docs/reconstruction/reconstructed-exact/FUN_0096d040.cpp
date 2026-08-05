// =============================================================================
// FUN_0096d040
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d040
// Address:   0x0096d040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d040 @ 0x0096d040
// Stable ID: aa_0096d040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_0096cad0, FUN_0096d040.
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

uint32_t /* width from decompiler */ __fastcall FUN_0096d040(int param_1)



{

  int *in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EBX;

  

  if (unaff_EBX == *(int *)(param_1 + 0x34)) {

    if ((*(byte *)(param_1 + 0x2d) & 0x40) == 0) {

      if ((*in_EAX <= *(int *)(param_1 + 0x1c)) && (*(int *)(param_1 + 0x1c) / 2 < *in_EAX)) {

        if ((in_EAX[1] <= *(int *)(param_1 + 0x20)) && (*(int *)(param_1 + 0x20) / 2 < in_EAX[1])) {

          return 0;

        }

      }

    }

    else if ((*in_EAX == *(int *)(param_1 + 0x1c)) && (in_EAX[1] == *(int *)(param_1 + 0x20))) {

      return 0;

    }

  }

  uVar1 = FUN_0096cad0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x24),*in_EAX,in_EAX[1],unaff_EBX,

                       *(uint32_t /* width from decompiler */ *)(param_1 + 0x30),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

  return uVar1;

}
