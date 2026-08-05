# Review B (skeptical / adversarial): `Client_ConfirmEquipOrCustomizeItem` @ `0x00941b20`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941b20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00941b20_Client_ConfirmEquipOrCustomizeItem.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is server equip authority | Body only toasts / modal / C2S send; no inventory mutation | **Falsified** — client gate |
| 2 | Always equips without checks | Multi-gate: char/vehicle, type 0xe town, type 4 reject, `FUN_004fabc0` reasons, space, permanent confirm | **Falsified** |
| 3 | Town-only applies to all items | Town branch only when `*(item[0x2a]+0x38)==0xe` and not-in-town and `char+0x6b4<1` | **Falsified as universal** — **stands as type-0xe conditional** |
| 4 | Permanent modal is the only path | Success can skip modal when `confirmFlag==0` or bit20 already set or `FUN_00513fc0` false | **Falsified as only path** |
| 5 | Emits UseItem **0x2045** | No 0x2045 construction; success is `FUN_00931440` → **0x203c** / **0x2053** | **Falsified** |
| 6 | Decompiler `in_EAX` is garbage | Call sites: `MOV EAX,ESI` / `MOV EAX,0xd1a840` before CALL; body uses `+0xe98` like client | **Stands as client this** |
| 7 | `0x4e59` is Yes | Open uses `MOV EAX,0x4e58`; stack secondary `0x4e59`; dispatch: 0x4e58 re-enters equip, 0x4e59 dismiss-only | **Falsified** — **0x4e58 Yes / 0x4e59 No** |
| 8 | `DAT_00d1e438` is unrelated global | `0xd1a840+0x3bf8 = 0xd1e438`; writes and Yes handler match | **Falsified** — alias of staging fields |
| 9 | Type 4 equips after space check | Entire equip body under `type != 4`; type 4 falls to `return 0` | **Falsified** |
| 10 | Space toast is only failure UX | `FUN_00931db0` maps many reason codes from `FUN_004fabc0` | **Falsified as only UX** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Client pre-gate only (no local equip apply) | **High** | Invented client-side equip state |
| Success C2S family 0x203c / 0x2053 via `FUN_00931440` | **Confirmed** | Wrong opcode in AutoCore send path |
| Permanent bind modal pairing 0x4e58/0x4e59 | **Confirmed** | Broken Yes/No handling |
| Bit20 skip after Yes (`FUN_00513e30`) | **Confirmed** | Infinite re-prompt loop |
| Equip fail reason enum via `FUN_00931db0` | **High** | Missing fail UX parity |
| `FUN_00522020` mode→grid map | **High** | Wrong inventory target for space check |
| Product name | **Tentative** | Naming churn only |
| Full 0x203c payload | **Open** (sibling) | Incomplete wire emulator |

---

## 3. Cross-check raw vs clean vs live

| Stage | Match |
|---|---|
| Prologue: `SUB ESP,0x10; item→EBP; EAX→ESI` | Yes (memory) |
| Epilogue success: `ECX=ESI; EAX=EBP; PUSH mode; CALL 0x00931440; MOV AL,1; RET 0xC` | Yes |
| Permanent open: store `+0x3bf8/+0x3bfc`; `MOV EAX,0x4e58`; push string; call toast helper | Yes |
| Three xrefs only (UseItem, UI equip, modal Yes) | Yes (`get_function_xrefs`) |
| Clean scaffold CF ≡ live decompile | Yes (no modernization drift) |

---

## 4. Surviving contract for AutoCore

```
Client_ConfirmEquipOrCustomizeItem(client, item, mode, confirmFlag) → 0|1
  Precondition: local char + vehicle + non-null item.
  Reject type 4 silently.
  Type 0xe: town (or char+0x6b4>=1) required else toast + 0.
  Precheck FUN_004fabc0 → on fail ShowEquipFailureMessage(reason) + 0.
  If displaced item needs space: probe grids; fail → space toast + 0.
  If confirmFlag && !bit20(item+0x17c) && permanent-bind probe:
      stage item/mode; modal 0x4e58/0x4e59; return 0.
  Else: send equip C2S (0x203c default / 0x2053 type 0xe); return 1.

Yes handler (UiModalDispatch 0x4e58):
  FUN_00513e30(item, 1);  // set bit20
  ConfirmEquip(item, mode, confirmFlag=0);
  close modal.

No handler (0x4e59): close only.
```

Do **not** fold this into InventoryUseItem **0x2045**.

---

## 5. Open questions (residual)

1. Product symbol / RTTI.
2. Exact C2S **0x203c** field map beyond TFID + mode (sibling `aa_00931440`).
3. `char+0x6b4` meaning.
4. Live wire validation.

**Verdict:** **accept-with-gaps** — adversarial checks reinforce client gate + modal + equip packet family; residual is naming and full packet layout ownership of callee.
