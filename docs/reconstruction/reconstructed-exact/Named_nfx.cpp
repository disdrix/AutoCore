// =============================================================================
// Named_nfx
// -----------------------------------------------------------------------------
// Stable ID: aa_00542790
// Address:   0x00542790  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_nfx @ 0x00542790
// Stable ID: aa_00542790
// Embedded strings (evidence for future rename):
//   - "_nfx.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×10, goto×4, return×3, do×1, while×1.
//  - Notable callees: FUN_004ed310×2, FUN_0054b480×2, FUN_005b2ba0×2, FUN_00971820×2, CNDHash_LookupByKey, FUN_00418890, FUN_0043d650, FUN_0043d670.
//  - Strings: "_nfx.xml".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "_nfx.xml"
 * Domain alias of FUN_00542790 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Named_nfx(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            int param_6,int *param_7,uint32_t /* width from decompiler */ param_8)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  void *pvVar5;

  int iVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int local_46c;

  int local_468;

  uint32_t /* width from decompiler */ local_464;

  uint32_t /* width from decompiler */ local_460;

  uint32_t /* width from decompiler */ local_45c;

  uint32_t /* width from decompiler */ local_458;

  int local_454;

  int local_450;

  int local_44c;

  int local_448;

  uint32_t /* width from decompiler */ local_444;

  uint local_440;

  uint32_t /* width from decompiler */ local_43c;

  uint32_t /* width from decompiler */ local_438;

  uint32_t /* width from decompiler */ local_434;

  uint32_t /* width from decompiler */ local_430;

  uint8_t local_42c [4];

  uint8_t local_428 [4];

  uint32_t /* width from decompiler */ local_424;

  uint32_t /* width from decompiler */ local_420;

  uint32_t /* width from decompiler */ local_41c;

  uint32_t /* width from decompiler */ local_418;

  uint8_t local_414;

  uint32_t /* width from decompiler */ uStack_40d;

  uint8_t local_404 [1016];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = param_7;

  puStack_8 = &LAB_009a40df;

  local_c = ExceptionList;

  if (*(int *)(DAT_00d1f050 + 0x6c) == 0) {

    return 0;

  }

  local_424 = 0;

  local_420 = 0;

  local_41c = 0;

  local_418 = 0;

  local_43c = param_4;

  local_444 = param_3;

  local_438 = param_5;

  local_4 = 0;

  local_414 = 0;

  local_42c[0] = 0;

  local_430 = 0;

  local_440 = param_2;

  if (param_6 == 0) {

    puVar3 = &DAT_009d00a8;

  }

  else {

    puVar3 = (uint32_t /* width from decompiler */ *)(param_6 + 0x160);

  }

  local_464 = *puVar3;

  local_460 = puVar3[1];

  local_45c = puVar3[2];

  local_458 = puVar3[3];

  piVar4 = param_7 + 0x58;

  if (param_7 == (int *)0x0) {

    piVar4 = &DAT_009d00a8;

  }

  local_454 = *piVar4;

  local_450 = piVar4[1];

  local_44c = piVar4[2];

  local_448 = piVar4[3];

  local_434 = param_8;

  ExceptionList = &local_c;

  local_468 = param_1;

  pvVar5 = CNDHash_LookupByKey(*(void **)(param_1 + 0xf0c),param_2);

  if (pvVar5 == (void *)0x0) goto LAB_00542a35;

  if (*(char *)((int)pvVar5 + 10) == '\0') {

    puVar3 = &param_2;

    piVar4 = &local_46c;

    FUN_0054b480(piVar4,puVar3);

    FUN_00418890(piVar4,puVar3);

    iVar6 = FUN_0054b480();

    if (local_46c == *(int *)(iVar6 + 4)) goto LAB_00542a35;

    FUN_00540090(local_46c + 0x10,(int)&uStack_40d + 1,0x400);

    puVar3 = &uStack_40d;

    do {

      puVar8 = puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

    } while (*(char *)((int)puVar8 + 1) != '\0');

    *(uint32_t /* width from decompiler */ *)((int)puVar8 + 1) = DAT_009ca184;

    *(uint32_t /* width from decompiler */ *)((int)puVar8 + 5) = DAT_009ca188;

    *(uint8_t *)((int)puVar8 + 9) = DAT_009ca18c;

    FUN_00989e00(&local_46c,(int)&uStack_40d + 1);

    FUN_0043d670(&local_46c);

    cVar2 = FUN_004ed310(local_428,local_42c,&local_430);

    if (cVar2 != '\0') {

      pcVar7 = strstr((char *)((int)&uStack_40d + 1),"_nfx.xml");

      if (pcVar7 != (char *)0x0) {

        *pcVar7 = '\0';

        FUN_004a6390((int)&uStack_40d + 1);

      }

      goto LAB_005429aa;

    }

    FUN_00971820(local_428);

    local_414 = 1;

  }

  else {

LAB_005429aa:

    FUN_0043d650(0);

    local_42c[0] = 0;

    local_430 = 0;

    FUN_004a04f0(local_428,1,1,1);

    cVar2 = FUN_004ed310(local_428,local_42c,&local_430);

    if (cVar2 != '\0') {

      iVar6 = FUN_004a16d0(local_444,1,0xffffffff);

      if ((iVar6 == 0) || (piVar1 == (int *)0x0)) {

LAB_00542a35:

        FUN_005b2ba0();

        ExceptionList = local_c;

        return 0;

      }

      (**(code **)(*piVar1 + 0x238))

                (local_444,local_440,local_43c,local_438,param_6,local_434,1,iVar6);

      goto LAB_00542a68;

    }

    FUN_00971820(local_428);

  }

  FUN_00545d70(&local_464);

LAB_00542a68:

  FUN_005b2ba0();

  ExceptionList = local_c;

  return 1;

}
