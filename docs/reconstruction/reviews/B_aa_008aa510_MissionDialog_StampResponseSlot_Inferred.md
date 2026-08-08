# Review B (skeptical / adversarial): `FUN_008aa510` @ `0x008aa510`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_008aa510_MissionDialog_StampResponseSlot_Inferred.md` |
| **Work item** | MEGA-046 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** on stamp CF + register ABI + offsets; product names / TFID domain open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `unaff_ESI` / `unaff_EDI` are decompiler junk | All 6 sites set ESI=index and EDI=dialog (`MOV EDI,EBX`) before CALL; body only uses those regs for host/index | **Falsified** — deliberate ABI |
| 2 | This is `__fastcall` ECX=this | ECX is scratch (loads widget); no `MOV reg,ECX` this at entry; callers never set ECX as dialog | **Falsified thiscall/fastcall-this** |
| 3 | Function clears all slots | Only one slot path; no loop; no −1 stores unless caller pushes −1 | **Falsified as clear** — clear is peer `008aa560` |
| 4 | Stamps reward chrome (`+0x558` / `+0x698`) | Stores only `+0x518` / `+0x51c` and widgets `+0x708` | **Falsified as reward** — reward is `008aa3f0` / `008aa760` |
| 5 | Creates / destroys widgets | No `operator_new`; no vtbl+0xBC; only set-text + refresh | **Falsified create/destroy** — rebuild is `008ac110` |
| 6 | Sends network / response packet | No sector send; only UI vtbl + local stores | **Falsified packet** |
| 7 | Plain `RET` / no stack args | Bytes end `C2 08 00`; callers push two dwords | **Falsified plain RET** |
| 8 | `Named_CalleeOf_Client_ShowNpcMissionDialogUI` is product name | Auto plate from one parent; second parent `FUN_0093e450` also calls | **Demote** scaffold — retired MEGA-046 |
| 9 | Sole caller is ShowNpcMissionDialogUI | Xrefs: 4 in Show + 2 in `FUN_0093e450` | **Falsified sole-caller** (Ghidra callers list incomplete) |
| 10 | EDX is TFID | EDX pushed as caption before stack TFID load overwrites EDX | **Falsified EDX=TFID** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI dialog + ESI slot | **High** | Wrong host/index stamped |
| EDX caption + stack TFID | **High** | Caption/TFID swapped in port |
| `RET 8` | **High** | Stack imbalance |
| +0x510 / +0x518 / +0x708 | **High** | Wrong banks vs clear peer |
| Set-text + refresh ordinals | **High** role | UI no-op if wrong ordinal |
| Product English | **Open** | Registry noise |
| Dynamic TFID meaning | **Tentative** | Wrong HandleButton mapping |

---

## 3. Cross-check spine

```
// EDI = dialog, ESI = slot, EDX = caption
// stack: tfidLo, tfidHi; RET 8
if (ESI < 0 || ESI >= dialog->count_at_0x510) return;
w = dialog->widgets_0x708[ESI]
if (w):
  w->vtbl[0x1d8](caption, 1, 1)
  w->vtbl[0x34c]()
dialog->tfid_0x518[ESI] = {tfidLo, tfidHi}
```

### What this unit is **not**

| Non-claim | Why |
|---|---|
| Clear-all wipe (`FUN_008aa560`) | no loop; no −1 hardcoded; no destroy |
| Reward slot select (`FUN_008aa3f0`) | different banks +0x558/+0x698 |
| XML rebuild (`FUN_008ac110`) | no widget create |
| HandleButton / click | no input path |
| Packet send | no network |

### Caption evidence (falsifies non-UI roles)

| String VA | Text | Used as EDX at |
|---|---|---|
| `0x00a2d33c` | Complete | `00943abe` |
| `0x00a2d338` | OK | `00943b12` |
| `0x00a2d330` | Accept | `00943b48` |
| `0x00a2d328` | Decline | `00943b5b` |
| `0x00a2d364` | Work in progress | `0093e6c7` |

---

## 4. Residual attacks left open

1. Are the two stack dwords always a TFID pair, or sometimes a different 64-bit key? (Static paths always −1/−1; dynamic path from `FUN_0057a250` still residual.)
2. Exact product names for vtbl+0x1d8 / +0x34c.
3. Capacity: bounds use live count at +0x510, not hardcoded 8 (unlike clear). Could count exceed widget bank capacity? (Rebuild path sets count then stamps; not sealed beyond observed 1–2 and choice loop.)

---

## 5. Verdict

**accept-with-gaps** — adversarial pass cannot break single-slot stamp CF, EDI/ESI/EDX+stack TFID ABI, `RET 8`, or shared response banks with clear peer. Product English and dynamic TFID domain remain open. No runtime Confirmed.
