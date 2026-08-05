# Dual A/B report — W29-T OWN `aa_0055e760` + `aa_005617c0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-T  
**Scope:** VAs `0x0055e760`, `0x005617c0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/xrefs + assembly context). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` → W29-T  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0055e760` WorldObj_AttachRegisterHost_Inferred | **accept** — host attach CF/ABI sealed; machine this-pointer corrects decompiler |
| `aa_005617c0` WorldObj_SnapshotHostRefsAndUnbind_Inferred | **accept** — mode-7 snapshot + compact remove + unbind tail CF/ABI sealed |

---

## VA `0x0055e760` — sealed facts

1. **Body:** `0x0055e760`–`0x0055e850` (**240 B** / `0xF0`); pad `CC` after `ret 4`.
2. **ABI:** **thiscall**; ECX = **manager**; stack = **world object**; void; **`ret 4`**.
3. **Stamp:** always `obj+8 = manager`.
4. **Sticky path:** if `obj+0x40 != 0` → `FUN_006291e0(this=*(manager+0x2c), obj)`; return.
5. **Island path:** if `manager+0x23c != 0` → arena `vtbl+0x10(0xa8, tag 0x2d)`; sizeword `+4=0xa8`; `FUN_006295f0(host, manager)`; `host+0x24 = manager.count`; attach to **new host**; push host on `manager+8` list (grow `005b3370` elem 4); return.
6. **Empty list:** if `manager+0xc == 0` → same create/push first host.
7. **Default:** `FUN_006291e0(this=manager.list[0], obj)`.
8. **Callers (3):** `FUN_00560ec0`, `FUN_00560f30`, `FUN_00560f70` — all `PUSH obj; MOV ECX,mgr`.
9. **Name:** `WorldObj_AttachRegisterHost_Inferred` (Ghidra `FUN_0055e760`).
10. **Decompile residual:** bare `FUN_006291e0(obj)` omits host ECX — **machine sealed** in clean/annotated.

### Gaps

- Product English for `manager+0x23c` and sticky `obj+0x40`.  
- Product type name for 0xa8 host block.  
- Nested duals of `006291e0` / `006295f0` / arena.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.md` |
| Annotated | `docs/reconstruction/raw/aa_0055e760_FUN_0055e760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_AttachRegisterHost_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055e760.cpp` |
| Function | `docs/reconstruction/functions/aa_0055e760_FUN_0055e760.md` |
| Function named | `docs/reconstruction/functions/aa_0055e760_WorldObj_AttachRegisterHost_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055e760.md` |

---

## VA `0x005617c0` — sealed facts

1. **Body:** `0x005617c0`–`0x005618a0` (**224 B** / `0xE0`); pad `CC` after `ret 8`.
2. **ABI:** **thiscall**; ECX = **manager**; stack #1 = **object**; stack #2 = **snapshot** worklist desc `{data,count,cap}`; void; **`ret 8`**.
3. **CF:** zero `snapshot.count`; walk `*(manager+0x2c)` list at `+0x58/+0x5c`; on `entry+0xc==obj` or `entry+0x10==obj`: grow snapshot, push entry, entry `vtbl+0x28`, host `vtbl+0xc`, compact-remove, `i--`.
4. **Tail:** `FUN_005614f0(manager, &objSlot, obj)` — if `manager+0x12c==1` defer onto `+0xf0` list; else unbind (`0055fbf0` / `0055f0b0` / `0055fd80`).
5. **Caller (1):** `FUN_005d4440` @ `0x005d44d0` when **old** HBAI mode code == **7** (before controller swap).
6. **Consumer:** `FUN_00560f70` (`WorldObj_RehomeLinksFromSnapshot_Inferred`) when old == 7 after swap.
7. **Name:** `WorldObj_SnapshotHostRefsAndUnbind_Inferred` (Ghidra `FUN_005617c0`).
8. **Decompile ≡ bytes** for CF stages; ABI sealed at call site.

### Gaps

- Product English for mode **7** / host entry type (`+0xc`/`+0x10`).  
- Product names for entry `vtbl+0x28` and host `vtbl+0xc`.  
- Snapshot data/cap pre-init by caller (count cleared here).  
- Nested dual of `FUN_005614f0`.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005617c0_FUN_005617c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_SnapshotHostRefsAndUnbind_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005617c0.cpp` |
| Function | `docs/reconstruction/functions/aa_005617c0_FUN_005617c0.md` |
| Function named | `docs/reconstruction/functions/aa_005617c0_WorldObj_SnapshotHostRefsAndUnbind_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005617c0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055e760` | Enroll / enter-mode-7 reattach / rehome phase 0 must **attach-register host** before bind-links. Preserve `obj+8` stamp, sticky path via `*(manager+0x2c)`, island/empty host create (**0xa8 / tag 0x2d**), and **host this-pointer** on attach. **Do not** substitute `WorldObj_BindLinks` (`0055fa40`) or unbind (`0055fbf0`). |
| `005617c0` | On SwitchHBAI **leave mode 7**, snapshot host-list entries referencing the object, compact-remove them, then unbind/defer via `005614f0` — **before** controller swap. Snapshot must feed `WorldObj_RehomeLinksFromSnapshot` after swap. Skipping either half desyncs island glue. Closes residual left open by W27-O rehome dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs + assembly context). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.  
- Avoided bare `undefined4` in clean (used `uint32_t` / `uint8_t`).
