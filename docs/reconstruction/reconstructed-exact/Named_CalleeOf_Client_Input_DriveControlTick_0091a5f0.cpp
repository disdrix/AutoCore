// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_0091a5f0  (LEGACY ALIAS)
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a5f0
// Canonical: Client_Camera_ApplyLookOffset
// Address:   0x0091a5f0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (camera / look apply)
// Generated: 2026-07-23 scaffold; dual A/B seal 2026-07-29
// Prefer:    Client_Camera_ApplyLookOffset.cpp (refined clean)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Camera look-offset apply; sole callers are Client_Input_DriveControlTick
// (sites 0x0092278b / 0x00922f13). Dual: reviews/A|B_aa_0091a5f0_*.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×15, return×2.
//  - Notable callees: FUN_0040d0a0×2, FUN_004c3a40×2, FUN_004e8a40×2, _finite×2, FUN_00404dc0, FUN_004e8ad0, FUN_004e8bf0, FUN_0053d970.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_DriveControlTick
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Client_Input_DriveControlTick_0091a5f0(float param_1,float *param_2)



{

  uint8_t uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  float10 fVar4;

  float fVar5;

  uint8_t uStack_62;

  uint8_t uStack_61;

  float local_60;

  float local_5c;

  float local_58;

  float local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  float local_40;

  float local_3c;

  float local_38;

  float fStack_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint8_t local_20 [28];

  

  local_54 = *(float *)(DAT_00d09874 + 0x30);

  if ((unaff_ESI != 0) && (*(int *)(unaff_ESI + 8) != 0)) {

    if (param_1 != g_flOne) {

      iVar2 = *(int *)(*(int *)(unaff_ESI + 8) + 0x3c);

      local_50 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x30);

      local_4c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x34);

      local_48 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x38);

      local_44 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x3c);

      FUN_004e8a40(&local_50,&local_40);

      local_60 = local_38 * DAT_00afda68 + local_3c * DAT_00afda64 + local_40 * DAT_00afda60;

      fVar5 = g_flOne;

      if ((g_flOne < local_60) || (fVar5 = DAT_00aaa668, local_60 < DAT_00aaa668)) {

        local_60 = fVar5;

      }

      fVar4 = (float10)FUN_0040d0a0();

      local_5c = (float)fVar4;

      iVar2 = _finite((double)fVar4);

      if (iVar2 == 0) {

        local_5c = 0.0;

      }

      FUN_004e8ad0(&local_50,local_20);

      if (local_38 * _DAT_00afda78 + local_3c * _DAT_00afda74 + local_40 * _DAT_00afda70 < 0.0) {

        local_5c = DAT_00aaa7dc - local_5c;

      }

      local_58 = g_flOne;

      local_60 = param_1;

      if (g_flOne < param_1) {

        local_58 = DAT_00aaa668;

        local_60 = g_flOne - (param_1 - g_flOne);

      }

      if (local_60 < DAT_00aaa668) {

        local_60 = DAT_00aaa668;

      }

      fVar4 = (float10)FUN_0040d0a0();

      local_60 = (float)fVar4;

      iVar2 = _finite((double)fVar4);

      fVar5 = 0.0;

      if (iVar2 != 0) {

        fVar5 = local_60;

      }

      FUN_00567ce0(&DAT_00afda50,local_54 * DAT_00aaa6fc * fVar5 * local_58 + local_5c);

      FUN_00404dc0();

    }

    if (DAT_00aaa948 <= param_1) {

      if (param_1 <= _DAT_00aaa9bc) {

        uVar1 = 0;

      }

      else {

        uVar1 = 0xff;

      }

    }

    else {

      uVar1 = 1;

    }

    *(uint8_t *)(unaff_ESI + 0x14c) = uVar1;

    if (((*param_2 != 0.0) || (param_2[2] != 0.0)) || (*(char *)(unaff_ESI + 0x304) != '\0')) {

      if ((*(int *)(unaff_ESI + 8) != 0) &&

         (iVar2 = (**(code **)(**(int **)(*(int *)(unaff_ESI + 8) + 0x3c) + 0x18))(), iVar2 == 6)) {

        FUN_0053d970();

        uStack_61 = 1;

        uStack_62 = 0;

        CVOGSpawnPoint_SetObjectActiveState

                  (*(int *)(*(int *)(unaff_ESI + 4) + 4) + 4 + unaff_ESI,&uStack_61,&uStack_62);

      }

      iVar2 = *(int *)(unaff_ESI + 8);

      if (iVar2 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 0x84 + unaff_ESI);

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x3c) + 0xb0);

      }

      local_50 = *puVar3;

      local_4c = puVar3[1];

      local_48 = puVar3[2];

      local_44 = puVar3[3];

      if (iVar2 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(unaff_ESI + 4) + 4) + 0x94 + unaff_ESI);

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(iVar2 + 0x3c) + 0x30);

      }

      local_30 = *puVar3;

      uStack_2c = puVar3[1];

      uStack_28 = puVar3[2];

      uStack_24 = puVar3[3];

      FUN_004e8bf0(&local_50,&local_30,param_2,local_20);

      FUN_004c3a40();

      if ((param_2[2] == 0.0) && (*param_2 == 0.0)) {

        FUN_004e8a40(&local_30,&local_40);

        local_40 = local_40 * DAT_00a0f70c;

        local_3c = local_3c * DAT_00a0f70c;

        local_38 = local_38 * DAT_00a0f70c;

        fStack_34 = fStack_34 * DAT_00a0f70c;

        local_50 = 0;

        local_4c = 0;

        local_48 = 0;

        local_44 = 0;

        FUN_004c3a40();

        return;

      }

      *(uint8_t *)(unaff_ESI + 0x304) = 1;

    }

  }

  return;

}
