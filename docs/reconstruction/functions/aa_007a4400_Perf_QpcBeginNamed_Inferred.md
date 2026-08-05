# Function record: Perf_QpcBeginNamed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4400` |
| **Canonical name** | `Perf_QpcBeginNamed_Inferred` |
| **Ghidra name** | `FUN_007a4400` |
| **Address** | `0x007a4400`–`0x007a445c` (**92 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | perf / QPC named begin |
| **Completion status** | **Sealed** W26-D dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Named QPC begin helper used as high-traffic stage marker across client init and sector map IO.

## Signature

```c
// thiscall; ret 4
LARGE_INTEGER *Perf_QpcBeginNamed_Inferred(LARGE_INTEGER *slot /*ECX*/, char *label);
// side effects: DAT_00b00a74 once-clear; DAT_00afa254 = 1/freq; label@slot+8; QPC@slot+0
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` full **92 B** body; epilogue `ADD ESP,8; RET 4`
- IAT `[0x009c61b4]` QPF / `[0x009c61b0]` QPC
- Call-site strings (`@@new CVOGSectorMap`, `Client InitInstance`, …)

## Artifacts

See `aa_007a4400_FUN_007a4400.md` for full artifact table.
