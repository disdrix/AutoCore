# Function record: MedalUI_PrepClearButtonSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090c700` |
| **Canonical name** | `MedalUI_PrepClearButtonSlots_Inferred` |
| **Ghidra name** | `FUN_0090c700` |
| **Address** | `0x0090c700`–`0x0090c74c` (**77 B** / `0x4D`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Partition** | MEGA-102 — Medal UI prep (parent `0x0090cbc0`) |
| **Completion status** | **Dual sealed** (A/B **accept-with-gaps**) |
| **Bit-for-bit / runtime / diff** | Open |
| **Terminal** | **false** |

## Naming rationale

| Evidence | Weight |
|---|---|
| Sole caller `FUN_0090cbc0` rebuilds medal/achievement UI grid | High |
| Sibling `FUN_0090c9a0` loads `"i_d_a_2d_btn_achievement.xml"` into `host[index+0x150]` (= `+0x540` base) | High |
| This unit tears down the same 24 slots (detach + scalar-delete + null) before that rebuild | High |
| Partition map hint: **Medal UI prep** | Medium |
| No product symbol inside body → **`_Inferred`** suffix | Required |

Retired: `Named_CalleeOf_Named_VOG_DEBUG_STOP_0090c700`.

## Purpose

Prep-clear the medal achievement **button slot array** on the medal UI host:

1. Iterate `slots[0..23]` at `host+0x540`.
2. If slot non-null and host `vtbl[+0x3d8]()` true → `vtbl[+0xb0](slot)`.
3. If slot still non-null → scalar-delete flags=1.
4. Null slot.

## Signature

```c
// Retail ABI: EDI = MedalUI host*; void; bare RET
void MedalUI_PrepClearButtonSlots_Inferred(void);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.md` |
| Annotated | `docs/reconstruction/raw/aa_0090c700_FUN_0090c700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MedalUI_PrepClearButtonSlots_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090c700.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0090c700_FUN_0090c700.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0090c700_MedalUI_PrepClearButtonSlots_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090c700-mega-102-report.md` |

## Callers / callees

| Direction | Value |
|---|---|
| Callers | `FUN_0090cbc0` @ `0x0090cbef` |
| Callees | virtual only |

## Gaps

- Product English for host class.
- Product English for vtbl `+0x3d8` / `+0xb0`.
- Widget RTTI behind slots (XML peer only).
- Runtime / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Medal UI prep role | **High** |
| Product type names | **Low** |
