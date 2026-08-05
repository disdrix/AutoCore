# Dual A/B report — W18-H OWN-ONLY (`0x004c41c0`, `0x0094a6a0`)

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W18-H  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x004c41c0`, `0x0094a6a0` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta / callers / xrefs). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x004c41c0` | `Creature_GetPerception` | **accept-with-gaps** |
| `0x0094a6a0` | `Client_InitInstance` | **accept-with-gaps** |

---

## VA `0x004c41c0` — Creature_GetPerception

### Sealed facts

1. **ABI:** leaf-style `__fastcall` / thiscall — creature in **ECX** (`push esi; mov esi,ecx`); **int** in **EAX**; plain `RET`. Body `0x004c41c0`–`0x004c428e`.
2. **CF:**
   ```
   score = min(min(int16(this+0x142), 200) + int16(this+0x14a), 250)
   thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
   return max(score, thr)   // thr < score ? score : thr
   ```
3. **Constants:** base cap **200**, score cap **250**, thr encode mask **0x65** / offset **-100**, vtbl slot **0x1DC**.
4. **Product name:** **"Perception"** — UI caller `FUN_00845360` uses `FUN_007a6de0("Perception")` with this getter; debug dump packs **P**.
5. **Siblings (pattern only):** Combat `004c4070` (same thr shape on `+0x13e/+0x146`); Theory `004c4140` thr-less floor-1 on `+0x140/+0x148`.
6. **Static callees:** none; **two** identical indirect vtbl calls (not CSE).
7. **Callers (12):** UI Perception, req gates, debug dump, cast-autohit residual, etc.
8. **Live decompile ≡** 2026-07-23 raw body (no CF delta).

### Gaps

1. DB/wire English for shorts at `+0x142` / `+0x14a`.  
2. Product English for `vtbl+0x1DC` probe.  
3. Runtime dump vs formula (vehicle vs on-foot).  
4. Discarded-return residual at `Skill_NonCreatureCastAutoHit` (parent unit).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004c41c0_Creature_GetPerception.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004c41c0_Creature_GetPerception.md` |
| Function record | `docs/reconstruction/functions/aa_004c41c0_Creature_GetPerception.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Creature_GetPerception.cpp` |
| Clean (Ghidra name) | `docs/reconstruction/reconstructed-exact/FUN_004c41c0.cpp` |
| Raw named | `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.md` |
| Annotated named | `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_004c41c0_FUN_004c41c0.md` |

**Sibling context (not owned):** `FUN_004c4070` Combat, `FUN_004c4140` Theory, `FUN_00845360` UI requires, `Client_DebugDumpEntityCombatStats` `0x00955eb0`.

---

## VA `0x0094a6a0` — Client_InitInstance

### Sealed facts

1. **ABI:** **`__stdcall`**, one stack arg (client app); success **`return 1`**; exit **`RET 4`**. Body `0x0094a6a0`–`0x0094b324`.
2. **Product identity:** banners `"Client InitInstance"` / `"@@Finish of InitInstance"` / `"InitInstance::done"`.
3. **Sole static caller:** `FUN_0094ba40` → `Client_InitInstance(&DAT_00d1a840)`.
4. **Role:** full client boot orchestration (crypto, COM, render, map, assets, clonebase, optional tables, physics, generators, sound, UI) — **not** table-only.
5. **Gate `app+0x31f5`:** when **0**, runs table ensure batch + map generators + extra asset post-init; when **nonzero**, skips those.
6. **Hard fail:** `InitRenderEngine` (`FUN_00948530`) nonzero → log → **`_exit(1)`**.
7. **Live decompile ≡** 2026-07-23 raw body (no CF delta).

### Gaps

1. Product C++ class for client app / `DAT_00d1a840`.  
2. English for flag `+0x31f5`.  
3. Full manager class English inventory.  
4. Whether non-developer entry uses a twin (residual on **caller** tree).  
5. Runtime phase timing.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0094a6a0_Client_InitInstance.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0094a6a0_Client_InitInstance.md` |
| Function record | `docs/reconstruction/functions/aa_0094a6a0_Client_InitInstance.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InitInstance.cpp` |
| Clean (Ghidra name) | `docs/reconstruction/reconstructed-exact/FUN_0094a6a0.cpp` |
| Clean (legacy named) | `docs/reconstruction/reconstructed-exact/Named_Client_InitInstance_0094a6a0.cpp` |
| Raw named | `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.md` |
| Annotated named | `docs/reconstruction/raw/aa_0094a6a0_Client_InitInstance.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_0094a6a0_FUN_0094a6a0.md` |

**Sibling context (not owned):** caller `FUN_0094ba40`; gated ensures (`EnsureQuest*`, `Experience_*`, `FUN_00519660`, `FUN_005129b0`); `NDXml_GetLoaderSingleton` `0x007b6a20`.

---

## Dual A/B summary

| VA | Review A | Review B | Agreement |
|---|---|---|---|
| `0x004c41c0` | accept-with-gaps | accept-with-gaps | CF/thr/Perception sealed; reject Theory-leaf / TargetAccuracy-only misreads |
| `0x0094a6a0` | accept-with-gaps | accept-with-gaps | InitInstance phase map sealed; reject table-only / wrong-ABI misreads |

---

## Evidence tools used (both VAs)

- `decompile_function`
- `read_memory` (entry + tails)
- `get_function_by_address` (body bounds)
- `analyze_function_complete` (callers/callees/xrefs)
- `get_function_callers`
- Context decompiles of callers / siblings (**read-only**, no writes outside owned VAs)

**Not used:** `disassemble_bytes`, Launcher, parent ledgers.
