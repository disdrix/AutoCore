// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: Client_SetFirstTimeTipBit.
//  - Return sites: 1.

// =============================================================================
// Client_SetFirstTimeTipBit
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ff80
// Address:   0x0040ff80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* OR tip bit into FirstTimeFlags at character+0xD30.

   AL = tip id; EDX/param_2 = character object.

   Only for tip id < 0x80: flags[id>>5] |= 1<<(id&0x1f). */



void __fastcall Client_SetFirstTimeTipBit(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint *puVar1;

  byte in_AL;

  

  if (in_AL < 0x80) {

    puVar1 = (uint *)(param_2 + 0xd30 + (uint)(in_AL >> 5) * 4);

    *puVar1 = *puVar1 | 1 << (in_AL & 0x1f);

  }

  return;

}
