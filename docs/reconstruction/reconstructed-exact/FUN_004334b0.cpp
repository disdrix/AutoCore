// =============================================================================
// FUN_004334b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004334b0
// Address:   0x004334b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004334b0 @ 0x004334b0
// Stable ID: aa_004334b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CONCAT11, CONCAT12, CONCAT13, FUN_004334b0.
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

void __thiscall FUN_004334b0(int param_1,byte param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = *(int *)(param_1 + 4);

  local_4 = 0;

  if (iVar2 != 0) {

    if (*(uint *)(param_1 + 0x28) == 0) {

      *unaff_ESI = 0;

      return;

    }

    if (*(uint *)(param_1 + 0x28) <= (uint)param_2) {

      *unaff_ESI = 0;

      return;

    }

    iVar1 = (uint)param_2 * 4;

    local_4 = CONCAT13(*(uint8_t *)(iVar1 + 0x2b + iVar2),

                       CONCAT12(*(uint8_t *)(iVar1 + 0x2a + iVar2),

                                CONCAT11(*(uint8_t *)(iVar1 + 0x29 + iVar2),

                                         *(uint8_t *)(iVar1 + 0x28 + iVar2))));

  }

  *unaff_ESI = local_4;

  return;

}
