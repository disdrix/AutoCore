# Review A (reconstruction fidelity): `aa_004cf120` AllocateNewObjectFromCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf120` |
| **VA** | `0x004cf120`–`0x004cf296` |
| **Canonical name (Ghidra)** | `FUN_004cf120` |
| **Proposed name** | `AllocateNewObjectFromCbid` (**High** — plate string) |
| **Prior scaffold aliases** | `Named_AllocateNewObjectFromCbidFailed`; `Named_CalleeOf_…_004cf120` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-T) |
| **Reviewer role** | Reconstruction fidelity (factory + template + host register) |
| **Counterpart** | `reviews/B_aa_004cf120_AllocateNewObjectFromCbid.md` |
| **System** | sector-map / object-spawn (client) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Allocate a new object from clonebase id, optionally from a template, init it, register on the sector-map host, return object\*.**

Stages:

1. Optional `FUN_00508e20(templateId)` → override `cbid` from `template+0x84`; set template flag.
2. Reject `cbid == -1`.
3. `CVOGReaction_GiveItemByCbid(cbid)`; on null log plate and return 0.
4. `obj->vtbl[+8](cbid, host, 1)`; on `< 0` return 0.
5. If template flag: apply template bind/slots/`vtbl+0x64`/`vtbl+0x9c`.
6. `obj+0x17c |= 0x10`; `FUN_00512670`; bump `host+0xe6e0` 64-bit; `FUN_00512160`; `vtbl+0x218(host)`; `vtbl+0x2a4(host+0xe4e8)`; return obj.

### Primary use

- `FUN_004d08c0`: up to four child objects from a parent descriptor.
- `FUN_004d31a0`: combat-adjacent spawn of cbid `0x21a3` with `templateId=-1`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004cf120_FUN_004cf120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AllocateNewObjectFromCbid.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cf120_AllocateNewObjectFromCbid.md` |
| Live Ghidra | `decompile_function` `0x004cf120`; complete analysis; callers/callees; body `read_memory`; plate `read_memory` `0x00a7f228` |
| Callers decompiled | `FUN_004d08c0`, `FUN_004d31a0` |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// ECX = sector-map host (saved EDI); stack cbid, templateId; RET 8
void * __thiscall AllocateNewObjectFromCbid(void *host, int cbid, int templateId);
```

| Item | Evidence |
|---|---|
| Stack arity 2 | `RET 8` at all exits |
| thiscall host | `MOV EDI,ECX`; later `[EDI+0xe6e0]` / `[EDI+0xe4e8]` |
| Product name | plate exact lowercase token |
| Factory | `CALL CVOGReaction_GiveItemByCbid` |
| Init virtual | `CALL [EAX+8]` with pushes cbid, EDI, 1 |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| templateId==-1 vs lookup | **Yes** |
| cbid==-1 / GiveItem null / init<0 → 0 | **Yes** |
| Template apply only when flag set | **Yes** (bytes; decompiler mislabeled flag as unaff_EDI) |
| Flag OR + counter + attach | **Yes** |
| RET 8 | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Product name AllocateNewObjectFromCbid | **High** | plate |
| thiscall host + RET 8 | **High** | bytes |
| Template cbid @ +0x84 | **High** | `MOV EBX,[EBP+0x84]` |
| Host +0xe4e8 / +0xe6e0 | **High** | EDI loads |
| Nested product names | **Tentative** | open |
| packedLocal product meaning | **Probable** | this copy + hi flag byte |

---

## 6. Gaps / open

1. Nested callee / virtual product names.
2. Full template struct documentation beyond used offsets.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — name/ABI/CF High; nested names open.
