# Review A (reconstruction fidelity): `aa_008aa3f0` dialog select reward slot

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa3f0` |
| **VA** | `0x008aa3f0` |
| **Canonical name** | `FUN_008aa3f0` (product alias: **Dialog_SelectRewardSlot** / auto-select reward slot) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008aa3f0_Dialog_SelectRewardSlot.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Select mission-dialog **reward slot `param_1` (0..3)** on the dialog host:

1. Copy 8-byte TFID from slot table `dialog+0x558 + slot*8` / `+0x55c + slot*8` into selected pair **`dialog+0x578` / `+0x57c`**.
2. For each of **4** chrome widgets at `dialog+0x698[i]` (stride 4): apply **unselected** style via `vtbl+0x158(0, dialog+0x594)` then `vtbl+0x34c` refresh.
3. Re-apply **selected** style on widget `dialog+0x698 + slot*4` via `vtbl+0x158(0, dialog+0x5a4)` then `vtbl+0x34c`.
4. If hint widget `dialog+0x708` non-null: `vtbl+0x308(&DAT_00a1419b)` — **clear** “must choose” hint (empty C-string).

Does **not** send packets. Does **not** gate on `+0x64c` (callers gate). Does **not** validate slot range.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_008aa3f0` @ `0x008aa3f0` (2026-07-29) ≡ raw |
| Live bytes | `read_memory` `0x008aa3f0` length 80 |
| Raw | `docs/reconstruction/raw/aa_008aa3f0_FUN_008aa3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa3f0_FUN_008aa3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008aa3f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_008aa3f0_FUN_008aa3f0.md` |
| Empty hint string | `DAT_00a1419b` first byte `0x00` (`read_memory`) |
| Call sites | `get_assembly_context` xrefs `0x008aa968`, `0x008aed23` |
| Caller A | `FUN_008aa760` reward chrome — auto-select slot 0 |
| Caller B | `FUN_008aec40` UI event dispatch — click reward ids `0x9c42..0x9c45` |
| Parent duals | `A/B_aa_008aa760_DialogRewardChrome.md`, `tmp/a_008aec40.md` |

---

## 3. Signature / framing — **SEALED**

```c
// Register this: EAX = dialog UI host (not ECX __thiscall)
// Stack: param_1 = reward slot index (0..3 expected; no clamp)
// Callees: only indirect UI vtbl methods
void FUN_008aa3f0(int slotIndex);  // EAX = dialog
```

| Evidence | Detail |
|---|---|
| Prologue bytes | `53 55 56 57 8B F8` → push EBX/EBP/ESI/EDI; **`MOV EDI,EAX`** |
| Slot load | `8B 44 24 14` → `MOV EAX,[ESP+0x14]` (arg after 4 pushes) |
| Call site chrome | `PUSH 0` ; `MOV EAX,EDI` ; `CALL 0x008aa3f0` @ `0x008aa968` |
| Call site click | `LEA EAX,[EBX+0xFFFF63BE]` (= `id-0x9c42`); `PUSH EAX`; `MOV EAX,ESI`; `CALL` @ `0x008aed23` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `EAX` = dialog host on entry | **High** | Prologue `MOV EDI,EAX`; both callers set EAX = host |
| `param_1` = slot index 0..3 | **High** | Click: `controlId - 0x9c42`; chrome auto: imm `0` |
| Copy slot TFID → `+0x578/+0x57c` | **High** | Bytes `…[EDI+EAX*8+0x558] → [EDI+0x578]`; same for `+0x55c→+0x57c` |
| Slot TFID base `+0x558`, stride 8 | **High** | Decomp + `MOV ECX,[EDI+EAX*8+0x558]` |
| Widget array `+0x698`, count 4, stride 4 | **High** | `LEA ESI,[EDI+0x698]`; `MOV EBX,4`; `ADD ESI,4` |
| Unselected style blob `dialog+0x594` | **High** | `LEA EBP,[EDI+0x594]`; push EBP + push 0 → `vtbl+0x158` |
| Selected style blob `dialog+0x5a4` | **High** | Second `vtbl+0x158(0, +0x5a4)` on selected widget only |
| `vtbl+0x158` = apply style/state | **Tentative** (product name) | Ordinal only; args `(0, stylePtr)` consistent with hover path |
| `vtbl+0x34c` = refresh/invalidate | **Tentative** | Shared with chrome caption refresh |
| `vtbl+0x308` = set text | **Tentative** | Same ordinal as multi-reward hint in `FUN_008aa760` |
| `DAT_00a1419b` = empty string clear | **High** | `read_memory` first byte `0x00` |
| Hint clear only if `+0x708 != 0` | **High** | Decomp guard |
| No null-check on `+0x698` widgets | **High** | Loop derefs `*puVar2` unconditionally |
| No range clamp on `param_1` | **High** | No CMP/JA on slot |
| Does not test `+0x64c` | **High** | Callers gate turn-in flag |
| Two static callers only | **High** | Xrefs `0x008aa968`, `0x008aed23` only |
| Product name | **Tentative** | Scaffold / role alias; not retail symbol |
| Exact TFID field order (lo/hi) | **High** layout / **Tentative** names | Matches ResolveObjectTarget(lo,hi) elsewhere |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live Ghidra | Clean |
|---|---|---|---|
| TFID copy slot → selected | Yes | Yes | Yes |
| Loop 4× unselected style + refresh | Yes | Yes | Yes |
| Selected slot style + refresh | Yes | Yes | Yes |
| Optional clear hint `+0x708` | Yes | Yes | Yes |
| Invented clamps / deleted branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 6. Param / local renames (evidence only)

| Raw | Meaning | Evidence |
|---|---|---|
| `in_EAX` / EDI | dialog UI host | Prologue + callers |
| `param_1` | reward slot index | Click id−0x9c42; chrome pushes 0 |
| `puVar2` / ESI | cursor over `+0x698` widget ptrs | `LEA ESI,[EDI+0x698]`; `ADD ESI,4` |
| `iVar1` / EBX | countdown 4 | `MOV EBX,4` |
| EBP | `dialog+0x594` unselected style | `LEA EBP,[EDI+0x594]` |

### Dialog offsets written / read

| Offset | Role | R/W |
|---|---|---|
| `+0x558/+0x55c + slot*8` | per-slot reward TFID | R |
| `+0x578/+0x57c` | selected reward TFID | W |
| `+0x594` | unselected style param block | R (ptr) |
| `+0x5a4` | selected style param block | R (ptr) |
| `+0x698..+0x6a4` | 4 reward chrome widget ptrs | R |
| `+0x708` | choose-reward hint widget | R (optional) |

---

## 7. Call graph (this unit)

```
FUN_008aa760 (reward chrome fill)
  └─ when +0x514==1 && +0x64c≠0: FUN_008aa3f0(0)     // auto-select sole reward

FUN_008aec40 (mission dialog UI events)
  └─ controlId ∈ {0x9c42..0x9c45}, msg==8, +0x64c≠0:
        FUN_008aa3f0(controlId - 0x9c42)             // multi-choice click select
        then FUN_0087b500(8, controlId)

FUN_008aa3f0
  └─ indirect only: widget vtbl+0x158, +0x34c, (+0x708) vtbl+0x308
```

**Downstream (not this unit):** `Client_MissionDialogHandleButton` state 1 turn-in reads `+0x578/+0x57c` as reward COIDs when `+0x64c≠0`.

---

## 8. Sealed facts (A)

1. **ABI sealed:** EAX=dialog; stack slot index.
2. **Selection writer sealed:** `+0x578/+0x57c ← +0x558[slot]`.
3. **UI select chrome sealed:** 4× unselected (`+0x594`) then selected (`+0x5a4`) on slot widget.
4. **Hint clear sealed:** empty `DAT_00a1419b` via `+0x708` `vtbl+0x308`.
5. **Both call paths sealed:** single-reward auto-select (chrome) **and** multi-reward click (event dispatch) — closes parent gap “multi-reward selection writer”.

---

## 9. Gaps (A)

1. Product names for `vtbl+0x158` / `+0x34c` / `+0x308` and style blobs `+0x594` / `+0x5a4` layout.
2. No runtime verification of visual selected vs unselected.
3. Null widget / OOB slot behavior untested (static shows no guards).
4. Retail symbol name unknown.

---

## 10. Verdict rationale

Structure, ABI, offsets, and both callers are high-confidence from decompile + prologue bytes + call-site assembly context. Residual is UI framework product naming only → **accept-with-gaps**.
