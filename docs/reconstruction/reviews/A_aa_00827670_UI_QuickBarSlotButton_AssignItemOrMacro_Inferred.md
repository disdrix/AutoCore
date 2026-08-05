# Review A (reconstruction fidelity): `aa_00827670` UI_QuickBarSlotButton_AssignItemOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00827670` |
| **VA** | `0x00827670` |
| **Body** | `0x00827670`–`0x00827918` exclusive (**680** B) |
| **Canonical name** | `UI_QuickBarSlotButton_AssignItemOrMacro_Inferred` (inferred) |
| **Ghidra symbol** | `FUN_00827670` |
| **Prior / alias** | CreateCharacter callee seed; plate `UI_macro_icon` (partial) |
| **Review date** | `2026-07-29` (W24-I OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| **System** | client UI / quickbar |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs/call sites (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

QuickBar **slot-button assign** for **item/macro-style** payloads (not skill objects):

1. Cache kind (EAX) + id64 on the button; flat slot = page*10+col.  
2. Mirror to character: **SetQuickBarItem(id)** then **SetQuickBarSkill(−1)**.  
3. Clear selection if bind changed; rebuild chrome (Power/Battle/Macro).  
4. Always return success **1**.

Primary rebind dispatch: table type **5** → this unit with **EAX=5**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00827670_FUN_00827670.md` (+ W24-I append) |
| Annotated | `docs/reconstruction/raw/aa_00827670_FUN_00827670.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00827670.cpp` |
| Function record | `docs/reconstruction/functions/aa_00827670_UI_QuickBarSlotButton_AssignItemOrMacro_Inferred.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` full 680 B |
| Call sites | `0x008a0e90` (mov eax,5; mov esi,button), `0x00828cb0` family |
| Twin skill | `aa_00826860` AssignSkill |
| Parent rebind | `aa_008a0e10` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal highlights

```
sub esp,0xC; push ebx/ebp; mov ebp,[esp+0x18]=id; push edi; mov edi,eax=kind
cmp [esi+0x548],edi / id64 → bChanged
store id, flatSlot, kind; [esi+0x558]=0
call SetQuickBarItem; call SetQuickBarSkill(-1)
optional SetSelected(0)
kind switch: sub edi,3 / -1 / -1 → cases 3,4,5
epilogue: mov al,1; add esp,0xC; ret 4
```

Strings: `"Power"`, `"Battle"`, `"i_d_macro_2d_wnd_icon.dds"`, `"(%d)"`, id display `id+0xbb9`.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Body exclusive end `00827918` | **pass** |
| ret 4 + AL=1 | **pass** |
| ESI button / EAX kind | **pass** (call sites) |
| Item set before skill clear | **pass** |
| Inverse of skill assign policy | **pass** |
| Decompiler unaff_ESI residual | **corrected** |

---

## 5. Gaps

1. Product English method name on slot-button class.  
2. Full icon vtbl English.  
3. Whether kinds 3/4 are live from any current caller (body supports them; sealed sites use 5).  
4. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
