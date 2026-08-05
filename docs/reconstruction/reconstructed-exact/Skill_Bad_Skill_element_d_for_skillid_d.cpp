// READABILITY (auto CF):
//  - Body size: ~482 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, switch×1, for×1, while×1.
//  - Notable callees: FUN_00549320×6, FUN_005495f0, FUN_007a4480.
//  - Strings: "Bad Skill element! %d for skillid:%d".
//  - Return sites: 2.

// =============================================================================
// Skill_Bad_Skill_element_d_for_skillid_d
// -----------------------------------------------------------------------------
// Stable ID: aa_005495f0
// Address:   0x005495f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Bad Skill element! %d for skillid:%d"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Skill_Bad_Skill_element_d_for_skillid_d(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  

  iVar5 = 0;

  if (0 < *(short *)(param_1 + 0x92c)) {

    fVar6 = 0.0;

    iVar4 = 0;

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x930) + iVar4);

      switch(*(uint *)(*(int *)(param_1 + 0x930) + 4 + iVar4) & 0xffff) {

      case 1:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x40) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x44) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x48) = uVar1;

        break;

      case 2:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x50) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x54) = uVar1;

        break;

      case 3:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x58) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x60) = uVar1;

        break;

      case 4:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 100) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x68) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x6c) = uVar1;

        break;

      case 5:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x70) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x74) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x78) = uVar1;

        break;

      case 6:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x7c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x80) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x84) = uVar1;

        break;

      case 7:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x88) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x8c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x90) = uVar1;

        break;

      case 8:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xa0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xa4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xa8) = uVar1;

        break;

      case 9:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xb8) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xbc) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xc0) = uVar1;

        break;

      case 10:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xc4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 200) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xcc) = uVar1;

        break;

      case 0xb:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xe8) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xec) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xf0) = uVar1;

        break;

      case 0xc:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xd0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xd4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xd8) = uVar1;

        break;

      case 0xd:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xdc) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xe0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xe4) = uVar1;

        break;

      case 0xe:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xf4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xf8) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xfc) = uVar1;

        break;

      case 0xf:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x100) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x104) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x108) = uVar1;

        break;

      case 0x10:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0xac) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4) = uVar1;

        break;

      case 0x11:

        FUN_00549320(puVar3,0,param_2);

        break;

      case 0x12:

        FUN_00549320(puVar3,1,param_2);

        break;

      case 0x13:

        FUN_00549320(puVar3,2,param_2);

        break;

      case 0x14:

        FUN_00549320(puVar3,3,param_2);

        break;

      case 0x15:

        FUN_00549320(puVar3,4,param_2);

        break;

      case 0x16:

        FUN_00549320(puVar3,5,param_2);

        break;

      case 0x17:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x388) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x38c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x390) = uVar1;

        break;

      case 0x18:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x394) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x398) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x39c) = uVar1;

        break;

      case 0x19:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3a0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3a4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3a8) = uVar1;

        break;

      case 0x1a:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3ac) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3b0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3b4) = uVar1;

        break;

      case 0x1b:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x10c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x110) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x114) = uVar1;

        break;

      case 0x1c:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x364) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x368) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x36c) = uVar1;

        break;

      case 0x1d:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x358) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x35c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x360) = uVar1;

        break;

      case 0x1e:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x37c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x380) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 900) = uVar1;

        break;

      case 0x1f:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x370) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x374) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x378) = uVar1;

        break;

      case 0x20:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3b8) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3bc) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c0) = uVar1;

        break;

      case 0x21:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3c4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c8) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3cc) = uVar1;

        break;

      case 0x22:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3d0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3d4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3d8) = uVar1;

        break;

      case 0x23:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3dc) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3e0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3e4) = uVar1;

        break;

      case 0x24:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 1000) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3ec) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3f0) = uVar1;

        break;

      case 0x25:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x3f4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3f8) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3fc) = uVar1;

        break;

      case 0x26:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x400) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x404) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x408) = uVar1;

        break;

      case 0x27:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x40c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x410) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x414) = uVar1;

        break;

      case 0x28:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x418) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x41c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x420) = uVar1;

        break;

      case 0x29:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x424) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x428) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x42c) = uVar1;

        break;

      case 0x2a:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x454) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x458) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x45c) = uVar1;

        break;

      case 0x2b:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x28) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = uVar1;

        break;

      case 0x2c:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x430) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x434) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x438) = uVar1;

        break;

      case 0x2d:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x448) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x44c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x450) = uVar1;

        break;

      case 0x2e:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x34) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x38) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x3c) = uVar1;

        break;

      case 0x2f:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x46c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x470) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x474) = uVar1;

        break;

      case 0x30:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x460) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x464) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x468) = uVar1;

        break;

      case 0x31:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x478) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x47c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x480) = uVar1;

        break;

      case 0x32:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x484) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x488) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x48c) = uVar1;

        break;

      case 0x33:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x490) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x494) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x498) = uVar1;

        break;

      case 0x34:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x94) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x98) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x9c) = uVar1;

        break;

      case 0x35:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4a8) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4ac) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4b0) = uVar1;

        break;

      case 0x36:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4b4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4b8) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4bc) = uVar1;

        break;

      case 0x37:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4c0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4c8) = uVar1;

        break;

      case 0x38:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x49c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4a0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4a4) = uVar1;

        break;

      case 0x39:

        if ((float)puVar3[3] <= fVar6) {

          *(uint8_t *)(param_2 + 9) = 0;

        }

        else {

          *(uint8_t *)(param_2 + 9) = 1;

        }

        break;

      case 0x3a:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4cc) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4d0) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4d4) = uVar1;

        break;

      case 0x3b:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4d8) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4dc) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4e0) = uVar1;

        break;

      case 0x3c:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4e4) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4e8) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4ec) = uVar1;

        break;

      case 0x3d:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4f0) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4f4) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x4f8) = uVar1;

        break;

      case 0x3e:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x4fc) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x500) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x504) = uVar1;

        break;

      case 0x3f:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x508) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x50c) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x510) = uVar1;

        break;

      case 0x40:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x514) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x518) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x51c) = uVar1;

        break;

      case 0x41:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x520) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x524) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x528) = uVar1;

        break;

      case 0x42:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x43c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x440) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x444) = uVar1;

        break;

      case 0x43:

        if ((float)puVar3[3] <= fVar6) {

          *(uint8_t *)(param_2 + 0x14) = 0;

        }

        else {

          *(uint8_t *)(param_2 + 0x14) = 1;

        }

        break;

      case 0x44:

        uVar1 = puVar3[3];

        uVar2 = puVar3[4];

        *(uint *)(param_2 + 0x52c) = (uint)*(byte *)(puVar3 + 2);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x530) = uVar2;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x534) = uVar1;

        break;

      case 0x45:

        *(bool *)(param_2 + 0x15) = (float)puVar3[3] <= fVar6;

        break;

      default:

        FUN_007a4480(0,"Bad Skill element! %d for skillid:%d",puVar3[1] & 0xffff,*puVar3);

        return 0;

      }

      iVar5 = iVar5 + 1;

      iVar4 = iVar4 + 0x14;

    } while (iVar5 < *(short *)(param_1 + 0x92c));

  }

  return 1;

}
