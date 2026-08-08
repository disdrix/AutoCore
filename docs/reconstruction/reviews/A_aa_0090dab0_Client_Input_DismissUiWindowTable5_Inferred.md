# Review A (reconstruction fidelity): `aa_0090dab0` Client_Input_DismissUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dab0` |
| **VA** | `0x0090dab0`–`0x0090dad5` (**38 B** / `0x26`) |
| **Canonical name** | `Client_Input_DismissUiWindowTable5_Inferred` |
| **Ghidra name** | `FUN_0090dab0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-097) |
| **Counterpart** | `reviews/B_aa_0090dab0_Client_Input_DismissUiWindowTable5_Inferred.md` |
| **System** | input-drive-control |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `callees` + `get_xrefs_to` + `get_function_hash` + `read_memory` + parent call-site bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Nested OnKeyDown ESC helper: with client host in **EAX**, walk the 5-slot UI window pointer table `DAT_00d09a38`..`<0xd09a4c` and call `FUN_0090d400` per slot (dismiss-if-active + host notify).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-097 append) | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.md` |
| Annotated | `docs/reconstruction/raw/aa_0090dab0_FUN_0090dab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_DismissUiWindowTable5_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090dab0.cpp` |
| Parent | `Client_Input_OnKeyDown_MatchAction` @ `0x00911030` |
| Gate sibling | `FUN_0090d390` (same table; not dualled) |
| Per-slot worker | `FUN_0090d400` (not dualled) |

---

## 3. Signature (sealed)

```c
// EAX = client host*; no stack args; bare RET (C3)
void Client_Input_DismissUiWindowTable5_Inferred(void* /*eax*/ host);
```

| Formal | Source | Conf |
|---|---|---|
| host | EAX (`MOV EDI,EAX` / call-site `MOV EAX,EBX`) | **High** |
| return | void | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (bytes authority)

| Stage | Match | Conf |
|---|---|---|
| Prologue push EBX/ESI/EDI | `53 56 57` | **High** |
| Host capture | `8B F8` | **High** |
| Table base imm | `BB 38 9A D0 00` (`0xd09a38`) | **High** |
| Slot load + call | `8B 33` / `E8 …` → `0090d400` | **High** |
| Stride +4 | `83 C3 04` | **High** |
| End compare | `81 FB 4C 9A D0 00` (`0xd09a4c`) | **High** |
| Loop JL | `7C EE` | **High** |
| Epilogue + RET | `5F 5E 5B C3` | **High** |
| Slot count | `(0xd09a4c-0xd09a38)/4 = 5` | **High** |

---

## 5. Machine bytes

Full 38 B hex in raw MEGA-097 append. Entry: `53 56 57 8B F8 BB 38 9A D0 00 …`. Epilogue: `5F 5E 5B C3`. Hash `85eba3a5…`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | ESC UI-cancel nested helper (wrapper over table walk) |
| Code callers | `Client_Input_OnKeyDown_MatchAction` (2 UNCONDITIONAL_CALL) |
| Call sites | `0x00911075`, `0x00911893` — both `MOV EAX,EBX` then CALL |
| Callee | `FUN_0090d400` only |
| Parent gate | `FUN_0090d390()!=0` after flag `client+0x50d` set |

---

## 7. Gaps

1. Product English for five window types at table slots.  
2. Product names for vtbl methods exercised inside `FUN_0090d400`.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

CF/ABI/table bounds/call-site EAX-host reload/ESC role sealed. Product residual on window types and vtbl English → **accept-with-gaps**.
