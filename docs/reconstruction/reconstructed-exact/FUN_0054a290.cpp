// =============================================================================
// FUN_0054a290
// -----------------------------------------------------------------------------
// Stable ID: aa_0054a290
// Address:   0x0054a290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054a290 @ 0x0054a290
// Stable ID: aa_0054a290
// Embedded strings (evidence for future rename):
//   - "Skill %d had no skill elements - it won\'t work."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~157 non-empty decompiler lines.
//  - Control keywords: if×13, for×5, return×3.
//  - Notable callees: CONCAT31×5, FUN_00403450×3, free×3, FUN_00418890, FUN_005495f0, FUN_0054a290, FUN_0054cc10, FUN_0054d9a0.
//  - Strings: "Skill %d had no skill elements - it won\'t work.".
//  - Return sites: 3.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void FUN_0054a290(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  undefined3 uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int local_134c [2];

  uint8_t *local_1344;

  uint8_t local_1340 [128];

  uint8_t *puStack_12c0;

  uint8_t auStack_12bc [128];

  uint8_t *puStack_123c;

  uint8_t auStack_1238 [128];

  uint32_t /* width from decompiler */ local_11b8;

  byte local_11b4;

  uint8_t local_11b2;

  uint8_t local_11b1;

  uint8_t local_11b0;

  uint32_t /* width from decompiler */ local_11ac;

  uint8_t local_11a3;

  uint32_t /* width from decompiler */ local_11a0;

  uint32_t /* width from decompiler */ local_119c;

  uint32_t /* width from decompiler */ local_1198;

  uint32_t /* width from decompiler */ local_1194;

  uint32_t /* width from decompiler */ local_c7c [397];

  uint32_t /* width from decompiler */ auStack_648 [395];

  uint32_t /* width from decompiler */ uStack_1c;

  void *local_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a4451;

  local_14 = ExceptionList;

  uStack_1c = 0x54a2b6;

  if (*(short *)(param_1 + 0x24b) == 0) {

    ExceptionList = &local_14;

    FUN_007a4480(0xffffffff,"Skill %d had no skill elements - it won\'t work.",*param_1);

    ExceptionList = local_14;

    return;

  }

  ExceptionList = &local_14;

  FUN_0054cc10();

  puVar6 = &local_11b8;

  for (iVar5 = 0x14e; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  cVar1 = *(char *)(param_1 + 0x242);

  if (cVar1 == '\x01') {

    local_11b8._1_1_ = local_11b8._1_1_ | 0x10;

  }

  if (cVar1 == '\x02') {

    local_11b8._1_1_ = local_11b8._1_1_ | 8;

  }

  if (cVar1 == '\x03') {

    local_11b2 = 1;

  }

  if (cVar1 == '\x04') {

    local_11b1 = 1;

  }

  if (cVar1 == '\x05') {

    local_11b0 = 1;

  }

  if (param_1[0x240] != 0) {

    local_11b8._1_1_ = local_11b8._1_1_ | 0x40;

  }

  if (param_1[0x241] != 0) {

    local_11b4 = local_11b4 | 1;

  }

  local_119c = param_1[0x248];

  local_11ac = param_1[0x246];

  local_11a0 = param_1[0x247];

  local_1198 = param_1[0x249];

  local_1194 = param_1[0x24a];

  local_11a3 = 1;

  FUN_005495f0(param_1,&local_11b8);

  FUN_0054d9a0(local_134c,param_1);

  if (local_134c[0] == DAT_00b0472c) {

    local_c7c[0] = *param_1;

    puVar6 = local_c7c;

    puVar7 = &local_11b8;

    for (iVar5 = 0x14e; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar6 = *puVar7;

      puVar7 = puVar7 + 1;

    }

    FUN_0054e9a0(local_134c,local_c7c);

  }

  else {

    puVar6 = &local_11b8;

    puVar7 = (uint32_t /* width from decompiler */ *)(local_134c[0] + 0x10);

    for (iVar5 = 0x14e; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

  }

  uVar2 = param_1[9];

  local_1344 = local_1340;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_1 + 0x21f,uVar3);

  puStack_12c0 = auStack_12bc;

  uStack_c = 0;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450((int)param_1 + 0x7a,uVar3);

  puStack_123c = auStack_1238;

  uStack_c._0_1_ = 1;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(param_1 + 0xe,uVar3);

  uStack_c = CONCAT31(uStack_c._1_3_,2);

  uVar4 = (undefined3)((uint)(param_1[5] | param_1[4]) >> 8);

  Skill_InitializeRuntimeObject

            (CONCAT31(uVar4,*(uint8_t *)(param_1 + 0xd)),

             CONCAT31((int3)((uint)*param_1 >> 8),*(uint8_t *)((int)param_1 + 0x35)),0xff,

             CONCAT31((int3)((uint)param_1[3] >> 8),*(uint8_t *)((int)param_1 + 0x36)),

             CONCAT31(uVar4,*(uint8_t *)((int)param_1 + 0x909)),*param_1,param_1[3],

             param_1[5] | param_1[4],param_1[6],param_1[8] | param_1[7],

             -(uint)(uVar2 != 0xffffffff) & uVar2,param_1[2],param_1[1],

             *(uint8_t *)((int)param_1 + 0x37),param_1[0x243] == 1,param_1[0x244],param_1[0x245],

             puStack_123c,puStack_12c0,local_1344,param_1[10],param_1[0xb],param_1[0xc]);

  if (puStack_123c != auStack_1238) {

    free(puStack_123c);

  }

  if (puStack_12c0 != auStack_12bc) {

    free(puStack_12c0);

  }

  uStack_c = 0xffffffff;

  if (local_1344 != local_1340) {

    free(local_1344);

  }

  FUN_00418890(local_134c,param_1);

  if (local_134c[0] != DAT_00b04738) {

    puVar6 = (uint32_t /* width from decompiler */ *)(local_134c[0] + 0x10);

    puVar7 = local_c7c;

    for (iVar5 = 0x18c; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = *puVar6;

      puVar6 = puVar6 + 1;

      puVar7 = puVar7 + 1;

    }

    Skill_CopyRuntimeFieldsFromTemplate(auStack_648);

    ExceptionList = local_14;

    return;

  }

  local_c7c[0] = *param_1;

  puVar6 = local_c7c;

  puVar7 = auStack_648;

  for (iVar5 = 0x18c; puVar6 = puVar6 + 1, iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = *puVar7;

    puVar7 = puVar7 + 1;

  }

  FUN_0054ea60(local_134c,local_c7c);

  ExceptionList = local_14;

  return;

}
