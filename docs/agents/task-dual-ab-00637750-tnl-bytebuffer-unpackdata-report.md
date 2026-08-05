# Dual A/B report — `aa_00637750` TNL_ByteBuffer_UnpackData

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x00637750`. Dual A/B + three-rep artifacts. Seal special-message unpack for opcode **`0x804D`** (`MapInstanceListResponse`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` (+ callees/callers). No `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00637750` TNL_ByteBuffer_UnpackData | **accept-with-gaps** — ABI + wire + rebuild layouts **sealed**; entry English names open |

---

## Sealed facts

1. **ABI:** **cdecl** — `out**`, `inRefBuf*`; epilogue `ADD ESP,0x164` / **`RET`**; returns `out**` in EAX.

2. **Body:** `0x00637750`–`0x00637982`.

3. **Sole caller:** `Client_UnpackSpecialMessage` (`0x00637c20`) when `param_2 == **0x804D**`.

4. **Opcode:** AutoCore `GameOpcode.MapInstanceListResponse = 0x804D`. Header constant written into rebuild is **`0x804D`**.

5. **Wire (BitStream over `in+0x0c` / size `in+0x10`):**  
   `u8 count`; then `count × { u64, u16, u16, flag, flag }`.  
   Flags are **inlined** bit reads (not `BitStream_readFlag` call).

6. **Entry stride `0x18`:**  
   `+0x00` u64, `+0x08` u16→u32, `+0x0c` u16→u32, `+0x10` bool, `+0x11` bool.

7. **Rebuild:** heap `Entry[count]` via `operator_new[]`; ByteBuffer object `0x18` bytes, vtable **`PTR_LAB_009d7b00`**, data malloc, **size = count×0x18+8**, owns=1, refcount++.

8. **Data prefix:** `{ u32 0x804D, u32 count, Entry* }` — confirmed by consumer **`FUN_0080a810`** (`count@+4`, `entries*@+8`).

9. **Helpers:** `FUN_0042b3a0` = BitStream-from-buffer (vtable `009d7b94`); `FUN_0042b250`/`FUN_0042b270` = ref-object base ctor/related cleanup.

10. **Not sealed here:** entry field English names; u64 identity; server pack encoder; runtime/bit-exact; full BitStream type product name.

---

## Gaps

1. Map-instance UI field dictionary for the two u16s and two flags.  
2. u64 semantic domain.  
3. ByteBuffer size field vs 12-byte pointer header (payload-mass vs struct size).  
4. Clean abstracts inlined flag bodies — raw is authoritative for bit extract.  
5. Runtime live verification / differential.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00637750_TNL_ByteBuffer_UnpackData.md` | **accept-with-gaps** |

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| Function record | `docs/reconstruction/functions/aa_00637750_TNL_ByteBuffer_UnpackData.md` |
| Function record (FUN twin) | `docs/reconstruction/functions/aa_00637750_FUN_00637750.md` |
| Clean | `docs/reconstruction/reconstructed-exact/TNL_ByteBuffer_UnpackData.cpp` |
| Raw (authoritative body + live section) | `docs/reconstruction/raw/aa_00637750_FUN_00637750.md` |
| Annotated | `docs/reconstruction/raw/aa_00637750_FUN_00637750.annotated.md` |
| This report | `docs/agents/task-dual-ab-00637750-tnl-bytebuffer-unpackdata-report.md` |

Sibling context (not owned):  
`Client_UnpackSpecialMessage` `aa_00637c20`; consumer `FUN_0080a810` `0x0080a810`; BitStream helpers `aa_0042b3a0` / `aa_0042b670`.

---

## AutoCore impact

- Server **`MapInstanceListResponse` (0x804D)** must pack: **u8 count** + per instance **u64 + u16 + u16 + 2 one-bit flags** on the TNL BitStream.
- Client-local rebuild uses a **heap entry array pointer** inside the ByteBuffer data prefix — server need not emit that pointer form.
- Do not confuse this unit with generic multi-opcode ByteBuffer unpack; siblings handle `0x206C` / `0x2005` / `0x2023` separately.
- Max instances per message: **255** (u8 count).
