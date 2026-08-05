# Raw capture: FUN_0066eec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0066eec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0066eec0` |
| **Canonical name** | `FUN_0066eec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0066eec0(int param_1)

{
  undefined4 uVar1;
  int local_4;
  
  if (*(char *)(param_1 + 0x184) != '\0') {
    if ((*(char *)(param_1 + 0x58) == '\0') || (*(char *)(param_1 + 0x5a) == '\0')) {
      return 0xffffffff;
    }
    local_4 = param_1;
    uVar1 = FUN_0076cec0(&local_4,"local Post Stop recording command");
    vog_LogMessage("C:\\vog\\1_code\\palantir\\core\\infrastruct\\Voice\\TalkClientLib\\ChatClientImpl.cpp"
                   ,0x11b,1,uVar1);
    *(undefined1 *)(param_1 + 0x184) = 0;
    FUN_00671b70();
  }
  return 0;
}
```
