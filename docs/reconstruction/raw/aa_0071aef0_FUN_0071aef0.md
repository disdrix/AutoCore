# Raw capture: FUN_0071aef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071aef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0071aef0` |
| **Canonical name** | `FUN_0071aef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0071aef0(undefined4 param_1,SIZE_T param_2)

{
  char in_AL;
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 uVar3;
  LPVOID unaff_ESI;
  undefined1 local_4 [4];
  
  if (*(int *)((int)unaff_ESI + 8) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,(LPTHREAD_START_ROUTINE)&LAB_0071aed0,
                          unaff_ESI,-(uint)(in_AL != '\0') & 4 | 0x10000,
                          (LPDWORD)((int)unaff_ESI + 4));
    *(HANDLE *)((int)unaff_ESI + 8) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      DVar2 = GetLastError();
      uVar3 = FUN_0076cec0(local_4,"Error creating thread <%d>",DVar2);
      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp",0x31,3,uVar3);
      return 0;
    }
  }
  else {
    uVar3 = FUN_0076cec0(local_4,"Thread already created!");
    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp",0x40,3,uVar3);
  }
  return 1;
}
```
