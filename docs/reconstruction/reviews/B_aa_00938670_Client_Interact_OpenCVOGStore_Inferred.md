# Review B (skeptical / adversarial): `aa_00938670` Client_Interact_OpenCVOGStore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00938670` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-027) |
| **Counterpart** | `reviews/A_aa_00938670_Client_Interact_OpenCVOGStore_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Generic `Named_CalleeOf_Client_InteractClickPickTarget` is final name | **Falsified** — body is store-specific (RTTI `CVOGStore`, dialogs 0xB/0xC, opcode 0x2024) |
| 2 | ECX **thiscall** | **Falsified** — no `MOV ESI,ECX`; callers set **ESI**; ECX reused for entity/dialog/comm |
| 3 | `cdecl` / bare `RET` (no stack cleanup) | **Falsified** — epilogue **`RET 0x10`** (`C2 10 00`) |
| 4 | Always parks vehicle | **Falsified** — park triple only when `entity @ +0xe98→+0x250 != 0` |
| 5 | Opens inventory / mission / skill UI | **Falsified** — RTTI target is **CVOGStore**; dialog indices 0xB/0xC on store hosts |
| 6 | Sends UseObject **0x2072** | **Falsified** — packet opcode store is **0x2024** (not 0x2072) |
| 7 | Dynamic cast to CVOGCharacter / CVOGObject only | **Falsified** — TD push `0x00afe0c8` = `.?AVCVOGStore@@` |
| 8 | Single caller only (click pick) | **Falsified** — second site `FUN_00946c00` @ `0x00947057` |
| 9 | Dialog index always 0x0B | **Falsified** — branch on `store+0x4e5` selects **0x0B** vs **0x0C** |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |
| 11 | Product dialog English sealed without `_Inferred` | **Fails** — 0xB/0xC titles and `+0x4e5` English open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI client + RET 0x10 | **Confirmed** | Stack imbalance / wrong this |
| CVOGStore RTTI cast | **Confirmed** | Wrong interact target type |
| Vehicle park triple | **Confirmed** | Missing axis park on open |
| Opcode 0x2024 size 0x18 | **Confirmed** | Wrong C2S contract |
| Dialog 0xB/0xC selection | **Confirmed** | Wrong UI surface |
| Already-open early-out | **Confirmed** | Double-open / flicker |
| `FUN_007fef20` role = open dialog by index | **High** | Mis-wire dialog table |
| Product names 0xB/0xC / +0x4e5 | **Low** | Doc only |
| Runtime behavior | **Open** | Differential residual |

---

## 3. Cross-check against raw / bytes

```text
raw 2026-07-23 ≡ live decompile 2026-08-05 ≡ clean Client_Interact_OpenCVOGStore_Inferred.cpp

8B 86 98 0E 00 00     MOV EAX,[ESI+0xe98]
8B 88 50 02 00 00     MOV ECX,[EAX+0x250]
83 EC 18              SUB ESP,0x18
… park CALLS 004f3630 / 004f3620 / 004f5650 …
68 C8 E0 AF 00        PUSH CVOGStore TD
68 10 8E AF 00        PUSH ClonedObjectBase TD
E8 …                  Object_ResolveFromTFID + __RTDynamicCast
C7 44 24 08 24 20 00 00   MOV [ESP+8], 0x2024
… PUSH 0x0B / 0x0C …
8B CE                 MOV ECX,ESI
E8 …                  CALL FUN_007fef20
5F 5B 83 C4 18 C2 10 00   POP EDI; POP EBX; ADD ESP,18; RET 10

RTTI: ".?AVCVOGStore@@" @ 0x00afe0c8
RTTI: ".?AVCVOGClonedObjectBase@@" @ 0x00af8e10
```

Reject ports that:

- Name this only as anonymous click-pick callee.
- Use ECX thiscall without rewriting both call sites.
- Park vehicle unconditionally / skip park when entity present.
- Emit UseObject 0x2072 instead of 0x2024.
- Open a single hard-coded dialog ignoring `store+0x4e5`.
- Drop the already-open same-store early-out.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail: client store interact open (type 0x16 / event case 3)
// Port:
//   if (localVehicle != null) {
//       localVehicle.Flag109 = true;
//       localVehicle.Handbrake = true;
//       localVehicle.LongitudinalInput = 0;
//   }
//   var store = ResolveAndCastStore(tfid);
//   if (store == null) return;
//   if (StoreDialogAlreadyOpenOn(store)) return;
//   SendSector(0x2024, tfid, size: 0x18);
//   BindTfidToStoreDialog(store);
//   OpenDialog(store.SubtypeFlag == 0 ? 0x0B : 0x0C, force: true);
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/RTTI/callers. Product UI English residual only → **accept-with-gaps**.
