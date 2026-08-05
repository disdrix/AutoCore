# Review B (skeptical / adversarial): `aa_00763f60` GfxBody_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00763f60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-C) |
| **Counterpart** | `reviews/A_aa_00763f60_GfxBody_CompleteDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is scalar-deleting dtor | **Falsified** — no flags arg; never `operator_delete(this)`; epilogue bare `C3` after stack cleanup |
| 2 | Mission-audio scaffold plate is identity | **Falsified** — xrefs are ListTrackedObj member teardown + CVOG graphics paths; plate discarded |
| 3 | Ghidra noreturn truncates body | **Falsified** — 206 B reaches `FUN_0096d7a0` + SEH restore + `C3` |
| 4 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; thiscall-equivalent complete-dtor frame |
| 5 | Only frees two buffers | **Falsified** — also nested `FUN_00763740`, vector@+0x128, ptr-vec@+0xDC, aligned@+0x98, base dtor |
| 6 | Vtbl install is “base only at end” | **N/A pattern differ** — this unit sets **class** vtbl at **entry** (typical derived complete dtor); base work is `FUN_0096d7a0` at end |
| 7 | Unrelated to ListTrackedObj | **Falsified** — W30-P calls at `+0x2C8/+0x17C/+0x30` |
| 8 | Matching ctor differs in type | **Falsified** — `FUN_00764030` installs same `PTR_LAB_00a9da8c` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar-deleting | **High** | Double free / leak |
| Offset map + stage order | **High** | Partial teardown UAF |
| Vtbl identity | **High** | Wrong type during dtor |
| Product class name | **Low** | Naming only |
| Nested callee semantics | **Med** | Residual leak surface |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// ListTrackedObj_CompleteDtor (W30-P):
FUN_00763f60(this+0x2C8);
FUN_00763f60(this+0x17C);
FUN_00763f60(this+0x30);

// Ctor twin:
FUN_00764030: *this = PTR_LAB_00a9da8c; zero fields; base FUN_0096d830
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full-body hex seals epilogue after all “noreturn” deletes.

---

## 4. Surviving contract for AutoCore

```
// Port as COMPLETE dtor only:
void GfxBody_CompleteDtor(GfxBody* self) {
  self->vtbl = &PTR_LAB_00a9da8c;
  // FUN_00763740 nested teardown
  // destroy vector host at +0x128
  // free ptr-vector at +0xDC
  // free buffers +0xD0 and +0xC0 triples
  // FUN_0096aec0(+0x98); FUN_0096d7a0(self)
}
// Do not operator_delete(self) here.
// Reject Mission-audio Named_CalleeOf plate.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/offsets/epilogue. Residual product class + nested English → **accept-with-gaps**.
