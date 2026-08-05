# Raw capture: FUN_0083edf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083edf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0083edf0` |
| **Canonical name** | `FUN_0083edf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0083edf0(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_EBX;
  int *piVar2;
  int *piVar3;
  
  unaff_EBX[0x145] = in_EAX;
  if (in_EAX == 0) {
    *(undefined1 *)(unaff_EBX + 0x13f) = 0;
  }
  else {
    piVar2 = (int *)(in_EAX + 0x24);
    piVar3 = unaff_EBX + 0x146;
    for (iVar1 = 0x18c; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    *(undefined1 *)(unaff_EBX + 0x13f) = 1;
  }
  (**(code **)(*unaff_EBX + 0x444))();
                    /* WARNING: Could not recover jumptable at 0x0083ee2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_EBX + 0x34c))();
  return;
}
```
