// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, for×1.
//  - Notable callees: FUN_007996d0×3, FUN_00403450×2, FUN_00798bb0×2, FUN_00799300×2, free×2, strncpy×2, FUN_004a00d0, FUN_005b8370.
//  - Strings: "addBodyVelocity"; "detachFromBody"; "scale"; "color".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_004a00d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a00d0
// Address:   0x004a00d0  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004a00d0(int param_1,int *param_2)



{

  uint8_t *puVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  byte bStack_2a6;

  byte bStack_2a5;

  int *local_2a4;

  uint32_t /* width from decompiler */ uStack_2a0;

  uint32_t /* width from decompiler */ uStack_29c;

  uint32_t /* width from decompiler */ uStack_298;

  char *pcStack_294;

  char acStack_290 [128];

  uint uStack_210;

  uint32_t /* width from decompiler */ auStack_20c [130];

  

  if (param_2 != (int *)0x0) {

    iVar2 = (**(code **)(*param_2 + 0x44))(param_2,&local_2a4);

    if ((iVar2 == 0) && (local_2a4 != (int *)0x0)) {

      *(float *)(param_1 + 800) = g_flOne;

      puVar1 = (uint8_t *)(param_1 + 0x318);

      *(uint8_t *)(param_1 + 0x31a) = 0xff;

      *(uint8_t *)(param_1 + 0x319) = 0xff;

      *puVar1 = 0xff;

      *(uint8_t *)(param_1 + 0x31b) = 0xff;

      bStack_2a6 = 0;

      FUN_007996d0(local_2a4,L"addBodyVelocity",&bStack_2a6);

      *(byte *)(param_1 + 0x1e8) = *(byte *)(param_1 + 0x1e8) & 0x7f | bStack_2a6 << 7;

      bStack_2a6 = 0;

      FUN_007996d0(local_2a4,L"detachFromBody",&bStack_2a6);

      *(byte *)(param_1 + 0x1e9) =

           *(byte *)(param_1 + 0x1e9) ^ (*(byte *)(param_1 + 0x1e9) ^ bStack_2a6) & 1;

      uVar3 = FUN_00799200(local_2a4,L"scale",param_1 + 800,param_1 + 0x324,&bStack_2a5);

      *(uint *)(param_1 + 0x3c8) =

           *(uint *)(param_1 + 0x3c8) ^ ((uVar3 & 0xff) << 9 ^ *(uint *)(param_1 + 0x3c8)) & 0x200;

      bStack_2a6 = (byte)uVar3;

      if (bStack_2a6 != 0) {

        *(uint *)(param_1 + 0x3c8) =

             ((uint)bStack_2a5 << 10 ^ *(uint *)(param_1 + 0x3c8)) & 0x400 ^

             *(uint *)(param_1 + 0x3c8);

      }

      bStack_2a6 = FUN_00798d90(local_2a4,&uStack_298,L"color",puVar1,param_1 + 0x31c,&bStack_2a5);

      FUN_005b8370(uStack_298,4,puVar1,param_1);

      uStack_2a0 = 0xff;

      uStack_29c = 0xff;

      *(byte *)(param_1 + 0x3c4) =

           *(byte *)(param_1 + 0x3c4) ^ (*(byte *)(param_1 + 0x3c4) ^ bStack_2a6) & 1;

      bStack_2a6 = FUN_00799350(local_2a4,L"alpha",&uStack_2a0,&uStack_29c,&bStack_2a5);

      *(uint8_t *)(param_1 + 0x31b) = (uint8_t)uStack_2a0;

      *(byte *)(param_1 + 0x3c4) =

           *(byte *)(param_1 + 0x3c4) ^ (bStack_2a6 * '\x02' ^ *(byte *)(param_1 + 0x3c4)) & 2;

      uStack_210 = 0;

      puVar5 = auStack_20c;

      for (iVar2 = 0x81; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = 0;

        puVar5 = puVar5 + 1;

      }

      *(uint8_t *)(param_1 + 799) = (uint8_t)uStack_29c;

      bStack_2a6 = FUN_00798bb0(local_2a4,L"textureName",&uStack_210);

      pcStack_294 = acStack_290;

      uVar4 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(&uStack_210,uVar4);

      strncpy((char *)(param_1 + 0x338),pcStack_294,0x40);

      if (pcStack_294 != acStack_290) {

        free(pcStack_294);

      }

      if (bStack_2a6 == 0) {

        *(byte *)(param_1 + 0x3c9) = *(byte *)(param_1 + 0x3c9) & 0xf7;

      }

      else {

        *(byte *)(param_1 + 0x3c9) = *(byte *)(param_1 + 0x3c9) | 8;

      }

      uStack_210 = uStack_210 & 0xffff0000;

      bStack_2a6 = FUN_00798bb0(local_2a4,L"animationName",&uStack_210);

      pcStack_294 = acStack_290;

      uVar4 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(&uStack_210,uVar4);

      strncpy((char *)(param_1 + 0x379),pcStack_294,0x40);

      if (pcStack_294 != acStack_290) {

        free(pcStack_294);

      }

      if (bStack_2a6 == 0) {

        *(byte *)(param_1 + 0x3c9) = *(byte *)(param_1 + 0x3c9) & 0xef;

      }

      else {

        *(byte *)(param_1 + 0x3c9) = *(byte *)(param_1 + 0x3c9) | 0x10;

      }

      *(float *)(param_1 + 0x3bc) = g_flOne;

      FUN_00799300(local_2a4,L"animationBlendTime",(float *)(param_1 + 0x3bc));

      bStack_2a6 = 0;

      FUN_007996d0(local_2a4,L"animationLooping",&bStack_2a6);

      *(uint *)(param_1 + 0x3c8) =

           *(uint *)(param_1 + 0x3c8) ^

           ((uint)bStack_2a6 << 0xd ^ *(uint *)(param_1 + 0x3c8)) & 0x2000;

      bStack_2a6 = FUN_00799300(local_2a4,L"animationSpeedScale",param_1 + 0x3c0);

      *(uint *)(param_1 + 0x3c8) =

           *(uint *)(param_1 + 0x3c8) ^

           ((uint)bStack_2a6 << 0xe ^ *(uint *)(param_1 + 0x3c8)) & 0x4000;

      (**(code **)(*local_2a4 + 8))(local_2a4);

      return 1;

    }

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  return 0;

}
