// =============================================================================
// FUN_0073ff40
// -----------------------------------------------------------------------------
// Stable ID: aa_0073ff40
// Address:   0x0073ff40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073ff40 @ 0x0073ff40
// Stable ID: aa_0073ff40
// Embedded strings (evidence for future rename):
//   - "%1.3fms: Unspecified (%1.3f)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~92 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT13×4, ROUND×3, FUN_0040aef0×2, FUN_00758460×2, FUN_00759730×2, FUN_0073ff40, Unspecified, sprintf.
//  - Strings: "%1.3fms: Unspecified (%1.3f)".
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

void FUN_0073ff40(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *unaff_EBX;

  int unaff_EDI;

  float local_d8;

  char *pcStack_d4;

  undefined3 local_b0;

  uint8_t uStack_ad;

  int local_ac;

  float local_a8;

  uint8_t *local_a4;

  int local_a0;

  int local_98;

  float local_94;

  int local_84;

  char local_80 [128];

  

  if ((((*(int *)(param_1 + 0x54) <= *unaff_EBX) && (*(int *)(param_1 + 0x58) <= unaff_EBX[1])) &&

      (*unaff_EBX < *(int *)(param_1 + 0x5c))) && (unaff_EBX[1] < *(int *)(param_1 + 0x60))) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  }

  local_ac = (int)ROUND(*(float *)(unaff_EDI + 0xf4) * DAT_00aaa6f8);

  local_94 = (float)param_3;

  local_a8 = (float)(int)ROUND(*(float *)(param_1 + 0x18) * local_94);

  local_98 = *(int *)(param_1 + 8) + unaff_EBX[1];

  local_d8 = (float)local_98;

  _local_b0 = CONCAT13((uint8_t)local_ac,0x601010);

  pcStack_d4 = &DAT_00d1ec78;

  FUN_00758460((float)*unaff_EBX,(float)(unaff_EBX[1] + -1),(float)((int)local_a8 + *unaff_EBX));

  iVar1 = *(int *)(unaff_EDI + 0x68) + 1;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  if (*(int *)(param_1 + 0x10) <= param_2) {

    puVar3 = &param_2;

  }

  local_a4 = (uint8_t *)(float)param_2;

  local_a8 = *(float *)(param_1 + 0x18) * (float)local_a4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = *puVar3;

  local_84 = *(int *)(param_1 + 8) + unaff_EBX[1];

  local_d8 = (float)local_84;

  _local_b0 = CONCAT13((uint8_t)local_ac,0x8c2020);

  pcStack_d4 = &DAT_00d1ec78;

  FUN_00758460((float)*unaff_EBX,(float)(unaff_EBX[1] + -1),

               (float)((int)ROUND(local_a8) + *unaff_EBX));

  iVar1 = *(int *)(unaff_EDI + 0x68) + 1;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  _local_b0 = CONCAT13((uint8_t)local_ac,0xd2d2d2);

  pcStack_d4 = (char *)0x74016b;

  sprintf(local_80,"%1.3fms: Unspecified (%1.3f)");

  pcStack_d4 = local_80;

  local_a4 = (uint8_t *)&local_d8;

  FUN_0040aef0(&local_d8);

  local_a0 = unaff_EBX[1];

  local_a4 = (uint8_t *)((*(uint *)(param_1 + 0xc) >> 1) + *unaff_EBX);

  FUN_00759730(unaff_EDI,&local_a4,&local_b0);

  iVar1 = *(int *)(unaff_EDI + 0x68);

  iVar2 = iVar1 + -1;

  local_d8 = (float)-iVar2;

  *(int *)(unaff_EDI + 0x68) = iVar2;

  *(float *)(unaff_EDI + 0x74) = (float)(int)local_d8;

  if (*(int *)(unaff_EDI + 0x70) < iVar2) {

    *(int *)(unaff_EDI + 0x70) = iVar2;

  }

  iVar1 = iVar1 + -2;

  *(int *)(unaff_EDI + 0x68) = iVar1;

  *(float *)(unaff_EDI + 0x74) = (float)-iVar1;

  if (*(int *)(unaff_EDI + 0x70) < iVar1) {

    *(int *)(unaff_EDI + 0x70) = iVar1;

  }

  pcStack_d4 = "\\";

  local_a4 = (uint8_t *)&local_d8;

  _local_b0 = CONCAT13((uint8_t)local_ac,0xffc8c8);

  FUN_0040aef0(&local_d8);

  local_a0 = unaff_EBX[1];

  local_a4 = (uint8_t *)((*unaff_EBX - *(int *)(param_1 + 0xc)) + 2);

  FUN_00759730(unaff_EDI,&local_a4,&local_b0);

  return;

}
