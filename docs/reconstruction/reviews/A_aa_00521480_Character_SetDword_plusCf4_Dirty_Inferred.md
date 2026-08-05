# Review A (reconstruction fidelity): `aa_00521480` Character_SetDword_plusCf4_Dirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521480` |
| **VA** | `0x00521480` |
| **Canonical name** | `Character_SetDword_plusCf4_Dirty_Inferred` (Ghidra `FUN_00521480`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00521480_Character_SetDword_plusCf4_Dirty_Inferred.md` |
| **System** | character identity / mission-dirty family |
| **Evidence pass** | Live `batch_decompile` + `read_memory` (`or dword [ecx+0x634],1`; store `[ecx+0xcf4]`; mask `0x20000000`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set character dword **`this+0xcf4`**, local dirty **`this+0x634 |= 1`**, and net dirty character NetObject with **`0x20000000`**.

Twin of `0x005214b0` (`+0xcf8`). Sits next to string buffer at `+0xcfc` (`0x00521440`). Always writes (no change-detect).

**Callers:** `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00521480_FUN_00521480.md` |
| Annotated | `docs/reconstruction/raw/aa_00521480_FUN_00521480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00521480.cpp` |
| Function record | `docs/reconstruction/functions/aa_00521480_FUN_00521480.md` |
| Live | `8B 44 24 04  83 89 34 06 00 00 01  …  89 81 F4 0C 00 00  …  push 0; push 0x20000000; call` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = character*
// stack: uint32_t value  (ret 4)
void Character_SetDword_plusCf4_Dirty(void *self, uint32_t value);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| value | stack dword | **High** |
| field | `this+0xcf4` | **High** |
| local dirty | `this+0x634 \|= 1` | **High** (`charMissionDirtyFlags` family bit 0) |
| net mask | `0x20000000` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| `+0x634 \|= 1` then store `+0xcf4` | **Yes** | **High** |
| Conditional net dirty | **Yes** | **High** |
| No change-detect | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store `+0xcf4` | **High** | bytes `F4 0C 00 00` |
| Local dirty bit 0 at `+0x634` | **High** | `or dword, 1` |
| Net mask `0x20000000` | **High** | |
| Semantic meaning of dword | **Open** | identity/id residual |
| Bit 0 of `+0x634` shared with mission family | **Probable** | NAMING `charMissionDirtyFlags` notes multi-bit OR family |

---

## 6. Gaps

1. Product meaning of `+0xcf4` vs twin `+0xcf8`.
2. Readers of `+0x634` bit 0.
3. Pack twin / wire type for ghost path.

**Verdict:** **accept-with-gaps**
