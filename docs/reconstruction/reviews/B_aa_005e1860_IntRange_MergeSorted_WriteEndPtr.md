# Review B (skeptical / adversarial): `aa_005e1860` IntRange_MergeSorted_WriteEndPtr

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — W16-D) |
| **Counterpart** | `reviews/A_aa_005e1860_IntRange_MergeSorted_WriteEndPtr.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always a pure memcpy (never merges) | Body has dual-cursor `<` merge when A non-empty | **Falsified** as “always memcpy”; **survives** as sole-caller usage |
| 2 | Returns end in EAX | Epilogue writes `*pOutEndSlot`; EAX holds slot address | **Falsified** EAX-return |
| 3 | `__stdcall` / `ret 0x18` | Bare `C3` | **Falsified** stdcall |
| 4 | Unsigned compare | Signed `int` `<` in decompile + load as dwords compared signed | **Falsified** unsigned |
| 5 | Mutates catalog tables in place | Read-only sources; writes only through `out` | **Falsified** in-place mutate |
| 6 | Same as `005e07d0` fill | Different VA; this is leaf merge only | **Falsified** merge |
| 7 | Scaffold Named_CalleeOf is product name | No strings; role from CF + sole caller | **Falsified** product name |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Merge CF + end-slot write | **Confirmed** | Corrupt out-vector end → loot roll empty/overflow |
| cdecl bare ret | **Confirmed** | Stack imbalance |
| Sole caller empty-A copy | **Confirmed** | Misread as always needing sorted inputs |
| Product CRT name | Residual | Naming only |
| Out-buffer capacity (caller `00410420`) | Out of unit | OOB if prep wrong — owned by `005e0cd0` |

---

## 3. Live ≡ raw

```
Live decompile ≡ raw aa_005e1860 (2026-07-23 body + 2026-07-29 reconfirm).
Epilogue: *pOutEndSlot = out; ret.
No SEH; no globals; no callees.
```

---

## 4. Surviving contract for AutoCore

```
// Leaf helper used by quality/type band fill:
void IntRange_MergeSorted_WriteEndPtr(
    int32_t **pOutEndSlot,
    int32_t *beginA, int32_t *endA,
    int32_t *beginB, int32_t *endB,
    int32_t *out);
// *pOutEndSlot receives advanced out.
// When beginA==endA: copies [beginB,endB) to out (loot catalog path).
// When both non-empty: std::merge-style sorted int merge (ties → A).

// AutoCore:
//  - Port as merge OR as specialized copy if only empty-A path is needed.
//  - Do not invent RNG/pick here; pick lives in 005e1150 / 005e1030.
```

Pair with:

- `LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` `0x005e0cd0`
- `LootCatalog_RollFilteredCandidateId_Inferred` `0x005e1150`

---

## 5. Open questions (residual only)

1. CRT mangled name.
2. Whether retail ever ships a second caller with dual non-empty ranges.

**Verdict:** **accept**. No CF blockers. Scaffold “unknown system” closed to inventory/loot helper.
