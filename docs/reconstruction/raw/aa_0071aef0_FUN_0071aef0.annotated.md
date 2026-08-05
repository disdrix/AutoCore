# Annotated low-level: FUN_0071aef0

| Field | Value |
|---|---|
| Stable ID | `aa_0071aef0` |
| VA | `0x0071aef0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0071aef0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
