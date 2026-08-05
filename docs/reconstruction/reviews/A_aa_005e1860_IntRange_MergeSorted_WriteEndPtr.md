# Review A (reconstruction fidelity): `aa_005e1860` IntRange_MergeSorted_WriteEndPtr

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1860` |
| **VA** | `0x005e1860`–`0x005e18cf` |
| **Canonical name (Ghidra)** | `FUN_005e1860` |
| **Proposed name** | `IntRange_MergeSorted_WriteEndPtr` (**High** role; no product string) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005e1860` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W16-D) |
| **Reviewer role** | Reconstruction fidelity / dual residual |
| **Counterpart** | `reviews/B_aa_005e1860_IntRange_MergeSorted_WriteEndPtr.md` |
| **System** | inventory / loot catalog |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Sorted merge of two half-open `int32` ranges** into a write cursor, then store the advanced cursor in `*pOutEndSlot`.

```
out ← merge_sorted([beginA,endA), [beginB,endB))
*pOutEndSlot = out
```

Compare is **signed** (`*B < *A` takes B, else A — ties prefer A). Leaf: no calls, no globals.

**Sole live caller** `FUN_005e0cd0` (`LootCatalog_FillCandidateIds_QualityTypeBand_Inferred`) always passes **empty A** (`beginA=endA=0`) so the body degenerates to **memcpy-style dword copy** of catalog candidate ID ranges into the out-vector cursor. Full two-range merge remains live machine behavior for any future/non-empty A.

**Not** a pick/RNG step, not band indexing (`005e0480`/`005e0590`), not the unfiltered fill (`005e07d0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra MCP `decompile_function` @ `0x005e1860` |
| Bytes | `read_memory` @ `0x005e1860` len 96 + epilogue @ `0x005e18c0` |
| Callers | `get_function_callers` → sole `FUN_005e0cd0` |
| Function meta | body `005e1860`–`005e18cf` |
| Parent dual | `A\|B_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred` |
| Raw / annotated / clean | updated this pass |
| Function record | `docs/reconstruction/functions/aa_005e1860_FUN_005e1860.md` |

**This pass:** live decompile + epilogue bytes + sole-caller CF. **Not performed:** Launcher, runtime, bit-exact, parent ledger edits.

---

## 3. Sealed ABI (Confirmed — machine)

```
005e18c8  8B 44 24 14     mov eax, [esp+0x14]   ; pOutEndSlot (after 4 pushes)
005e18cc  5F              pop edi
005e18cd  5E              pop esi
005e18ce  5D              pop ebp
005e18cf  89 08           mov [eax], ecx        ; *pOutEndSlot = final out
005e18d1  5B              pop ebx
005e18d2  C3              ret                   ; __cdecl
```

(Body ends at listed function end `005e18cf` per Ghidra; epilogue sequence spans into next symbol boundary padding — **bare `ret` confirmed**, no `ret 0x18`.)

| Slot | Role | Evidence |
|---|---|---|
| `[esp+4]` | `int **pOutEndSlot` | final `mov [eax],ecx` |
| `[esp+8]` | `int *beginA` | entry `mov eax,[esp+8]` |
| `[esp+0xC]` | `int *endA` | loaded to `ebx` |
| `[esp+0x10]` | `int *beginB` | loaded to `edi` |
| `[esp+0x14]` | `int *endB` | loaded to `ebp` |
| `[esp+0x18]` | `int *out` | loaded to `ecx` |

```c
// MSVC __cdecl
void IntRange_MergeSorted_WriteEndPtr(
    int32_t **pOutEndSlot,
    int32_t  *beginA,
    int32_t  *endA,
    int32_t  *beginB,
    int32_t  *endB,
    int32_t  *out);
```

---

## 4. Sealed control flow (Confirmed)

```c
void IntRange_MergeSorted_WriteEndPtr(
    int32_t **pOutEndSlot,
    int32_t *beginA, int32_t *endA,
    int32_t *beginB, int32_t *endB,
    int32_t *out)
{
  if (beginA != endA) {
    do {
      if (beginB == endB) break;
      if (*beginB < *beginA) { *out++ = *beginB++; }
      else                   { *out++ = *beginA++; }
    } while (beginA != endA);
    for (; beginA != endA; ++beginA) *out++ = *beginA;
  }
  for (; beginB != endB; ++beginB) *out++ = *beginB;
  *pOutEndSlot = out;
}
```

| Stage | Match |
|---|---|
| `beginA == endA` skip first block | Yes (entry `je`) |
| dual-cursor merge + signed `<` | Yes |
| drain A then drain B | Yes |
| `*pOutEndSlot = out` | Yes (epilogue) |
| clean ≡ raw ≡ live | **Yes** |

---

## 5. Caller contract (`0x005e0cd0`)

```c
// From LootCatalog_FillCandidateIds_QualityTypeBand:
FUN_005e1860(&param_3, 0, 0, *(cell+4), *(cell+8), 0);
FUN_005e1860(&param_3, 0, 0, *(band+4), *(band+8), *(outVec+4));
```

| Observation | Conf |
|---|---|
| Empty A on both sites → pure copy of B | **Confirmed** |
| Updates out-vector end via `*pOutEndSlot` | **High** |
| Source ranges are catalog dword ID slices | **High** (parent dual) |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sorted-merge CF | **Confirmed** | leaf body |
| `*pOutEndSlot = advanced out` | **Confirmed** | epilogue |
| `__cdecl` bare `ret` | **Confirmed** | `C3` |
| Signed int compare | **Confirmed** | decompiler + `jl` family |
| Sole caller `005e0cd0` | **Confirmed** | xrefs |
| Empty-A → pure copy at call sites | **Confirmed** | |
| Product / CRT symbol name | **Open** | `_Inferred` optional |
| Runtime / bit-exact | **Open** | deferred |

---

## 7. Gaps / open

1. MSVC CRT / STL mangled name (internal `std::merge` instantiation) — non-blocking.
2. No second caller exercises non-empty dual ranges in this image.
3. Parent `005e0cd0` out-vector formal / `FUN_00410420` prep residual (owned by parent dual).

**Verdict:** **accept** — CF, ABI, sole-caller role sealed. Residual naming only.
