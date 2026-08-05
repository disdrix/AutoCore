# Review A (reconstruction fidelity): `aa_00636f00` EMSG_Sector_Damage_Unpack

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636f00` |
| **VA** | `0x00636f00` |
| **Canonical name** | `EMSG_Sector_Damage_Unpack` (Ghidra plate; scaffold `FUN_00636f00`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00636f00_EMSG_Sector_Damage_Unpack.md` |
| **System tag** | `client-net` / `combat-floaters` |
| **Scope** | Dual A/B only — own VA; no WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00636f00_FUN_00636f00.md` |
| Annotated | `docs/reconstruction/raw/aa_00636f00_FUN_00636f00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00636f00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00636f00_FUN_00636f00.md` |
| Caller (context only) | `Client_UnpackSpecialMessage` @ `0x00637c20` — opcode `0x2023` |
| Product pack (cross-check) | `src/AutoCore.Game/Packets/Sector/DamagePacket.cs` |
| Live Ghidra | `decompile_function` / `analyze_function_complete` / `read_memory` @ `0x00636f00`; xrefs; callees |

---

## 2. Purpose (sealed role)

**TNL special-message unpacker for `EMSG_Sector_Damage` (opcode `0x2023`).**

Sole code xref: unconditional call from `Client_UnpackSpecialMessage` when `param_2 == 0x2023` (`0x00637c87`). Builds a heap payload (header + `count` × `0x20` entries) from a `BitStream` bound to the inbound TNL buffer, wraps it in a refcounted `0x18`-byte object (`vtbl = PTR_LAB_009d7b00`), stores that pointer at `*param_1`, bumps wrapper refcount, then releases the input message refcount (`param_2[2]--`, destroy via vtbl+8 if zero).

Does **not** apply damage, queue combat floaters, or touch HP — pure unpack → owned buffer.

---

## 3. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Named unpack for opcode **0x2023** | **High** | Immediate `C7 44 24 30 23 20 00 00` → `mov [esp+0x30], 0x2023`; stack header `local_164[0] = 0x2023` |
| Sole caller `Client_UnpackSpecialMessage` on `0x2023` | **High** | `get_function_xrefs` → `00637c87`; caller decompile `if (param_2 != 0x2023) goto …; EMSG_Sector_Damage_Unpack(...)` |
| Bind stream: `FUN_0042b3a0(param_2[3], param_2[4])` thiscall on stack BitStream | **High** | Decompile; callees list; pattern matches other unpack units |
| Header wire: **64-bit** source coid + **1 flag** (global) + **16-bit** count | **High** | `BitStream_readBits(0x40)`, `BitStream_readFlag`, `BitStream_readBits(0x10)`; prologue `push 0x40` |
| Entry stride **0x20**; temp `operator_new[](count*0x20)` | **High** | `uVar6 * 0x20`; loop `piVar8 += 8` dwords |
| Final malloc size **`count*0x20 + 0x1c`** | **High** | `puVar5 = count*0x20` then `puVar5 += 7` (dword ptr) → +0x1c; `malloc(puVar5)` |
| Entries copied at packed buffer **+0x1c** | **High** | `puVar2 + 7` dword destination after 8-dword header copy |
| Per-entry wire order (flags + amount + TFID) | **High** | Decompile store order vs `DamagePacket.Write` |
| Amount is **signed int16** on wire, stored as **int32** | **High** | `(int)(short)local_17c[0]` after `readBits(0x10)` |
| Loop flags = inlined `BitStream_readFlag` (OOB → false + sticky error) | **High** | Identical bit-index math on `local_138` / `local_12c` / `local_118` / `local_128` |
| Wrapper object size **0x18**, owns buffer at `[3]`, size at `[4]`, owns-flag at byte `[5]` | **High** | `operator_new(0x18)`; `FUN_0042b250`; assign `[3]/[4]`; free old if owns |
| Output: `*param_1 = wrapper`; `wrapper[2]++` (refcount) | **High** | Epilogue |
| Input msg ref release `param_2[2]--; if 0 → (*param_2)[2]()` | **High** | Epilogue |
| Clean ≡ raw ≡ live decompile control flow | **High** | Live 2026-07-29 matches raw 2026-07-23 body (scaffold clean is whitespace-expanded same CF) |
| Semantic names of residual 7 entry flags beyond Crit/Resist/Deflect | **Open** | Port writes zeros; apply path out of this VA |
| `local_164[1]` / header dword +0x04 meaning | **Open** | Not written in this function body |
| `FUN_0042b250` / `FUN_0042b270` / exact wrapper class name | **Probable** | Refcount/base + BitStream dtor pattern; not dual-reviewed here |
| Bit-for-bit / runtime capture | **Open** | Project-wide deferred |

---

## 4. Wire format contract (from this unit)

```
// BitStream order after FUN_0042b3a0 bind
Source.Coid      : readBits(64)   → header +0x08 (i64)
Source.Global    : readFlag       → header +0x10 (bool)
Count            : readBits(16)   → header +0x18 (u16→u32)

// each entry i in [0, Count), temp slot base = entries + i*0x20
// cursor piVar8 = entry + 0x10
IsCrit           : readFlag       → entry +0x14
Amount           : readBits(16)   → entry +0x10 as (int32)(int16)
Target.Coid      : readBits(64)   → entry +0x00 (i64)
Target.Global    : readFlag       → entry +0x08
IsResist         : readFlag       → entry +0x1B
IsDeflect        : readFlag       → entry +0x1C
flag_1d          : readFlag       → entry +0x1D
flag_15          : readFlag       → entry +0x15
flag_16          : readFlag       → entry +0x16
flag_17          : readFlag       → entry +0x17
flag_18          : readFlag       → entry +0x18
flag_19          : readFlag       → entry +0x19
flag_1a          : readFlag       → entry +0x1A
```

**Note:** residual flag **wire** order is not the same as ascending memory offsets after Crit (stores scatter to `+0x1B…1D` then `+0x15…1A`). Product `DamagePacket.Write` matches **wire** order (Crit, amount, target, global, Resist, Deflect, seven `false`).

### Packed buffer layout (malloc result)

| Off | Field |
|---|---|
| `+0x00` | Opcode dword `0x2023` |
| `+0x04` | Unassigned in this body (stack residue / unknown) |
| `+0x08` | Source TFID coid (i64) |
| `+0x10` | Source global (bool) |
| `+0x14` | (padding / unset in body) |
| `+0x18` | Entry count |
| `+0x1C` | `entries[count]` each `0x20` |

Total size = `0x1C + count * 0x20`.

---

## 5. Control flow: clean ≡ raw ≡ live

```
SEH frame (LAB_009a8cf5)
header.opcode = 0x2023
BitStream_ctor/bind FUN_0042b3a0(msg+0x0C, msg+0x10)   // param_2[3], param_2[4]
read source TFID (64 + flag)
read count (16)
alloc temp entries[count * 0x20]
for each entry: 1 flag + i16 amount + 64-bit TFID + 1 global + 9 flags
malloc(0x1C + count*0x20)
memcpy 8 dwords header from local_164
memcpy entry bytes to dest+0x1C
delete[] temp
new 0x18 wrapper (FUN_0042b250, vtbl PTR_LAB_009d7b00)
adopt malloc buffer (size, ptr, owns=1)
*param_1 = wrapper; wrapper.refcount++
BitStream teardown FUN_0042b270 (+ free stream buffer if owned)
release param_2 refcount
return param_1
```

| Stage | Match |
|---|---|
| Opcode stamp 0x2023 | **Yes** |
| Header TFID + count | **Yes** |
| Entry loop 0x20 / flag scatter | **Yes** |
| Pack 0x1C + N×0x20 | **Yes** |
| Wrapper adopt + out store | **Yes** |
| Input ref release | **Yes** |
| No combat apply / no floater queue | **Yes** |

---

## 6. Callees (this VA only)

| Callee | Role in unit |
|---|---|
| `FUN_0042b3a0` | BitStream bind from TNL buffer ptr/len |
| `BitStream_readBits` | 64 / 16 bit fields |
| `BitStream_readFlag` | header global (loop flags often inlined) |
| `operator_new[]` / `operator_delete[]` | temp entry array |
| `malloc` / `free` | packed payload + stream buffer |
| `operator_new` | 0x18 wrapper |
| `FUN_0042b250` | wrapper base init |
| `FUN_0042b270` | BitStream dtor helper |

---

## 7. Gaps (accept)

1. Semantic names / consumers of residual entry flags at `+0x15…1A`, `+0x1D` (apply path e.g. `0x812A60` is **out of scope** for this dual).
2. Header dword at `+0x04` (and possible padding at `+0x14`) never written here.
3. Exact C++ type of wrapper / `PTR_LAB_009d7b00` class name.
4. Precise identity of `FUN_0042b250` / `FUN_0042b270` (base ctor / stream dtor) — pattern sealed, symbols open.
5. Clean unit still scaffold-named `FUN_00636f00.cpp` with `uint32_t /* width */` noise; CF faithful, not modernized.
6. Runtime / bit-exact / image diff open.

**Verdict:** static dual fidelity **sealed** for role, opcode, wire order, entry stride, pack size, and ownership/refcount epilogue. **accept-with-gaps.**
