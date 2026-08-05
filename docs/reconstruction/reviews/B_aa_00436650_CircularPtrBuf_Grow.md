# Review B (skeptical / adversarial): `aa_00436650` CircularPtrBuf_Grow

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436650` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-E) |
| **Counterpart** | `reviews/A_aa_00436650_CircularPtrBuf_Grow.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Standard `__thiscall` (this in ECX) | **Falsified** — all ops via EBX; ECX used as scratch |
| 2 | cdecl (caller cleans stack) | **Falsified** — `ret 4` |
| 3 | Ghidra plate is complete after `operator_delete` | **Falsified** — bytes show capacity/slots commit after delete |
| 4 | `operator_delete` is truly noreturn | **Falsified** — `add esp,4` then commit; retail CRT delete returns |
| 5 | This is stock `std::deque::` map grow of T blocks | **Not proven** — uses same max + error string, but object is a small circular **pointer** map with explicit head; treat as **custom** utility |
| 6 | Updates `count` (+0x10) | **Falsified** — no write to +0x10 |
| 7 | Multiple callers / general allocator | **Falsified** — sole xref from push sibling |
| 8 | Grow amount always exactly the stack arg | **Falsified as always** — geometric bump to ≥ max(cap/2, 8) when safe |
| 9 | Leaf / no throw | **Falsified** — can throw via `FUN_00436860` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX this + ret 4 | **High** | Wrong port ABI → crash |
| Commit after delete | **High** | Leaked/stale slots pointer if plate followed blindly |
| Geometric grow | **High** | Under-growing → immediate re-grow loop |
| Circular rearrange algebra | **Medium–High** | Corrupted slot order / head mismatch |
| Name `CircularPtrBuf_Grow` | **Inferred** | Cosmetic only |
| Runtime golden | **Open** | Silent map corruption edge cases |

---

## 3. Cross-check against raw + bytes

Must preserve:

```
if overflow: throw "deque<T> too long"
grow' = geometric(grow, capacity)
neu = new ((cap+grow')*4)
// rearrange circular map (memmove + zero)
if (old) delete old
capacity += grow'
slots = neu
return (ret 4)
```

Clean **must not**:

- Use ECX as this
- Return before capacity/slots publish after delete
- Touch count
- Invent element POD copies (push sibling owns that)

---

## 4. Surviving contract for AutoCore

```c
// Port shape — custom register this
void CircularPtrBuf_Grow(CircularPtrBuf* self /*reg EBX*/, unsigned grow_request);
// On success: self->capacity increased, self->slots replaced, head still valid index.
// On overflow: C++ exception path (deque too long).
// Does not modify self->count. Does not construct element PODs.
```

Porting note: AutoCore likely does not need this client container; if mirrored, prefer a standard growable ring or `std::deque` of pointers with tests for head-preserving reallocation.

---

## 5. Open questions

1. Whether +0x00 is a vptr / allocator cookie (untouched).
2. Whether geometric policy matches MSVC deque map exactly or is a simplified custom copy.
3. Failure path if `operator_new` throws (not observed beyond normal C++ new).

**Verdict:** **accept-with-gaps**
