# Review B (skeptical / adversarial): `aa_006297e0` Phys_CommitPairListStorage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006297e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-M) |
| **Counterpart** | `reviews/A_aa_006297e0_Phys_CommitPairListStorage_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/layout; **needs-more-evidence** on product English + list payload types |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Spawn-point only (prior Named_CalleeOf_CVOGSpawnPoint) | **Falsified** — callers BindLinks/UnbindLinks/00629d90 |
| 2 | Always mutates storage | **Falsified** — early return both counts 0 |
| 3 | ret 4 / cdecl | **Falsified** — C2 10 00 ret 0x10 thiscall |
| 4 | Pair stride 8 | **Falsified** — 4 dwords; count<<4 |
| 5 | Free always runs | **Falsified** — only when capacity signed >= 0 |
| 6 | local_14 is heap | **Overstated** — stack temp |
| 7 | Product name retail | **Overstated** — _Inferred only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 0x10 / thiscall | **High** | Convention break |
| Gate on counts | **High** | Spurious work / skip |
| +0x68/+0x6c/+0x70 | **High** | Corrupt pairs |
| Allocator tag 0x12 | **High** | Wrong arena |
| BindLinks payload types | **Medium** | Wrong attach |
| Product English | **Tentative** | Docs only |

---

## 3. Cross-check

Live 2026-07-29 equiv raw 2026-07-23 CF. Clean preserves spine with uint32_t (no bare undefined4).

---

## 4. Surviving contract

```
if (listA_count != 0 || listB_count != 0)
  merge lists into host pair storage (stride 16), grow with tag 0x12
```

---

## 5. Residual

- Product class name / PDB.
- Shared layout proof manager vs subIsland.
- Nested 006caaa0 / 006cad30.

**Verdict:** **accept** (CF/ABI/layout sealed).
