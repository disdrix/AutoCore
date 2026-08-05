# Review B (skeptical / adversarial): `aa_0056ff00` WeaponHitResultVec_PushBack

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056ff00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-R) |
| **Counterpart** | `reviews/A_aa_0056ff00_WeaponHitResultVec_PushBack.md` |
| **Scratch** | `tmp/a_0056ff00.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is insert-at-iterator (not append) | **Falsified** — always writes at `end` (`[esi+8]`); no position arg |
| 2 | Element stride 4 / 8 / 0x38 | **Falsified** — `sar 5` + `add 0x20` seals **0x20** |
| 3 | Shell is +0 begin / +4 end / +8 cap | **Falsified** — bytes load **+4/+8/+0xc** |
| 4 | `__cdecl` / bare `ret` | **Falsified** — ECX this; **`ret 4`** |
| 5 | Constructs non-POD (ctor calls per element) | **Falsified** — `FUN_0056f1e0` is raw 8-dword move |
| 6 | Multiple unrelated callers | **Falsified** — only `FUN_0056e000` |
| 7 | Grow path is inlined realloc | **Falsified** — tail-call-ish `FUN_0056fab0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 0x20 | **High** | Buffer overrun / wrong count |
| ABI thiscall + ret 4 | **High** | Stack smash on port |
| Fast vs grow split | **High** | Missed reallocation |
| Name domain (weapon hit) | **Med** | Naming only; CF independent |
| +0 unused | **High** | Do not invent writes |

---

## 3. Cross-check against raw + bytes

```
if begin && size < cap:
  POD_copy_20(end, value); end += 0x20
else:
  grow_insert(vec, end, 1, value)
ret 4
```

Clean must **not** invent mid-insert, non-0x20 stride, or element ctors.

Hex seal: `568bf18b560485d2750433c9eb088b4e082bcac1f90585d274318b460c2bc2c1f8053bc873258b4424088b4c2408578b7e085056516a0157e8a3f2ffff83c41483c720897e085f5ec204008b5424088b4608526a01508bcee853fbffff5ec20400`

---

## 4. Surviving contract for AutoCore

```c
// Port of WeaponHitResultVec_PushBack
// thiscall VecShell* vec (begin@+4,end@+8,cap@+0xc), const Elem20* value; ret 4
void PushBack(VecShell* v, const Elem20* val) {
  if (v->begin && size(v) < capacity(v)) {
    memcpy(v->end, val, 0x20);
    v->end += 0x20;
  } else {
    GrowInsert(v, v->end, 1, val); // FUN_0056fab0
  }
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI, stride, and CF. Gaps limited to product English + nested helpers + runtime → **accept-with-gaps**.
