# Dual A/B report — W30-J OWN `aa_006295f0` + `aa_005614f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-J  
**Scope:** VAs `0x006295f0`, `0x005614f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` → W30-J  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_006295f0` Phys_IslandHost_Ctor_Inferred | **accept** — pure 0xa8 host ctor CF/ABI/field map sealed |
| `aa_005614f0` WorldObj_UnbindOrDefer_Inferred | **accept** — defer vs unbind (no destroy) CF/ABI sealed; distinct from RemoveOrDefer |

---

## VA `0x006295f0` — sealed facts

1. **Body:** `0x006295f0`–`0x006296a2` (**178 B** / `0xB2`); pad `CC` after `ret 4`.
2. **ABI:** **thiscall**; ECX = **host**; stack = **manager**; void (EAX returns this); **`ret 4`**.
3. **Callees:** **none** — pure field constructor.
4. **Vtbls:** primary `PTR_FUN_009e331c` @ `+0`; secondary `PTR_LAB_009e3310` @ `+0x1c` (overwrites transient `009d2794`).
5. **Manager:** `host+0x20 = manager`.
6. **Flags:** `+0x28=0`, `+0x29=1`, `+0x2c=0`, `+0x30=1`; floats at `+0x34/+0x38` zeroed via `MOVSS`.
7. **Lists:** empty growable descriptors through `+0x94` with capacity sentinels `0x80000000` / `0x80000001`; inline heads at `+0x3c→+0x48` and `+0x58→+0x64`.
8. **Callers (CODE):** `FUN_0055e760` (AttachRegisterHost) ×2, `FUN_00560110`, `FUN_00561e20`.
9. **Call-site machine:** `PUSH manager; MOV ECX, host; CALL` then caller sets `host+0x24 = manager.count`.
10. **Sibling:** `FUN_006296c0` dtor-like frees list slots (allocator tag `0x12`).
11. **Name:** `Phys_IslandHost_Ctor_Inferred` (Ghidra `FUN_006295f0`; preferred over scaffold Named_CalleeOf_Named_hkWorld).
12. **Decompile ≡ raw** for field-init body (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product class English for 0xa8 host.  
- List element types.  
- Nested dual of `006296c0`.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.md` |
| Annotated | `docs/reconstruction/raw/aa_006295f0_FUN_006295f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_IslandHost_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006295f0.cpp` |
| Function | `docs/reconstruction/functions/aa_006295f0_FUN_006295f0.md` |
| Function named | `docs/reconstruction/functions/aa_006295f0_Phys_IslandHost_Ctor_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006295f0.md` |

---

## VA `0x005614f0` — sealed facts

1. **Body:** `0x005614f0`–`0x00561571` (**129 B** / `0x81`); pad `CC` after `ret 8`.
2. **ABI:** **thiscall**; ECX = **manager**; stack #1 = **out byte\***; stack #2 = **object**; void; **`ret 8`**.
3. **Adjacent:** immediately after sibling `FUN_00561450` (`WorldObj_RemoveOrDefer_Inferred`, body ends `0x005614ef`).
4. **Defer:** if `manager+0x12c == 1` → grow/push onto `+0xf0` queue (`005b3370` elem 4), `obj.ref6++`, `*out=0`.
5. **Immediate:** if `manager+0x24 > 0` → `FUN_00561320`; then `0055fbf0(this=mgr,obj)` → `0055f0b0(this=obj)` → `0055fd80(this=mgr,obj)`; `*out=1`.
6. **Not destroy:** no `0062a490` / `005ffff0` / ref-- / vtbl destroy (those are RemoveOrDefer only).
7. **Callers (CODE):** `FUN_00561580`, `FUN_005617c0` (`WorldObj_SnapshotHostRefsAndUnbind_Inferred`).
8. **Call-site machine (`005617c0` @ `0x00561892`):** `PUSH obj; PUSH &out; MOV ECX, manager; CALL`.
9. **Name:** `WorldObj_UnbindOrDefer_Inferred` (Ghidra `FUN_005614f0`).
10. **Decompile ≡ raw** for CF stages; machine seals nested this-pointers.

### Gaps

- Product English for defer flag / shared queue drain.  
- Nested duals of unbind helpers.  
- Full role of `FUN_00561580`.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005614f0_FUN_005614f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldObj_UnbindOrDefer_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005614f0.cpp` |
| Function | `docs/reconstruction/functions/aa_005614f0_FUN_005614f0.md` |
| Function named | `docs/reconstruction/functions/aa_005614f0_WorldObj_UnbindOrDefer_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005614f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `006295f0` | After arena alloc of **0xa8** (tag **0x2d**), construct island host before attach. Preserve vtbls, `manager@+0x20`, flag bytes, list sentinels, **ret 4**. Caller sets `host+0x24`. Closes residual left open by W29-T AttachRegisterHost dual. |
| `005614f0` | Mode-7 leave / snapshot tail must **unbind-or-defer**, not remove-or-destroy. Preserve defer queue `+0xf0`, ref6++, outDone polarity, immediate unbind trio (`0055fbf0`/`0055f0b0`/`0055fd80`), **ret 8**. **Do not** substitute `WorldObj_RemoveOrDefer` (`00561450`). Closes residual left open by W29-T SnapshotHostRefsAndUnbind dual. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.  
- Avoided bare `undefined4` in clean (used `uint32_t` / `uint8_t`).
