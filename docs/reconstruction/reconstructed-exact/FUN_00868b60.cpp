// =============================================================================
// FUN_00868b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00868b60
// Address:   0x00868b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00868b60 @ 0x00868b60
// Stable ID: aa_00868b60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~115 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00791f30×2, FUN_00868b60.
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

void __thiscall FUN_00868b60(int *param_1,uint8_t *param_2)



{

  char cVar1;

  float *pfVar2;

  int iVar3;

  uint8_t *puVar4;

  float fVar5;

  float fStack_4c;

  uint8_t *puStack_48;

  uint8_t *puStack_44;

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [8];

  uint8_t auStack_28 [4];

  uint8_t auStack_24 [4];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [4];

  uint8_t auStack_18 [8];

  uint8_t auStack_10 [12];

  

  if (param_1[0x13f] != 0) {

    puStack_44 = (uint8_t *)0x868b88;

    cVar1 = (**(code **)(*(int *)param_1[0x13f] + 0xf8))();

    if (cVar1 == '\0') {

      puStack_44 = (uint8_t *)0x868b96;

      (**(code **)(*param_1 + 0x448))();

      puStack_44 = param_2;

      puStack_48 = (uint8_t *)0x868ba1;

      FUN_00791f30();

      return;

    }

    puStack_44 = (uint8_t *)0x868bf0;

    (**(code **)(*(int *)param_1[0x13f] + 0xe8))();

    puStack_44 = auStack_28;

    puStack_48 = (uint8_t *)0x868c1c;

    (**(code **)(*(int *)param_1[0x13f] + 0x134))();

    puStack_48 = auStack_24;

    fStack_4c = 1.2356248e-38;

    (**(code **)(*(int *)param_1[0x13f] + 0x124))();

    fStack_4c = 0.0;

    puVar4 = auStack_20;

    (**(code **)(*(int *)param_1[0x13f] + 0x120))(puVar4,1);

    puStack_44 = (uint8_t *)(int)(float)puStack_48;

    (**(code **)(*(int *)param_1[0x13f] + 0x110))(&puStack_44);

    pfVar2 = (float *)(**(code **)(*(int *)param_1[0x13f] + 0x134))(auStack_30);

    fStack_4c = (float)DAT_00d1e818 * (g_flOne - (float)puVar4) * *pfVar2 * DAT_00aaa67c;

    iVar3 = (**(code **)(*(int *)param_1[0x13f] + 0x140))(&stack0xffffffc4,1);

    puStack_48 = *(uint8_t **)(iVar3 + 4);

    fStack_4c = (float)(int)(float)puVar4;

    (**(code **)(*(int *)param_1[0x13f] + 300))(&fStack_4c);

    (**(code **)(*(int *)param_1[0x13f] + 0x34c))();

    if (param_1[0x142] != 0) {

      puStack_44 = auStack_18;

      puStack_48 = (uint8_t *)0x868d48;

      (**(code **)(*(int *)param_1[0x142] + 0x134))();

      puStack_48 = auStack_24;

      fStack_4c = 1.2356668e-38;

      (**(code **)(*(int *)param_1[0x142] + 0x124))();

      fStack_4c = 0.0;

      fVar5 = 1.4013e-45;

      puVar4 = auStack_18;

      (**(code **)(*(int *)param_1[0x142] + 0x120))(puVar4,1);

      (**(code **)(*(int *)param_1[0x142] + 0x110))(&stack0xffffffc4);

      pfVar2 = (float *)(**(code **)(*(int *)param_1[0x142] + 0x134))(auStack_28);

      fStack_4c = (float)DAT_00d1e818 * fVar5 * *pfVar2 * DAT_00aaa67c;

      iVar3 = (**(code **)(*(int *)param_1[0x142] + 0x140))(auStack_34,1);

      puStack_48 = *(uint8_t **)(iVar3 + 4);

      fStack_4c = (float)(int)(float)puVar4;

      (**(code **)(*(int *)param_1[0x142] + 300))(&fStack_4c);

      (**(code **)(*(int *)param_1[0x142] + 0x34c))();

    }

    if (param_1[0x141] != 0) {

      puStack_44 = auStack_10;

      puStack_48 = (uint8_t *)0x868e66;

      (**(code **)(*(int *)param_1[0x141] + 0x134))();

      puStack_48 = auStack_1c;

      fStack_4c = 1.2357069e-38;

      (**(code **)(*(int *)param_1[0x141] + 0x124))();

      fStack_4c = 0.0;

      fVar5 = 1.4013e-45;

      puVar4 = auStack_28;

      (**(code **)(*(int *)param_1[0x141] + 0x120))(puVar4,1);

      (**(code **)(*(int *)param_1[0x141] + 0x110))(&stack0xffffffc4);

      pfVar2 = (float *)(**(code **)(*(int *)param_1[0x141] + 0x134))(auStack_28);

      fStack_4c = (float)DAT_00d1e818 * fVar5 * *pfVar2 * DAT_00aaa67c;

      iVar3 = (**(code **)(*(int *)param_1[0x141] + 0x140))(auStack_34,1);

      puStack_48 = *(uint8_t **)(iVar3 + 4);

      fStack_4c = (float)(int)(float)puVar4;

      (**(code **)(*(int *)param_1[0x141] + 300))(&fStack_4c);

      (**(code **)(*(int *)param_1[0x141] + 0x34c))();

    }

    if (param_1[0x140] != 0) {

      puStack_44 = auStack_10;

      puStack_48 = (uint8_t *)0x868f84;

      (**(code **)(*(int *)param_1[0x140] + 0x134))();

      puStack_48 = auStack_1c;

      fStack_4c = 1.235747e-38;

      (**(code **)(*(int *)param_1[0x140] + 0x124))();

      fStack_4c = 0.0;

      fVar5 = 1.4013e-45;

      puVar4 = auStack_28;

      (**(code **)(*(int *)param_1[0x140] + 0x120))(puVar4,1);

      (**(code **)(*(int *)param_1[0x140] + 0x110))(&stack0xffffffc4);

      pfVar2 = (float *)(**(code **)(*(int *)param_1[0x140] + 0x134))(auStack_28);

      fStack_4c = (float)DAT_00d1e818 * fVar5 * *pfVar2 * DAT_00aaa67c;

      iVar3 = (**(code **)(*(int *)param_1[0x140] + 0x140))(auStack_34,1);

      puStack_48 = *(uint8_t **)(iVar3 + 4);

      fStack_4c = (float)(int)(float)puVar4;

      (**(code **)(*(int *)param_1[0x140] + 300))(&fStack_4c);

      (**(code **)(*(int *)param_1[0x140] + 0x34c))();

    }

  }

  puStack_44 = param_2;

  puStack_48 = (uint8_t *)0x869090;

  FUN_00791f30();

  return;

}
