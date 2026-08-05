// =============================================================================
// FUN_0073ae10
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ae10
// Address:   0x0073ae10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ae10 @ 0x0073ae10
// Stable ID: aa_0073ae10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: CVOGReaction_FailMissionNotify×2, FUN_0073ae10.
//  - Return sites: 1.

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

void FUN_0073ae10(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puStack_1c;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009af97b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00aa4384;

  local_4 = 0;

  uVar1 = param_1[0x45];

  puStack_1c = &local_10;

  local_10 = uVar1;

  CVOGReaction_FailMissionNotify();

  piVar3 = (int *)*DAT_00d1f044;

  puStack_1c = (uint32_t /* width from decompiler */ *)0x0;

  (**(code **)(*piVar3 + 0xd4))(piVar3,uVar1);

  puVar2 = (uint32_t /* width from decompiler */ *)param_1[0x46];

  puStack_1c = puVar2;

  CVOGReaction_FailMissionNotify(&puStack_1c);

  (**(code **)(*(int *)*DAT_00d1f044 + 0xd4))((int *)*DAT_00d1f044,puVar2,0);

  *param_1 = &PTR_LAB_009d45f0;

  ExceptionList = piVar3;

  return;

}
