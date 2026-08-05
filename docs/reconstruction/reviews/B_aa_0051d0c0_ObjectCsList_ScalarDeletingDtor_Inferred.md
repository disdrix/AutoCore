# Review B (skeptical / adversarial): `aa_0051d0c0` ObjectCsList_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051d0c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-O) |
| **Counterpart** | `reviews/A_aa_0051d0c0_ObjectCsList_ScalarDeletingDtor_Inferred.md` |
| **Scratch** | `tmp/a_0051d0c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a **skill** function (skill-adjacent partition note) | **Falsified** — only calls complete CS-list dtor + optional `operator_delete`; vtbl `009ce154` is ObjectCsList derived (W31-R); no skill tables/IDs |
| 2 | Same as complete dtor `FUN_0051d0e0` | **Falsified** — wraps it + free flag + `RET 4` |
| 3 | Same as base scalar `FUN_0051bf10` | **Falsified** — no inline vtbl/DeleteCS; calls complete which does derived→base phases |
| 4 | Always frees | **Falsified** — free only when `flags&1` (`74 09` skip) |
| 5 | Ghidra noreturn truncates body | **Falsified** — 30 B reaches `MOV EAX,ESI` / `RET 4` |
| 6 | Has CODE callers | **Falsified** — analyze/xrefs: DATA vtbl slot0 only |
| 7 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; thiscall + stack flags |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting role | **High** | Leak / double free |
| Not skill | **High** | Wrong subsystem ownership |
| Complete + free sequencing | **High** | Wrong dtor order |
| flags bit0 only | **High** | Wrong array-delete assumption |
| Product derived name | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// vtbl PTR_FUN_009ce154 @ 0x009ce154:
//   [0] = 0x0051d0c0   // this unit (scalar deleting)
//   [1] = 0x0051c0a0   // (not owned)

// Complete path FUN_0051d0e0 does NOT free; free only here when flags&1.
// Base scalar is separate: FUN_0051bf10 @ 009ce07c[0].
```

Live decompile 2026-08-04 ≡ raw 2026-07-23. Full hex seals free-path fall-through. Adjacent complete body starts immediately after pad at `0x0051d0e0`.

---

## 4. Surviving contract for AutoCore

```
// Port as DERIVED scalar deleting dtor (NOT skill):
void* ObjectCsList_ScalarDtor(List* self, uint8_t flags) {
  ObjectCsList_CompleteDtor(self);  // FUN_0051d0e0
  if (flags & 1) operator_delete(self);
  return self;
}
// Virtual via derived vtbl 009ce154 slot0.
// Do not substitute for base scalar 0051bf10 or complete-only 0051d0e0.
// Ignore Ghidra noreturn on operator_delete.
// Do not invent skill/ability semantics from partition adjacency.
```

---

## 5. Verdict

Adversarial pass confirms A on scalar role/ABI/complete wrap/flags; **rejects skill mislabel**. Residual product English → **accept-with-gaps**.
