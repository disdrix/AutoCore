# Raw capture: CVOGCharacter_CreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_005237a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005237a0` |
| **Canonical name** | `CVOGCharacter_CreateFromPacket` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
CVOGCharacter_CreateFromPacket
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  FUN_005c9120(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if (((*(uint *)(param_1 + -0xb90) & *(uint *)(param_1 + -0xb8c)) != 0xffffffff) && (param_4 != 0))
  {
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + -0xd8c) = DVar1;
    iVar2 = FUN_004bafe0(*(undefined1 *)
                          (*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc34 + param_1),
                         *(undefined4 *)(param_1 + -0xb90),*(undefined4 *)(param_1 + -0xb8c));
    *(int *)(param_1 + -0xb50) = iVar2;
    if (iVar2 != 0) {
      if (param_1 == 0xda0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1;
      }
      FUN_005131b0(iVar3);
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x218))
                (*(undefined4 *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf8 + param_1));
    }
    if (((char)param_7 == '\0') ||
       ((*(uint *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc20 + param_1) >> 6 & 1) == 0)) {
      FUN_00521310(param_2,param_3,param_5,param_6,param_7,0);
    }
  }
  return;
}
```
