// =============================================================================
// FUN_0052dff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052dff0
// Address:   0x0052dff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052dff0 @ 0x0052dff0
// Stable ID: aa_0052dff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, for×1.
//  - Notable callees: FUN_00418b80×2, FUN_0052d0b0, FUN_0052dff0, FUN_00538ab0.
//  - Return sites: 3.

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

int __fastcall FUN_0052dff0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_214;

  int local_210;

  int local_20c;

  uint32_t /* width from decompiler */ local_208 [9];

  short local_1e2;

  

  iVar1 = *(int *)(param_1 + 0x594);

  local_214 = iVar1;

  piVar2 = (int *)FUN_00538ab0(&local_20c,&local_214);

  if (*piVar2 == DAT_00b045b4) {

    return 0;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(*piVar2 + 0x10);

  puVar5 = local_208;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  local_214 = iVar1;

  FUN_00418b80(&local_210,&local_214);

  local_20c = *(int *)(param_1 + 0x588);

  if (local_210 == local_20c) {

    local_214 = 0;

  }

  else {

    local_214 = *(int *)(local_210 + 0x14);

  }

  iVar3 = FUN_0052d0b0();

  iVar3 = iVar3 + local_214;

  local_210 = iVar1;

  FUN_00418b80(&local_214,&local_210);

  if ((local_214 != local_20c) && (0 < *(int *)(local_214 + 0x14))) {

    return (iVar3 + local_1e2 * 2) * 10;

  }

  return 100;

}
