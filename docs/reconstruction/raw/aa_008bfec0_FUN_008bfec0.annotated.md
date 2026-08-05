# Annotated low-level: FUN_008bfec0

| Field | Value |
|---|---|
| Stable ID | `aa_008bfec0` |
| VA | `0x008bfec0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_008bfec0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __fastcall FUN_008bfec0(int param_1)

{
  *(undefined4 *)(param_1 + 0x540) = 0;
  *(undefined4 *)(param_1 + 0x53c) = 0;
  *(undefined4 *)(param_1 + 0x548) = 0;
  *(undefined4 *)(param_1 + 0x554) = 0;
  *(undefined1 *)(param_1 + 0x50c) = 1;
  *(undefined1 *)(param_1 + 0x50d) = 1;
  *(undefined1 *)(param_1 + 0x50e) = 1;
  *(undefined1 *)(param_1 + 0x50f) = 1;
  *(undefined1 *)(param_1 + 0x510) = 1;
  *(undefined1 *)(param_1 + 0x511) = 1;
  *(undefined1 *)(param_1 + 0x512) = 1;
  *(undefined1 *)(param_1 + 0x513) = 0;
  *(undefined4 *)(param_1 + 0x59c) = 0;
  *(undefined4 *)(param_1 + 0x5a0) = 0;
  *(undefined4 *)(param_1 + 0x5a4) = 0;
  *(undefined4 *)(param_1 + 0x5a8) = 0;
  *(undefined4 *)(param_1 + 0x5ac) = 0;
  *(undefined4 *)(param_1 + 0x5b0) = 0;
  *(undefined4 *)(param_1 + 0x5b4) = 0;
  *(undefined4 *)(param_1 + 0x5b8) = 0;
  *(undefined4 *)(param_1 + 0x574) = 0;
  *(undefined4 *)(param_1 + 0x524) = 0;
  *(undefined1 *)(param_1 + 0x514) = 0;
  *(undefined1 *)(param_1 + 0x515) = 0;
  *(undefined1 *)(param_1 + 0x516) = 0;
  *(undefined1 *)(param_1 + 0x517) = 0;
  *(undefined1 *)(param_1 + 0x518) = 0;
  *(undefined1 *)(param_1 + 0x519) = 0;
  *(undefined1 *)(param_1 + 0x51a) = 0;
  *(undefined1 *)(param_1 + 0x534) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
