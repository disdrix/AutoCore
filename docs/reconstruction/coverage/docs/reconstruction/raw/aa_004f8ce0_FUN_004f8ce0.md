# Raw capture: FUN_004f8ce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f8ce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004f8ce0` |
| **Canonical name** | `FUN_004f8ce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004f8ce0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  int *piVar5;
  char local_220 [264];
  int local_118 [2];
  undefined1 local_10e [266];
  
  if ((((byte)param_2 < 8) && (*(int *)(param_1 + 0x28c + (param_2 & 0xff) * 4) != param_3)) &&
     (*(int *)(param_1 + 0x28c + (param_2 & 0xff) * 4) = param_3, *(int *)(param_1 + 0x48) != 0)) {
    if (param_3 < 1) {
      local_220[0] = '\0';
      FUN_004f5ae0(param_2,local_220);
      return;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xac + *(int *)(*(int *)(param_1 + 4) + 4)) + 0x3c);
    bVar3 = 0;
    if (*(char *)(iVar1 + 0x716) != '\0') {
      do {
        piVar4 = (int *)((uint)bVar3 * 0x110 + *(int *)(iVar1 + 0x720));
        piVar5 = local_118;
        for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar5 = *piVar4;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        }
        if (local_118[0] == param_3) {
          _snprintf(local_220,0x104,"%S%s",local_10e,&DAT_00a28904);
          FUN_004f5ae0(param_2,local_220);
          return;
        }
        iVar1 = *(int *)(*(int *)(param_1 + 0xac + *(int *)(*(int *)(param_1 + 4) + 4)) + 0x3c);
        bVar3 = bVar3 + 1;
      } while (bVar3 < *(byte *)(iVar1 + 0x716));
    }
    FUN_00512670();
  }
  return;
}
```
