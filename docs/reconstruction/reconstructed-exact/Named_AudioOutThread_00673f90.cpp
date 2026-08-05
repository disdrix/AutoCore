// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1.
//  - Notable callees: FUN_00673f90, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Unable to set 3d listener params.".
//  - Return sites: 2.

// =============================================================================
// Named_AudioOutThread_00673f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00673f90
// Address:   0x00673f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "AudioOutThread"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_AudioOutThread_00673f90(int param_1,void *param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ local_40 [5];

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  

  pvVar1 = param_2;

  if (*(int *)(param_1 + 0x158) == 2) {

    puVar4 = local_40;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    local_40[0] = 0x40;

    (**(code **)(**(int **)(param_1 + 0x15c) + 0xc))(*(int **)(param_1 + 0x15c),local_40);

    local_40[0] = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 4);

    local_40[1] = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8);

    uStack_2c = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0xc);

    uStack_28 = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x10);

    uStack_24 = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x14);

    uStack_20 = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x18);

    uStack_1c = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x1c);

    uStack_18 = *(uint32_t /* width from decompiler */ *)((int)pvVar1 + 0x20);

    iVar3 = (**(code **)(**(int **)(param_1 + 0x15c) + 0x28))

                      (*(int **)(param_1 + 0x15c),&stack0xffffffb8,0);

    if (iVar3 < 0) {

      uVar2 = FUN_0076cec0(&param_2,"Unable to set 3d listener params.");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\AudioOutThread.cpp"

                     ,0x2d3,2,uVar2);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
