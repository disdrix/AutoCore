# Review B (skeptical / adversarial): `aa_004540b0` StdVector_ThrowTooLong

| Field | Value |
|---|---|
| **Stable ID** | `aa_004540b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-B) |
| **Counterpart** | `reviews/A_aa_004540b0_StdVector_ThrowTooLong.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a normal size/capacity getter | **Falsified** — no return value path; ends in `_CxxThrowException` |
| 2 | Message is something other than vector length | **Falsified** — bytes push `0x00a15830`; memory is `"vector<T> too long"` |
| 3 | This is deque/list/map too-long (wrong container) | **Falsified** — plate is specifically `vector<T>` (siblings use other plates) |
| 4 | Function has stack formals / returns | **Falsified** — Ghidra signature void(void); no `ret N` success path |
| 5 | Clean invents extra math | **Falsified** — clean is throw-only CF |
| 6 | Unique sole instance of this string | **Partial** — other VAs also embed same plate; this unit is still the **shared call target** for many grow paths (xrefs) |
| 7 | Can be ported as log-and-continue | **Falsified for fidelity** — client always throws; port may map to exception or hard fail but must not silently grow past max |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Noreturn throw | **High** | Infinite grow / corrupt heap on overflow |
| Message plate | **High** | Wrong diagnostic |
| Shared helper (not per-type body) | **High** | Missing call sites when porting guards |
| Exception type class | Medium | Wrong C++ catch filters (rare in AutoCore C#) |

---

## 3. Cross-check against raw + bytes

```
SEH → string("vector<T> too long") → ExceptionFromString → _CxxThrowException(ThrowInfo@00acc388)
```

Clean must **not** invent resize arithmetic, return codes, or alternate messages.

Sibling throw VAs with the same string are **not** this dual's ownership; do not merge bodies without byte equality proof.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of StdVector_ThrowTooLong
static void StdVector_ThrowTooLong()
{
    // Client: throws C++ exception with message "vector<T> too long"
    throw new InvalidOperationException("vector<T> too long"); // or dedicated LengthError
}
// Call only on size overflow arms (max element count exceeded).
```

Do **not** use this as a soft-fail path when porting insert/grow: retail aborts the operation via exception unwind.

---

## 5. Open questions

1. Exact `std::length_error` vs `logic_error` identity for AutoCore catch policy.
2. Whether server ports should throw managed exceptions or assert (product choice; CF is throw).

**Verdict:** **accept**
