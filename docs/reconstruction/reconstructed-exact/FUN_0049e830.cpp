// =============================================================================
// FUN_0049e830
// -----------------------------------------------------------------------------
// Stable ID: aa_0049e830
// Address:   0x0049e830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049e830 @ 0x0049e830
// Stable ID: aa_0049e830
// Embedded strings (evidence for future rename):
//   - "startOffset"
//   - "bright"
//   - "target"
//   - "relativeCoords"
//   - "startDelay"
//   - "duration"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×10, return×2.
//  - Notable callees: FUN_00799300×9, FUN_007996d0×5, FUN_00799460×3, FUN_005b8370×2, FUN_00799200×2, FUN_0049dab0, FUN_0049e830, FUN_005b94e0.
//  - Strings: "startOffset"; "bright"; "target"; "relativeCoords".
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

int FUN_0049e830(int *param_1)



{

  float *pfVar1;

  float *pfVar2;

  int *piVar3;

  int iVar4;

  float fVar5;

  byte bStack_229;

  int *local_228;

  byte bStack_221;

  int iStack_220;

  uint32_t /* width from decompiler */ uStack_21c;

  void *pvStack_218;

  uint8_t auStack_214 [516];

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0f61;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (param_1 != (int *)0x0) {

    ExceptionList = &pvStack_c;

    iVar4 = (**(code **)(*param_1 + 0x44))(param_1,&local_228);

    if ((iVar4 == 0) && (local_228 != (int *)0x0)) {

      pvStack_218 = operator_new(0x17c);

      uStack_4 = 0;

      if (pvStack_218 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_005b94e0();

      }

      *(byte *)(iVar4 + 0x178) = *(byte *)(iVar4 + 0x178) | 0x80;

      uStack_4 = 0xffffffff;

      FUN_007994c0(local_228,L"startOffset",iVar4 + 0x128,0,0,0);

      bStack_221 = FUN_007996d0(local_228,L"bright",&bStack_229);

      if (bStack_221 == 0) {

        *(byte *)(iVar4 + 0x179) = *(byte *)(iVar4 + 0x179) | 0x20;

      }

      else {

        *(uint *)(iVar4 + 0x178) =

             *(uint *)(iVar4 + 0x178) ^

             ((uint)bStack_229 << 0xd ^ *(uint *)(iVar4 + 0x178)) & 0x2000;

      }

      FUN_007995a0(local_228,&iStack_220,L"target",iVar4 + 0x144,0,0,0);

      FUN_005b8370(iStack_220,0xc,iVar4 + 0x144,iVar4);

      if (-1 < iStack_220) {

        *(uint *)(iVar4 + 0x178) = *(uint *)(iVar4 + 0x178) | 2;

      }

      bStack_221 = 0;

      FUN_007996d0(local_228,L"relativeCoords",&bStack_221);

      *(uint *)(iVar4 + 0x178) =

           *(uint *)(iVar4 + 0x178) ^ ((uint)bStack_221 ^ *(uint *)(iVar4 + 0x178)) & 1;

      FUN_00799300(local_228,L"startDelay",iVar4 + 0x34);

      FUN_00799300(local_228,L"duration",iVar4 + 0x48);

      bStack_221 = FUN_00798bb0(local_228,L"textureID",auStack_214);

      if (bStack_221 != 0) {

        FUN_0049dab0(auStack_214,iVar4 + 0x54,iVar4 + 0x50);

        *(uint *)(iVar4 + 0x178) = *(uint *)(iVar4 + 0x178) | 8;

      }

      FUN_00799300(local_228,L"linksPerMeter",iVar4 + 0x164);

      FUN_00799300(local_228,L"backDropScale",(float *)(iVar4 + 0x16c));

      if (*(float *)(iVar4 + 0x16c) == g_flZero) {

        *(uint *)(iVar4 + 0x178) = *(uint *)(iVar4 + 0x178) & 0xfffffffb;

      }

      else {

        *(uint *)(iVar4 + 0x178) = *(uint *)(iVar4 + 0x178) | 4;

      }

      FUN_00799300(local_228,L"backDropColorScale",iVar4 + 0x170);

      bStack_229 = 1;

      FUN_007996d0(local_228,L"forkForward",&bStack_229);

      *(uint *)(iVar4 + 0x178) =

           *(uint *)(iVar4 + 0x178) ^ ((uint)bStack_229 << 4 ^ *(uint *)(iVar4 + 0x178)) & 0x10;

      FUN_00798d90(local_228,&iStack_220,L"color",iVar4 + 0x2c,0,0);

      FUN_005b8370(iStack_220,4,iVar4 + 0x2c,iVar4);

      uStack_21c = 0xff;

      FUN_00799460(local_228,L"alpha",&uStack_21c,10);

      pfVar1 = (float *)(iVar4 + 0x3c);

      pfVar2 = (float *)(iVar4 + 0x38);

      *(uint8_t *)(iVar4 + 0x2f) = (uint8_t)uStack_21c;

      bStack_229 = 0;

      FUN_00799200(local_228,L"scale",pfVar2,pfVar1,&bStack_229);

      if (bStack_229 == 0) {

        *pfVar1 = *pfVar2;

      }

      else {

        *pfVar1 = *pfVar1 - *pfVar2;

      }

      pfVar1 = (float *)(iVar4 + 0x154);

      bStack_229 = 0;

      FUN_00799200(local_228,L"jiggleRadius",(float *)(iVar4 + 0x150),pfVar1,&bStack_229);

      if (bStack_229 == 0) {

        fVar5 = 0.0;

      }

      else {

        fVar5 = *pfVar1 - *(float *)(iVar4 + 0x150);

      }

      *pfVar1 = fVar5;

      piVar3 = (int *)(iVar4 + 0x158);

      *piVar3 = 1;

      FUN_00799460(local_228,L"jiggleRecalcScale",piVar3,10);

      if (*piVar3 == 0) {

        *piVar3 = 1;

      }

      bStack_229 = 0;

      FUN_007996d0(local_228,L"lightningStream",&bStack_229);

      *(uint *)(iVar4 + 0x178) =

           *(uint *)(iVar4 + 0x178) ^ ((uint)bStack_229 << 6 ^ *(uint *)(iVar4 + 0x178)) & 0x40;

      bStack_229 = 0;

      FUN_007996d0(local_228,L"forked",&bStack_229);

      *(uint *)(iVar4 + 0x178) =

           *(uint *)(iVar4 + 0x178) ^ ((uint)bStack_229 << 5 ^ *(uint *)(iVar4 + 0x178)) & 0x20;

      FUN_00799300(local_228,L"changeTime",iVar4 + 0x40);

      FUN_00799300(local_228,L"forkChance",iVar4 + 0x15c);

      FUN_00799300(local_228,L"forkScale",iVar4 + 0x160);

      FUN_00799300(local_228,L"forkColorScale",iVar4 + 0x174);

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168) = 1;

      FUN_00799460(local_228,L"numberOfForksScale",(uint32_t /* width from decompiler */ *)(iVar4 + 0x168),10);

      (**(code **)(*local_228 + 8))(local_228);

      ExceptionList = pvStack_10;

      return iVar4;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  ExceptionList = pvStack_c;

  return 0;

}
