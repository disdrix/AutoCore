# Dual A/B report — W28-G OWN `aa_0051f890` + `aa_006264e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W28-G  
**Scope:** VAs `0x0051f890`, `0x006264e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_by_address` / xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051f890` Object_SetEnhancedStateFlag_Inferred | **accept** — 13 B CF + ABI + `+0x6b9` store sealed; product spelling `_Inferred` only |
| `aa_006264e0` CVOGHBActivatePlayer_ctor_Inferred | **accept-with-gaps** — CF + ABI + fields + sole-caller sealed; product class English open |

---

## VA `0x0051f890` — sealed facts

1. **Body:** `0x0051f890`–`0x0051f89c` (**13 B**); pad `CC` after `RET 4`.
2. **ABI:** **`__thiscall`** ECX = object; stack `(uint8_t fEnhanced)`; epilogue **`ret 4`** (`C2 04 00`); void.
3. **Entry / body:** `8A 44 24 04  88 81 B9 06 00 00  C2 04 00`.
4. **Effect:** `*(uint8_t*)(this + 0x6b9) = fEnhanced` — **enhanced-state** flag.
5. **Classification:** stub (leaf store; **0** callees).
6. **Code xrefs (2):**
   - `Object_ActivatePlayerEnqueueHB_Inferred` (`FUN_00626890`) @ `0x00626916` — **set 1** on player after TFID rebind.
   - `0x0062667b` — **clear 0** (`push 0`); **no** Ghidra function spans site (undefined gap after `FUN_00626530` pad through pre-`00626890`).
7. **Role evidence (siblings, not OWN):** prompt suffix `"in your enhanced state."`; drive/camera/skill/UI gates on `+0x6b9`.
8. **Name:** `Object_SetEnhancedStateFlag_Inferred` (Ghidra `FUN_0051f890`).
9. **Decompile ≡ raw ≡ bytes** (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB method spelling.  
- Exhaustive writer catalog.  
- Neighbor bytes `+0x6b8/+0x6ba/+0x6bb` (parent sets some).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_SetEnhancedStateFlag_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051f890.cpp` |
| Function | `docs/reconstruction/functions/aa_0051f890_FUN_0051f890.md` |
| Function named | `docs/reconstruction/functions/aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0051f890.md` |

---

## VA `0x006264e0` — sealed facts

1. **Body:** `0x006264e0`–`0x0062652a` (**75 B / `0x4B`**); pad `CC` after **`ret 0xC`**.
2. **ABI:** **`__thiscall`** ECX = HB action; stack `(periodSrc, pOwner, pHost)`; epilogue **`C2 0C 00`**; returns `this`.
3. **Entry:** `56 8B F1 E8 …` (push esi; this→ESI; call base ctor).
4. **Exit:** `8B C6 5E C2 0C 00`.
5. **Classification:** worker (HB subclass ctor; **3** callees).
6. **Caller (1):** `Object_ActivatePlayerEnqueueHB_Inferred` (`FUN_00626890`) @ `0x006269e8` after `operator_new(0x2c)` with args `(host+0x24, player_obj, host)`.
7. **Callees:** `CVOGHBBase_ctor` (`0x00508200`), `CVOGHBBase_AttachOwnerObject` (`0x005083b0`), `CVOGHBBase_SetPeriodAndCounter` (`0x005081a0`) — relative calls sealed.
8. **Fields:**
   - `*this = 0x009e3168` (subclass vtbl)
   - `+0x28 = 0` (byte)
   - `+0x08 = *(periodSrc+0x1c)`
   - period `*(periodSrc+0x18)` clamp **0→1** → SetPeriod(true)
   - `+0x24 = pHost` (host backref)
   - owner via AttachOwner at base `+0x18`
9. **Does not:** Enqueue, Start, or store `host+0x6c4` (parent).
10. **Name:** `CVOGHBActivatePlayer_ctor_Inferred` (Ghidra `FUN_006264e0`).
11. **Decompile ≡ raw CF** (live 2026-07-29 ≡ 2026-07-23).

### Gaps

- Product/PDB class name for vtbl `0x009e3168`.  
- Semantic meaning of `periodSrc+0x1c` vs dual period fields.  
- Nested vtbl methods `FUN_00626210` / `FUN_006261e0` English (not OWN).  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006264e0_FUN_006264e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBActivatePlayer_ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006264e0.cpp` |
| Function | `docs/reconstruction/functions/aa_006264e0_FUN_006264e0.md` |
| Function named | `docs/reconstruction/functions/aa_006264e0_CVOGHBActivatePlayer_ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006264e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051f890` | Port as pure byte store at **object+0x6b9**. Preserve **ret 4**. Activate path sets **1** after TFID rebind; clear path uses **0**. Do not fold enhanced-state *policy* into this leaf — readers own gating. |
| `006264e0` | HB subclass ctor only: base → vtbl **`0x009e3168`** → attach owner → **`+0x28=0`** → period fields → **min period 1** → host@**`+0x24`**. Preserve **`ret 0xC`** and arg order `(periodSrc, pOwner, pHost)`. Size **0x2c**. Parent must Enqueue+Start and may store at `host+0x6c4`. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00626890` | `Object_ActivatePlayerEnqueueHB_Inferred` (W27-F) — sole sealed caller of both OWN VAs |
| `0x00508200` | `CVOGHBBase_ctor` |
| `0x005083b0` | `CVOGHBBase_AttachOwnerObject` (`pOwnerObject` @ `+0x18`) |
| `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |
| `0x005081c0` | `CVOGHBBase_Start` (parent after this ctor) |
| `0x005078f0` | `CVOGHBList_Enqueue` (parent) |
| `0x00626210` / `0x006261e0` | subclass vtbl methods (host `+0x6c8` side effects) |
| `0x009e3168` | activate-player HB vtbl |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; structural `_Inferred` only.  
- Avoid bare `undefined4` in clean (use `uint32_t` / `uint8_t` / `void*`).

---

## This report

`docs/agents/task-dual-ab-0051f890-006264e0-w28g-report.md`
