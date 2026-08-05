# Review B (skeptical / adversarial): `aa_0051b5f0` StdDeque_ThrowTooLong_0051b5f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b5f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-E) |
| **Counterpart** | `reviews/A_aa_0051b5f0_StdDeque_ThrowTooLong_0051b5f0.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is a normal size/capacity getter | **Falsified** — no return value path; ends in `_CxxThrowException` |
| 2 | Message is vector/list/map too-long (wrong container) | **Falsified** — plate is specifically `deque<T>` @ `0x00a31520` |
| 3 | Function has stack formals / returns | **Falsified** — Ghidra signature void(void); no success `ret` |
| 4 | Identical byte-for-byte to `FUN_0040ff30` / `FUN_005b2a80` | **Not claimed** — role-equivalent clones only; not merged |
| 5 | Clean invents extra math | **Falsified** — clean is throw-only CF |
| 6 | Can be ported as log-and-continue | **Falsified for fidelity** — client always throws |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Noreturn throw | **High** | Infinite grow / corrupt heap on overflow |
| Message plate | **High** | Wrong diagnostic |
| Shared helper (not unique sole instance) | **High** | Missing call sites when porting guards |
| Exception type class | Medium | Wrong C++ catch filters (rare in AutoCore C#) |

---

## 3. Cross-check against raw + bytes

```
SEH → string("deque<T> too long") → exception ctor → vftable 009c7628
    → message copy → vftable 009c7634 → _CxxThrowException(ThrowInfo@00acc388)
```

Clean must **not** invent resize arithmetic, return codes, or alternate messages.

Do **not** merge this body with other deque-too-long VAs without proving byte equality.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of StdDeque_ThrowTooLong_0051b5f0
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
