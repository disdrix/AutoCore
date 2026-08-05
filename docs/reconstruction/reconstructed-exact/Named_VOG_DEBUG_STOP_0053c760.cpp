// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, for×1.
//  - Notable callees: FUN_007a4480×3, CNDHash_LookupByKey×2, FUN_00537d30, FUN_0053ada0, FUN_0053c760.
//  - Strings: "HashError:insert, already locked for traversal"; "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 5.

// =============================================================================
// Named_VOG_DEBUG_STOP_0053c760
// -----------------------------------------------------------------------------
// Stable ID: aa_0053c760
// Address:   0x0053c760  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_0053c760(void *param_1,uint param_2,int param_3,char param_4)



{

  int iVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_3 == 0) {

    return 0x80004003;

  }

  if (*(char *)((int)param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:insert, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (param_4 != '\0') {

    pvVar2 = CNDHash_LookupByKey(param_1,param_2);

    if (pvVar2 != (void *)0x0) {

      return 1;

    }

  }

  pvVar2 = CNDHash_LookupByKey(param_1,param_2);

  if (pvVar2 != (void *)0x0) {

    FUN_007a4480(0,"Duplicate hash insert %u, failing out",param_2);

    return 0x80004005;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0053ada0();

  puVar3[3] = 0;

  *puVar3 = &PTR_FUN_009cefec;

  puVar3[5] = 0;

  puVar3[6] = 0;

  *(uint8_t *)(puVar3 + 1) = 0;

  puVar3[2] = param_3;

  puVar3[4] = param_2;

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x10) + (*(uint *)((int)param_1 + 8) & param_2) * 4);

  puVar3[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

  *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar3;

  FUN_00537d30();

  if (*(int *)((int)param_1 + 0x18) != 0) {

    *(uint32_t /* width from decompiler */ **)(*(int *)((int)param_1 + 0x18) + 0x14) = puVar3;

    puVar3[5] = 0;

    puVar3[6] = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0x18);

    *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;

    *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x18) = puVar3;

    return 0;

  }

  *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x18) = puVar3;

  *(uint32_t /* width from decompiler */ **)((int)param_1 + 0x14) = puVar3;

  puVar3[6] = 0;

  puVar3[5] = 0;

  *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + 1;

  return 0;

}
