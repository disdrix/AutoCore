// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, for×2, if×1.
//  - Notable callees: FUN_00678c50, FUN_0076cec0, vog_LogMessage.
//  - Strings: "Codec cannot decode".
//  - Return sites: 2.

// =============================================================================
// Named_ClearCodec_00678c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00678c50
// Address:   0x00678c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "ClearCodec"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_ClearCodec_00678c50(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (*(int *)(param_1 + 4) != 1) {

    uVar1 = FUN_0076cec0(&param_4,"Codec cannot decode");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ClearCodec.cpp"

                   ,0x28,3,uVar1);

    return 0xffffffff;

  }

  puVar3 = param_3;

  for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *param_2 = *puVar3;

    puVar3 = puVar3 + 1;

    param_2 = param_2 + 1;

  }

  for (uVar2 = param_4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint8_t *)param_2 = *(uint8_t *)puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

  }

  *(char *)(param_1 + 0x2c) = (char)((*(byte *)((int)param_3 + (param_4 - 1)) + 0x7f) / 2);

  return 0;

}
