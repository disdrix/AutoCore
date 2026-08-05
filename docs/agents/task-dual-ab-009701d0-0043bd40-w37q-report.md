# Dual A/B report — W37-Q OWN `aa_009701d0` + `aa_0043bd40`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-Q  
**Scope:** VAs `0x009701d0`, `0x0043bd40` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `batch_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + xrefs/callers. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-Q).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_009701d0` EffEffectSlot_BindByPath_Inferred | **accept-with-gaps** — thiscall slot + path/`ret 4` + refcount swap + fail `-1` + status return sealed; product plate + loader internals open |
| `aa_0043bd40` StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred | **accept-with-gaps** — unsigned Val12 op[] CF + ECX/EAX ABI + mapped@+0x10 + miss `{key,0,0}` sealed; insert-helper internals + product demangle open |

---

## VA `0x009701d0` — sealed facts

1. **Body:** `0x009701d0`–`0x00970250` exclusive (**128** B / `0x80`).
2. **ABI:** **`__thiscall`**; ECX = `void**` effect/material **slot**; stack **`(pathOrToken)`**; epilogue **`RET 0x04`**.
3. **Semantics:**
   - `effect = FUN_0073e1e0(DAT_00d1f61c, pathOrToken, &status)` — third arg **aliases** the stack formal (status overwrite).
   - Null effect → **`return 0xFFFFFFFF`**.
   - `refcount @ +4 ++`; if became **1**, thiscall **`vtbl[+4]`**.
   - If old `*slot`: `refcount--`; if **0**, thiscall **`vtbl[+8]`**.
   - `*slot = effect`.
   - Optional: if `*(char*)(DAT_00d1f050 + 0x68) != 0` → `FUN_00965600` + `FUN_00744ea0` (path/`.fxc` helper + host notify).
   - Success return = **status formal** (callers treat as signed; `-1 < status` means OK).
4. **Object:** intrusive refcount layout `+0` vtbl / `+4` int32 (same family as W23-A `RefCountedSlot_ReleaseAndClear`).
5. **Classification:** worker (effect slot bind).
6. **Callers:** 100+ xrefs — FX preload (`FUN_00948bd0`), material setup (`FUN_0099e6c0`, `FUN_00731130`, `FUN_0099f450`, …), graphics bootstrap (`FUN_004c0a90`, …), Z-fill (`FUN_0098d870`), unserialize paths.
7. **Callees:** `FUN_0073e1e0`, `FUN_00965600`, `FUN_00744ea0`, indirect vtbl+4 / vtbl+8.
8. **Name:** `EffEffectSlot_BindByPath_Inferred` (Ghidra `FUN_009701d0`; **Inferred** from manager + `.fx` callers + refcount CF). **Reject** bare scaffold void/undefined return.
9. **Decompile ≡ bytes** for CF/ABI/refcount; full hex sealed in raw.  
    Full hex: `51538b5c240c56578d442414508bf98b0d1cf6d1005351e8f4dfdcff8bf085f6750a5f5e83c8ff5b59c2040083460401837e040175078b168bceff52048b0f85c9740b834104ff75058b01ff50088937a150f0d10080786800741b8b70646a018d4c24105351e8c553ffff83c408508bcee85a4cddff8b4424145f5e5b59c204`

### Gaps

- Unowned loader `FUN_0073e1e0` / manager object product type.  
- Exact status code domain.  
- Product English plate beyond role-inferred name.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_009701d0_FUN_009701d0.md` |
| Annotated | `docs/reconstruction/raw/aa_009701d0_FUN_009701d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EffEffectSlot_BindByPath_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009701d0.cpp` |
| Function | `docs/reconstruction/functions/aa_009701d0_FUN_009701d0.md` |
| Function named | `docs/reconstruction/functions/aa_009701d0_EffEffectSlot_BindByPath_Inferred.md` |

---

## VA `0x0043bd40` — sealed facts

1. **Body:** `0x0043bd40`–`0x0043bda5` exclusive (**101** B / `0x65`; pad `CC`).
2. **ABI:** **ECX** = map shell (`head` @ `+4`); **EAX** = `uint32_t* key`; **no stack args**; plain **`RET`**; returns **`mapped*`** at `node+0x10`.
3. **Semantics:** MSVC `_Tree` / map **operator[]-style** get-or-insert (unique Val12, **unsigned** key):
   - Lower_bound walk: isnil@`+0x19`, key@`+0x0c`; if `node.key < *key` go right else candidate + left.
   - Hit: candidate ≠ head and `candidate.key <= *key` → return `node+0x10`.
   - Miss: stage `{*key, 0, 0}`; `FUN_0043be60` insert-hint; return `*outIt + 0x10`.
4. **Node / Val12:** key@`+0x0c`, mapped@`+0x10`/`+0x14`, color@`+0x18`, isnil@`+0x19`.
5. **Not** the signed thiscall+`ret 4` twin `StdTree_OperatorIndex_Val12` (`0x0053af20` / W29-Q).
6. **Classification:** worker (map op[]).
7. **Callers (5 xrefs):** `FUN_0073e3a0` @ `0073e43e`; `FUN_0096eec0` @ `0096ef4a`; `FUN_0072a660` @ `0072a974`; `FUN_0098d870` @ `0098d983`; site `00733896`. Call sites write two dwords to mapped (fn*/ptr + 0).
8. **Callees:** `FUN_0043be60` only (unowned).
9. **Name:** `StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred` (Ghidra `FUN_0043bd40`; **Inferred** structural).
10. **Decompile ≡ bytes** for CF/ABI/unsigned; full hex sealed in raw.  
    Full hex: `8b510483ec10568bf08b4204807819007518578b3e39780c73058b4008eb048bd08b008078190074ec5f3b510474078b063b420c73288b3633c0897424088944240c89442410528d44240c8d742408e8cc0000008b0083c0105e83c410c38d42105e83c410c3`

### Gaps

- Unowned insert-hint `FUN_0043be60` full edge/rebalance contract.  
- Product demangle per map owner.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043bd40_FUN_0043bd40.md` |
| Annotated | `docs/reconstruction/raw/aa_0043bd40_FUN_0043bd40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043bd40.cpp` |
| Function | `docs/reconstruction/functions/aa_0043bd40_FUN_0043bd40.md` |
| Function named | `docs/reconstruction/functions/aa_0043bd40_StdTree_OperatorIndex_Val12_U32Key_Eax_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `009701d0` | Port as **effect slot bind**: ECX-equivalent slot, path/token arg, load via effect manager, **AddRef before Release**, first-ref activate (`vtbl+4`), zero-ref destroy (`vtbl+8`), fail **`-1`**, success returns **status** not object*. Pair with path intern (`FUN_00989e00`). Do not model as set-param (`FUN_0096fff0`). |
| `0043bd40` | Port as Val12 map **operator[]** with **uint32** keys: ECX=map, **EAX=&key**, plain ret, return **mapped@+0x10**, miss inserts `{key,0,0}`. **Do not** reuse signed thiscall+`ret 4` twin (`0x0053af20`). High-bit keys must stay unsigned-ordered. |
| Shared | Both appear near graphics init (e.g. Z-fill uses both) but are **independent** workers — no shared CF ownership. Map op[] also registers factory entries during effect-manager / NestedHash host ctors. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Trio artifacts: raw + annotated + clean (+ FUN_* twin + function records).  
- No invented product plates; `_Inferred` names from sealed CF + caller evidence.  
- Avoided bare `undefined4` in clean (`uint32_t` / typed nodes / `void**` slot).
