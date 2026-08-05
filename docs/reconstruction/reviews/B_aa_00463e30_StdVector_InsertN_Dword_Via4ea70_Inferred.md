# Review B (skeptical / adversarial): `aa_00463e30` StdVector_InsertN_Dword_Via4ea70_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463e30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-M) |
| **Counterpart** | `reviews/A_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` / `batch_decompile` + `read_memory` + callers/xrefs + helper decompiles. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | ECX is count (same as `00419880`) | **Falsified** — ECX is vector (`mov edi,ecx`; triad on EDI) |
| 2 | Element stride is not 4 | **Falsified** — all size math `>>2` / `*4` |
| 3 | Growth is 2× | **Falsified** — `cap + (cap>>1)` = 1.5× |
| 4 | This is vertex-decl-only logic | **Falsified** — 13 heterogeneous callers; scaffold Named_CalleeOf rejected |
| 5 | Overflow silently saturates | **Falsified** — calls `FUN_004540b0` throw |
| 6 | `operator_delete` never returns so triad install is null-only | **Falsified as port rule** — bytes install triad after optional delete; prefer bytes |
| 7 | Drop-in of `004073a0` without helper note | **Falsified as identical binary** — same algorithm family, **different** relocate helpers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 0x0C ABI | **High** | Stack corruption |
| Triad offsets | **High** | Memory smash on grow |
| 1.5× policy | **High** | Wrong capacity / OOM patterns |
| Generic role | **High** | Overfitting gfx English |
| Helper micro-ABI in clean | Medium | Wrong relocate if over-trusted schematic |
| Product English | Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
mov edi, ecx          ; vector this
begin = [edi+4]
cap = (capEnd-begin)>>2
if count==0 ret
if size+count > 0x3fffffff: call FUN_004540b0
if cap < size+count: grow 1.5x; new; 4ea70/36ef0/4ea70; delete; triad; ret 0xC
else in-place fill/shift
ret 0x0C
```

Do **not** port as count-in-ECX matching `00419880` without adapting formals. Do **not** trust decompiler cut-off after `operator_delete`.

---

## 4. Surviving contract for AutoCore

```csharp
// void InsertN(ref VectorDword v, uint* where, uint count, uint value)
// triad begin+4 end+8 cap+0xC; stride 4; 1.5x grow; throw on >0x3fffffff
```

Shared infrastructure; pair with twin insert engines only when helper policy matches.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm thiscall insert-N dword engine; residual helper micro-detail and runtime only. Not reject.
