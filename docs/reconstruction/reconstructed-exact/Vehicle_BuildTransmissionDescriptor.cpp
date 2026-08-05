// =============================================================================
// Vehicle_BuildTransmissionDescriptor
// -----------------------------------------------------------------------------
// Stable ID: aa_005fc840
// Address:   0x005fc840  (autoassault.exe, image base 0x400000)
// System:    missions-progression
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

void Vehicle_BuildTransmissionDescriptor(float param_1,uint32_t /* width from decompiler */ param_2,uint8_t *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  uint8_t uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float fVar12;
  
  iVar5 = (int)param_1;
  uVar10 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                            (int)param_1) + 0x3c) + 0x699);
  if ((*(uint *)(param_3 + 0x20) & 0x7fffffff) < uVar10) {
    uVar8 = (*(uint *)(param_3 + 0x20) & 0x7fffffff) * 2;
    if ((int)uVar8 <= (int)uVar10) {
      uVar8 = uVar10;
    }
    FUN_005b3300(param_3 + 0x18,uVar8,4);
  }
  *(uint *)(param_3 + 0x1c) = uVar10;
  cVar6 = FUN_004f5560();
  iVar11 = (int)cVar6;
  piVar1 = (int *)(param_3 + 0x24);
  if ((int)(*(uint *)(param_3 + 0x2c) & 0x7fffffff) < iVar11) {
    iVar9 = (*(uint *)(param_3 + 0x2c) & 0x7fffffff) * 2;
    if (iVar9 <= iVar11) {
      iVar9 = iVar11;
    }
    FUN_005b3300(piVar1,iVar9,4);
  }
  *(int *)(param_3 + 0x28) = iVar11;
  uVar7 = FUN_004f5560();
  *param_3 = uVar7;
  *(float *)(param_3 + 4) =
       (float)(int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                               (int)param_1) + 0x3c) + 0x69c) *
       *(float *)((int)param_1 + 0x1fc);
  *(float *)(param_3 + 8) =
       (float)(int)*(short *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                               (int)param_1) + 0x3c) + 0x69e) *
       *(float *)((int)param_1 + 0x1fc);
  *(uint32_t /* width from decompiler */ *)(param_3 + 0x14) =
       *(uint32_t /* width from decompiler */ *)
        (*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) + 0x3c) +
        0x6cc);
  *(uint32_t /* width from decompiler */ *)(param_3 + 0xc) =
       *(uint32_t /* width from decompiler */ *)
        (*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) + 0x3c) +
        0x6c4);
  *(uint32_t /* width from decompiler */ *)(param_3 + 0x10) =
       *(uint32_t /* width from decompiler */ *)
        (*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) + 0x3c) +
        0x6c8);
  iVar11 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) + 0x3c)
  ;
  iVar9 = 0;
  if (*(char *)(iVar11 + 0x699) != '\0') {
    do {
      *(uint32_t /* width from decompiler */ *)(*(int *)(param_3 + 0x18) + iVar9 * 4) =
           *(uint32_t /* width from decompiler */ *)(iVar11 + 0x6d0 + (char)iVar9 * 4);
      iVar11 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) +
                       0x3c);
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)(uint)*(byte *)(iVar11 + 0x699));
  }
  iVar11 = (int)*(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 600) + 4) + 4)
                                            + 0xac + *(int *)((int)param_1 + 600)) + 0x3c) + 0x4cc);
  iVar9 = 0;
  if (0 < iVar11) {
    fVar12 = g_flOne / (float)iVar11;
    do {
      *(float *)(*piVar1 + iVar9 * 4) =
           *(float *)(*(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac +
                                       (int)param_1) + 0x3c) + 0x5e8) * fVar12;
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar11);
  }
  cVar6 = FUN_004f5560();
  if (iVar9 < cVar6) {
    do {
      iVar3 = *piVar1;
      iVar2 = iVar9 * 4;
      iVar4 = *(int *)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xac + (int)param_1) +
                      0x3c);
      cVar6 = FUN_004f5560();
      iVar9 = iVar9 + 1;
      *(float *)(iVar3 + iVar2) = *(float *)(iVar4 + 0x5ec) / (float)(cVar6 - iVar11);
      cVar6 = FUN_004f5560();
    } while (iVar9 < cVar6);
  }
  param_1 = 0.0;
  cVar6 = FUN_004f5560();
  if ('\0' < cVar6) {
    iVar11 = 0;
    do {
      param_1 = *(float *)(*piVar1 + iVar11 * 4) + param_1;
      iVar11 = iVar11 + 1;
      cVar6 = FUN_004f5560();
    } while (iVar11 < cVar6);
    if (g_flOne < param_1) {
      FUN_007a4480(0,"Vehicle %d has incorrect wheel torque values: %0.2f",
                   *(uint32_t /* width from decompiler */ *)
                    (*(int *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0xac + iVar5) + 0x34),
                   (double)param_1);
    }
  }
  return;
}
