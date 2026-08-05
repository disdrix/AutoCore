# Annotated low-level: FUN_008cb2a0

| Field | Value |
|---|---|
| Stable ID | `aa_008cb2a0` |
| VA | `0x008cb2a0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008cb2a0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008cb2a0(undefined4 param_1)

{
  byte bVar1;
  char cVar2;
  int in_EAX;
  char *pcVar3;
  int *piVar4;
  undefined2 *puVar5;
  char *pcVar6;
  int *unaff_ESI;
  undefined8 uVar7;
  int iVar8;
  
  if (in_EAX == 0) {
    FUN_008caf50(param_1);
  }
  else {
    bVar1 = *(byte *)(in_EAX + 4);
    unaff_ESI[0x156] = (uint)bVar1;
    iVar8 = 0;
    if (bVar1 != 0) {
      puVar5 = (undefined2 *)(in_EAX + 0x148);
      pcVar6 = (char *)(in_EAX + 0x48);
      piVar4 = unaff_ESI + 0x15d;
      do {
        piVar4[-4] = *(int *)(puVar5 + -0xa0);
        pcVar3 = pcVar6;
        do {
          cVar2 = *pcVar3;
          pcVar3[(int)piVar4 - (int)pcVar6] = cVar2;
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\0');
        *(undefined2 *)(piVar4 + -2) = *puVar5;
        iVar8 = iVar8 + 1;
        puVar5 = puVar5 + 2;
        pcVar6 = pcVar6 + 0x10;
        piVar4 = piVar4 + 0xf;
      } while (iVar8 < unaff_ESI[0x156]);
    }
  }
  if ((int *)unaff_ESI[0x252] != (int *)0x0) {
    uVar7 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();
    *(undefined8 *)(unaff_ESI + 0x154) = uVar7;
  }
  FUN_008ca6c0();
  if ((int *)unaff_ESI[0x252] != (int *)0x0) {
    (**(code **)(*(int *)unaff_ESI[0x252] + 0x448))(unaff_ESI[0x154],unaff_ESI[0x155]);
    uVar7 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();
    *(undefined8 *)(unaff_ESI + 0x154) = uVar7;
  }
                    /* WARNING: Could not recover jumptable at 0x008cb37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 0x34c))();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
