# Function record: Object_SetDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00516720` |
| **Canonical name** | `Object_SetDisplayName_Inferred` |
| **Ghidra name** | `FUN_00516720` |
| **Address** | `0x00516720`–`0x00516899` exclusive (**377 B** / `0x179`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-identity / display-name |
| **Partition** | R10-031 residual under parent dual `0x0051b230` (skills-abilities map row) |
| **Completion status** | **Dual A/B sealed 2026-08-05** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Launcher not used) |

## Purpose

Shared thiscall helper that owns `*(object+0x158)` as a heap display-name string:

1. `nameOrNull == NULL` → return (preserve existing name).
2. Free/clear prior `+0x158`.
3. **Compose** via `FUN_005146a0` when `vtbl+0x60`, host `+0xA4`, and name manager (`FUN_004ce940`) are live; store composed string.
4. **Else** store input only if it differs from template default (`strncmp` n=`0x41`) and `strlen > 1`.

## Signature (sealed)

```c
void __thiscall Object_SetDisplayName_Inferred(void *self, char *nameOrNull);
// ECX=self; [ESP+4]=nameOrNull; RET 4
```

## Key fields

| Offset | Role |
|---|---|
| `+0x158` | Owned display-name `char*` |
| `+0xA4` | Host gate for compose |
| `+0xA8` | Template/descriptor for default name |
| vtbl `+0x60` | Compose eligibility count/gate |

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00516720_FUN_00516720.md` |
| Annotated | `docs/reconstruction/raw/aa_00516720_FUN_00516720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetDisplayName_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00516720.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00516720_Object_SetDisplayName_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00516720_Object_SetDisplayName_Inferred.md` |
| FUN record | `docs/reconstruction/functions/aa_00516720_FUN_00516720.md` |
| Report | `docs/agents/task-dual-ab-00516720-r10-report.md` |

## Dual verdict

| Path | Verdict |
|---|---|
| A fidelity | **accept-with-gaps** |
| B adversarial | **accept-with-gaps** |

## Confidence

| Claim | Level |
|---|---|
| ABI / CF / field `+0x158` | **Confirmed** |
| Role: set display name (compose or custom) | **Confirmed** |
| Product demangled symbol | **Inferred** (`_Inferred` suffix required) |
| Runtime | **Open** |
