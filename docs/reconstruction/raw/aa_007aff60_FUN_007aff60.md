# Raw capture: FUN_007aff60

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007aff60` |
| **Canonical name** | `FUN_007aff60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_007aff60(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,char *param_7)

{
  char cVar1;
  void *pvVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  
  puVar3 = operator_new(0x28);
  if (puVar3 == (undefined1 *)0x0) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    puVar3[0x22] = 0xff;
    puVar3[0x21] = 0xff;
    puVar3[0x20] = 0xff;
    puVar3[0x23] = 0xff;
  }
  *puVar3 = param_2;
  *(undefined4 *)(puVar3 + 8) = param_3;
  *(undefined4 *)(puVar3 + 0xc) = param_4;
  *(undefined4 *)(puVar3 + 0x10) = param_5;
  *(undefined4 *)(puVar3 + 0x14) = param_6;
  *(undefined4 *)(puVar3 + 0x20) = DAT_00afdf0c;
  *(undefined4 *)(puVar3 + 0x18) = 0;
  *(undefined4 *)(puVar3 + 0x1c) = 0;
  if (param_7 != (char *)0x0) {
    pcVar4 = param_7;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    pcVar4 = operator_new__((uint)(pcVar4 + (1 - (int)(param_7 + 1))));
    *(char **)(puVar3 + 0x18) = pcVar4;
    do {
      cVar1 = *param_7;
      *pcVar4 = cVar1;
      param_7 = param_7 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
  }
  puVar5 = operator_new(8);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = 0;
    puVar5[1] = 0;
  }
  *puVar5 = 0xd;
  puVar5[1] = puVar3;
  FUN_0041c7e0(param_1 + 0x1e8,puVar5);
  pvVar2 = *(void **)(param_1 + 0x28c);
  if (pvVar2 != (void *)0x0) {
    FUN_00797d70(pvVar2);
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar2);
  }
  *(undefined4 *)(param_1 + 0x28c) = 0;
  return;
}
```
