# Function record: Skill_FilterTargetForResolveList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054ff00` |
| **Canonical name** | `Skill_FilterTargetForResolveList_Inferred` |
| **Prior** | `FUN_0054ff00` |
| **Address** | `0x0054ff00` |
| **System** | skills-abilities |
| **Name confidence** | **Probable** — sole caller `Skill_ResolveTargetList`; ORs `*outFlags` bits **4 / 8 / 0x10** |
| **Status** | Human-refined + dual A/B **accept** (2026-07-29 dual residual: OR sites machine-sealed) |

## Purpose

Skill targeting filter for resolve-list building. Returns accepted target pointer or null; on reject sets `*outFlags |= 4|8|0x10` depending on gate. **Closes** open question “who ORs outFlags bits 4 and 8” (also seals **0x10**).

## Signature

```c
// __thiscall  this = skill runtime
// RET 0x0C (3 stack dwords) — Confirmed epilogue
int* Skill_FilterTargetForResolveList_Inferred(
    /*ECX*/ int* skill,
    /*stack*/ int* candidate,   // nullable
    /*stack*/ int* caster,
    /*stack*/ uint* outFlags);
```

## outFlags OR sites (sealed — machine)

| Bit | OR insn VA | Bytes | Condition (summary) |
|----:|-----------:|-------|---------------------|
| **8** | `0x0054ff72` | `83 08 08` | `vtbl+0x198` non-zero while skill `+0x615` bit2 (Remains) clear |
| **0x10** | `0x0055007c` | `83 08 10` | object type not in `{0xe, 0x12, 0x14}` |
| **4** | `0x005502c1` | `83 08 04` | fallthrough reject `LAB_005502bd` (+ early gotos E1–E3) |

Exactly **three** outFlags stores in body (pcode INT_OR count = 3). Does **not** write bits **1** or **2**.

### Bit4 early-exit sources

| ID | Path |
|----|------|
| E1 | null candidate without self-pos redirect |
| E2 | `+0x614&1` set but mode `+0x60c` ∉ `{0,1}` |
| E3 | remains + Ally gate mismatch |
| E4 | fallthrough after accept arms miss |

## Chain ownership

| Bit | Writer |
|----:|--------|
| 1, 2 | `Skill_ResolveTargetList` (bit2 via RangeCheck zero) |
| **4, 8, 0x10** | **this function only** (sole caller ResolveTargetList) |

## Callers / callees

| Role | Symbol | VA |
|------|--------|-----|
| Sole caller | `Skill_ResolveTargetList` | `0x00550300` |
| Callees (selected) | `FUN_005130e0`, `FUN_0040aff0`, `TFID_NotEquals`, `TFID_EqualsObjectId`, `FUN_004bb0d0`, `FUN_005749d0` | various |
| Downstream consumer | `Client_Skill_ResolveCastTarget` (bits 1/2/4/8) | `0x0093b3a0` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw/clean | **Confirmed** |
| Exact OR VAs via `read_memory` | **Confirmed** |
| Sole caller | **Confirmed** |
| Exclusive 4/8/0x10 writer in resolve chain | **Confirmed** |
| Parameter semantics | **High** |
| `vtbl+0x198` product name | Probable remains/dead-like (English open) |
| Bit 0x10 UX | Open |
| Product original name | Inferred |
| Runtime / bit-exact | Open |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0054ff00_FUN_0054ff00.md` (+ rename append)
- Annotated: `docs/reconstruction/raw/aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_FilterTargetForResolveList_Inferred.cpp`
- Dual: `reviews/A|B_aa_0054ff00_Skill_FilterTargetForResolveList_Inferred.md`
- Residual: `tmp/a_0054ff00.md`
- Parent residual: `reviews/a_00550300.md`
