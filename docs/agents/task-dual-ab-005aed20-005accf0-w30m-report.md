# Dual A/B report — W30-M OWN-ONLY (`0x005aed20`, `0x005accf0`)

**Date:** 2026-07-29  
**Agent:** W30-M OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005aed20`, `0x005accf0`. Dual A/B + artifacts.  
**Partition:** wave30 (OWN-ONLY dual W30-M).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005aed20` StdMap_InsertOrFindByIntKey_Val12 | **accept-with-gaps** — Val12 int-key insert-or-find; insert via `005ae4e0`; **`ret 8`**; peer of `0053a1a0` (do not merge) |
| `aa_005accf0` CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred | **accept-with-gaps** — leg time = dist/scale×Percent [+5.0]; **`ret 0x14`**; **no static callers** |

---

## `aa_005aed20` — StdMap_InsertOrFindByIntKey_Val12

### Sealed facts

1. **Body:** `0x005aed20`–`0x005aedd8` exclusive (**184** B / `0xB8`). Final **`c2 08 00`** (×3 exits); pad `CC` → `0x005aede0`.

2. **ABI:** `__thiscall` ECX = map (`head` @ +4, `size` @ +8); stack `(InsertPair* out, Val12* value)`; clean **8** B.

3. **Algorithm:**
   ```
   lower_bound walk: key < node.key → left else right; isnil@+0x19
   if addLeft && where == begin: insert(addLeft=1); inserted=1
   else if addLeft: Dec(where); // predecessor
   if where.key < key: insert(addLeft); inserted=1
   else: inserted=0; it=where
   ```

4. **InsertPair:** `it` @ +0; **`inserted` byte @ +4**.

5. **Callees:** `FUN_005ae4e0` (`StdTree_InsertAndRebalance_Val12`, W27-T), `FUN_005ae050` (`StdTree_Dec_Val12`, W29-E).

6. **Callers (2 xrefs):** `FUN_005acf10` @ `005ad0ae` (CrazyTaxi XML dump — TimeLimit populate); `005ada8b` in undefined body ~`005ad2f0` (CrazyTaxi vtable +0x48 parse/load).

7. **Peer:** `aa_0053a1a0` @ `0x0053a1a0` — same role, insert via `0x00539210` — **do not merge**.

8. **Name:** structural `StdMap_InsertOrFindByIntKey_Val12`. Legacy MissionStopLimit alias is **narrow**.

9. **Decompile ≡ raw ≡ live** (W30-M).

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Orphan parse function @ `005ad2f0` not dualed (out of OWN).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005aed20_StdMap_InsertOrFindByIntKey_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005aed20_FUN_005aed20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFindByIntKey_Val12_005aed20.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005aed20.cpp` |
| Raw | `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.md` |
| Annotated | `docs/reconstruction/raw/aa_005aed20_FUN_005aed20.annotated.md` |

---

## `aa_005accf0` — CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred

### Sealed facts

1. **Body:** `0x005accf0`–`0x005acee7` exclusive (**503** B / `0x1F7`); Ghidra plate max `005acee6`. Final **`c2 14 00`**; pad `CC` → `0x005acef0`.

2. **ABI:** `__thiscall` ECX = CrazyTaxi req; stack `(actor*, stopsKey, acc, fromIndex, toIndex)`; clean **20** B (`ret 0x14`); return float (x87 / float10 in decomp).

3. **Algorithm:**
   ```
   scale = actor+0x250 → … → float@+0x634
   src = (fromIndex < 0) ? actor.GetPos(vtbl+0x1a0)
                         : ResolveTFID(this+0x4c[fromIndex]).pos@+0x84
   dest = ResolveTFID(this+0x4c[toIndex])
   if dest:
     dist = SQRT(|src-dest|)
     lower_bound TimeLimit map (this+0x8c, Val12 isnil@+0x19, key=stopsKey)
     if it != begin: Dec(it)
     if it == head: dist /= scale
     else:          dist = (dist/scale) * Percent@+0x14
     acc += dist
   if stopsKey < 1: acc += 5.0f   // DAT_00aaa688
   return acc
   ```

4. **Constant:** `DAT_00aaa688` @ `0x00aaa688` = **5.0f** (`00 00 a0 40`).

5. **Callees:** `FUN_004bb1c0`, `FUN_005ae050`, `SQRT`, actor vtbl `+0x1a0`.

6. **Callers:** **none static** — full-image E8 + absolute pointer scan `0x00400000`–`0x00b00000` found zero refs.

7. **Layout corroboration:** ctor `FUN_005adb20` (type 0xE / maps @ +0x74/+0x80/+0x8c); XML dump `FUN_005acf10` (`TimeLimit` Stops/Percent, `GenericTargetCOID`); RTTI `CVOGObjectiveRequirement_CrazyTaxi`.

8. **Name:** `CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred`.

9. **Decompile ≡ raw ≡ live** (W30-M).

### Gaps

1. Product English / demangled method name.  
2. Zero static callers (dead vs dynamic-only).  
3. TimeLimit bracket policy after Dec (product intent).  
4. Uninit source if `fromIndex >= 0` and TFID miss.  
5. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_005accf0_CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005accf0_FUN_005accf0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005accf0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.md` |
| Annotated | `docs/reconstruction/raw/aa_005accf0_FUN_005accf0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### StdMap_InsertOrFindByIntKey_Val12 (`0x005aed20`)

- Port as **generic Val12 unique insert-or-find by int key**, not MissionStopLimit-specific logic.
- Insert helper is **`0x005ae4e0`** (not `0x00539210` peer).
- Preserve **`ret 8`**; InsertPair `inserted` as **byte @ +4**.
- Do not merge with `aa_0053a1a0` without matching insert helper + callers.
- CrazyTaxi TimeLimit consumer uses key = Stops; Percent lives in value dword @ node+0x14 (owner of payload meaning).

### CVOGObjectiveRequirement_CrazyTaxi_AccumulateLegTime_Inferred (`0x005accf0`)

- Port as **CrazyTaxi leg time budget accumulator**, not generic pathfinding.
- Formula: `acc += (‖Δpos‖ / scale) * Percent` (or unweighted if map miss/end); if `stopsKey < 1` add **5.0f**.
- Stops TFID list @ **`this+0x4c`**; TimeLimit Val12 map head @ **`this+0x8c`**.
- `fromIndex < 0` means use **actor world position** (vtbl+0x1a0), not a stop index.
- **No static callers found** — verify before wiring into mission eval; may be residual/dead.
- Preserve **`ret 0x14`**.

---

## Notes

- Tools used: `decompile_function`, `read_memory`, `get_function_by_address`, `get_function_callers` / `get_function_callees`, `get_xrefs_to`, `analyze_function_complete`, full-image call/ptr scan via Ghidra HTTP `read_memory`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W30-M only for these two VAs.
- Did not write artifacts for non-owned helpers (`005ae4e0` dualed W27-T; `005ae050` dualed W29-E; `004bb1c0` dualed W18-T; `005acf10` / `005adb20` / `005ad2f0` / `005aca60` out of ownership).
