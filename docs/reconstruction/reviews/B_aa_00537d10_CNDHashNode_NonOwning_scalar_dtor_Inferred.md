# Review B (skeptical / adversarial): `aa_00537d10` CNDHashNode_NonOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d10` |
| **VA** | `0x00537d10` |
| **Canonical name** | `CNDHashNode_NonOwning_scalar_dtor_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.md` |
| **System** | container / CNDHash |
| **Live tools** | Independent `force_decompile` + `read_memory` + twin `00537550` + insert `0053c460` |
| **Verdict** | **accept-with-gaps** — accept non-owning CF; reject “missing body” / “same as value-owning” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Address is not a function / data only | **Falsified** — valid 28 B prologue; was simply not created in Ghidra until this dual |
| 2 | Identical to `00537550` | **Falsified** — no `+8` free path |
| 3 | Frees definition objects | **Falsified** — would UAF mission defs if it did; body has no value delete |
| 4 | Part of `FUN_00537d30` | **Falsified** — separate entry; int3 pad; different CF |
| 5 | `009cf02c` region is only a string (“Target: %d…”) | **Partial misread** — dword0 is this dtor; adjacent ASCII is **following rodata**, not vtbl methods |
| 6 | Mission-only | **Over-narrow** — multiple insert sites stamp this vtbl |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar dtor + non-owning | **High** | Double-free defs if port frees value |
| Vtbl slot 0 | **High** | Wrong teardown dispatch |
| Separation from integrity `00537d30` | **High** | Confused dual coverage |
| Product name | **None** | — |

---

## 3. CF challenge of Review A

- Body size 28 B + `ret 4`: **agree**
- Non-owning vs `00537550`: **agree High**
- accept-with-gaps: **agree**

**Verdict:** **accept-with-gaps**
