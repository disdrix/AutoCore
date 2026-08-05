# Review A (reconstruction fidelity): `aa_006374f0` TNL_GroupReactionCall_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_006374f0` |
| **VA** | `0x006374f0`–`0x0063774d` |
| **Canonical name** | `TNL_GroupReactionCall_UnpackData` |
| **Ghidra name** | `FUN_006374f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-N) |
| **Counterpart** | `reviews/B_aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| **System** | client-net / TNL special-message (`GroupReactionCall` `0x206C`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/mid/epilogue; caller `Client_UnpackSpecialMessage` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Convert inbound TNL special-message payload for opcode **`0x206C` (GroupReactionCall)** into a heap **ByteBuffer** whose data is a rebuilt stack image of tag/`count`/entries (entry stride **`0x28`**).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.md` (+ W22-N append) |
| Annotated | `docs/reconstruction/raw/aa_006374f0_FUN_006374f0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/TNL_GroupReactionCall_UnpackData.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_006374f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006374f0_TNL_GroupReactionCall_UnpackData.md` |
| Sibling dual | `reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md` (`0x804D`) |
| Dispatch | `reviews/A_aa_00637c20_Client_UnpackSpecialMessage.md` |
| Live | `decompile_function` `0x006374f0`; `read_memory` @ entry / `+0x100` / epilogue |

---

## 3. Signature

```c
// cdecl
undefined4 * FUN_006374f0(undefined4 *out, int *inRefBuf);
// epilogue: add esp, 0x2940; ret (C3)
```

| Item | Evidence | Conf |
|---|---|---|
| cdecl + plain RET | `81 C4 40 29 00 00 C3` | **High** |
| Two stack args | decompile + caller | **High** |
| Return out** | `return param_1` | **High** |
| Large frame / chkstk | `B8 34 29 00 00` + `__chkstk` | **High** |

---

## 4. Control flow (sealed)

```
SEH; local_tag = 0x206c
BitStream bind from in[+0xc],[+0x10]
count = readBits(8)
for i in 0..count-1:          // stride +0x28
  type = readBits(8)
  if type == 1: readBits(16); readBits(32) as float (movss)
  else: readInt(19); zero; readBits(64); flag; flag
size = count*0x28 + 1
bb = new(0x18); list-ctor; vtbl 009d7b00; malloc(size); owns=1
memcpy(stack_image, bb->data, size)
*out = bb; bb.ref++
teardown BitStream; in.ref--; if 0 Release
return out
```

| Stage | Match | Conf |
|---|---|---|
| Opcode constant `0x206c` | **Yes** (`C7 … 6C 20 00 00`) | **High** |
| u8 count | **Yes** `readBits(8)` | **High** |
| type==1 float store | **Yes** `F3 0F 11 46 04` movss | **High** |
| else 19-bit + u64 + 2 flags | **Yes** | **High** |
| stride 0x28 | **Yes** `add esi,0x28` / `puVar7+10` | **High** |
| size `count*0x28+1` | **Yes** lea pattern | **High** |
| ByteBuffer vtbl/size/owns/refcount | **Yes** same as sibling 0x804D | **High** |
| Sole caller 0x206c path | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Notes |
|---|---|
| Entry | SEH + `mov eax,0x2934` + chkstk + save regs |
| Mid loop | `readBits(8)` type; branch; `movss` on type-1; flag bit tests |
| Alloc | `push 0x18; call operator_new`; vtbl `00 7B 9D 00`; `malloc` |
| Epilogue | release input; `add esp,0x2940; ret` |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA / condition |
|---|---|
| `Client_UnpackSpecialMessage` | `0x00637d04` when opcode `0x206c` |

Xrefs: **1**.

---

## 7. Confidence

| Claim | Level |
|---|---|
| ABI / opcode / wire skeleton / ByteBuffer rebuild | **High** |
| type==1 float semantics (IEEE bits) | **High** store / **Probable** product meaning |
| Entry field English / consumer offset map | **Probable / Tentative** |
| size `+1` product rationale | **Medium** (retail sealed, meaning open) |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product English for type-1 vs reaction entry fields.
2. Full byte-accurate stack image layout vs `Client_RecvGroupReactionCall` consumer (normal S2C path may differ from special-message blob).
3. Why size is `count*0x28+1` — do not “fix” without capture.
4. OOM null-new continues into memcpy in decompile — retail crash path.
5. Live pack/unpack differential — open.

**Verdict:** **accept-with-gaps** — wire/ABI/rebuild sealed for AutoCore ports; field English open.
