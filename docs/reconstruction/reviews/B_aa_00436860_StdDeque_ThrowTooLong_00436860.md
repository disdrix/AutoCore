# Review B (skeptical / adversarial): `aa_00436860` StdDeque_ThrowTooLong_00436860

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-C) |
| **Counterpart** | `reviews/A_aa_00436860_StdDeque_ThrowTooLong_00436860.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a normal size/capacity getter | **Falsified** — no return value path; ends in `_CxxThrowException` |
| 2 | Message is vector/list/map too-long (wrong container) | **Falsified** — plate is specifically `deque<T>` @ `0x00a31520` |
| 3 | Function has stack formals / returns | **Falsified** — Ghidra signature void(void); no success `ret` |
| 4 | Identical byte-for-byte to `FUN_0051b5f0` / other clones | **Not claimed** — role-equivalent only (75 B vs 112 B); not merged |
| 5 | Clean invents resize math | **Falsified** — clean is throw-only CF |
| 6 | Can be ported as log-and-continue | **Falsified for fidelity** — client always throws |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Noreturn throw | **High** | Infinite grow / corrupt heap on overflow |
| Message plate | **High** | Wrong diagnostic |
| Shared helper (multi-caller) | **High** | Missing call sites when porting guards (4 parents) |
| Exception type class | Medium | Wrong C++ catch filters (rare in AutoCore C#) |

---

## 3. Cross-check against raw + bytes

```
SEH LAB_009bc919 → string("deque<T> too long") → FUN_00401a40 (vftable 009c7634)
    → _CxxThrowException(ThrowInfo@00acc388)
```

Clean must **not** invent resize arithmetic, return codes, or alternate messages.

Do **not** merge this body with other deque-too-long VAs without proving byte equality.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of StdDeque_ThrowTooLong_00436860
static void StdDeque_ThrowTooLong()
{
    // Client: throws C++ exception with message "deque<T> too long"
    throw new InvalidOperationException("deque<T> too long"); // or dedicated LengthError
}
// Call only on map/size overflow arms (max element/block count exceeded).
```

Do **not** use this as a soft-fail path when porting map grow: retail aborts via exception unwind.

---

## 5. Open questions

1. Exact `std::length_error` vs `logic_error` identity for AutoCore catch policy.
2. Whether server ports should throw managed exceptions or assert (product choice; CF is throw).

**Verdict:** **accept**
