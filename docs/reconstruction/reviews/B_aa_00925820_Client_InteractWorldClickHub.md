# Review B (skeptical / adversarial): `aa_00925820` `Client_InteractWorldClickHub`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925820` |
| **VA** | `0x00925820` |
| **Canonical name** | `Client_InteractWorldClickHub` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00925820_Client_InteractWorldClickHub.md` |
| **System** | `interaction-activation` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same as `Client_InteractClickPickTarget` | Different VA; no 25f `SendUseObject`; ItemPickup + destroy modal unique | **Falsified** alias |
| 2 | Always sends UseObject | Only `IfInteractable` on interact-match path; ItemPickup is `0x2055` | **Falsified** always-UseObject |
| 3 | Early gate enters when mode==6 quiet | Bytes: skip body (return 0) when mode==6 && flags quiet | **Falsified** inverted gate if misread |
| 4 | Ray length 25f (click gate) | `DAT_00aaa7ac` = **100.0f**; gather **20.0f** | **Falsified** 25f ray |
| 5 | Direct call sites everywhere | Only DATA vtable install | **Falsified** as direct multi-caller |
| 6 | ItemPickup without clearing select | Explicit `param_1[0x1d6]=0` then `FUN_0093e120(0)` | **Falsified** no-clear claim |
| 7 | ForPick sends UseObject | ForPick only `FUN_0093e120`; ForInteract adds IfInteractable | **Falsified** ForPick-send |
| 8 | Scaffold invents stages | Live ≡ raw; constants memory-sealed | **Attack fails** |
| 9 | Product name proven | Structural only | **Agree Open/Probable** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stage order + dual branches | **High** | Wrong interact client port |
| 100f ray / 20f gather | **Confirmed** | Wrong gather radius in AutoCore tools |
| ItemPickup + select clear | **Confirmed** | Sticky selection after loot click |
| ABI ret 8 / packed mouse | **Confirmed** | Wrong hook signature |
| Vtbl English / mode 6 meaning | **Open** | Docs only |
| Which UI event installs this slot | **Open** | Wrong “when does this fire” narrative |

---

## 3. Cross-check traps

### Gate polarity trap

Decompiler:

```
if ((mode != 6) || (flag493 != 0) || (worldF5 != 0)) { /* body */ }
// fallthrough return 0
```

Bytes match: **only** the triple-quiet mode-6 case skips the hub. Do not document as “mode 6 enables click.”

### 25f vs 20f/100f trap

`Client_InteractClickPickTarget` uses **25.0f** for UseObject distance. This unit uses **100.0f** ray scale and **20.0f** gather radius for `FUN_0058cd60` — different numbers, different role.

### ItemPickup ESI trap

`Client_SendItemPickup` has **no stack formals**; call sites load **ESI = TFID pair***. Clean rewrites must not invent a C parameter for the pair without noting the register ABI (see ItemPickup dual).

### Auth / drive trap

`CVOGHBBase_Stop` + `SetLongitudinalInput(0)` run only under `DAT_00d1a860 && client[0x31c]` — not every click. Do not claim universal input kill.

### Destroy modal trap

String + `0x4E4B` only on `char+0xCD0 != 0`. Not a general error dialog.

---

## 4. Surviving contract for AutoCore

```
Client_InteractWorldClickHub(client, param2, packedMouse):
  if mode==6 and !flag493 and !worldF5: return 0
  dispatch mouse vtbls (+0x430, +0x428)
  maybe Stop + longInput(0)
  maybe selected.vtbl+0x37C consume → return 1
  if dead/UI modals: return 0
  if !DAT_00d1a860: return FUN_0091a350()
  if char.cd0: ShowModalPrompt(destroy); return 1
  ray 100f; gather 20f mode 6
  if no TFID: walk hits → ForPick select / ForInteract+IfInteractable
  else: ItemPickup(0x2055); clear select; select(0)
  return 0

AutoCore must NOT:
  - merge this with ClickPickTarget 25f UseObject hub
  - treat ForPick path as UseObject send
  - use 25f as this unit's gather radius
  - assume direct non-virtual calls
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Multi-stage world-click hub | **Agree High** |
| Constants 100f/20f Confirmed | **Agree Confirmed** |
| ItemPickup clears select | **Agree Confirmed** |
| accept-with-gaps | **Agree** (English + sub-helpers + runtime) |
| Distinct from ClickPickTarget | **Agree High** |

---

## 6. Open questions

1. Product name for the vtable method / mode 6.
2. Live event that indexes slot `@ 0x00a2f420`.
3. `FUN_0093e120` dual (select chrome).
4. Whether hit-list path can both select and IfInteractable on same click for multiple hits (loop allows multiple).

**Verdict:** **accept-with-gaps** — adversarial pass on CF; residual is naming/runtime/sub-callees.
