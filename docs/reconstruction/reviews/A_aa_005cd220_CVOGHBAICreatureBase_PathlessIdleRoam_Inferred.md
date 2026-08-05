# Review A (reconstruction fidelity): `aa_005cd220` CVOGHBAICreatureBase_PathlessIdleRoam_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cd220` |
| **VA** | `0x005cd220`–`0x005cd3ad` exclusive |
| **Body** | **397** bytes / `0x18D` |
| **Canonical name** | `CVOGHBAICreatureBase_PathlessIdleRoam_Inferred` |
| **Ghidra name** | `FUN_005cd220` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-S) |
| **Counterpart** | `reviews/B_aa_005cd220_CVOGHBAICreatureBase_PathlessIdleRoam_Inferred.md` |
| **System** | client creature HBAI / pathless idle roam |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + caller decompile + float globals |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pathless idle-roam step for `CVOGHBAICreatureBase`:

1. Gate on owner flag `+0x279` and AI cooldown (`[0x1d]` vs `g_dwClientTickMs - [0x1c]`).
2. Mark busy byte `[0x1e]`.
3. With **1/3** probability (`rand_u16 % 3 == 0`), sample radius from table `+0x4d4` (if `r < 3.0f` then `r += 3.0f`).
4. Build local XZ offset in `~[-r,+r]` via `u16 * r * 2.0f * (~1/65536) - r`.
5. Orient via `FUN_0053e0b0` + `Math_QuatTransformPoint_Inferred`; issue move via AI **vtbl+0x4c**.

Does **not** path toward the player.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | full body @ `0x005cd220` |
| Bounds | `get_function_by_address` → `005cd220`–`005cd3ad` |
| Entry / exit | `55 8b ec 83 e4 f0 …` / `… 5d c3 cc` |
| Callers | `CVOGHBAICreatureBase_OnHeartBeat` xrefs `005d0667`, `005d0769` |
| Floats | `0xa1330c=3.0`, `0xa10e74=2.0`, `0xaaa638≈1.5259e-5` |
| Math callee | `aa_004e8bf0` Math_QuatTransformPoint_Inferred |
| Domain doc | `docs/NPC.md` pathless idle roam note |
| Raw / annotated / clean | W30-S updated |

**Not performed:** Launcher, runtime golden, product demangle, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// __thiscall; ECX = AI*; no stack args; ret (c3); uint incidental
uint32_t CVOGHBAICreatureBase_PathlessIdleRoam_Inferred(void *ai_self);
```

| Formal | Source | Conf |
|---|---|---|
| this / ECX | HBAI creature controller | **High** |
| stack args | none | **High** |
| cleanup | plain `ret` | **Confirmed** |
| return | ignored by OnHeartBeat | **High** |

---

## 4. Control flow checklist

| Stage | Match | Conf |
|---|---|---|
| owner+0x279 gate | **Yes** | **High** |
| cooldown vs `g_dwClientTickMs` | **Yes** | **High** |
| set busy `[0x1e]=1` | **Yes** | **High** |
| 1/3 random gate | **Yes** | **Confirmed** |
| radius + floor-add 3.0 | **Yes** | **Confirmed** |
| XZ offset formula | **Yes** | **Confirmed** |
| quat transform + set dest | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pathless idle roam role | **High** | caller context + NPC.md + CF |
| Formula constants | **Confirmed** | `read_memory` |
| Misnamed globals (2.0 / 3.0) | **Confirmed** | values ≠ symbol semantics |
| Multi-inherit ECX for vtbl+0x1a4 | **Medium** | decomp path only |
| Radius field product name | **Inferred** | `+0x4d4` patrol family |
| Runtime | **Open** | |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Exact product name for radius `+0x4d4` and flags `+0x279` / AI `+0x70/+0x74/+0x78`.
3. Full typing of object vtbl `+0x1a4` pack helper.
4. Why return value is computed when callers ignore it.
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps** — CF, gates, formula, and caller role sealed; field English residual.
