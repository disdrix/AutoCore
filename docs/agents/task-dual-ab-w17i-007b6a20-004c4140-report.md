# Dual A/B report — W17-I OWN-ONLY

**Date:** 2026-07-29  
**Agent:** W17-I  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**Owned VAs:** `0x007b6a20`, `0x004c4140` **only**  
**Tools:** Ghidra `decompile_function` + `read_memory` (+ function meta / callers / xrefs). **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits (`ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER` / `WORK_QUEUE` / `RESUME`).

---

## Verdicts

| VA | Canonical name | Verdict |
|---|---|---|
| `0x007b6a20` | `NDXml_GetLoaderSingleton` | **accept-with-gaps** |
| `0x004c4140` | `Creature_GetTheory` | **accept-with-gaps** |

---

## VA `0x007b6a20` — NDXml_GetLoaderSingleton

### Sealed facts

1. **ABI:** no stack args; plain `RET`; return **pointer in EAX** = `&DAT_00d20c38`.
2. **Body:** `0x007b6a20`–`0x007b6a82`. Entry FS:[0] SEH; exit `ADD ESP,0xC; RET`.
3. **Role:** Meyers **singleton getter** for process-static NDXml path-loader object.
4. **Once guard:** `DAT_00d20c48` bit 0 (adjacent BSS, not consumer field of returned object).
5. **First-call init:**
   - `+0x00` vtbl = `PTR_FUN_00a95b88` (slot0 scalar dtor `FUN_004239a0`)
   - `+0x04` flags = `1` (search-path bit for `NDXml_LoadDocumentFromPath`)
   - `+0x08` = `0`, `+0x0c` = `0`
   - `_atexit(LAB_009c3040)`
6. **Always** returns `&DAT_00d20c38` after optional init.
7. **Primary chain:** `NDXml_OpenTaggedDocument` → **this** → `NDXml_LoadDocumentFromPath(loader, doc, path)`.
8. **Callers:** 50+ (UI, terrain image/tint, creature graphics, FX, etc.).
9. **Live decompile ≡** 2026-07-23 raw body (no CF delta).

### Gaps

1. Full product class English name / remaining vtable slots.  
2. `+0x08` / `+0x0c` field English beyond zero-init.  
3. Runtime / image-diff.  
4. Multi-thread first-call race (classic unprotected Meyers).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| Function record | `docs/reconstruction/functions/aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDXml_GetLoaderSingleton.cpp` |
| Clean (Ghidra name) | `docs/reconstruction/reconstructed-exact/FUN_007b6a20.cpp` |
| Raw named | `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.md` |
| Annotated named | `docs/reconstruction/raw/aa_007b6a20_NDXml_GetLoaderSingleton.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_007b6a20_FUN_007b6a20.md` |

**Sibling context (not owned):** `NDXml_LoadDocumentFromPath` `0x007b6c70`, `NDXml_OpenTaggedDocument` `0x007999c0`, basename/helpers `0x007b6420` / `0x007b66c0` (W17-L / W17-M).

---

## VA `0x004c4140` — Creature_GetTheory

### Sealed facts

1. **ABI:** leaf `__fastcall` / thiscall — creature in **ECX**; **int** in **EAX**; plain `RET`. Body `0x004c4140`–`0x004c41bb`.
2. **Entry:** `66 8B 81 40 01 00 00` = `mov ax, [ecx+0x140]`.
3. **CF:**
   ```
   clamp(min(int16(this+0x140), 200) + int16(this+0x148), 1, 250)
   ```
4. **Constants (immediates):** base cap **200**, min return **1**, max return **250** (`0xFA`).
5. **Product name:** **"Theory"** — UI caller `FUN_00845360` uses `FUN_007a6de0("Theory")` with this getter.
6. **Siblings (pattern only):** Combat `004c4070` (`+0x13e/+0x146`), Perception `004c41c0` (`+0x142/+0x14a`). Those add vehicle floor via vfunc `+0x1dc`; **Theory does not** (leaf, no calls).
7. **Accuracy chain:** `Skill_AccuracyScore_Inferred` (`0x005531d0`) → `(float)Creature_GetTheory(creature)` as attacker bonus → `Skill_NonCreatureCastAutoHit`.
8. **Callers (10):** accuracy, UI Theory, req gates, pool-related, etc.
9. **Live decompile ≡** 2026-07-23 raw body (no CF delta).

### Gaps

1. DB/wire English for shorts at `+0x140` / `+0x148` (base vs bonus is structural Probable).  
2. Why Theory lacks vehicle floor present on Combat/Perception.  
3. Runtime dump vs formula.  
4. Design scale of Theory-as-accuracy-bonus (points vs normalized).

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004c4140_Creature_GetTheory.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004c4140_Creature_GetTheory.md` |
| Function record | `docs/reconstruction/functions/aa_004c4140_Creature_GetTheory.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Creature_GetTheory.cpp` |
| Clean (Ghidra name) | `docs/reconstruction/reconstructed-exact/FUN_004c4140.cpp` |
| Raw named | `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.md` |
| Annotated named | `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.annotated.md` |
| Raw scaffold + re-verify append | `docs/reconstruction/raw/aa_004c4140_FUN_004c4140.md` |

**Sibling context (not owned):** `FUN_004c4070` (W17-O), `FUN_004c41c0`, `Skill_AccuracyScore_Inferred` `0x005531d0`, `Skill_NonCreatureCastAutoHit` `0x004ceba0`.

---

## Dual A/B summary

| VA | Review A | Review B | Agreement |
|---|---|---|---|
| `0x007b6a20` | accept-with-gaps | accept-with-gaps | CF/singleton sealed; reject VOG-ini-only scaffold name |
| `0x004c4140` | accept-with-gaps | accept-with-gaps | CF/Theory sealed; reject debug-only / float-probability misreads |

---

## Evidence tools used (both VAs)

- `decompile_function`
- `read_memory` (entry + tails + related globals/vtable)
- `get_function_by_address` (body bounds)
- `analyze_function_complete` (callers/callees/xrefs)
- `get_function_callers`
- Context decompiles of callers / siblings (**read-only**, no writes outside owned VAs)

**Not used:** `disassemble_bytes`, Launcher, parent ledgers.
