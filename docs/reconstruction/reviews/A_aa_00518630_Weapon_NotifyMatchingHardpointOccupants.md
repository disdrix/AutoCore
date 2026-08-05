# Review A (reconstruction fidelity): `aa_00518630` Weapon_NotifyMatchingHardpointOccupants

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518630` |
| **VA** | `0x00518630` |
| **Canonical name** | `Weapon_NotifyMatchingHardpointOccupants` (**INFERRED**) |
| **Aliases** | `FUN_00518630`, equip weapon-slot pre-unbind purge/notify |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip nested residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00518630_Weapon_NotifyMatchingHardpointOccupants.md` |
| **System** | `inventory-transfer` / weapons |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Before a **ranged weapon slot replace** (`Vehicle_EquipWeaponSlot` `0x004fe110`), collect live objects whose clonebase CBID matches a hardpoint-linked definition, stamp a value, and notify them:

**Gates:** `this+0xac` host non-null **and** host vfunc `+0x214()` non-null (occupant/hardpoint table owner).

**Flow:**

1. SEH frame; hash at `this+0x70` traversal-lock byte `+0x1d` (strings `HashError:TraversalLock…` / `TraverseToNext…` / `VOG_DEBUG_STOP`).
2. Walk hash nodes (`+0x14` chain); for each value with `*(byte*)(val+0xda) != 0`, load linked CBID `*(val+0x14c)`.
3. For each TFID in host table (`FUN_004c3f10(1)` count; entries stride `0x10` at host `+0x1bc..+0x1c0`):
   - `Object_ResolveFromTFID`; if resolved clonebase `+0x34` **equals** linked CBID, push to growable vector (`FUN_004073a0` / inline).
4. Unlock hash `+0x1d = 0`.
5. If vector non-empty and `(param_3 == 0 || count >= lastSlotByte)`:
   - For up to **`param_2`** entries: `*(obj+0xcc) = param_4`; `FUN_004d0e90(obj)`.
6. `operator_delete` vector (decompiler “noreturn” artifact — returns after free).

**Primary equip call site:** `FUN_004fe110` → `FUN_00518630(100, 0, 0)` immediately before unbind vfunc `+0x158(0)` on previous weapon — max **100** notifies, no min-count gate (`param_3==0`), stamp **0**.

Also called from `FUN_005ffa10` (non-equip residual).

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | weapon / hardpoint-bearing object (this) |
| stack0 | `maxNotify` (equip path: **100**) |
| stack1 | `requireMinCount` char (0 = always if any) |
| stack2 | stamp written to `obj+0xcc` |
| return | void |

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00518630_*`, `reconstructed-exact/FUN_00518630.cpp` |
| Live decompile | Ghidra 2026-07-29 |
| Parent dual | `A_aa_004fe110_Vehicle_EquipWeaponSlot` |
| Callees | `Object_ResolveFromTFID`, `FUN_004c3f10`, `FUN_004073a0`, `FUN_004d0e90`, `FUN_007a4480` |
| Hash strings | TraversalLock / TraverseToNext / VOG_DEBUG_STOP |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Host `+0xac` + vfunc `+0x214` gate | **Yes** |
| Hash lock at `+0x70/+0x1d` | **Yes** |
| CBID match via resolve table | **Yes** |
| Cap by `param_2`; stamp `+0xcc` | **Yes** |
| `FUN_004d0e90` notify | **Yes** |
| delete vector | **Yes** (noreturn warning residual) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Equip pre-unbind side-effect helper | **High** | sole call from EquipWeaponSlot body |
| Args (100,0,0) at equip site | **High** | parent clean/raw |
| Not the slot store itself | **High** | no `+0x260` write |
| Product name of `FUN_004d0e90` | **Open** | role = per-object notify |
| Occupant table layout product | **Medium** | offsets sealed |

---

## 6. Gaps

1. Formal product names for `FUN_004d0e90` / host vfunc `+0x214`.
2. What `+0xcc` stamp means at consumers.
3. Runtime / bit-exact open.
4. Decompiler delete-noreturn noise.

**Verdict:** Pre-unbind matching-occupant notify sealed at CF. **accept-with-gaps.**
