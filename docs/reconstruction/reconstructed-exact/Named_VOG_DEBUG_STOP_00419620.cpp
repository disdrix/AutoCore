// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, for×1.
//  - Notable callees: FUN_007a4480×3, FUN_00419b40×2, FUN_00419620, FUN_00419ad0, FUN_00419bd0.
//  - Strings: "HashError:insert, already locked for traversal"; "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 5.

// =============================================================================
// Named_VOG_DEBUG_STOP_00419620
// -----------------------------------------------------------------------------
// Stable ID: aa_00419620
// Address:   0x00419620  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_00419620(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,int param_4,char param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_4 == 0) {

    return 0x80004003;

  }

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:insert, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (param_5 != '\0') {

    iVar1 = FUN_00419b40(param_2,param_3);

    if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {

      return 1;

    }

  }

  iVar1 = FUN_00419b40(param_2,param_3);

  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {

    FUN_007a4480(0,"Duplicate hash insert %u, failing out",param_2,param_3);

    return 0x80004005;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00419bd0();

  puVar2[4] = 0;

  puVar2[8] = 0;

  puVar2[9] = 0;

  *(uint8_t *)(puVar2 + 2) = 0;

  *puVar2 = &PTR_FUN_00a2c2bc;

  puVar2[3] = param_4;

  puVar2[6] = param_2;

  puVar2[7] = param_3;

  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4);

  puVar2[4] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

  *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar2;

  FUN_00419ad0();

  if (*(int *)(param_1 + 0x18) != 0) {

    *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x18) + 0x20) = puVar2;

    puVar2[8] = 0;

    puVar2[9] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

    return 0;

  }

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x14) = puVar2;

  puVar2[9] = 0;

  puVar2[8] = 0;

  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  return 0;

}
