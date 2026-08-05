# Review B (skeptical / adversarial): `aa_004cf120` AllocateNewObjectFromCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cf120_AllocateNewObjectFromCbid.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Name is only “Failed” logger | Plate is the failure message of the allocator; body is full factory | **Falsified** rename-to-logger |
| 2 | `unaff_EDI>>24` is a real input flag from caller | Prologue `MOV EDI,ECX` (this); gate is stack hi-byte written 0/1 in body | **Falsified** decompiler |
| 3 | First stack arg is not cbid when template used | Template path overwrites EBX from `template+0x84` before GiveItem | **Survives** as override |
| 4 | `vtbl+8` second arg is masked flags uint | Bytes `PUSH EDI` (host this) | **Falsified** decompiler |
| 5 | Same as plain `GiveItemByCbid` | Adds init, template apply, host counter, attach virtuals | **Falsified** merge |
| 6 | stdcall with no this | `RET 8` + EDI host throughout | **Falsified** |

---

## 2. Live ≡ raw ≡ bytes

Live decompile matches 2026-07-23 raw structure. `read_memory` seals prologue/EDI, flag byte, plate push, counter, attach, `RET 8`. Callers match `get_function_callers` (2). Callees match (7 named + virtuals).

Decompiler pseudocode retained as raw authority for call order; clean **corrects** the two traps (flag source; vtbl+8 this arg).

---

## 3. Surviving contract

```
// ECX = sector-map host
// (cbid, templateId) → optional template override → GiveItemByCbid
// → vtbl+8 init → optional template apply → flag|0x10 → counter++ → attach
// RET 8; return obj* or 0
// Product name: AllocateNewObjectFromCbid
```

**Gaps kept:** nested product names; packedLocal intent beyond observed bytes.

**Verdict:** **accept-with-gaps**.
