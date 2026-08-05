// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: Client_RefreshLocalCharacterLevelUi, clonebase.
//  - Return sites: 1.

// =============================================================================
// Client_RefreshLocalCharacterLevelUi
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f4d0
// Address:   0x0092f4d0  (autoassault.exe, image base 0x400000)
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

/* Client_RefreshLocalCharacterLevelUi - after CharacterLevel applies to local player,

   refresh level/rank UI fields from character clonebase (not money itself).

   Called from Client_RecvCharacterLevel when packet TFID matches local character. */



void Client_RefreshLocalCharacterLevelUi(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 0xe98);

  if (iVar1 != 0) {

    *(uint *)(unaff_ESI + 0xeec) =

         (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xac + iVar1) + 0x3c)

                        + 0x531);

    uVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x27c))();

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xee4) = uVar2;

    *(uint *)(unaff_ESI + 0xee8) =

         (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0xe98) + 4) + 4) +

                                           0xac + *(int *)(unaff_ESI + 0xe98)) + 0x3c) + 0x532);

  }

  return;

}
