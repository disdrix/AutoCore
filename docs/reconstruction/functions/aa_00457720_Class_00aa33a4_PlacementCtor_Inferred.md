# Function record: Class_00aa33a4_PlacementCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00457720` |
| **Canonical name** | `Class_00aa33a4_PlacementCtor_Inferred` |
| **Ghidra name** | `FUN_00457720` |
| **Address** | `0x00457720`–`0x004577aa` (**139 B** / `0x8B`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host class placement ctor |
| **Completion status** | **Dual A/B sealed** (W36-I) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Naming basis

- Primary vtbl `PTR_FUN_00aa33a4` written at `*self`.
- Placement ctor pattern (stack this, RET 4, return this) matching NestedHash/Class duals.
- **Inferred** — no PDB. Reject bare `FUN_00457720`.

## Signature

```c
void* __stdcall Class_00aa33a4_PlacementCtor_Inferred(void* self);
```

## Artifacts

See `aa_00457720_FUN_00457720.md`.

## Dual verdict

| Review | Verdict |
|--------|---------|
| A | **accept-with-gaps** |
| B | **accept-with-gaps** |
