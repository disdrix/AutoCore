# Review B (skeptical / adversarial): `aa_0051bf10` ObjectCsListBase_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051bf10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-R) |
| **Counterpart** | `reviews/A_aa_0051bf10_ObjectCsListBase_ScalarDeletingDtor_Inferred.md` |
| **Scratch** | `tmp/a_0051bf10.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is complete dtor only (no free) | **Falsified** — `flags&1` → `operator_delete`; `RET 4` |
| 2 | Same body as `FUN_0051d0e0` | **Falsified** — no derived `009ce154` install; free flag present |
| 3 | Same as clear `FUN_0051b8a0` / `FUN_0051bc90` alone | **Falsified** — installs vtbl + DeleteCS + optional free |
| 4 | Ghidra noreturn truncates body | **Falsified** — 46 B reaches `MOV EAX,ESI` / `RET 4` after delete |
| 5 | Has CODE callers | **Falsified** — analyze: DATA vtbl slot0 only |
| 6 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; thiscall + stack flags |
| 7 | Always frees | **Falsified** — free only when bit0 set (`74 09` skip) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting role | **High** | Leak / double free |
| Base-only vtbl | **High** | Wrong mid-dtor virtuals |
| DeleteCS @ +4 | **High** | CS leak |
| flags bit0 only | **High** | Wrong array-delete assumption |
| Product base name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// vtbl PTR_FUN_009ce07c @ 0x009ce07c:
//   [0] = 0x0051bf10   // this unit (scalar deleting)
//   [1] = 0x0051bc30   // (not owned)

// Derived complete path does NOT call this; uses FUN_0051d0e0 then free in 0051d0c0.
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full hex seals free-path fall-through.

---

## 4. Surviving contract for AutoCore

```
// Port as BASE scalar deleting dtor:
void* ObjectCsListBase_ScalarDtor(List* self, uint8_t flags) {
  self->vtbl = &vtable_base_009ce07c;
  ObjectCsList_Clear_NoNodePlus4(self);  // FUN_0051bc90
  DeleteCriticalSection(&self->cs);
  if (flags & 1) operator_delete(self);
  return self;
}
// Virtual via base vtbl slot0. Do not substitute for derived complete dtor.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on scalar role/ABI/base phase/DeleteCS/flags. Residual product English → **accept-with-gaps**.
