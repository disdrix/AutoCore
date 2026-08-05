# Annotated low-level: FUN_0075bcd0

| Field | Value |
|---|---|
| Stable ID | `aa_0075bcd0` |
| VA | `0x0075bcd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0075bcd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 FUN_0075bcd0(void)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  int iVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float local_18;
  float local_14;
  
  local_18 = 0.0;
  local_14 = 0.0;
  iVar3 = *(int *)(in_EAX + 0x13c);
  fVar6 = (float)*(int *)(in_EAX + 0xe4) - DAT_00a0f298;
  fVar8 = (float)*(int *)(in_EAX + 0xe8) - DAT_00a0f298;
  fVar9 = (float)*(int *)(in_EAX + 0xdc) + fVar6;
  fVar7 = (float)*(int *)(in_EAX + 0xe0) + fVar8;
  if (iVar3 == 0) {
    iVar5 = 1;
    iVar3 = 1;
  }
  else {
    iVar5 = *(int *)(iVar3 + 0x1c);
    iVar3 = *(int *)(iVar3 + 0x20);
  }
  if (*(int *)(in_EAX + 0x140) == 0) {
    local_18 = g_flOne;
  }
  else if (*(int *)(in_EAX + 0x140) == 1) {
    local_18 = (float)*(int *)(in_EAX + 0xdc) / (float)iVar5;
  }
  if (*(int *)(in_EAX + 0x144) == 0) {
    local_14 = g_flOne;
  }
  else if (*(int *)(in_EAX + 0x144) == 1) {
    local_14 = (float)*(int *)(in_EAX + 0xe0) / (float)iVar3;
  }
  if (*(int *)(*(int *)(in_EAX + 0x130) + 0x10) != 0) {
    pfVar4 = (float *)FUN_00746520(*(undefined4 *)(*(int *)(in_EAX + 0x130) + 0x14),4,1);
    fVar2 = g_flOne;
    if (pfVar4 != (float *)0x0) {
      *pfVar4 = fVar6;
      pfVar4[1] = fVar8;
      fVar1 = *(float *)(in_EAX + 0x100);
      pfVar4[3] = fVar2;
      pfVar4[2] = fVar1;
      pfVar4[7] = fVar9;
      pfVar4[8] = fVar8;
      fVar8 = *(float *)(in_EAX + 0x100);
      pfVar4[0xe] = fVar6;
      pfVar4[10] = fVar2;
      pfVar4[0xf] = fVar7;
      pfVar4[9] = fVar8;
      fVar6 = *(float *)(in_EAX + 0x100);
      pfVar4[0x11] = fVar2;
      pfVar4[0x10] = fVar6;
      pfVar4[0x16] = fVar7;
      pfVar4[0x15] = fVar9;
      fVar6 = *(float *)(in_EAX + 0x100);
      pfVar4[0x18] = fVar2;
      pfVar4[0x17] = fVar6;
      pfVar4[4] = *(float *)(in_EAX + 0x148);
      pfVar4[5] = 0.0;
      pfVar4[6] = 0.0;
      fVar6 = *(float *)(in_EAX + 0x148);
      pfVar4[0xd] = 0.0;
      pfVar4[0xb] = fVar6;
      pfVar4[0xc] = local_18;
      fVar6 = *(float *)(in_EAX + 0x148);
      pfVar4[0x13] = 0.0;
      pfVar4[0x12] = fVar6;
      pfVar4[0x14] = local_14;
      pfVar4[0x19] = *(float *)(in_EAX + 0x148);
      pfVar4[0x1a] = local_18;
      pfVar4[0x1b] = local_14;
      FUN_00414a50();
      FUN_0096f800(2);
      FUN_0043f410();
      if (*(int *)(in_EAX + 0x130) != 0) {
        FUN_0043f4b0();
      }
      if (*(int *)(*(int *)(in_EAX + 0x130) + 0x34) == 0) {
        FUN_00967150(*(int *)(in_EAX + 0x130) + 0x24);
      }
      FUN_00734550();
      FUN_0075e8e0(5,0,2);
      FUN_0074f360();
      return 0;
    }
  }
  return 0xffffffff;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
