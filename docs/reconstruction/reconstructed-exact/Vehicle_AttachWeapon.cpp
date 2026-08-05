// =============================================================================
// Vehicle_AttachWeapon
// -----------------------------------------------------------------------------
// Stable ID: aa_004fdf20
// Address:   0x004fdf20  (autoassault.exe, image base 0x400000)
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

void __thiscall Vehicle_AttachWeapon(int param_1,int param_2,uint param_3,char param_4)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  float fVar4;
  
  if (param_3 < 3) {
    FUN_00512670();
    if (param_4 == '\0') {
      if (*(int *)(*(int *)(param_1 + 0x260) + param_3 * 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + 0x260) + param_3 * 4);
        iVar3 = *(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3;
      }
      FUN_004fbb50(iVar3);
    }
    if (*(int *)(*(int *)(param_1 + 0x260) + param_3 * 4) != 0) {
      FUN_00569d50();
    }
    *(int *)(*(int *)(param_1 + 0x260) + param_3 * 4) = param_2;
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x630 + param_3 * 8) = 0xffffffff;
    *(uint32_t /* width from decompiler */ *)(param_1 + 0x634 + param_3 * 8) = 0xffffffff;
    if (param_2 != 0) {
      if (*(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0xac + param_2) + 0x38) != 0xc) {
        iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);
        FUN_007a4480(1,"Set weapon of unhappy type: CBID:%d COID:%I64d Slot:%u",
                     *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + param_2 + 0xac) + 0x34),
                     *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + param_2),
                     *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + param_2),param_3);
      }
      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0xb8))(0x3f800000);
      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x158))
                (*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);
      FUN_004fdcb0(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);
      (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x218))
                (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1));
      FUN_0056be70();
      iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);
      *(uint32_t /* width from decompiler */ *)(param_1 + 0x630 + param_3 * 8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + param_2);
      *(uint32_t /* width from decompiler */ *)(param_1 + 0x634 + param_3 * 8) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + param_2);
    }
    piVar2 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    if (piVar2 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar2 + 0x1d8))();
      if (iVar3 != 0) {
        piVar2 = *(int **)(param_1 + 0x260);
        fVar4 = 0.0;
        if ((*piVar2 != 0) && (fVar1 = *(float *)(*piVar2 + 0xe8), 0.0 < fVar1)) {
          fVar4 = fVar1;
        }
        if ((piVar2[1] != 0) && (fVar1 = *(float *)(piVar2[1] + 0xe8), fVar4 < fVar1)) {
          fVar4 = fVar1;
        }
        if ((piVar2[2] != 0) && (fVar1 = *(float *)(piVar2[2] + 0xe8), fVar4 < fVar1)) {
          fVar4 = fVar1;
        }
        if (*(float *)(iVar3 + 0x124) <= fVar4 && fVar4 != *(float *)(iVar3 + 0x124)) {
          *(float *)(iVar3 + 0x124) = fVar4 * g_flInferredThreatScale;
        }
      }
    }
  }
  return;
}
