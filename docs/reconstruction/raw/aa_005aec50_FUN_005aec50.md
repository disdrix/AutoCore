# Raw capture: FUN_005aec50

| Field | Value |
|---|---|
| **Stable ID** | `aa_005aec50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005aec50` |
| **Canonical name** | `FUN_005aec50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005aec50(int param_1,undefined4 *param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_4;
  
  piVar2 = param_3;
  puVar4 = *(undefined4 **)(param_1 + 4);
  bVar1 = true;
  local_4 = 1;
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      if ((*param_3 < (int)puVar4[3]) ||
         ((*param_3 <= (int)puVar4[3] && (param_3[1] < (int)puVar4[4])))) {
        puVar3 = (undefined4 *)*puVar4;
        bVar1 = true;
        local_4 = 1;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
        bVar1 = false;
        local_4 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  param_3 = puVar4;
  if (bVar1) {
    if (puVar4 == (undefined4 *)**(int **)(param_1 + 4)) {
      local_4 = 1;
      goto LAB_005aecad;
    }
    FUN_005adff0();
  }
  if ((*piVar2 <= param_3[3]) && ((*piVar2 < param_3[3] || (piVar2[1] <= param_3[4])))) {
    *param_2 = param_3;
    *(undefined1 *)(param_2 + 1) = 0;
    return;
  }
LAB_005aecad:
  puVar4 = (undefined4 *)FUN_005ae2f0(&param_3,local_4,puVar4,piVar2);
  *param_2 = *puVar4;
  *(undefined1 *)(param_2 + 1) = 1;
  return;
}
```
