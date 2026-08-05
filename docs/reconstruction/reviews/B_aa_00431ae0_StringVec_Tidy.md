# Review B (skeptical / adversarial): `aa_00431ae0` StringVec_Tidy

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431ae0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-D) |
| **Counterpart** | `reviews/A_aa_00431ae0_StringVec_Tidy.md` |
| **Scratch** | `tmp/a_00431ae0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler is complete | **Falsified** — omits post-`operator_delete` triad zeros; false noreturn |
| 2 | Range dtor only (like `FUN_00431aa0`) | **Falsified** — free + null after loop |
| 3 | Leaves empty non-null buffer | **Falsified** — zeros begin/end/capEnd |
| 4 | Has stack formals / RET n | **Falsified** — ECX only; bare `C3` |
| 5 | Stride 4 / dword elements | **Falsified** — `ADD ESI,0x1c` destroy walk |
| 6 | Null begin returns without writes | **Falsified** — still zeros all three fields |
| 7 | assManager scaffold name sealed | **Rejected** — structural `StringVec_Tidy` |
| 8 | Same as vector clear keeping capacity | **Falsified** — frees buffer (full tidy, not clear-to-empty-capacity) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX=self + bare RET | **High** | ABI crash |
| stride 0x1c destroy | **High** | leak / double-free adjacent |
| free + null triad | **High** | use-after-free / stale cap |
| not capacity-preserving clear | **High** | wrong reuse semantics |
| Product plate | **Low** | naming |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00431ae0  (bytes)
if begin==null: zero triad; ret
destroy [begin,end) step 0x1c
delete begin
zero triad; ret

// FUN_00431aa0  (sibling, unowned)
destroy [a,b) step 0x1c; return   // no free

// Callers: W32-D listing cleanup, AssManager path lists, EH unwind
```

Decompile ≢ hex on tail; full 71 B hex seals free+null. Thunk `00431ad0` is pure JMP.

---

## 4. Surviving contract for AutoCore

```
// Port as vector _Tidy / buffer release:
void StringVec_Tidy(StringVecShell* v) {
  if (v->begin) {
    for (auto* p = v->begin; p != v->end; p = next_string(p, 0x1c))
      p->~basic_string();
    operator delete(v->begin);
  }
  v->begin = v->end = v->capEnd = nullptr;
}
// Do not keep capacity. Do not skip free. Elem stride 0x1c.
// Prefer this over range-dtor FUN_00431aa0 when releasing the shell.
```

---

## 5. Verdict

Adversarial pass confirms A: bytes override decompiler on post-delete nulling; unit is full tidy not range-dtor. Product English + runtime open → **accept-with-gaps**.
