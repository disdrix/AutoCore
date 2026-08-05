// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_007a4480, FUN_008073b0, FUN_009339a0, FUN_00945370, _exit.
//  - Strings: "\n\n************ Starting ShutDown on Client\n\n".
//  - Return sites: 2.

// =============================================================================
// Named_Starting_ShutDown_on_Client_00945370
// -----------------------------------------------------------------------------
// Stable ID: aa_00945370
// Address:   0x00945370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "

************ Starting ShutDown on Client

"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Starting_ShutDown_on_Client_00945370(char param_1)



{

  char cVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uStack_8;

  uint8_t uStack_4;

  

  FUN_007a4480(0xffffffff,"\n\n************ Starting ShutDown on Client\n\n");

  if ((param_1 == '\0') && (*(int **)(in_EAX + 0xc7c) != (int *)0x0)) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0xc7c) + 8))();

    if ((cVar1 != '\0') && (*(int *)(in_EAX + 0xe98) != 0)) {

      uStack_4 = 1;

      uStack_8 = 0x801c;

      FUN_008073b0(8,&uStack_8);

      return;

    }

  }

  *(uint8_t *)(in_EAX + 0x13) = 0;

  FUN_009339a0();

                    /* WARNING: Subroutine does not return */

  _exit(0);

}
