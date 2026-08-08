# Review B (adversarial): `aa_00941f50` Client_UseInventoryItemByCoid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941f50` |
| **VA** | `0x00941f50` |
| **Canonical name** | `Client_UseInventoryItemByCoid` |
| **Review date** | `2026-08-04` (WQ8R-I dual seal) |
| **Reviewer role** | Adversarial / red-team reconstruction |
| **Counterpart** | `reviews/A_aa_00941f50_Client_UseInventoryItemByCoid.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

### 1. “Trust the decompiler invalid-COID return”

**Reject.** Decompiler emits `return uVar1 & 0xffffff00` (host pointer with AL cleared). Image on that arm is **`pop edi; xor al,al; pop esi; ret 0x0C`**. Seal **0**, not host-masked.

### 2. “This is thiscall ECX=client”

**Reject.** Entry is `push esi; mov esi,eax`. Call site places client in **EAX** (`mov eax,0xD1A840`). Not ECX-this.

### 3. “Find uses locker `+0xCBC` like 0092adf0”

**Reject.** This leaf: `host = *(char+0x250); ecx = *(host+0x2B0)` — **cargo** plate. Different grid from the target-filter unit.

### 4. “Always safe / checks item non-null”

**Accept as gap.** No `test eax` after Find before `mov edi,eax` / Use. Callers that pass missing COIDs can hand NULL EDI to `00941d50`. Not a CF mis-seal; residual robustness.

### 5. “Name overstates — only skill use”

**Reject overstatement claim.** Tail is full `Client_UseInventoryItem_Inferred`, which has equip **and** skill arms. Call site happens to skill-bit-gate before calling, but this leaf does not re-check the bit.

### 6. “Multiple callers hide complexity”

**Low risk.** Single static CALL xref. Dynamic/vtbl calls not observed; absence is residual not contradiction.

---

## Residual risks

| Risk | Severity | Mitigation |
|---|---|---|
| NULL item into Use | Med | Gap; callers must ensure COID in cargo |
| Orphan UI owner CF incomplete | Low | Site bytes sealed |
| Mode argument semantics beyond pass-through | Low | Forwarded to Use; equip arm uses it |

---

## Verdict

**accept-with-gaps** — adversarial review **confirms** byte corrections over decompiler and seals cargo COID→use. Does not block accept.
