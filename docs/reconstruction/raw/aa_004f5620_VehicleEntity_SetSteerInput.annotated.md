# Annotated low-level: VehicleEntity_SetSteerInput (`aa_004f5620`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f5620` |
| **VA** | `0x004f5620` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **Source raw** | `aa_004f5620_VehicleEntity_SetSteerInput.md` (capture 2026-07-23) |
| **Companion verified** | `docs/reconstruction/physics/verified/fn_004f5620_setSteerInput.md` |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = this
void __thiscall VehicleEntity_SetSteerInput(VehicleEntity* this, float steerInput);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | unsigned address | `ECX` | Vehicle entity |
| `steerInput` | 32-bit float bit pattern | IEEE-754 f32 | stack arg | Desired steer axis (typically `[-1,+1]`, **not enforced here**) |

Decompiler types `int` / `undefined4` are storage-level only.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `*(byte *)(iVar1 + 0xb4) & 199` | Mask is **unsigned** `0xC7` (199 decimal). Not a signed compare. | **Confirmed** |
| `199` as magic | Expand to bits: `0x01 \| 0x02 \| 0x04 \| 0x40 \| 0x80` | **Confirmed** |
| `param_2` as `undefined4` | Semantic **f32** store; no conversion | **Confirmed** |
| `param_1` as `int` | **`VehicleEntity*`** / entity base | **High** |
| `iVar1` | **`wobj`**: linked object pointer (wheel-control / lock object — semantic **Probable**) | **Probable** (pointer identity) |
| Gate meaning “disabled” | Retail lock / external-override suppression on steer write | **Probable** |

---

## 3. Pointer chain (integer-width expanded)

Ghidra expression:

```c
iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
```

Reading order (all loads are **32-bit** pointers / ints on x86):

```text
uint32_t p0   = *(uint32_t*)((uint8_t*)this + 0x4);   // this+4
uint32_t p1   = *(uint32_t*)((uint8_t*)p0   + 0x4);   // *(*(this+4)+4)
uint32_t wobj = *(uint32_t*)(p1 + (uint32_t)this + 0xb0);
// equivalent address: (p1 + this + 0xb0) as byte offset sum, then dword load
```

| Step | Expression | Width | Notes |
|---|---|---|---|
| 1 | `*(this + 4)` | u32 ptr | First link |
| 2 | `*(p0 + 4)` | u32 ptr | Second link |
| 3 | `*(p1 + this + 0xb0)` | u32 ptr | Entity-relative slot on linked object |
| 4 | `*(wobj + 0xb4)` | **u8** | Flag byte only |

**Null handling:** if `wobj == 0`, the flag byte is **not** loaded (short-circuit `||`).

---

## 4. Control flow and branch

```text
wobj = load_chain(this)
if (wobj == 0) goto STORE
if ( (*(uint8_t*)(wobj + 0xb4) & 0xC7u) == 0 ) goto STORE
return                    // gate closed: no write
STORE:
  *(float*)(this + 0x618) = steerInput
return
```

| Branch | Condition | Effect |
|---|---|---|
| Gate **open** | `wobj == NULL` **OR** `(flags & 0xC7) == 0` | Single store to `this+0x618` |
| Gate **closed** | `wobj != NULL` **AND** `(flags & 0xC7) != 0` | Early return; prior steer retained |

Control-flow confidence: **High / Confirmed** (trivial; matches verified note).

---

## 5. Side-effect order

1. **Read** pointer chain (3 dword loads).
2. **Optional read** of `wobj+0xb4` (only if `wobj != 0`).
3. **Conditional write** of 4 bytes at `this+0x618`.
4. **Return.**

**No other side effects:**

- No clamps / min / max / abs
- No function calls
- No writes to `+0x614` (longitudinal), `+0x61c` (handbrake), or controller
- No flag mutation on `wobj`
- No FP ops (store is integer MOV of the float bits)

---

## 6. Field map (touched / related)

| Offset | Type | Role in this function |
|---|---|---|
| `this+0x4` | ptr chain | Gate resolution only |
| `wobj+0xb4` | u8 flags | Gate mask source (`& 0xC7`) |
| `this+0x618` | f32 | **Only store** — raw steer axis |
| `this+0x614` | f32 | **Not** written here (sibling `0x004f5650`) |

---

## 7. Mask `0xC7` detail

| Bit | Value | Included in gate |
|---:|---:|:---:|
| 0 | `0x01` | yes |
| 1 | `0x02` | yes |
| 2 | `0x04` | yes |
| 3 | `0x08` | no |
| 4 | `0x10` | no |
| 5 | `0x20` | no |
| 6 | `0x40` | yes |
| 7 | `0x80` | yes |

Any **set** bit among `{0,1,2,6,7}` closes the gate when `wobj` is non-null. Per-bit retail names for this specific object+offset remain **open** (see function record).

---

## 8. Call-site context (not in body)

From plate / prior RE (callers impose values; this function does not):

| Context | Typical value written via this setter |
|---|---|
| SteerLeft held (`DAT_00d1bc8e`) | `+1.0f` |
| SteerRight held (`DAT_00d1bcc2`) | `-1.0f` |
| Soft L / R | `±0.5f` |
| Clear / deadband straighten | `0.0f` |

Downstream: `VehicleAction_applyAction` ramps `entity+0x618` → `VA+0x24` (not done inside this function).

---

## 9. Sibling parity

`VehicleEntity_SetLongitudinalInput` @ `0x004f5650` is the same control flow and gate; only the store target differs (`this+0x614`). Annotated differences are limited to that offset and caller sets.

`read_memory` 2026-07-29: sibling body is **byte-identical** through the gate; only the `movss` store displacement differs (`0x618` vs `0x614`).

---

## 10. Instruction seal (`read_memory` @ `0x004f5620`, 2026-07-29 dual residual)

```
8b 41 04                mov eax, [ecx+4]
8b 50 04                mov edx, [eax+4]
8b 84 0a b0 00 00 00    mov eax, [edx+ecx+0xb0]
85 c0 / 74 09           test eax; jz STORE
f6 80 b4 00 00 00 c7    test byte [eax+0xb4], 0xC7   ; imm8 sealed
75 0e                   jnz RET
f3 0f 10 44 24 04       movss xmm0, [esp+4]
f3 0f 11 81 18 06 00 00 movss [ecx+0x618], xmm0
c2 04 00                ret 4
```

| Item | Value |
|---|---|
| Body | `0x004f5620`–`0x004f564a` (43 B) |
| Mask | **instruction** imm8 `0xC7` (not decompiler-only) |
| Store | displacement `0x618` |

Full residual: `docs/reconstruction/reviews/a_004f5620.md`.
