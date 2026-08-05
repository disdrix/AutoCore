# Review B (skeptical / adversarial): `aa_00466ea0` StdVector_InsertN_Elem28_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00466ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W34-Q) |
| **Counterpart** | `reviews/A_aa_00466ea0_StdVector_InsertN_Elem28_CountEcx_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs only. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | True thiscall with vector in ECX (like `004306b0` basic_string insert) | **Falsified** — ECX is **count**; vec in **EDX**; `RET 8` |
| 2 | Element stride is 4 (dword insert) | **Falsified** — all size math `/0x1c`; magic `0x92492493` |
| 3 | This is `basic_string` insert (`004306b0`) | **Falsified** — POD 7-dword copy helpers; no string ctor/dtor loop |
| 4 | Growth is 2× | **Falsified** — `cap + (cap>>1)` = 1.5× |
| 5 | Overflow silently saturates | **Falsified** — calls `FUN_004540b0` throw |
| 6 | Decompiler 3-arg signature is complete | **Falsified as complete** — bytes load `value*` from `[ebp+0xC]`; two stack formals + `RET 8` |
| 7 | Drop-in for `00469f50` | **Falsified** — different register/stack ABI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Count-ECX + vec-EDX ABI | **High** | Stack/register corruption at call site |
| Triad + stride 0x1c | **High** | Memory smash on grow |
| 1.5× policy + max `0x9249249` | **High** | Wrong capacity / throw edges |
| POD not basic_string | **High** | Wrong dtor/leak on port |
| Helper formal wiring | Medium | Local residual only |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
mov ebx, ecx          ; count
mov esi, edx          ; vec
value* = [ebp+0xC]    ; snapshot 0x1c
where  = [ebp+8]
cap = (capEnd-begin)/0x1c
if count==0 ret
if size+count > 0x9249249: call FUN_004540b0
if cap < size+count: grow 1.5x / exact; new; relocate; delete; rewrite triad; ret 8
else in-place fill/shift; ret 8
```

Do **not** port as `__thiscall(Vector*)` matching basic_string insert, nor as dword CountEcx without stride change.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — prefer BCL List<T>.InsertRange for 28-byte POD T:
void InsertN(List<Elem28> v, int index, int count, in Elem28 value)
{
    for (int i = 0; i < count; i++) v.Insert(index + i, value);
}
```

Retail dual ABIs (`00466ea0` CountEcx/VecEdx vs `00469f50` ValueEdx) are compile artifacts — server needs one correct insert, not both.

---

## 5. Open questions

1. Concrete T identity (which 0x1c POD).  
2. Why this TU emits CountEcx/VecEdx vs ValueEdx sibling.  
3. Exact EH state numbers on fill paths.

**Verdict:** **accept-with-gaps**
