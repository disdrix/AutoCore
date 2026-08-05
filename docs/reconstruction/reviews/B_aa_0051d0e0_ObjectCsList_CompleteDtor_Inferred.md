# Review B (skeptical / adversarial): `aa_0051d0e0` ObjectCsList_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-R) |
| **Counterpart** | `reviews/A_aa_0051d0e0_ObjectCsList_CompleteDtor_Inferred.md` |
| **Scratch** | `tmp/a_0051d0e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is scalar-deleting dtor | **Falsified** — no flags arg; bare `RET`; never `operator_delete(this)`; free is `FUN_0051d0c0` |
| 2 | Same as clear-only `FUN_0051b8a0` | **Falsified** — this installs vtbls + `DeleteCriticalSection`; clear does not |
| 3 | Same as base scalar `FUN_0051bf10` | **Falsified** — dual-phase `009ce154`+`009ce07c`; base scalar is base-only + free flag |
| 4 | cdecl / stack this | **Falsified** — `MOV ESI,ECX` thiscall |
| 5 | Decompiler drops ECX into `FUN_0051bc90` | **Near miss only** — bytes keep ESI/`MOV ECX,ESI`; clean must pass `this` |
| 6 | Deletes nodes with `node+4=0` | **Falsified** — callee is `FUN_0051bc90` (no +4 clear); that step is `0051b8a0` |
| 7 | Unrelated to SharedBase `+0xB0` | **Falsified** — W30-F / ctor chain; vtbl `009ce154` shared |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete vs scalar-deleting | **High** | Double free / leak |
| Dual vtbl order | **High** | Wrong virtuals mid-teardown |
| DeleteCS @ +4 | **High** | CS leak / UAF |
| Drain via `0051bc90` | **High** | Node leak |
| Product class name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_0051d0c0 (vtbl 009ce154 slot0):
ObjectCsList_CompleteDtor(this);  // this unit
if (flags & 1) operator_delete(this);

// Contrast FUN_0051bf10 (vtbl 009ce07c slot0):
// base vtbl only + clear + DeleteCS + optional delete
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 39 B hex seals epilogue after dual clear + DeleteCS.

---

## 4. Surviving contract for AutoCore

```
// Port as COMPLETE dtor only:
void ObjectCsList_CompleteDtor(List* self) {
  self->vtbl = &vtable_derived_009ce154;
  ObjectCsList_Clear_NoNodePlus4(self);   // FUN_0051bc90
  self->vtbl = &vtable_base_009ce07c;
  ObjectCsList_Clear_NoNodePlus4(self);
  DeleteCriticalSection(&self->cs);       // @ +4
}
// Scalar path: complete then optional operator_delete (FUN_0051d0c0).
// Do NOT merge with ObjectCsList_ClearDestroy (no DeleteCS / no vtbl swap).
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/dual-vtbl/DeleteCS. Residual product English → **accept-with-gaps**.
