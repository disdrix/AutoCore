# Review A (reconstruction fidelity): `aa_005e1150` LootCatalog_RollFilteredCandidateId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1150` |
| **VA** | `0x005e1150` |
| **Canonical name (Ghidra)** | `FUN_005e1150` |
| **Proposed name** | `LootCatalog_RollFilteredCandidateId_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispa_005e1150` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005e1150_LootCatalog_RollFilteredCandidateId_Inferred.md` |
| **System** | `inventory` / loot generation (filtered roll) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Fill a candidate ID vector, remove excluded / invalid entries, then randomly pick one ID** (or fail).

Sibling of `FUN_005e1030` with an extra **filter pass** before the pick:

1. SEH `LAB_009a748a`; empty vector locals.
2. `FUN_005e0cd0(param_1..param_4, &local_vector, 0xffffffff)` — **alternate fill** path (quality/type indexed tables inside catalog; uses `FUN_005e0590` random band bias + `FUN_005e1860` range copy).
3. If `local_18 == NULL` → `return 0xffffffff`.
4. If vector non-empty, walk each dword ID:
   - **Exclusion list** (`param_5`): if non-null, scan `param_5→[begin,end)` (`+4`/`+8` vector); match ⇒ remove via `memmove` compact.
   - **Invalid-prefix / unusable gate** when `param_6 != 0`:
     - `FUN_004ce940()` non-zero **and**
     - `FUN_005097b0(id)` null **or** `*entry == -1`
     - ⇒ remove ID.
   - Else advance cursor.
5. If remaining count non-zero: `CVOGReaction_RandomUnitScalar` + `FUN_007a41f0` pick; free buffer.
6. Empty after filter → free; fail.

Caller `FUN_00509b10` (affix/mod apply path): builds an owned-id exclusion vector from object hardpoints, gets catalog via `005e0580`, calls this, then applies selected id via `vtbl+0x54`.

**Not** unfiltered `005e1030`, not filler-only `005e0cd0` / `005e07d0`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x005e1150` |
| Fill callee | live `FUN_005e0cd0` |
| Prefix helper | dual/context `A_aa_005097b0_CVOGLootGenerator_GetTypeFromIDPrefix_*` |
| Caller | `get_function_callers` → `00509b10` only (primary) |
| Sibling roll | `A_aa_005e1030_*` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005e1150` |
| Function record | `docs/reconstruction/functions/aa_005e1150_FUN_005e1150.md` |

**This pass:** live decompile; callers; fill/filter callees. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// param_1 is catalog / table host (same object 005e0580 returns; may be thiscall lost)
int LootCatalog_RollFilteredCandidateId_Inferred(
    void *catalog,           // param_1 → passed as this into 005e0cd0
    int   band_or_key,       // param_2
    int   quality_or_a,      // param_3
    int   quality_or_b,      // param_4
    int  *exclude_vec,       // param_5 — optional std::vector-like {?, begin@+4, end@+8}
    char  filter_invalid);   // param_6 — enable prefix/invalid strip
// returns: selected id, or 0xffffffff
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_005e0cd0` | Fill candidates from catalog type/quality tables |
| `FUN_004ce940` | Gate for invalid-prefix filter path |
| `FUN_005097b0` | Lookup type-from-id-prefix; `-1` / null ⇒ strip |
| `memmove` | Compact vector on erase |
| `CVOGReaction_RandomUnitScalar` / `FUN_007a41f0` | Pick remaining |
| `operator_delete` | Free buffer (SEH noreturn noise) |

| Caller | Role |
|---|---|
| `FUN_00509b10` | Build exclude list from equipped slots; roll; apply |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `005e0cd0` fill with `0xffffffff` sentinel arg | Yes |
| Null vector → `-1` | Yes |
| Exclusion list scan + memmove erase | Yes |
| Optional invalid-prefix strip (`param_6`) | Yes |
| Non-empty remaining → random pick | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Filtered loot ID roll | **High** | CF + caller |
| Exclusion via `param_5` dword vector | **High** | explicit compare loop |
| `param_6` enables invalid-prefix filter | **High** | |
| `005e0cd0` is fill, not pick | **High** | live body |
| Distinct from `005e1030` | **High** | different fill + filter |
| Exact product name / formal names | **Tentative** | |
| `004ce940` semantic | **Probable** | non-zero enables strip branch |

---

## 7. Gaps / open

1. Product names of catalog tables and of `004ce940`.
2. Full formal map of `param_2..4` (band/quality) — residual in `005e0cd0`.
3. Clean return of selected ID through SEH-polluted tail.
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — filter+roll CF High; formal naming open.
