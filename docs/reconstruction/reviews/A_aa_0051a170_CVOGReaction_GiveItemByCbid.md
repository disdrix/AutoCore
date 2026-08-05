# Review A (reconstruction fidelity): `aa_0051a170` CVOGReaction_GiveItemByCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a170` |
| **VA** | `0x0051a170` |
| **Canonical name** | `CVOGReaction_GiveItemByCbid` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0051a170_CVOGReaction_GiveItemByCbid.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client **item factory by CBID** (not full bag-insert):

1. `FUN_00404d70(cbid)` → clonebase def; null → return 0.
2. Switch on `itemDef+0x38` (clonebase type id).
3. Per-type `operator_new(size)` then type-specific ctor (`FUN_005c7f30` weapon/currency/ammo, armor, module, container, vehicle, special subtypes, mount, pet, consumable, mission/quest items, blueprint, key/salvage/token raw returns, etc.).
4. Most success paths return **dual-base simple-object** pointer: `item + *(*(item+4)+4) + 4`.
5. Blueprint uses alternate adjust; key/salvage/token return ctor raw.
6. Default: log `"VOG_DEBUG_STOP"` and return 0.

Does **not** place the item into an inventory bag — callers insert the returned object.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051a170_CVOGReaction_GiveItemByCbid.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_GiveItemByCbid.cpp` |
| System map | `docs/reconstruction/systems/inventory-transfer.md` (when present) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__cdecl(cbid) → item*|0` | **High** | Raw |
| Lookup via FUN_00404d70 | **High** | First call |
| Type switch on def+0x38 | **High** | All cases |
| Per-type new sizes preserved | **High** | Match raw cases |
| Dual-base adjust common path | **High** | LAB dual-base |
| Blueprint alternate adjust | **High** | Explicit |
| Key/salvage/token raw return | **High** | Early return cases |
| Ctor FUN names / type labels | **Tentative** | Labels are plate inference |
| Does not insert into bag | **High** | No inventory walk in body |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null def → 0 | **Yes** |
| Type switch cases / sizes | **Yes** |
| Dual-base vs raw return paths | **Yes** |
| Default VOG_DEBUG_STOP | **Yes** |
| No invented bag insert | **Yes** |

---

## 5. Gaps

1. Ctor symbols remain FUN_*; type labels are human inference.
2. operator_new result often unused by decompiler surface (placement/side-effect).
3. Ammo nCbid==0 branch shape odd — needs runtime.
4. Callers that bag-insert not enumerated in this review.

**Verdict:** accept-with-gaps.
