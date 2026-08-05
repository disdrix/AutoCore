// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×13, return×4.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_0066f910, FUN_006718d0, FUN_00673de0, FUN_0067b3e0.
//  - Strings: "Unable to cleanly close output thread."; "Unable to cleanly close input thread.".
//  - Return sites: 4.

// =============================================================================
// Named_ChatClientImpl_0066f910
// -----------------------------------------------------------------------------
// Stable ID: aa_0066f910
// Address:   0x0066f910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ChatClientImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_ChatClientImpl_0066f910(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (*(int **)(param_1 + 0x38) == (int *)0x0) {

    return 0xffffffff;

  }

  (**(code **)(**(int **)(param_1 + 0x38) + 0x10))(1);

  if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x38) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x38))(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint8_t *)(param_1 + 0x58) = 0;

  *(uint8_t *)(param_1 + 0x5a) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x17c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = 0;

  if (*(void **)(param_1 + 0x1bc) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x1bc));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c4) = 0;

  if (*(void **)(param_1 + 0x178) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x178));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = 0;

  }

  if (*(int *)(param_1 + 0x30) != 0) {

    FUN_00673de0();

    iVar1 = (**(code **)(**(int **)(param_1 + 0x30) + 8))(1000);

    if (iVar1 < 0) {

      uVar2 = FUN_0076cec0(&stack0xfffffff8,"Unable to cleanly close output thread.");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                     ,0x1ae,3,uVar2);

    }

    else {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x30) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x30))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

    }

  }

  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {

    iVar1 = (**(code **)(**(int **)(param_1 + 0x2c) + 8))(1000);

    if (iVar1 < 0) {

      uVar2 = FUN_0076cec0(&stack0xfffffff8,"Unable to cleanly close input thread.");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"

                     ,0x1ba,3,uVar2);

    }

    else {

      if (*(uint32_t /* width from decompiler */ **)(param_1 + 0x2c) != (uint32_t /* width from decompiler */ *)0x0) {

        (**(code **)**(uint32_t /* width from decompiler */ **)(param_1 + 0x2c))(1);

      }

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

    }

  }

  if (*(int *)(param_1 + 0x20c) != 0) {

    FUN_0067b3e0();

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 0x20c));

  }

  if (*(void **)(param_1 + 0x208) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x208));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x208) = 0;

  }

  FUN_006718d0();

  if (*(void **)(param_1 + 0x1f8) != (void *)0x0) {

    operator_delete__(*(void **)(param_1 + 0x1f8));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1f8) = 0;

  }

  (**(code **)(**(int **)(param_1 + 0x54) + 0x1c))();

  return 0;

}
