# Raw capture: FUN_0080fea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080fea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0080fea0` |
| **Canonical name** | `FUN_0080fea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0080fea0(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_007a69d0();
  if (*(char *)(param_1 + 4) == '\0') {
    uVar4 = 0;
    uVar3 = 1;
    uVar2 = 0xffffffff;
    uVar1 = FUN_007a6de0("The server is not accepting logins at this time. Please try again in a few moments..."
                         ,0xffffffff);
    FUN_007fdfb0(in_EAX,uVar1,uVar2,uVar3,uVar4);
  }
  else {
    FUN_00937560(in_EAX);
    if (*(int *)(in_EAX + 0xf38) != 0) {
      FUN_00920050();
      return;
    }
  }
  return;
}
```
