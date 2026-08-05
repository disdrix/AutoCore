# Skeptical / adversarial review: `Client_RecvInventoryGrabResponse` @ `0x00811be0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | S2C grab response / stack-split client handler |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

Raw/annotated/clean/function record; system map; stack-split design spec; SendGrab C2S unit; DropResponse sibling; networking mass-move notes (GrabMM → GrabResponse 0x2035, early-out 0x2039).

**Not performed:** dispatch table seal, live split grab, server struct cross-read in this session.

---

## 2. Evidence used

Raw alone:

1. Ignores packets whose first dword is `0x2039`.
2. Resolves object by TFID from packet.
3. Requires extra packet flag `EBX[0xe] != 0` for “success” arm.
4. Two success sub-arms on `EBX[8]`.
5. Split arm creates new item via `CVOGReaction_GiveItemByCbid`, adjusts quantities, runs setup vcalls.
6. Failure mostly logs via `OutputDebugStringA` (not always UI toast).

---

## 3. Attack results

### Claim 1 — Handles InventoryGrabResponse `0x2035`

| Sub-claim | Result |
|-----------|--------|
| Body checks for `0x2035` | **ABSENT.** Only special-cases `0x2039`. |
| Plate / networking docs say 0x2035 | **External.** Needs dispatch evidence. |
| Shared jump with 0x2039 early-out | **Consistent** with plate + networking mass-move notes. |

### Claim 2 — Full grab + stack split both handled completely

| Sub-claim | Result |
|-----------|--------|
| Split path creates new stack object | **CF holds** when `EBX[8] != 0` and resolve/flag OK. |
| Simple path when `EBX[8]==0` | **Only** `FUN_0093d6e0` + UI refresh — **no place/remove from grid visible here**. |
| All successful grabs covered | **ATTACKED.** If simple path is “already moved to cursor,” work may be elsewhere; if not, path looks incomplete for a full grab. |
| Condition `EBX[0xe] != 0` required | **Odd if `0xe` means split-only.** On failure of that flag, goes to “Failed on coid” even if object resolved — suggests `0xe` may be **success/valid** not “is split”. |

### Claim 3 — `EBX[0xe]` is concat/split flag (by analogy to DropResponse `+0x38`)

| Sub-claim | Result |
|-----------|--------|
| Offset 0x38 used in both handlers | **Holds as offset.** |
| Same meaning | **Not proven.** Drop uses it inside swap arm; grab requires it for any success arm. **Different control use → dangerous to equate names.** |

### Claim 4 — Signature `__cdecl(client, packet)`

| Sub-claim | Result |
|-----------|--------|
| Header claims it | **Yes.** |
| Body uses args | **No** — uses `in_EAX`/`unaff_EBX`. |
| Portable reconstruction | **Broken** until registers mapped or args wired. |

### Claim 5 — Error handling is complete / user-visible

| Sub-claim | Result |
|-----------|--------|
| Split create fail uses UI toast `FUN_007fdfb0` | **Holds.** |
| Generic fail uses `OutputDebugStringA` only | **Holds** — **weaker** UX; easy to miss in retail without debugger. |
| Always clears busy / grab pending | **Not in this body** (no `DAT_00d1a8f6` clear seen). |

### Claim 6 — Clean exact finished

Scaffold fidelity **yes**. Semantic completeness **no**.

### Claim 7 — Overconfident naming

| Name | Attack |
|------|--------|
| `Client_RecvInventoryGrabResponse` | Working; opcode body-unproven |
| “Handles stack split / cursor object creation” | Split arm yes; cursor details in unnamed FUN/vcalls |
| Partial scaffold | Appropriate |

---

## 4. Alternate interpretations

### Minimal reading

```
void on_grab_like_s2c() {
  client->flag_b6 = 0;
  helper();
  if (pkt->opcode == 0x2039) return;
  obj = resolve(pkt->tfid);
  if (obj && pkt->byte_0x38) {
    if (!pkt->byte_0x20) { simple_cursor_update(); refresh(); return; }
    split_stack_and_make_cursor_object(); return;
  }
  debug_fail(); refresh();
}
```

### Competing flag stories for `+0x38`

1. Success boolean (fits grab’s required check).
2. Split/concat boolean (fits drop’s use; poor fit for grab’s mandatory check).
3. Multi-purpose field (different modes per opcode).

### Competing stories for simple arm

1. Server already applied inventory remove; client only updates cursor qty UI.
2. Incomplete decompile missing calls.
3. Simple arm is residual qty notify not full grab.

---

## 5. Confirmed despite skepticism

1. Early-out `0x2039`.
2. TFID resolve gate.
3. Distinct simple vs split success arms.
4. Split uses GiveItemByCbid + qty vfuncs `+0x25c/+0x260`.
5. Clean ≡ raw CF.
6. Failure path does not toast (except split create fail).

---

## 6. Critical contradictions / risks

### C1 — Opcode seal is external

Same class of risk as DropResponse.

### C2 — `+0x38` meaning conflict if shared name with drop concat/split

Grab requires nonzero for any success; drop uses inside swap/concat. **Do not unify names without evidence.**

### C3 — Simple success arm looks thin

Package claims “grab / stack split” may oversell simple arm as full grab apply.

### C4 — Busy flag not cleared here

C2S grab sets `DAT_00d1a8f6`; this S2C body does not clear it. Clearer may be `FUN_007fc150` / other — **not shown**. Risk: busy stuck if wrong path.

---

## 7. Residual uncertainty

| # | Item | Blocks seal? |
|---|------|--------------|
| R1 | Dispatch 0x2035 binding | Yes |
| R2 | Packet field dictionary | Yes |
| R3 | Simple arm semantics | Yes |
| R4 | Busy clear site | Yes |
| R5 | Runtime split grab | Yes |
| R6 | sprintf buffer size | Mild |

---

## 8. Concrete checks performed

1. Re-derived all arms from raw.
2. Compared flag uses of `EBX[0xe]` to DropResponse `+0x38`.
3. Noted missing busy clear vs SendGrab set.
4. Compared signature fiction vs register body.
5. Line-compared clean vs raw.
6. Cross-read networking mass-move early-out claim for 0x2039.
7. Attacked “complete grab apply in this function.”

---

## 9. Verdict

### **`needs-more-evidence`**

Scaffold CF is real; interpretation of packet flags, simple-arm completeness, opcode binding, and busy lifecycle are not sealed. Split path is the best-evidenced success story.

### Stronger-verdict bar

1. Dispatch table → this VA for 0x2035.
2. Server GrabResponse struct field map.
3. Decompile `FUN_0093d6e0` + busy clear xrefs.
4. Runtime: whole-stack grab vs partial split captures.
5. Wire formal params to EAX/EBX or recover true prototype.

---

## 10. Scorecard

| # | Claim | Result |
|---|-------|--------|
| 1 | Body is 0x2035 handler | **External only** |
| 2 | Full grab+split complete here | **Split partial; simple thin** |
| 3 | +0x38 = split flag | **Challenged** |
| 4 | Signature sealed | **Fail** |
| 5 | Errors always user-visible | **Fail** |
| 6 | Clean finished | **Scaffold only** |

**Final verdict: `needs-more-evidence`**
