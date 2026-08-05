# Raw capture: FUN_0067cde0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067cde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0067cde0` |
| **Canonical name** | `FUN_0067cde0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0067cde0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a96ed;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)(param_1 + 0x2a3c) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x40);
    ExceptionList = &local_c;
    *piVar1 = *piVar1 + 1;
  }
  if (*(char *)(param_1 + 0x2a12) == '\0') {
    *(undefined1 *)(param_1 + 0x2a12) = 1;
    pvVar2 = operator_new(0x1c);
    local_4 = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_00680c30();
    }
    *(undefined4 *)(param_1 + 0x2a14) = uVar3;
  }
  local_4 = 0xffffffff;
  if (param_4 == 0) {
    uVar3 = FUN_0076cec0(&param_4,"Session %lu: Received a fragment of size zero",
                         *(undefined4 *)(param_1 + 0x2a20));
    vog_LogMessage("C:\\vog\\1_code\\palantir\\platform\\library\\src\\nazgul\\net\\netSession.cpp",
                   0x569,2,uVar3);
  }
  else {
    FUN_006810a0(param_3,param_4);
  }
  if ((*(byte *)(param_2 + 0xd) & 0x20) != 0) {
    FUN_0067cd80(0,*(undefined4 *)(param_1 + 0x2a14));
    *(undefined1 *)(param_1 + 0x2a12) = 0;
    *(undefined4 *)(param_1 + 0x2a14) = 0;
    if (*(int *)(param_1 + 0x2a3c) != 0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x2a3c) + 0x48);
      *piVar1 = *piVar1 + 1;
    }
  }
  thunk_FUN_0076c4d0();
  ExceptionList = local_c;
  return 1;
}
```
