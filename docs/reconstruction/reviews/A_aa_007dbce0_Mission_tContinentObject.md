# Review A (reconstruction fidelity): `aa_007dbce0` Mission_tContinentObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_007dbce0` |
| **VA** | `0x007dbce0` |
| **Canonical name** | `Mission_tContinentObject` (plate `//tContinentObject/row`) |
| **Ghidra name** | `FUN_007dbce0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007dbce0_Mission_tContinentObject.md` |
| **System** | missions-progression / DB table load |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

WAD/DB **row loader** for continent-object definitions keyed by XPath/plate **`//tContinentObject/row`**.

Produces a **linked staging list** of row records, then **bulk-copies** each row as **`0x55` dwords = `0x154` bytes** into the caller’s destination buffer (vector-like). Sibling pattern to `Mission_tContinentExploredAreas` (`0x007dd5e0`).

Two source modes gated by global **`DAT_00d1793c`**:

### Mode A — `DAT_00d1793c == 0` (binary / column reader path)

1. Alloc list head via `FUN_0041c5a0`.
2. If `*param_1 == 0` → cleanup / `operator_delete` (fail).
3. Build reader state; `FUN_0041a810` on `param_1+0x28` (MBCS→wide→COM bind family).
4. Cascade many **`FUN_004231d0`** column pulls (decompiler collapses args; failure any arm → teardown + `FUN_007a4480` debug).
5. Require `local_2cc != 0` (row material present) else fail path.
6. Loop `FUN_0041c000` / `FUN_0041f340` / `FUN_0041eab0`: materialize list nodes; count in `local_2e8`.
7. Optional `FUN_00422de0` / `FUN_0041bf70` if flag set.
8. Teardown reader; **copy** each node’s payload (`+2` dwords in) **`0x55` dwords** into `*(param_2+4)` advancing by `0x55` dwords.
9. Free temporary list / always `operator_delete` head (SEH / noreturn style exits in decompiler).

### Mode B — `DAT_00d1793c != 0` (COM XML path)

1. `SysAllocString(L"//tContinentObject/row")`.
2. COM open helpers `FUN_00419ca0` / `FUN_00419ed0`; `AddRef`; fail → `_com_issue_error(-0x7fffbffd)` (`E_POINTER` family).
3. Iterate rows via vtbl **+0x1c** method; release path with SysFreeString.
4. Same list teardown / delete epilogue.

**Caller:** `FUN_00541950` — loads table into `object+0xf20` blob, row count `(end-begin)/0x154`, then inserts each row into a CNDHash via **`FUN_00545a90`** (key = first dword of row, value = row ptr, soft=0).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_007dbce0_*`, `reconstructed-exact/FUN_007dbce0.cpp` |
| Function record | `functions/aa_007dbce0_FUN_007dbce0.md` |
| Fresh decompile | Ghidra `batch_decompile` @ `0x007dbce0` (2026-07-29) — large; many “unreachable” SEH arms |
| Bytes prologue | `read_memory` — SEH frame `LAB_009aed60`, stack `0x2e4` |
| String | `L"//tContinentObject/row"` (mode B) |
| Sibling dual | `A_aa_007dd5e0_Mission_tContinentExploredAreas.md` |
| Parent consumer | `FUN_00541950` decompile (stride **0x154**, insert `00545a90`) |
| Callers | `FUN_00541950` only (Ghidra) |
| Callees (sample) | `0041a810`, `004231d0`×N, `0041c000`, `0041f340`, SysAllocString/Free, `_com_issue_error` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Table id `//tContinentObject/row` | **Confirmed** | BSTR literal |
| Row stride **0x154** / **0x55 dwords** | **Confirmed** | body copy loop + caller `/0x154` |
| Dual mode via `DAT_00d1793c` | **Confirmed** | body |
| Mode A uses `0041a810` + column cascade | **High** | body |
| Mode B COM XML + SysAllocString path | **High** | body |
| Copy out to `*(param_2+4)` buffer | **High** | body |
| Sole loader caller `00541950` | **High** | callers list |
| Full column field map (names/types) | **Open** | many `004231d0` with collapsed args |
| SEH / “unreachable” blocks product paths | **Tentative** | decompiler warnings |
| clean ≡ raw ≡ live CF (macro) | **High** | scaffold large but same plate |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Mode flag branch | Yes |
| Mode A bind + column reads + list build + 0x55 copy | Yes |
| Mode B BSTR + COM iterate | Yes |
| List free / operator_delete epilogue | Yes |
| Invented product columns | None sealed — Open |

### Recovered CF (role-level)

```c
// void Mission_tContinentObject(pathOrCtx *p, OutVec *out)
// dual-source loader; rows size 0x154
list = AllocListHead();
if (DAT_00d1793c == 0) {
  // binary/column path via 0041a810 + 004231d0 cascade
  // foreach row: append 0x154 payload node
  // memcpy each node -> out buffer stride 0x154
} else {
  bstr = SysAllocString(L"//tContinentObject/row");
  // COM open + row iterate (vtbl+0x1c)
  SysFreeString(bstr);
}
FreeList(list);
```

---

## 5. Callers / callees (inventory)

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00541950` | install into `+0xf20`, hash insert each row |
| Callee | `FUN_0041a810` | locale/COM bind bridge |
| Callee | `FUN_004231d0` × many | column read |
| Callee | `FUN_0041c000` / `0041f340` / `0041eab0` | row iteration / node make |
| Callee | SysAllocString / SysFreeString / `_com_*` | mode B |

---

## 6. Gaps / open

1. **Column map** — seal field offsets inside 0x154 vs AutoCore continent-object model.
2. Meaning of `DAT_00d1793c` (shipping mode switch).
3. Exact `__thiscall` vs stack signature vs `00541950` call shape (decompiler arg loss).
4. SEH exception paths not product-tested.
5. Runtime row count / bit-exact deferred.

**Verdict:** **accept-with-gaps** — table identity + row size + dual-mode loader High; columns Open.
