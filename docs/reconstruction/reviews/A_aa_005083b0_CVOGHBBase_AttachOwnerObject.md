# Review A (reconstruction fidelity): `aa_005083b0` CVOGHBBase_AttachOwnerObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083b0` |
| **VA** | `0x005083b0` |
| **Canonical name** | `CVOGHBBase_AttachOwnerObject` |
| **Review date** | `2026-07-29` (machine seal; prior scaffold accept 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005083b0_CVOGHBBase_AttachOwnerObject.md` |
| **System** | `heartbeat` / timed-action infrastructure |
| **Live tools** | Ghidra `decompile_function` + `force_decompile` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (body High; callee *this* corrected vs decompiler) |

---

## 1. Purpose

Rebind `CVOGHBBase.pOwnerObject` at **`HB+0x18`** to `pOwnerObject` (stack arg). When the **prior / new** owner has a non-null list-manager pointer at **`owner+0xB0`**, maintain that owner's HB membership list:

1. **Detach** this HB from the old owner's list manager (`FUN_005085b0`) if old owner and `*(old+0xB0)` are non-null.
2. **Store** new owner pointer at `HB+0x18` (including null).
3. **Attach** this HB to the new owner's list manager (`FUN_00508490`) if new owner and `*(new+0xB0)` are non-null.

Null owner is legal: store clears the slot; attach is skipped. List ops are skipped when `owner+0xB0 == 0` (no list manager installed).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005083b0_CVOGHBBase_AttachOwnerObject.md` |
| Annotated | `docs/reconstruction/raw/aa_005083b0_CVOGHBBase_AttachOwnerObject.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_AttachOwnerObject.cpp` |
| Function record | `docs/reconstruction/functions/aa_005083b0_CVOGHBBase_AttachOwnerObject.md` |

---

## 3. Seal: body bytes (High)

`get_function_by_address`: entry `005083b0`, body `005083b0`–`005083ec` (**60 bytes**).  
`read_memory` @ `0x005083b0` length 64 (body + `CC` pad):

```
005083b0  56                 push esi
005083b1  8B F1              mov  esi, ecx                 ; ESI = this HB
005083b3  8B 46 18           mov  eax, [esi+0x18]          ; old pOwnerObject
005083b6  85 C0              test eax, eax
005083b8  74 12              jz   store                    ; no old → skip detach
005083ba  8B 80 B0 00 00 00  mov  eax, [eax+0xB0]          ; listMgr = *(oldOwner+0xB0)
005083c0  85 C0              test eax, eax
005083c2  74 08              jz   store                    ; no listMgr → skip detach
005083c4  56                 push esi                      ; stack arg = HB*
005083c5  8B C8              mov  ecx, eax                 ; ECX this = listMgr (NOT HB)
005083c7  E8 E4 01 00 00     call FUN_005085b0             ; target 0x005085b0
005083cc  store:
005083cc  8B 44 24 08        mov  eax, [esp+8]             ; pOwnerObject (after push esi)
005083d0  85 C0              test eax, eax
005083d2  89 46 18           mov  [esi+0x18], eax          ; ALWAYS store (null ok)
005083d5  74 12              jz   epilogue                 ; null new → skip attach
005083d7  8B 80 B0 00 00 00  mov  eax, [eax+0xB0]          ; listMgr = *(newOwner+0xB0)
005083dd  85 C0              test eax, eax
005083df  74 08              jz   epilogue
005083e1  56                 push esi                      ; stack arg = HB*
005083e2  8B C8              mov  ecx, eax                 ; ECX this = listMgr
005083e4  E8 A7 00 00 00     call FUN_00508490             ; target 0x00508490
005083e9  epilogue:
005083e9  5E                 pop  esi
005083ea  C2 04 00           ret  4                        ; __thiscall, 1 stack arg
```

Hex (60 bytes):  
`56 8b f1 8b 46 18 85 c0 74 12 8b 80 b0 00 00 00 85 c0 74 08 56 8b c8 e8 e4 01 00 00 8b 44 24 08 85 c0 89 46 18 74 12 8b 80 b0 00 00 00 85 c0 74 08 56 8b c8 e8 a7 00 00 00 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| Body **60 bytes**; ends `pop esi; ret 4` | `read_memory` + range `005083b0–005083ec` | **High** |
| **`__thiscall`**: ECX = HB; **1 stack arg** `pOwnerObject`; callee cleans 4 | `mov esi,ecx`; `ret 4` | **High** |
| **`HB+0x18` = pOwnerObject** | `8B 46 18` load; `89 46 18` store | **High** |
| Gate detach on old non-null **and** `*(old+0xB0)` non-null | dual `test/jz` | **High** |
| Gate attach on new non-null **and** `*(new+0xB0)` non-null | dual `test/jz` | **High** |
| Store to +0x18 is **unconditional** after detach block (null clears) | `mov [esi+18],eax` before attach `jz` | **High** |
| **`FUN_005085b0` this = listMgr** (`*(old+0xB0)`), arg = HB | `push esi; mov ecx,eax; call` | **High** |
| **`FUN_00508490` this = listMgr** (`*(new+0xB0)`), arg = HB | same shape | **High** |
| Relative CALL targets exact | `E8 E4010000` → `0x005085b0`; `E8 A7000000` → `0x00508490` | **High** |
| Decompiler CF shape matches (gates + store + callees) | force_decompile ≡ raw | **High** |
| Decompiler **mis-attributes callee this as HB** | plate/pseudocode `FUN_*(this)` vs machine ECX=listMgr | **High** (machine wins) |

### Decompiler A/B

| Pass | Tool | Result |
|---|---|---|
| A | `decompile_function` @ `0x005083b0` | gates + store + `FUN_005085b0` / `FUN_00508490`; plate names offsets |
| B | `force_decompile` @ `0x005083b0` | **identical** pseudocode body |

Pseudocode (both passes) is **behavior-correct on gates/store** but **wrong on callee ECX** (shows HB as sole arg / implied this). Machine is authoritative for call shape.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Control flow (detach gate → store → attach gate) | **High** | Machine sealed |
| `HB+0x18` owner pointer | **High** | Load/store |
| `owner+0xB0` = **pointer to list manager object** (not embedded head) | **High** | loaded then used as `this` |
| Callee this ≠ HB | **High** | `mov ecx, eax` after load from +0xB0 |
| Null owner allowed / clears slot | **High** | store then jz |
| Helper names / full list-node schema | **Probable** | bodies read for call shape; residual naming |
| Owner type always SimpleObject vehicle/character | **Tentative** | callers also pass skill runtime (e.g. OKToCastAgain_ctor) |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Detach if old && old→listMgr | **Yes** |
| Store owner at +0x18 | **Yes** |
| Attach if new && new→listMgr | **Yes** |
| Callee this = listMgr (clean corrected 2026-07-29) | **Yes** (prior clean wrongly passed HB as sole C arg without ECX listMgr) |
| No invented list walk in this unit | **Yes** |

---

## 6. Call / xref inventory (this unit)

### Callees (from body)

| VA | Role | Call shape (machine) |
|---|---|---|
| `0x005085b0` `FUN_005085b0` | Remove HB from list manager | `__thiscall` listMgr, stack HB* |
| `0x00508490` `FUN_00508490` | Insert HB into list manager | `__thiscall` listMgr, stack HB* |

### Callers (`get_function_callers` / xrefs) — partial named set

| Owner | VA region | Notes |
|---|---|---|
| `CVOGHBOKToCastAgain_ctor` | `0x0051e240` | attach skill runtime |
| `CVOGHBRegeneration_ctor` | `0x005fbdb0` | regen HB |
| `CVOGHBSkillBase_ctor` | `0x005788d0` | skill HB base |
| `Vehicle_CreateWeaponTrackAction` | `0x005a4f60` | weapon track |
| `TimedAction_CreateTokenFlagAction` | `0x005ffbd0` | token flag (×2 sites) |
| `FUN_005075f0`, `FUN_00578430`, `FUN_00578830`, `FUN_005b3210` (×2), `FUN_005d1990`, `FUN_005d6b80`, `FUN_005d8360`, `FUN_005dabc0`, `FUN_005fc1f0` (×2), `FUN_005fe6a0`, `FUN_00604d40`, `FUN_006061e0`, `FUN_0060b380` (×2), `FUN_006238a0`, `FUN_006264e0`, `FUN_00626530`, `FUN_006270b0`, `FUN_00632850`, `FUN_006335b0`, `FUN_00636bd0` (×2), `FUN_006428e0`, `FUN_00642a90`, `FUN_00650510` (×2), `FUN_006507c0`, `FUN_00650d30` | various | HB / timed-action ctors & rebinds |

~36 unconditional CALL xrefs — widespread HB construction / rebind surface.

---

## 7. Gaps / open

1. Canonical names for `FUN_00508490` / `FUN_005085b0` (list insert/remove).
2. Publish `owner+0xB0` list-manager type in SimpleObject (or skill) layout docs.
3. Full list-node schema residual (vtable free at node+0; payload at +4; next/prev +8/+0xC; CS at mgr+4; head +0x1c; count +0x24; closed +0x28) — observed on helpers, **not owned** here.
4. Owner polymorphic type (vehicle / character / skill runtime / other).
5. Bit-for-bit / runtime differential: **deferred**.

**Verdict:** **accept** (body + call-shape High; helper names residual)
