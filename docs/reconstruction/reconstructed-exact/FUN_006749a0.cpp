// =============================================================================
// FUN_006749a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006749a0
// Address:   0x006749a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006749a0 @ 0x006749a0
// Stable ID: aa_006749a0
// Embedded strings (evidence for future rename):
//   - "No available audio stream for %d"
//   - "C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"
//   - "Assigning stream %d to player %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_006749a0, FUN_006773f0.
//  - Strings: "No available audio stream for %d"; "Assigning stream %d to player %d".
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

int __thiscall FUN_006749a0(int param_1,uint8_t param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  if (*(int *)(param_1 + 0x13c) == 0) {

    uVar4 = FUN_0076cec0(&param_2,"No available audio stream for %d",param_2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                   ,499,1,uVar4);

  }

  else {

    piVar3 = *(int **)(param_1 + 0x138);

    iVar1 = *(int *)(*piVar3 + 8);

    if (iVar1 != 0) {

      piVar2 = (int *)*piVar3;

      if (piVar2 != piVar3) {

        *(int *)piVar2[1] = *piVar2;

        *(int *)(*piVar2 + 4) = piVar2[1];

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar2);

      }

      piVar3 = (int *)FUN_006773f0(&param_2);

      *piVar3 = iVar1;

      uVar4 = FUN_0076cec0(&param_2,"Assigning stream %d to player %d",*(uint32_t /* width from decompiler */ *)(iVar1 + 0x68)

                           ,param_2);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                     ,0x1ee,1,uVar4);

      return iVar1;

    }

  }

  return 0;

}
