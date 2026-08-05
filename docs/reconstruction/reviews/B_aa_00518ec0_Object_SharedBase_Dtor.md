# Review B (skeptical / adversarial): `aa_00518ec0` Object_SharedBase_Dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518ec0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-G) |
| **Counterpart** | `reviews/A_aa_00518ec0_Object_SharedBase_Dtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is scalar-deleting dtor | **Falsified** — no flags; no `operator_delete(this)`; bare RET; multi-type callers |
| 2 | Truncated by noreturn `operator_delete` | **Falsified** — fall-through zeros + final RET in 497 B body |
| 3 | Unrelated to Object_SharedBase_Ctor | **Falsified** — frees CS@`+0xb0`, FX@`+0x124`, owned slots ctor initializes; derived complete dtors chain here after SharedBase ctor path |
| 4 | Only called from one type | **Falsified** — 53 xrefs; many Unwind + complete dtors |
| 5 | Same as Class_009c7a1c dtor | **Falsified** — different layout; Class_009c7a1c is non-Object list class |
| 6 | Product type known | **Overstated** — role-sealed SharedBase only |
| 7 | `local = this & ~0xFF` is a bug | **Open/weak** — intentional predicate key packing; do not "fix" in port |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shared-base field dtor | **High** | Skip core teardown |
| ABI bare RET | **High** | Stack imbalance |
| operator_delete fall-through | **High** | Truncated port / leaks |
| Multi-caller base role | **High** | Wrong ownership |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against derived complete dtor

```
// FUN_00575350 Object_009d33c4_CompleteDtor (W28-M):
// ... free derived fields ...
// mov ecx, this; jmp FUN_00518ec0   // tail into SharedBase dtor
```

Confirms this VA is **base body**, not type-specific complete dtor.

---

## 4. Surviving contract for AutoCore

```
// Port as shared core dtor (ECX = core this, embedding-dependent):
Object_SharedBase_Dtor(core);
// Must run after derived complete-dtor field frees when chaining.
// Do not merge with Class_009c7a1c_CompleteDtor or scalar wrappers.
// Preserve CO-list safety log path; preserve delete fall-through zeros.
```

---

## 5. Verdict

Adversarial pass confirms A on role, ABI, multi-caller base chain, and false-noreturn handling. Product name residual → **accept-with-gaps**.
