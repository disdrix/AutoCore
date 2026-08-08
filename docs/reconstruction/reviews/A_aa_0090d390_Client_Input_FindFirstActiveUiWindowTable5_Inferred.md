# Review A (reconstruction fidelity): `aa_0090d390` Client_Input_FindFirstActiveUiWindowTable5_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d390` |
| **VA** | `0x0090d390`–`0x0090d3c4` inclusive (**53 B** / `0x35`) |
| **Canonical name** | `Client_Input_FindFirstActiveUiWindowTable5_Inferred` |
| **Ghidra name** | `FUN_0090d390` |
| **Prior scaffold** | `Named_CalleeOf_Client_Input_OnKeyDown_MatchAction_0090d390` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-096 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |
| **System** | `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` (full 53 B) + `get_assembly_context` (call sites) + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Find the first **active** UI window pointer in the fixed global 5-slot table `DAT_00d09a38[0..4]` (exclusive end `0x00d09a4c`). Active means non-null and `vtbl+0x3d8()` returns non-zero. Return that pointer in EAX, else 0.

```text
for i in 0..4:
  w = DAT_00d09a38[i]
  if w != null and w->vtbl[0x3d8/4]() != 0:
    return w
return null
```

Primary consumer is the ESC cancel path of `Client_Input_OnKeyDown_MatchAction`: if this returns non-null, dualed sibling `Client_Input_DismissUiWindowTable5_Inferred` (`0x0090dab0`) walks the same table and dismisses every slot.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-096 re-verify) | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.md` |
| Annotated | `docs/reconstruction/raw/aa_0090d390_FUN_0090d390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_Input_FindFirstActiveUiWindowTable5_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090d390.cpp` |
| Function record | `docs/reconstruction/functions/aa_0090d390_FUN_0090d390.md` |
| Named record | `docs/reconstruction/functions/aa_0090d390_Client_Input_FindFirstActiveUiWindowTable5_Inferred.md` |
| Live | decompile ≡ raw CF; full 53 B hex; 2 xrefs / 2 callers |
| Call sites | `0x0091106a` (OnKeyDown ESC), `0x0092cf32` (`FUN_0092cef0`) |
| Sibling | dualed dismiss walker `0x0090dab0` (MEGA-097) |

### Full body hex (sealed)

```
5633f6833cb5389ad0000074138b0cb5389ad0008b01ff90d803000084c0750c
83c60183fe057cdb33c05ec38b04b5389ad0005ec3
```

Both exits are plain **`RET`** (`C3` @ `0x0090d3bb`, `0x0090d3c4`). Index compare is **`CMP ESI,5`**. Virtual call displacement is **`0x3d8`** (`ff 90 d8 03 00 00`).

---

## 3. Signature (sealed)

```c
// no stack args; plain RET; EAX = window* or 0
// ECX used only as this for vtbl+0x3d8 thiscall
void* Client_Input_FindFirstActiveUiWindowTable5_Inferred(void);
```

| Slot | Source | Conf |
|---|---|---|
| stack args | none; `C3` both exits | **Confirmed** |
| ESI | loop index 0..4 (PUSH/POP ESI) | **Confirmed** |
| EAX return | table slot on hit; XOR EAX,EAX on miss | **Confirmed** |
| ECX | this for window vcall only | **Confirmed** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Index 0; do/while i < 5 | **Yes** | **Confirmed** |
| Null slot skip | **Yes** | **Confirmed** |
| thiscall vtbl+0x3d8 | **Yes** (`CALL [EAX+0x3d8]`) | **Confirmed** |
| Non-zero AL → return slot | **Yes** | **Confirmed** |
| Exhaust → return 0 | **Yes** | **Confirmed** |
| Named FUN callees | none (indirect only) | **Confirmed** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | small global-table scan / ESC any-active gate |
| External xrefs | **2** UNCONDITIONAL_CALL |
| Caller functions | `Client_Input_OnKeyDown_MatchAction`, `FUN_0092cef0` |
| Site role (primary) | ESC post-flag probe before dismiss walker |
| Site role (secondary) | supply window* for `vtbl+0x94` hide/close |

### Call-site context (sealed)

| Site | Pattern |
|---|---|
| `0x0091106a` | `MOV [EBX+0x50d],1` → `CALL 0090d390` → `TEST EAX` → if nz `MOV EAX,EBX` + `CALL 0090dab0` → `MOV AL,1` + `RET 8` |
| `0x0092cf32` | `CALL 0090d390` → `TEST EAX` → if nz `MOV ECX,EAX` + `JMP [vtbl+0x94]` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| 5-slot table `DAT_00d09a38` shared with dualed dismiss walker | **Yes** |
| Active gate via `vtbl+0x3d8` (same family as ESC client gate) | **Yes** |
| First-match return (not count / not dismiss) | **Yes** |
| ESC post-match callee of OnKeyDown | **Yes** |
| Product English for window classes | **No** → `_Inferred` |
| Scaffold Named_CalleeOf plate as role | **No** — retired |

Name: **`Client_Input_FindFirstActiveUiWindowTable5_Inferred`** — pairs with `Client_Input_DismissUiWindowTable5_Inferred` (`0x0090dab0`).

---

## 7. Gaps

1. Product English for the five UI window types (init sizes 0x554/0x5d8/0x604/0x54c/0x588 per MEGA-097 evidence).
2. Product names for `vtbl+0x3d8` / secondary `vtbl+0x94`.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
