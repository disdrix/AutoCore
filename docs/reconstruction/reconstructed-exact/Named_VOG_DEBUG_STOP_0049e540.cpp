// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, for×1.
//  - Notable callees: FUN_00799300×5, FUN_00799460×3, FUN_007996d0×3, FUN_005b8370×2, FUN_00798d90×2, SysFreeString×2, FUN_0049dab0, FUN_0049e540.
//  - Strings: "unlinkFromBody"; "duration"; "startDelay"; "bright".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0049e540
// -----------------------------------------------------------------------------
// Stable ID: aa_0049e540
// Address:   0x0049e540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_VOG_DEBUG_STOP_0049e540(int *param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  byte bStack_239;

  int *local_238;

  byte bStack_231;

  uint32_t /* width from decompiler */ uStack_230;

  uint32_t /* width from decompiler */ uStack_22c;

  uint32_t /* width from decompiler */ local_228;

  void *pvStack_224;

  uint32_t /* width from decompiler */ uStack_220;

  uint32_t /* width from decompiler */ auStack_21c [129];

  void *pvStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  int local_c;

  

  puStack_10 = &LAB_009a0f49;

  pvStack_14 = ExceptionList;

  local_228 = 0;

  local_c = 0;

  ExceptionList = &pvStack_14;

  if (param_1 != (int *)0x0) {

    ExceptionList = &pvStack_14;

    iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_238);

    if ((iVar2 == 0) && (local_238 != (int *)0x0)) {

      uStack_220 = 0;

      puVar3 = auStack_21c;

      for (iVar2 = 0x81; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar3 = 0;

        puVar3 = puVar3 + 1;

      }

      pvStack_224 = operator_new(0x17c);

      local_c._0_1_ = 1;

      if (pvStack_224 == (void *)0x0) {

        iVar2 = 0;

      }

      else {

        iVar2 = FUN_005b94e0();

      }

      local_c = (uint)local_c._1_3_ << 8;

      FUN_007996d0(local_238,L"unlinkFromBody",&bStack_231);

      *(uint *)(iVar2 + 0x178) =

           *(uint *)(iVar2 + 0x178) ^ ((uint)bStack_231 << 10 ^ *(uint *)(iVar2 + 0x178)) & 0x400;

      FUN_00799300(local_238,L"duration",iVar2 + 0x48);

      FUN_00799300(local_238,L"startDelay",iVar2 + 0x34);

      bStack_239 = 0;

      FUN_007996d0(local_238,L"bright",&bStack_239);

      *(uint *)(iVar2 + 0x178) =

           *(uint *)(iVar2 + 0x178) ^ ((uint)bStack_239 << 0xd ^ *(uint *)(iVar2 + 0x178)) & 0x2000;

      bStack_239 = 0;

      FUN_007996d0(local_238,L"distort",&bStack_239);

      *(uint *)(iVar2 + 0x178) =

           *(uint *)(iVar2 + 0x178) ^ ((uint)bStack_239 << 0xe ^ *(uint *)(iVar2 + 0x178)) & 0x4000;

      FUN_00799300(local_238,L"spawnTime",iVar2 + 0x40);

      FUN_00798bb0(local_238,L"textureID",&uStack_220);

      FUN_0049dab0(&uStack_220,iVar2 + 0x54,iVar2 + 0x50);

      piVar1 = (int *)(iVar2 + 0x88);

      FUN_00799460(local_238,L"numberOfLinks",piVar1,10);

      if (*piVar1 < 0x1f5) {

        if (*piVar1 < 0) {

          *piVar1 = 0;

        }

      }

      else {

        *piVar1 = 500;

      }

      FUN_00798d90(local_238,&uStack_22c,L"colorStart",iVar2 + 0x2c,0,0);

      FUN_005b8370(uStack_22c,4,iVar2 + 0x2c,iVar2);

      FUN_00798d90(local_238,&uStack_22c,L"colorEnd",iVar2 + 0x30,0,0);

      FUN_005b8370(uStack_22c,4,iVar2 + 0x30,iVar2);

      uStack_230 = 0xff;

      FUN_00799460(local_238,L"alphaStart",&uStack_230,10);

      *(uint8_t *)(iVar2 + 0x2f) = (uint8_t)uStack_230;

      uStack_230 = 0xff;

      FUN_00799460(local_238,L"alphaEnd",&uStack_230,10);

      *(uint8_t *)(iVar2 + 0x33) = (uint8_t)uStack_230;

      FUN_00799300(local_238,L"scaleStart",iVar2 + 0x38);

      FUN_00799300(local_238,L"scaleEnd",iVar2 + 0x3c);

      (**(code **)(*local_238 + 8))(local_238);

      SysFreeString((BSTR)0x0);

      ExceptionList = pvStack_18;

      return iVar2;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  SysFreeString((BSTR)0x0);

  ExceptionList = pvStack_14;

  return 0;

}
