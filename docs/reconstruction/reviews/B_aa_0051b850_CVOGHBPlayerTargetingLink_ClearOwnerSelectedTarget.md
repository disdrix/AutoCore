# Review B (skeptical / adversarial): `aa_0051b850` CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b850` |
| **VA** | `0x0051b850` |
| **Canonical name** | `CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget` (**Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| **System** | `heartbeat` / targeting link |
| **Live tools** | Independent `read_memory` + decompile after create + vtbl / SetSelectedTarget duals |
| **Verdict** | **accept-with-gaps** — accept CF; reject overclaim of product slot name / sole call path |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is the scalar dtor | **Falsified** — no delete; only clears `owner+0xA0` |
| 2 | Writes `this+0xA0` | **Falsified** — writes **`*(this+0x18)+0xA0`** (owner field) |
| 3 | Base also clears selected target | **Falsified** — base slot 7 is empty `FUN_0056f570` |
| 4 | Product name proven | **Not proven** — role inferred from field identity only |
| 5 | Always nulls target even if owner null | **Falsified** — early-out when `+0x18 == 0` |
| 6 | Has stack args | **Falsified** — bare `ret`; thiscall ECX only |
| 7 | Same as OnHeartBeat `0x00604dd0` | **Falsified** — different VA / slot / body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level CF | **High** | Wrong field clear |
| Owner at `+0x18` | **High** | Crash / wrong object |
| Selected target at owner `+0xA0` | **High** | Leaves stale target after link teardown |
| Derived-only override | **High** | Expect base to clear (it does not) |
| Virtual English name | **Tentative** | Registry polish |
| When slot 7 is invoked | **Probable / open** | Miss a call path |

---

## 3. Why base is nop

Target-side HB (base vtbl) must **not** zero the selector's `+0xA0` — that field lives on the **selecting** entity. Only the self-side `CVOGHBPlayerTargetingLink` owns the “clear my selected target” side effect. **Agree** with A’s asymmetry claim.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| 18-byte null-owner-selected-target clear | Product OnXxx name without PDB |
| Derived vtbl slot 7 only | Exhaustive dispatch catalog |
| Field identity via SetSelectedTarget dual | Side effects beyond the store |

---

## 5. CF challenge of Review A

- Bytes / decompile identity: **agree High**
- Inferred name + gaps: **agree**
- Not dtor / not OnHeartBeat: **agree**

**Verdict:** **accept-with-gaps**
