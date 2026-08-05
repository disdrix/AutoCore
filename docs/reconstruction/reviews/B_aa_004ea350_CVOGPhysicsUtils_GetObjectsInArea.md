# Review B (skeptical / adversarial): `aa_004ea350` CVOGPhysicsUtils_GetObjectsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ea350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` |
| **Verdict** | **accept** on product name + AABB default; **accept-with-gaps** on mode-1/2 English + return ABI |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Name only from VOG_DEBUG_STOP | **Falsified** — primary name from `GetObjectsInArea::aabb` string xref `004ea38f` |
| 2 | Single query shape only | **Falsified** — mode 1, mode 2, and default AABB |
| 3 | Mode integer == gather mode | **Falsified** — gather maps gatherMode → **filter flags** (last arg); mode path often 0/default |
| 4 | Does pair relationship filter | **Falsified** — that is `FUN_0058a810`; this only broadphase collects |
| 5 | Always returns success list | **Overstated** — debug-stop path returns 0; decomp delete paths muddy other exits |
| 6 | `param_3` is always sphere radius | **Overstated for mode≠2** — default uses it as AABB half-extent on each axis |
| 7 | AI FindTarget uses same flags as skill mode 2 | **Unproven** — AI passes mode `0` + own flag word; not gather's `0x11` ladder |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product name | **Confirmed** | — |
| AABB default CF | **High** | Wrong broadphase shape |
| Mode 1/2 existence | **High** | Miss alternate query |
| Mode 1/2 English | **Inferred** | Doc only |
| Filter flags last arg | **High** | Wrong gather hits |
| Exact return type | Partial | Caller misuse |
| List node layout | Partial | Mild |

---

## 3. Surviving contract

```
GetObjectsInArea(ctx, center, extent, queryCtx, mode, filterFlags)
  -> collects objects in region under filterFlags
  mode 1 / 2: alternate builders
  else: AABB center±extent; profile aabb; optional VOG_DEBUG_STOP
Consumers post-filter with domain logic (Gather pair filter, AI attack gates).
```

---

## 4. Residual uncertainty

| # | Item | Blocks name seal? |
|---|---|---|
| R1 | Mode 1/2 product names | No |
| R2 | Return ABI on success | Mild for port |
| R3 | `FUN_006c6c50` flag bits | No for role |
| R4 | Decomp non-returning delete | No (SEH noise) |

---

## 5. Concrete checks

1. String xref into default path. **Pass**
2. Mode branches 1 / 2 / else in decompile. **Pass**
3. Callers Gather + AI. **Pass**
4. Gather residual flag ladder cross-link. **Pass**

---

## 6. Verdict

**accept** on **CVOGPhysicsUtils::GetObjectsInArea** + AABB default broadphase; **accept-with-gaps** for mode-1/2 naming and exact success return packaging.
