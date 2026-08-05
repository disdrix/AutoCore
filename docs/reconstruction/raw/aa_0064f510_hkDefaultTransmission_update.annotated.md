# Annotated low-level: hkDefaultTransmission_update

| Field | Value |
|---|---|
| Stable ID | `aa_0064f510` |
| VA | `0x0064f510` |
| System | missions-progression |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0064f510`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
/* hkDefaultTransmission_update (WI-MOV-003b + 004):
   RPM→+0x18 from wheel+0x8c; torque factor→+0x1c = finalDrive*gearRatio*(fw+0x1c+0xc); axle
   [+0x20][i]=frac[i]*+0x1c.
   Reverse via fw+0x14+0x19. Does NOT write wheel+0x20/28.
   WI-MOV-004: +0x1c / axle array NOT consumed by postTickApplyForces or calcWheelTorque (no
   hkDefaultEngine). */

void __fastcall hkDefaultTransmission_update(int param_1)

{
  bool bVar1;
  int iVar2;
  int extraout_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  
  if (*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x14) + 0x19) == '\0') {
    bVar1 = false;
  }
  else {
    bVar1 = *(int *)(param_1 + 0x10) < 1;
  }
  *(bool *)(param_1 + 0x14) = bVar1;
  if (*(char *)(param_1 + 0x58) == '\0') {
    if (bVar1 == false) {
      fVar4 = *(float *)(*(int *)(param_1 + 0x40) + *(int *)(param_1 + 0x10) * 4);
    }
    else {
      fVar4 = 0.0 - *(float *)(param_1 + 0x3c);
    }
    fVar4 = *(float *)(param_1 + 0x34) * fVar4 *
            *(float *)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0xc);
  }
  else {
    fVar4 = 0.0;
  }
  *(float *)(param_1 + 0x1c) = fVar4;
  fVar3 = (float10)hkDefaultTransmission_calcRPM();
  *(float *)(extraout_ECX + 0x18) = (float)fVar3;
  iVar2 = 0;
  if (0 < *(int *)(extraout_ECX + 0x50)) {
    do {
      *(float *)(*(int *)(extraout_ECX + 0x20) + iVar2 * 4) =
           *(float *)(*(int *)(extraout_ECX + 0x4c) + iVar2 * 4) * *(float *)(extraout_ECX + 0x1c);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(extraout_ECX + 0x50));
  }
  fVar4 = *(float *)(*(int *)(extraout_ECX + 8) + 8);
  if ((*(char *)(extraout_ECX + 0x58) != '\0') &&
     (fVar5 = fVar4 - *(float *)(extraout_ECX + 0x5c),
     *(float *)(extraout_ECX + 0x38) <= fVar5 && fVar5 != *(float *)(extraout_ECX + 0x38))) {
    *(undefined1 *)(extraout_ECX + 0x58) = 0;
  }
  if (*(char *)(extraout_ECX + 0x14) == '\0') {
    if ((*(float *)(extraout_ECX + 0x18) <= *(float *)(extraout_ECX + 0x2c) &&
         *(float *)(extraout_ECX + 0x2c) != *(float *)(extraout_ECX + 0x18)) &&
       (0 < *(int *)(extraout_ECX + 0x10))) {
      *(int *)(extraout_ECX + 0x10) = *(int *)(extraout_ECX + 0x10) + -1;
      *(float *)(extraout_ECX + 0x5c) = fVar4;
      *(undefined1 *)(extraout_ECX + 0x58) = 1;
    }
    if ((*(float *)(extraout_ECX + 0x30) <= *(float *)(extraout_ECX + 0x18) &&
         *(float *)(extraout_ECX + 0x18) != *(float *)(extraout_ECX + 0x30)) &&
       (iVar2 = *(int *)(extraout_ECX + 0x10) + 1, iVar2 < *(int *)(extraout_ECX + 0x44))) {
      *(int *)(extraout_ECX + 0x10) = iVar2;
      *(float *)(extraout_ECX + 0x5c) = fVar4;
      *(undefined1 *)(extraout_ECX + 0x58) = 1;
    }
  }
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
