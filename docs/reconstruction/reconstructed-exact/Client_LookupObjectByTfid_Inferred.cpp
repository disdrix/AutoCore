// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, Client_LookupObjectByTfid_Inferred, Parameters, coidHi, coidLo, globalFlag.
//  - Return sites: 2.

// =============================================================================
// Client_LookupObjectByTfid_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bb0a0
// Address:   0x004bb0a0  (autoassault.exe, image base 0x400000)
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

/* Client_LookupObjectByTfid_Inferred - resolve world object by TFID.

   

   Parameters (INFERRED from CharacterLevel dispatch):

     globalFlag (byte), coidLo (uint), coidHi (uint)

   Returns: object* or null.

   

   Called from Client_RecvCharacterLevel before ApplyCharacterLevelPacket vfunc. */



void * __cdecl Client_LookupObjectByTfid_Inferred(byte bGlobal,uint nCoidLo,uint nCoidHi)



{

  int *piVar1;

  void *pvVar2;

  undefined3 in_stack_00000005;

  

  piVar1 = (int *)CVOGReaction_ResolveObjectTarget(_bGlobal,nCoidLo,nCoidHi);

  if (piVar1 != (int *)0x0) {

    pvVar2 = (void *)(**(code **)(*piVar1 + 0x1dc))();

    return pvVar2;

  }

  return (void *)0x0;

}
