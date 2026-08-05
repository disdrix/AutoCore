# Raw capture: FUN_0076aed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076aed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076aed0` |
| **Canonical name** | `FUN_0076aed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
char * __thiscall FUN_0076aed0(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *local_8;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (param_1 < pcVar2 + -((int)pcVar3 - (int)(param_2 + 1))) {
    iVar6 = (int)param_1 - (int)param_2;
    pcVar7 = param_2;
    local_8 = param_1;
    do {
      while( true ) {
        if (*pcVar7 == '\0') {
          return local_8;
        }
        iVar4 = tolower((int)pcVar7[iVar6]);
        iVar5 = tolower((int)*pcVar7);
        if (iVar4 != iVar5) break;
        pcVar7 = pcVar7 + 1;
      }
      local_8 = local_8 + 1;
      iVar6 = iVar6 + 1;
      pcVar7 = param_2;
    } while (local_8 < pcVar2 + -((int)pcVar3 - (int)(param_2 + 1)));
  }
  return (char *)0x0;
}
```
