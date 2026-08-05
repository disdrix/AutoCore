# Raw capture: FUN_004eb1c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb1c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eb1c0` |
| **Canonical name** | `FUN_004eb1c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_004eb1c0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char local_104 [4];
  undefined1 local_100 [256];
  
  pcVar4 = (char *)(param_1 + 0x188);
  iVar2 = -(int)pcVar4;
  do {
    cVar1 = *pcVar4;
    pcVar4[(int)(local_104 + iVar2)] = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  puVar3 = (undefined4 *)&stack0xfffffefb;
  do {
    puVar5 = puVar3;
    puVar3 = (undefined4 *)((int)puVar5 + 1);
  } while (*(char *)((int)puVar5 + 1) != '\0');
  *(undefined4 *)((int)puVar5 + 1) = DAT_00a28904;
  *(undefined1 *)((int)puVar5 + 5) = DAT_00a28908;
  FUN_00989e00(param_2,local_104);
  return param_2;
}
```
