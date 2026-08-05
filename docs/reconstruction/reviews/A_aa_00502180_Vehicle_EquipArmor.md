# Review A (reconstruction fidelity): `aa_00502180` Vehicle_EquipArmor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00502180` |
| **VA** | `0x00502180` |
| **Canonical name** | `Vehicle_EquipArmor` (**INFERRED** wrapper) |
| **Aliases** | `FUN_00502180`, `Inv_Tried_to_equip_same_armor_d` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00502180_Vehicle_EquipArmor.md` |
| **System** | `inventory-transfer` (equip path) |
| **Evidence pass** | Live Ghidra decompile + `read_memory`; sibling dual `Vehicle_SetEquippedArmor` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Minimal same-equip wrapper** over `Vehicle_SetEquippedArmor` for hardpoint **`vehicle+0x254`**:

1. If `new == *(this+0x254) && new != 0` → log `"Tried to equip same armor %d"` and return (**no** out-write).
2. `*outPrev = *(this+0x254)` (unconditional write when not same-equip).
3. `Vehicle_SetEquippedArmor(this, new, bSkipUnbind)`.

RecvInventoryEquip class **0x1c**; menu equip armor sound path.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00502180_FUN_00502180.md` |
| Annotated | `docs/reconstruction/raw/aa_00502180_FUN_00502180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00502180.cpp` |
| Function record | `docs/reconstruction/functions/aa_00502180_FUN_00502180.md` |
| SetArmor dual | `reviews/A_aa_00502090_Vehicle_SetEquippedArmor.md` |
| Counterpart B | `reviews/B_aa_00502180_Vehicle_EquipArmor.md` |

---

## 3. Signature (assembly-sealed)

```c
// __thiscall ECX = vehicle; ret 0x0c
void Vehicle_EquipArmor(
    void *vehicle,
    void *armor,
    int *outPrev,       // required on success path (no null check)
    char bSkipUnbind);  // forwarded to SetEquippedArmor
```

### Image (`read_memory` 2026-07-29)

```
mov edx, [ecx+0x254]
mov eax, [esp+4]          ; armor
cmp eax, edx
jne  do_set
test eax, eax
jz   do_set
; log "Tried to equip same armor %d"; ret 0xc
do_set:
mov  [outPrev], edx
push bSkipUnbind
push armor
call Vehicle_SetEquippedArmor   ; ECX=vehicle
ret  0xc
```

| Stage | Match | Confidence |
|---|---|---|
| Hardpoint `+0x254` | **Yes** | **High** |
| Same-equip log + return | **Yes** | **High** |
| Always `*outPrev` on proceed | **Yes** | **High** (no null test) |
| Forwards to `SetEquippedArmor` | **Yes** | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Wrapper only (no type check here) | **High** | type 0x1c lives in SetEquippedArmor |
| Same-equip string | **Confirmed** | plate |
| outPrev non-optional on set path | **High** | bytes write always |
| Skip-unbind passthrough | **High** | third stack arg |

---

## 5. Gaps / open

1. Callers that pass null `outPrev` (would fault).
2. Relationship of menu path vs Recv non-local path flag values.

**Verdict:** **accept-with-gaps**
