# Function record: CVOGObjectiveRequirement_Collect_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Action` |
| **Prior** | `FUN_00611f20` |
| **Address** | `0x00611f20` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Status** | **Human-refined + dual residual sealed 2026-07-29** (accept-with-gaps) |
| **Runtime / diff / bit-exact** | Open |
| **Verdict** | **partial** — dual A/B accept-with-gaps; clean kill CF stubbed (raw full) |

---

## Purpose

Collect requirement **virtual Action** (vtable `+0x04` under `PTR_FUN_009e12c4`):

| `param_4` | Arm | Effect | Low-byte return |
|:---------:|-----|--------|-----------------|
| `0` / null | Kill / optional loot | Multi-gate drop% → `GiveItemByCbid` + place (single or convoy) | **always 0** (side effects only) |
| `1` | Inventory change | `CountItemsByCbid` + CBID match + under `NumToCollect` | **1** if interested |
| other | — | Fallthrough | **0** |

Does **not** compute Eval fraction (`aa_00611940`) or SlotAction UI (`aa_006124b0`). Does **not** write mission objective slot floats.

---

## Signature (semantic)

```c
// thiscall: ECX = Collect requirement*
// Stack: +4 character, +8 unused(p3), +0xc eventType, +0x10 eventA,
//        +0x14 eventB, +0x18 unused(p7), +0x1c actor
uint __thiscall CVOGObjectiveRequirement_Collect_Action(
    int*   req,        // this
    int    character,  // cargo at +0x250
    uint   /*unused*/, // param_3 — unread
    int    eventType,  // 0 kill / 1 inventory (decomp typed int* — wrong)
    float  eventA,     // kill: killed CBID as int; inv: event item CBID
    float  eventB,     // inv: qty delta subtracted from live count
    uint   /*unused*/, // param_7 — unread
    int*   actor);     // killer / event actor (vtbl +0x27c/+0x1d4/+0x1c8/…)
```

Return: `uint` with **low-byte bool-like**. Only inventory success path sets low byte to 1 (`CONCAT31(...,1)`); fail / kill paths mask with `& 0xffffff00`.

---

## Layout consumers (req)

| Offset | Field | Use |
|------:|-------|-----|
| `+0x10` | Item CBID | Count / GiveItem / inv match |
| `+0x14` | NumToCollect | under-need gates |
| `+0x19` | TargetIsPlayer | non-player vs player kill branch |
| `+0x1a` | TargetIsTemplateVehicle | optional-target match mode |
| `+0x1c` | OptionalTarget count | non-player loop bound (**must be >0**) |
| `+0x20`… | OptionalTargetCBID[≤10] | match / `-1` wildcard |
| `+0x48` | OptionalDropPercent (f32) | RNG gate |
| `+0x4c` | GiveToAllConvoyMembers | single vs convoy |
| `+0x50`/`+0x54` | AllowedType / AllowedClass | player-target bits |
| `+0x58`/`+0x5c`/`+0x60` | RequireLevel flag/min/max | actor level band |

Cargo bridge (both arms): `character+0x250` → vehicle; grid at `vehicle+0x2b0` (`vehicle[0xac]`).

---

## Constants (verified `read_memory` 2026-07-29)

| Symbol | VA | Value | Role |
|--------|-----|------:|------|
| `DAT_00aaa638` | `0x00aaa638` | ≈ `1/65536` | drop RNG scale on u16 |
| `DAT_00a0f718` | `0x00a0f718` | `0.01` | drop% scale |
| `DAT_00aaa8a8` | `0x00aaa8a8` | `300.0` | convoy member 2D radius |

Drop pass: `(float)u16 * (~1/65536) <= OptionalDropPercent * 0.01`.

---

## Vtable / identity

| Fact | Value |
|------|-------|
| Collect vtable | `PTR_FUN_009e12c4` @ `0x009e12c4` |
| This body | slot `+0x04` → `0x00611f20` |
| Eval sibling | slot `+0x10` → `0x00611940` |
| SlotAction sibling | slot `+0x18` → `0x006124b0` |
| Ctor | `0x00611690` sets type code **2** |
| Xrefs | **DATA only** from `0x009e12c8` (virtual; no CODE callers) |

---

## Callees (Ghidra)

`FUN_005711c0` (CountItemsByCbid), `FUN_005001f0` (template id), `CVOGReaction_RandomUnitScalar`, `FUN_00404c90` (pos), `FUN_00404d70` (template check), `CNDHash_LookupByKey`, `CVOGReaction_GiveItemByCbid`, `FUN_004d2820` (place), `FUN_007a4480` (log), `FUN_00574760` (convoy member).

---

## Related artifacts

| Kind | Path |
|------|------|
| Raw (authoritative full body) | `raw/aa_00611f20_FUN_00611f20.md` |
| Raw named | `raw/aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| Annotated | `raw/aa_00611f20_*.annotated.md` |
| Clean (inventory arm; kill stubbed) | `reconstructed-exact/CVOGObjectiveRequirement_Collect_Action.cpp` |
| Dual A | `reviews/A_aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| Dual B | `reviews/B_aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| Chain | `reviews/CHAIN_2026-07-29_inventory_collect.md` |
| Count bridge | `aa_005711c0` |
| Eval sibling | `aa_00611940` |
| Scratch full CF map | `tmp/a_00611f20.md` |
| Legacy scaffold record | `functions/aa_00611f20_FUN_00611f20.md` |

---

## Dual residual seal (2026-07-29)

| Item | Status |
|------|--------|
| Dual event arms + cargo/Count bridge | **Sealed High** |
| Inventory return-1 predicates + kill return polarity 0 | **Sealed High** |
| Kill multi-gate structure + drop/convoy constants | **Sealed High** |
| Empty OptionalTarget non-player trap | **Sealed High** |
| Virtual-only entry / unused p3/p7 | **Sealed High** |
| Return-1 ≠ objective complete | **Sealed** as negative claim |
| Clean full kill/convoy CF | **Open by design** — leave full path in raw |
| Return-1 consumer / runtime / server GiveItem authority | **Open** |
| Pre-spawn count stack home SSA | **Intent High / home Probable** |
| Product names for eventA/eventB/actor | **Probable** |

---

## Confidence summary

| Area | Level |
|------|-------|
| Class Collect + Action slot | **High** |
| Dual kill / inventory CF structure | **High** |
| Cargo + CountItemsByCbid bridge | **High** |
| Inventory interest predicates | **High** |
| Drop formula + convoy radius constants | **High** |
| Clean kill fidelity | **N/A — stubbed** (raw is oracle) |
| Original method name | **Tentative** (role High) |
| Runtime / server / dispatcher | **Open** |

---

## One-line status

**Dual residual sealed (accept-with-gaps):** static Action dual-event structure, cargo bridge, drop/convoy math, and return polarity sealed; full kill CF remains in raw; clean inventory-only; runtime/server/return-consumer open.
