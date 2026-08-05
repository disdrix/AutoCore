# Raw capture: hkVehicleFrictionSolver_circleProjection

| Field | Value |
|---|---|
| **Stable ID** | `aa_006c3f90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006c3f90` |
| **Canonical name** | `hkVehicleFrictionSolver_circleProjection` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall hkVehicleFrictionSolver_circleProjection(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *unaff_ESI;
  float local_c;
  float local_8;
  float local_4;
  
  fVar1 = *(float *)(param_1 + 0x94) * *(float *)(param_1 + 0x84);
  fVar3 = *(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x80);
  if (g_flOne <= fVar1 * fVar1 + fVar3 * fVar3) {
    fVar1 = fVar1 * unaff_ESI[0x11];
    iVar7 = 0;
    local_8 = 0.0;
    local_4 = 0.0;
    local_c = 0.0;
    fVar4 = fVar3 * *unaff_ESI;
    fVar5 = fVar1 * fVar1 + fVar4 * fVar4;
    while ((fVar5 <= g_flOne && (iVar7 = iVar7 + 1, iVar7 < 0x10))) {
      fVar2 = fVar1 * unaff_ESI[0x10];
      fVar6 = fVar3 * unaff_ESI[iVar7];
      local_8 = fVar1;
      local_4 = fVar4;
      local_c = fVar5;
      fVar1 = fVar2;
      fVar4 = fVar6;
      fVar5 = fVar2 * fVar2 + fVar6 * fVar6;
    }
    fVar3 = g_flOne / ((SQRT(fVar5) - g_flOne) - (SQRT(local_c) - g_flOne));
    fVar2 = -(fVar3 * (SQRT(local_c) - g_flOne));
    fVar3 = (SQRT(fVar5) - g_flOne) * fVar3;
    fVar5 = (fVar2 * fVar1 + local_8 * fVar3) * *(float *)(param_1 + 0x8c);
    fVar3 = (fVar3 * local_4 + fVar2 * fVar4) * *(float *)(param_1 + 0x88);
    fVar1 = *(float *)(param_1 + 0x84);
    *(float *)(param_1 + 0x84) = fVar5;
    *(float *)(param_1 + 0x98) = *(float *)(param_1 + 0x80) - fVar3;
    *(float *)(param_1 + 0x80) = fVar3;
    fVar3 = *(float *)(param_1 + 0x7c) * *(float *)(param_1 + 0x98) * *(float *)(param_1 + 0x88);
    fVar1 = (fVar1 - fVar5) * *(float *)(param_1 + 0x74) * *(float *)(param_1 + 0x8c);
    *(float *)(param_2 + 8) =
         SQRT((fVar3 * fVar3 + fVar1 * fVar1) *
              (g_flOne /
              (*(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x68) +
              *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x60))));
    return;
  }
  *(undefined4 *)(param_1 + 0x98) = 0;
  return;
}
```
