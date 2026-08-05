# Dual A/B report — W30-I OWN `aa_005305b0` + `aa_006291e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W30-I  
**Scope:** VAs `0x005305b0`, `0x006291e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` / `get_function_by_address` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md` → W30-I  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005305b0` CVOGCharacter_SetMissionCounter | **accept-with-gaps** — map set CF/ABI/`ret 8`/hit +0x14/miss insert sealed; product English + dual-field vs Get open |
| `aa_006291e0` PhysHost_AttachObject_Inferred | **accept-with-gaps** — host attach CF/ABI/`ret 4`/vector/stamps/vcall this sealed; product vfunc English open |

---

## VA `0x005305b0` — sealed facts

1. **Body:** `0x005305b0`–`0x00530603` exclusive (**83** B / `0x53`); pad `CC` after.
2. **ABI:** **`__thiscall`**; ECX = **character**; stack `(key, value)`; void; **`ret 8`**.
3. **Map:** object `char+0x584`; end/head `char+0x588` (Val12 family with `FUN_00418b80` find + `StdTree_OperatorIndex_Val12`).
4. **CF miss:** `node == head` → operator[] → mapped `{0, value}` at +0x10/+0x14.
5. **CF hit:** `*(node+0x14) = value` only (absolute set, not `+=`).
6. **Callees:** `FUN_00418b80`, `FUN_0053af20` (W29-Q sealed).
7. **Callers (2 / 2 xrefs):** `FUN_00530670` @ `005306e9`; `FUN_0094e530` @ `0094e5cd`.
8. **Sibling:** `CVOGCharacter_AddMissionCounter` (`00530610`) hit `+=`; **ret 0xC** / 3 formals.
9. **Name:** `CVOGCharacter_SetMissionCounter` (Ghidra `FUN_005305b0`).
10. **Decompile residual:** map ECX omitted on both nested calls — **machine sealed** in clean/annotated.
11. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); full body hex sealed.

### Gaps

- Product English for counter key domain.  
- Dual-field: GetResourceBalance reads **+0x10**; Set/Add write **+0x14**.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005305b0_CVOGCharacter_SetMissionCounter.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005305b0_CVOGCharacter_SetMissionCounter.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005305b0_FUN_005305b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005305b0_FUN_005305b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_SetMissionCounter.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005305b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005305b0_FUN_005305b0.md` |
| Function named | `docs/reconstruction/functions/aa_005305b0_CVOGCharacter_SetMissionCounter.md` |
| Scratch | `docs/reconstruction/tmp/a_005305b0.md` |

---

## VA `0x006291e0` — sealed facts

1. **Body:** `0x006291e0`–`0x00629231` exclusive (**81** B / `0x51`); pad `CC` after.
2. **ABI:** **`__thiscall`**; ECX = **phys host**; stack `(worldObj*)`; void; **`ret 4`**.
3. **Stamps:** `obj+0x44 = host`; after push `obj+0x58 = size-1` (slot index).
4. **Vector @ host+0x3c:** `{data*, size, cap&0x7fffffff}`; grow `FUN_005b3370(vec, 4)` **cdecl**.
5. **Notify:** `result = (*(obj+0x3c))->vtbl+0x14()` then `host->vtbl+0x10(result)`.
6. **Callees:** `FUN_005b3370`; nested + host virtuals.
7. **Callers (3 / 3 xrefs):** all `FUN_0055e760` `WorldObj_AttachRegisterHost_Inferred` @ `0055e776`, `0055e7b5`, `0055e846`.
8. **Name:** `PhysHost_AttachObject_Inferred` (Ghidra `FUN_006291e0`; W29-T Host_Attach).
9. **Decompile residual:** first vcall this is nested object not host — **machine sealed**.
10. **Decompile ≡ raw CF** (live 2026-07-29 ≡ raw 2026-07-23); full body hex sealed.
11. Closes W29-T residual “nested dual of `006291e0` open” for CF/ABI.

### Gaps

- Product host type English (0xa8 / tag 0x2d from caller).  
- Nested / host vfunc product names.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_006291e0_PhysHost_AttachObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_006291e0_PhysHost_AttachObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_006291e0_FUN_006291e0.md` |
| Annotated | `docs/reconstruction/raw/aa_006291e0_FUN_006291e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysHost_AttachObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006291e0.cpp` |
| Function | `docs/reconstruction/functions/aa_006291e0_FUN_006291e0.md` |
| Function named | `docs/reconstruction/functions/aa_006291e0_PhysHost_AttachObject_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_006291e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005305b0` | Port as character map **absolute set** (not add). Preserve map this=`+0x584`, head=`+0x588`, miss insert via OperatorIndex with `{0,value}`, hit write **only +0x14**, **ret 8**. Do not use Add’s third formal / ret 0xC. Do not assume Get(+0x10) mirrors Set(+0x14) without a documented sync path. |
| `006291e0` | Port as phys-host **attach leaf** after host selection. Preserve backlink `obj+0x44`, vector@`host+0x3c`, index `obj+0x58`, nested query then host notify, grow cdecl, **ret 4**. Callers must pass **host** in ECX (not manager). |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00530610` | `CVOGCharacter_AddMissionCounter` — hit `+=` at +0x14; ret 0xC |
| `0x0052ada0` | `CVOGCharacter_GetResourceBalanceByType` — read +0x10 |
| `0x0053af20` | `StdTree_OperatorIndex_Val12` (W29-Q) |
| `0x00418b80` | ordered-map find |
| `0x0055e760` | `WorldObj_AttachRegisterHost_Inferred` (W29-T) — sole caller of `006291e0` |
| `0x006295f0` | host init (W30-J adjacent) |
| `0x005b3370` | pointer-vector grow |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ complete analysis / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; names from sibling family / structural `_Inferred`.  
- Avoid bare `undefined4` in clean (`uint32_t` / `int32_t`).

---

## This report

`docs/agents/task-dual-ab-005305b0-006291e0-w30i-report.md`
