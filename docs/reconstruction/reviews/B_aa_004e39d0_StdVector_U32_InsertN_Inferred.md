# Review B (skeptical / adversarial): `aa_004e39d0` StdVector_U32_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e39d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e39d0_StdVector_U32_InsertN_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Combat-only helper | Many non-combat callers (map/WAD) | **Falsified** as combat-only — general vector |
| 2 | Fixed-size array push | Grows with 1.5× + realloc | **Falsified** fixed — **dynamic** |
| 3 | Element size 8 (TFID) | All math is `>>2` / `*4` | **Falsified** 8 — **4-byte** slots (pointers) |
| 4 | Same as deferred queue `004e1600` | Distinct VA; no CS/link | **Falsified** merge |
| 5 | `operator_delete` true process-kill | Known Ghidra noreturn on free | **Survives** as decompiler noise |
| 6 | Always reallocs | In-place branch when capacity sufficient | **Survives** dual paths |

---

## 2. Live ≡ raw

Live `batch_decompile` @ `0x004e39d0` matches raw: capacity math, grow, `memmove`/`FUN_004e2f70`, in-place tail shift. Callers include `FUN_004da2e0` (confirmed `get_function_callers`).

---

## 3. Surviving contract

```
// this = vector host { begin@+4, end@+8, cap@+0xC } element size 4
// insert count copies of *value at insert_at
// grow if needed (max(old+old/2, size+count)); else shift in place
```

**Gaps kept:** product STL name; `004e1050` throw type.

**Verdict:** **accept-with-gaps**.
