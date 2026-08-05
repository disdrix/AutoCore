# Function record: NDSpecialFX_List1e0_AnyFlag10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6a80` |
| **Canonical name** | `NDSpecialFX_List1e0_AnyFlag10` (**Inferred**) |
| **Ghidra name** | `FUN_004b6a80` |
| **Address** | `0x004b6a80`–`0x004b6aa7` (**40 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client-fx / NDSpecialFX residual list |
| **Convention** | `__fastcall` / thiscall-like: **ECX**=host; **AL** bool; plain `RET` |
| **Completion status** | **partial** — dual A/B 2026-07-29 W26-G |
| **Dual verdict** | **accept** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Return true if any node on the host residual list at `+0x1e0` carries payload flag bit `0x10` at `+0x989`. Type-4 host tick/teardown uses this as a re-enter / keep-active gate.

## Signature

```c
uint8_t NDSpecialFX_List1e0_AnyFlag10(void* host /*ECX*/);
```

## Artifacts

- Scaffold record: `docs/reconstruction/functions/aa_004b6a80_FUN_004b6a80.md`
- Raw / annotated / clean / dual A/B — see scaffold record.

## Confidence

| Claim | Level |
|---|---|
| Leaf CF/ABI/offsets sealed | **Confirmed** |
| Name product English | **Inferred** |
