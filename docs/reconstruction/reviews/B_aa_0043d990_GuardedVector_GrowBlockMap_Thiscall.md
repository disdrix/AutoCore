# Review B (skeptical / adversarial): `aa_0043d990` GuardedVector_GrowBlockMap_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d990` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W30-A) |
| **Counterpart** | `reviews/A_aa_0043d990_GuardedVector_GrowBlockMap_Thiscall.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Custom EBX-only this (like `0x0043c9b0`) | **Falsified** — prologue `MOV EBX,ECX`; thiscall entry |
| 2 | cdecl (caller cleans stack) | **Falsified** — `RET 0x4` |
| 3 | Ghidra plate complete after `operator_delete` | **Falsified** — bytes show capacity/slots commit after delete |
| 4 | `operator_delete` is truly noreturn | **Falsified** — `ADD ESP,4` then commit |
| 5 | This is stock MSVC `std::deque::_Growmap` with PDB name | **Not proven** — same throw string + map pattern; treat as **custom GuardedVector family** structural |
| 6 | Updates `size` (+0x10) | **Falsified** — no write to +0x10 |
| 7 | `begin >> 1` (stride-2) | **Falsified** — `SHR EBP,2` only |
| 8 | Grow amount always exactly stack arg | **Falsified as always** — geometric bump to ≥ max(cap/2, 8) when safe |
| 9 | Leaf / no throw | **Falsified** — can throw via `FUN_00436860` |
| 10 | Identical body bytes to `0x0043c9b0` | **Falsified** — 340 B vs 334 B; ECX prologue / pops differ |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX this + ret 4 | **High** | Wrong port ABI → crash |
| Commit after delete | **High** | Leaked/stale slots if plate followed blindly |
| Geometric grow | **High** | Under-grow → re-grow loop |
| Circular rearrange algebra | **Medium–High** | Slot order / head mismatch |
| Name `…_Thiscall` | **Inferred** | Cosmetic; distinguishes EBX twin |
| Runtime golden | **Open** | Silent map corruption edge cases |

---

## 3. Cross-check against raw + bytes

Must preserve:

```
if overflow: throw "deque<T> too long"
grow' = geometric(grow, capacity)
neu = new ((cap+grow')*4)
// rearrange circular map (memmove + zero); begin_blk = begin>>2
if (old) delete old
capacity += grow'
slots = neu
return (ret 4)
```

Clean **must not**:

- Use EBX as entry this without ECX load
- Return before capacity/slots publish after delete
- Touch size (+0x10)
- Use `begin>>1` (that is `0x0043ea60`)
- Invent element POD copies (push siblings own that)

---

## 4. Surviving contract for AutoCore

```c
// Port shape — thiscall
void GuardedVector_GrowBlockMap_Thiscall(GuardedVectorHeader* self,
                                         unsigned min_grow);
// On success: self->capacity increased, self->slots replaced, begin still valid
// element index (block = begin>>2).
// On overflow: C++ exception path (deque too long).
// Does not modify self->size. Does not construct element PODs.
```

Porting note: AutoCore likely does not need this client container verbatim; if mirrored, prefer a standard growable ring or `std::deque` of page pointers with tests for head-preserving reallocation. Close residual shared with W28-B `GuardedVector_GrowBlockMap`.

---

## 5. Verdict

Adversarial attacks on ABI, decompiler commit plate, stride, and twin-identity all resolved by bytes + callers. Remaining gaps are product English and runtime golden only → **accept**.
