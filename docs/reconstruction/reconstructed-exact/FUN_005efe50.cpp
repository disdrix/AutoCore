// =============================================================================
// FUN_005efe50
// -----------------------------------------------------------------------------
// Stable ID: aa_005efe50
// Address:   0x005efe50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005efe50 @ 0x005efe50
// Stable ID: aa_005efe50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005ef1d0, FUN_005ef780, FUN_005efcc0, FUN_005efe50.
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

uint32_t /* width from decompiler */ FUN_005efe50(uint32_t /* width from decompiler */ param_1,float param_2,float *param_3)



{

  int extraout_EDX;

  float fVar1;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (param_2 <= 0.0) {

    return 1;

  }

  FUN_005efcc0();

  FUN_005ef780(param_1);

  fVar1 = param_2 / DAT_00d027b0;

  *param_3 = DAT_00d027b0;

  FUN_005ef1d0(param_2,fVar1);

  *(float *)(extraout_EDX + 0x10) = local_50 - local_60;

  *(float *)(extraout_EDX + 0x14) = local_4c - local_5c;

  *(float *)(extraout_EDX + 0x18) = local_48 - local_58;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x1c) = local_44;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x20) = local_40;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x24) = local_3c;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x28) = local_38;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x2c) = local_34;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x30) = local_30;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x34) = local_2c;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x38) = local_28;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x3c) = local_24;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x40) = local_20;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x44) = local_1c;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x48) = local_18;

  *(uint32_t /* width from decompiler */ *)(extraout_EDX + 0x4c) = local_14;

  *(float *)(extraout_EDX + 4) = param_2;

  return 0;

}
