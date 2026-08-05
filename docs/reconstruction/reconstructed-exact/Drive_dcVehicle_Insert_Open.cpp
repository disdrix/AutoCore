// READABILITY (auto CF):
//  - Body size: ~533 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00422fb0×155, CONCAT22×2, FUN_0041a4b0×2, FUN_00423170×2, FUN_0041b670, FUN_004230d0, FUN_007a4480, FUN_007bf560.
//  - Strings: "DBReader: %u against %s"; "dcVehicle_Insert::Open".
//  - Return sites: 2.

// =============================================================================
// Drive_dcVehicle_Insert_Open
// -----------------------------------------------------------------------------
// Stable ID: aa_007e8920
// Address:   0x007e8920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "dcVehicle_Insert::Open"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Drive_dcVehicle_Insert_Open(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  int iVar1;

  uint16_t uVar2;

  uint32_t /* width from decompiler */ local_280;

  uint32_t /* width from decompiler */ local_27c;

  uint32_t /* width from decompiler */ local_278;

  uint32_t /* width from decompiler */ local_274;

  uint32_t /* width from decompiler */ local_270;

  uint32_t /* width from decompiler */ local_26c;

  byte bStack_268;

  uint8_t local_267;

  uint8_t local_266;

  uint8_t local_265;

  uint8_t local_264;

  uint8_t local_263;

  uint8_t local_262;

  uint8_t local_261;

  uint32_t /* width from decompiler */ local_260;

  uint32_t /* width from decompiler */ local_25c;

  uint32_t /* width from decompiler */ local_258;

  uint32_t /* width from decompiler */ local_254;

  uint32_t /* width from decompiler */ local_250;

  uint32_t /* width from decompiler */ local_24c;

  uint32_t /* width from decompiler */ local_248;

  uint32_t /* width from decompiler */ local_244;

  uint32_t /* width from decompiler */ local_240;

  uint32_t /* width from decompiler */ local_23c;

  uint32_t /* width from decompiler */ local_238;

  uint32_t /* width from decompiler */ local_234;

  uint32_t /* width from decompiler */ local_230;

  uint32_t /* width from decompiler */ local_22c;

  uint32_t /* width from decompiler */ local_228;

  uint32_t /* width from decompiler */ local_224;

  uint32_t /* width from decompiler */ local_220;

  uint32_t /* width from decompiler */ local_21c;

  uint32_t /* width from decompiler */ local_218;

  uint32_t /* width from decompiler */ local_214;

  uint32_t /* width from decompiler */ local_210;

  uint32_t /* width from decompiler */ local_20c;

  uint32_t /* width from decompiler */ local_208;

  uint32_t /* width from decompiler */ local_204;

  uint32_t /* width from decompiler */ local_200;

  uint32_t /* width from decompiler */ local_1fc;

  uint32_t /* width from decompiler */ local_1f8;

  uint32_t /* width from decompiler */ local_1f4;

  uint32_t /* width from decompiler */ local_1f0;

  uint32_t /* width from decompiler */ local_1ec;

  uint32_t /* width from decompiler */ local_1e8;

  uint32_t /* width from decompiler */ local_1e4;

  uint local_1e0;

  uint32_t /* width from decompiler */ local_1dc;

  uint32_t /* width from decompiler */ local_1d8;

  uint32_t /* width from decompiler */ local_1d4;

  uint local_1d0;

  uint32_t /* width from decompiler */ local_1cc;

  uint32_t /* width from decompiler */ local_1c8;

  uint32_t /* width from decompiler */ local_1c4;

  uint32_t /* width from decompiler */ local_1c0;

  uint32_t /* width from decompiler */ local_1bc;

  uint32_t /* width from decompiler */ local_1b8;

  uint32_t /* width from decompiler */ local_1b4;

  uint32_t /* width from decompiler */ local_1b0;

  uint32_t /* width from decompiler */ local_1ac;

  uint32_t /* width from decompiler */ local_1a8;

  uint32_t /* width from decompiler */ local_1a4;

  uint32_t /* width from decompiler */ local_1a0;

  uint32_t /* width from decompiler */ local_19c;

  uint32_t /* width from decompiler */ local_198;

  uint32_t /* width from decompiler */ local_194;

  uint32_t /* width from decompiler */ local_190;

  uint32_t /* width from decompiler */ local_18c;

  uint32_t /* width from decompiler */ local_188;

  uint32_t /* width from decompiler */ local_184;

  uint32_t /* width from decompiler */ local_180;

  uint32_t /* width from decompiler */ local_17c;

  uint32_t /* width from decompiler */ local_178;

  uint32_t /* width from decompiler */ local_174;

  uint32_t /* width from decompiler */ local_170;

  uint32_t /* width from decompiler */ local_16c;

  uint32_t /* width from decompiler */ local_168;

  uint32_t /* width from decompiler */ local_164;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint32_t /* width from decompiler */ local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

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

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104;

  uint32_t /* width from decompiler */ local_100;

  uint32_t /* width from decompiler */ local_fc;

  uint32_t /* width from decompiler */ local_f8;

  uint32_t /* width from decompiler */ local_f4;

  uint32_t /* width from decompiler */ local_f0;

  uint32_t /* width from decompiler */ local_ec;

  uint32_t /* width from decompiler */ local_e8;

  uint32_t /* width from decompiler */ local_e4;

  uint32_t /* width from decompiler */ local_e0;

  uint32_t /* width from decompiler */ local_dc;

  uint32_t /* width from decompiler */ local_d8;

  uint32_t /* width from decompiler */ local_d4;

  uint32_t /* width from decompiler */ local_d0;

  uint32_t /* width from decompiler */ local_cc;

  float local_c8;

  uint32_t /* width from decompiler */ local_c4;

  float local_c0;

  uint32_t /* width from decompiler */ local_bc;

  float local_b8;

  uint32_t /* width from decompiler */ local_b4;

  float local_b0;

  uint32_t /* width from decompiler */ local_ac;

  uint32_t /* width from decompiler */ local_a8;

  uint32_t /* width from decompiler */ local_a4;

  uint32_t /* width from decompiler */ local_a0;

  uint32_t /* width from decompiler */ local_9c;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  char *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b0c3b;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else if (DAT_00d1793c == '\0') {

    ExceptionList = &local_c;

    local_18 = param_1;

    iVar1 = FUN_007e1fb0(param_2,param_3,param_5);

    if (-1 < iVar1) {

      local_ac = *(uint32_t /* width from decompiler */ *)(param_4 + 4);

      local_10 = *(uint32_t /* width from decompiler */ *)(param_4 + 8);

      local_254 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xc);

      local_34 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x10);

      local_24c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14);

      local_12c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18);

      local_244 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c);

      local_9c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20);

      local_23c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x24);

      local_124 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x28);

      local_234 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x2c);

      local_54 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x30);

      local_22c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x34);

      local_11c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x38);

      local_224 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x3c);

      local_94 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x40);

      local_21c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x44);

      local_114 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x48);

      local_14 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x54);

      local_20c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x58);

      local_10c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x5c);

      local_204 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x60);

      local_260 = *param_5;

      local_8c = *(uint32_t /* width from decompiler */ *)(param_4 + 100);

      local_1fc = *(uint32_t /* width from decompiler */ *)(param_4 + 0x68);

      local_261 = param_4[0x50];

      local_214 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x4c);

      local_104 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x6c);

      local_1f4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x70);

      local_4c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x74);

      local_1ec = *(uint32_t /* width from decompiler */ *)(param_4 + 0x78);

      local_fc = *(uint32_t /* width from decompiler */ *)(param_4 + 0x7c);

      local_1e4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x80);

      local_84 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x84);

      local_1dc = *(uint32_t /* width from decompiler */ *)(param_4 + 0x88);

      local_f4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x8c);

      local_1d4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x90);

      local_262 = param_4[0x51];

      local_2c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x94);

      local_1cc = *(uint32_t /* width from decompiler */ *)(param_4 + 0x98);

      local_ec = *(uint32_t /* width from decompiler */ *)(param_4 + 0x9c);

      local_1c4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xa0);

      local_7c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xa4);

      local_1bc = *(uint32_t /* width from decompiler */ *)(param_4 + 0xa8);

      local_e4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xac);

      local_1b4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xb0);

      local_44 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xb4);

      local_1ac = *(uint32_t /* width from decompiler */ *)(param_4 + 0xb8);

      local_dc = *(uint32_t /* width from decompiler */ *)(param_4 + 0xbc);

      local_1a4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xc0);

      local_74 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xc4);

      local_19c = *(uint32_t /* width from decompiler */ *)(param_4 + 200);

      local_d4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xcc);

      local_194 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xd0);

      local_1c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xd4);

      local_18c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xd8);

      local_cc = *(uint32_t /* width from decompiler */ *)(param_4 + 0xdc);

      local_184 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xe0);

      local_6c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xe4);

      local_17c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xe8);

      local_c4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xec);

      local_174 = *(uint32_t /* width from decompiler */ *)(param_4 + 0xf0);

      local_3c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xf4);

      local_16c = *(uint32_t /* width from decompiler */ *)(param_4 + 0xf8);

      local_bc = *(uint32_t /* width from decompiler */ *)(param_4 + 0xfc);

      uVar2 = (uint16_t)((uint)local_214 >> 0x10);

      local_134 = CONCAT22(uVar2,*(uint16_t *)(param_4 + 0x130));

      local_164 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x100);

      local_265 = *param_4;

      local_64 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x104);

      local_15c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x108);

      local_b4 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x10c);

      local_154 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x110);

      local_24 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x114);

      local_14c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x118);

      local_25c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x11c);

      local_144 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x120);

      local_5c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x124);

      local_13c = *(uint32_t /* width from decompiler */ *)(param_4 + 0x128);

      local_a4 = *(uint32_t /* width from decompiler */ *)(param_4 + 300);

      local_258 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x134);

      local_250 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x138);

      local_248 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x13c);

      local_240 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x140);

      local_238 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x144);

      local_230 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x148);

      local_228 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x14c);

      local_220 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x150);

      local_218 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x154);

      local_210 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x158);

      local_208 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x15c);

      local_200 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x160);

      local_1f8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x164);

      local_1f0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x168);

      local_1e8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x16c);

      local_1c8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1e0);

      local_1c0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1e4);

      local_1b8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1e8);

      local_1b0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1ec);

      local_1a8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1f0);

      local_267 = param_4[1];

      local_266 = param_4[0x1d9];

      local_1a0 = *(uint32_t /* width from decompiler */ *)(param_4 + 500);

      local_263 = param_4[0x1d8];

      local_198 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1f8);

      local_190 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1fc);

      local_188 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x200);

      local_180 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x204);

      local_178 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x208);

      local_170 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x20c);

      local_168 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x210);

      local_160 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x214);

      local_158 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x218);

      local_150 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x21c);

      local_148 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x220);

      local_130 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x23c);

      local_1e0 = (uint)*(ushort *)(param_4 + 0x1da);

      local_1d8 = CONCAT22(uVar2,*(uint16_t *)(param_4 + 0x1dc));

      local_1d0 = (uint)*(ushort *)(param_4 + 0x1de);

      local_128 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x240);

      local_120 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x244);

      local_118 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x248);

      local_110 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x24c);

      local_f8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x170);

      local_f0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x174);

      local_138 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x234);

      local_e8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c4);

      local_e0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1c8);

      local_d8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1cc);

      local_d0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1d0);

      local_c8 = (float)(byte)param_4[0x1c0];

      local_c0 = (float)(byte)param_4[0x1c1];

      local_b8 = (float)(byte)param_4[0x1c2];

      local_b0 = (float)(byte)param_4[0x1c3];

      local_a8 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x178);

      local_a0 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x17c);

      local_98 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x180);

      local_90 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x184);

      local_88 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x188);

      local_80 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x18c);

      local_78 = *(uint32_t /* width from decompiler */ *)(param_4 + 400);

      local_264 = param_4[0x255];

      local_70 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x194);

      local_68 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x198);

      local_60 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x19c);

      local_58 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1a0);

      local_50 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1a4);

      local_48 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1a8);

      local_40 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1ac);

      local_38 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1b0);

      local_30 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1b4);

      local_28 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1b8);

      local_20 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x1bc);

      local_100 = *(uint32_t /* width from decompiler */ *)(param_4 + 0x250);

      local_108 = 0;

      local_140 = 0;

      local_280 = 0;

      local_27c = 0;

      local_278 = 0;

      local_274 = 0;

      local_270 = 0;

      local_26c = 0;

      local_4 = 0;

      FUN_004230d0(&local_280,&local_260);

      iVar1 = FUN_00422fb0(1,1,4);

      if (((((((iVar1 < 0) || (iVar1 = FUN_00422fb0(1,2,4), iVar1 < 0)) ||

             (iVar1 = FUN_00422fb0(1,3,4), iVar1 < 0)) ||

            (((iVar1 = FUN_00422fb0(1,4,4), iVar1 < 0 || (iVar1 = FUN_00422fb0(1,5,4), iVar1 < 0))

             || ((iVar1 = FUN_00422fb0(1,6,4), iVar1 < 0 ||

                 ((iVar1 = FUN_00422fb0(1,7,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,8,4), iVar1 < 0)))))))) ||

           (((iVar1 = FUN_00422fb0(1,9,4), iVar1 < 0 ||

             (((((iVar1 = FUN_00422fb0(1,10,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0xb,4), iVar1 < 0)) ||

                (iVar1 = FUN_00422fb0(1,0xc,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0xd,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0xe,4), iVar1 < 0)))) ||

              ((iVar1 = FUN_00422fb0(1,0xf,4), iVar1 < 0 ||

               ((iVar1 = FUN_00422fb0(1,0x10,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x11,4), iVar1 < 0)))))))) ||

            (iVar1 = FUN_00422fb0(1,0x12,4), iVar1 < 0)))) ||

          ((((((iVar1 = FUN_00422fb0(1,0x13,4), iVar1 < 0 ||

               (iVar1 = FUN_00422fb0(1,0x14,4), iVar1 < 0)) ||

              (iVar1 = FUN_00422fb0(1,0x15,1), iVar1 < 0)) ||

             (((iVar1 = FUN_00422fb0(1,0x16,1), iVar1 < 0 ||

               (iVar1 = FUN_00422fb0(1,0x17,4), iVar1 < 0)) ||

              ((iVar1 = FUN_00422fb0(1,0x18,4), iVar1 < 0 ||

               ((iVar1 = FUN_00422fb0(1,0x19,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x1a,4), iVar1 < 0)))))))) ||

            ((iVar1 = FUN_00422fb0(1,0x1b,4), iVar1 < 0 ||

             ((((iVar1 = FUN_00422fb0(1,0x1c,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x1d,4), iVar1 < 0)) ||

               (iVar1 = FUN_00422fb0(1,0x1e,4), iVar1 < 0)) ||

              (((iVar1 = FUN_00422fb0(1,0x1f,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x20,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0x21,4), iVar1 < 0 ||

                ((iVar1 = FUN_00422fb0(1,0x22,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x23,4), iVar1 < 0)))))))))))) ||

           ((iVar1 = FUN_00422fb0(1,0x24,4), iVar1 < 0 ||

            ((((((iVar1 = FUN_00422fb0(1,0x25,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x26,4), iVar1 < 0)) ||

                (iVar1 = FUN_00422fb0(1,0x27,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0x28,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x29,4), iVar1 < 0)))) ||

              (iVar1 = FUN_00422fb0(1,0x2a,4), iVar1 < 0)) ||

             ((iVar1 = FUN_00422fb0(1,0x2b,4), iVar1 < 0 ||

              (iVar1 = FUN_00422fb0(1,0x2c,4), iVar1 < 0)))))))))) ||

         (((((iVar1 = FUN_00422fb0(1,0x2d,4), iVar1 < 0 ||

             (((iVar1 = FUN_00422fb0(1,0x2e,4), iVar1 < 0 ||

               (iVar1 = FUN_00422fb0(1,0x2f,4), iVar1 < 0)) ||

              (iVar1 = FUN_00422fb0(1,0x30,4), iVar1 < 0)))) ||

            (((((iVar1 = FUN_00422fb0(1,0x31,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x32,4), iVar1 < 0)) ||

               (iVar1 = FUN_00422fb0(1,0x33,4), iVar1 < 0)) ||

              ((iVar1 = FUN_00422fb0(1,0x34,4), iVar1 < 0 ||

               (iVar1 = FUN_00422fb0(1,0x35,4), iVar1 < 0)))) ||

             (((((iVar1 = FUN_00422fb0(1,0x36,4), iVar1 < 0 ||

                 (((iVar1 = FUN_00422fb0(1,0x37,4), iVar1 < 0 ||

                   (iVar1 = FUN_00422fb0(1,0x38,4), iVar1 < 0)) ||

                  (iVar1 = FUN_00422fb0(1,0x39,4), iVar1 < 0)))) ||

                ((iVar1 = FUN_00422fb0(1,0x3a,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x3b,4), iVar1 < 0)))) ||

               (iVar1 = FUN_00422fb0(1,0x3c,4), iVar1 < 0)) ||

              (((((iVar1 = FUN_00422fb0(1,0x3d,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x3e,4), iVar1 < 0)) ||

                 ((iVar1 = FUN_00422fb0(1,0x3f,4), iVar1 < 0 ||

                  ((((iVar1 = FUN_00422fb0(1,0x40,4), iVar1 < 0 ||

                     (iVar1 = FUN_00422fb0(1,0x41,4), iVar1 < 0)) ||

                    (iVar1 = FUN_00422fb0(1,0x42,4), iVar1 < 0)) ||

                   ((iVar1 = FUN_00422fb0(1,0x43,4), iVar1 < 0 ||

                    (iVar1 = FUN_00422fb0(1,0x44,4), iVar1 < 0)))))))) ||

                (iVar1 = FUN_00422fb0(1,0x45,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0x46,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x47,4), iVar1 < 0)))))))))) ||

           (((((((iVar1 = FUN_00422fb0(1,0x48,4), iVar1 < 0 ||

                 (((iVar1 = FUN_00422fb0(1,0x49,4), iVar1 < 0 ||

                   (iVar1 = FUN_00422fb0(1,0x4a,4), iVar1 < 0)) ||

                  (iVar1 = FUN_00422fb0(1,0x4b,4), iVar1 < 0)))) ||

                (((iVar1 = FUN_00422fb0(1,0x4c,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x4d,4), iVar1 < 0)) ||

                 (iVar1 = FUN_00422fb0(1,0x4e,2), iVar1 < 0)))) ||

               ((((((iVar1 = FUN_00422fb0(1,0x4f,1), iVar1 < 0 ||

                    (iVar1 = FUN_00422fb0(1,0x50,4), iVar1 < 0)) ||

                   ((iVar1 = FUN_00422fb0(1,0x51,4), iVar1 < 0 ||

                    (((iVar1 = FUN_00422fb0(1,0x52,4), iVar1 < 0 ||

                      (iVar1 = FUN_00422fb0(1,0x53,1), iVar1 < 0)) ||

                     (iVar1 = FUN_00422fb0(1,0x54,4), iVar1 < 0)))))) ||

                  ((iVar1 = FUN_00422fb0(1,0x55,4), iVar1 < 0 ||

                   (iVar1 = FUN_00422fb0(1,0x56,4), iVar1 < 0)))) ||

                 ((iVar1 = FUN_00422fb0(1,0x57,4), iVar1 < 0 ||

                  (((iVar1 = FUN_00422fb0(1,0x58,4), iVar1 < 0 ||

                    (iVar1 = FUN_00422fb0(1,0x59,4), iVar1 < 0)) ||

                   ((iVar1 = FUN_00422fb0(1,0x5a,4), iVar1 < 0 ||

                    ((((iVar1 = FUN_00422fb0(1,0x5b,4), iVar1 < 0 ||

                       (iVar1 = FUN_00422fb0(1,0x5c,4), iVar1 < 0)) ||

                      (iVar1 = FUN_00422fb0(1,0x5d,4), iVar1 < 0)) ||

                     ((iVar1 = FUN_00422fb0(1,0x5e,4), iVar1 < 0 ||

                      (iVar1 = FUN_00422fb0(1,0x5f,4), iVar1 < 0)))))))))))) ||

                (iVar1 = FUN_00422fb0(1,0x60,1), iVar1 < 0)))) ||

              (((iVar1 = FUN_00422fb0(1,0x61,1), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x62,2), iVar1 < 0)) ||

               (((iVar1 = FUN_00422fb0(1,99,2), iVar1 < 0 ||

                 (((iVar1 = FUN_00422fb0(1,100,2), iVar1 < 0 ||

                   (iVar1 = FUN_00422fb0(1,0x65,4), iVar1 < 0)) ||

                  (iVar1 = FUN_00422fb0(1,0x66,4), iVar1 < 0)))) ||

                (((iVar1 = FUN_00422fb0(1,0x67,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x68,4), iVar1 < 0)) ||

                 (iVar1 = FUN_00422fb0(1,0x69,4), iVar1 < 0)))))))) ||

             ((((iVar1 = FUN_00422fb0(1,0x6a,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x6b,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0x6c,4), iVar1 < 0 ||

                (((iVar1 = FUN_00422fb0(1,0x6d,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x6e,4), iVar1 < 0)) ||

                 (iVar1 = FUN_00422fb0(1,0x6f,4), iVar1 < 0)))))) ||

              ((((iVar1 = FUN_00422fb0(1,0x70,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x71,4), iVar1 < 0)) ||

                ((iVar1 = FUN_00422fb0(1,0x72,4), iVar1 < 0 ||

                 ((((iVar1 = FUN_00422fb0(1,0x73,4), iVar1 < 0 ||

                    (iVar1 = FUN_00422fb0(1,0x74,4), iVar1 < 0)) ||

                   ((iVar1 = FUN_00422fb0(1,0x75,4), iVar1 < 0 ||

                    ((((((iVar1 = FUN_00422fb0(1,0x76,2), iVar1 < 0 ||

                         (iVar1 = FUN_00422fb0(1,0x77,4), iVar1 < 0)) ||

                        (iVar1 = FUN_00422fb0(1,0x78,4), iVar1 < 0)) ||

                       ((iVar1 = FUN_00422fb0(1,0x79,4), iVar1 < 0 ||

                        (iVar1 = FUN_00422fb0(1,0x7a,4), iVar1 < 0)))) ||

                      (iVar1 = FUN_00422fb0(1,0x7b,4), iVar1 < 0)) ||

                     ((iVar1 = FUN_00422fb0(1,0x7c,4), iVar1 < 0 ||

                      (iVar1 = FUN_00422fb0(1,0x7d,2), iVar1 < 0)))))))) ||

                  (iVar1 = FUN_00422fb0(1,0x7e,1), iVar1 < 0)))))) ||

               ((((iVar1 = FUN_00422fb0(1,0x7f,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x80,4), iVar1 < 0)) ||

                 (iVar1 = FUN_00422fb0(1,0x81,4), iVar1 < 0)) ||

                ((iVar1 = FUN_00422fb0(1,0x82,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x83,4), iVar1 < 0)))))))))) ||

            (((((iVar1 = FUN_00422fb0(1,0x84,4), iVar1 < 0 ||

                ((iVar1 = FUN_00422fb0(1,0x85,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x86,4), iVar1 < 0)))) ||

               (iVar1 = FUN_00422fb0(1,0x87,4), iVar1 < 0)) ||

              (((((iVar1 = FUN_00422fb0(1,0x88,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x89,4), iVar1 < 0)) ||

                 (iVar1 = FUN_00422fb0(1,0x8a,4), iVar1 < 0)) ||

                (((iVar1 = FUN_00422fb0(1,0x8b,4), iVar1 < 0 ||

                  (iVar1 = FUN_00422fb0(1,0x8c,4), iVar1 < 0)) ||

                 ((iVar1 = FUN_00422fb0(1,0x8d,4), iVar1 < 0 ||

                  ((iVar1 = FUN_00422fb0(1,0x8e,4), iVar1 < 0 ||

                   (iVar1 = FUN_00422fb0(1,0x8f,4), iVar1 < 0)))))))) ||

               (iVar1 = FUN_00422fb0(1,0x90,4), iVar1 < 0)))) ||

             (((((iVar1 = FUN_00422fb0(1,0x91,4), iVar1 < 0 ||

                 (iVar1 = FUN_00422fb0(1,0x92,4), iVar1 < 0)) ||

                (iVar1 = FUN_00422fb0(1,0x93,4), iVar1 < 0)) ||

               ((iVar1 = FUN_00422fb0(1,0x94,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x95,4), iVar1 < 0)))) ||

              ((iVar1 = FUN_00422fb0(1,0x96,4), iVar1 < 0 ||

               ((iVar1 = FUN_00422fb0(1,0x97,4), iVar1 < 0 ||

                (iVar1 = FUN_00422fb0(1,0x98,4), iVar1 < 0)))))))))))) ||

          ((iVar1 = FUN_00422fb0(1,0x99,4), iVar1 < 0 ||

           (((iVar1 = FUN_00422fb0(1,0x9a,4), iVar1 < 0 ||

             (iVar1 = FUN_00422fb0(1,0x9b,4), iVar1 < 0)) ||

            (iVar1 = FUN_0041b670(&local_280,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar1 < 0)))))))

         ) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcVehicle_Insert::Open");

      }

      else {

        FUN_00423170();

        if ((*(int *)(param_4 + 0x260) != 0) && (param_4[0x256] != '\0')) {

          bStack_268 = 0;

          do {

            iVar1 = FUN_007bf560(local_18);

            if (iVar1 < 0) {

              local_4 = 0xffffffff;

              FUN_0041a4b0(&local_280);

              ExceptionList = local_c;

              return iVar1;

            }

            bStack_268 = bStack_268 + 1;

          } while (bStack_268 < (byte)param_4[0x256]);

        }

      }

      local_4 = 0xffffffff;

      FUN_0041a4b0(&local_280);

      iVar1 = 0;

    }

  }

  else {

    iVar1 = 0;

  }

  ExceptionList = local_c;

  return iVar1;

}
