# Review B (skeptical / adversarial): `aa_004447e0` Palantir_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004447e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-J) |
| **Counterpart** | `reviews/A_aa_004447e0_Palantir_ScalarDeletingDtor.md` |
| **Scratch** | `tmp/a_004447e0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This body is the complete dtor (tears down members) | **Falsified** — only calls `FUN_00754320` then optional free |
| 2 | Always frees `this` | **Falsified** — free only when `flags&1` |
| 3 | Never frees `this` | **Falsified** — free path present |
| 4 | Bare RET / no stack cleanup | **Falsified** — `RET 4` for flags formal |
| 5 | Not on Palantir vtbl | **Falsified** — `*(0x00a9f76c) == 0x004447e0` |
| 6 | Complete dtor is cdecl with stack this | **Falsified** — thiscall via ECX (ESI=ECX before CALL; complete uses ESI/ECX) |
| 7 | `operator_delete` noreturn ends function | **Falsified** — false warning; returns this after |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar deleting ABI | **High** | double-free / leak |
| Complete dtor handoff | **High** | incomplete teardown |
| Product class Palantir | **High** | wrong subsystem |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + vtbl

```
// FUN_004447e0 (30 B)
ESI=ECX
CALL Palantir_CompleteDtor   // 0x00754320
if (flags&1) operator_delete(ESI)
return ESI; RET 4

// vtbl PTR_FUN_00a9f76c
[0] = 0x004447e0   // this unit
[1] = 0x00754480   // Palantir::ResetDevice (W34-K product string)
```

W34-K already documented this wrapper as the free-this path outside the complete body.

---

## 4. Surviving contract for AutoCore

```
// Port as scalar deleting dtor only:
void* Palantir_ScalarDeletingDtor(Palantir* self, unsigned char flags) {
  Palantir_CompleteDtor(self);
  if (flags & 1) operator_delete(self);
  return self;
}
// Do not put member teardown here.
// Do not free inside Palantir_CompleteDtor.
// flags&1 is the only heap-free gate for the host object.
```

---

## 5. Verdict

Adversarial pass confirms A on every structural claim; residual gaps are naming/runtime only → **accept**.
