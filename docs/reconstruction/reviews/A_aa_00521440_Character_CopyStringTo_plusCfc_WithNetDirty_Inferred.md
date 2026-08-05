# Review A (reconstruction fidelity): `aa_00521440` Character_CopyStringTo_plusCfc_WithNetDirty_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521440` |
| **VA** | `0x00521440` |
| **Canonical name** | `Character_CopyStringTo_plusCfc_WithNetDirty_Inferred` (Ghidra `FUN_00521440`) |
| **Plate alias** | `Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_00521440` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00521440_Character_CopyStringTo_plusCfc_WithNetDirty_Inferred.md` |
| **System** | character identity / ghost net |
| **Evidence pass** | Live `batch_decompile` (byte-copy loop → `this+0xcfc`; mask `0x20000000`); callers UnpackGhost / reconcile / UI helper |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Null-terminated string copy** from caller buffer into character field buffer starting at **`this+0xcfc`**, then dirty character NetObject with mask **`0x20000000`**.

Decompiler form is classic MSVC byte strcpy rewrite:

```
delta = (this + 0xcfc) - src
do { c = *src; src[delta] = c; src++; } while (c != 0);
```

No length clamp visible in this body (caller-owned buffer size residual). No local dirty bit at `+0x634` (contrast sibling dword setters `0x00521480` / `0x005214b0`).

**Callers:** `VehicleNet_UnpackGhostVehicle`, `VehicleNet_ReconcilePrediction`, `FUN_0060a820`, `FUN_00808b50`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00521440_FUN_00521440.md` |
| Annotated | `docs/reconstruction/raw/aa_00521440_FUN_00521440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00521440.cpp` |
| Function record | `docs/reconstruction/functions/aa_00521440_FUN_00521440.md` |

**Three-rep:** present.

---

## 3. Signature

```c
// __thiscall  ECX = character*
// stack: char *src  (ret 4)
void Character_CopyStringTo_plusCfc_WithNetDirty(void *self, const char *src);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| src | stack ptr | **High** |
| dest base | `this+0xcfc` | **High** |
| mask | `0x20000000` | **High** |
| buffer capacity | unknown | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| strcpy-style loop incl. NUL | **Yes** | **High** |
| Net dirty after copy | **Yes** | **High** |
| No change-detect skip | **Yes** | **High** (always copies + may dirty) |
| No `+0x634` bit | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Dest `+0xcfc` C-string | **High** | decomp |
| Net mask `0x20000000` | **High** | same family as `0x00521480`/`0x005214b0` |
| Display/name-like identity field | **Probable** | adjacent `+0xcf4`/`+0xcf8` dword pair; ghost identity cluster |
| Exact product field name | **Open** | residual |
| Max length / overflow safety | **Open** | no clamp in body |

---

## 6. Gaps

1. Buffer size at `+0xcfc` (scan for fixed array length / packet max).
2. Confirm pack twin field and mask bit meaning (not vehicle HeatMask — different object type).
3. Whether empty-string / identical-string still dirties (yes on current CF).

**Verdict:** **accept-with-gaps**
