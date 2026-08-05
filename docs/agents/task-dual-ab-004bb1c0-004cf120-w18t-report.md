# Dual A/B report — W18-T OWN `0x004bb1c0` + `0x004cf120`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x004bb1c0`, `0x004cf120`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004bb1c0` `Object_ResolveCoidVtbl1e8_Inferred` | **accept-with-gaps** — free-arg resolve + `vtbl+0x1e8` + ECX passthrough sealed; product vtbl name open |
| `aa_004cf120` `AllocateNewObjectFromCbid` | **accept-with-gaps** — plate name + thiscall host factory sealed; nested product names open |

---

## `0x004bb1c0` — Object_ResolveCoidVtbl1e8_Inferred

### Sealed facts

1. **Body** `0x004bb1c0`–`0x004bb1e9`; **42 B**; leaf-thin wrapper.
2. **ABI:** three stack args cleaned by **`RET 0xC`**; **ECX = resolve context** supplied by caller and preserved into `CVOGReaction_ResolveObjectTarget` (`0x004bae70`). Decompiler omits ECX (same trap as sibling resolve wrappers).
3. **Algorithm:** Resolve(bGlobal, coidLo, coidHi) → if null return 0 else **`obj->vtbl[+0x1e8]()`**.
4. **Bytes ≡ decompile**  
   `8b44240c8b542408508b4424085250e89cfcffff85c0740d8b108bc8ff92e8010000c20c0033c0c20c00`.
5. **Callers (9):** `CVOGSectorMap_DoPlayerOnLoadTrigger`, `CVOGSectorMap_DoCreatorLoadTrigger`, `Client_UpdateNpcInteractIcons`, `FUN_004cdc80`, `FUN_004d9b50`, `FUN_004dbef0`, `FUN_004dd940`, `FUN_005aca60`, `FUN_005accf0`.
6. **Load-trigger site:** `MOV ECX,[host+0xe4e8]` then `FUN_004bb1c0(0, coidLo, coidHi)` for `m_coidPerPlayerLoadTrigger` / creator sibling.
7. **Siblings:** `004bb010` blob+`+0x1d4`; `004bb070` `+0x1d8`; `004bb0a0` `+0x1dc`; `004bb950` resolve-only.

### Gaps

1. Product name of `vtbl+0x1e8`.  
2. Whether return is always identity-equal to resolved `obj`.  
3. Runtime / bit-exact / image diff.  
4. Exhaustive per-caller ECX provenance (DoPlayerOnLoad sealed).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004bb1c0_Object_ResolveCoidVtbl1e8_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004bb1c0_FUN_004bb1c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveCoidVtbl1e8_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004bb1c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bb1c0_FUN_004bb1c0.annotated.md` |
| Scratch | `tmp/a_004bb1c0.md` |

---

## `0x004cf120` — AllocateNewObjectFromCbid

### Sealed facts

1. **Body** `0x004cf120`–`0x004cf296`.
2. **ABI:** **thiscall** — `ECX` host saved to **`EDI`**; stack **`cbid`**, **`templateId`**; **`RET 8`**.
3. **Product name High:** plate `"allocatenewobjectfromcbid failed %d"` @ `0x00a7f228`.
4. **templateId != -1:** `FUN_00508e20` → `cbid = *(t+0x84)`; template-apply flag; fail → 0.
5. **Factory:** `CVOGReaction_GiveItemByCbid` → `vtbl+8(cbid, host, 1)`; template apply (slots `+0x90`/`+0xa4`, `vtbl+0x64`/`+0x9c`); always `obj+0x17c\|=0x10`, bump `host+0xe6e0` 64-bit, `vtbl+0x218(host)`, `vtbl+0x2a4(host+0xe4e8)`.
6. **Decompiler traps sealed:** template gate is **stack flag byte**, not `unaff_EDI>>24`; `vtbl+8` arg2 is **host this**, not masked uint.
7. **Callers (2):** `FUN_004d08c0`, `FUN_004d31a0` (cbid `0x21a3`, template `-1`).

### Gaps

1. Product names of nested callees and virtuals.  
2. Full template record schema.  
3. Exact product intent of packed `vtbl+0x9c` arg.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004cf120_AllocateNewObjectFromCbid.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004cf120_AllocateNewObjectFromCbid.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004cf120_AllocateNewObjectFromCbid.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004cf120_AllocateNewObjectFromCbid.md` |
| Function record | `docs/reconstruction/functions/aa_004cf120_AllocateNewObjectFromCbid.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004cf120_FUN_004cf120.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AllocateNewObjectFromCbid.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004cf120.cpp` |
| Raw | `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.md` |
| Annotated | `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.annotated.md` |
| Scratch | `tmp/a_004cf120.md` |

---

## AutoCore impact

- **Sector load triggers / interact icons:** object resolve is **not** bare COID hash — it is resolve + **`vtbl+0x1e8`**. Ports that only call `Object_ResolveFromTFID` / free Resolve without the virtual may diverge.
- **Client object spawn:** `AllocateNewObjectFromCbid` is the plate-named sector-map factory used for descriptor children and at least one combat/loot spawn (`0x21a3`). Server ports already have GiveItem/clonebase paths; this seals the client post-alloc init + host counter/`+0xe4e8` bind sequence.
- Do not merge `004bb1c0` with blob-form `004bb010` — free triple + different vtbl slot.

---

## This report

`docs/agents/task-dual-ab-004bb1c0-004cf120-w18t-report.md`
