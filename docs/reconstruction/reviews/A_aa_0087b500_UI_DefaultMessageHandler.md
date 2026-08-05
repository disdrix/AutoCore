# Review A (reconstruction fidelity): `aa_0087b500` UI_DefaultMessageHandler

| Field | Value |
|---|---|
| **Stable ID** | `aa_0087b500` |
| **VA** | `0x0087b500` |
| **Canonical name** | `UI_DefaultMessageHandler` |
| **System** | UI dialog / window message base |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_0087b500_UI_DefaultMessageHandler.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Program** | `autoassault.exe` only |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Default **message fallthrough** for UI windows/dialogs. Swallows a mid-band of event codes (`7..15`), else optionally **bubbles** `(msg, controlId)` to the parent control at `this+0x2B0` via `vtbl+0x338`, gated by `this->vtbl+0xD8`.

Not networking, not inventory, not mission wire.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `batch_decompile` / `decompile_function` @ `0x0087b500` |
| Body bytes | `read_memory(0x0087b500, 128)` — body ends `ret 8` @ `0x0087b54f` |
| Function meta | Body `0087b500`–`0087b54f` |
| Callers | `get_function_callers` (sample includes `UI_OnAttributePointClick_Inferred`, `caseD_9c40`) |
| Raw | `docs/reconstruction/raw/aa_0087b500_FUN_0087b500.md` |
| Annotated | `docs/reconstruction/raw/aa_0087b500_FUN_0087b500.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_DefaultMessageHandler.cpp` |
| Peer duals | `A_aa_00870e15_UI_Case_CloseBtn_9c40`, `A_aa_008f92e0_UI_OnAttributePointClick_Inferred` (forward sites) |

---

## 3. Seal: body (`read_memory` @ `0x0087b500`)

Body range **`0x0087b500`–`0x0087b54f`** (`ret 8` / `C2 08 00`).

```
56 57 8b7c240c 83ff07 8bf1 7c0c 83ff0f 7f07
5f b001 5e c20800
8b06 8bce ff90d8000000 84c0 7422
83beb002000000 7419
8b442410 8b8eb0020000 8b11 50 57 ff9238030000
5f 5e c20800
5f 32c0 5e c20800
```

### Control flow (machine)

```
; __thiscall entry: ECX=this
; stack: [esp+4]=msg, [esp+8]=controlId

push esi; push edi
mov  edi, [esp+0xC]          ; msg
cmp  edi, 7
mov  esi, ecx                ; this
jl   out_of_band
cmp  edi, 0x0F
jg   out_of_band
pop  edi
mov  al, 1
pop  esi
ret  8                       ; handled

out_of_band:
call [this->vtbl+0xD8]
test al, al
jz   zero
cmp  dword [this+0x2B0], 0
jz   zero
push controlId               ; [esp+0x10] after saves
push msg                     ; edi
call [parent->vtbl+0x338]    ; ECX=parent
pop  edi; pop esi; ret 8

zero:
pop  edi
xor  al, al
pop  esi
ret  8
```

### ABI

| Item | Machine | Conf |
|---|---|---|
| Convention | MSVC **`__thiscall`**, **`ret 8`** | **High** |
| `this` | UI window/control | **High** (callers) |
| `msg` | int event type | **High** |
| `controlId` | unsigned / int id | **High** (peer duals) |
| Return | 1 handled-band; else parent result or 0 | **High** |

### Key offsets

| Offset | Role | Conf |
|---|---|---|
| `this+0x2B0` | Parent pointer | **High** |
| `vtbl+0xD8` | Forward predicate | **High** (slot); semantic **Tentative** |
| `vtbl+0x338` | Message virtual on parent | **High** (ecosystem) |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF clean ≡ raw ≡ machine | **High** | no material decomp defect |
| Inclusive msg `7..15` → 1 | **High** | `cmp 7` / `cmp 0x0F` |
| Parent forward path | **High** | bytes |
| Name `UI_DefaultMessageHandler` | **Probable** | role sealed; product name open |
| `vtbl+0xD8` exact meaning | **Tentative** | returns char; not string-named |
| Bit-exact / runtime | **Open** | deferred |

---

## 5. Gaps

1. Product class + method name.
2. Full UI message enum.
3. Predicate `+0xD8` semantics (visible / focused / modal?).
4. Layout proof that `+0x2B0` is always “parent window” vs host slot.
5. Runtime / differential.

---

## 6. Port implication

```
if (msg is mid-band 7..15) treat as handled;
else if window may-forward and has parent: parent.OnMessage(msg, controlId);
else unhandled.
```

Do not invent dialog-specific behavior in this base — specific cases live in callers.

**Verdict:** **accept-with-gaps**
