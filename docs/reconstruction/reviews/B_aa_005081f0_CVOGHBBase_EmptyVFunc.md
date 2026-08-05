# Review B (skeptical / adversarial): `aa_005081f0` CVOGHBBase_EmptyVFunc

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-A) |
| **Counterpart** | `reviews/A_aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| **Verdict** | **accept** (trivial CF; residual is naming/catalog only) |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Body does real cleanup / detach / free | **Falsified** — sole byte `c3` |
| 2 | Domain-specific OKToCastAgain-only helper (parent-seed) | **Falsified as sole role** — base vtbl DATA + multi-caller tails |
| 3 | Same unit as mass `EmptyRet` `0x0056f570` | **Falsified** — different VA |
| 4 | Same unit as neighbor empty `0x005081e0` | **Falsified** — different VA (Stop’s +0x10 default) |
| 5 | `__stdcall` / `ret 4` ABI | **Falsified** — bare `c3` |
| 6 | Returns meaningful EAX | **Unfounded** — no `mov eax` |
| 7 | Clean should invent OnEnd side effects because slot used as OnEnd | **Falsified** — base default is empty; overrides are other VAs |
| 8 | “Stop/detach” product body lives here | **Falsified** — Stop is `0x005081d0`; this is nop leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Pure nop body | **High** | inventing teardown breaks HB defaults / OnEnd tails |
| Bare `ret` | **High** | wrong port ABI |
| Shared leaf (not one caller) | **High** | wrong ownership / wrong system tag |
| Distinct from 0056f570 / 005081e0 | **High** | alias collapse |

---

## 3. Cross-check against raw + bytes

```
CVOGHBBase_EmptyVFunc:
  ret    ; c3
```

Any clean plate with branches, stores, list ops, or cast-flag work is **wrong** for this VA (that work is in **callers** such as OKToCastAgain_OnEnd).

Parent-seed alias is **auto-rename debt** — keep as alias only.

---

## 4. Surviving contract for AutoCore

```c
// Port: empty leaf (do not special-case by caller domain)
void CVOGHBBase_EmptyVFunc(void) { /* no-op */ }

// Base HB vtbl+0x14 may point here.
// Subclass OnEnd overrides are separate VAs; some tail-jmp here after real work.
// Do not implement Stop/Dequeue/free at this address.
```

---

## 5. Open questions

1. PDB / CRT symbol string.
2. Whether ports collapse all empty HB slots to one shared nop (optional).

**Verdict:** **accept**
