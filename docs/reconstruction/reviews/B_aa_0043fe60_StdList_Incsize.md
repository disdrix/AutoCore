# Review B (skeptical / adversarial): `aa_0043fe60` StdList_Incsize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fe60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0043fe60_StdList_Incsize.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory`. No `disassemble_bytes`. Own VA `0x0043fe60` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `__thiscall` with `this` in ECX | Bytes use **EDX** for list (`[edx+8]`); ECX is count; caller `mov edx,ebx` + `mov ecx,1` | **Falsified** as thiscall — **fastcall ECX/EDX** |
| 2 | Auth-only helper | 18+ callers across audio, UI, Auth, maps | **Falsified** — shared leaf |
| 3 | Allocates / links list nodes | Body only size math + optional throw; no `new` | **Falsified** — size only (`_Incsize`) |
| 4 | Max size is `0xffffffff` / unlimited | Immediate `0x3fffffff` in `be ff ff ff 3f` | **Falsified** |
| 5 | Returns bool success | Plain `ret`; void | **Falsified** |
| 6 | Stack args / `ret N` | Epilogue `C3` only | **Falsified** |
| 7 | Three-rep diverges from live | live ≡ raw string/CF; clean matches | **Falsified** |
| 8 | Twin `00403600` is identical | Twin is `__thiscall` + max `0x6666666` | **Survives** as related but distinct |
| 9 | Product studio name known | No plate; only STL string | **Survives** — name remains **Inferred** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX count, EDX list*, plain RET | **High** | Wrong insert ABI → corrupt size / crash |
| `+8` is `_Mysize` | **High** | Wrong field update |
| `0x3fffffff` gate | **High** | Missed throw / false throw |
| `"list<T> too long"` path | **High** | Wrong exception contract |
| Node alloc not here | **High** | Misattribute to BuyNode |
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
caller 0048036e: b901000000 8bd3 e8…     ; ecx=1, edx=list
```

**No conflict** on owned CF.

---

## 4. Surviving contract for AutoCore

```csharp
// StdList_Incsize @ 0x0043fe60
// retail: ECX=count, EDX=list*, plain RET

void Incsize(StdList list, uint count)
{
    uint size = list.Mysize; // +8
    if (0x3FFFFFFFu - size < count)
        throw new InvalidOperationException("list<T> too long"); // retail C++ throw
    list.Mysize = size + count;
}
```

---

## 5. Gaps that survive attack

1. **Exact MSVC exception type** (`std::length_error` vs custom) — ThrowInfo pointer only.
2. **Why max is `0x3fffffff`** vs twin `0x6666666` — specialization/open.
3. **Runtime** not run.

**Verdict:** **accept** — adversarial checks reinforce Path A seal.
