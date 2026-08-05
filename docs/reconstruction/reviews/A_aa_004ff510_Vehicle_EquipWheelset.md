# Review A (reconstruction fidelity): `aa_004ff510` Vehicle_EquipWheelset

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff510` |
| **VA** | `0x004ff510` |
| **Canonical name** | `Vehicle_EquipWheelset` (**INFERRED** wrapper) |
| **Aliases** | `FUN_004ff510`, `Inv_Tried_to_equip_same_wheelset_d` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004ff510_Vehicle_EquipWheelset.md` |
| **System** | `inventory-transfer` (equip path) |
| **Evidence pass** | Live Ghidra decompile; sibling dual `Vehicle_SetWheelset` (`+0x258`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Same-equip-gated / previous-out wrapper** over `Vehicle_SetWheelset` for hardpoint **`vehicle+0x258`** (decimal **600** in decompiler):

1. If `new == current && new != 0` → log `"Tried to equip same wheelset %d"` and return.
2. If `outPrev != null` **and** current non-null **and** `*(char*)(current+0xcc) == 0` → `*outPrev = current` (gated previous capture).
3. If current non-null:
   - type-check current clonebase `+0x38 == 0x10` else log `"Set wheelset2 of unhappy type…"`
   - `FUN_004fbb50` on current gfx base; unbind **`+0x158(0)`**
4. `Vehicle_SetWheelset(new)` (this = vehicle).
5. If new non-null → copy item TFID/COID halves to vehicle **`+0x628` / `+0x62c`**; else write **`0xFFFFFFFF`** to both.

RecvInventoryEquip class **0x10**; menu equip same.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ff510_FUN_004ff510.md` |
| Annotated | `docs/reconstruction/raw/aa_004ff510_FUN_004ff510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004ff510.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ff510_FUN_004ff510.md` |
| SetWheelset dual | `reviews/A_aa_004fea90_Vehicle_SetWheelset.md` |
| Counterpart B | `reviews/B_aa_004ff510_Vehicle_EquipWheelset.md` |

---

## 3. Signature

```c
// __thiscall ECX = vehicle
void Vehicle_EquipWheelset(
    void *vehicle,
    void *wheelset,     // new or null
    void **outPrev);    // optional; gated by item+0xcc
```

### Control flow seal

| Stage | Match | Confidence |
|---|---|---|
| Hardpoint load `+0x258` (600) | **Yes** | **High** |
| Same-equip early out | **Yes** | **High** |
| Gated `*outPrev` (`item+0xcc==0`) | **Yes** | **High** CF / **Tentative** flag English |
| Pre-clear + `Vehicle_SetWheelset` | **Yes** | **High** |
| COID pair `+0x628/+0x62c` or −1 | **Yes** | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Slot `+0x258` | **High** | sealed class map + SetWheelset dual |
| Type 0x10 wheelset | **High** | unhappy string + SetWheelset |
| COID mirror offsets | **High** | store/clear |
| `+0xcc` gate English | **Tentative** | only known as char flag |
| Same-equip does not clear COID | **High** | early return |

---

## 5. Gaps / open

1. Product meaning of `item+0xcc` previous-out gate.
2. Whether pre-unbind here duplicates work inside `SetWheelset` on some paths.

**Verdict:** **accept-with-gaps**
