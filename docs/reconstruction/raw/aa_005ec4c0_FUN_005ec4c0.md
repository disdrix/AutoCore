# Raw capture: FUN_005ec4c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ec4c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ec4c0` |
| **Canonical name** | `FUN_005ec4c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ec4c0(int *param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((char)param_1[2] == '\0') {
    iVar7 = **(int **)(param_3 + 0x10);
    iVar5 = *param_1;
    iVar6 = param_1[1];
  }
  else {
    iVar5 = param_1[1];
    iVar7 = **(int **)(param_3 + 0x10);
    iVar6 = *param_1;
  }
  fVar1 = *(float *)(iVar7 + 4 + iVar6 * 0xc);
  fVar2 = *(float *)(iVar7 + 8 + iVar6 * 0xc);
  fVar3 = *(float *)(iVar7 + 4 + iVar5 * 0xc);
  fVar4 = *(float *)(iVar7 + 8 + iVar5 * 0xc);
  *param_2 = *(float *)(iVar7 + iVar6 * 0xc) - *(float *)(iVar7 + iVar5 * 0xc);
  param_2[1] = fVar1 - fVar3;
  param_2[2] = fVar2 - fVar4;
  return;
}
```
