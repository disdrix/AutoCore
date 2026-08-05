// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b1cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b1cb0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004b1cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: return×7, if×6.
//  - Notable callees: FUN_004b0d60, FUN_004b1cb0, FUN_007a2410, FUN_007a2450, FUN_007a2490, FUN_007a24c0, FUN_007a24f0, FUN_007a2520.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004b1cb0(int *param_1)



{

  byte bVar1;

  int iVar2;

  int local_44;

  int local_40;

  int local_3c;

  uint8_t local_34 [16];

  int local_24;

  int local_20;

  int local_1c;

  int local_18;

  int local_14;

  float local_c;

  float local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_44 = param_1[0x5e];

  local_40 = param_1[0x5f];

  local_3c = param_1[0x60];

  FUN_004b0d60(local_34,param_1[0x20]);

  iVar2 = *param_1;

  local_24 = param_1[0xd];

  local_c = *(float *)(iVar2 + 0x8bc) * (float)param_1[4];

  local_8 = *(float *)(iVar2 + 0x8bc) * (float)param_1[6];

  local_1c = param_1[0x61];

  local_18 = param_1[0x62];

  local_14 = param_1[99];

  local_20 = param_1[0xc];

  local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x8f4);

  if (*(char *)((int)param_1 + 0x241) != '\0') {

    if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {

      FUN_007a24f0(&local_44);

      return;

    }

    FUN_007a24c0(&local_44);

    return;

  }

  bVar1 = *(byte *)(iVar2 + 0x98a);

  if ((bVar1 & 2) != 0) {

    FUN_007a2550(&local_44);

    return;

  }

  if ((bVar1 & 4) != 0) {

    FUN_007a2450(&local_44);

    return;

  }

  if ((bVar1 & 8) != 0) {

    FUN_007a2410(&local_44);

    return;

  }

  if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {

    FUN_007a2520(&local_44);

    return;

  }

  FUN_007a2490(&local_44);

  return;

}
