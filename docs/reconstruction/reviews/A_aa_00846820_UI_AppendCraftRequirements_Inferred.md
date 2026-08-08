# Review A (reconstruction fidelity): `aa_00846820` UI_AppendCraftRequirements_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00846820` |
| **VA** | `0x00846820` |
| **Body span** | `00846820` – `00847232` (**4115** bytes / `0x1013`) |
| **Canonical name** | `FUN_00846820` (Ghidra) |
| **Proposed name** | `UI_AppendCraftRequirements_Inferred` (**High** role) |
| **Rejected alias** | `Named_Required_Combat_00846820` — Combat is one line only |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **R11-028**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_00846820_UI_AppendCraftRequirements_Inferred.md` |
| **System** | skills-abilities / client craft UI requirements |
| **Parent (partition)** | `0x0051f940` LookupClassDisplayName_Inferred (class line only) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI helper that builds a **craft/recipe requirements** text block:

1. Gate on local player presence (`DAT_00d1b6d8`).
2. Optionally append **INGREDIENTS** (def object-id slots) and **ENHANCEMENT INGREDIENTS** (recipe-prefix rows).
3. Optionally append **Discipline**, **Required Faction/Class**, four stat requirements, **Required Level**.
4. Color section headers green (`0xff20ff20`); failed player checks red (`0xffff2020`).
5. Return **line count** (0 if no player).

**ABI:** UI text in **ESI**; stack craftable/item object*; plain `ret`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw (+ R11 re-verify) | `docs/reconstruction/raw/aa_00846820_FUN_00846820.md` |
| Annotated | `docs/reconstruction/raw/aa_00846820_FUN_00846820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00846820.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/UI_AppendCraftRequirements_Inferred.cpp` |
| Function records | `docs/reconstruction/functions/aa_00846820_FUN_00846820.md`, `aa_00846820_UI_AppendCraftRequirements_Inferred.md` |
| Sibling (context) | `UI_AppendItemRequirements` `0x00845360` |
| Parent (context) | `LookupClassDisplayName_Inferred` `0x0051f940` |
| Stat getters | Combat `004c4070`, Theory `004c4140`, Perception `004c41c0`, Tech `004c3ff0` |

**This pass (live):** `decompile_function` @ `0x00846820`; `analyze_function_complete`; `disassemble_function`; `read_memory` entry/epilogue + product strings; `get_function_by_address`; call graph; xrefs (empty); `audit_globals_in_function`; `batch_decompile` of `00599dd0` / `005097b0` / `004ce940`. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits, other VAs.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span / SEH `LAB_009ac516` / `sub esp,0x19c` / plain ret | **High** | entry + epilogue bytes + `get_function_by_address` |
| UI text in **ESI** (not saved) | **High** | disasm uses ESI from first ingredients store; never written |
| Stack arg = item/craft object | **High** | `mov ebp,[esp+0x1b0]`; `+0xa8` def chain |
| Local player gate → return 0 | **High** | entry `cmp [DAT_00d1b6d8],0` |
| Product section strings | **High** | `read_memory` + globals audit |
| Ingredient slots def `+0x498..+0x4a8` + `FUN_00599dd0` | **High** | callee decompile + loop |
| Enhancement via `FUN_005097b0` recipe rows | **High** | callee has GetTypelessRecipe / IDPrefix strings |
| Discipline `+0x4ac`/`+0x4b0` + balance | **High** | disasm + `FUN_0052b040`/`0052ada0` |
| Faction/class/stat/level lines + colors | **High** | product strings + shared getters |
| Return = line count | **High** | counter at stack; epilogue `mov eax,[esp+0xc]` |
| Header color `0xff20ff20` | **High** | immediate push |
| Fail color `0xffff2020` | **High** | immediate push |
| Level cap 80 (`0x50`) | **High** | compare/clamp in disasm |
| Static callers | **Open** | Ghidra xrefs empty |
| Product C++ method symbol | **Probable** | role High; symbol open → `_Inferred` |
| Runtime tooltip golden | **Open** | not run |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| SEH + frame + player gate | **Yes** |
| Ingredient count + INGREDIENTS header/loop | **Yes** |
| Enhancement header/nested loops | **Yes** |
| Discipline block | **Yes** |
| Faction / class / four stats / level | **Yes** |
| Multi-exit plain ret family | **Yes** |

### 4.1 Requirement layout

| Offset | Use |
|--------|-----|
| item `+0xa8` → `+0x3c` | def* |
| def `+0x498..+0x4a8` | ingredient object ids (5 slots, -1 empty) |
| def `+0x4ac` / `+0x4b0` | discipline type / threshold |
| def vfunc `+0x14` | race id (-1 none) |
| def `+0x3e0` | class id (-1 none) |
| def `+0x3fe` | Combat req short |
| def `+0x400` | Perception |
| def `+0x402` | Tech |
| def `+0x404` | Theory |
| item `+0xe8`, `+0xea` | level shorts (sum; cap 80) |
| item vfunc `+0x5c` / `+0x60` | enhancement get / count |

### 4.2 Player compare sources

| Line | Player source |
|------|----------------|
| Level | vfunc `+0x27c` on local player component chain |
| Faction/race | byte `@ creature+0x532` |
| Class | byte `@+0x531` |
| Combat | `FUN_004c4070` |
| Perception | `FUN_004c41c0` |
| Tech | `Character_GetTechForPoolCalcs(DAT_00d1b6d8)` |
| Theory | `FUN_004c4140` |
| Discipline | `FUN_0052ada0(type)` vs threshold |

---

## 5. Callers

Live Ghidra: **none recovered**. Absolute address not present as data pointer. Relative CALL inventory open. Sibling string reuse inside `UI_BuildItemTooltipStats` (`0x00847ad0`) is **inline duplicate**, not a call to this VA.

---

## 6. Gaps / open

1. Product C++ method / UI class owning text vfuncs.
2. Static caller inventory.
3. English of `DAT_00d1b6d8+0x6b4` qty gate (debug/show-amounts flag).
4. Exact English of "Required Faction" vs race table (`FUN_0051f8e0`).
5. Runtime capture / differential.
6. Full bit-exact clean body (stage stub + raw decompile; assembly-sealed notes authoritative for ABI).

**Verdict:** **accept-with-gaps** — ABI, stages, field map, product strings, colors, getters sealed static; callers / product symbol / runtime open.
