# Review B (skeptical / adversarial): `aa_00418790` StdList_Incsize_00418790

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00418790_StdList_Incsize_00418790.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + `get_assembly_context` + callers/xrefs. No `disassemble_bytes`. Own VA `0x00418790` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with `this` (list) in ECX | Bytes use **EDX** for list (`[edx+8]`); ECX is count; callers `mov edx,ebx` + `mov ecx,1` | **Falsified** as thiscall — **fastcall ECX/EDX** |
| 2 | RecvBroadcast-only / missions-only helper | **29** xrefs / **21** callers across insert paths | **Falsified** — shared leaf |
| 3 | Allocates / links list nodes | Body only size math + optional throw; no `new` | **Falsified** — size only (`_Incsize`) |
| 4 | Max size is `0xffffffff` / unlimited | Immediate `0x3fffffff` in `be ff ff ff 3f` | **Falsified** |
| 5 | Returns bool success / status in EAX | Plain `ret` (`C3`); void | **Falsified** |
| 6 | Stack args / `ret N` | Epilogue `C3` only; no stack loads of args | **Falsified** |
| 7 | Same as thiscall `FUN_00404840` | `00404840` is thiscall (list in ECX); this unit is fastcall | **Survives** as related but distinct ABI |
| 8 | Same as `StdList_Incsize_Max1fffffff` | That twin uses max `0x1fffffff` | **Survives** as related but distinct max |
| 9 | Identical role to dualed `0043fe60` | Live CF/ABI/max/string/throw match twin | **Survives** — true twin; VA name disambiguation required |
| 10 | Three-rep diverges from live | live ≡ raw CF; annotated/clean match | **Falsified** |
| 11 | Product studio name known | No plate; only STL string | **Survives** — name remains STL-inferred |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX count, EDX list*, plain RET | **High** | Wrong insert ABI → corrupt size / crash |
| `+8` is `_Mysize` | **High** | Wrong field update |
| `0x3fffffff` gate | **High** | Missed throw / false throw |
| `"list<T> too long"` path | **High** | Wrong exception contract |
| Node alloc not here | **High** | Misattribute to BuyNode |
| Twin of `0043fe60` | **High** | Duplicate port work if ignored |
| Runtime / bit-exact | **Open** | Shipping list growth |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (0x3fffffffU - *(param_2+8) < param_1) throw "list<T> too long";
  *(param_2+8) += param_1;

bytes:
  8b4208 … beffffff3f 2bf0 3bf1 … 73..   ; load size, max, cmp, jae
  … 03c1 894208 … c3                     ; add count, store, ret
string 00a1581c: "list<T> too long"
caller 00402805: b901000000 8bd3 e8…     ; ecx=1, edx=list (parent push_front)
```

**No conflict** on owned CF.

---

## 4. Surviving contract for AutoCore

```csharp
// StdList_Incsize_00418790 @ 0x00418790
// retail: ECX=count, EDX=list*, plain RET
// twin of StdList_Incsize @ 0x0043fe60

void Incsize(StdList list, uint count)
{
    uint size = list.Mysize; // +8
    if (0x3FFFFFFFu - size < count)
        throw new InvalidOperationException("list<T> too long"); // retail C++ throw
    list.Mysize = size + count;
}
```

Port note: may share implementation with dualed `StdList_Incsize` (`0043fe60`); keep both call-site VAs mappable.

---

## 5. Gaps that survive attack

- Exact exception C++ type name (ThrowInfo sealed; English open).
- Runtime / bit-exact / differential not run (Terminal **false**).
- Product-domain list element English is caller's concern, not this leaf.

None of these overturn the `_Incsize` / ABI / twin seal.

---

## 6. Verdict

**accept** — adversarial probes against thiscall / domain-only / BuyNode / unlimited-size / stack-arg claims **fail**. Owned contract matches dualed twin `0043fe60`.
