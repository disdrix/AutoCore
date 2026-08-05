# Dual A/B report — W25-D OWN-ONLY (`aa_004c8110`, `aa_00583f10`)

**Date:** 2026-07-29  
**Agent:** W25-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004c8110`, `0x00583f10`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00583f10` NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred | **accept** — 143 B thiscall `ret 0x10`; dual host* tables → sealed `004b7030` |
| `aa_004c8110` Object_ApplyDualFxSlots_SlotFilterWild_Inferred | **accept** — 214 B dual effect slots + fan-out + local hosts; tail jmp `00584330` |

---

## Sealed facts — `0x00583f10`

1. **ABI:** MSVC **thiscall**; **4 stack dwords**; epilogue **`ret 0x10`**.
2. **Body:** `0x00583f10`–`0x00583f9e` (**143** bytes).
3. **Vbase:** `base = this + *(*(this+4)+4)`.
4. **Tables:** host* vectors **`base+0x128/+0x12c`** and **`base+0x13c/+0x140`**.
5. **Per entry:** `ECX = *it` then sealed `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` with passthrough args (decompiler omits ECX setup).
6. **Callee:** only `FUN_004b7030` (W24-D sealed). Rel32 **Confirmed**.
7. **Callers:** `004c8110` (×2), `004ff6f0`, `00584290`, `00584330`, `005857a0`, `00586060`, xref `0052bdfb`.
8. **Name:** `NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00583f10`. Reject creature-setup chain alias as sole name.

---

## Sealed facts — `0x004c8110`

1. **ABI:** MSVC **thiscall** (nested subobject); **no stack formals**; **tail jmp** (not ret).
2. **Body:** `0x004c8110`–`0x004c81e5` (**214** bytes).
3. **Slots:** effect A `*(this-0x27c)`, effect B `*(this-0x280)`; null-gated.
4. **Per non-null:** `00583f10(this-0x4c0, 0, effect, 1, -1)` then local host* vector via vb `*(this-0x4fc)` at **`-0x3c4/-0x3c0`** → `004b7030` same args.
5. **Arg pack:** `(want_start=0, want_stop=effect*, use_slot_filter=1, slot_filter=-1)` — e270 wild path (W24-D sample).
6. **Chain:** `lea ecx,[this-0x430]; jmp FUN_00584330` — **Confirmed** rel32.
7. **Callers:** MI thunks `0x004cce83`, `0x0053bc49`.
8. **Name:** `Object_ApplyDualFxSlots_SlotFilterWild_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_004c8110`.

---

## Gaps

### `00583f10`
1. Product C++ type / table A vs B English.  
2. EAX leftover-base consumers.  
3. Runtime / bit-exact / differential — open.

### `004c8110`
1. Product class + dual-slot member names.  
2. Full dual of chain `FUN_00584330` (out of owned scope).  
3. effect* as want_stop product meaning (forwarded).  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00583f10` | `reviews/A_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` | `reviews/B_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` | **accept** |
| `0x004c8110` | `reviews/A_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` | `reviews/B_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` | **accept** |

---

## Files

### `aa_00583f10`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00583f10_NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00583f10_FUN_00583f10.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_ForEachHostPtrTablePair_ApplyFxToggle_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00583f10.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00583f10_FUN_00583f10.md` |
| Annotated | `docs/reconstruction/raw/aa_00583f10_FUN_00583f10.annotated.md` |

### `aa_004c8110`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004c8110_Object_ApplyDualFxSlots_SlotFilterWild_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004c8110_FUN_004c8110.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ApplyDualFxSlots_SlotFilterWild_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004c8110.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_004c8110_FUN_004c8110.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8110_FUN_004c8110.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004c8110-00583f10-w25d-report.md` |

---

## AutoCore impact

### `00583f10`
- Client FX apply that targets **tables of hosts** must walk **both** ptr ranges after vbase adjust — not only a single list.
- Preserve **thiscall + ret 0x10** and host ECX from `*iterator` (do not trust decompiler-only call forms).
- Port as thin fan-out over sealed owned-bit7 apply; do not re-implement child list walk here.

### `004c8110`
- Dual attach/effect slots use **slot filter on + wild `-1`** pack, distinct from chain unit's filter-off path.
- Nested this offsets matter: table owner at `-0x4c0`, chain at `-0x430`, slots at `-0x27c/-0x280`.
- Entry may arrive via MI thunks that adjust ECX before the body.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004b7030` | sealed owned-bit7 apply (W24-D) |
| `0x00584330` | chain sibling apply (filter char 0) |
| `0x0058e270` / `0x0058e300` | child FX toggle helpers |
| `0x004b7150` | NDSpecialFX deactivate/clear peer |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.
