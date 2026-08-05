# Review A (reconstruction fidelity): `aa_004fdcb0` Vehicle_CastItemSkillsOnEquip

| Field | Value |
|---|---|
| **Stable ID** | `aa_004fdcb0` |
| **VA** | `0x004fdcb0` |
| **Canonical name** | `Vehicle_CastItemSkillsOnEquip` |
| **Aliases** | `FUN_004fdcb0`, equip-path skill cast / reaction fire |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B — Equip callee residual) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004fdcb0_Vehicle_CastItemSkillsOnEquip.md` |
| **System** | `inventory-transfer` / skills |
| **Dual status** | **Present** (first dual pair) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

After an item is bound onto a vehicle slot (weapon / melee / ornament / armor / wheelset paths), **fire equip-time skills / reactions** owned by that item:

**Gates:** vehicle COM has character host `+0xb0`, clonebase `+0xa8`, item non-null, and `Object_ResolveFromTFID(host.TFID@+0x160)` succeeds.

**Phase A — pending reaction list on item (`item[0x1c]`):**  
Iterate `FUN_00411900` over list built by `FUN_00402c40`. For each entry with flag `*(entry+0x614) & 0x100`, cast via `CVOGReaction_CastSkillOnTarget` with target mode args (host-relative offset `+0x84` or alternate `+0xb0` when `vehicle+8 != 0`). Then clear `*(item[0x1c]+0x1d)=0`.

**Phase B — skill table on item (requires `FUN_004ce940()` non-null world/context):**  
1. For `i in [0, item.vtbl+0x60)`: if `vtbl+0x5c(i)` skill id non-zero, resolve via `FUN_00509940` + `CVOGReaction_ResolveSkillTargets`, then `CastSkillOnTarget` (delete targets — decompiler marks noreturn on delete; CF is cast-then-free).  
2. For `j in [0, item.vtbl+0x80)`: if `vtbl+0x7c(j)` non-zero, `FUN_00404d70` → def `+0x3c` → skill id at `+0x4c0`, resolve targets with level from `vtbl+0x94(j)`, cast same way.

---

## 2. Calling convention

| Slot | Role |
|------|------|
| **ECX** | vehicle (this) |
| stack0 | item* just equipped |
| return | void |

Heavy xrefs from equip helpers: `004fe110` weapon, `004fe800` melee, `004fe620` ornament, `00502180` armor, `004ff510` wheelset, attach paths `004fdf*`, etc. (~15 call sites).

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_004fdcb0_*`, `reconstructed-exact/FUN_004fdcb0.cpp` |
| Live decompile | Ghidra 2026-07-29 ≡ raw |
| Parent equip duals | weapon/melee/ornament/armor/wheelset A_aa reviews |
| Skill callees | `CVOGReaction_CastSkillOnTarget`, `CVOGReaction_ResolveSkillTargets`, `Object_ResolveFromTFID` |
| Hash walk | `FUN_00411900` CNDHash traverse |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Quad gate host/clonebase/item/resolve | **Yes** |
| Phase A list walk + flag `0x100` | **Yes** |
| Clear `+0x1d` byte after phase A | **Yes** |
| `FUN_004ce940` gate for phase B | **Yes** |
| Dual loops `+0x60/+0x5c` and `+0x80/+0x7c` | **Yes** |
| CastSkillOnTarget + operator_delete | **Yes** (delete warning residual) |
| Early return if gates fail | **Yes** |

---

## 5. Notable offsets / vfuncs

| Site | Role | Confidence |
|------|------|------------|
| vehicle COM `+0xb0` | character host | **High** |
| vehicle COM `+0xa8` | clonebase* gate | **High** |
| host `+0x160` | TFID for resolve | **High** |
| item `[0x1c]` | reaction list head | **High** as pointer |
| entry `+0x614` bit `0x100` | equip-cast eligible | **High** |
| item vtbl `+0x5c/+0x60/+0x70` | skill id table A | **High** as calls |
| item vtbl `+0x7c/+0x80/+0x94` | skill id table B + level | **High** |
| def blob `+0x4c0` | skill id from secondary table | **High** |

---

## 6. Gaps

1. Decompiler `operator_delete` “does not return” — real control returns to loop (known Ghidra artifact); not modeled as abort.
2. Product names for `FUN_004ce940` / `FUN_00509940` / `FUN_00404d70`.
3. Exact CastSkillOnTarget arg meanings beyond dual of that unit.
4. Runtime / bit-exact open.

**Verdict:** Equip-time skill fire pipeline sealed at CF. **accept-with-gaps.**
