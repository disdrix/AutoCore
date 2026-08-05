# Annotated low-level: FUN_0066eec0

| Field | Value |
|---|---|
| Stable ID | `aa_0066eec0` |
| VA | `0x0066eec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0066eec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
