# Dual A/B report — W32-I OWN `aa_005441d0` + `aa_00556b10`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-I  
**Scope:** VAs `0x005441d0`, `0x00556b10` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` / callers/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave32_partition_map.md` → **W32-I**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005441d0` GuardedVector_InsertRange_Thiscall | **accept-with-gaps** — ECX dest + `RET 0x1C` + shorter-side insert-range CF + thiscall push pair sealed; 7th stack formal map + product English open |
| `aa_00556b10` Weather_NfxListFillOrActivate_Inferred | **accept-with-gaps** — ECX host + `RET 0xC` + clear/mode0 fill/`_nfx.xml`/mode1 activate sealed; product English + unowned apply helper open |

---

## VA `0x005441d0` — sealed facts

1. **Body:** `0x005441d0`–`0x00544587` exclusive (**951 B** / `0x3B7`); terminal **`C2 1C 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; **ECX = dest** (`MOV ESI,ECX`); **7 stack formals** cleaned by **`RET 0x1C`**. Decompiler shows 6 stack + ECX; copy-ctor site pushes 7.
3. **Semantics:** GuardedVector **insert range** `[first,last)` at absolute `insert_at`:
   - `prefix = insert_at - begin`; `suffix = size - prefix`; `n = last - first`.
   - **Front-biased** (`prefix < suffix`): room via `GuardedVector_PushFront_Thiscall` (`0043e3d0`); assign via `FUN_0043ec50`.
   - **Back-biased**: room via `GuardedVector_PushBack_Thiscall` (`0043d670`); backward shuffle `FUN_0043ebb0` when `suffix ≥ n`.
   - SEH `LAB_009a4170`.
4. **Layout:** `+0x04` pages, `+0x08` capacity, `+0x0c` begin, `+0x10` size (family).
5. **Classification:** worker.
6. **Callers (1 / 1 xref):** `FUN_00545190` @ `005451de` — zero dest header, insert full `[src.begin, src.begin+src.size)` at 0.
7. **Name:** `GuardedVector_InsertRange_Thiscall` (Ghidra `FUN_005441d0`; **Inferred** structural; sibling of W29-A InsertN + W31-I push pair).
8. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23).
9. **Entry/exit hex sealed** via `read_memory` (see raw append).

### Gaps

- Product/PDB class English.  
- Exact map of stack formal #0 vs residual 7th push.  
- Nested product names for `0043ec50` / `0043ebb0`.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005441d0_GuardedVector_InsertRange_Thiscall.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005441d0_GuardedVector_InsertRange_Thiscall.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005441d0_FUN_005441d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_InsertRange_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005441d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005441d0_FUN_005441d0.md` |
| Function named | `docs/reconstruction/functions/aa_005441d0_GuardedVector_InsertRange_Thiscall.md` |

---

## VA `0x00556b10` — sealed facts

1. **Body:** `0x00556b10`–`0x00556ce2` exclusive (**466 B** / `0x1D2`); terminal **`C2 0C 00`**; pad `CC`.
2. **ABI:** **ECX = weather host**; stack `(GuardedVector* outList, weatherObj*, mode)`; **`RET 0xC`**.
3. **Prologue:** `SUB ESP,0x108`; clear **outList** via `FUN_0043d650(0)` (resize-to-0); host saved from entry ECX.
4. **mode == 0 (fill):** resolve weather name (`weather+0x558` path via `FUN_00555660`) and TOD name (`FUN_00553ce0`); if name lacks `"_nfx.xml"`, append `DAT_009ca184`; if resource open (`007b6a20`/`007b6730`), `FUN_00989e00` + `GuardedVector_PushBack_Thiscall` (`0043d670`).
5. **mode != 0 (activate):** `FUN_00555600` / `FUN_00553d20` (weather FX load; sibling string `"Failed to load weather FX"`) then `FUN_004b88e0(...,1,0,0)`.
6. **Constant:** `0x009ca184` = `"_nfx.xml"` (`5f 6e 66 78 2e 78 6d 6c 00`).
7. **Callers (1 / 2 xrefs):** `FUN_005575c0` @ `005577c8` (mode 0, list `host+0x190`) and `00557851` (mode 1, list `host+0x1a4`).
8. **Name:** `Weather_NfxListFillOrActivate_Inferred` (Ghidra `FUN_00556b10`; plate residual `Named_nfx_00556b10`).
9. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product English for weather host / list fields `+0x190`/`+0x1a4`.  
- Full unowned `FUN_004b88e0` apply semantics.  
- `FUN_00989e00` product name.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.md` |
| Annotated | `docs/reconstruction/raw/aa_00556b10_FUN_00556b10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weather_NfxListFillOrActivate_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00556b10.cpp` |
| Function | `docs/reconstruction/functions/aa_00556b10_FUN_00556b10.md` |
| Function named | `docs/reconstruction/functions/aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005441d0` | Port as GuardedVector **insert range**: **ECX=dest**, **RET 0x1C**, shorter-side policy. Room via **thiscall** `PushFront`/`PushBack` (W31-I), not EAX W29-B push. Assign via ring forward/backward helpers. Do not reuse `InsertN` (ECX=N, RET 0x10, fill value). Sole known caller is empty-dest full-range copy at index 0. |
| `00556b10` | Port as weather helper: **ECX=host**, stack `(list*, weather*, mode)`, **RET 0xC**. Always **clear list** first. Mode 0: resolve names, **strstr**-gated `_nfx.xml` append (`DAT_009ca184`), push resource ids if open. Mode 1: activate/load weather FX (depends on unowned `004b88e0` / `00553d20`). Caller uses `host+0x190` (fill) and `host+0x1a4` (activate). |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x0043cb00` | `GuardedVector_InsertN` (W29-A) — fill N copies |
| `0x0043e3d0` | `GuardedVector_PushFront_Thiscall` (W31-I) |
| `0x0043d670` | `GuardedVector_PushBack_Thiscall` (W31-I) |
| `0x0043ec50` | ring assign forward |
| `0x0043ebb0` | ring assign backward |
| `0x00545190` | sole caller of insert-range (copy-construct path) |
| `0x005575c0` | sole caller of weather nfx helper |
| `0x00553d20` | weather FX load (`"Failed to load weather FX"`) |
| `0x004b88e0` | apply/collect (unowned; large) |
| `0x009ca184` | `"_nfx.xml"` shared with FxCache / FxMaster paths |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names from sibling family / structural `_Inferred`.  
- Avoid bare `undefined4` in clean (`uint32_t` / `int32_t`).

---

## This report

`docs/agents/task-dual-ab-005441d0-00556b10-w32i-report.md`
