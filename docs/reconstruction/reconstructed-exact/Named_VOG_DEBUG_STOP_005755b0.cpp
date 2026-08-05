// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_00418d70, FUN_00520330, FUN_005749d0, FUN_005755b0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_005755b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005755b0
// Address:   0x005755b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_005755b0(int param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  uint *puVar4;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (3 < (int)((uint)*(byte *)(param_1 + 0x1d8) + *(int *)(param_1 + 0x1e4))) {

    return 0;

  }

  cVar2 = FUN_005749d0(param_2);

  if (cVar2 == '\0') {

    iVar3 = 0;

    puVar4 = (uint *)(param_1 + 0x198);

    do {

      if ((*puVar4 & puVar4[1]) == 0xffffffff) {

        iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

        *(uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + 0x198 + param_1) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + param_2);

        *(uint32_t /* width from decompiler */ *)(iVar3 * 0x10 + 0x19c + param_1) = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_2);

        *(int *)((iVar3 + 0x1a) * 0x10 + param_1) = param_2;

        FUN_00520330(param_1);

        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);

        local_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + param_2);

        local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + param_2);

        FUN_00418d70(&local_8);

        *(char *)(param_1 + 0x1d8) = *(char *)(param_1 + 0x1d8) + '\x01';

        return 1;

      }

      iVar3 = iVar3 + 1;

      puVar4 = puVar4 + 4;

    } while (iVar3 < 4);

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  return 0;

}
