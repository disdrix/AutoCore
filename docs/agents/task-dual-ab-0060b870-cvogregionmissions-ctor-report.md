# Dual A/B report — `aa_0060b870` CVOGRegionMissions_ctor

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x0060b870`. Dual A/B + artifacts. Seal region-missions wrapper ctor.  
**Agent:** W17-B  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0060b870` CVOGRegionMissions_ctor | **accept** — **0x10 four-hash layout + insert this-ptrs + preload/DB dual path sealed** |

---

## Sealed facts

1. **ABI:** `CVOGRegionMissions *__fastcall CVOGRegionMissions_ctor(this)` — **ECX = this**, returns **this** in EAX, MSVC **SEH**, bare **`RET`**.

2. **Body:** `0x0060b870`–`0x0060bb77` (**0x308** bytes).

3. **Product identity:** log path `...\libVOG\VOGRegionMissions.cpp` line `0x33`; OOM `"Out-o-memory... missions!"`.

4. **Layout (0x10 wrapper):**

   | Off | Role |
   |-----|------|
   | `+0x00` | Primary mission-id CNDHash (`new 0x34` + `FUN_0053b0b0(8)`) |
   | `+0x04` | Objective-id CNDHash (`new 0x34` + `FUN_0053b1b0(8)`) |
   | `+0x08` | Extended hash 0x38 (vtbl `009df688`) — key `def[+0x88]` if ≠ -1 |
   | `+0x0C` | Extended hash 0x38 — key byte `def[+0x86]` |

5. **Source dual path:** preload vector `DAT_00b0434c`/`DAT_00b04350` if non-empty; else DB enter `FUN_007e1d80` → `FUN_007c0350` → leave `FUN_007b7df0` + per-row `FUN_005480d0` + COM free.

6. **Insert routing (this-ptr residual closed by bytes):**

   | Hash | Helper | Key |
   |------|--------|-----|
   | `this[0]` | `FUN_0053c360` | `*def` |
   | `this[1]` | `FUN_0053c460` | `obj[+0x10]` |
   | `this[2]` | `FUN_0060c010` | `def[+0x88]` (if ≠ -1) |
   | `this[3]` | `FUN_0060c010` | byte `def[+0x86]` |

7. **Does NOT** `new(0x10)` or store owner `+0xf18` — that is Ensure (`0x0053fff0`).

8. **Name:** `CVOGRegionMissions_ctor` (aliases `Mission_VOGRegionMissions`, `FUN_0060b870`).

---

## Gaps

1. Product English for secondary keys `+0x86` / `+0x88`.  
2. Product names of hash ctor/insert callees.  
3. Runtime OOM continuation after log-only stop; bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0060b870_CVOGRegionMissions_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0060b870_CVOGRegionMissions_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_0060b870_FUN_0060b870.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGRegionMissions_ctor.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0060b870.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_0060b870_FUN_0060b870.md` |
| Annotated | `docs/reconstruction/raw/aa_0060b870_FUN_0060b870.annotated.md` |
| Scratch | `tmp/a_0060b870.md` |
| This report | `docs/agents/task-dual-ab-0060b870-cvogregionmissions-ctor-report.md` |

---

## AutoCore impact

- Port region-mission tables as a **four-hash wrapper**, not a single map.  
- Callers that need mission-id lookup must **`*wrapper`** (or use `+0x00`) after Ensure.  
- Keep Ensure (lazy `new(0x10)` + store `+0xf18`) separate from this ctor.  
- Preload path must remain available for WAD/clonebase-filled vectors; DB cold path is fallback.
