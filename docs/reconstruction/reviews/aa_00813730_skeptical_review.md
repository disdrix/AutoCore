# Skeptical / adversarial review: `Client_RecvInventoryDropResponse` @ `0x00813730`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | S2C drop response handler + inventory-type binding claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Raw/annotated/clean/function record; system map; wire RE locker section; place unit `aa_00571620`; grab response sibling for dispatch/register patterns; networking mass-move early-out notes (`0x203B`).

**Not performed:** fresh decompile, packet struct from server C#, live drop swap/concat traces.

---

## 2. Evidence used

Raw alone proves:

1. Multi-stage validation then switch on packet byte `+0x1a`.
2. Multiple inventory object bindings (cargo/locker/trade/lookup).
3. Branch on swap flag `+0x23` and concat-ish `EBX[0xe]` (offset 0x38).
4. Placement attempts call `FUN_00571620` with X/Y from packet and item size vfunc `+0x25c`.
5. Early-out when first dword is `0x203b` (mass-move sibling response).
6. Failure strings: invalid inventory, add fail, swap fail, concatenate fail, server false.

---

## 3. Attack results

### Claim 1 — Opcode handled is DropResponse `0x2037`

| Sub-claim | Result |
|-----------|--------|
| Function early-outs `0x203b` | **Holds.** |
| Positive check for `0x2037` inside body | **ABSENT.** Body assumes dispatcher already selected it; only rejects 0x203b. |
| Plate “0x2037” | **Dispatcher-level claim**, not body-proven. Acceptable if dispatch table sealed elsewhere — **not in this unit pack**. |

### Claim 2 — Type map 1=cargo, 3=locker, 5=trade, 6=other

| Sub-claim | Result |
|-----------|--------|
| Case 1 binds `client+0x1040` / char `+0x250→+0x2b0` | **CF holds.** “Cargo” label Probable via system docs. |
| Case 3 binds `client+0x1034` / char `+0xcbc` | **CF holds.** Wire RE + enum docs support **locker**. |
| Case 5/6 trade-ish `+0xce0` | **CF holds**; “trade” name Probable (mission UI refresh hints commerce UI). |
| Labels sealed as retail enum names | **Not fully sealed** without packet enum cross-ref in unit artifacts. |

### Claim 3 — Non-swap path always places footprint

| Sub-claim | Result |
|-----------|--------|
| Place when not already at loc / not placed | **Partial.** Calls `FUN_00571b60` then compares vfuncs `+0x250/+0x254` to packet X/Y; place only if check fails (not placed or wrong pos). |
| “Always stamp on success” | **Overstated.** May skip place if already correct; may no-op path still refresh UI. |
| Place always succeeds on server success | **Falsified.** Client can still fail place and toast “Dropping failed trying to add…”. |

### Claim 4 — Register convention sealed

| Sub-claim | Result |
|-----------|--------|
| `in_EAX` client, `unaff_EBX` packet | **Consistent with Ghidra**; formal clean signature is `void` with unused plate args story. |
| Portable `__cdecl(client,packet)` | **Not demonstrated** in this clean (contrast grab response header). |

### Claim 5 — Swap/concat paths understood

| Sub-claim | Result |
|-----------|--------|
| Swap uses `FUN_00571010` on coids `EBX[10], EBX[0xb]` | **CF holds.** |
| Concat updates qty / mission paths | **CF holds at call level.** |
| Full retail stack-merge semantics | **Unsealed** — many vfuncs unnamed. |

### Claim 6 — Clean complete reconstruction

Faithful **scaffold** of a messy decompile — **not** a finished semantic port. Error: goto structure and repeated vtable resolves may hide real register reuse bugs from Ghidra.

### Claim 7 — Naming / status

| Name | Attack |
|------|--------|
| `Client_RecvInventoryDropResponse` | Working; body does not self-identify opcode 0x2037 |
| Partial scaffold | Appropriate — do not promote |
| System map “High” on type map | Stronger than unit pack alone; depends on external docs |

---

## 4. Alternate interpretations

### Minimal reading

Dispatch handler that, given a drop-related S2C blob, binds a target inventory object by type byte, then either:

- moves/places held cursor item into grid,
- swaps with occupant,
- or merges stacks,

with UI refresh and error toasts.

### Competing “success” stories

Server `success@+0x22` true only means server accepted; client place can still fail locally → desync risk if server already committed.

---

## 5. Confirmed despite skepticism

1. Early-out `0x203b`.
2. Fail path on `@+0x22==0`.
3. Four explicit type cases + default error.
4. Locker binding offsets match wire-RE narrative.
5. Place goes through `FUN_00571620`.
6. Clean does not drop major branches vs raw.

---

## 6. Critical contradictions / risks

### C1 — Dispatcher opcode not validated in body

Package “handles 0x2037” needs dispatch table evidence; body only special-cases 0x203b.

### C2 — Server success vs client place failure

Both can be true in sequence → interpretation that “DropResponse success always updates grid” is false.

### C3 — Case 1 early goto when `char+0x250==0`

Invalid path even for type 1 if vehicle/cargo parent missing — cargo label assumes that pointer is cargo inventory.

### Body internal CF contradictions

None found that overturn the switch + place structure.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Full packet schema | Yes |
| R2 | Dispatch binding to 0x2037 | Yes for opcode seal |
| R3 | Swap/concat field roles | Yes |
| R4 | Place callee correctness | Yes (depends aa_00571620) |
| R5 | Runtime multi-type round-trip | Yes |

---

## 8. Concrete checks performed

1. Walked every switch case and both swap/concat arms in raw.
2. Mapped plate offsets to EBX indexing (`[6]`→0x18 X, `+0x19` Y, `+0x22`, `+0x23`, `[0xe]`→0x38).
3. Compared clean to raw for branch parity.
4. Cross-checked case 3 offsets to wire RE.
5. Attacked “server success ⇒ client place always”.
6. Noted missing positive 0x2037 check.
7. Compared signature presentation to grab response sibling.

---

## 9. Verdict

### **`needs-more-evidence`**

Handler shape is real and scaffold-faithful; semantic completeness (opcode binding, packet schema, swap/concat, place success) is not sealed. Port risk is high if treated as finished.

### Stronger-verdict bar

1. Dispatch table entry for this VA ↔ 0x2037.
2. Server `InventoryDropResponse` struct field map.
3. Runtime cargo + locker + swap traces.
4. Stabilize place callee review (`aa_00571620`).

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Body proves 0x2037 | **Fail (dispatch-level)** |
| 2 | Type map | **CF holds; labels Probable–High with external docs** |
| 3 | Always place | **Overstated** |
| 4 | Signature sealed | **Fail** |
| 5 | Swap/concat full semantics | **Unsealed** |
| 6 | Clean exact finished | **Scaffold only** |

**Final verdict: `needs-more-evidence`**
