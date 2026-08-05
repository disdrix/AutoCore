# Dual A/B report — W38-P OWN `aa_0096efd0` + `aa_00970060`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W38-P  
**Scope:** VAs `0x0096efd0`, `0x00970060` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave38_partition_map.md` (W38-P).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0096efd0` RefCountedPtr_Dtor_Inferred | **accept** — SEH handle dtor; rc@+8 / iface@+4; peer of `0096ef70`; 107 B sealed |
| `aa_00970060` EffectHandle_SetSlot_CoW_Inferred | **accept-with-gaps** — ESI-this CoW + set slot; `ret 8`; product effect English + fail-path rarity open |

---

## VA `0x0096efd0` — sealed facts

1. **Body:** `0x0096efd0`–`0x0096f03a` inclusive (**107 B** / `0x6B`); pad `CC`×5 then sibling @ `0x0096f040`.
2. **ABI:** **`__thiscall` / `__fastcall`**; ECX = **handle\*** (4-byte slot); no stack formals; void; **`ret`** (`c3`) after SEH epilog `add esp,0x10`.
3. **Semantics:** MSVC **SEH-wrapped refcounted handle destructor**:
   - Try (EH state 0): if `payload = *handle` → `--payload->refcount@+8`; on zero, `lea ecx,[payload+4]; call [vtbl+8]` (release); then `*handle = 0`.
   - Cleanup (EH state -1): same release **without** nulling — no-op on happy path after null.
4. **Payload contract:** `+4` = iface subobject (release this-ptr); `+8` = `int32` refcount. **Not** the COM-style binder layout (rc@+4) used by `00448fc0` / `0096fdf0`.
5. **Peer:** `RefCountedPtr_DefaultCtor_Inferred` @ `0x0096ef70` (W25-N) zeros the same slot.
6. **Classification:** leaf utility; **100+** xrefs (real CODE + many `Unwind@*` EH registrations). Thunk twin `thunk_FUN_0096efd0` @ `0x004434c0` (not OWN).
7. **Callees:** virtual release only.
8. **Name:** `RefCountedPtr_Dtor_Inferred` (Ghidra `FUN_0096efd0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_CVOGTacArc_dtor_helper_0096efd0`.
9. **Decompile ≡ bytes** for CF after SEH interpretation; dual-block is state machine, not double-free.

### Gaps

- Product / RTTI payload type name.  
- Exact release method identity (free vs pool).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0096efd0_RefCountedPtr_Dtor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.md` |
| Annotated | `docs/reconstruction/raw/aa_0096efd0_FUN_0096efd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RefCountedPtr_Dtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0096efd0.cpp` |
| Function | `docs/reconstruction/functions/aa_0096efd0_FUN_0096efd0.md` |
| Function named | `docs/reconstruction/functions/aa_0096efd0_RefCountedPtr_Dtor_Inferred.md` |

---

## VA `0x00970060` — sealed facts

1. **Body:** `0x00970060`–`0x009700a8` inclusive (**73 B** / `0x49`); pad `CC`×7 then sibling @ `0x009700b0`.
2. **ABI:** **ESI-based this** (not ECX); stack **`(slotIndex, resource*)`**; returns **int32** status in EAX; **`ret 8`** (`c2 08 00`).
3. **Semantics:**
   - `cowed = FUN_0096fdf0(ESI)` — if `*handle` shared (binder rc@+4 > 1), clone via factory/`FUN_0073df30`, install unique binder; AL=1 if cloned.
   - `status = FUN_007528f0(*ESI, slotIndex, resource)` — bind/unbind effect parameter slot; **-1** if `slotIndex < 0`, else **0**.
   - If `status == -1 && cowed && *ESI`: `parent = (*ESI)->+0x18 || *ESI`; if `parent != *ESI`, `FUN_00448fc0(ESI, parent)` rebinds outer handle to parent (COM-style rc@+4).
4. **Call-site wiring (bytes):**
   - `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (`0x0075bf40`): `lea esi,[edi+0x134]`; if index≥0 `push 0; push index; call 00970060` (clear **DiffuseTexture**).
   - `FUN_00970140`: `mov esi,ecx` then name→index → call.
5. **Classification:** worker (effect-handle parameter setter with CoW).
6. **Callers (8 funcs / 11 sites):** `FUN_0075bf40`, `FUN_00970140`, `FUN_007a2580`, `FUN_009521c0`, `FUN_00988860`, `FUN_009887a0`, `FUN_0073cb70`, `FUN_0073cd70`.
7. **Callees:** `FUN_0096fdf0`, `FUN_007528f0`, `FUN_00448fc0` (none OWN).
8. **Name:** `EffectHandle_SetSlot_CoW_Inferred` (Ghidra `FUN_00970060`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00970060`.
9. **Decompiler pitfall:** `unaff_ESI` is ABI this; `FUN_00448fc0` this = ESI not the parent arg alone.

### Gaps

- Product effect / binder class English (`PTR_FUN_00a9f9c4` family).  
- Whether parent-rebind fail path is live under shipping callers (most gate index≥0).  
- Full `007528f0` slot-table layout (callee not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00970060_FUN_00970060.md` |
| Annotated | `docs/reconstruction/raw/aa_00970060_FUN_00970060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffectHandle_SetSlot_CoW_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00970060.cpp` |
| Function | `docs/reconstruction/functions/aa_00970060_FUN_00970060.md` |
| Function named | `docs/reconstruction/functions/aa_00970060_EffectHandle_SetSlot_CoW_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0096efd0` | Port as **`RefCountedPtr` destructor** for the iface@+4 / rc@+8 payload family. SEH can be collapsed to single release+null in C++. **Do not** mix with COM-style binder assign (`00448fc0`, rc@+4). Pair with existing `RefCountedPtr_DefaultCtor_Inferred`. |
| `00970060` | Port as **effect-handle set-slot with CoW**: ensure unique binder, then set parameter slot, return status. Preserve **ESI-this** call convention at asm boundary or lift to explicit handle\* argument. Clear path = `(index, nullptr/0)`. Optional parent rebind on -1 after CoW is rare if callers pre-check index. |
| Shared | Adjacent graphics-util domain (handle dtor used everywhere; set-slot used by GfxView/effect bind). Co-owned only by W38-P partition pair. |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0096ef70` | `RefCountedPtr_DefaultCtor_Inferred` (W25-N) |
| `0x004434c0` | `thunk_FUN_0096efd0` (identical dtor shape) |
| `0x0096fdf0` | EffectHandle ensure-unique / CoW |
| `0x007528f0` | Effect set parameter slot (index, resource) |
| `0x00448fc0` | COM-style binder assign (rc@+4) |
| `0x0075bf40` | `GfxView_SetDiffuseColor_ClearDiffuseTex_Inferred` (W37-L) — primary clear consumer |
| `0x00970140` | Name→index wrapper then `00970060` |
| `0x0073df30` | Effect binder clone factory path |

Closes W38-P OWN pair: universal refcounted-handle dtor + effect-handle CoW set-slot used by DiffuseTexture clear and related binds.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names; `_Inferred` structural names only.  
- Rejected long Named_CalleeOf scaffold aliases.  
- Clean avoids bare `undefined4` (`uint32_t` / explicit structs).
