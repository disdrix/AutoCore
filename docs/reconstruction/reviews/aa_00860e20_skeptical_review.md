# Skeptical / adversarial review: `Client_SendInventoryGrab_FromGrid` @ `0x00860e20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **Review type** | Skeptical / adversarial (try to falsify current interpretation) |
| **Date** | 2026-07-23 |
| **Scope** | C2S grab-from-grid send unit and package claims |
| **Verdict** | **needs-more-evidence** |

**Generic approval is insufficient.** Claims that survive are those that survived attack.

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` | Immutable decompile |
| `raw/aa_00860e20_*.annotated.md` | Scaffold notes |
| `reconstructed-exact/Client_SendInventoryGrab_FromGrid.cpp` | Clean surface |
| `functions/aa_00860e20_*.md` | Record status |
| `systems/inventory-transfer.md` | System narrative |
| `docs/inventory-cargo-wire-re.md` | Locker/grab wire claims |
| Sibling drop unit `aa_00860a50` | Compare send helper / busy flag |
| `docs/networking.md` (opcode table) | Cross-doc opcodes |

**Not performed:** fresh Ghidra re-decompile, disassembly of packet stack layout, CE/runtime, caller xrefs for EDI/param_1.

---

## 2. Evidence used (authoritative body)

Mechanical facts from raw alone:

1. Body builds a stack buffer with first dword `0x2034` and passes size `0x20` to a send vcall.
2. Item identifiers loaded from `*(resolve()+0x160/0x164)` and byte at `+0x168` (repeated resolve via EDI vtable `+0x3ac`).
3. Inventory type byte from `*(*(param_1+0x56c)+4)`.
4. Quantity / fourth field = stack `param_2`.
5. Gate on global `DAT_00d1a8f6`; after send path sets that global and `DAT_00d1b4b0`.
6. Returns constant `1` even if send path skipped.

---

## 3. Attack results (claim-by-claim)

### Claim 1 — This is C2S InventoryGrab opcode `0x2034` size `0x20`

| Sub-claim | Attack result |
|-----------|----------------|
| Immediate `0x2034` + size `0x20` in body | **Not broken.** Explicit in decompile. |
| Semantic name “InventoryGrab” | **Working name only.** Supported by plate + system map + wire RE, not by string in body. |
| Size is wire size of full grab struct | **Probable** — size is send length; field packing inside 0x20 not fully typed here. |

### Claim 2 — `ucTypeFrom` comes from window inventory type

| Sub-claim | Attack result |
|-----------|----------------|
| Byte loaded from `*(param_1+0x56c)+4` | **Not broken** as CF. |
| That byte is inventory type enum (cargo=1, locker=3, …) | **Probable** via wire RE / DropResponse switch parity; **not proven** inside this body. |
| `param_1` is inventory window | **Inferred** from plate “window+0x56c”; no caller seal in unit pack. |

### Claim 3 — Quantity is `param_2`

| Sub-claim | Attack result |
|-----------|----------------|
| Stored into packet slot `uStack_4` | **Not broken.** |
| Always means stack quantity | **Unproven type** — could be count, flags, or packed field; name “quantity” is plate narrative. |

### Claim 4 — Send path is the only side effect that matters

| Sub-claim | Attack result |
|-----------|----------------|
| Busy flag gate | **Holds** (`DAT_00d1a8f6`). |
| Pre-clear EDI block is optional noise | **Risky dismiss.** It mutates `DAT_00d1d8f4/f5` and may vcall destroy/clear on `DAT_00d1d8dc`. Port omitting it can desync cursor state. |
| Return value indicates success | **FALSIFIED as “sent OK”.** Always returns 1, including when busy skip omits send. |

### Claim 5 — Signature / calling convention is known

| Sub-claim | Attack result |
|-----------|----------------|
| `(int param_1, undefined4 param_2)` complete | **BROKEN.** `unaff_EDI` is a live input not in the formal signature. |
| Clean “uint32_t or float bits” return | **Cosmetic overclaim.** Raw returns `1` as `undefined4`; not float. |
| `__cdecl` vs thiscall vs custom | **Unsealed.** EDI usage suggests MSVC thiscall/fastcall residue or register-preserved UI object. |

### Claim 6 — Clean ≡ retail exact behavior

| Sub-claim | Attack result |
|-----------|----------------|
| Clean mirrors decompiler CF | **Yes.** |
| Decompiler ≡ retail | **Not sealed.** No asm / stack-frame validation; packet field packing relies on Ghidra stack var placement. |
| `g_pSectorNetConnection_INFERRED` correct global | **Name admits inference.** Drop path uses `Client_SendSectorPacket(&DAT_00d1a840,…)` — possible alternate/shared path; identity not proven here. |

### Claim 7 — Overconfident naming inventory

| Name | Warranted? | Attack |
|------|------------|--------|
| `Client_SendInventoryGrab_FromGrid` | Working | OK if Ghidra/plate; body has no string |
| `g_pSectorNetConnection_INFERRED` | Explicitly weak | Good honesty |
| “quantity from stack arg” | Tentative | Not typed |
| Partial scaffold status | Correct | Do not elevate without callers + layout |

---

## 4. Alternate interpretations

### Minimal hard reading

```
// EDI = some UI/object context; param_1 = window-like; param_2 = packet field
maybe_clear_cursor(EDI);
FUN_007fbbb0();
if (!DAT_00d1a8f6) {
  buf.opcode = 0x2034;
  fill_item_ids_from(resolve(EDI));
  buf.type = *(*(param_1+0x56c)+4);
  buf.field = param_2;
  send(connection, buf, 0x20);
  DAT_00d1b4b0 = 1; DAT_00d1a8f6 = 1;
}
return 1;
```

### Competing stories for pre-clear block

1. Clear conflicting mass-move / drag state when grabbing same object.
2. Tear down stale selection highlight.
3. Unrelated UI housekeeping mis-attributed to grab.

None selected by body alone.

---

## 5. What was confirmed despite skepticism

1. Opcode immediate `0x2034` and send length `0x20`.
2. Busy global gate + set after send path.
3. Type byte path through `param_1+0x56c` → `+4`.
4. Item id material from resolved object `+0x160/+0x164/+0x168`.
5. Clean does not invent extra logic beyond raw.

---

## 6. Critical contradictions found

### C1 — Return value vs “send success”

Package narrative “sends grab” can be read as success-returning API; body always returns 1 even when `DAT_00d1a8f6` blocks send. **Semantic overclaim risk.**

### C2 — Formal signature vs EDI

Any port typed as two-arg only is incomplete relative to decompile inputs.

### C3 — Send helper inconsistency across grab/drop siblings

Grab: raw connection vtable `+0x18`. Drop: `Client_SendSectorPacket(&DAT_00d1a840, size, buf)`. Not a body contradiction, but weakens “one sealed send API” claims without cross-map.

**Body CF contradictions:** none overturning opcode/size/gate shape.

---

## 7. Residual uncertainty

| # | Uncertainty | Blocks sealing? |
|---|-------------|-----------------|
| R1 | EDI identity / calling convention | Yes for exact port signature |
| R2 | Full 0x20 field map | Yes for server wire parity |
| R3 | Busy flag clearer | Yes for reentrancy/port |
| R4 | Runtime grab observed | Yes for “Verified” |
| R5 | Stack layout vs Ghidra vars | Mild–medium |

---

## 8. Concrete checks performed

1. Re-derived CF from raw alone (pre-clear → helper → busy → fill → send → flags → return 1).
2. Compared clean line-by-line to raw (match with type renames only).
3. Cross-checked opcode/size vs system map and wire RE.
4. Attacked return-value-as-success claim.
5. Attacked completeness of signature given `unaff_EDI`.
6. Compared send mechanism to drop sibling narrative.
7. Audited function-record status vs scaffold quality.

**Not done:** caller decompile, asm stack layout, live packet capture.

---

## 9. Verdict

### **`needs-more-evidence`**

Mechanical CF of the scaffold holds, but the interpretation package cannot honestly seal wire field layout, calling convention, or success semantics without callers + stack/asm + runtime. Clean faithfulness is not the same as semantic completeness.

### Acceptance bar for stronger verdict

1. Recover callers; seal EDI / `param_1` types.
2. Map 0x20 grab packet fields (prefer asm stack or server struct parity).
3. Identify busy-flag clear sites.
4. Runtime: one grab emit with known quantity/type.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Opcode/size | **Holds** |
| 2 | Type-from window | **CF holds; enum semantics Probable** |
| 3 | Quantity = param_2 | **Slot holds; meaning Tentative** |
| 4 | Return = success | **Falsified** |
| 5 | Signature complete | **Broken (EDI)** |
| 6 | Clean exact retail | **Decompiler scaffold only** |

**Final verdict: `needs-more-evidence`**
