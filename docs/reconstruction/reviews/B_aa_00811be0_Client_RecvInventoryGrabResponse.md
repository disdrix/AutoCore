# Review B (skeptical / adversarial): `aa_00811be0` Client_RecvInventoryGrabResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh) |
| **Counterpart** | `reviews/A_aa_00811be0_Client_RecvInventoryGrabResponse.md` |
| **Scratch** | `tmp/a_00811be0.md` |
| **Verdict** | **accept-with-gaps** on CF + dispatch/ABI/fields; runtime still open |

---

## 1. Claims under attack (post-residual)

| # | Claim | Attack result (2026-07-29) |
|---|---|---|
| 1 | Body proves opcode is always `0x2035` | Still **body-absent** — only special-cases `0x2039`. **Dispatch Confirmed** externally (PacketDispatch + sole xref). |
| 2 | Simple arm only helper+refresh (incomplete grab) | **Falsified.** Asm shows full `FUN_0093d6e0` with item/invType/count; grid remove lives in helper. |
| 3 | `EBX[0xe]` / `+0x38` means “is split” | **Falsified for grab.** Required for *any* success arm; success flag. Split is `@+0x20`. |
| 4 | Signature portable `__cdecl(client, packet)` | Formals unused — **Confirmed register** EAX/EBX from call site + prologue. |
| 5 | Split always attaches via sealed helpers | Partial: COID bind + cursor helper roles sealed; gfx/`FUN_004bc180` names still inferred. |
| 6 | Failure always user-visible | **Still falsified** for resolve fail (ODS only); split-create toasts. |
| 7 | This body clears C2S busy `DAT_00d1a8f6` | **Falsified** — not in xref set. |
| 8 | Decompiler 2-arg `FUN_0093d6e0(client,count)` is complete | **Falsified** — missing invType@+0x18 and item-in-EAX. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Early-out on 0x2039 | High | Wrong shared-slot handling |
| Dispatch 0x2035 → this VA | **Confirmed** | Dead handler |
| EAX=client / EBX=packet | **Confirmed** | Silent no-op / crash |
| Split create + qty peel CF | High | Stack desync |
| `+0x38` success / `+0x20` split | High | Wrong server field map |
| `+0x18` invType into cursor helper | High | Wrong grid on multi-inv grabs |
| Simple arm completeness | **High** (via helper) | — |
| Busy `DAT_00d1a8f6` lifecycle | External | Sticky busy if clearer missing elsewhere |
| Runtime split peel | Open | — |

---

## 3. Cross-check against raw + asm

Raw pseudocode CF authority holds. Residual **asm** corrects the call to the cursor helper:

```
// Whole-grab (0x00811d91..):
MOV ECX, [EBX+0x1c]     ; count
MOV DL,  [EBX+0x18]     ; inventoryType  ← decompiler dropped
PUSH ECX
PUSH ESI                ; client
MOV EAX, EBP            ; resolved item
CALL FUN_0093d6e0

// Split (after create; 0x00811d7x):
; ECX=EDI new stack for FUN_00512160(coidLo@+0x28, coidHi@+0x2c, 1)
; then FUN_0093d6e0 with EAX=EDI (new stack), same DL/count/client pattern
```

Clean preserves structure; plate must not claim 2-arg-only helper API.

---

## 4. Surviving contract for AutoCore

```
On S2C GrabResponse (0x2035) with client in EAX, packet in EBX:
  clear client+0xb6
  if opcode==0x2039: return
  resolve TFID @+0x08
  if !obj or !success@+0x38: debug fail; refresh; return
  invType = byte@+0x18; count = i32@+0x1c
  if !split@+0x20:
    GrabApplyToCursor(item=obj, invType, client, count); refresh; return
  peel count from source; spawn stack; SetCoidIdentity(new, splitCoid@+0x28, 1);
  init/set qty; GrabApplyToCursor(item=new, invType, client, count); refresh
Do not place into grid here (drop path owns place).
Do not treat +0x38 as split (that is DropResponse concat).
Wire +0x20 is SplitFlag (0 whole / nonzero split) — not AutoCore "AddToExistingItem" semantics.
```

---

## 5. Open questions

1. Runtime stack-split capture still open.
2. Who clears `DAT_00d1a8f6` after successful grab response (not this body).
3. Product names for `FUN_004bc180` / gfx reset chain.
4. AutoCore split emit (SplitCoid + SplitFlag=1) parity with client peel path.

**Verdict:** Safe as grab/split CF + sealed wire/ABI map; do not claim runtime seal or PDB names.
