# Review A (reconstruction fidelity): `aa_008aa760` dialog reward chrome

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa760` |
| **VA** | `0x008aa760` |
| **Canonical name** | `FUN_008aa760` (product: dialog reward chrome / turn-in caption fill) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008aa760_DialogRewardChrome.md` |
| **System tag** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fill mission-dialog **reward chrome** for up to **4** reward slots and stamp the dialog **turn-in / claim-mode** byte:

1. **First store:** `*(byte*)(dialog + 0x64c) = param_3` (turn-in flag from Show).
2. Clear selection TFID pair `dialog+0x578/0x57c = −1` and resolved-count `dialog+0x514 = 0`.
3. For each slot `i ∈ [0, min(param_2,4))`: copy 8-byte TFID from `param_1 + i*8` into `dialog+0x558 + i*8`; resolve via `CVOGReaction_ResolveObjectTarget(1, coidLo, coidHi)`; on hit show icon (`.dds`), name, and chrome widgets; on miss hide the four slot widgets; count successes at `+0x514`.
4. Branch captions on resolved count + `+0x64c`:
   - count==1, flag==0 → `"You Will Receive:"`
   - count==1, flag≠0 → `"Your Reward:"` + `FUN_008aa3f0(0)` auto-select slot 0 into `+0x578/+0x57c`
   - count≥2, flag==0 → `"You Will Get To Choose From:"` + clear hint via empty `DAT_00a1419b`
   - count≥2, flag≠0 → `"Select A Reward:"` + `"You must choose a reward item first"`
   - count==0 → hide header widget `+0x690`
5. Always (if `+0x6e8` present) set Mission Complete banner from count (independent of flag).

Does **not** send packets. Does **not** write chrome mode `+0x510` or button router `+0x648`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_008aa760` @ `0x008aa760` (≡ raw) |
| Raw | `docs/reconstruction/raw/aa_008aa760_FUN_008aa760.md` |
| Annotated | `docs/reconstruction/raw/aa_008aa760_FUN_008aa760.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_008aa760.cpp` |
| Function record | `docs/reconstruction/functions/aa_008aa760_FUN_008aa760.md` |
| Sole caller | `Client_ShowNpcMissionDialogUI` @ `0x009438f0` (call `0x00943b6b`) |
| Callee auto-select | `FUN_008aa3f0` @ `0x008aa3f0` |
| String-table bootstrap | `FUN_007a69d0` → `&DAT_00d1f660` |
| Localize | `FUN_007a6de0(cstr, −1)` |
| Empty hint string | `DAT_00a1419b` first byte `0x00` (`read_memory`) |
| Parent dual | `reviews/A|B_aa_009438f0_Client_ShowNpcMissionDialogUI.md` |
| Naming | `dialogTurnInMode` = host `+0x64c` in `NAMING_REGISTRY.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `this` / dialog host is **EDI** | **High** | Entry uses `EDI+…`; caller `MOV EDI,EBX` immediately before CALL |
| First store `*(byte*)(dialog+0x64c)=param_3` | **High** | Decomp + bytes `88 87 4c 06 00 00` = `MOV [EDI+0x64c],AL` |
| Resets `+0x578/+0x57c=−1`, `+0x514=0` | **High** | `OR EAX,-1`; `MOV [EDI+0x578/57c],EAX`; `MOV [EDI+0x514],EBP` (EBP=0) |
| `param_1` = reward TFID array (8-byte entries) | **High** | Loop `param_1 + i*8`; Show passes `FUN_0052dac0` → `state+0x18` |
| `param_2` = slot count; hard cap 4 | **High** | `if (3 < i) break`; Show always passes **4** |
| `param_3` = turn-in / claim-mode flag (byte) | **High** | Show sets 0 (offer/active) or 1 (turn-in ready via `FUN_0052b420`) |
| Resolve via `CVOGReaction_ResolveObjectTarget(1,…)` | **High** | Named callee; null → hide widgets |
| Icon path = object name + `".dds"` | **High** | `vtbl+0x1c4` name → `strncpy`/`strncat` → `vtbl+0x50` load |
| Show alpha `0x3f000000` = **0.5f** | **High** | IEEE float; used with `vtbl+0xfc(1, 0.5f)` |
| Slot widget banks at `+0x698` stride 4, four rows ×4 | **High** (layout) | `piVar8[0/4/8/0xc]` = +0x0/+0x10/+0x20/+0x30 from `+0x698`; `piVar8++` = next slot |
| Single-reward turn-in calls `FUN_008aa3f0(0)` | **High** | Only when `+0x514==1 && +0x64c≠0` |
| `FUN_008aa3f0` copies slot TFID → `+0x578/+0x57c` | **High** | Callee decompile; feeds HandleButton turn-in COIDs |
| Caption pairs by flag | **High** | Literal strings in body |
| Multi-reward offer hint = empty string | **High** | `DAT_00a1419b` → `0x00…` |
| Mission Complete banner `+0x6e8` ignores flag | **High** | Branch only on `+0x514` |
| Sole xref = ShowNpcMissionDialogUI | **High** | `get_function_callers` / xref `0x00943b6b` only |
| Product function name | **Tentative** | Scaffold alias from banner string; not retail symbol |
| Exact vtbl method names (+0x50/+0xfc/+0x158/…) | **Tentative** | UI framework ordinals only |
| `FUN_007a69d0` purpose beyond table init | **Tentative** | Returns string-table root; side effect only |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Raw | Live Ghidra | Clean |
|---|---|---|---|
| Bootstrap `FUN_007a69d0` | Yes | Yes | Yes |
| Store `+0x64c` / clear selection / zero count | Yes | Yes | Yes |
| Guard `param_1 && param_2` | Yes | Yes | Yes |
| Slot loop max 4 + resolve/show/hide | Yes | Yes | Yes |
| count==1 caption + optional auto-select | Yes | Yes | Yes |
| count==0 hide header / count≥2 choose captions + hint | Yes | Yes | Yes |
| Banner `+0x6e8` by count | Yes | Yes | Yes |
| Invented clamps / deleted branches | — | — | **None** |

**Result:** Clean CF ≡ raw ≡ live Ghidra.

---

## 5. Param / local renames (evidence only)

| Raw | Meaning | Evidence |
|---|---|---|
| `unaff_EDI` | mission dialog UI* (`this`) | `MOV EDI,EBX` at call; all host stores |
| `param_1` | reward TFID* (8-byte × N) | Show: `FUN_0052dac0` result |
| `param_2` | slot count (Show: **4**) | Push `4` at call site |
| `param_3` | turn-in flag → `+0x64c` | Show `uVar9` from `FUN_0052b420` branch |
| `iVar7` | slot index | Loop counter |
| `puVar6` | dest TFID slot at `dialog+0x558` | `puVar6 += 2` per slot |
| `piVar8` | slot widget cursor at `+0x698` | `piVar8 += 1` (4 bytes) |
| `piVar2` | resolved reward object* | Resolve result |
| `dialog+0x514` | resolved reward count | Inc on hit; drives captions |
| `dialog+0x578/57c` | selected reward TFID (or −1) | Cleared here; set by `FUN_008aa3f0` / click path |
| `dialog+0x690` | reward-header text widget | Caption strings |
| `dialog+0x6e8` | Mission Complete banner widget | Banner strings |
| `dialog+0x708` | choose-reward hint widget | Empty vs must-choose |

---

## 6. Assembly seals

### 6.1 Entry + first store (`read_memory` @ `0x008aa760`)

```
81 EC 8C 00 00 00     sub  esp, 0x8C
53 55 56              push ebx / ebp / esi
E8 .. .. .. ..        call FUN_007a69d0
…                     mov  al, [esp+param_3]
33 ED                 xor  ebp, ebp
88 87 4C 06 00 00     mov  [edi+0x64c], al     ; SEALED byte store
83 C8 FF              or   eax, -1
89 87 78 05 00 00     mov  [edi+0x578], eax
89 87 7C 05 00 00     mov  [edi+0x57c], eax
89 AF 14 05 00 00     mov  [edi+0x514], ebp    ; count = 0
```

### 6.2 Sole call site (`read_memory` @ `0x00943b5c`, one flag=0 path)

```
8B 44 24 18           mov  eax, [esp+0x18]     ; reward region
6A 00                 push 0                   ; param_3 (this path)
6A 04                 push 4                   ; param_2
50                    push eax                 ; param_1
8B FB                 mov  edi, ebx            ; dialog this
E8 F0 6B F6 FF        call FUN_008aa760
```

(Other Show branches push `param_3=1` when turn-in ready.)

---

## 7. Surviving contract

```
DialogRewardChrome(dialog /*EDI*/, rewardTfid*, slotCount, turnInFlag /*byte*/)
  *(byte*)(dialog+0x64c) = turnInFlag
  dialog+0x578/57c = -1; dialog+0x514 = 0
  for i in 0 .. min(slotCount,4)-1:
    copy rewardTfid[i] → dialog+0x558[i]
    obj = ResolveObjectTarget(1, tfid)
    if obj: show icon/name/chrome for slot i; ++dialog+0x514
    else: hide slot i widgets
  set header/hint/banner strings from (count, turnInFlag)
  if count==1 and turnInFlag: auto-select slot 0 (FUN_008aa3f0)
```

---

## 8. Gaps / open questions

1. Product name for this helper (not a retail symbol in Ghidra).
2. Full product names for UI vtbl slots (`+0x50` load tex, `+0xfc` show, `+0x158` tint/rect, `+0x1d8` set text, `+0x308` set hint, `+0x34c` layout).
3. Writer of multi-reward **click → `+0x578/+0x57c`** selection (not this function; `FUN_008aa3f0` only for single turn-in).
4. Whether `+0x6e8` banner is only visible on turn-in chrome or always present when non-null.
5. Exact TFID field order inside each 8-byte reward entry (lo/hi vs typed object id) beyond “two dwords Resolve consumes”.
6. Runtime / bit-diff vs retail EXE (open).

**Verdict:** Reward chrome + `+0x64c` first-store sealed; CF faithful. **accept-with-gaps.**
