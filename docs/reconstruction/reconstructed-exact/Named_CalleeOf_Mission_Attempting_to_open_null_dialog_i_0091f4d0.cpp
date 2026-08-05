// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0091f4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f4d0
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x0091f4d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper. Evidence string: "You cannot afford the transfer fee!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You cannot afford the transfer fee!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: CONCAT44, FUN_0040ccb0, FUN_007a69d0, FUN_007a6de0, FUN_008f8200, FUN_0091f1f0, FUN_0091f4d0, block.
//  - Strings: "You cannot afford the transfer fee!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x0091f536) */



void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0091f4d0(void)



{

  uint32_t /* width from decompiler */ uVar1;

  longlong lVar2;

  

  FUN_007a69d0();

  if (((DAT_00d1b6d8 != 0) && (DAT_00d1b644 != 0)) && (DAT_00d1b8c0 != 0)) {

    if ((*(int *)(DAT_00d1b8c0 + 0x544) == *(int *)(DAT_00d1b644 + 0xfc)) ||

       (lVar2 = FUN_0040ccb0(),

       lVar2 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                         (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728)),

                         *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728)))) {

      FUN_0091f1f0(2);

    }

    else {

      uVar1 = FUN_007a6de0("You cannot afford the transfer fee!",0xffffffff);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar1,0);

        return;

      }

    }

  }

  return;

}
