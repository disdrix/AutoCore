# Review A (reconstruction fidelity): `aa_005e0480` LootCatalog_TypeCodeToRowIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0480` |
| **VA** | `0x005e0480` |
| **Canonical name (Ghidra)** | `FUN_005e0480` |
| **Proposed name** | `LootCatalog_TypeCodeToRowIndex_Inferred` (**High** role; product type names absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Mission_after_CVOGRegionMissions_005e0480` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W16-C) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_005e0480_LootCatalog_TypeCodeToRowIndex_Inferred.md` |
| **System** | `inventory` / loot catalog type-row axis |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Pure type-code → compact table-row remap** for loot catalog tables:

```c
// ret 4
int LootCatalog_TypeCodeToRowIndex_Inferred(int typeCode)
{
  switch (typeCode) {
  case 6:    return 0;
  case 8:    return 1;
  case 10:   return 2;
  case 0xc:  return 3;
  case 0xe:  return 4;
  case 0x10: return 5;
  case 0x1a: return 6;
  case 0x1c: return 7;
  case 0x32: return 9;   // non-monotonic pair with 0x34
  case 0x34: return 8;
  case 0x44: return 0xb; // non-monotonic pair with 0x46
  case 0x46: return 10;
  default:   return -1;  // 0xffffffff
  }
}
```

Consumers treat **−1** as “all subtypes” (walk 12 buckets in `005e07d0`) or skip typed paths. Mapped rows address a dense **0..11** axis (12 types).

**Not** a roll, not a filter, not a catalog walker.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005e0480` |
| Live bytes | `read_memory` @ `0x005e0480` len 160 — jump-table switch, `ret 4` |
| Callers | `get_function_callers` → `005e0610`, `005e07d0`, `005e0c50`, `005e0cd0` |
| Consumer duals | `A_aa_005e07d0_*`, `A_aa_005e0cd0_*` cite this helper |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_005e0480` |
| Function record | `docs/reconstruction/functions/aa_005e0480_FUN_005e0480.md` |

**This pass:** live decompile + memory + callers. **Not performed:** Launcher, runtime, bit-exact, parent ledger edits.

---

## 3. Signature

```c
// stdcall-ish stack cleanup; return EAX
uint32_t FUN_005e0480(uint32_t typeCode);  // 0..11 or 0xffffffff
```

---

## 4. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `LootCatalog_FillCandidateIds_Inferred` `0x005e07d0` | type row; −1 = all 12 subtypes |
| Caller | `LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` `0x005e0cd0` | `row * 0x32` band index term |
| Caller | `FUN_005e0610` | counters only when row ≥ 0 |
| Caller | `FUN_005e0c50` | gate when row ≥ 0 and short param `< 0x33` |
| Callee | *(none)* | pure |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| All 12 cases + default −1 | **Yes** |
| Non-monotonic 0x32/0x34 and 0x44/0x46 pairs | **Yes** |
| No side effects / no callees | **Yes** |
| Clean switch order matches raw (default early in decompile listing) | **Yes** |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Full map 12 codes → 0..11 else −1 | **High** | live ≡ raw |
| Role = catalog type-row index | **High** | four callers |
| Jump-table implementation (`add -6`, bound 0x40) | **High** | `read_memory` |
| Product names of type codes | **Tentative** | `_Inferred` |
| Why two pairs are swapped | **Open** | table content only |

---

## 7. Gaps / open

1. Retail names for type codes (weapon / armor / …) — no string at site.
2. Authoring reason for swapped 0x32↔0x34 and 0x44↔0x46 row order.

**Verdict:** **accept** — pure High-confidence remap; dual sealed.
