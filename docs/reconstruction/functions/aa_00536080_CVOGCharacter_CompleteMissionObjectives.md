# Function record: CVOGCharacter_CompleteMissionObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **Canonical name** | `CVOGCharacter_CompleteMissionObjectives` |
| **Address** | `0x00536080` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC **`__thiscall`** (character `this` + 2 stack formals; **`RET 8`**) |
| **Completion status** | **Human-refined clean** + dual A/B residual strengthened 2026-07-29 |
| **Dual status** | **Present** — `reviews/A\|B_aa_00536080_*` accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Bulk force-complete all objectives for a mission id on the local character: lookup mission def, walk `+0x13c` array (`count` byte at `+0x130`), call

`CVOGReaction_CompleteObjective(this, objId, -1, -1, forceComplete)`

for each. Return 1 if def found (even count 0), else 0.

Does **not** own mission-level completed-hash wrap-up (callee). Formal historically labeled `uReason` is callee **forceComplete** (prereqs push **1**).

## Signature

```c
char __thiscall CVOGCharacter_CompleteMissionObjectives(
    void* thisCharacter,       // CVOGCharacter* — required; forwarded to CompleteObjective
    unsigned uMissionID,
    uint32_t forceComplete);   // raw name uReason; callee force flag (0/non-zero)
```

**Not** `__cdecl`. Ghidra plate/decomp prototype still wrong; listing: save ECX, `RET 8`.

## Callers (static, 2026-07-29 residual)

| Site | Caller | forceComplete | this |
|---|---|---|---|
| `0x005365ae` | `CVOGCharacter_CheckMissionPrerequisites` (live-active + autoComplete) | `1` | `MOV ECX,ESI` (**live**) |
| `0x00536722` | same (post-GiveMission + autoComplete) | `1` | same |

No other xrefs (`get_function_xrefs` / `get_function_callers`).

## Callees

| VA | Name | Role |
|---|---|---|
| `0x0053fff0` | `FUN_0053fff0` | Lazy table object at owner `DAT_00b041fc` + `0xf18` |
| `0x005b0920` | `CNDHash_LookupByKey` | Mission id → def |
| `0x00533f90` | `CVOGReaction_CompleteObjective` | Per-objective force; return discarded |

## Offsets

| Location | Role |
|---|---|
| `def+0x130` | u8 objective count |
| `def+0x13c` | ObjectiveDef** table |
| `objDef+0x10` | Objective id |
| `DAT_00b041fc` | Global owner for FUN_0053fff0 |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Function boundary | **High** | 46 insns; clear RET 8 exits |
| Control flow | **High** | Single lookup + counted loop; live ≡ raw |
| Convention / this | **High** | Listing + call-site ECX (prior dual residual corrected) |
| Offsets `+0x130` / `+0x13c` / obj `+0x10` | **High** | Body + listing |
| CompleteObjective arg packing | **High** | 4 stack + ECX this; wildcards −1/−1 |
| Sole-caller force `1` | **High** | Asm `PUSH 1` at both sites |
| force vs multi-reason enum | **High** as force bit; enum **open** | Callee forceComplete only |
| Overall | **High (static)** | Runtime / wrap-up open |

## Open questions

- Runtime bulk-complete + CompleteObjective failure visibility.
- Product name for `FUN_0053fff0` / `DAT_00b041fc`.
- Whether count-0 success is intentional for empty defs.
- Any dynamic/non-xref callers.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| Annotated | `raw/aa_00536080_CVOGCharacter_CompleteMissionObjectives.annotated.md` |
| Clean | `reconstructed-exact/CVOGCharacter_CompleteMissionObjectives.cpp` |
| Dual A | `reviews/A_aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| Dual B | `reviews/B_aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| Scratch | `tmp/a_00536080.md` |
