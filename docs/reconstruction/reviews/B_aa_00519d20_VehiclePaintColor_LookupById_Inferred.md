# Review B (skeptical / adversarial): `aa_00519d20` VehiclePaintColor_LookupById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519d20` |
| **VA** | `0x00519d20` |
| **Canonical name** | `VehiclePaintColor_LookupById_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00519d20_VehiclePaintColor_LookupById_Inferred.md` |
| **System** | vehicle paint |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as MedalDef_LookupById | Medals use `DAT_00b042e0` + `00519660`; this uses `b042b4/b8/bc` + `00519a30` | **Falsified** medal identity |
| 2 | Returns full node* | Returns `*(*(node+8))` first dword | **Falsified** node* |
| 3 | Negative id hard-null | No signed test (unlike medals) | **Agree** no signed gate |
| 4 | Inserts into table | Read-only lookup | **Falsified** insert |
| 5 | UI-only helper | Also `004fcd80` mesh tint path | **Falsified** UI-only |
| 6 | Count global is occupancy forever | Lazy gate; post-load meaning open | **Survives with gap** |

---

## 2. Live ≡ raw

```
Live ≡ raw: ensure → bucket → chain key@+0x10 → *value@+8 → *payload
```

---

## 3. Surviving contract

```
// payload_first_dword_or_0 = Lookup(id)
// Table: mask DAT_00b042b4, buckets DAT_00b042bc, count DAT_00b042b8
// Lazy: FUN_00519a30
```

**Verdict:** **accept-with-gaps.**
