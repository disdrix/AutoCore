// =============================================================================
// FUN_004eb560
// -----------------------------------------------------------------------------
// Stable ID: aa_004eb560
// Address:   0x004eb560  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void FUN_004eb560(int *param_1,char *param_2,float param_3,float param_4,int *param_5,char param_6,
                 char param_7)

{
  char cVar1;
  uint32_t /* width from decompiler */ *puVar2;
  float fVar3;
  short sVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  uint32_t /* width from decompiler */ uVar10;
  uint32_t /* width from decompiler */ *puVar11;
  uint32_t /* width from decompiler */ *puVar12;
  uint uVar13;
  uint32_t /* width from decompiler */ *puVar14;
  void *pvVar15;
  char *pcVar16;
  float fVar17;
  uint32_t /* width from decompiler */ *puStack_23c;
  uint uStack_238;
  void *local_234;
  uint auStack_230 [4];
  void *pvStack_220;
  uint32_t /* width from decompiler */ uStack_21c;
  uint8_t auStack_218 [4];
  char local_214 [6];
  uint8_t local_20e [253];
  char cStack_111;
  char local_110 [4];
  char local_10c [4];
  char local_108 [4];
  char local_104 [4];
  char local_100 [244];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2796;
  local_c = ExceptionList;
  pvVar15 = (void *)*param_5;
  if (pvVar15 != (void *)0x0) {
    pcVar5 = param_2;
    do {
      cVar1 = *pcVar5;
      pcVar5[(int)(local_214 + -(int)param_2)] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    puVar2 = (uint32_t /* width from decompiler */ *)(auStack_218 + 3);
    do {
      puVar12 = puVar2;
      puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar12 + 1);
    } while (*(char *)((int)puVar12 + 1) != '\0');
    *(uint32_t /* width from decompiler */ *)((int)puVar12 + 1) = DAT_009cccf0;
    *(uint16_t *)((int)puVar12 + 5) = DAT_009cccf4;
    *(uint8_t *)((int)puVar12 + 7) = DAT_009cccf6;
    local_10c = (char  [4])s____physics_physx__00a96084._4_4_;
    local_110 = (char  [4])s____physics_physx__00a96084._0_4_;
    local_108 = (char  [4])s____physics_physx__00a96084._8_4_;
    local_100._0_2_ = s____physics_physx__00a96084._16_2_;
    local_104 = (char  [4])s____physics_physx__00a96084._12_4_;
    pcVar5 = local_214;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar6 = (int)pcVar5 - (int)local_214;
    pcVar5 = &cStack_111;
    do {
      pcVar16 = pcVar5 + 1;
      pcVar5 = pcVar5 + 1;
    } while (*pcVar16 != '\0');
    pcVar16 = local_214;
    for (uVar13 = uVar6 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar16;
      pcVar16 = pcVar16 + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar5 = *pcVar16;
      pcVar16 = pcVar16 + 1;
      pcVar5 = pcVar5 + 1;
    }
    if (param_1 != (int *)0x0) {
      ExceptionList = &local_c;
      local_234 = pvVar15;
      iVar7 = (**(code **)(*param_1 + 0x1c))();
      if (iVar7 == 0) {
        (**(code **)*param_1)(1);
        FUN_007a4480(1,"Rigid body of PhysX object \'%s\' is zero length",param_2);
      }
      else {
        uStack_238 = 0;
        FUN_00766e50(local_214,0xff);
        iVar7 = sscanf(local_214,"%ld",&uStack_238);
        if ((uStack_238 == 0) || (iVar7 != 1)) {
          FUN_007a4480(1,"No vertices for PhysX object \'%s\'",param_2);
        }
        uVar6 = uStack_238;
        puStack_23c = operator_new__(uStack_238 * 0xc);
        uStack_4 = 0;
        if (puStack_23c == (void *)0x0) {
          puStack_23c = (void *)0x0;
        }
        else {
          FUN_00404d80(puStack_23c,0xc,uVar6,FUN_005edf20);
        }
        uVar6 = 0;
        uStack_4 = 0xffffffff;
        if (uStack_238 != 0) {
          iVar7 = (int)puStack_23c + 4;
          do {
            FUN_00766e50(local_214,0xff);
            iVar8 = sscanf(local_214,"%f %f %f",iVar7 + -4,iVar7,iVar7 + 4);
            if (iVar8 != 3) {
              FUN_007a4480(1,"Invalid vertex %ld for PhysX object \'%s\'",uVar6,param_2);
            }
            uVar6 = uVar6 + 1;
            iVar7 = iVar7 + 0xc;
          } while (uVar6 < uStack_238);
        }
        if ((param_4 != g_flOne) && (uVar6 = 0, uStack_238 != 0)) {
          pfVar9 = (float *)((int)puStack_23c + 8);
          do {
            pfVar9[-2] = pfVar9[-2] * param_4;
            pfVar9[-1] = pfVar9[-1] * param_4;
            *pfVar9 = *pfVar9 * param_4;
            uVar6 = uVar6 + 1;
            pfVar9 = pfVar9 + 3;
          } while (uVar6 < uStack_238);
        }
        auStack_230[1] = 0;
        auStack_230[3] = 0;
        uStack_21c = 0;
        auStack_230[2] = 0xc;
        pvStack_220 = puStack_23c;
        auStack_218 = (uint8_t  [4])0x4;
        auStack_230[0] = uStack_238;
        uVar10 = FUN_004b4bf0(auStack_230);
        if (puStack_23c != (void *)0x0) {
          operator_delete__(puStack_23c);
        }
        *(uint32_t /* width from decompiler */ *)((int)pvVar15 + 0x34) = 0;
        puStack_23c = operator_new(0x70);
        fVar17 = g_flOne;
        if (puStack_23c == (uint32_t /* width from decompiler */ *)0x0) {
          puStack_23c = (uint32_t /* width from decompiler */ *)0x0;
        }
        else {
          puStack_23c[1] = 5;
          puStack_23c[0xd] = 0;
          puStack_23c[0xc] = 0;
          puStack_23c[0xb] = 0;
          puStack_23c[3] = 0;
          puStack_23c[4] = 0;
          puStack_23c[5] = 0;
          puStack_23c[7] = 0;
          puStack_23c[8] = 0;
          puStack_23c[9] = 0;
          puStack_23c[2] = fVar17;
          puStack_23c[6] = fVar17;
          puStack_23c[10] = fVar17;
          puStack_23c[3] = 0;
          puStack_23c[4] = 0;
          puStack_23c[5] = 0;
          puStack_23c[7] = 0;
          puStack_23c[8] = 0;
          puStack_23c[9] = 0;
          puStack_23c[2] = fVar17;
          puStack_23c[6] = fVar17;
          puStack_23c[10] = fVar17;
          puStack_23c[0xd] = 0;
          puStack_23c[0xc] = 0;
          puStack_23c[0xb] = 0;
          *puStack_23c = &PTR_FUN_009cb228;
          puStack_23c[3] = 0;
          puStack_23c[4] = 0;
          puStack_23c[5] = 0;
          puStack_23c[7] = 0;
          puStack_23c[8] = 0;
          puStack_23c[9] = 0;
          puStack_23c[2] = fVar17;
          puStack_23c[6] = fVar17;
          puStack_23c[10] = fVar17;
          puStack_23c[0xd] = 0;
          puStack_23c[0xc] = 0;
          puStack_23c[0xb] = 0;
          fVar3 = DAT_00aaa668;
          puStack_23c[0xe] = 8;
          *(uint16_t *)(puStack_23c + 0xf) = 0;
          *(uint16_t *)((int)puStack_23c + 0x3e) = 0;
          puStack_23c[0x10] = 0;
          puStack_23c[0x13] = fVar3;
          puStack_23c[0x11] = fVar17;
          puStack_23c[0x12] = fVar3;
          puStack_23c[0x14] = 0;
          puStack_23c[0x15] = 0;
          puStack_23c[0x16] = 0;
          puStack_23c[0x17] = 0;
          puStack_23c[0x18] = 0;
          puStack_23c[0x19] = 0;
          puStack_23c[0x1a] = 0;
          puStack_23c[0x1b] = 0;
        }
        puStack_23c[0x1a] = uVar10;
        if (param_7 == '\0') {
          sVar4 = (param_6 != '\0') + 1;
        }
        else {
          sVar4 = 4;
        }
        *(short *)(puStack_23c + 0xf) = sVar4;
        if (*(uint *)((int)pvVar15 + 0x58) <= *(uint *)((int)pvVar15 + 0x54)) {
          iVar7 = *(int *)((int)pvVar15 + 0x50);
          uVar6 = ((int)(*(uint *)((int)pvVar15 + 0x54) - iVar7) >> 2) * 2 + 2;
          if (iVar7 == 0) {
            uVar13 = 0;
          }
          else {
            uVar13 = (int)(*(uint *)((int)pvVar15 + 0x58) - iVar7) >> 2;
          }
          if (uVar13 < uVar6) {
            puVar11 = malloc(uVar6 * 4);
            puVar2 = *(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x54);
            puVar12 = *(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x50);
            puVar14 = puVar11;
            for (; puVar12 != puVar2; puVar12 = puVar12 + 1) {
              *puVar14 = *puVar12;
              puVar14 = puVar14 + 1;
              pvVar15 = local_234;
            }
            if (*(void **)((int)pvVar15 + 0x50) != (void *)0x0) {
              free(*(void **)((int)pvVar15 + 0x50));
            }
            iVar7 = *(int *)((int)pvVar15 + 0x50);
            *(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x58) = puVar11 + uVar6;
            *(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x50) = puVar11;
            *(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x54) =
                 puVar11 + (*(int *)((int)pvVar15 + 0x54) - iVar7 >> 2);
          }
        }
        iVar7 = 0;
        **(uint32_t /* width from decompiler */ **)((int)pvVar15 + 0x54) = puStack_23c;
        *(int *)((int)pvVar15 + 0x54) = *(int *)((int)pvVar15 + 0x54) + 4;
        pfVar9 = operator_new(0x84);
        fVar17 = g_flOne;
        if (pfVar9 == (float *)0x0) {
          pfVar9 = (float *)0x0;
        }
        else {
          pfVar9[0xb] = 0.0;
          pfVar9[10] = 0.0;
          pfVar9[9] = 0.0;
          fVar3 = DAT_009c7b84;
          *pfVar9 = fVar17;
          pfVar9[1] = 0.0;
          pfVar9[2] = 0.0;
          pfVar9[3] = 0.0;
          pfVar9[4] = fVar17;
          pfVar9[5] = 0.0;
          pfVar9[6] = 0.0;
          pfVar9[7] = 0.0;
          pfVar9[8] = fVar17;
          pfVar9[0xb] = 0.0;
          pfVar9[10] = 0.0;
          pfVar9[9] = 0.0;
          pfVar9[0xe] = 0.0;
          pfVar9[0xd] = 0.0;
          pfVar9[0xc] = 0.0;
          pfVar9[0x12] = 0.0;
          pfVar9[0x11] = 0.0;
          pfVar9[0x10] = 0.0;
          pfVar9[0x15] = 0.0;
          pfVar9[0x14] = 0.0;
          pfVar9[0x13] = 0.0;
          pfVar9[0x16] = fVar3;
          pfVar9[0x18] = DAT_00a10e78;
          fVar3 = DAT_00aaa668;
          pfVar9[0xf] = 0.0;
          pfVar9[0x17] = 0.0;
          pfVar9[0x19] = fVar3;
          pfVar9[0x1c] = fVar3;
          pfVar9[0x1d] = fVar3;
          pfVar9[0x1a] = 0.0;
          pfVar9[0x1e] = 5.60519e-45;
          pfVar9[0x1b] = 3.22859e-42;
          pfVar9[0x1f] = fVar3;
          pfVar9[0x20] = 0.0;
        }
        fVar3 = DAT_00a0f298;
        if (param_3 != 0.0) {
          fVar17 = param_3;
        }
        pfVar9[0xf] = fVar17;
        pfVar9[0x18] = fVar3;
        pfVar9[0x1e] = 1.4013e-45;
        pfVar9[0x1b] = (float)((-(uint)(param_6 != '\0') & 0xffffff80) + 0x80);
        *(float **)((int)pvVar15 + 0x30) = pfVar9;
        local_234 = operator_new(0x6c);
        uStack_4 = 1;
        if (local_234 != (void *)0x0) {
          iVar7 = FUN_005eddd0(pvVar15,*DAT_00b037f0);
        }
        uStack_4 = 0xffffffff;
        FUN_004b52e0(local_110,param_5 + 0x18);
        pvVar15 = (void *)*param_5;
        if (pvVar15 != (void *)0x0) {
          FUN_004b55e0();
                    /* WARNING: Subroutine does not return */
          operator_delete(pvVar15);
        }
        *param_5 = iVar7;
      }
    }
  }
  ExceptionList = local_c;
  return;
}
