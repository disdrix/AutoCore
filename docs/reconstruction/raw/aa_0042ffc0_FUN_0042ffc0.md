# Raw capture: FUN_0042ffc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ffc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0042ffc0` |
| **Canonical name** | `FUN_0042ffc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0042ffc0(undefined4 param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int local_384 [4];
  undefined1 local_374 [256];
  undefined1 local_274 [624];
  int *piStack_4;
  
  piVar2 = (int *)FUN_0042c6c0();
  if (piVar2 != (int *)0x0) {
    BitStream_readBits(0x40,local_384 + 2);
    BitStream_readBits(0x40,local_384);
    iVar3 = 2;
    bVar6 = true;
    piVar4 = local_384 + 2;
    piVar5 = piVar2 + 0x4e;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *piVar4 == *piVar5;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (bVar6);
    if (bVar6) {
      iVar3 = 2;
      bVar6 = true;
      piVar4 = local_384;
      piVar5 = piVar2 + 0x50;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *piVar4 == *piVar5;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (bVar6);
      if (bVar6) {
        *(uint *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 7U & 0xfffffff8;
        if (*(char *)((int)piVar2 + 0x135) != '\0') {
          FUN_007838a0();
          cVar1 = FUN_0042bd10(param_2,5,local_274);
          if (cVar1 == '\0') {
            FUN_0042bdf0();
            return;
          }
          FUN_0042bdf0();
        }
        FUN_0042ba90(local_374);
        piVar2[0x6e] = 8;
        (**(code **)(*piVar2 + 0x10))(3,local_374);
        (**(code **)(*piStack_4 + 0x10))(piVar2);
      }
    }
  }
  return;
}
```
