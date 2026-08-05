// =============================================================================
// FUN_006e8560
// -----------------------------------------------------------------------------
// Stable ID: aa_006e8560
// Address:   0x006e8560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e8560 @ 0x006e8560
// Stable ID: aa_006e8560
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063a190, FUN_006e8560.
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

void FUN_006e8560(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *local_80;

  int local_7c;

  uint32_t /* width from decompiler */ *local_78;

  int *local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[2];

  local_70 = *puVar1;

  local_6c = puVar1[1];

  local_68 = puVar1[2];

  local_64 = puVar1[3];

  local_60 = puVar1[4];

  local_5c = puVar1[5];

  local_58 = puVar1[6];

  iVar2 = *param_1;

  local_54 = puVar1[7];

  FUN_0063a190(param_1[2] + 0x20,iVar2 + 0x10);

  local_74 = param_1;

  local_78 = &local_70;

  local_80 = *(int **)(iVar2 + 0xc);

  local_7c = param_1[1];

  iVar2 = (**(code **)(*local_80 + 0x14))();

  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();

  (**(code **)(*param_3 + 0x218c + (iVar2 * 0x20 + iVar3) * 4))(&local_80,param_2,param_3,param_4);

  return;

}
