# Review A (reconstruction fidelity): `aa_005214b0` Character_SetDword_plusCf8_Dirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005214b0` |
| **VA** | `0x005214b0` |
| **Canonical name** | `Character_SetDword_plusCf8_Dirty_Inferred` (Ghidra `FUN_005214b0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005214b0_Character_SetDword_plusCf8_Dirty_Inferred.md` |
| **System** | character identity / mission-dirty family |
| **Evidence pass** | Live `batch_decompile` (OR `+0x634\|=1`; store `+0xcf8`; mask `0x20000000`); twin of `0x00521480` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Set character dword **`this+0xcf8`**, local dirty **`this+0x634 |= 1`**, and net dirty character NetObject with **`0x20000000`**.

Exact twin of `0x00521480` (`+0xcf4`); same dirty/mask pattern. Adjacent to string buffer `+0xcfc`.

**Callers:** `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005214b0_FUN_005214b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005214b0_FUN_005214b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005214b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005214b0_FUN_005214b0.md` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = character*
// stack: uint32_t value  (ret 4)
void Character_SetDword_plusCf8_Dirty(void *self, uint32_t value);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| value | stack dword | **High** |
| field | `this+0xcf8` | **High** |
| local dirty | `this+0x634 \|= 1` | **High** |
| net mask | `0x20000000` | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| `+0x634 \|= 1` then store `+0xcf8` | **Yes** | **High** |
| Conditional net dirty | **Yes** | **High** |
| Twin of `0x00521480` (only dest offset differs) | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Store `+0xcf8` | **High** | decomp |
| Same dirty/mask as `0x00521480` | **High** | structural twin |
| Semantic meaning | **Open** | residual pair with `+0xcf4` |

---

## 6. Gaps

1. Product meaning of `+0xcf8` vs `+0xcf4`.
2. Wire order in unpack relative to string `+0xcfc`.
3. Readers of bit 0 at `+0x634`.

**Verdict:** **accept-with-gaps**
