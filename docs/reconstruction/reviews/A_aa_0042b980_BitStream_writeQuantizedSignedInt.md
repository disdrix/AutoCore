# Review A (reconstruction fidelity): `aa_0042b980` BitStream_writeQuantizedSignedInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b980` |
| **VA** | `0x0042b980`–`0x0042b9cc` |
| **Canonical name** | `BitStream_writeQuantizedSignedInt` |
| **Ghidra name** | `FUN_0042b980` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W20-J) |
| **Counterpart** | `reviews/B_aa_0042b980_BitStream_writeQuantizedSignedInt.md` |
| **System** | network-bitstream |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; sole caller `BitStream_writeQuantizedFloat` `0x0042b910` |
| **Verdict** | **accept** |

---

## 1. Purpose

Write a **signed quantized integer** into a TNL-style BitStream:

1. `BitStream_writeFlag(value < 0)` — 1 sign bit.
2. If negative → `value = -value`.
3. `BitStream_writeBits(bitCount - 1, &value)` — magnitude.

Integer stage for **`BitStream_writeQuantizedFloat`** (float scale + trunc happens in caller).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0042b980_FUN_0042b980.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_0042b980_FUN_0042b980.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_writeQuantizedSignedInt.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0042b980.cpp` |
| Function record | `docs/reconstruction/functions/aa_0042b980_FUN_0042b980.md` |
| Parent trampoline | `BitStream_writeQuantizedFloat` `0x0042b910` |
| Read sibling | `FUN_0042b9d0` / readQuantizedSignedInt `0x0042b9d0` |
| Live | decompile ≡ raw; `read_memory` 80 B body; rel calls → `0x0042b770`, `0x0042b4a0` |

---

## 3. Signature (sealed)

```c
// EDI = BitStream* this
// ECX = int value
// AL  = bitCount (includes sign flag bit)
void BitStream_writeQuantizedSignedInt(BitStream *stream, int value, uint8_t bitCount);
```

| Formal | Source | Conf |
|---|---|---|
| Stream | **EDI** (caller `MOV EDI,ECX`; body `MOV ECX,EDI` into thiscalls) | **High** |
| value | **ECX → ESI** | **High** |
| bitCount | **AL → BL**, magnitude uses `BL-1` | **High** |
| Return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
flag = writeFlag(stream, value < 0)
magBits = bitCount - 1
if flag:
  local = -value
  writeBits(stream, magBits, &local)
else:
  local = value
  writeBits(stream, magBits, &local)
```

| Stage | Match | Conf |
|---|---|---|
| SETL / writeFlag sign | **Yes** | **High** |
| NEG on negative path | **Yes** | **High** |
| magBits = bitCount−1 | **Yes** | **High** |
| No write-side mask | **Yes** | **High** |
| Sole callees writeFlag + writeBits | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body:
```
5153568bf18ad885f60f9cc08bcf50e8dcfdffff80eb0184c0741a8d4c24080fb6d351f7de528bcf89742410e8effaffff5e5b59c38d4424080fb6cb50518bcf89742410e8d7faffff5e5b59c3
```

Callee targets (rel32): **writeFlag** `0x0042b770`, **writeBits** `0x0042b4a0`.

Decompile ≡ bytes for CF. Phantom `in_AL` / EDI this filled from caller + body.

---

## 6. Parent quantize (context only)

`0x0042b910` (`read_memory`): `max=(1<<(bitCount-1))-1`; `q=(int)trunc(float*max)`; then call this unit with `EDI=this`, `ECX=q`, `AL=bitCount`; `RET 8`.

---

## 7. Confidence

| Claim | Level |
|---|---|
| CF + ABI | **High** |
| Name pair with read sibling | **High** |
| Protocol use via writeQuantizedFloat | **High** (sole xref) |
| Runtime capture | **Open** |

---

## 8. Gaps

1. `INT_MIN` absolute-value wrap (no special case).
2. Packet-level live proof.
3. Parent dual for `writeQuantizedFloat` still residual (`needs-more-evidence` historically) — **this unit** seals the integer stage.

**Verdict:** **accept** — signed quant int write kernel sealed.
