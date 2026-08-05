# Review B (skeptical / adversarial): `aa_00537550` CNDHashNode_ValueOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537550` |
| **VA** | `0x00537550` |
| **Canonical name** | `CNDHashNode_ValueOwning_scalar_dtor_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00537550_CNDHashNode_ValueOwning_scalar_dtor_Inferred.md` |
| **System** | container / CNDHash |
| **Live tools** | Independent `force_decompile` + `read_memory` + vtbl/insert cross-check vs `0x00537d10` |
| **Verdict** | **accept-with-gaps** — accept owning CF; reject “no free” / “mission-only class” overclaims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same as `FUN_00537d10` | **Falsified** — this unit **deletes `this+8`**; sibling does not |
| 2 | Does not free payload | **Falsified** — `operator_delete([this+8])` before clear |
| 3 | Direct call sites (code xrefs) | **Falsified as primary** — method is vtbl[0]; static use is DATA/vtbl install |
| 4 | Ghidra “Subroutine does not return” on `operator_delete` | **Noise** — MSVC delete returns; CF continues |
| 5 | Mission-exclusive type | **Over-narrow** — any hash stamping `009cefec` shares this dtor |
| 6 | Also runs hash unlink | **Falsified** — body is pure dtor; unlink is caller-side |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar dtor shape + `ret 4` | **High** | Wrong ABI on vcall |
| Owns value at `+8` | **High** | Leak or double-free in port |
| Twin of non-owning `00537d10` | **High** | Wrong family teardown |
| Product name | **None** | Registry pollution |

---

## 3. CF challenge of Review A

- Force ≡ raw: **agree**
- Ownership distinction vs `00537d10`: **agree High**
- accept-with-gaps: **agree**

**Verdict:** **accept-with-gaps**
