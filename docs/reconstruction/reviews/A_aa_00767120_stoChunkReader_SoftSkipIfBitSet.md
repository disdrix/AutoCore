# Review A (reconstruction fidelity): `aa_00767120` stoChunkReader_SoftSkipIfBitSet

| Field | Value |
|---|---|
| **Stable ID** | `aa_00767120` |
| **VA** | `0x00767120`–`0x0076715c` |
| **Canonical name** | `stoChunkReader_SoftSkipIfBitSet` (Ghidra `FUN_00767120`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY dual A, W17-L) |
| **Counterpart** | `reviews/B_aa_00767120_stoChunkReader_SoftSkipIfBitSet.md` |
| **System** | storage / arda2 stoChunk |
| **Verdict** | **accept-with-gaps** — body CF sealed; field English + id%32 edge open |

---

## 1. Purpose

Leaf **soft-skip predicate** on a `stoChunkReader*`. After `stoChunkReader_EnterChunkScope`, gfx unserialize paths call this with **ECX = reader**. If it returns nonzero, the caller cleans the scope and returns **0** (soft success — do not read chunk body). If zero, deserialization continues. Hard failures remain **−1** via separate tag/version paths.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00767120_FUN_00767120.md` |
| Annotated | `docs/reconstruction/raw/aa_00767120_FUN_00767120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00767120.cpp` / `stoChunkReader_SoftSkipIfBitSet.cpp` |
| Function record | `docs/reconstruction/functions/aa_00767120_FUN_00767120.md` |
| Live Ghidra | `decompile_function` + `force_decompile` `0x00767120` (**identical**) |
| | `read_memory` 80 B @ `0x00767120` |
| | `get_function_pcode` basic |
| | `analyze_function_complete` (4 xrefs, leaf) |
| | `get_assembly_context` on all 4 call sites |
| Tools avoided | `disassemble_bytes` (policy) |

**Dual A/B decompile agreement:**

```
uint __fastcall FUN_00767120(uint *param_1) {
  uint id = *param_1;
  if (id == 0) return in_EAX & 0xffffff00; // XOR AL,AL
  uint base = param_1[2];
  base += (id >> 5) * 4;
  uint low = id & 0x1f;
  return ((1 << ((low - 1) & 0x1f)) & *(uint*)(base + (((low - 1) >> 5) * 4))) != 0;
}
```

No third-rep needed.

---

## 3. Signature

```c
// __fastcall this-style: ECX = stoChunkReader*
// plain RET; no stack args; leaf
uint32_t __fastcall stoChunkReader_SoftSkipIfBitSet(uint32_t *reader);
// Return: 0 = continue; 1 = soft-skip (booleanized via NEG/SBB/NEG)
```

| Item | Evidence |
|---|---|
| Convention | `MOV ECX, EBX/ESI/EDI` then `CALL`; plain `RET` |
| ECX = reader | GPCE: `PUSH EBX` into EnterChunkScope then `MOV ECX,EBX` before this call |
| Return | `TEST AL,AL` at every site; bytes booleanize to 0/1 |
| Body range | `0x00767120`–`0x0076715c` (~61 B); `CC` pad follows |
| Callees | none |

---

## 4. Control flow (sealed)

```
id = reader[+0]
if (id == 0) return false          // XOR AL,AL; RET
base = reader[+8]
base += (id >> 5) * 4
low = id & 0x1f
idx = low - 1
word = *(uint32*)(base + (idx >> 5) * 4)
mask = 1 << (idx & 0x1f)
return (word & mask) != 0          // boolean 0/1
```

---

## 5. Machine bytes (`read_memory` @ `0x00767120`)

```
8B 11 85 D2 75 03 32 C0 C3
8B 49 08 33 C0 85 D2 76 0B
8B C2 C1 EA 05 8D 0C 91 83 E0 1F
83 E8 01 8B D0 83 E0 1F C1 EA 05 8D 14 91
8B C8 B8 01 00 00 00 D3 E0 23 02 F7 D8 1B C0 F7 D8 C3
CC CC CC
```

Matches decompile (id load, zero early-out, +8 base, shift/adjust, bit test, booleanize).

---

## 6. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| Leaf CF / bit math | **High** | bytes + pcode + dual decompile |
| Soft-skip role | **High** | 4/4 callers same pattern |
| ECX = reader | **High** | call-site registers |
| `+0` / `+8` English names | **Tentative** | plate: id + bitset; not RTTI-named |
| id multiple of 32 | **Open** | underflow idx; no asset proof |
| Studio symbol | **Tentative** | inferred name only |

---

## 7. Gaps (non-blocking for CF seal)

1. Product names for reader fields `+0` and `+8`.
2. Whether retail ever passes `id & 0x1f == 0`.
3. Whether bitset is "already consumed", "optional child present", or other.
4. Runtime bit-exact capture.

---

## 8. AutoCore impact

- Unserialize ports must distinguish **soft-skip (0)** from **hard fail (−1)**.
- Do not invent body reads when this predicate is true.
- Port bit formula exactly if reusing client asset skip semantics; otherwise document intentional divergence.
