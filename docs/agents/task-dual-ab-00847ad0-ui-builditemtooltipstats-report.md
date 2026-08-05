# Dual A/B report — `aa_00847ad0` UI_BuildItemTooltipStats

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00847ad0`. Dual A/B + artifacts. Seal client item-tooltip **stat-line builder** ABI, type switch, power-plant offsets, return semantics.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/callees/meta. No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = independent fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00847ad0` UI_BuildItemTooltipStats | **accept-with-gaps** — **ABI / switch / plant offsets / line-count return sealed** |

Three-rep: **not required** (A and B agree).

---

## Sealed facts

1. **Role:** Client UI **item tooltip stats** appender. **No** packets, **no** cast, **no** server path.

2. **Body:** `0x00847ad0`–`0x0084af04` (**0x3434** bytes). Large switch + heavy localization/`sprintf`.

3. **ABI:**
   - **ECX** = tooltip host (`this`); saved to **EBX** at entry.
   - Stack: **item\***, **char showDetail**, **char showExtra**.
   - Epilogue **`RET` (`C3`)** — **caller** cleans three stack dwords.
   - **EAX** = **int line count** (decomp `int*` is a cast artifact).

4. **Early exits:**
   - `DAT_00d1b6d8 == 0` → **0**
   - `FUN_00524520` (FindActiveObjectiveIdForInteract) ≠ 0 → append one line, return **1**

5. **Type switch** on `*(*(item + 0xA8) + 0x38)`:
   - Cases: **4, 6, 8, 10, 0xC, 0xE, 0x10, 0x1A, 0x1C, 0x32, 0x34**, **default**
   - Default: `item[+0x17C] |= 0x10` then `FUN_00512670`

6. **Power plant (type 10)** on RTTI-cast object:
   | Off | Field (plate) |
   |----:|---|
   | `+0xB0` | HeatMax |
   | `+0xB4` | PowerMax |
   | `+0xB8` | PowerRegenRate (short) |
   | `+0xBA` | CoolRate (short) |
   - Plate ⅓ display scale: **not** sealed as multiply inside this VA.

7. **Host vfuncs:** `+0x224` append (primary), `+0x250` spacing, plus `+0x22c` / `+0x1b8` in tails.

8. **Callers (4 xrefs / 3 parents):** `FUN_00843a60`, `FUN_0084b890`, `FUN_0088d980` (Drive loading uses `(item,1,0)`).

9. **Constants (this unit uses):** `g_flMsToSeconds` @ `0x00a0f72c` = **0.001f**; `DAT_00a0f298` = **0.5f** (shared pool); `DAT_00aaa664` ≈ **1e-4f** threshold.

10. **Not sealed:** full localization keys, product type enum English, case-6 subtype names, complete 0x3434-byte bit-exact clean, runtime verification.

---

## Gaps

1. Localization key catalog (`FUN_007a6de0`).  
2. Item type / subtype product dictionary.  
3. Power-regen ⅓ scale dataflow (plate vs this body).  
4. RTTI class names for cast branches.  
5. Decompiler noise (false no-return `operator_delete`, unaff registers).  
6. Runtime / diff / bit-exact open.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00847ad0_UI_BuildItemTooltipStats.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00847ad0_UI_BuildItemTooltipStats.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00847ad0_UI_BuildItemTooltipStats.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00847ad0_UI_BuildItemTooltipStats.md` |
| Function record | `docs/reconstruction/functions/aa_00847ad0_UI_BuildItemTooltipStats.md` |
| Clean (named contract) | `docs/reconstruction/reconstructed-exact/UI_BuildItemTooltipStats.cpp` |
| Clean (full scaffold body) | `docs/reconstruction/reconstructed-exact/FUN_00847ad0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.annotated.md` |
| This report | `docs/agents/task-dual-ab-00847ad0-ui-builditemtooltipstats-report.md` |

Legacy: `functions/aa_00847ad0_FUN_00847ad0.md`.

---

## AutoCore impact

- **Client UI only** — no server inventory/combat change.
- Emulate tooltips as type-switch formatters writing into a text host; treat return as **line count** for spacing.
- Power plant UI fields: **B0/B4/B8/BA** on the plant cast body.
- Do not map this VA to equip packets or skill resolution (those are callees/siblings, not this unit’s product).
- Hybrid ABI: ECX this + **caller-cleaned** stack args (`C3`).
