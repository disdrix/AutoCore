# Dual A/B report — WQ9R-G OWN-ONLY (`0x00519d80`, `0x0051a120`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ9R-G  
**Scope:** VAs `0x00519d80`, `0x0051a120` only. Dual A/B + trio + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers / NAMING_REGISTRY / VERIFICATION_MATRIX / systems/*.  
**Ghidra:** `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-G**.

**Domain note:** Wave label is “skill-bank helpers residual.” Live bodies are **not** skill-bank walks — they sit in the `0x00519xxx` game-data / object neighborhood. Accurate systems: **object OnDeath** + **faction table lookup**.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00519d80` Object_OnDeath | **accept-with-gaps** — CF/ABI/`ret 4`/ONDeath string/multi-vtbl/HB+delete-queue paths sealed; demangle + deathCtx English open |
| `aa_0051a120` Faction_LookupById | **accept-with-gaps** — leaf hash CF/ABI/globals/caller faction strings sealed; record field English open |

---

## VA `0x00519d80` — sealed facts

1. **Body:** `0x00519d80`–`0x0051a0db` inclusive; exclusive end **`0x0051a0dc`** (**860 B** / `0x35C`). Final **`C2 04 00`** (`ret 4`); pad `CC`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`this` (`8B F1`); **one stack formal** (deathCtx / non-zero gate; decompiler `unaff_retaddr`); SEH `LAB_009a36ba`.
3. **Semantics — multi-vtbl Object OnDeath:**
   - Resolve owner TFID @ `this+0x40`; host vfunc `+0x210(0)`; optional `FUN_004cdc80` on mismatch.
   - If `(this+0x28 & this+0x2C) != -1` and deathCtx: `FUN_004d2700`; resolve self COID TFID @ `+0x160`.
   - Stamp `this+0x1C = DAT_00b0421c`; `NetObject_SetMaskBits(this+0x14, 8, 0)`.
   - Owner notify (`+0x228/+0x224/+0x54`); optional double-list remove when `this+0x23`.
   - Vfunc `+0x40(1)`; optional `FUN_005b2ba0` if `this+0x64`.
   - Gate: localish vfunc `+0x198` / global `+0x168` / clone type @ `+0x38` ∈ {**1, 3**}:
     - Flag bit12 @ `+0x17c` clear → optional early delete-queue jump if global; else vfunc `+0x2a8` + `FUN_004e77d0(..., mode=1)`.
     - Bit12 set → optional HB: random ushort × **`DAT_009cec58` (≈0.001831f)** → ROUND; `operator_new(0x24)` + `FUN_005dabc0`; `CVOGHBList_Enqueue(world+0xe4ec)`; `CVOGHBBase_Start`; then `+0x2a8` + `FUN_004e77d0(..., mode=0)`.
     - Both complete paths: `*(byte*)(this+0x17d) |= 1`; return 0.
   - Else delete-queue: same death flag bit; if `FUN_004e23d0` InactiveObjects entry non-empty → product log **`ONDeath` … `InactiveObjectsHas`** + `FUN_004bcda0`.
4. **Classification:** worker (multi-vtbl OnDeath).
5. **Callers (CODE 2):** `FUN_0053cf70`, `FUN_00582670` (death FX switch then this).
6. **DATA xrefs (4 vtbl slots):** `0x009ce29c`, `0x009d3414`, `0x009d419c`, `0x009dbc4c` (all store `0x00519d80`).
7. **Related:** `Object_QueueDelete` `0x004d4790` (same warn family, narrower); HB list duals (`CVOGHBList_Enqueue`).
8. **Name:** `Object_OnDeath` (Ghidra `FUN_00519d80`). String-sealed; product demangle open.
9. **Decompile ≡ raw CF**; ABI/size/float sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for owning classes.  
- deathCtx stack formal product name.  
- `FUN_004e77d0` mode 0/1 English; clone type 1 vs 3; flag bit12.  
- Late return status byte (decompiler `unaff_ESI>>24` artifact).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00519d80_Object_OnDeath.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00519d80_Object_OnDeath.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00519d80_FUN_00519d80.md` |
| Annotated | `docs/reconstruction/raw/aa_00519d80_FUN_00519d80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_OnDeath.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00519d80.cpp` |
| Function | `docs/reconstruction/functions/aa_00519d80_FUN_00519d80.md` |
| Function named | `docs/reconstruction/functions/aa_00519d80_Object_OnDeath.md` |

---

## VA `0x0051a120` — sealed facts

1. **Body:** `0x0051a120`–`0x0051a16a` inclusive; exclusive end **`0x0051a16b`** (**75 B** / `0x4B`); pad `CC`.
2. **ABI:** **cdecl**; one stack formal `factionId` (`56 8B 74 24 08`); bare **`C3`** all exits; returns record* in EAX or NULL.
3. **Semantics — faction hash lookup:**
   - If `(int)id < 0` → NULL.
   - If `DAT_00b04320 == 0` → `FUN_005197b0()` (lazy load; owned by WQ9R-F).
   - Bucket: `*(DAT_00b04324 + (DAT_00b0431c & id)*4)`; chain head `*(bucket+4)`.
   - Walk: key `@+0x10`, next `@+0x0C`; hit returns **value `@+0x08`** (pointer, not `*value`).
4. **Classification:** leaf worker.
5. **Callers (2):**  
   - `FUN_00612df0` — miss `"UNKNOWN: %i"`; hit name @ `record+4`; type `*record` 9/10 ⇒ Creatures.  
   - `FUN_00614380` — miss **`"UNDEFINED FACTION: %i"`**; hit name @ `record+4`.
6. **Sibling contrast:** `FUN_00519d20` uses `DAT_00b042b*` and returns `*value`; `FUN_0051a0e0` → `CNDHash_LookupByKey(&DAT_00b042e0,…)`. **Not skill-bank.**
7. **Name:** `Faction_LookupById` (Ghidra `FUN_0051a120`). Reject scaffold `Named_CalleeOf_Drive_Vehicles_0051a120` as too narrow.
8. **Full body bytes** sealed by `read_memory`; clean ≡ raw CF.

### Gaps

- Product record type / RTTI (loader allocates **0x64** bytes).  
- Fields beyond id@0 / name@+4 / secondary string@+0x24 (from loader, not owned).  
- Whether `DAT_00b04320` is count vs ready bool.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051a120_Faction_LookupById.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051a120_Faction_LookupById.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051a120_FUN_0051a120.md` |
| Annotated | `docs/reconstruction/raw/aa_0051a120_FUN_0051a120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Faction_LookupById.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051a120.cpp` |
| Function | `docs/reconstruction/functions/aa_0051a120_FUN_0051a120.md` |
| Function named | `docs/reconstruction/functions/aa_0051a120_Faction_LookupById.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00519d80` Object_OnDeath | Port as shared multi-class OnDeath: preserve deathCtx stack arg + `ret 4`; death flag bit0 @ `+0x17d`; dual path complete (`FUN_004e77d0` modes) vs delete-queue + InactiveObjects warn. Do not collapse into `Object_QueueDelete` (`0x004d4790`). HB arming = construct → Start → Enqueue on `world+0xe4ec`. |
| `0051a120` Faction_LookupById | Port as cdecl faction id → record*; lazy-init table; signed-negative reject; return value ptr @ node+8. Wire UI/mission formatters that need faction display names. Pair with loader `FUN_005197b0` (WQ9R-F). |
| Pair with | `Object_QueueDelete` (`0x004d4790`), `CVOGHBList_Enqueue`, `FUN_005197b0` (faction load), wrappers `0053cf70` / `00582670`. |

---

## Process

- OWN VAs only (`0x00519d80`, `0x0051a120`); no Launcher; **no parent ledger edits**.  
- Seal tools: decompile + analyze_function_complete + read_memory (no `disassemble_bytes`).  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Trio: raw (append re-verify) + annotated + clean with meaningful names.  
- Wave neighborhood ≠ skill-bank body — documented domain correction for parent merge.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
