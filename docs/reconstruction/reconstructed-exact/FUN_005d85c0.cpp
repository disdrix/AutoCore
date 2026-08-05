// =============================================================================
// FUN_005d85c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d85c0
// Address:   0x005d85c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d85c0 @ 0x005d85c0
// Stable ID: aa_005d85c0
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "ERROR: "
//   - "Server could not be created, please check that you platform supports sockets with the hkBa"
//   - " every frame"
//   - "Server created and will poll for new client(s) on port "
//   - "Server has already been created, only one server allowed per visual debugger instance"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×2.
//  - Notable callees: FUN_00631dc0×7, client×2, FUN_005d85c0, FUN_00631da0, FUN_00631e10, FUN_00631f80.
//  - Strings: "VisualDebugger: ["; "ERROR: "; " every frame"; "Server created and will poll for new client(s) on port ".
//  - Return sites: 4.

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

void __thiscall FUN_005d85c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  char *pcVar4;

  char *pcVar5;

  

  if (*(int *)(param_1 + 0x10) == 0) {

    piVar1 = (int *)(*(code *)PTR_FUN_00af4fe8)();

    *(int **)(param_1 + 0x10) = piVar1;

    if (piVar1 == (int *)0x0) {

      if (DAT_00d030ec < 0) {

        return;

      }

      pcVar4 = "VisualDebugger: [";

      (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

      FUN_00631dc0(pcVar4);

      pcVar4 = "ERROR: ";

      (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

      FUN_00631dc0(pcVar4);

      pcVar5 = 

      "Server could not be created, please check that you platform supports sockets with the hkBase library"

      ;

      pcVar4 = (char *)0x5d8682;

      (**(code **)(*DAT_00d030e0 + 4))

                ("Server could not be created, please check that you platform supports sockets with the hkBase library"

                 ,0x5d);

    }

    else {

      (**(code **)(*piVar1 + 0x18))(param_2);

      if (DAT_00d030ec < 1) {

        return;

      }

      pcVar4 = "VisualDebugger: [";

      (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

      FUN_00631dc0(pcVar4);

      pcVar5 = (char *)0x5d;

      pcVar4 = " every frame";

      pcVar3 = "Server created and will poll for new client(s) on port ";

      (**(code **)(*DAT_00d030e0 + 4))

                ("Server created and will poll for new client(s) on port ",param_2," every frame",

                 0x5d);

      FUN_00631dc0(pcVar3);

      FUN_00631e10(param_2);

    }

  }

  else {

    if (DAT_00d030ec < 0) {

      return;

    }

    pcVar4 = "VisualDebugger: [";

    (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

    FUN_00631dc0(pcVar4);

    pcVar4 = "ERROR: ";

    (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

    FUN_00631dc0(pcVar4);

    pcVar5 = "Server has already been created, only one server allowed per visual debugger instance"

    ;

    pcVar4 = (char *)0x5d86cd;

    (**(code **)(*DAT_00d030e0 + 4))

              ("Server has already been created, only one server allowed per visual debugger instance"

               ,0x5d);

  }

  FUN_00631dc0(pcVar4);

  uVar2 = FUN_00631da0(pcVar5);

  FUN_00631f80(uVar2);

  return;

}
