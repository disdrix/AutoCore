# Review A (reconstruction fidelity): `aa_005d6c10` CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d6c10` |
| **VA** | `0x005d6c10`–`0x005d6c37` |
| **Canonical name** | `CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred` |
| **Ghidra name** | `FUN_005d6c10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-T) |
| **Counterpart** | `reviews/B_aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` |
| **System** | heartbeat / creature facing |
| **Evidence pass** | Live `decompile_function` + `read_memory` + xrefs; sealed slew `004c7bd0`; sibling ctor W28-K |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual OnHeartBeat for secondary SlewFacingYaw HB (`vtbl 009daee8+0x0C`): if owner attached, re-slew **raw owner** by pulse period ms; always reschedule list delay; return `pOutStatus`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d6c10_FUN_005d6c10.md` (+ W30-T append) |
| Annotated | `docs/reconstruction/raw/aa_005d6c10_FUN_005d6c10.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d6c10.cpp` |
| Function | `docs/reconstruction/functions/aa_005d6c10_CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred.md` |
| Sealed slew | `CVOGCreature_SlewFacingYaw_Inferred` (`aa_004c7bd0`) |
| Sibling ctor | `CVOGHB_SlewFacingYaw_ctor_Inferred` (`aa_005d6b80`) |
| Vtbl | `read_memory` `009daee8` → slot +0x0C = `005d6c10` |

---

## 3. Signature

```c
// Ghidra residual: __fastcall + EDX garbage; bytes: thiscall RET 4
uint32_t *__thiscall CVOGHB_SlewFacingYaw_OnHeartBeat_Inferred(
    void *self, uint32_t *pOutStatus);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=HB | `56 8B F1` | **High** |
| stack pOutStatus; RET 4 | `8B 7C 24 0C` … `C2 04 00` | **High** |
| returns pOutStatus | `8B C7` before epilogue | **High** |
| No true EDX formal | no EDX load for schedule arg | **High** |

---

## 4. Control flow (sealed)

1. If `*(self+0x18) != 0` (pOwnerObject):
   - `CVOGCreature_SlewFacingYaw_Inferred(*(self+0x24), *(self+0x08))` — **ECX=raw owner**
2. `CVOGHBBase_RescheduleAfterFire(self, pOutStatus)`
3. return `pOutStatus`

| Stage | Match | Conf |
|---|---|---|
| Owner gate +0x18 | **Yes** | **High** |
| Slew ECX raw +0x24 | **Yes** (bytes) | **High** |
| Period arg +0x08 | **Yes** | **High** |
| Reschedule + return out ptr | **Yes** | **High** |
| Vtbl +0x0C sole xref | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr role | Bytes / note |
|---|---|
| prolog | `56 8B F1 83 7E 18 00 57` |
| slew setup | `8B 46 08 8B 4E 24 50 E8 …` → period + ECX raw + call `004c7bd0` |
| reschedule | `8B 7C 24 0C 57 8B CE E8 …` → `00508350` |
| epilogue | `8B C7 5F 5E C2 04 00` |
| pad | `CC` @ `005d6c38+` |

---

## 6. Gaps / open

1. Product/PDB English for class `009daee8`.
2. Runtime / bit-exact — open.

---

## 7. Verdict

CF/ABI/vtbl/slew this-arg sealed; product class English residual → **accept-with-gaps**.
