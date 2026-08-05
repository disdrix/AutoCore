# Review A (reconstruction fidelity): `aa_00925820` `Client_InteractWorldClickHub`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00925820` |
| **VA** | `0x00925820` |
| **Body span** | `00925820`–`00925d59` (1338 B) |
| **Canonical name** | `Client_InteractWorldClickHub` (structural) |
| **Ghidra name** | `FUN_00925820` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W17-C) |
| **Counterpart** | `reviews/B_aa_00925820_Client_InteractWorldClickHub.md` |
| **System** | `interaction-activation` / client input |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callees/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Large **virtual world-click hub** on the client object:

1. Early-outs when mode==6 and two quiet flags.
2. Dispatches mouse screen coords through **two** client vtbl slots (`+0x430`, `+0x428`).
3. Optionally stops a heartbeat and zeroes vehicle longitudinal input.
4. Lets a selected object consume the click via its `vtbl+0x37C`.
5. Gates on character-dead / UI modal vtbls.
6. Branches:
   - `DAT_00d1a860==0` → `FUN_0091a350` return.
   - `char+0xCD0≠0` → drop-destroy **modal** (`Client_ShowModalPrompt` + destroy string).
   - else **ray (100f) + gather (20f mode 6)**:
     - empty TFID → hit list → ForPick select / ForInteract + **IfInteractable**
     - valid TFID → **ItemPickup `0x2055`**, clear select `[0x1d6]`, `FUN_0093e120(0)`

Distinct from `Client_InteractClickPickTarget` (`0x009247b0`) which owns the primary 25f UseObject click path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `raw/aa_00925820_FUN_00925820.md` (+ 2026-07-29 live append) |
| Annotated | `raw/aa_00925820_FUN_00925820.annotated.md` |
| Clean | `reconstructed-exact/Client_InteractWorldClickHub.cpp` |
| Scaffold | `reconstructed-exact/FUN_00925820.cpp` |
| Function record | `functions/aa_00925820_Client_InteractWorldClickHub.md` |
| Live decompile | Ghidra @ `0x00925820` ≡ raw |
| Bytes | `read_memory` 0x920 B spanning body; constants @ `0x00aaa7ac`, `0x00a0f2a0`, string `0x00a2faac` |
| Callees | `get_function_callees` |
| Xrefs | DATA `@ 0x00a2f420` only |
| Related duals | ItemPickup, IfInteractable, ForPick, CVOGHBBase_Stop, ShowModalPrompt |

**Not performed:** `disassemble_bytes`, Launcher, runtime click capture.

---

## 3. Byte / constant seal

### ABI prologue / epilogue

```
55 8B EC 83 E4 F0 ... 8B F9 ... C2 08 00
```

| Claim | Evidence | Conf |
|---|---|---|
| thiscall; `EDI=ECX` this | `8B F9` after prologue | **Confirmed** |
| 2 stack args; `ret 8` | epilogue `C2 08 00` | **Confirmed** |
| 16-byte stack align | `83 E4 F0` | **Confirmed** |
| Body ~1338 B | function range | **Confirmed** |

### Early gate

```
cmp [edi+0xCC4], 6 ; jnz body
cmp byte [edi+0x493], 0 ; jnz body
cmp byte [DAT_00d1b644+0xF5], 0 ; jz skip→return 0
```

### Constants

| Site | Value | Conf |
|---|---|---|
| `DAT_00aaa7ac` | **100.0f** | **Confirmed** `read_memory` → `00 00 C8 42` |
| gather imm | **20.0f** (`0x41A00000`) | **Confirmed** in decompile + bytes path |
| `g_flOne` | **1.0f** | **Confirmed** `00 00 80 3F` |
| destroy string | @ `0x00a2faac` | **Confirmed** |
| modal id | `0x4E4B` | **Confirmed** imm in body |

### ItemPickup branch (sealed with callee dual)

When gather TFID pair is valid (not both `0xFFFFFFFF`):

1. `FUN_00925580` / `Client_SendItemPickup` (call site `0x00925be3` per ItemPickup dual).
2. `self[0x1d6] = 0` → **+0x758** select clear.
3. `FUN_0093e120(0)`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Multi-stage interact hub role | **High** | callees + string + stages |
| Live ≡ raw CF | **High** | decompile match |
| Gate / ABI / 100f / 20f | **Confirmed** | bytes + memory |
| ItemPickup + clear select | **Confirmed** | decompile + sibling dual |
| ForPick select-only; ForInteract → IfInteractable | **High** | sealed matchers |
| Not primary 25f UseObject hub | **High** | no `Client_SendUseObject`; uses IfInteractable + ItemPickup |
| Structural name | **Probable** | product English Open |
| Vtbl +0x428/+0x430/+0x37C English | **Open** | |
| `FUN_0093e120` exact role | **Probable** select/highlight | residual unit |
| Soft-cast / list internals | **Partial** | callees out of OWN |

---

## 5. Call graph (this unit)

**Install:** client vtable dword `@ 0x00a2f420` → `0x00925820`.

**Callees (selected):** see function record — Stop, SetLongInput, ForPick, ForInteract, IfInteractable, ItemPickup, ShowModalPrompt, gather `0058cd60`, select `0093e120`, etc.

**Does not call:** `Client_SendUseObject` (`0x00916740`), `Client_InteractClickPickTarget`.

---

## 6. Gaps

1. Product English for mode `6`, `DAT_00d1a860`, flags `+0x493`/`+0xA35`, vtbl slots.
2. Full dual of `FUN_0093e120`, `FUN_0091a350`, `FUN_00914c20`, soft-cast helpers (not OWN).
3. Runtime click routing: when this vtbl fires vs ClickPickTarget path.
4. Bit-exact / differential deferred.

**Verdict:** **accept-with-gaps** — OWN stage CF + constants Confirmed; residual product English + sub-helper duals + runtime.
