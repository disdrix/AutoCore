# Dual A/B report — WQ9F-J OWN-ONLY (`aa_00553cd0`, `aa_0051d940`)

**Date:** 2026-08-04  
**Agent:** WQ9F-J OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00553cd0`, `0x0051d940`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-3 residual dual seal (world-clock sibling + map neighborhood residual).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` / `analyze_function_complete` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-J**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00553cd0` WorldClock_GetSkyBlendAmount_Inferred | **accept-with-gaps** — ECX/`fld [+0x15c]`/bare ret/sole env caller sealed; product English open |
| `aa_0051d940` Map_EraseRange_Isnil15_B | **accept-with-gaps** — range erase CF/ABI/isnil@+0x15/free-twin sealed; K/V English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; collapse into siblings rejected; skill-cast names rejected.

---

## Sealed facts — `0x00553cd0` WorldClock_GetSkyBlendAmount_Inferred

1. **Body:** `0x00553cd0`–`0x00553cd6` (**7 B** inclusive); `CC` pad; next at `0x00553ce0`.

2. **Bytes:** `D9 81 5C 01 00 00 C3` = **`fld dword ptr [ecx+0x15c]; ret`**.

3. **ABI:** ECX = **clock host** (same object as dualed `WorldClock_GetQuarterPhase01_Inferred`); result on **x87 ST0**; **no stack args**; bare **`C3`**.

4. **Role:** pure **load** of stored **f32** at **`this+0x15c`**. Not phase math (that is sibling `0x00553dd0` / cache `+0x24`).

5. **Caller (1):** `FUN_004912c0` @ `0x004912e5` — env day-cycle consumer.  
   - Defaults to `g_flOne` when clock missing.  
   - Feeds return value into `FUN_00490af0` as material **`fBlendAmount`** on SkyBox / SkyBoxCloud / SkyBoxForeground.  
   - Also gates `FUN_00490820` when value ≥ 1.0.

6. **Name:** `WorldClock_GetSkyBlendAmount_Inferred` — role **High** (stored sky blend scalar via sole consumer); product English **Inferred**.

7. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `00553cd0`

1. Product/PDB clock class and field English.  
2. Writers of `+0x15c`.  
3. Runtime / bit-exact open.

---

## Sealed facts — `0x0051d940` Map_EraseRange_Isnil15_B

1. **Body:** `0x0051d940`–`0x0051d9f3` (**180 B** exclusive pad); `CC` pad; next at `0x0051da00`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = map (`head@+4`, `size@+8`)  
   - stack `(void **out_it, node *first, node *last)`  
   - **`ret 0x0c`** (`C2 0C 00`) at full-clear and partial exits  

3. **Identity:** MSVC map/set **range erase** for small-node family **`isnil@+0x15`**. Twin of dualed `Map_EraseRange_Isnil15` (`0x0051d7c0`).

4. **Full-range fast path** when `first == *head && last == head`:  
   - **`FUN_0051bed0(head->parent)`** free tree (**discriminator** vs twin free `FUN_0051be50`)  
   - reset head parent/left/right to head; `size = 0`  
   - `*out_it = *head`  

5. **Partial path:** while `first != last`:  
   - inline tree successor (isnil@+0x15)  
   - **`FUN_0051ce00(map, &first, node)`** — shared with twin; STL `"invalid map/set<T> iterator"`  
   - bytes restore `ECX = map` before call (decomp plate omits formal)  
   - advance to precomputed successor; `*out_it = first`  

6. **Callers:** map host complete dtor **`FUN_0051e1b0`** @ `0x0051e1c2` only (`xref_count=1`).

7. **Name:** `Map_EraseRange_Isnil15_B` — keep distinct from `Map_EraseRange_Isnil15`.  
   **Reject:** merge with isnil@+0x29 `Map_EraseRange` / `_B`; identity with `StdMap_EraseRange_Inferred`.

8. **Live ≡ raw CF** (2026-08-04 re-verify).

### Gaps — `0051d940`

1. Value-type / size reason for second isnil@+0x15 instantiation (shared erase, different free).  
2. Free-subtree `FUN_0051bed0` dual open.  
3. Host class English for `FUN_0051e1b0`.  
4. Runtime / bit-exact open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00553cd0` | `reviews/A_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` | `reviews/B_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` | **accept-with-gaps** |
| `0x0051d940` | `reviews/A_aa_0051d940_Map_EraseRange_Isnil15_B.md` | `reviews/B_aa_0051d940_Map_EraseRange_Isnil15_B.md` | **accept-with-gaps** |

---

## Files

### `aa_00553cd0` / `WorldClock_GetSkyBlendAmount_Inferred`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00553cd0_WorldClock_GetSkyBlendAmount_Inferred.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_00553cd0_FUN_00553cd0.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/WorldClock_GetSkyBlendAmount_Inferred.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_00553cd0.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00553cd0_FUN_00553cd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00553cd0_FUN_00553cd0.annotated.md` |

### `aa_0051d940` / `Map_EraseRange_Isnil15_B`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051d940_Map_EraseRange_Isnil15_B.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051d940_Map_EraseRange_Isnil15_B.md` |
| Function record | `docs/reconstruction/functions/aa_0051d940_Map_EraseRange_Isnil15_B.md` |
| Scaffold alias | `docs/reconstruction/functions/aa_0051d940_FUN_0051d940.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Map_EraseRange_Isnil15_B.cpp` |
| Clean FUN_* | `docs/reconstruction/reconstructed-exact/FUN_0051d940.cpp` |
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051d940_FUN_0051d940.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d940_FUN_0051d940.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00553cd0-0051d940-wq9fj-report.md` |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00553dd0` | `WorldClock_GetQuarterPhase01_Inferred` — sibling phase leaf on same clock |
| `0x004912c0` | env day-cycle consumer of both clock leaves |
| `0x00490af0` / `0x00490820` | sky `fBlendAmount` / texture apply (consumer chain) |
| `0x0051d7c0` | `Map_EraseRange_Isnil15` — twin (free `FUN_0051be50`) |
| `0x0051bed0` | free-subtree for owned full clear |
| `0x0051ce00` | single-node erase (shared with twin; STL throw string) |
| `0x0051e1b0` | map host complete dtor calling owned unit |
| `0x0051c7c0` / `0x0051d880` | `Map_EraseRange` / `_B` (isnil@+0x29 family) |
| `0x004bacf0` | `StdMap_EraseRange_Inferred` (isnil@+0x15; different free/erase VAs) |

---

## AutoCore impact

### `WorldClock_GetSkyBlendAmount_Inferred`

- Port as pure **`float` load of clock+0x15c`** (x87 ST0 / C++ return).  
- Keep distinct from quarter-phase getter (`+0x24` cache / live time math).  
- Env consumer uses value as sky **`fBlendAmount`** with default **1.0** when clock absent.  
- Not combat / skill accuracy.

### `Map_EraseRange_Isnil15_B`

- Client STL helper. Ports use standard `map::erase(first, last)` / container clear — preserve full-range fast path and successor-before-erase loop.  
- Do **not** omit `ECX = map` on single-node erase (decomp trap).  
- Do **not** merge with `Map_EraseRange_Isnil15`; free-subtree callees differ (`bed0` vs `be50`) even though partial erase is shared (`FUN_0051ce00`).  
- Distinct from isnil@+0x29 `Map_EraseRange` family and from `StdMap_EraseRange_Inferred`.  
- Skill residual **container** helper only (map host teardown).

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` and/or environment system notes  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).
