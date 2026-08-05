// =============================================================================
// InventoryGrid_SetOwnerFlag_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00570600
// Address:   0x00570600  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
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

/* InventoryGrid_SetOwnerFlag_Inferred — write int flag at grid+0x4.
   
   Parameters: this grid; nFlag (cargo path always passes 1 after ctor).
   Returns: void.
   
   Trivial setter. Name INFERRED from cargo create call site only. */

void __thiscall InventoryGrid_SetOwnerFlag_Inferred(void *this,int nFlag)

{
  *(int *)((int)this + 4) = nFlag;
  return;
}
