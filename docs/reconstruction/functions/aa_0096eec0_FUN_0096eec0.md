# Function record: FUN_0096eec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096eec0` |
| **Canonical name** | `Host34_NestedHash0xC_Singleton_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0096eec0` |
| **Address** | `0x0096eec0`–`0x0096ef6a` exclusive (**170 B** / `0xAA`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | NestedHash0xC host + singleton + type-token once-init |
| **Wave** | W35-S OWN-ONLY dual 2026-07-29 |
| **Completion status** | **Dual-reviewed** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Preferred: `Host34_NestedHash0xC_Singleton_Ctor_Inferred`
- **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_0096eec0`

## Purpose

Placement ctor for a **0x34**-byte host: NestedHash (sentinel **0x0C**) at base, trailing flag/fields, publish `DAT_00d1f04c`, once-init static type-token `DAT_00d1f7e4`, register handler `LAB_0096ed30` into map at `*DAT_00d1f050+0x58`.

## Signature

```c
// stack(self*); RET 4; returns self in EAX
Host34_NestedHash0xC* Host34_NestedHash0xC_Singleton_Ctor_Inferred(Host34_NestedHash0xC* self);
```

## Callers / callees

| Direction | Targets |
|---|---|
| Callers (1) | `FUN_0075f7f0` @ `0x0075fa2f` — `param_2[0x1d5] = this(new(0x34))` |
| Callees | `FUN_0043fdf0` / `NestedHash_Ctor_Sentinel0xC_Inferred` (W34-F); `_atexit`; `FUN_0043bd40` |

## Artifacts

- Raw (+ W35-S append): `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.md`
- Annotated: `docs/reconstruction/raw/aa_0096eec0_FUN_0096eec0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Host34_NestedHash0xC_Singleton_Ctor_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0096eec0.cpp`
- Named record: `docs/reconstruction/functions/aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md`
- Review A: `docs/reconstruction/reviews/A_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0096eec0_Host34_NestedHash0xC_Singleton_Ctor_Inferred.md`
- Scratch: `docs/reconstruction/tmp/a_0096eec0.md`
- Report: `docs/agents/task-dual-ab-0096eec0-00996bc0-w35s-report.md`

## Confidence

| Claim | Level |
|---|---|
| Placement ctor ABI stack/RET4/return this | **High** (bytes) |
| Layout NestedHash@0 + flags + size 0x34 | **High** |
| Singleton `DAT_00d1f04c` | **High** |
| Once-init type-token + atexit | **High** |
| Map insert tree/key/value | **High** (bytes; decompile incomplete) |
| Product English / handler body | **Low** / open |
