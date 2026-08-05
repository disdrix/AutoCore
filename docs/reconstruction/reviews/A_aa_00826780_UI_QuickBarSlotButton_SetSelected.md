# Review A (reconstruction fidelity): `aa_00826780` UI_QuickBarSlotButton_SetSelected

| Field | Value |
|---|---|
| **Stable ID** | `aa_00826780` |
| **VA** | `0x00826780` |
| **Body** | `0x00826780`–`0x0082685e` |
| **Canonical name** | `UI_QuickBarSlotButton_SetSelected` (INFERRED) |
| **Review date** | `2026-07-29` (W17-N dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| **System** | client UI / quickbar |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). Context cross-check: ctor `0x00825bf0`, peer-clear `0x0089fef0`, page select `0x008a0ed0`, clear-active `0x008274c0`.

---

## 1. Purpose

Toggle **visual selected chrome** on one QuickBar slot-button: exclusive select (clear peers, highlight, stamp global page→column) or clear (unhighlight, alpha, clear global if matching). **No** network, **no** skill cast, **no** character QB bind mutation.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |
| Annotated | `docs/reconstruction/raw/aa_00826780_UI_QuickBarSlotButton_SetSelected.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_SetSelected.cpp` |
| Function record | `docs/reconstruction/functions/aa_00826780_UI_QuickBarSlotButton_SetSelected.md` |

---

## 3. Byte seal (`read_memory` @ `0x00826780`)

| Claim | Confidence | Evidence |
|---|---|---|
| `this` in **ECX**, one stack arg | **High** | `mov esi,ecx`; `mov bl,[esp+8]`; dual `ret 4` |
| Branch on `fSelected==0` first | **High** | `test bl,bl` / `jz` to clear block |
| Select gate kind `+0x548` ≠0 and ≠6 | **High** | `mov eax,[esi+0x548]`; `test/jz`; `cmp 6/jz` |
| RTTI cast parent `+0x88` → CDlgQuickBar | **High** | push RTTI `0x00afe3b4` / `0x00afe190`; `call __RTDynamicCast` |
| Peer clear via `FUN_0089fef0` (EAX=dlg) | **High** | immediate `call 0x0089fef0`; helper uses `in_EAX` |
| Highlight child `+0x56c` `vtbl+4(1|0)` | **High** | `push 1/0; call [eax+4]` |
| Global `DAT_00d1da38[page]=column` on select | **High** | `mov [ecx*4+0x00d1da38], edx` with page/column loads |
| Clear global only if match on clear | **High** | `cmp` then `mov dword …, -1` |
| Icon alpha `result+3=0xFF` on clear | **High** | `call [edx+0x164]`; `mov byte [eax+3],0xff`; `call [eax+0x34c]` |
| Store `+0x4fc` both paths | **High** | `mov [esi+0x4fc], bl` |
| Not QuickBarUpdate / cast | **High** | no sector net; no skill APIs in callees |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| fSelected branch | **Yes** |
| Kind gate 0/6 | **Yes** |
| Cast + exclusive peer clear | **Yes** |
| Highlight + global stamp + flag | **Yes** |
| Clear unhighlight + alpha + global clear | **Yes** |
| No wire side effects | **Yes** |

---

## 5. Lifecycle / callers (context)

| Caller | Role |
|---|---|
| `FUN_0089fef0` | exclusive clear of other selected slots |
| `FUN_008a0ed0` page select | clear all selected; may reselect |
| `FUN_00826860` skill assign | clear prior selected chrome when changing |
| `QuickBar_ClearActiveSlot_INFERRED` | clear when emptying active slot |
| Ctor `0x00825bf0` | seeds `+0x4fc=0` |

---

## 6. Gaps / open

1. Product/PDB English for method name (INFERRED from behavior + CDlgQuickBar RTTI).
2. Semantic English for payload kind **6** (rejected on select).
3. Full type names for widgets at `+0x56c` / `+0x564` and their vtbl slots.
4. Whether non-0/1 `fSelected` values are used in production callers.
5. Runtime / bit-exact / differential — open.

**Verdict:** **accept-with-gaps**
