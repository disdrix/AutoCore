// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_007fc0b0, FUN_007fde80, FUN_00861c10, FUN_00919a00.
//  - Strings: "Lost Connection To Server!".
//  - Return sites: 2.

// =============================================================================
// Named_Lost_Connection_To_Server_00919a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00919a00
// Address:   0x00919a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Lost Connection To Server!"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Lost_Connection_To_Server_00919a00(float param_1)



{

  float fVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  float10 fVar5;

  

  if ((DAT_00d1b968 != (int *)0x0) && (iVar4 = FUN_007fc0b0(), iVar4 == 0)) {

    cVar3 = (**(code **)(*DAT_00d1b968 + 0x3d8))();

    if ((cVar3 == '\0') || (cVar3 = FUN_00861c10(), cVar3 == '\0')) {

      FUN_007fde80("Lost Connection To Server!",0,0x3e4ccccd,0x3f000000,2);

      DAT_00d1b968[0x146] = -3;

      DAT_00d1b968[0x147] = -1;

    }

    else if ((DAT_00d1b968[0x146] == -3) && (DAT_00d1b968[0x147] == -1)) {

      fVar1 = (float)DAT_00d1b968[0x148];

      fVar5 = (float10)(**(code **)(*DAT_00d1b968 + 0xf4))();

      piVar2 = DAT_00d1b968;

      DAT_00d1b968[0x149] = (int)(float)fVar5;

      piVar2[0x148] = (int)(fVar1 + param_1);

      return;

    }

  }

  return;

}
