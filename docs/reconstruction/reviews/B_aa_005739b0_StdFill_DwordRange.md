# Review B (skeptical / adversarial): `aa_005739b0` StdFill_DwordRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_005739b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-B) |
| **Counterpart** | `reviews/A_aa_005739b0_StdFill_DwordRange.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is memcpy / memmove of a block | **Falsified** — writes same `*value` repeatedly; no source range |
| 2 | Element size is not 4 | **Falsified** — `add eax, 4` only |
| 3 | Args are (count, dst, value) FillN form | **Falsified** — second arg compared as end pointer (`cmp eax,ecx`), not a countdown |
| 4 | `__thiscall` / ECX this | **Falsified** — all three args from stack; bare `ret` |
| 5 | Constructs non-POD (calls ctor) | **Falsified** — leaf; pure store |
| 6 | Value is passed by register dword (not pointer) | **Falsified** — `[esp+0xC]` then `[edx]` load |
| 7 | Inclusive end (`last` written) | **Falsified** — exit when `first == last` before store |
| 8 | Same as CombatFloater FillN 0x38 | **Falsified** — different VA, stride, no construct-N callee |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Half-open range | **High** | Off-by-one write past end |
| Dword stride | **High** | Corrupting adjacent fields |
| Value is pointer | **High** | Wrong ABI on port |
| No construction | **High** | Double-ctor if port adds constructors |

---

## 3. Cross-check against raw + bytes

```
first=[esp+4], last=[esp+8], value=[esp+0xC]
while first != last: *first = *value; first += 4
ret
```

Clean must **not** invent count-based FillN, byte memset, or object constructors. Distinct from uninitialized_fill that placement-news.

Parent `FUN_004507a0` passes `&param_4` (address of template dword) — matches pointer-to-value ABI.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of StdFill_DwordRange
static void StdFill_DwordRange(Span<uint> range, uint value)
{
    for (int i = 0; i < range.Length; i++) range[i] = value;
}
// Or pointer form:
// for (uint* p = first; p != last; p++) *p = *valuePtr;
```

Safe for POD dword / pointer-sized element vectors. Do **not** use for types needing copy-ctors.

---

## 5. Open questions

1. Product symbol name.
2. Whether any caller relies on re-read of a mutating `*value` mid-loop (bytes re-load; unusual).

**Verdict:** **accept**
