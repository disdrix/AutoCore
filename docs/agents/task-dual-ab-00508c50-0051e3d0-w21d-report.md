# Dual A/B report — W21-D OWN-ONLY (`0x00508c50`, `0x0051e3d0`)

**Date:** 2026-07-29  
**Agent:** W21-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00508c50`, `0x0051e3d0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00508c50` HandlerTable58_FindById6c | **accept** — **leaf linear find-by-id @ +0x58 / DAT_00d02984 / entry+0x6c; ret 4 sealed** |
| `aa_0051e3d0` CNDHash_Insert_009ce0a0 | **accept** — **thiscall ret 0xC CNDHash insert; node vtbl 009ce0a0; HRESULTs sealed** |

---

## `aa_00508c50` — HandlerTable58_FindById6c

### Sealed facts

1. **Body:** `0x00508c50`–`0x00508c91` exclusive (**65** B / `0x41`). Final **`c2 04 00`** both exits; following `cc` pad.

2. **ABI:** **`__thiscall`** — ECX=registry*; stack: `int32 id`. **`ret 4`**.

3. **Algorithm:**
   ```
   if id == -1 or DAT_00d02984 <= 0: return null
   table = *(entry***)(registry + 0x58)
   for i in [0, DAT_00d02984):
     if *(int32*)(table[i] + 0x6c) == id: return table[i]
   return null
   ```

4. **Callees:** none (leaf).

5. **Callers:** 12 sites / 8 functions — `FUN_004fe380` (Vehicle_ApplyItemStatusHooksOnEquip), loot GetTypeFromIDPrefix family (`005092b0`…`00509940`), `FUN_00513580`.

6. **Family twin:** `HandlerTable54_FindById6c` (`0x00508c00`) — table **`+0x54`** / count **`DAT_00d02988`**. Equip dual maps this unit to subtype **0xa** (10); twin to subtype **0xb**.

7. **Name:** structural `HandlerTable58_FindById6c`. Auto-seed `Named_CalleeOf_…Skill_GetModifier…` is **misleading**.

### Gaps

1. Product/PDB symbol spelling.  
2. Loader for `+0x58` / `DAT_00d02984`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00508c50_HandlerTable58_FindById6c.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00508c50_HandlerTable58_FindById6c.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00508c50_HandlerTable58_FindById6c.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00508c50_HandlerTable58_FindById6c.md` |
| Function record | `docs/reconstruction/functions/aa_00508c50_HandlerTable58_FindById6c.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00508c50_FUN_00508c50.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HandlerTable58_FindById6c.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00508c50.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c50.cpp` |
| Raw | `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00508c50_FUN_00508c50.annotated.md` |

---

## `aa_0051e3d0` — CNDHash_Insert_009ce0a0

### Sealed facts

1. **Body:** `0x0051e3d0`–`0x0051e4c7` exclusive (**247** B / `0xF7`). Final **`c2 0c 00`** (`ret 0xC`) all exits; following `cc` pad.

2. **ABI:** **`__thiscall`** — ECX=CNDHash*; stack: `uint key`, `void *value`, `char softIfExists`. **`ret 0xC`**.

3. **Returns:**
   | EAX | Meaning |
   |---|---|
   | `0` | inserted |
   | `1` | soft: key present (`softIfExists != 0`) |
   | `0x80004003` | null value (`E_POINTER`) |
   | `0x80004005` | hard duplicate (`E_FAIL`) |

4. **Lock:** `this+0x1d` non-zero → log `"HashError:insert, already locked for traversal"` + `"VOG_DEBUG_STOP"`; **continue** (does not abort).

5. **Soft path:** if soft flag and `CNDHash_LookupByKey` hits → return **1** without mutation. Hard path logs `"Duplicate hash insert %u, failing out"`.

6. **Alloc / link:** freelist at **`this+0x20`** → `FUN_0053ada0`; node vtbl **`0x009ce0a0`**; bucket head-insert; `FUN_00537d30`; list append; `count++`.

7. **Callees:** `FUN_007a4480`, `CNDHash_LookupByKey`, `FUN_0053ada0`, `FUN_00537d30`.

8. **Callers:** `FUN_00519a30` only — 3 sites, `softIfExists=0`.

9. **Twins (same CF, different vtbl/VA):** `CNDHash_Insert_009ce0a8` (`0x0051e4d0` / `009ce0a8`); `CNDHash_Insert` (`0x0053c560` / `009cefd4`). **Do not merge.**

10. **Name:** structural `CNDHash_Insert_009ce0a0`. Auto-seed `Named_VOG_DEBUG_STOP_0051e3d0` is **misleading**.

### Gaps

1. Product specialty / hosted value type for vtbl `009ce0a0`.  
2. Full freelist + integrity dual units.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| Function record | `docs/reconstruction/functions/aa_0051e3d0_CNDHash_Insert_009ce0a0.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0051e3d0_FUN_0051e3d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Insert_009ce0a0.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0051e3d0.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0051e3d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e3d0_FUN_0051e3d0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### HandlerTable58_FindById6c (`0x00508c50`)

- Port as **linear table find-by-id** on registry slot **`+0x58`**, not a hash map.
- Match field is **`entry+0x6c`**; count is global **`DAT_00d02984`** (not `this`).
- Distinct from `HandlerTable54_FindById6c` (`+0x54` / `DAT_00d02988`) — equip subtype **0xa** vs **0xb**.
- Reject `id == -1`; return **entry pointer** or null; **`ret 4`**.

### CNDHash_Insert_009ce0a0 (`0x0051e3d0`)

- Port as **CNDHash insert** with node vtbl **`009ce0a0`** — do not substitute twin inserts.
- Preserve **soft-skip-if-exists** (return 1) vs hard dup (`0x80004005`) vs null (`0x80004003`).
- Lock at `+0x1d` is **log-only**.
- Alloc via freelist at **`this+0x20`**, not CRT `new`.
- Wire only through known caller `FUN_00519a30` / correct hash instance — not medal twin (`0051e4d0`).

---

## This report

`docs/agents/task-dual-ab-00508c50-0051e3d0-w21d-report.md`
