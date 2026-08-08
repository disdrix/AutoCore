# Review B (skeptical / adversarial): `aa_007aff00` CNDUIWindow_ReleaseTextLayoutAndNested_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-G) |
| **Counterpart** | `reviews/A_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `CNDUIWindow` complete dtor | **Falsified** — no vtbl install / owner-debug / base chain; parent is `007b5be0` |
| 2 | Always frees text layout at `+0x28C` | **Falsified** — gated on `+0x20C != 0`; parent may free later |
| 3 | `FUN_00424060()` on window this | **Falsified** — bytes `LEA ECX,[ESI+0x1E8]` before call |
| 4 | thiscall layout dtor | **Falsified** — `PUSH EDI; CALL 00797d70` with `RET 4` (stdcall, WQ9L-F sealed) |
| 5 | Frees host window | **Falsified** — no `operator_delete(this)` |
| 6 | `operator_delete` noreturn truncates | **Falsified** — continues nested clear + zeros + RET |
| 7 | Scaffold VOG_DEBUG_STOP product plate | **Falsified** — string is parent debug path only |
| 8 | Same as parent free of `+0x28C` alone | **Falsified** — also always runs nested clear + field zeros; parent free is separate stage |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Helper vs complete | **High** | Wrong ownership of free stages |
| Gate on `+0x20C` | **High** | Premature free / leak |
| Nested `+0x1E8` thiscall | **High** | Wrong object tear |
| Layout stdcall pair | **High** | Stack imbalance |
| Product field English | **Open** | Name residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_007aff00:
ESI=this
if [ESI+0x20C]:
  free layout [ESI+0x28C] via 00797d70 + delete; null slot
LEA ECX,[ESI+0x1E8]; CALL 00424060
zero +0x128; zero +0x12C
ret
```

Live decompile 2026-08-05 matches CF except bare `FUN_00424060()` display — LEA sealed by hex.  
Parent after return: may free `+0x28C` again; later restamps nested vtbl and re-clears + `DeleteCriticalSection`.

---

## 4. Surviving contract for AutoCore

```
// Port as partial CNDUIWindow teardown helper only:
void CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(CNDUIWindow* self) {
  if (self->gate_20C) {
    if (auto* p = self->textLayout_28C) {
      UiTextLayout_CompleteDtor_Inferred(p);
      operator_delete(p);
    }
    self->textLayout_28C = nullptr;
  }
  FUN_00424060(&self->nested_1E8);
  self->field_128 = self->field_12C = 0;
}
// Do NOT free self. Do NOT DeleteCriticalSection here.
// Pair with parent CNDUIWindow_CompleteDtor (007b5be0).
```

---

## 5. Verdict

**accept-with-gaps** — adversarial claims against complete-dtor / always-free / wrong nested this / thiscall-layout are falsified. Product English for gate and nested class remains open → `_Inferred` retained.
