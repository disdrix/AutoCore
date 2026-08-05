# Annotated low-level: FUN_0074bda0

| Field | Value |
|---|---|
| Stable ID | `aa_0074bda0` |
| VA | `0x0074bda0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0074bda0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 __fastcall FUN_0074bda0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ad91f;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  stoChunkWriter_BeginChunk(0x42424f58,2);
  local_4 = 0;
  FUN_004399a0();
  FUN_00436030();
  FUN_00436030();
  FUN_00436030();
  uVar1 = FUN_0043b500(param_2 + 0xc);
  local_4 = 0xffffffff;
  stoChunkWriter_EndChunk();
  ExceptionList = local_c;
  return uVar1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
