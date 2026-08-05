# Review B (skeptical / adversarial): `aa_0085fd20` Client_UI_InventorySheet_RemoveItemObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_0085fd20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0085fd20_Client_UI_InventorySheet_RemoveItemObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function finds item then removes | **Falsified** — no search; needs item* in EAX |
| 2 | Sets sheet pointer | **Falsified** — ESI untouched; wrapper only packs COIDs |
| 3 | Removes from grid cells | **Falsified** — callee is **sheet** hash/list UI (`0085fcc0`) |
| 4 | Destroys world object | **Falsified for this body** — sheet detach only (callee scope) |
| 5 | Push order lo then hi | **Falsified** — bytes push **hi then lo** (`+0x164` then `+0x160`) matching callee dual |

---

## 2. Surviving contract

```
// EAX=item*, ESI=sheet* (caller)
FUN_0085fcc0( *(item+0x160), *(item+0x164) )  // after push hi,lo stdcall order
```

Six xrefs including GrabApplyToCursor path — inventory sheet UI maintenance, not C2S.

---

## 3. Open

Per-caller sheet base offsets (see `0085fcc0` dual). Product English of wrapper.

**Verdict:** Adapter cannot be attacked. **accept-with-gaps.**
