// =============================================================================
// FUN_0049e0a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0049e0a0
// Address:   0x0049e0a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049e0a0 @ 0x0049e0a0
// Stable ID: aa_0049e0a0
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
//   - "scale"
//   - "scaleY"
//   - "scaleYProportional"
//   - "color"
//   - "alpha"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×12, return×2, goto×2, for×2.
//  - Notable callees: FUN_00798850×3, FUN_00798bb0×2, FUN_00799200×2, FUN_0049e0a0, FUN_005b8370, FUN_00798d90, FUN_00799300, FUN_00799350.
//  - Strings: "VOG_DEBUG_STOP"; "scale"; "scaleY"; "scaleYProportional".
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

uint32_t /* width from decompiler */ FUN_0049e0a0(int param_1,int *param_2)



{

  float fVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  char cStack_21e;

  char cStack_21d;

  int *local_21c;

  uint32_t /* width from decompiler */ *puStack_218;

  uint32_t /* width from decompiler */ uStack_214;

  uint32_t /* width from decompiler */ uStack_210;

  uint32_t /* width from decompiler */ uStack_20c;

  uint8_t auStack_208 [4];

  uint32_t /* width from decompiler */ auStack_204 [128];

  

  if (param_2 == (int *)0x0) {

LAB_0049e3e5:

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return 0;

  }

  iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_21c);

  if ((iVar3 != 0) || (local_21c == (int *)0x0)) goto LAB_0049e3e5;

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0x2f8);

  puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x36c);

  for (iVar3 = 0x1d; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar5 = *puVar4;

    puVar4 = puVar4 + 1;

    puVar5 = puVar5 + 1;

  }

  cVar2 = FUN_00799200(local_21c,L"scale",(uint32_t /* width from decompiler */ *)(param_1 + 0x36c),param_1 + 0x370,

                       &cStack_21e);

  if (cVar2 != '\0') {

    *(byte *)(param_1 + 0x3e1) =

         (cStack_21e * '\x04' ^ *(byte *)(param_1 + 0x3e1)) & 4 ^ *(byte *)(param_1 + 0x3e1) | 1;

  }

  cVar2 = FUN_00799200(local_21c,L"scaleY",param_1 + 0x374,param_1 + 0x378,&cStack_21e);

  if (cVar2 != '\0') {

    *(byte *)(param_1 + 0x3e1) =

         (cStack_21e << 4 ^ *(byte *)(param_1 + 0x3e1)) & 0x10 ^ *(byte *)(param_1 + 0x3e1) | 1;

  }

  FUN_007996d0(local_21c,L"scaleYProportional",&cStack_21e);

  *(char *)(param_1 + 0x37c) = cStack_21e;

  cStack_21d = FUN_00798d90(local_21c,&uStack_20c,L"color",param_1 + 0x390,param_1 + 0x394,

                            &cStack_21e);

  FUN_005b8370(uStack_20c,4,param_1 + 0x390,param_1);

  if (cStack_21d != '\0') {

    *(byte *)(param_1 + 0x3e1) = *(byte *)(param_1 + 0x3e1) | 0x20;

    *(byte *)(param_1 + 0x3e2) =

         *(byte *)(param_1 + 0x3e2) ^ (cStack_21e * '\x04' ^ *(byte *)(param_1 + 0x3e2)) & 4;

  }

  uStack_214 = 0xff;

  uStack_210 = 0xff;

  cVar2 = FUN_00799350(local_21c,L"alpha",&uStack_214,&uStack_210,&cStack_21e);

  if (cVar2 != '\0') {

    *(uint8_t *)(param_1 + 0x393) = (uint8_t)uStack_214;

    *(uint8_t *)(param_1 + 0x397) = (uint8_t)uStack_210;

    *(byte *)(param_1 + 0x3e2) =

         (cStack_21e << 4 ^ *(byte *)(param_1 + 0x3e2)) & 0x10 ^ *(byte *)(param_1 + 0x3e2) | 1;

  }

  cVar2 = FUN_00799300(local_21c,L"light",param_1 + 0x38c);

  if (cVar2 != '\0') {

    *(byte *)(param_1 + 0x3e2) = *(byte *)(param_1 + 0x3e2) | 0x40;

  }

  auStack_208 = (uint8_t  [4])0x0;

  puVar4 = auStack_204;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  cStack_21d = FUN_00798bb0(local_21c,L"rotationAxis",auStack_208);

  if (cStack_21d == '\0') {

    *(uint8_t *)(param_1 + 0x3a4) = 0;

  }

  else {

    if ((auStack_208._0_2_ == 0x68) || (auStack_208._0_2_ == 0x48)) {

      *(uint8_t *)(param_1 + 0x3a4) = 1;

      puStack_218 = (uint32_t /* width from decompiler */ *)(auStack_208 + 2);

    }

    else {

      *(uint8_t *)(param_1 + 0x3a4) = 0;

      puStack_218 = (uint32_t /* width from decompiler */ *)auStack_208;

    }

    FUN_00798850(&puStack_218,param_1 + 0x398);

  }

  *(byte *)(param_1 + 0x3e1) =

       *(byte *)(param_1 + 0x3e1) ^ (cStack_21d << 6 ^ *(byte *)(param_1 + 0x3e1)) & 0x40;

  fVar1 = g_flOne;

  if (cStack_21d == '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x398) = 0;

    *(float *)(param_1 + 0x39c) = fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x3a0) = 0;

  }

  cStack_21d = FUN_00798bb0(local_21c,L"heading",auStack_208);

  if (cStack_21d != '\0') {

    if ((auStack_208._0_2_ == 0x68) || (auStack_208._0_2_ == 0x48)) {

      puStack_218 = (uint32_t /* width from decompiler */ *)(auStack_208 + 2);

      *(uint8_t *)(param_1 + 0x3b4) = 1;

      FUN_00798850(&puStack_218,param_1 + 0x3a8);

      goto LAB_0049e395;

    }

    puStack_218 = (uint32_t /* width from decompiler */ *)auStack_208;

    FUN_00798850(&puStack_218,param_1 + 0x3a8);

  }

  *(uint8_t *)(param_1 + 0x3b4) = 0;

LAB_0049e395:

  *(byte *)(param_1 + 0x3e1) = *(byte *)(param_1 + 0x3e1) & 0x7f | cStack_21d << 7;

  (**(code **)(*local_21c + 8))(local_21c);

  return 1;

}
