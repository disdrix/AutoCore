// =============================================================================
// FUN_00740260
// -----------------------------------------------------------------------------
// Stable ID: aa_00740260
// Address:   0x00740260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00740260 @ 0x00740260
// Stable ID: aa_00740260
// Embedded strings (evidence for future rename):
//   - "%1.3fms: %s (%1.3fp)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×13, return×2.
//  - Notable callees: CONCAT13×4, FUN_00759730×3, ROUND×3, CONCAT31×2, FUN_0040aeb0×2, FUN_0040aef0×2, FUN_00758460×2, FUN_00740260.
//  - Strings: "%1.3fms: %s (%1.3fp)".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00740260(int *param_1,char *param_2)



{

  int iVar1;

  float *pfVar2;

  int iVar3;

  int unaff_EBX;

  int unaff_EDI;

  char *local_144;

  undefined3 local_11c;

  uint8_t uStack_119;

  float local_118;

  uint8_t *local_114;

  int local_110;

  int local_108;

  int local_104;

  char local_100 [256];

  

  if ((((*(int *)(unaff_EBX + 0x54) <= *param_1) && (*(int *)(unaff_EBX + 0x58) <= param_1[1])) &&

      (*param_1 < *(int *)(unaff_EBX + 0x5c))) && (param_1[1] < *(int *)(unaff_EBX + 0x60))) {

    *(char **)(unaff_EBX + 100) = param_2;

    *(uint *)(unaff_EBX + 0x5c) = (*(uint *)(unaff_EBX + 8) >> 1) + *param_1;

  }

  local_104 = (int)ROUND(*(float *)(unaff_EDI + 0xf4) * DAT_00aaa6f8);

  local_118 = (float)*(int *)(param_2 + 0x5c);

  if (*(int *)(param_2 + 0x5c) < 0) {

    local_118 = local_118 + _DAT_00aaa5dc;

  }

  local_118 = local_118 * *(float *)(unaff_EBX + 0x18);

  local_108 = *(int *)(unaff_EBX + 8) + param_1[1];

  local_144 = (char *)(float)local_108;

  _local_11c = CONCAT13((uint8_t)local_104,0x303000);

  _local_11c = CONCAT31(stack0xfffffee5,0x60);

  FUN_00758460((float)*param_1,(float)(param_1[1] + -1),(float)((int)ROUND(local_118) + *param_1));

  iVar1 = *(int *)(unaff_EDI + 0x68) + 1;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  if (*(uint *)(param_2 + 0x74) == 0) {

    local_114 = (uint8_t *)0x0;

  }

  else {

    local_114 = (uint8_t *)(*(uint *)(param_2 + 0x54) / *(uint *)(param_2 + 0x74));

  }

  local_118 = (float)(int)local_114;

  if ((int)local_114 < 0) {

    local_118 = local_118 + _DAT_00aaa5dc;

  }

  local_118 = local_118 * *(float *)(unaff_EBX + 0x18);

  local_108 = *(int *)(unaff_EBX + 8) + param_1[1];

  local_144 = (char *)(float)local_108;

  _local_11c = CONCAT13((uint8_t)local_104,0x404000);

  _local_11c = CONCAT31(stack0xfffffee5,0x96);

  FUN_00758460((float)*param_1,(float)(param_1[1] + -1),(float)((int)ROUND(local_118) + *param_1));

  iVar1 = *(int *)(unaff_EDI + 0x68) + 1;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  _local_11c = CONCAT13((uint8_t)local_104,0xffffff);

  if (*(uint *)(param_2 + 0x74) == 0) {

    local_118 = 0.0;

  }

  else {

    local_118 = (float)(*(uint *)(param_2 + 0x54) / *(uint *)(param_2 + 0x74));

  }

  pfVar2 = (float *)(unaff_EBX + 0x10);

  if (*(int *)(unaff_EBX + 0x10) <= (int)local_118) {

    pfVar2 = &local_118;

  }

  *(float *)(unaff_EBX + 0x10) = *pfVar2;

  local_118 = *(float *)(param_2 + 0x5c);

  if (*(uint *)(param_2 + 0x74) == 0) {

    local_114 = (uint8_t *)0x0;

  }

  else {

    local_114 = (uint8_t *)(*(uint *)(param_2 + 0x54) / *(uint *)(param_2 + 0x74));

  }

  local_144 = (char *)0x740505;

  sprintf(local_100,"%1.3fms: %s (%1.3fp)");

  local_114 = (uint8_t *)&local_144;

  FUN_0040aef0(&local_144);

  local_110 = param_1[1];

  local_114 = (uint8_t *)((*(uint *)(unaff_EBX + 0xc) >> 1) + *param_1);

  FUN_00759730(unaff_EDI,&local_114,&local_11c);

  iVar1 = *(int *)(unaff_EDI + 0x68);

  iVar3 = iVar1 + -1;

  *(int *)(unaff_EDI + 0x68) = iVar3;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar3;

  if (*(int *)(unaff_EDI + 0x70) < iVar3) {

    *(int *)(unaff_EDI + 0x70) = iVar3;

  }

  iVar1 = iVar1 + -2;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  _local_11c = CONCAT13((uint8_t)local_104,0xffc8c8);

  if ((*(int *)(param_2 + 0x40) != 0) &&

     (*(int *)(param_2 + 0x44) - *(int *)(param_2 + 0x40) >> 2 != 0)) {

    if (*param_2 == '\0') {

      local_114 = (uint8_t *)&local_144;

      local_144 = param_2;

      FUN_0040aeb0(&local_144);

      local_114 = (uint8_t *)((*param_1 - (*(uint *)(unaff_EBX + 0xc) >> 1)) + -3);

    }

    else {

      local_114 = (uint8_t *)&local_144;

      local_144 = param_2;

      FUN_0040aeb0(&local_144);

      local_114 = (uint8_t *)(*param_1 - (*(uint *)(unaff_EBX + 0xc) >> 1));

    }

    local_110 = param_1[1];

    FUN_00759730(unaff_EDI,&local_114,&local_11c);

    return;

  }

  local_114 = (uint8_t *)&local_144;

  local_144 = param_2;

  FUN_0040aef0(&local_144);

  local_114 = (uint8_t *)(*param_1 - *(int *)(unaff_EBX + 0xc));

  local_110 = param_1[1];

  FUN_00759730(unaff_EDI,&local_114,&local_11c);

  return;

}
