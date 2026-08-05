# Review B (skeptical / adversarial): `aa_00754320` Palantir_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00754320` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-K) |
| **Counterpart** | `reviews/A_aa_00754320_Palantir_CompleteDtor.md` |
| **Scratch** | `tmp/a_00754320.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a scalar-deleting dtor (frees this) | **Falsified** — no `operator_delete` in body; free is only in wrapper `FUN_004447e0` when `flags&1` |
| 2 | Decompiler ExceptionList restore is correct | **Falsified** — bytes restore `fs:[0]` from stack slot; no `ExceptionList = this` |
| 3 | `StringVec_Tidy()` uses ambient / global ECX only | **Falsified** — `LEA ECX,[ESI+0xA0]` immediately before call |
| 4 | Nested dtors are ECX-thiscall with no push | **Falsified** — `PUSH` of `self+0x30` / `self+0x10` then `CALL` |
| 5 | Class is AssManager-only (not Palantir) | **Falsified** — vtbl[1] `FUN_00754480` logs `Palantir.cpp` / `Palantir::ResetDevice` |
| 6 | Leaves `DAT_00d1f058` / `DAT_00d1f1fc` live | **Falsified** — both explicitly zeroed |
| 7 | Order free host then members | **Falsified** — members first; globals last; no free host |
| 8 | Nested callees dual-sealed here | **Accepted gap** — `FUN_0075d8e0` / `FUN_00964d00` unowned |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=this complete dtor (no free) | **High** | double-free / leak |
| Member destroy order | **High** | UAF mid-dtor |
| Global clears | **High** | stale singleton / path list |
| Product class Palantir | **High** | wrong subsystem port |
| Nested subobject types | **Low** | wrong member cleanup |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00754320 (bytes authority)
vtbl=00a9f76c
~string(+0xB4)
Tidy(+0xA0); DAT_00d1f1fc=0
FUN_0075d8e0(+0x30)
FUN_00964d00(+0x10)
DAT_00d1f058=0

// FUN_004447e0 scalar wrapper
CALL FUN_00754320
if (flags & 1) operator_delete(this)
RET 4

// vtbl[1] FUN_00754480
vog_LogMessage("...\\Palantir.cpp", 0x184, 0, "Palantir::ResetDevice failed...")
```

AssManager code that *uses* `DAT_00d1f058` as host is compatible with Palantir embedding manager state (offset `+0x58` GuardedVector etc.) — does **not** overturn Palantir class identity of this vtbl.

---

## 4. Surviving contract for AutoCore

```
// Port as complete dtor (not scalar):
void Palantir_CompleteDtor(Palantir* self) {
  self->vtbl = &Palantir_DtorVtbl; // 00a9f76c
  destroy basic_string at +0xB4;
  StringVec_Tidy(self+0xA0); DAT_00d1f1fc = nullptr;
  dtor_subobject_30(self+0x30);  // FUN_0075d8e0
  dtor_subobject_10(self+0x10);  // FUN_00964d00
  DAT_00d1f058 = nullptr;
}
// Scalar path: complete dtor then optional operator_delete (FUN_004447e0).
// Do not invent free-this inside complete body.
// Do not skip either global clear.
// Nested +0x10/+0x30 remain residual until dualed.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, order, globals, and Palantir identity; nested member plates remain open → **accept-with-gaps**.
