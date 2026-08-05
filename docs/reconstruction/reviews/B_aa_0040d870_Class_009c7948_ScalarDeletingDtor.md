# Review B (skeptical / adversarial): `aa_0040d870` Class_009c7948_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d870` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-A) |
| **Counterpart** | `reviews/A_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` |
| **Scratch** | `tmp/a_0040d870.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the complete dtor | **Falsified** — calls `FUN_0040d890`; has flags; may `operator_delete(this)`; RET 4 |
| 2 | Vector-deleting (array) | **Falsified** — tests bit0 only; no element count / loop |
| 3 | Always frees this | **Falsified** — free gated on `flags & 1` |
| 4 | Installs vtbl here | **Falsified** — vtbl install is in complete `0040d890` |
| 5 | Same as base scalar `0040d590` | **Shape yes, identity no** — different complete callee / vtbl family |
| 6 | Product class name sealed | **Careful** — structural from vtbl address only |
| 7 | No return value | **Falsified** — `MOV EAX,ESI` returns this |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar vs complete | **High** | Leak / double free |
| flags bit0 gate | **High** | Wrong free policy |
| RET 4 / return this | **High** | ABI break |
| vtbl[0] binding | **High** | Wrong type identity |
| Product plate | **Low** | Naming only |
| Slots [1]/[2] | **Open** | Unknown methods |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Complete FUN_0040d890 (W32-C):
//   *this = PTR_FUN_009c7948; FUN_0040d820(base complete); no delete this
// Base scalar FUN_0040d590:
//   FUN_0040d820; if (flags&1) delete; return this; RET 4
// This FUN_0040d870:
//   FUN_0040d890; if (flags&1) delete; return this; RET 4
// Vtbl 009c7948[0]=0040d870
```

Live decompile 2026-07-29 ≡ scaffold 2026-07-23; 30 B hex seals CF. Closes W32-C residual “scalar caller `FUN_0040d870`” named as high-mention nested callee in wave33 partition.

---

## 4. Surviving contract for AutoCore

```
// Port as DERIVED scalar-deleting dtor only:
void* Class_009c7948_ScalarDeletingDtor(Host* self, uint8_t flags) {
  Class_009c7948_CompleteDtor(self); // derived vtbl + base complete chain
  if (flags & 1) operator_delete(self);
  return self;
}
// Do not invent vector-deleting or extra member teardown in this body.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl[0]/complete-then-free. Residual product + vtbl slots → **accept-with-gaps**.
