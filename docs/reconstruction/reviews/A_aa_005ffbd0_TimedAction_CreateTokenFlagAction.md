# Review A (reconstruction fidelity): `aa_005ffbd0` TimedAction_CreateTokenFlagAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffbd0` |
| **VA** | `0x005ffbd0` |
| **Canonical name** | `TimedAction_CreateTokenFlagAction` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005ffbd0_TimedAction_CreateTokenFlagAction.md` |
| **System** | `heartbeat` / timed-actions (enter-world token/flag HB factory) |
| **Live tools** | Ghidra `decompile_function` ×2 + `force_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** (body High; plate period is caller arg, not body load) |

---

## 1. Purpose

Placement-style **heartbeat ctor / factory** for the enter-world **token/flag** timed action:

1. `CVOGHBBase_ctor(this)`
2. Install subclass vtable **`PTR_FUN_009dde2c`** at `*this`
3. `CVOGHBBase_SetPeriodAndCounter(this, 1, true)` — seed TryFire sentinel/counter at **`+0x0C`/`+0x10`** with **1** (not combat `-1000`)
4. Store real pulse period ms at **`this+0x08`** from stack **`param_3`**
5. `CVOGHBBase_AttachOwnerObject` — null owner if `param_2 == 0`, else MSVC MI this-adjust  
   `param_2 + *(*(param_2 + 4) + 4) + 4`
6. Return `this` (EAX)

Does **not** call fire path / `FUN_005ffc20` / mask `0x100` in-body (plate residual on **vtable** slot). Does **not** load `DAT_00af0c6c` (300000) — that constant is the **caller-supplied** period (`Vehicle_ActivateEnterWorld` → `g_dwTokenFlagActionPeriodMs`).

Object size at sole call site: `operator_new(0x24)` (36 bytes HB).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ffbd0_TimedAction_CreateTokenFlagAction.md` |
| Annotated | `docs/reconstruction/raw/aa_005ffbd0_TimedAction_CreateTokenFlagAction.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TimedAction_CreateTokenFlagAction.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ffbd0_TimedAction_CreateTokenFlagAction.md` |

---

## 3. Seal: body bytes (High)

`get_function_by_address`: entry `005ffbd0`, body `005ffbd0`–`005ffc1d` (**78 bytes**).  
`read_memory` @ `0x005ffbd0` length 128 (body + next-fn lead-in):

```
005ffbd0  56                 push esi
005ffbd1  8B F1              mov  esi, ecx                 ; ESI = this (HB*)
005ffbd3  E8 28 86 F0 FF     call CVOGHBBase_ctor          ; → 0x00508200
005ffbd8  6A 01              push 1                        ; bAlsoSetCounter = true
005ffbda  6A 01              push 1                        ; nPeriodSentinel = 1
005ffbdc  8B CE              mov  ecx, esi
005ffbde  C7 06 2C DE 9D 00  mov  dword [esi], 0x009DDE2C  ; PTR_FUN_009dde2c
005ffbe4  E8 B7 85 F0 FF     call CVOGHBBase_SetPeriodAndCounter ; → 0x005081a0
005ffbe9  8B 44 24 0C        mov  eax, [esp+0xC]           ; param_3 (period ms)
005ffbed  89 46 08           mov  [esi+0x08], eax          ; pulse period at +0x08
005ffbf0  8B 44 24 08        mov  eax, [esp+0x8]           ; param_2 (ownerish)
005ffbf4  85 C0              test eax, eax
005ffbf6  75 0E              jnz  nonnull                  ; → 005ffc06
; null owner path
005ffbf8  50                 push eax                      ; push 0
005ffbf9  8B CE              mov  ecx, esi
005ffbfb  E8 B0 87 F0 FF     call CVOGHBBase_AttachOwnerObject ; → 0x005083b0
005ffc00  8B C6              mov  eax, esi                 ; return this
005ffc02  5E                 pop  esi
005ffc03  C2 08 00           ret  8                        ; 2 stack args
; nonnull owner path
005ffc06  8B 48 04           mov  ecx, [eax+4]             ; *(ownerish+4)
005ffc09  8B 51 04           mov  edx, [ecx+4]             ; *(*(ownerish+4)+4)
005ffc0c  8D 44 02 04        lea  eax, [edx+eax+4]         ; ownerish + delta + 4
005ffc10  50                 push eax
005ffc11  8B CE              mov  ecx, esi
005ffc13  E8 98 87 F0 FF     call CVOGHBBase_AttachOwnerObject ; → 0x005083b0
005ffc18  8B C6              mov  eax, esi
005ffc1a  5E                 pop  esi
005ffc1b  C2 08 00           ret  8
; 005ffc1e  CC padding / next function
```

Hex (78 bytes):  
`56 8b f1 e8 28 86 f0 ff 6a 01 6a 01 8b ce c7 06 2c de 9d 00 e8 b7 85 f0 ff 8b 44 24 0c 89 46 08 8b 44 24 08 85 c0 75 0e 50 8b ce e8 b0 87 f0 ff 8b c6 5e c2 08 00 8b 48 04 8b 51 04 8d 44 02 04 50 8b ce e8 98 87 f0 ff 8b c6 5e c2 08 00`

| Claim | Evidence | Conf |
|---|---|---|
| Body **78 bytes**; dual `ret 8` exits | range `005ffbd0`–`005ffc1d` | **High** |
| **`__thiscall`**: ECX = HB; **2 stack args**; returns **this** in EAX | `mov esi,ecx`; `ret 8`; `mov eax,esi` | **High** |
| Callee targets exact | ctor `0x00508200`; SetPeriod `0x005081a0`; Attach `0x005083b0` ×2 | **High** |
| Vtable install `0x009DDE2C` | `C7 06 2C DE 9D 00` | **High** |
| SetPeriod args **(1, true)** hardcoded | dual `push 1` | **High** |
| Real period → **`this+0x08`** from stack param_3 | `89 46 08` after `[esp+0xC]` | **High** |
| Null `param_2` → Attach(null) | `test/jz` + `push eax` (0) | **High** |
| Non-null → MI adjust `obj + *(*(obj+4)+4) + 4` | `lea eax,[edx+eax+4]` | **High** |
| No body load of `DAT_00af0c6c` | no data ref in body | **High** |
| No call to `FUN_005ffc20` | no CALL to `0x005ffc20` | **High** |
| Decompiler CF ≡ machine (minor arg-setup reorder) | three-rep below | **High** |

### Stack layout after `push esi`

| Offset | Meaning |
|---|---|
| `[esp+0]` | saved ESI |
| `[esp+4]` | return address |
| `[esp+8]` | **param_2** ownerish object (or 0) |
| `[esp+0xC]` | **param_3** period ms → `+0x08` |

### Decompiler three-rep (2026-07-29)

| Pass | Tool | Result |
|---|---|---|
| 1 | `decompile_function` @ `0x005ffbd0` | ctor → vtable → SetPeriod(1,true) → `[2]=param_3` → Attach null/adjust |
| 2 | `force_decompile` @ `0x005ffbd0` | **identical** pseudocode |
| 3 | `analyze_function_complete` decompiled_code | **identical** body |

Machine nuance vs decompiler: pushes for SetPeriod land **before** the vtable `mov [esi],…`; decompiler lists vtable then SetPeriod. Both end with vtable installed and SetPeriod called; SetPeriod is pure field stores (no vtable use) — **semantically equivalent**.

### Vtable note (own-VA residual only)

`read_memory` @ `0x009dde2c` slot includes pointer **`0x005ffc20`** (`FUN_005ffc20`) — plate “token/flag via FUN_005ffc20 / mask 0x100” refers to **dispatch/vtable**, not this ctor body. Not re-owned here.

### Caller period constant (context, not body)

`read_memory` @ `DAT_00af0c6c` / `0x00af0c6c`: dword **`0x000493E0` = 300000** ms. Sole xref caller `Vehicle_ActivateEnterWorld` @ `0x00503f30` (call site `0x00504093`) supplies that as period after `operator_new(0x24)`.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Control flow sealed | **High** | Machine + 3× decompile |
| Signature: `(HB* this, void* ownerish, uint32 periodMs) → HB*` thiscall, `ret 8` | **High** | |
| `SetPeriodAndCounter(1,true)` then pulse at `+0x08` | **High** | Same dual-layout pattern as Regeneration (sentinel vs pulse) |
| Not combat-pool ctor (`-1000`) | **High** | Hardcoded 1 |
| MI adjust is attach-target owner base | **High** formula / **Probable** type name (CVOGObject-ish) |
| Product meaning “token/flag” | **Probable** | Plate + name; fire body is sibling VA |
| Period always 300000 | **Probable at sole caller** | Body accepts any `param_3` |
| Runtime / bit-exact | **Open** | Deferred |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Base ctor | **Yes** |
| Vtable `PTR_FUN_009dde2c` | **Yes** |
| SetPeriod(1,true) | **Yes** |
| `this[+0x08] = period` | **Yes** (`param_1[2]`) |
| Null owner → Attach(0) + ret this | **Yes** |
| Non-null → MI adjust → Attach + ret this | **Yes** |
| No invented clamps / loops / globals | **Yes** |

Clean/raw scaffolding already matches decompiler; machine confirms field offsets and call targets.

---

## 6. Callers / callees (own-VA surface)

**Callers (Ghidra 2026-07-29):** 1 UNCONDITIONAL_CALL

| Site | Function |
|---|---|
| `0x00504093` | `Vehicle_ActivateEnterWorld` (`0x00503f30`) |

**Callees (body):**

| Address | Name |
|---|---|
| `0x00508200` | `CVOGHBBase_ctor` |
| `0x005081a0` | `CVOGHBBase_SetPeriodAndCounter` |
| `0x005083b0` | `CVOGHBBase_AttachOwnerObject` (×2 paths) |

---

## 7. Surviving contract (for AutoCore)

```
// __thiscall placement ctor; size 0x24
HB* TimedAction_CreateTokenFlagAction(
    HB* this,              // ECX — zeroed/new 0x24
    void* pOwnerish,       // [esp+4] — object or null; MI-adjusted for Attach
    uint32_t nPeriodMs)    // [esp+8] — stored at this+0x08 (caller often 300000)
{
  CVOGHBBase_ctor(this);
  *this = PTR_FUN_009dde2c;                 // token-flag HB vtable
  CVOGHBBase_SetPeriodAndCounter(this, 1, true);  // +0x0C/+0x10 = 1
  *(uint32_t*)((uint8_t*)this + 0x08) = nPeriodMs;
  if (pOwnerish == null)
    CVOGHBBase_AttachOwnerObject(this, null);
  else
    CVOGHBBase_AttachOwnerObject(this,
      pOwnerish + *(*(int**)((uint8_t*)pOwnerish + 4) + 1 /* +4 */) + 4);
  return this;
}
```

Port notes:

- **Do not** treat plate “period 300000” as a body constant — pass it in.
- **Do not** confuse with combat-pool ctors that seed `SetPeriodAndCounter(-1000, true)`.
- Fire/token side effect is **vtable** (`FUN_005ffc20`), not this function.

---

## 8. Gaps / open

1. Name/document `FUN_005ffc20` (vtable fire) and mask `0x100` semantics — **sibling VA**, not this unit.
2. Confirm `pOwnerish` static type at call site (vehicle vs character base) via MI layout — residual naming only here.
3. Unify HB field plates: `+0x08` pulse period vs `+0x0C` sentinel (family-wide).
4. Runtime / bit-exact / differential still deferred.

**Verdict:** **accept** (body High; plate period is caller arg, not body load)
