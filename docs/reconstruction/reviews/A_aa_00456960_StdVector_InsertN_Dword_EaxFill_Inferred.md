# Review A (reconstruction fidelity): `aa_00456960` StdVector_InsertN_Dword_EaxFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00456960` |
| **VA** | `0x00456960` |
| **Canonical name** | `StdVector_InsertN_Dword_EaxFill_Inferred` (structural) |
| **Ghidra name** | `FUN_00456960` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00456960_StdVector_InsertN_Dword_EaxFill_Inferred.md` |
| **System** | util / container (generic `std::vector<dword>`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style `std::vector<T>` **insert-n** for **4-byte** elements. Inserts `count` copies of `*value` at iterator `pos`, growing capacity when needed (**1.5×** growth with exact-fit floor).

**ABI (sealed from body + callers):**

| Slot | Role |
|---|---|
| `param_1` / ECX path | **count** (elements to insert) |
| `param_2` | **vector** object (`+4` begin, `+8` end, `+0xc` capEnd) |
| `param_3` | **insert position** (element*) |
| `*EAX` | **fill value** (dword replicated `count` times) |

Sibling of `StdVector_InsertN_Dword_Inferred` (`0x004073a0`, different calling convention / fill helpers). Wrapper `StdVector_InsertOne_RebindIt_Inferred` (`0x00466da0`) calls this with **count=1**.

**Not** domain logic — multi-caller dword bag (UI, mission, assManager, etc.).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00456960_*`, `reconstructed-exact/FUN_00456960.cpp` |
| Function record | `functions/aa_00456960_FUN_00456960.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x00456960` (2026-07-29) ≡ clean CF |
| Bytes | `read_memory` 32 B — `sub esp,0xC`; load `*EAX` fill; triad via `[ebx+4]` |
| Insert-1 wrapper dual | `A_aa_00466da0_StdVector_InsertOne_RebindIt_Inferred.md` |
| Twin insert-n dual | `A_aa_004073a0_StdVector_InsertN_Dword_Inferred.md` |
| Callers (bulk xrefs) | dozens: `00466dd1`, `004567a8`, UI `007*`, ass/hash `0096*`, … |

**Not performed:** bulk disassembly, Launcher, runtime, bit-exact.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live decompile | **High** | CF spine identical |
| Triad begin `+4` / end `+8` / capEnd `+0xc` | **Confirmed** | body |
| Element stride **4** (`>>2` / `*4`) | **Confirmed** | body |
| `param_1` = insert count; early-out if 0 | **Confirmed** | body |
| Fill value from `*EAX` | **Confirmed** | `uVar1 = *in_EAX`; fill loops |
| Growth: `cap + (cap>>1)` else exact `size+count` | **Confirmed** | body; max `0x3fffffff` |
| Overflow path `FUN_004540b0` | **High** | max-size gate |
| Realloc: `operator_new` → prefix `memmove` → fill helper `FUN_004651d0` → suffix `memmove` → `operator_delete` old | **Confirmed** | body |
| In-place two sub-cases by distance-to-end | **Confirmed** | `FUN_0040c7c0` relocate + fill |
| Product demangled name | **Open** | no RTTI on VA |
| Element domain always same | **Falsified** | multi-caller generic |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Cap = 0 if begin null else `(capEnd-begin)>>2` | Yes |
| If count==0 return | Yes |
| Max-size check → `FUN_004540b0` | Yes |
| Need grow: 1.5× / min-fit; realloc three-way; update triad; return | Yes |
| Else near-end: shift tail then fill | Yes |
| Else: shift-from-end + fill | Yes |

### Recovered CF

```c
// void StdVector_InsertN_Dword_EaxFill(uint count, Vec* vec, uint32_t* pos /* fill *EAX */)
uint32_t fill = *value_eax;
uint cap = begin ? (capEnd - begin) >> 2 : 0;
if (count == 0) return;
// size checks / 0x3fffffff overflow → FUN_004540b0
if (cap < size + count) {
  // newCap = cap + (cap>>1) or size+count; operator_new; relocate around pos; delete old; write triad
  return;
}
// in-place relocate via FUN_0040c7c0 / FUN_004651d0; fill [pos, pos+count) with fill
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00466da0` | insert-one rebind wrapper |
| Caller | many UI / ass / mission sites | generic dword push/insert |
| Callee | `operator_new` / `operator_delete` | buffer |
| Callee | `memmove` | relocate |
| Callee | `FUN_004651d0` / `FUN_0040c7c0` | fill / shift helpers |
| Callee | `FUN_004540b0` | overflow / length error |

---

## 6. Gaps / open

1. Exact MSVC demangled name / template args.
2. Precise roles of `FUN_004651d0` / `FUN_0040c7c0` (sealed as relocate/fill family).
3. Full caller taxonomy (dozens).
4. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps** — insert-n + 1.5× growth + EAX fill ABI sealed; keep `_Inferred`.
