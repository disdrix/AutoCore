# Review A (reconstruction fidelity): `aa_00611f20` Collect_Action

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611f20` |
| **VA** | `0x00611f20` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_Action` |
| **Prior FUN_** | `FUN_00611f20` |
| **Review date** | `2026-07-29` (dual residual strengthen) |
| **Reviewer role** | Independent reconstruction-fidelity review |
| **Counterpart** | `reviews/B_aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| **Verdict** | **accept-with-gaps** |
| **Dual residual** | **sealed (static)** — accept-with-gaps; clean kill CF left in raw |

---

## 1. Purpose

Collect requirement **virtual Action** (vtable `+0x04`). Dual-purpose event sink:

1. **Death / loot path** (`param_4 == 0` / null): optional kill-target match → `OptionalDropPercent` RNG → `CVOGReaction_GiveItemByCbid` + place (`FUN_004d2820`); single-character or convoy-all. **Always returns low-byte 0** after side effects (or silent fail).
2. **Inventory-change path** (`param_4 == 1`): re-count cargo via `InventoryGrid_CountItemsByCbid` (`0x005711c0`); if event item matches requirement CBID and `(count − (int)param_6) < NumToCollect`, return low-byte **1** — **only** low-byte-1 path in the unit.

Does **not** implement Eval fraction or SlotAction UI (siblings `0x00611940` / `0x006124b0`). Does **not** write mission slot floats.

---

## 2. Inspected artifacts (residual re-check)

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `0x00611f20` (this session; body ≡ raw `FUN_00611f20`) |
| Complete analysis | callers=[], xrefs DATA-only `009e12c8`, callees listed below |
| Raw (legacy full body) | `raw/aa_00611f20_FUN_00611f20.md` |
| Raw (named capture) | `raw/aa_00611f20_CVOGObjectiveRequirement_Collect_Action.md` |
| Annotated | `raw/aa_00611f20_*.annotated.md` |
| Clean | `reconstructed-exact/CVOGObjectiveRequirement_Collect_Action.cpp` (**inventory only**; kill stubbed) |
| Collect ctor | Ghidra `0x00611690` — type code **2**, vtable `PTR_FUN_009e12c4` |
| Collect Eval | `0x00611940` (cargo + count; no Action call) |
| Count bridge | `0x005711c0` `InventoryGrid_CountItemsByCbid` (includeBroken=`0`) |
| Vtable memory | `read_memory` @ `0x009e12c4` (12 dwords) — residual re-verify |
| Floats | `read_memory` `DAT_00aaa638` / `DAT_00a0f718` / `DAT_00aaa8a8` |
| Chain | `reviews/CHAIN_2026-07-29_inventory_collect.md` |
| Scratch CF map | `tmp/a_00611f20.md` |

---

## 3. Residual sealed facts (static)

| Claim | Confidence | Evidence |
|---|---|---|
| Class is Collect (`CVOGObjectiveRequirement_Collect`) | **High** | Ctor type=2 + RTTI; ptr at `PTR_FUN_009e12c4+0x04` |
| This is vtable Action slot `+0x04`, not Eval/SlotAction | **High** | Vtable: `+0x04=0x00611f20`, `+0x10=0x00611940`, `+0x18=0x006124b0` |
| `__thiscall` ECX = Collect req (`param_1`) | **High** | Decompile storage `register:ECX` |
| Stack formals (thiscall): char@`+4`, event@`+0xc`, A@`+0x10`, B@`+0x14`, actor@`+0x1c` | **High** | analyze locals storage; `param_3`/`param_7` empty storage / unread |
| `param_3` / `param_7` unused in body | **High** | No loads; decompiler `undefined4` with empty storage |
| Event discriminator: null/0 vs exact 1 on `param_4` | **High** | Outer `if (param_4==0)` / `else if (param_4==1 && cargo)` |
| Codes other than 0/1 → low-byte 0 | **High** | Fallthrough `LAB_00611fe2` |
| Cargo: `char+0x250` vehicle; grid non-null at `vehicle+0x2b0` (`[0xac]`) | **High** | Same as Collect_Eval |
| Inventory path: `CountItemsByCbid(req[4], 0)` then `(int)param_5==CBID && count-(int)param_6 < NumToCollect` → low-byte **1** | **High** | Exact compare before `CONCAT31(...,1)` |
| Kill path: **no** low-byte 1; GiveItem success still masks return to low-byte 0 | **High** | All kill exits `& 0xffffff00` or fallthrough |
| Kill multi-gate (level, cargo/count-under-need, optional targets or race/class, drop%, actor flags, template, hash/veto, GiveItem) | **High** structure | CF; silent fails common |
| Non-player kill requires `0 < req[7]` OptionalTarget count | **High** | Empty list ⇒ no client loot from this arm |
| Optional target match: CBID / `-1` wildcard, or template via `FUN_005001f0` when `TargetIsTemplateVehicle` | **High** | Loop `req+8` |
| Player-target: race `@+0x532` hostile + `AllowedType`/`AllowedClass` bitmasks `@req+0x50/+0x54` | **High** | CF; nested race-table walk |
| Drop roll: `(float)u16 * DAT_00aaa638 <= drop% * DAT_00a0f718` | **High** | `read_memory`: ≈`1/65536` and `0.01` |
| Convoy radius `DAT_00aaa8a8` = **300.0f** | **High** | `read_memory` `00 00 96 43` |
| GiveToAllConvoyMembers at `req+0x4c` + convoy ptr `char+0xcb0` | **High** | XML + CF; proximity + per-member hash/veto |
| Field map CBID/`NumToCollect`/drop%/targets/level from XML + use sites | **High** | ctor defaults + Action consumers |
| Virtual-only entry | **High** | Xref: **only** DATA `009e12c8`; callers=[] |
| Callees (this unit) | **High** | `FUN_005711c0`, `FUN_005001f0`, `CVOGReaction_RandomUnitScalar`, `FUN_00404c90`, `FUN_00404d70`, `CNDHash_LookupByKey`, `CVOGReaction_GiveItemByCbid`, `FUN_004d2820`, `FUN_007a4480`, `FUN_00574760` |
| Return-1 ≠ objective complete (no slot float write; no Eval call) | **High** as negative claim | Body; Eval is separate vtable method |
| Clean inventory arm behavior-equivalent; kill CF **not** in clean | **High** | Clean intentionally stubs loot → `return 0` |
| Pre-spawn count intent “held < NumToCollect” | **High** intent / **Probable** stack home | Result → `uStack_38`; compare `iStack_3c` (SSA noise) |

---

## 4. Control-flow map (raw ≡ live decompile)

| Stage | Match |
|---|---|
| `param_4 == 0` outer kill/loot | **Yes** |
| Optional level band on actor (`vtbl+0x27c`, min/max) | **Yes** |
| Non-player: cargo + count-under-need + optional-target loop | **Yes** (count stack noisy) |
| Player-target race/class bitmasks | **Yes** |
| Shared DROP: drop% RNG → actor soft gates → pos/template → single or convoy GiveItem | **Yes** |
| `param_4 == 1` inventory recount → low-byte 1 | **Yes** |
| Fallthrough `LAB_00611fe2` → low-byte 0 | **Yes** |

### Clean fidelity

| Aspect | Fidelity |
|---|---|
| Inventory branch | **Good** (reordered to top; predicates match) |
| Kill/loot full CF | **Gap / intentional stub** — authoritative body is raw |
| Named CBID / NumToCollect / cargo helpers | **Good** |
| Convoy / template / level edges | **Not in clean** — leave in raw |

---

## 5. Field map (req layout used by Action)

| Offset | Index (int*) | Field | Source |
|------:|-------------:|-------|--------|
| `+0x10` | `[4]` | Item CBID | XML `CBID` |
| `+0x14` | `[5]` | NumToCollect | XML `NumToCollect` |
| `+0x04`→`[1]+0x10` | parent | Mission hash key for `CNDHash_LookupByKey` | kill place path |
| `+0x19` | byte | TargetIsPlayer | XML |
| `+0x1a` | byte | TargetIsTemplateVehicle | XML |
| `+0x1c` | `[7]` | OptionalTarget count | XML multi |
| `+0x20`… | `[8]`… | OptionalTargetCBID[≤10]; ctor fills `-1` | XML + ctor |
| `+0x48` | `[0x12]` float | OptionalDropPercent | XML |
| `+0x4c` | byte of `[0x13]` | GiveToAllConvoyMembers | XML |
| `+0x50` / `+0x54` | `[0x14]`/`[0x15]` | AllowedType / AllowedClass masks | XML |
| `+0x58` / `+0x5c` / `+0x60` | flag / min / max | RequireLevel* | XML |

### Constants (`read_memory` 2026-07-29 residual)

| Symbol | VA | LE bytes | Value |
|--------|-----|----------|------:|
| `DAT_00aaa638` | `0x00aaa638` | `80 00 80 37` | ≈ `1.5258789e-05` (~1/65536) |
| `DAT_00a0f718` | `0x00a0f718` | `0a d7 23 3c` | `0.01` |
| `DAT_00aaa8a8` | `0x00aaa8a8` | `00 00 96 43` | `300.0` |

### Collect vtable (`0x009e12c4`, residual re-read)

| Slot | Off | VA | Role |
|-----:|----:|----|------|
| 0 | `+0x00` | `0x006126f0` | (family) |
| 1 | `+0x04` | **`0x00611f20`** | **Action (this)** |
| 4 | `+0x10` | `0x00611940` | Eval |
| 6 | `+0x18` | `0x006124b0` | SlotAction |

---

## 6. Residual disposition

| Prior / dual residual | Disposition |
|---|---|
| Dual event arms 0 vs 1 | **Sealed High** |
| Cargo + CountItemsByCbid bridge | **Sealed High** |
| Inventory return-1 predicates | **Sealed High** |
| Kill multi-gate structure + convoy radius + drop formula | **Sealed High** (structure + constants) |
| Empty OptionalTarget non-player trap | **Sealed High** (behavioral) |
| Virtual-only / no static callers | **Sealed High** |
| Kill always low-byte 0 (side effects only) | **Sealed High** |
| Return-1 ≠ complete objective | **Sealed** as negative (consumer still Open) |
| `param_3`/`param_7` unused | **Sealed High** |
| Pre-spawn count stack home (`uStack_38` vs `iStack_3c`) | **Intent High / SSA Probable** — do not claim bit-exact stack |
| Clean full kill/convoy body | **Open residual by design** — full CF remains in raw; clean stub OK |
| `param_5`/`param_6` product names | **Probable** (overloaded by event; int casts sealed) |
| `param_8` product type (killer vs actor) | **Probable–High** from vtbl uses; RTTI open |
| Return-1 virtual consumer | **Open** |
| Runtime event capture | **Open** |
| Client GiveItem vs server authority | **Open** (out of unit) |
| Drop% content scale 0–100 vs 0–1 | **Probable** percent-style (×0.01); assets not re-dumped here |

---

## 7. Cross-checks

- Sibling Eval/SlotAction use same cargo + `0x005711c0` + CBID/`NumToCollect` — Action inventory arm is the third consumer in the inventory↔collect chain.
- Deliver `0x00611290` is a **different** class (type 3); do not merge labels.
- Human name `Collect_Action` is role-inferred (vtable Action slot + Collect class); original symbol unknown — **High** role / **Tentative** original spelling.
- Agree with Review B on: multi-gate kill, empty-optional trap, clean non-authority for loot, return-1 demotion to interest bool.

---

## 8. Verdict

**accept-with-gaps** — dual residual **sealed (static)**.

Static dual-event behavior, field map, cargo bridge, drop-percent math (verified floats), convoy radius, vtable placement, kill-vs-inventory return polarity, and empty-optional-target edge are solid. Remaining gaps: incomplete clean kill path (raw is oracle), decompiler stack noise on pre-spawn count, param product names, return-1 consumer, server/runtime ownership of GiveItem.
