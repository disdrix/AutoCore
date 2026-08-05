# Review A (reconstruction fidelity): `aa_00403980` UiToastVector_InsertN

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403980` |
| **VA** | `0x00403980` |
| **Canonical name** | `UiToastVector_InsertN` (structural MSVC-style `vector::insert` / `_Insert_n`) |
| **Ghidra name** | `FUN_00403980` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00403980_UiToastVector_InsertN.md` |
| **System** | `missions-progression` / shared UI toast vector helpers |
| **Verdict** | **accept-with-gaps** — CF / stride / growth policy sealed; product symbol + some helper names open |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

MSVC-style **vector insert-N** for elements of stride **`0x98`** (UI toast POD).

Signature shape (thiscall):

```c
void __thiscall UiToastVector_InsertN(
    Vec *this,          // ECX — begin@+4, end@+8, capacity_end@+0xC
    void *pos,          // insert position iterator (pointer into buffer)
    unsigned count,     // number of copies of value to insert
    /*value*/ void *src // POD source (copied as 0x26 dwords to stack, then fill)
);
```

High-level CF:

1. **POD-copy** value into stack local (`0x26` dwords) — same width as `FUN_00404710`.
2. If `count == 0` → return.
3. Compute size/capacity via `(end−begin)/0x98` and `(cap−begin)/0x98`.
4. **Max-size guard** vs `0x1af286b` → `FUN_00418130` on overflow.
5. If `capacity < size + count`:
   - Growth: prefer **1.5×** (`cap + (cap>>1)`), else 0, else at least `size+count` via `FUN_00403960`.
   - `operator_new(newCap * 0x98)`; relocate via `FUN_00404510` / fill via `FUN_00404130` / tail via `FUN_00404510`.
   - `operator_delete` old buffer; rebind begin/end/cap.
6. Else in-place:
   - If insert near end: shift tail with `FUN_00404510`, fill remainder `FUN_00404130`, patch middle `FUN_00404530`.
   - Else: back-shift via `FUN_00404510` + `FUN_00421ee0`, fill hole with `FUN_00404530`.

Callers: `FUN_0040c720` (toast grow, count=1) and `FUN_00402ed0` (other insert site; same stride family).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_00403980_*`, `FUN_00403980.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x00403980` (2026-07-29) |
| Entry bytes | `read_memory` SEH prologue `55 8b ec … 81 ec b0 00 00 00` |
| Callees | `get_function_callees`: `00403960`, `00404130`, `00404510`, `00404530`, `00418130`, `00421ee0`, `operator_new`/`delete` |
| Callers | `0040c720`, `00402ed0` |
| Parent context | toast push dual `A_aa_0040c5c0_*` |

**Not performed:** deep dual of each relocate helper; runtime; bit-exact; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element stride **`0x98`** throughout | **Confirmed** | all size/cap/index `/0x98`; `* 0x98` on alloc |
| Stack value copy **`0x26` dwords** | **Confirmed** | same loop as `00404710` |
| Vector layout begin/end/cap @ +4/+8/+0xC | **Confirmed** | decompile stores |
| 1.5× growth (`cap + cap>>1`) when safe | **Confirmed** | classic MSVC pattern in body |
| Max element count bound `0x1af286b` | **Confirmed** | compare before grow |
| `count==0` early no-op (after stack copy) | **Confirmed** | outer `if (param_3 != 0)` |
| Role = toast-width vector insert (not UI draw) | **High** | toast chain + craft seed alias |
| Exact product name (`std::vector<T>::insert`) | **Open** | structural |
| Helper VAs semantic names (`00404510` move, …) | **Probable** | from CF usage; not dual-owned here |
| Clean ≡ raw ≡ live control skeleton | **Confirmed** | large body; scaffold plate |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH frame + stack value POD copy | **Yes** |
| Capacity math /0x98 | **Yes** |
| Max-size path → `FUN_00418130` | **Yes** |
| Realloc path new/move/fill/delete/rebind | **Yes** |
| In-place near-end path | **Yes** |
| In-place mid path + `FUN_00421ee0` | **Yes** |
| No mission/audio | **Yes** |

### Growth sketch

```
need = size + count
if capacity < need:
  newCap = cap + (cap >> 1)   // if no overflow vs 0x1af286b
  if newCap < need: newCap = size + count   // via FUN_00403960 helper path
  buf = new (newCap * 0x98)
  // move [begin,pos) → buf; fill count×value; move [pos,end) → after
  delete old; rebind begin/end/cap
else:
  // shift + fill in place (two sub-shapes)
```

---

## 5. Gaps

1. Product/PDB name and `T` typedef.
2. OWN duals of relocate helpers (`00404510` / `00404130` / `00404530` / `00421ee0`) — residual.
3. Full audit of second caller `FUN_00402ed0` domain (may be same toast type or sibling POD).
4. Runtime / bit-exact — open.

**Verdict:** **accept-with-gaps** — insert-N CF, stride, growth policy, and vector slot layout sealed for ports of the toast queue grow path.
