// =============================================================================
// FUN_0067e2b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067e2b0
// Address:   0x0067e2b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067e2b0 @ 0x0067e2b0
// Stable ID: aa_0067e2b0
// Embedded strings (evidence for future rename):
//   - "received ephemeral packet out of sequence: seq %d."
//   - "C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp"
//   - "Session %lu: received ephemeral packet out of sequence: seq %d."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_0067c560, FUN_0067d980, FUN_0067e2b0.
//  - Strings: "received ephemeral packet out of sequence: seq %d.".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_0067e2b0(int param_1,uint *param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  puVar4 = param_2;

  iVar2 = param_1 + 0x114 + (uint)(byte)param_2[3] * 0x28;

  if ((*(char *)(param_1 + 0x134 + (uint)(byte)param_2[3] * 0x28) != '\0') &&

     (*(uint *)(iVar2 + 0x14) == param_2[1])) {

    *(uint8_t *)(iVar2 + 0x20) = 0;

    *(uint8_t *)(iVar2 + 0x18) = 0;

    *(int *)(param_1 + 0x2a18) = *(int *)(param_1 + 0x2a18) - *(int *)(*(int *)(iVar2 + 0x10) + 0xc)

    ;

    puVar3 = *(uint32_t /* width from decompiler */ **)(iVar2 + 0x10);

    piVar1 = puVar3 + 5;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = 0;

  }

  if (param_4 != 0) {

    if (*(uint *)(iVar2 + 8) < *puVar4) {

      *(uint8_t *)(iVar2 + 0x21) = 1;

      *(uint *)(iVar2 + 8) = *puVar4;

      FUN_0067d980((char)puVar4[3],param_3,param_4);

      FUN_0067c560((char)puVar4[3]);

      return 1;

    }

    uVar5 = FUN_0076cec0(&param_2,"received ephemeral packet out of sequence: seq %d.",*puVar4);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x42c,1,uVar5);

    uVar5 = FUN_0076cec0(&param_2,"Session %lu: received ephemeral packet out of sequence: seq %d.",

                         *(uint32_t /* width from decompiler */ *)(param_1 + 0x2a20),*puVar4);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",

                   0x42d,1,uVar5);

  }

  return 1;

}
