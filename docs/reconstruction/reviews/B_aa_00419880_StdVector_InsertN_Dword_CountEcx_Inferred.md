# Review B (skeptical / adversarial): `aa_00419880` StdVector_InsertN_Dword_CountEcx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00419880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-D) |
| **Counterpart** | `reviews/A_aa_00419880_StdVector_InsertN_Dword_CountEcx_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | True thiscall with vector in ECX (same as `004073a0`) | **Falsified** — ECX is count; vector on stack; ret 0x0C |
| 2 | Element stride is not 4 | **Falsified** — all size math `>>2` / `*4` |
| 3 | Growth is 2× | **Falsified** — `cap + (cap>>1)` = 1.5× |
| 4 | This is mission-journal-only logic | **Falsified** — dozens of heterogeneous callers |
| 5 | Overflow silently saturates | **Falsified** — calls `FUN_00418130` throw |
| 6 | Insert of `004073a0` so one name suffices without ABI note | **Falsified as drop-in** — same algorithm, **different calling convention** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Count-in-ECX ABI | **High** | Stack corruption at every call site |
| Triad offsets | **High** | Memory smash on grow |
| 1.5× policy | **High** | Wrong capacity / OOM patterns |
| Generic role | **High** | Overfitting mission journal semantics |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
mov esi, ecx          ; count
mov edi, [ebp+8]      ; vec
begin = [edi+4]
cap = (capEnd-begin)>>2
if count==0 ret
if size+count > 0x3fffffff: call ThrowTooLong
if cap < size+count: grow 1.5x / exact; new; relocate; delete; rewrite triad; ret
else in-place fill/shift
ret 0x0C
```

Do **not** port as `__thiscall(Vector*)` matching `004073a0` without adapting formals.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape — prefer BCL List<T>.InsertRange; if hand-rolled:
void InsertN(List<uint> v, int index, int count, uint value)
{
    // capacity policy optional; semantic = insert count copies at index
    for (int i = 0; i < count; i++) v.Insert(index + i, value);
}
```

Retail dual instantiations (`004073a0` thiscall vs this count-ECX) are compile artifacts — server needs one correct insert, not both ABIs.

---

## 5. Open questions

1. Why two MSVC instantiations coexist (TU / template / COMDAT).
2. Whether `FUN_00418690` is `vector::resize` peer for this flavor only.

**Verdict:** **accept**
