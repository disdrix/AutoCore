# Review A (reconstruction fidelity): `aa_004507a0` StdVector_Dword_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004507a0` |
| **VA** | `0x004507a0`–`0x00450959` |
| **Canonical name** | `StdVector_Dword_InsertN_Inferred` |
| **Prior scaffold** | `FUN_004507a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_004507a0_StdVector_Dword_InsertN_Inferred.md` |
| **System** | util / container |
| **Agent** | W18-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **`count` copies of one fill dword** into an MSVC-style `vector` shell at `insertPos`:

1. **count == 0** → return.
2. **size + count > 0x3FFFFFFF** → `FUN_004540b0()` (length overflow).
3. **capacity < size + count** → geometric `cap + cap/2` (or `size+count`), `operator_new(newCap*4)`, copy prefix / fill n / copy suffix, `operator_delete` old, rebind begin/end/capEnd.
4. **Else if tail room from pos insufficient for pure scheme** → hybrid move + fill (`FUN_004e2e80` / `FUN_004e2f70` / `FUN_005739b0`).
5. **Else** → extend end by backward copy (`FUN_004e2e80` + `FUN_004e24d0`) then fill hole.

**Primary caller shape:** `StdVector_DwordResize` (`FUN_004367f0`) grow arm calls with `insertPos = end`, `count = newCount - size`, `fillSrc = &fillValue`.

**Not** erase, not map insert, not non-dword stride.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004507a0_FUN_004507a0.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_004507a0_FUN_004507a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Dword_InsertN_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004507a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004507a0_FUN_004507a0.md` |
| Live decompile | Ghidra `0x004507a0` — **≡ scaffold CF** |
| Machine | `read_memory` full body; all exits `C2 0C 00` |
| Resize dual | `A_aa_004367f0_StdVector_DwordResize` (caller) |

**Not performed:** `disassemble_bytes`, Launcher, runtime, ownership of copy/fill helpers.

---

## 3. Signature / layout

```c
// __thiscall; ret 0xC
void __thiscall StdVector_Dword_InsertN_Inferred(
    DwordVector *vec,
    uint32_t *insertPos,
    uint32_t count,
    uint32_t *fillSrc);
```

| Offset | Role |
|---|---|
| vec `+4` | begin |
| vec `+8` | end |
| vec `+0xC` | capacity_end |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Insert-N fill of dword vector | **Confirmed** | CF + resize caller |
| ABI thiscall `ret 0xC` | **Confirmed** | three exits |
| Stride 4 / `>>2` / `*4` new | **Confirmed** | |
| Cap imm `0x3FFFFFFF` | **Confirmed** | `BF FF FF FF 3F` |
| Geometric growth `cap+(cap>>1)` | **Confirmed** | |
| Realloc rebind begin/end/capEnd | **Confirmed** | |
| count==0 no-op | **Confirmed** | |
| Clean ≡ raw ≡ live CF | **Confirmed** | |
| Product STL name | **Open** | `_Inferred` |
| vs `FUN_004073a0` twin | **Open** | sibling not owned |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Early out count==0 | **Yes** |
| Overflow → `FUN_004540b0` | **Yes** |
| Realloc path new/fill/copy/delete/rebind | **Yes** |
| Hybrid mid-insert | **Yes** |
| In-place backward + fill | **Yes** |

---

## 6. Gaps

- Mangled STL symbol / exact MSVC version template.
- Whether `FUN_004073a0` is a duplicate instantiation.
- Throw string / type inside `FUN_004540b0`.
- Runtime golden.
