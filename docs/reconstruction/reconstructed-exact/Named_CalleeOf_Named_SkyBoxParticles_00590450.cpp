// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_00590450
// -----------------------------------------------------------------------------
// Stable ID: aa_00590450
// Callee of Named_SkyBoxParticles
// Address:   0x00590450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~130 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CONCAT31, FUN_0055f210, FUN_00560ec0, FUN_00590450, FUN_005961f0, FUN_005d4240, FUN_005e1c80, FUN_006351b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles
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

void __fastcall Named_CalleeOf_Named_SkyBoxParticles_00590450(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puStack_158;

  float fStack_154;

  uint32_t /* width from decompiler */ local_150;

  uint32_t /* width from decompiler */ local_14c;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ auStack_140 [2];

  uint32_t /* width from decompiler */ uStack_138;

  uint32_t /* width from decompiler */ uStack_134;

  uint8_t auStack_130 [8];

  uint32_t /* width from decompiler */ uStack_128;

  uint32_t /* width from decompiler */ uStack_124;

  int iStack_11c;

  uint32_t /* width from decompiler */ uStack_108;

  float fStack_104;

  uint32_t /* width from decompiler */ uStack_100;

  uint32_t /* width from decompiler */ uStack_fc;

  uint32_t /* width from decompiler */ uStack_f8;

  uint32_t /* width from decompiler */ uStack_f4;

  uint32_t /* width from decompiler */ uStack_f0;

  uint32_t /* width from decompiler */ uStack_ec;

  uint8_t auStack_78 [4];

  uint8_t uStack_74;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_24;

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a58e1;

  local_1c = ExceptionList;

  if (*(int *)(param_1 + 0x14) != 0) {

    local_150 = DAT_00a0f718;

    local_14c = DAT_00a0f718;

    local_148 = DAT_00a0f718;

    local_144 = 0;

    ExceptionList = &local_1c;

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x22);

    *(uint16_t *)(iVar1 + 4) = 0x20;

    local_1c = (void *)0x0;

    uVar2 = FUN_006c7970(&puStack_158,0);

    local_1c = (void *)0xffffffff;

    FUN_005e1c80();

    iVar1 = *(int *)(*(int *)(param_1 + 0x260) + 0x3c);

    uStack_108 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb0);

    uStack_128 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x900);

    fStack_104 = *(float *)(iVar1 + 0xb4) + (0.0 - fStack_154) + g_flMultiKillCountBlend;

    uStack_100 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xb8);

    uStack_fc = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc);

    iVar1 = *(int *)(*(int *)(param_1 + 0x260) + 0x3c);

    uStack_f8 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

    uStack_f4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    uStack_f0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38);

    uStack_ec = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c);

    uStack_74 = 7;

    local_1c = (void *)0x1;

    uStack_124 = uVar2;

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xa0,0x28);

    *(uint16_t *)(iVar1 + 4) = 0xa0;

    uStack_24._0_1_ = 2;

    uVar2 = FUN_005d4240(auStack_130);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4) = uVar2;

    uStack_24 = CONCAT31(uStack_24._1_3_,1);

    FUN_00560ec0(uVar2);

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xa4);

    *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;

    if (*(short *)((int)puVar4 + 6) == 0) {

      (**(code **)*puVar4)(1);

    }

    uStack_24 = 0xffffffff;

    if (-1 < iStack_11c) {

      (**(code **)(*DAT_00b05060 + 0x14))(uStack_124,iStack_11c * 8,0x12);

    }

    FUN_006357c0();

    auStack_140[0] = 0;

    uStack_138 = 0;

    uStack_134 = 0;

    local_150 = 0;

    local_14c = 0;

    local_148 = 0;

    local_144 = 0;

    FUN_005961f0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa4),*(uint32_t /* width from decompiler */ *)(param_1 + 0x260),auStack_140,

                 &local_150);

    iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x50,0x27);

    *(uint16_t *)(iVar1 + 4) = 0x50;

    uStack_2c = 3;

    iVar1 = FUN_006356a0(auStack_78);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x40) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

    uStack_2c = 0xffffffff;

    iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0x2c,0x27);

    *(uint16_t *)(iVar3 + 4) = 0x2c;

    uStack_34 = 4;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_006353b0(iVar1);

    uStack_34 = 0xffffffff;

    FUN_006352e0(0x3f800000);

    FUN_006352d0(0x3f000000);

    fStack_154 = (float)(**(code **)(*DAT_00b05060 + 0x10))(0x34,0x27);

    *(uint16_t *)((int)fStack_154 + 4) = 0x34;

    uStack_14 = 5;

    puVar5 = (uint32_t /* width from decompiler */ *)

             FUN_006351b0(puVar4,*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x14) + 0x2c) + 0xe4a4)

                         );

    uStack_14 = 0xffffffff;

    puVar5[10] = *(float *)(param_1 + 0xac) * *(float *)(param_1 + 0xac);

    *(uint8_t *)((int)puVar5 + 0x2d) = 0;

    *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;

    if (*(short *)((int)puVar4 + 6) == 0) {

      (**(code **)*puVar4)(1);

    }

    *(short *)((int)puStack_158 + 6) = *(short *)((int)puStack_158 + 6) + -1;

    if (*(short *)((int)puStack_158 + 6) == 0) {

      (**(code **)*puStack_158)(1);

    }

    FUN_0055f210(puVar5);

    *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;

    if (*(short *)((int)puVar5 + 6) == 0) {

      (**(code **)*puVar5)(1);

    }

  }

  ExceptionList = local_1c;

  return;

}
