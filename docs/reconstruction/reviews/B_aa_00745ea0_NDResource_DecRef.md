# Review B (skeptical / adversarial): `aa_00745ea0` NDResource_DecRef

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745ea0` |
| **VA** | `0x00745ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00745ea0_NDResource_DecRef.md` |
| **Evidence** | Live decompile + full-body `read_memory` + 12 xrefs + sibling acquire dual |
| **Agent** | W21-N OWN-ONLY |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is full `Release` / destructor | No `operator_delete`, no `vtbl` call, no zeroing of `+0x8` | **Falsified full Release** |
| 2 | Decrements even when count is 0 | Branch `test [+0x10]; jbe skip` skips store | **Falsified underflow** |
| 3 | Always takes the critical section | Gated on `+0x38` / `[CS+0x18]` both sides | **Falsified always-lock** |
| 4 | Leave uses a different flag than Enter | `[ebx+0x18]` with `ebx=this+0x20` → `this+0x38` | **Falsified dual-flag** |
| 5 | Stack arg + `ret N` | Epilogue plain `C3`; `mov esi,ecx` only | **Falsified stdcall** |
| 6 | Same as AcquireInnerObject | Acquire increments + stamps time + returns inner; this only decrements status | **Falsified conflation** |
| 7 | Return value unused / void | EAX set from EDI (`0` or `-1`) at epilogue | **Falsified void** |
| 8 | Product name sealed by PDB | Role inferred from layout + sibling naming | **Accepted gap** (name is role-level) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Soft decref CF + return codes | **Confirmed** | Wrong ref lifetime in ports |
| ABI thiscall 0-arg | **Confirmed** | Stack smash |
| Shared shell layout with acquire | **Confirmed** | Offset mismatch vs `00745ee0` |
| Product English name | **Open** | Doc-only |
| Runtime | **Open** | — |

---

## 3. Cross-check vs sibling

`NDResource_AcquireInnerObject` owns pin + touch-time + null-inner `vtbl+8`. This unit owns **only** optional-locked refcount decrement + status. Do not merge destroy ownership into this dual.

---

## 4. Byte anchors

```text
0x00745ea0: 53 56 8B F1
            80 7E 38 00          ; flag this+0x38
            8D 5E 20             ; CS = this+0x20
            57 74 07 53 FF 15 BC 61 9C 00   ; Enter IAT
            8B 46 10 83 CF FF    ; refcount; result=-1
            85 C0 76 08
            83 C0 FF 89 46 10 33 FF         ; --count; result=0
            80 7B 18 00          ; flag CS+0x18
            74 07 53 FF 15 B8 61 9C 00      ; Leave IAT
            8B C7 5F 5E 5B C3
```

---

## 5. What would reverse the seal?

- Proof of a hidden free/vtbl path after return (would reclassify as full Release helper) — **not in body**.
- Proof that `+0x10` is not a refcount (e.g. ticket/generation only) — contradicted by acquire `add [+0x10],1` dual.

None observed from decompile + bytes + sibling dual + callers.
