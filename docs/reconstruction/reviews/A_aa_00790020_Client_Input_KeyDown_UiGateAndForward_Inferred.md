# Review A (reconstruction fidelity): `aa_00790020` Client_Input_KeyDown_UiGateAndForward_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00790020` |
| **VA** | `0x00790020`–`0x00790098` (**121 B** / `0x79`) |
| **Canonical name** | `Client_Input_KeyDown_UiGateAndForward_Inferred` |
| **Ghidra name** | `FUN_00790020` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-094) |
| **Counterpart** | `reviews/B_aa_00790020_Client_Input_KeyDown_UiGateAndForward_Inferred.md` |
| **System** | `input-drive-control` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **key-down** worker on client/UI host: gate (`vtbl+0x3D8`), forward key to focused UI (`+0x4BC` → child `vtbl+0x358`), ESC cancel (`vtbl+0x3BC(0)`) or secondary-modal dispatch (`vtbl+0x338(8, +0x49C)`). Returns 0 if gated off, else 1 / modal result.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-094 append) | `docs/reconstruction/raw/aa_00790020_FUN_00790020.md` |
| Annotated | `docs/reconstruction/raw/aa_00790020_FUN_00790020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_KeyDown_UiGateAndForward_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00790020.cpp` |
| Scaffold (retired) | `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_00790020.cpp` |
| Parent caller | `Client_Input_OnKeyDown_MatchAction` `aa_00911030` |
| Modal dual-id prior | `reviews/a_007fdfb0.md` (`+0x49C`, `vtbl+0x338(8,…)`) |

---

## 3. Signature (sealed)

```c
// ECX = this; stack key, lParam; AL return; RET 8
undefined4 __thiscall Client_Input_KeyDown_UiGateAndForward_Inferred(
    int *self, int key, undefined4 lParam);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| key | stack → `EDI` | **High** |
| lParam | stack | **High** |
| return | AL | **High** |
| cleanup | `C2 08 00` ×4 exits | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Gate `vtbl+0x3D8` → 0 return | `CALL [EAX+0x3D8]` / `TEST AL` / `JZ` | **High** |
| Focus `+0x4BC` forward `vtbl+0x358` | `CMP [ESI+0x4BC]` / `CALL [EDX+0x358]` | **High** |
| Non-ESC → return 1 | `CMP EDI,0x1B` / `MOV AL,1` / `RET 8` | **High** |
| ESC + UI → `vtbl+0x3BC(0)` return 1 | `PUSH 0` / `CALL [EDX+0x3BC]` | **High** |
| ESC + no UI + `+0x49C>=0` → `vtbl+0x338(8,code)` | `PUSH EAX; PUSH 8; CALL [EDX+0x338]` | **High** |
| Gate fail → XOR AL,AL | `32 C0` | **High** |

Live decompile **identical** to original raw body CF.

---

## 5. Machine bytes

Full 121 B hex in raw MEGA-094 append. Entry: `56 8B F1 8B 06 FF 90 D8 03 00 00 …`. All exits: `C2 08 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | shared virtual thiscall method (DATA vtbl ×~150) |
| Code callers | `Client_Input_OnKeyDown_MatchAction`, `FUN_00866220`, `FUN_008cc420` |
| Static callees | none (vcalls only) |
| Role vs parent | parent merges return into key low-byte; **not** DIK rewrite |

---

## 7. Gaps

1. Product English for `+0x4BC` focused object type.  
2. Product names for vtbl `+0x3D8` / `+0x3BC` / `+0x358` / `+0x338`.  
3. Owning RTTI class for primary vtbl family (many derived installs).  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/RET8/offsets/ESC/callers sealed against live Ghidra. Product residual on slot English → **accept-with-gaps**.
