# Annotated low-level: DES_InitializeCipher

| Field | Value |
|---|---|
| Stable ID | `aa_0071c000` |
| VA | `0x0071c000` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071c000`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void DES_InitializeCipher(void)

{
  byte bVar1;
  byte *in_EAX;
  uint uVar2;
  uint uVar3;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  bVar1 = *in_EAX;
  for (uVar3 = 0; (bVar1 != 0 && ((int)uVar3 < 0x28)); uVar3 = uVar3 + 1) {
    uVar2 = uVar3 & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    *(byte *)((int)&local_8 + uVar2) = *(byte *)((int)&local_8 + uVar2) ^ bVar1;
    bVar1 = in_EAX[1];
    in_EAX = in_EAX + 1;
  }
  FUN_0071b430(&DAT_00d16ef0,&DAT_00afca50);
  FUN_0071b430(&DAT_00d12690,&DAT_00afca90);
  DES_KeySchedule();
  FUN_0071bdd0();
  FUN_0071b5a0();
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
