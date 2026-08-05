// =============================================================================
// FUN_004aac50
// -----------------------------------------------------------------------------
// Stable ID: aa_004aac50
// Address:   0x004aac50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004aac50 @ 0x004aac50
// Stable ID: aa_004aac50
// Embedded strings (evidence for future rename):
//   - "NDDiffTerrainLayered.fx"
//   - "DiffuseTexture"
//   - "fEdgeMaxX"
//   - "fEdgeMaxZ"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31×2, FUN_00442640×2, FUN_00989e00×2, FUN_004a8fd0, FUN_004aac50, FUN_0096ef70, FUN_0096efd0, FUN_0096f3e0.
//  - Strings: "NDDiffTerrainLayered.fx"; "DiffuseTexture"; "fEdgeMaxX"; "fEdgeMaxZ".
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

void __fastcall FUN_004aac50(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_150;

  void *local_14c;

  float local_148;

  float local_144;

  uint8_t local_140 [4];

  undefined **local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint8_t local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a12e0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_14c = operator_new(8);

  local_4 = 0;

  if (local_14c == (void *)0x0) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_0096f530();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x394) = uVar1;

  local_4 = 0xffffffff;

  FUN_00989e00(local_140,"NDDiffTerrainLayered.fx");

  FUN_009701d0(local_140);

  FUN_004a8fd0(*(uint8_t *)(param_1 + 0x1c),local_110);

  local_13c = &PTR_FUN_009caec8;

  local_138 = 0;

  local_134 = 0;

  local_130 = 0;

  local_12c = 0x101;

  local_128 = 1;

  local_124 = 0;

  local_120 = DAT_00aaa688;

  local_11c = 0;

  local_118 = 1;

  local_4 = 1;

  local_114 = 6;

  FUN_0096ef70();

  local_4 = CONCAT31(local_4._1_3_,2);

  FUN_00989e00(&local_14c,local_110);

  iVar2 = FUN_0096f3e0(&local_14c,&local_13c);

  if (-1 < iVar2) {

    FUN_00970140("DiffuseTexture",local_150);

    local_148 = (float)*(int *)(param_1 + 0x10) * *(float *)(param_1 + 0x18);

    local_144 = (float)*(int *)(param_1 + 0x14) * *(float *)(param_1 + 0x18);

    FUN_00442640("fEdgeMaxX",&local_148);

    FUN_00442640("fEdgeMaxZ",&local_144);

    *(uint8_t *)(param_1 + 0x398) = 1;

  }

  local_4 = CONCAT31(local_4._1_3_,1);

  FUN_0096efd0();

  ExceptionList = local_c;

  return;

}
