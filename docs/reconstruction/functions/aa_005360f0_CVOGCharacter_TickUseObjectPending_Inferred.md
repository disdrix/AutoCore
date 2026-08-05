# Function record: CVOGCharacter_TickUseObjectPending_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005360f0` |
| **Canonical name** | `CVOGCharacter_TickUseObjectPending_Inferred` |
| **Ghidra name** | `FUN_005360f0` |
| **Address** | `0x005360f0`–`0x00536143` (84 B; exclusive end `0x00536144`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` / use-object pending |
| **Calling convention** | MSVC `__thiscall` (ECX=character; 1 stack float dt; AL bool; `ret 4`) |
| **Completion status** | **Sealed** — dual A/B W26-S 2026-07-29; CF/ABI/timer High; product English **Probable** |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- `FUN_005360f0`

## Purpose

Per-frame **countdown tick** for the character's pending use-object interaction. When the timer at `+0xc80` is active (and vbase/flag gates pass), subtract frame dt; when remaining ≤ 0, **commit** via `CVOGCharacter_ResolveUseObjectPending_Inferred(1)`.

## Signature

```c
bool __thiscall CVOGCharacter_TickUseObjectPending_Inferred(
    void* this /* Character* */,
    float dt);
// RET 4
```

## Behavioral summary (sealed)

1. Gate: vbase via this-adjust `+0xa8` flag `+0x7e`; pending flag `+0xc7c`; timer `+0xc80 > 0`.
2. `timer -= dt`; store.
3. If `timer <= 0`: `ResolveUseObjectPending(commit=1)`.
4. Return **1** if gate passed; **0** if gated off (no write).

## Callers / callees

| Direction | Address / name | Role |
|---|---|---|
| Caller | `FUN_00930040` @ `0x009300c3` | client frame tick; dt = `*(DAT_00d09874+0x30)` |
| Callee | `CVOGCharacter_ResolveUseObjectPending_Inferred` | commit on expiry (W25-A sealed) |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | Ghidra body `…6143` + `CC` pad |
| thiscall / ret 4 / AL bool | **High** | epilogue bytes |
| Gate offsets + timer | **High** | decompile + read_memory |
| Commit polarity (1) | **High** | `6A 01` before call |
| Product English name | **Probable** | `_Inferred` structural |
| Overall static CF | **High** | dual W26-S |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_005360f0_FUN_005360f0.md` |
| Annotated | `raw/aa_005360f0_FUN_005360f0.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_TickUseObjectPending_Inferred.cpp` |
| Clean twin | `reconstructed-exact/FUN_005360f0.cpp` |
| Dual A | `reviews/A_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` |
| Dual B | `reviews/B_aa_005360f0_CVOGCharacter_TickUseObjectPending_Inferred.md` |
| Commit sibling | `A/B_aa_00535ed0_CVOGCharacter_ResolveUseObjectPending_Inferred.md` |

## Open questions

- Product/PDB method name.
- Who arms initial `+0xc80` duration.
