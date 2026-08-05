# Review B (skeptical / adversarial): `aa_0040d820` StdTreeHost_PtrVal_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-A) |
| **Counterpart** | `reviews/A_aa_0040d820_StdTreeHost_PtrVal_CompleteDtor.md` |
| **Scratch** | `tmp/a_0040d820.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the scalar-deleting dtor | **Falsified** — no flags arg; no `operator_delete(this)`; scalar is `FUN_0040d590` which calls this then conditional delete |
| 2 | `FUN_0040d7c0` on bare this | **Falsified** — bytes `LEA ECX,[ESI+4]` before call |
| 3 | Decompiler order wrong | **Falsified** — install → clear → 7c0 order matches bytes |
| 4 | Also frees tree nodes itself | **Falsified** — node free is inside clear (`0040d5b0` + `0040d630`); this only sequences clear + head teardown |
| 5 | No SEH | **Falsified** — full SEH frame + EH state 0/−1 |
| 6 | Product class name sealed | **Careful** — structural only from vtbl/CF |
| 7 | Derived complete is same unit | **Partial** — `FUN_0040d890` installs different vtbl then **calls** this |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar | **High** | Double free / leak |
| Stage order | **High** | Wrong dtor sequencing |
| this+4 for 7c0 | **High** | Wrong subobject teardown |
| Vtbl install address | **High** | Wrong type identity |
| Nested 7c0 English | **Med** | Head free residual |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Scalar FUN_0040d590:
//   FUN_0040d820(this);
//   if (flags & 1) operator_delete(this);
// Derived FUN_0040d890:
//   *this = PTR_FUN_009c7948;
//   FUN_0040d820(this);
// Vtbl 009c7938[0]=0040d590, [2]=0040d5b0
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 for stage list; bytes seal this+4.

---

## 4. Surviving contract for AutoCore

```
// Port as COMPLETE dtor only:
void StdTreeHost_PtrVal_CompleteDtor(Host* self) {
  self->vtbl = &PTR_FUN_009c7938;
  StdTree_Clear_PtrVal_Vtbl0C(self);   // values + free nodes + reset
  FUN_0040d7c0(self + 4);              // head / tree subobject
  // caller / scalar path deletes self if needed
}
// Do not invent product map type. Pair with FreeSubtree + Clear duals.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/vtbl/this+4. Residual product + nested 7c0 → **accept-with-gaps**.
