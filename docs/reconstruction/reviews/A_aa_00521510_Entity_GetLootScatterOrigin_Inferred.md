# Review A (reconstruction fidelity): `aa_00521510` Entity_GetLootScatterOrigin_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521510` |
| **VA** | `0x00521510` |
| **Canonical name** | `Entity_GetLootScatterOrigin_Inferred` (leave-FUN retail) |
| **Prior names** | `FUN_00521510`; scaffold Named_CalleeOf_OnDeath… |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity / clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00521510_Entity_GetLootScatterOrigin_Inferred.md` |
| **System** | missions-progression / combat death loot placement |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return a **64-bit origin token** (two dwords packed — likely **TFID / position handle**) for loot scatter and related placement.

```
if *(this+0xcb0) == 0:
  // non-convoy / simple entity path
  base = *( *(this+4) + 4 )     // component offset root
  return PACK(*(base + 0x168 + this), *(base + 0x164 + this))
else:
  // convoy / multi-slot path
  v = FUN_00575870(this, param_2)
  if v == -1: fall back to same PACK fields
  return v
```

Call sites: OnDeath credit drop (`FUN_004d2750`), item list scatter (`store at item+0x170` + `FUN_004d2820`), plus `FUN_004d31a0`, `FUN_004d4440`, and inside `FUN_0050ac80`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean / function record | `aa_00521510_*` |
| Live decompile | Ghidra `0x00521510` ≡ clean |
| Related | `+0xcb0` convoy flag also branches XP path in OnDeath |
| Helper | `FUN_00575870` (convoy member resolve; not dualed this pass) |

---

## 3. Control flow (authoritative)

```
longlong __thiscall FUN_00521510(int this, undefined4 param_2):
  if (*(int*)(this + 0xcb0) == 0):
    iVar1 = *(*(this + 4) + 4)
    return CONCAT44(*(this + iVar1 + 0x168), *(this + iVar1 + 0x164))
  lVar2 = FUN_00575870(this, param_2)
  if (lVar2 == -1):
    iVar1 = *(*(this + 4) + 4)
    lVar2 = CONCAT44(*(this + iVar1 + 0x168), *(this + iVar1 + 0x164))
  return lVar2
```

Note: offsets `0x164/0x168` are **relative to `this` with base `iVar1` added** — standard MSVC component layout (`this + *(vtbl_adjust) + field`).

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall + one extra formal | **High** | |
| Branch on `this+0xcb0` | **High** | shared with OnDeath convoy XP |
| Fallback pair at adj+0x164 / +0x168 | **High** | |
| `FUN_00575870` == -1 → same fallback | **High** | |
| Return is 64-bit packed two u32 | **High** | CONCAT44 |
| Product = loot scatter / placement origin | **Probable** | call-site use |
| Fields are TFID vs XYZ | **Tentative** | parent stores to `item+0x170` as undefined8 |
| Meaning of `param_2` into 00575870 | **Open** | often position stack in parent |

---

## 5. Control flow: clean ≡ raw

**Yes.**

---

## 6. Callers (static)

| Site | Role |
|---|---|
| OnDeathAwardKillXp | credits + item scatter |
| FUN_004d31a0 / FUN_004d4440 | related death/loot placement |
| FUN_0050ac80 | internal generate path |

---

## 7. Gaps / open

1. Exact type of packed 64-bit (TFID_16×2? world handle?).
2. Dual `FUN_00575870` convoy resolver.
3. Layout registry for adj+0x164/0x168.

**Verdict:** CF **High**. Token semantics **Probable/Tentative**. **accept-with-gaps.**
