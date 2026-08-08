# Review B (skeptical / adversarial): `aa_00416350` Class_00a7000c_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9I-H) |
| **Counterpart** | `reviews/A_aa_00416350_Class_00a7000c_ScalarDeletingDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete dtor | **Falsified** — calls `FUN_00832fa0`; has flags; may `operator_delete(this)`; RET 4 |
| 2 | Vector-deleting (array) | **Falsified** — tests bit0 only; no element count / loop |
| 3 | Always frees this | **Falsified** — free gated on `flags & 1` |
| 4 | Installs vtbl here | **Falsified** — vtbl install is in complete `FUN_00832fa0` |
| 5 | operator_delete never returns | **Falsified** — decompiler WARNING wrong; epilogue returns this |
| 6 | Product class name sealed | **Careful** — structural from vtbl address only → `_Inferred` |
| 7 | No return value | **Falsified** — `MOV EAX,ESI` returns this |
| 8 | Same as peer scalars at 004160d0/004160f0 | **Shape yes, identity no** — different complete callee / vtbl |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar vs complete | **High** | Leak / double free |
| flags bit0 gate | **High** | Wrong free policy |
| RET 4 / return this | **High** | ABI break |
| vtbl[0] binding | **High** | Wrong type identity |
| Product plate | **Low** | Naming only |
| Complete member map | **Open** | Residual under 00832fa0 |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Complete FUN_00832fa0:
//   *this = PTR_FUN_00a7000c; free this[0x122]; FUN_007b5be0(); no delete this
// This FUN_00416350:
//   FUN_00832fa0; if (flags&1) delete; return this; RET 4
// Vtbl 00a7000c[0]=00416350  (read_memory sealed)
// Xrefs: DATA only
```

Live decompile 2026-08-05 ≡ scaffold 2026-07-23; 30 B hex seals CF. Peer pattern matches `Class_009c7948_ScalarDeletingDtor` family.

---

## 4. Surviving contract for AutoCore

```
// Port as scalar-deleting dtor only:
void* Class_00a7000c_ScalarDeletingDtor(Host* self, uint8_t flags) {
  CompleteDtor_00a7000c(self); // FUN_00832fa0
  if (flags & 1) operator_delete(self);
  return self;
}
// Do not invent vector-deleting or extra member teardown in this body.
// Do not treat decompiler "noreturn" on operator_delete as real.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl[0]/complete-then-free. Residual product + complete dual → **accept-with-gaps**.
