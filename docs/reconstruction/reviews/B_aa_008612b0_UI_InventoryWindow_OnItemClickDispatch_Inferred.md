# Review B (skeptical / adversarial): `aa_008612b0` UI_InventoryWindow_OnItemClickDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008612b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (gap-close OWN dual) |
| **Counterpart** | `reviews/A_aa_008612b0_UI_InventoryWindow_OnItemClickDispatch_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as Path A. **No** `disassemble_bytes`. No Launcher / no runtime Confirmed.

---

## 1. Claims under attack

| # | Attack claim | Result |
|---|---|---|
| 1 | This VA **is only** the equip leaf / equals `00861200` | **Falsified** — 966 B multi-branch; equip is one CALL at `008615f4` |
| 2 | Unit is pure store-sell / equals drop helpers (`0x2036`) | **Falsified** — store is one `DAT_00d1bdfa` branch; non-store has UseObject/equip/skill paths; opcode here is **`0x2027`** size **`0x40`** |
| 3 | Code callers exist / not a vtable method | **Falsified** — sole xref DATA `@0x00a64b00` |
| 4 | ECX is item\* / dual-register like equip leaf | **Falsified** — `MOV EDI,ECX` window this; equip leaf reloads `ECX=EBX` (item) + `EAX=EDI` (window) |
| 5 | Bare `RET` cleanup | **Falsified** — all exits **`RET 0x8`** |
| 6 | Always succeeds / always closes | **Falsified** — multiple `XOR AL,AL` reject exits (store want, mode-3 flag, type 4, early fail) |
| 7 | RTTI is decorative / cast always fails | **Falsified** — cast result in EBX gates mode body; type strings sealed |
| 8 | Name without `_Inferred` / exact `OnEquipCommand` demangle | **Rejected** — host class / mode / formals / vtbl English open; equip-only name under-states CF |
| 9 | Merge with `Client_SendInventoryEquipC2S` or ConfirmEquip | **Falsified** — equip C2S lives under dualed leaf → ConfirmEquip → SendInventoryEquipC2S |
| 10 | Runtime Confirmed | **Rejected** — terminal false; no Launcher |

---

## 2. Surviving contract

```text
// ECX = inventory window this*; RET 0x8; AL bool
// vtable install @ 0x00a64b00

if (host[+0xcd0] || !window[+0x4b8]) → FUN_0085f220 early; maybe DAT_00d1b1f8 resolve; ret 0/1

itemWnd = RTTI_cast(window[+0x4b8], CNDUIWindow → CWndInventoryItem)
mode = *(window[+0x56c] + 4)   // 1 / 3 / 4

mode==4 → FUN_00861280; close vtbl[+0x33c](0); ret 1
mode==3 && !flag(DAT_00d1b644+0xf5) → ret 0

obj = itemWnd->vtbl[+0x3ac]()

if store(DAT_00d1bdfa):
  gates…; if !Item_IsWantedByStore → toast "The store does not want that item." (0x4e24); ret 0
  else SendSectorPacket(0x2027, size 0x40); ret 1

non-store:
  template word 0x3f4==8 → ret 1
  FUN_00524520 → UseObject_IfInteractable; close; ret 1
  flags bit19 → FUN_0093a330; close; ret 1
  template bit7 → UseInventoryItemByCoid; maybe FUN_007fbb70; close
  type 8 / 0x32 → stash TFID; PromptSkillTargetSelect; close
  else → TryEquipOrLockedToast(item, window)
close; ret 1
```

---

## 3. Residual risks (honest gaps)

| Risk | Severity | Mitigation |
|---|---|---|
| Host window product class stamp | Med | Child RTTI sealed; keep `_Inferred` |
| Mode 1/3/4 English | Med | Document values only; no invented UI labels |
| Opaque stack formals (`RET 0x8`) | Low–Med | Document unused-in-body; preserve cleanup |
| Packet field layout beyond opcode/size/TFID/IsBuy | Med | Cross-ref `vendor-store-useobject.md`; do not over-claim field map |
| Residual callees product names | Med | Leave FUN names; dualed children referenced by sealed names |
| Runtime click / store / equip | Med | Deferred (OWN-ONLY, no Launcher) |

---

## 4. What would flip to reject

- Live body diverging from raw CF (not observed 2026-08-05).
- Proof of code callers with different ABI (not observed — DATA only).
- Proof that store path is not `0x2027` / that string is unrelated (bytes seal both).
- Proof equip leaf is not entered with `ECX=item, EAX=window` (parent site seals it).

---

## 5. Verdict

Path B **cannot** reject the sealed CF/ABI/RTTI/string/opcode/vtable install/child dual chain. Naming stays **`_Inferred`**. Product English + runtime remain open.

**Verdict:** **accept-with-gaps**
