# Review B (skeptical / adversarial): `aa_007fbd30` UiProgressBar_BindFromRanges (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fbd30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fbd30_UiProgressBar_BindFromRanges_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory grid place helper | Pure UI vcalls; no COID/grid | **Falsified** |
| 2 | Portable 2-arg cdecl | EAX/ESI/EDI registers | **Falsified as portable** |
| 3 | Single formula only | Three distinct branches | **Falsified** |
| 4 | Skips refresh when empty | Tail `+0x34c` always | **Falsified** |
| 5 | Inventory-only | 15 multi-dialog xrefs | **Survives as shared UI** — AddItem is one consumer |
| 6 | Vtbl English sealed | Offsets only | **Gap** |

---

## 2. Surviving contract

```
// EAX=source, ESI=dest, EDI=float context
// read source 0x490/494/49c → write dest 0x460/454/d4 → dest 0x34c refresh
```

**Verdict:** CF **survives**. **accept-with-gaps.**
