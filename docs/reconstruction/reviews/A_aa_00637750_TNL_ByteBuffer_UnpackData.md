# Review A (reconstruction fidelity): `aa_00637750` TNL_ByteBuffer_UnpackData

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637750` |
| **VA** | `0x00637750` |
| **Canonical name** | `TNL_ByteBuffer_UnpackData` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| **System** | client-net / TNL special-message (`MapInstanceListResponse` `0x804D`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Convert inbound TNL special-message payload for opcode **`0x804D`** into a heap **ByteBuffer** object whose data prefix is `{ u32 0x804D, u32 count, Entry* }`, with `count` entries of stride **`0x18`** decoded from a BitStream.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00637750_FUN_00637750.md` |
| Annotated | `docs/reconstruction/raw/aa_00637750_FUN_00637750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_ByteBuffer_UnpackData.cpp` |
| Function record | `docs/reconstruction/functions/aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| Live decompile | Ghidra `decompile_function` `0x00637750` — body ≡ raw |
| Live bytes | Ghidra `read_memory` entry + mid + epilogue (`C3`) |
| Function meta | `get_function_by_address` → body `00637750`–`00637982` |
| Xrefs | sole call from `Client_UnpackSpecialMessage` @ `00637d68` |
| Callees | `FUN_0042b3a0`, `BitStream_readBits`, `FUN_0042b250`, `FUN_0042b270`, alloc/free |
| Caller opcode | `Client_UnpackSpecialMessage` only when `param_2 == 0x804D` |
| Consumer cross-check | `FUN_0080a810` @ `0x0080a810` (count@+4, entries*@+8) |
| Opcode enum | `GameOpcode.MapInstanceListResponse = 0x804D` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **cdecl** — args on stack; epilogue `ADD ESP,0x164` / **`RET` (`C3`)** |
| Args | `out**`, `inRefBuf*` |
| Return | `out**` in EAX; `*out = ByteBuffer*` |
| SEH | Present (`LAB_009a8d9e`); not load-bearing for wire math |

### 3.2 Dispatch context — **SEALED**

- Only special-message opcode **`≥ 0x206D`** handled as a real unpack on this path is **`0x804D`** (siblings: `0x206C`, `0x2005`, `0x2023` below the cut).
- AutoCore name: **`MapInstanceListResponse`**.

### 3.3 Wire codec — **SEALED**

```
count = readBits(8)           // u8
for i in 0..count-1:
  id     = readBits(64)       // → entry+0x00 (u64)
  fieldA = readBits(16)       // → entry+0x08 (u32 zext)
  fieldB = readBits(16)       // → entry+0x0c (u32 zext)
  flag0  = readFlag()         // → entry+0x10
  flag1  = readFlag()         // → entry+0x11
```

- Entry stride: **`0x18`** (bytes: `lea ebp,[esi+esi*2]; shl×3` → `×24`; loop `add edi,0x18`).
- Flags are **inlined** BitStream bit tests (same shape as `BitStream_writeFlag` inverse), not a call to `BitStream_readFlag`.

### 3.4 Rebuild / ByteBuffer — **SEALED**

| Step | Fact |
|---|---|
| Entry storage | `operator_new[](count * 0x18)` |
| Header constant | stack/data prefix tag **`0x804D`** (`C7 … 4D 80 00 00`) |
| Object | `operator_new(0x18)` + `FUN_0042b250` + vtable **`PTR_LAB_009d7b00`** |
| Size field | **`count * 0x18 + 8`** (`add ebp, 8` before malloc) |
| Data | `malloc(size)`; ownsMemory = 1 @ `+0x14` |
| Refcount | `bb[+0x08]++` after assign to `*out` |
| Input release | `in[+0x08]--`; if 0 → `vtbl[+0x08]()` |

### 3.5 Data prefix vs consumer — **SEALED**

Consumer `FUN_0080a810`:

- `count = *(int*)(buf + 4)`
- `entries = *(void**)(buf + 8)`
- copies `count × 0x18`, then `delete[]` entries

⇒ rebuilt payload is **pointer-based**, not a single inline blob of entries after the header. Matches unpacker `new[]` + header `{tag, count, ptr}`.

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + bind BitStream from in+0xc/+0x10 | **Yes** |
| u8 count; alloc entries; per-entry codec | **Yes** |
| ByteBuffer ctor + memcpy prefix + refcount | **Yes** |
| BitStream teardown + input release | **Yes** |
| return out | **Yes** |

---

## 5. Gaps

1. English names for entry `fieldA` / `fieldB` / flags (map-instance UI semantics).
2. Identity of the **u64** (instance id vs TFID vs map key) — Probable instance id; not string-proven here.
3. Why ByteBuffer **size** equals `count*0x18+8` rather than `12` (header only) — consumer ignores size; treat as payload-mass field.
4. Retail memcpy over-reads stack when `size > 12`; unused by consumer — document, do not “fix” in ports without capture.
5. Runtime live capture / bit-exact image diff / server pack mirror — open.
6. Clean file abstracts inlined flag bodies; authoritative bit extract remains in raw.

**Verdict:** **accept-with-gaps** — wire, ABI, rebuild layouts, and opcode binding sealed for AutoCore ports; field English names remain open.
