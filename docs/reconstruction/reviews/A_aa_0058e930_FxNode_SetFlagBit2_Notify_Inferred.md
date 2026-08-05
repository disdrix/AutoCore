# Review A (reconstruction fidelity): `aa_0058e930` FxNode_SetFlagBit2_Notify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e930` |
| **VA** | `0x0058e930` |
| **Body span** | `0058e930` – `0058e96e` (leaf; `ret 4`) |
| **Canonical name** | `FxNode_SetFlagBit2_Notify_Inferred` |
| **Ghidra name** | `FUN_0058e930` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B seal — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile CF) |
| **Counterpart** | `reviews/B_aa_0058e930_FxNode_SetFlagBit2_Notify_Inferred.md` |
| **System** | client special-FX host active-flag cascade (list #2 notify) |
| **Dual status** | **Present (first dual A/B)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`__thiscall` leaf** called from FX-host active cascade `FUN_004b8dc0` when walking list at host **`+0x204`**.

1. **Deposit bit value 4** (bit 2) of **`this+0x90e`** from boolean `param_2` (0→clear, non-zero→set) via classic XOR deposit:
   ```
   byte ^= ( (param2*4) ^ byte ) & 4
   ```
2. **Optional notify:** if **`(this+0x90f) & 2`** and **`this+0x91c != 0`**:
   - `obj = *(this+0x91c)`
   - `inner = *(obj + 0x8c)`
   - `*(inner + 0xdc) += 1`  (counter bump)
   - `*(char*)(inner + 0xd0) = param_2`

```c
void __thiscall FxNode_SetFlagBit2_Notify_Inferred(void *this, char flag);
```

No callees (direct field writes only). Sibling list notify: `FUN_005bbb90` (host list `+0x1E0`, three-arg).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0058e930_FUN_0058e930.md` | ≡ live |
| Annotated | `docs/reconstruction/raw/aa_0058e930_FUN_0058e930.annotated.md` | Scaffold |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058e930.cpp` | CF ≡ raw |
| Named alias | `Named_CalleeOf_Mission_Uses_Client_GetMissionCompleteAudioTable_0058e930.cpp` | Parent-seed only |
| Function record | `docs/reconstruction/functions/aa_0058e930_FUN_0058e930.md` | Scaffold |
| Live decompile | Ghidra @ `0x0058e930` | **≡ raw** |
| Live `read_memory` | body @ `0x0058e930` length 64 | Bit-deposit seal |
| Parent dual | `reviews/A_aa_004b8dc0_FUN_004b8dc0.md` | Walks list `+0x204` → this |
| Callers | **1** xref: `FUN_004b8dc0` @ `0x004b8e0f` | Host cascade only |

**Not performed:** Launcher, runtime, bit-exact. **No ledgers.**

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; stack `char flag`; `ret 4` | **High** | bytes |
| Bit deposit on **`this+0x90e`**, mask **4** | **High** | `param*4` then XOR-and deposit |
| Gate: **`(this+0x90f) & 2`** | **High** | decompile + `test byte, 2` |
| Gate: **`this+0x91c != 0`** | **High** | |
| Nested: `*(*(+0x91c)+0x8c)` then `+0xdc`++ and `+0xd0=flag` | **High** | offsets sealed |
| Sole caller `FUN_004b8dc0` | **High** | single xref |
| Product English / type of node | **Tentative** | `_Inferred` |
| Nested object type at `+0x91c` | **Tentative** | layout partial |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| bit deposit at `+0x90e` | **Yes** |
| if gate `+0x90f&2` and ptr | **Yes** |
| counter++ and store flag | **Yes** |
| else / fallthrough return | **Yes** |

### 4.1 Live decompile (2026-07-29)

```c
void __thiscall FUN_0058e930(int param_1, char param_2)
{
  int *piVar1;
  int iVar2;

  *(byte *)(param_1 + 0x90e) =
       *(byte *)(param_1 + 0x90e) ^ (param_2 * '\x04' ^ *(byte *)(param_1 + 0x90e)) & 4;
  if (((*(byte *)(param_1 + 0x90f) & 2) != 0) && (*(int *)(param_1 + 0x91c) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x91c) + 0x8c);
    piVar1 = (int *)(iVar2 + 0xdc);
    *piVar1 = *piVar1 + 1;
    *(char *)(iVar2 + 0xd0) = param_2;
  }
  return;
}
```

### 4.2 Instruction seal

```text
8A 54 24 04             mov  dl, [esp+4]           ; flag
8A C2                   mov  al, dl
02 C0                   add  al, al                ; *2
02 C0                   add  al, al                ; *4
32 81 0E 09 00 00       xor  al, [ecx+0x90E]
24 04                   and  al, 4
30 81 0E 09 00 00       xor  [ecx+0x90E], al       ; deposit bit2
F6 81 0F 09 00 00 02    test byte ptr [ecx+0x90F], 2
74 1D                   jz   → ret
8B 89 1C 09 00 00       mov  ecx, [ecx+0x91C]
85 C9                   test ecx, ecx
74 13                   jz   → ret
8B 81 8C 00 00 00       mov  eax, [ecx+0x8C]
83 80 DC 00 00 00 01    add  dword ptr [eax+0xDC], 1
88 90 D0 00 00 00       mov  [eax+0xD0], dl
C2 04 00                ret  4
```

### 4.3 Layout (touched)

| Off | Role |
|---|---|
| `this+0x90e` | flags byte; **bit 2 (value 4)** mirrors `flag` |
| `this+0x90f` | flags byte; **bit 1 (value 2)** enables notify |
| `this+0x91c` | optional object pointer |
| `obj+0x8c` | inner pointer |
| `inner+0xd0` | char copy of flag |
| `inner+0xdc` | dword generation/counter ++ |

---

## 5. Callers

| Call site | Function | Role |
|---|---|---|
| `0x004b8e0f` | `FUN_004b8dc0` | Host active cascade list `+0x204` walk; `flag = newFlag` (2-arg; **no** `param_3`) |

---

## 6. Gaps / open

1. Product type names for node / nested objects.
2. Semantic of counter `+0xdc` and mirror `+0xd0` (UI dirty? audio gen?).
3. When `+0x90f` bit1 is set in construction paths.
4. Runtime not run; clean still `FUN_*`.

**Verdict:** **accept-with-gaps** — dual **bit deposit CF + notify gates + offsets + single-caller context** sealed; product English open.
