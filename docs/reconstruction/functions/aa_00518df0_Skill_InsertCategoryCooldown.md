# Function record: Skill_InsertCategoryCooldown

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518df0` |
| **Canonical name** | `Skill_InsertCategoryCooldown` |
| **Address** | `0x00518df0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **accept-with-gaps** dual A/B residual seal 2026-07-29 — CF/ABI/pack sealed; owner class name + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

High-level API to arm a **category cooldown** on the cast-owner map: skip if `categoryId == -1`; else pack `{categoryId, g_dwClientTickMs, durationMs}` and `Skill_CategoryCooldownMap_Insert` on the lazy map from `Skill_GetCategoryCooldownMap(owner)`.

## Signature (sealed)

```c
void __stdcall Skill_InsertCategoryCooldown(int nCategoryId, int nDurationMs);
// RET 0x8
// ECX (implicit, not formal) = map owner — host with map* at +0x6c
```

## Behavior (Confirmed CF)

```
if (nCategoryId == -1) return;
entry = { key: nCategoryId, start: g_dwClientTickMs, duration: nDurationMs };
map = Skill_GetCategoryCooldownMap(ECX);   // lazy +0x6c
Skill_CategoryCooldownMap_Insert(map, &outPair, &entry);  // insert-or-find; out ignored
```

### Layout (entry + global)

| Item | Detail |
|---|---|
| Entry | 12 B: `key@+0`, `startTick@+4`, `durationMs@+8` |
| Clock | `g_dwClientTickMs` @ `0x00b041cc` (`uint`, client ms) |
| Map host | owner `+0x6c` (GetMap sibling) |
| Node (callee) | 0x1C; key `+0xC`, start `+0x10`, duration `+0x14` |

### Important semantic

`Map_Insert` is **insert-or-find**, not insert-or-assign. Re-arming the same category while the node exists **does not** refresh start/duration via this path.

## Callers / callees

| Role | VA / name | Notes |
|---|---|---|
| Caller (only static) | `Skill_ApplyStatusEffectLocal` @ `0x0051ac77` | item path `packet+0x38 != 0` |
| Callee | `Skill_GetCategoryCooldownMap` `0x00518d70` | site `0x00518e1c` |
| Callee | `Skill_CategoryCooldownMap_Insert` `0x0051d2f0` | site `0x00518e23` |

Cast-again (`CVOGHBOKToCastAgain_ctor`) inserts category CD via **direct** Map_Insert — not a caller of this wrapper.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518df0_Skill_InsertCategoryCooldown.md`
- Annotated: `docs/reconstruction/raw/aa_00518df0_Skill_InsertCategoryCooldown.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_InsertCategoryCooldown.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00518df0_Skill_InsertCategoryCooldown.md`, `B_aa_00518df0_Skill_InsertCategoryCooldown.md`

## Confidence

| Claim | Level |
|---|---|
| CF / early-out `-1` | **High** (decompile ≡ bytes) |
| ABI `__stdcall` `RET 8` | **High** (`C2 08 00`) |
| Pack start=`g_dwClientTickMs` (`0x00b041cc`) | **High** (`A1 CC 41 B0 00`) |
| Clock units ms | **High** (global plate + physics peers) |
| ECX = map owner for GetMap | **High** (phantom ECX + GetMap `__fastcall`) |
| Sole static caller | **High** (`get_function_xrefs` / callers) |
| Insert-or-find no refresh | **High** (Map_Insert dual; inherited) |
| Owner product class name | **Open** |
| Runtime / bit-exact | **Open** |
