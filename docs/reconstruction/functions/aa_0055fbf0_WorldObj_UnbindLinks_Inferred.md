# Function record: WorldObj_UnbindLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fbf0` |
| **Canonical name** | `WorldObj_UnbindLinks_Inferred` |
| **Ghidra name** | `FUN_0055fbf0` |
| **Address** | `0x0055fbf0`–`0x0055fd72` (**386 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | world-object / manager unbind |
| **Completion status** | **Sealed** W26-D dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Manager unbind helper: drop spatial-query links for `obj` under `manager`. Pair of bind helper `FUN_0055fa40` (W26-E).

## Signature

```c
// thiscall; ret 4; void
void WorldObj_UnbindLinks_Inferred(void *manager /*ECX*/, void *obj /*stack*/);
```

## Evidence

- Live Ghidra decompile 2026-07-29 ≡ raw 2026-07-23
- `read_memory` **386 B** body; dual epilogues `POP`s + `ADD ESP,0x38; RET 4`
- Callers sealed in W24-B rebind dual as unbind step

## Artifacts

See `aa_0055fbf0_FUN_0055fbf0.md` for full artifact table.
