# Function record: MemZero_DestSize_ReturnOne_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00788db0` |
| **Canonical name** | `MemZero_DestSize_ReturnOne_Inferred` |
| **Ghidra name** | `FUN_00788db0` |
| **Address** | `0x00788db0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / buffer zero leaf |
| **Wave** | W37-O OWN-ONLY dual |
| **Completion status** | **Sealed** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Zero `size` bytes at `dest` (signed; ≤0 no-op). Always return **1**. Leaf `REP STOS*` implementation. Not CRT `memset` (return value differs).

## Signature

```c
uint32_t __cdecl MemZero_DestSize_ReturnOne_Inferred(void *dest, int size);
```

## See also

- Function (FUN_): `aa_00788db0_FUN_00788db0.md`
- Report: `docs/agents/task-dual-ab-00788db0-0051d0c0-w37o-report.md`
