# Raw capture: FUN_005ac9c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ac9c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ac9c0` |
| **Canonical name** | `FUN_005ac9c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall
FUN_005ac9c0(int param_1,undefined4 param_2,undefined4 param_3,char *param_4,size_t param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  char local_208 [2];
  undefined4 local_206 [128];
  
  local_208[0] = '\0';
  local_208[1] = '\0';
  puVar4 = local_206;
  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  FUN_007a69d0();
  if (*(int *)(param_1 + 0x58) < 1) {
    pcVar2 = (char *)FUN_007a6de0("CrazyTaxi mission without any taxi points.",0xffffffff);
  }
  else {
    pcVar2 = (char *)FUN_007a6de0("Get to your next destination.",0xffffffff);
  }
  sprintf(local_208,pcVar2);
  strncat(param_4,local_208,param_5);
  pcVar2 = local_208;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return (int)pcVar2 - (int)(local_208 + 1);
}
```
