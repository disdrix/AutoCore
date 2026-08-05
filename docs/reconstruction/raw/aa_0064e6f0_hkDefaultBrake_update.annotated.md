# Annotated low-level: hkDefaultBrake_update

| Field | Value |
|---|---|
| Stable ID | `aa_0064e6f0` |
| VA | `0x0064e6f0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064e6f0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* WI-MOV-005: reads fw+0x14 status +0x10 brake pedal, +0x18 handbrake. Per-wheel brake torque →
   brake+0x10[i]; locks → +0x1c. Live coast path when pedal≈0 and handbrake off. */

void __thiscall hkDefaultBrake_update(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  float fVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  
  fVar1 = param_2[1];
  iVar7 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  iVar8 = *(int *)(*(int *)(param_1 + 8) + 0x14);
  fVar2 = *(float *)(iVar8 + 0x10);
  cVar3 = *(char *)(iVar8 + 0x18);
  iVar8 = 0;
  bVar6 = false;
  if (0 < *(int *)(param_1 + 0xc)) {
    iVar9 = 0;
    do {
      *(bool *)(iVar8 + *(int *)(param_1 + 0x1c)) =
           *(char *)(iVar8 + *(int *)(param_1 + 0x40)) != '\0' && cVar3 != '\0';
      if (*(float *)(*(int *)(param_1 + 0x34) + iVar8 * 4) <= fVar2) {
        bVar6 = true;
      }
      iVar4 = *(int *)(iVar7 + 0x80);
      fVar10 = *(float *)(*(int *)(iVar7 + 0x10) + iVar8 * 4);
      fVar5 = fVar2 * *(float *)(*(int *)(param_1 + 0x28) + iVar8 * 4);
      fVar10 = (0.0 - *(float *)(iVar4 + 0x8c + iVar9) * fVar10 *
                      *(float *)(iVar4 + 0x84 + iVar9) * fVar1) * fVar10;
      fVar11 = fVar10;
      if ((fVar5 < ABS(fVar10)) && (fVar11 = fVar5, fVar10 <= 0.0)) {
        fVar11 = 0.0 - fVar5;
      }
      *(float *)(*(int *)(param_1 + 0x10) + iVar8 * 4) = fVar11;
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 0xc0;
    } while (iVar8 < *(int *)(param_1 + 0xc));
    if (bVar6) {
      if (0.0 < *(float *)(param_1 + 0x50)) {
        *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x50) - *param_2;
        return;
      }
      iVar7 = 0;
      if (*(int *)(param_1 + 0xc) < 1) {
        return;
      }
      do {
        if (*(float *)(*(int *)(param_1 + 0x34) + iVar7 * 4) <= fVar2) {
          *(undefined1 *)(iVar7 + *(int *)(param_1 + 0x1c)) = 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0xc));
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x4c);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
