# Review B (skeptical / adversarial): `aa_007fc360` Client_DismissModalPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fc360` |
| **Review type** | Skeptical / adversarial (OWN-ONLY dual B / W17-M) |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007fc360_Client_DismissModalPrompt.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This **is** ShowModalPrompt / builds popup | No ctor, no `i_d_pop`, no OK/Cancel program; called **first** by show | **Falsified** as show — **dismiss** |
| 2 | Always sends `0x8006` | Gated by `client+0x30f4` | **Falsified** — optional pending only |
| 3 | `__stdcall` stack client | `MOV ESI,EAX`; plain `RET` | **Falsified** — **EAX client**, no stack this |
| 4 | Clears dual-id to zero | Copies from `+0x514/+0x518` | **Falsified** — **restore backups** |
| 5 | Panel flag `+0x4fd` only cleared when active | Label after active block still runs under outer gate | **Clarify** — cleared even if `+0x3d8` false |
| 6 | Slot loop includes index `0x16` | Explicit `CMP EDI,0x16` / skip | **Falsified** |
| 7 | `piVar1[0x140]` is byte flag | dword compare to **1** at +0x500 | **Clarify** — **dword == 1** |
| 8 | Packet size/layout wrong | bytes: size push `0x18`; opcode `0x8006`; `+0x14=9`; `+0x11=0` | **Sealed** |
| 9 | Only PacketDispatch uses it | 64 xrefs; input/ESC/login/show | **Falsified** as exclusive |
| 10 | Dual decompiles disagree | force ≡ decompile | **No conflict** |
| 11 | Name is retail symbol | No RTTI/string product name in body | **INFERRED only** — keep `FUN_007fc360` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dismiss vs show role | **High** | Wrong port wiring of modal lifecycle |
| Dual-id restore offsets | **High** | Modal codes stick / lose abandon pairing |
| Outer gate +0x1118/+0xf40 | **High** | Spurious dismiss |
| `0x8006` layout when pending | **High** | Wire mismatch |
| Opcode product semantics | Medium | Misnamed net message |
| Slot-scan product meaning | Medium | Wrong HUD restore side effects |
| INFERRED English name | Medium | Prefer stable id in code |

---

## 3. Cross-check: decompile vs bytes

| Step | Decompile | Bytes |
|---|---|---|
| Prolog | `in_EAX` client | `SUB ESP,0x18; PUSH ESI; MOV ESI,EAX` |
| Outer gate | panel & host non-null | load `+0x1118` / `+0xf40`; JE exit |
| Active | vtbl+0x3d8 | `CALL [EAX+0x3d8]` |
| Host notify | vtbl+0xb0(panel) | `PUSH panel; CALL [EDX+0xb0]` |
| Hide | vtbl+0x440 | `CALL [EDX+0x440]` |
| Packet | 0x8006 / FUN_008073b0 | immediates + CALL `0x008073b0` |
| Restore | 0x514→0x498, 0x518→0x49c | MOV pairs |
| Slot loop | 0..0x39 skip 0x16 | `CMP EDI,0x16` / `CMP EDI,0x3A` |
| Flag clear | panel+0x4fd=0 | `MOV byte [EAX+0x4fd],0` |
| Epilogue | return | `POP ESI; ADD ESP,0x18; RET` |

**Consensus:** accept.

---

## 4. Surviving contract for AutoCore

```csharp
// Shared client modal dismiss (EAX = game client). Not ShowModalPrompt.
void Client_DismissModalPrompt(ClientGame client)
{
    var panel = client.MessagePanel;      // +0x1118
    var hostHolder = client.ModalHostHolder; // +0xf40
    if (panel == null || hostHolder == null) return;

    if (panel.IsActive()) { // vtbl+0x3d8
        var host = hostHolder.Object;
        if (host != null) host.OnModalDismiss(panel); // +0xb0
        panel.HideDismiss(); // +0x440

        if (client.PendingOpcode8006) { // +0x30f4
            client.PendingOpcode8006 = false;
            client.Send(new byte[0x18] { /* opcode 0x8006, [0x14]=9, [0x11]=0 */ });
        }

        if (host != null) {
            host.DualIdPrimary = host.DualIdPrimaryBackup;     // 0x498 ← 0x514
            host.DualIdSecondary = host.DualIdSecondaryBackup; // 0x49c ← 0x518
        }

        if (client.SecondaryUi != null && !AnyBlockingSlot(client))
            client.SecondaryUi.SetMode(client.SecondaryModeByte); // +0x3c4(+0x31d8)
    }

    panel.Flag4fd = 0; // always when outer gate held
}
```

Server ports: only implement **`0x8006`** if matching pending client flag; do not invent dismiss as assert/stop.
