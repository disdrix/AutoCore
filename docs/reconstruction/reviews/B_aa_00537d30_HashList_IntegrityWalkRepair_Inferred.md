# Review B (skeptical / adversarial): `aa_00537d30` HashList_IntegrityWalkRepair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d30` |
| **VA** | `0x00537d30` |
| **Canonical name** | `HashList_IntegrityWalkRepair_Inferred` (Ghidra `FUN_00537d30`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00537d30_HashList_IntegrityWalkRepair_Inferred.md` |
| **System** | container / hash-list integrity |
| **Live tools** | Independent `force_decompile` + `read_memory` + string dump + multi-caller sample (`004e2ca0`, `0053c460`, `0053c760`) |
| **Verdict** | **accept-with-gaps** — accept A's CF; reject “optional debug” / “frees nodes” / “is CNDHash_Insert” |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Debug-only / stripped in retail | **Falsified** — unconditional from insert/unlink hot paths; string in image |
| 2 | Frees cyclic nodes | **Falsified** — only severs next link + clears marks |
| 3 | Same function as scalar dtor `00537d10` | **Falsified** — different entry; integrity walk |
| 4 | Walks CNDHash global list (`+0x14/+0x18`) | **Falsified** — only `list+4` / `node+0xC` chain (bucket/free-list shape) |
| 5 | Compares keys | **Falsified** — no key load |
| 6 | `FUN_007a4480(0, …)` like other stops | **Falsified** — severity **1** here |
| 7 | Mission-only | **Falsified** — 30+ callers across domains |
| 8 | Decompiler `__fastcall` vs thiscall | **Cosmetic** — single ECX arg; MSVC thiscall-compatible |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Mark/next offsets | **High** | Silent corruption on port |
| Sever on re-touch | **High** | Infinite loop if wrong |
| No free in unit | **High** | Double-free if port frees |
| Multi-domain | **High** | Wrong subsystem ownership |
| Product name | **None** | — |

---

## 3. Decompiler pitfalls

1. `FUN_00537d30()` at call sites printed with zero args — ECX must carry list/bucket.
2. Scaffold alias `Named_CalleeOf_CVOGReaction_CompleteObjective_*` is **one** caller, not exclusive identity.
3. Mark byte shares offset with CNDHash node touch field written zero at insert — consistent.

---

## 4. CF challenge of Review A

- Force ≡ raw: **agree**
- String + sever + multi-xref: **agree High**
- leave-FUN / accept-with-gaps: **agree** (prefer retain `FUN_` in plates until RTTI)

**Verdict:** **accept-with-gaps**
