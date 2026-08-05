# Review B (skeptical / adversarial): `aa_0043ea60` GuardedVector_GrowBlockMap_Stride2

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ea60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W30-A) |
| **Counterpart** | `reviews/A_aa_0043ea60_GuardedVector_GrowBlockMap_Stride2.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only. No `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Standard `__thiscall` (this in ECX) | **Falsified** — entry uses EBX; no `MOV EBX,ECX` |
| 2 | cdecl | **Falsified** — `RET 0x4` |
| 3 | Same `begin>>2` as GuardedVector push family | **Falsified** — `D1 ED` = `>>1`; parents use `&1`/`>>1` |
| 4 | Ghidra plate complete after `operator_delete` | **Falsified** — bytes commit capacity/slots after delete |
| 5 | `operator_delete` noreturn | **Falsified** |
| 6 | Updates size (+0x10) | **Falsified** |
| 7 | Grow amount always stack arg only | **Falsified as always** — geometric floor |
| 8 | Identical to CircularPtrBuf_Grow (`0x00436650`) | **Falsified** — that unit uses head without shift + max `0x0CCCCCCC` |
| 9 | Leaf / no throw | **Falsified** — `FUN_00436860` |
| 10 | `unaff_EBX` is decompiler noise | **Falsified** — intentional register ABI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EBX this + ret 4 | **High** | Wrong ABI → crash |
| `begin>>1` stride | **High** | Wrong page math → corrupt map |
| Commit after delete | **High** | Stale slots pointer |
| Geometric grow | **High** | Under-grow loop |
| Element POD English | **Open** | Port type size mismatch |
| Runtime golden | **Open** | Edge-case map order |

---

## 3. Cross-check against raw + bytes

Must preserve:

```
if overflow: throw "deque<T> too long"
grow' = geometric(grow, capacity)
neu = new ((cap+grow')*4)
// rearrange; begin_blk = begin>>1
if (old) delete old
capacity += grow'
slots = neu
return (ret 4)
```

Clean **must not**:

- Use ECX as this
- Use `begin>>2`
- Skip commit after delete
- Touch size
- Invent element construction

---

## 4. Surviving contract for AutoCore

```c
// Port shape — custom register this
void GuardedVector_GrowBlockMap_Stride2(
    GuardedVectorHeader_Stride2* self /*reg EBX*/, unsigned min_grow);
// begin remains valid element index; block = begin>>1 after grow.
// Does not modify size. Does not construct PODs.
```

Sibling relationship: algorithm shared with `GuardedVector_GrowBlockMap` / `…_Thiscall`; only head shift and ABI differ.

---

## 5. Verdict

Attacks on ABI, stride, and decompiler commit plate resolved by full-body bytes + caller gates. Residual product English / runtime only → **accept**.
